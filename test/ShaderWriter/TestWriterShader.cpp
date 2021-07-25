#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	struct St
		: public sdw::StructInstance
	{
		St( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, a{ getMember< sdw::Vec4 >( "a" ) }
			, b{ getMemberArray< sdw::Vec4 >( "b" ) }
		{
		}

		St & operator=( St const & rhs )
		{
			sdw::StructInstance::operator=( rhs );
			return *this;
		}

		static std::unique_ptr< sdw::Struct > declare( sdw::ShaderWriter & writer )
		{
			return std::make_unique< sdw::Struct >( writer, makeType( writer.getTypesCache() ) );
		}

		static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140, "St" );

			if ( result->empty() )
			{
				result->declMember( "a", ast::type::Kind::eVec4F );
				result->declMember( "b", ast::type::Kind::eVec4F, 4u );
			}

			return result;
		}

		sdw::Vec4 a;
		sdw::Array< sdw::Vec4 > b;
	};
	using InSt = sdw::InParam< St >;

	struct St2
		: public sdw::StructInstance
	{
		St2( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, a{ getMember< St >( "a" ) }
			, b{ getMember< sdw::Vec4 >( "b" ) }
		{
		}

		St2 & operator=( St2 const & rhs )
		{
			sdw::StructInstance::operator=( rhs );
			return *this;
		}

		static std::unique_ptr< sdw::Struct > declare( sdw::ShaderWriter & writer )
		{
			return std::make_unique< sdw::Struct >( writer, makeType( writer.getTypesCache() ) );
		}

		static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140, "St2" );

			if ( result->empty() )
			{
				result->declMember( "a", St::makeType( cache ) );
				result->declMember( "b", ast::type::Kind::eVec4F );
			}

			return result;
		}

		St a;
		sdw::Vec4 b;
	};
	using InSt2 = sdw::InParam< St2 >;

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
			, testCounts );
		testEnd();
	}

	void vertex( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vertex" );
		using namespace sdw;

		VertexWriter writer;
		auto position = writer.declInput< Vec2 >( "position", 0u );
		auto texcoord = writer.declInput< Vec2 >( "texcoord", 1u );

		// Shader outputs
		auto vtx_texture = writer.declOutput< Vec2 >( "vtx_texture", 0u );
		auto out = writer.getOut();

		writer.implementFunction< sdw::Void >( "main", [&]()
			{
				vtx_texture = texcoord;
				out.vtx.position = vec4( position.x(), position.y(), 0.0, 1.0 );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void fragment( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "fragment" );
		using namespace sdw;

		FragmentWriter writer;
		// Shader inputs
		Ubo hdrConfig{ writer, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapDiffuse = writer.declSampledImage< FImg2DRgba32 >( "c3d_mapDiffuse", 1u, 0u );
		auto vtx_texture = writer.declInput< Vec2 >( "vtx_texture", 0u );

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

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto hdrColor = writer.declLocale( "hdrColor"
					, sampleTex( c3d_mapDiffuse, vtx_texture ) );
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
			, testCounts );
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
			, testCounts );

#if !defined( __APPLE__ )
		// Disabled on apple since somebody somewhere thinks putting an ivec3 inside an uint3 intrinsic is doable :/.
		test::validateShader( writer.getShader()
			, testCounts );
#endif

		testEnd();
	}

	void params( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "params" );
		using namespace sdw;
		FragmentWriter writer;

		Ubo ubo{ writer, "Matrices", 0u, 0u };
		auto c3d_viewMatrix = ubo.declMember< Mat4 >( "c3d_viewMatrix" );
		ubo.end();

		auto c3d_maps = writer.declSampledImageArray< FImg2DRgba32 >( "c3d_maps", 1u, 0u, 4u );

		auto st = St::declare( writer );

		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & p )
			{
			}
			, InVec4Array{ writer, "p", 4u } );

		auto foo02 = writer.implementFunction< sdw::Void >( "foo02"
			, [&]( Vec4 p )
			{
				p = p + vec4( 1.0_f );
			}
			, InOutVec4{ writer, "p" } );

		auto foo03 = writer.implementFunction< Vec4 >( "foo03"
			, [&]( Mat4 const & m
				, Vec4 const & p )
			{
				writer.returnStmt( m * p );
			}
			, InMat4{ writer, "m" }
			, InVec4{ writer, "p" } );

		auto foo04 = writer.implementFunction< Vec4 >( "foo04"
			, [&]( St const & m
				, Vec4 const & p )
			{
				FOR( writer, UInt, i, 0_u, i < 4_u, ++i )
				{
					m.b[i] *= p;
				}
				ROF;
				writer.returnStmt( m.a * p );
			}
			, InSt{ writer, "m" }
			, InVec4{ writer, "p" } );

		auto foo05 = writer.implementFunction< Vec4 >( "foo05"
			, [&]( SampledImage2DRgba32 const & m
				, Vec2 const & p )
			{
				writer.returnStmt( m.sample( p ) );
			}
			, InSampledImage2DRgba32{ writer, "m" }
			, InVec2{ writer, "p" } );

		auto foo06 = writer.implementFunction< Vec2 >( "foo06"
			, [&]( Vec2 const & e )
			{
				e.r() = e.r() * abs( 5.0_f * e.r() - 5.0 * 0.75 );
				writer.returnStmt( round( e ) );
			}
			, InVec2{ writer, "e" } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto va = writer.declLocaleArray< Vec4 >( "va", 4u );
				auto m = writer.declLocale< Mat4 >( "m" );
				foo01( va );
				foo02( v );
				foo03( m, v );
				auto r = writer.declLocale< Vec4 >( "r"
					, foo03( c3d_viewMatrix, v ) );
				auto inst = st->getInstance< St >( "inst", true );
				v = foo04( inst, v );
				v = foo05( c3d_maps[0_u], vec2( 0.0_f, 1.0_f ) );
				auto e = writer.declLocale< Vec2 >( "e" );
				e = foo06( e );
			} );

		test::expectError( "must be a memory object declaration"
			, testCounts );
		test::writeShader( writer
			, testCounts );
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
			, testCounts );
		testEnd();
	}

	void arrayAccesses( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arrayAccesses" );
		using namespace sdw;
		ComputeWriter writer;

		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & p
				, Vec4 v
				, Int const & i )
			{
				auto j = writer.declLocale< Int >( "j" );
				v = p[j];
			}
			, InVec4Array{ writer, "p", 4u }
			, OutVec4{ writer, "v" }
			, InInt{ writer, "i" } );

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto p = writer.declLocaleArray< Vec4 >( "p", 4u );
				auto v = writer.declLocale< Vec4 >( "v" );
				auto i = writer.declLocale< Int >( "i" );
				foo01( p, v, i );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void removeGamma( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "removeGamma" );
		using namespace sdw;
		ComputeWriter writer;

		auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				IF( writer, gamma < 0.0_f )
				{
					writer.returnStmt( srgb );
				}
				FI;

				writer.returnStmt( pow( srgb, vec3( gamma ) ) );
			}
			, InFloat{ writer, "gamma" }
			, InVec3{ writer, "srgb" } );

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto f = writer.declLocale< Float >( "f" );
				auto v = writer.declLocale< Vec3 >( "v" );
				v = removeGamma( f, v );
			} );

		test::writeShader( writer
			, testCounts );
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
			, testCounts );
		testEnd();
	}

	void returns( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "returns" );
		using namespace sdw;
		ComputeWriter writer;

		St::declare( writer );
		St2::declare( writer );

		auto foo01 = writer.implementFunction< St2 >( "foo01"
			, [&]( Vec4 const & p )
			{
				auto result = writer.declLocale< St2 >( "result" );
				result.a.a = p * 2.0_f;
				result.a.b[0] = p * 2.0_f;
				result.a.b[1] = p * 3.0_f;
				result.a.b[2] = p * 4.0_f;
				result.a.b[3] = p * 5.0_f;
				result.b = p * 6.0_f;
				writer.returnStmt( result );
			}
			, InVec4{ writer, "p" } );

		auto foo02 = writer.implementFunction< Vec4 >( "foo02"
			, [&]( St2 const & p )
			{
				writer.returnStmt( p.a.a );
			}
			, InSt2{ writer, "p" } );

		auto foo03 = writer.implementFunction< Float >( "foo03"
			, [&]( Vec4 const & p )
			{
				IF( writer, p.x() )
				{
					writer.returnStmt( p.y() );
				}
				ELSE
				{
					writer.returnStmt( p.z() );
				}
				FI;
			}
			, InVec4{ writer, "p" } );

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				v = foo02( foo01( v ) );
				auto r = writer.declLocale( "r"
					, foo01( v ) );
				v += foo02( r );
				foo03( v );
			} );

		test::writeShader( writer
			, testCounts );
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
			, testCounts );
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
			, testCounts );
		testEnd();
	}

	void vtx_frag( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vtx_frag" );
		using namespace sdw;

		ShaderArray shaders;
		{
			VertexWriter writer;

			// Shader inputs
			auto pos = writer.declInput< Vec4 >( "pos", 0u );
			auto color = writer.declInput< Vec4 >( "color", 1u );
			auto in = writer.getIn();

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "outColor", 0u );
			auto out = writer.getOut();

			writer.implementFunction< void >( "main", [&]()
				{
					outColor = color;
					out.vtx.position = pos;
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			using namespace sdw;
			FragmentWriter writer;

			// Shader inputs
			auto vtxColor = writer.declInput< Vec4 >( "vtxColor", 0u );

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "fragColor", 0u );

			writer.implementFunction< void >( "main"
				, [&]()
				{
					outColor = vtxColor;
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts );
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

			// Shader inputs
			auto in = writer.getIn();

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "outColor", 0u );
			auto out = writer.getOut();

			writer.implementFunction< void >( "main", [&]()
				{
					outColor = colors[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					outColor = colors[0];
					out.vtx.position = positions[0];

					outColor = vec4( 1.0_f, 0.0f, 0.0f, 1.0f );
					out.vtx.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			using namespace sdw;
			FragmentWriter writer;

			// Shader inputs
			auto color = writer.declInput< Vec4 >( "color", 0u );

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "fragColor", 0u );

			writer.implementFunction< void >( "main"
				, [&]()
				{
					outColor = color;
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts );
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

			// Shader inputs
			auto in = writer.getIn();

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "outColor", 0u );
			auto out = writer.getOut();

			writer.implementFunction< void >( "main", [&]()
				{
					outColor = colors[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					outColor = colors[0];
					out.vtx.position = positions[0];

					outColor = vec4( 1.0_f, 0.0f, 0.0f, 1.0f );
					out.vtx.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			using namespace sdw;
			FragmentWriter writer;

			// Shader inputs
			auto color = writer.declInput< Vec4 >( "color", 0u );

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "fragColor", 0u );

			writer.implementFunction< void >( "main"
				, [&]()
				{
					outColor = color;
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts );
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

			// Shader inputs
			auto in = writer.getIn();

			// Shader outputs
			auto outColor = writer.declOutput<Vec4>( "outColor", 0u );
			auto out = writer.getOut();

			writer.implementFunction<void>(
				"main", [&]()
				{
					out.vtx.position =
						vec4( positions[indices[in.vertexIndex]], 0.0_f, 1.0_f );
					outColor = vec4( colors[indices[in.vertexIndex]], 1.0_f );
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			// Shader inputs
			auto color = writer.declInput<Vec4>( "color", 0u );

			// Shader outputs
			auto fragColor = writer.declOutput<Vec4>( "fragColor", 0u );

			writer.implementFunction<void>(
				"main", [&]()
				{
					fragColor = color;
				} );

			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts );
		testEnd();
	}

	void radiance_computer( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "radiance_computer" );
		using namespace sdw;
		FragmentWriter writer;

		// Inputs
		auto vtx_worldPosition = writer.declInput< Vec3 >( "vtx_worldPosition", 0u );
		auto c3d_mapEnvironment = writer.declSampledImage< FImgCubeRgba32 >( "c3d_mapEnvironment", 1u, 0u );

		// Outputs
		auto pxl_fragColor = writer.declOutput< Vec4 >( "pxl_FragColor", 0u );

		writer.implementFunction< Void >( "main"
			, [&]()
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
			, testCounts );
		testEnd();
	}

	void arthapzMin( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arthapzMin" );
		sdw::ShaderArray shaders;
		{
			auto writer = sdw::VertexWriter{};

			auto position = writer.declInput<sdw::Vec3>( "vertex_position", 0u );
			auto texcoord = writer.declInput<sdw::Vec2>( "vertex_texcoord", 2u );
			auto out_texcoord = writer.declOutput<sdw::Vec2>( "out_vertex_texcoord", 2u );
			auto out = writer.getOut();

			writer.implementFunction<void>( "main", [&]()
				{
					using namespace sdw;

					out_texcoord = texcoord;

					out.vtx.position = vec4( position, 1.f );
				} );
			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			auto writer = sdw::FragmentWriter{};
			auto in_texcoord = writer.declInput<sdw::Vec2>( "in_texcoord", 2u );
			auto frag_color = writer.declOutput<sdw::Vec4>( "frag_color", 0u );
			auto base_color_sampler = writer.declSampledImage<FImg2DRgba32>( "base_color_sampler", 0, 2 );

			auto getEmissiveColor = writer.implementFunction<sdw::Vec4>( "getEmissiveColor", [&]()
				{
					writer.returnStmt( sdw::vec4( 0._f, 0.f, 0.f, 0.f ) );
				} );

			writer.implementFunction<void>( "main", [&]()
				{
					frag_color = base_color_sampler.sample( in_texcoord ) + getEmissiveColor();
				} );
			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts );
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

			auto position = writer.declInput<sdw::Vec3>( "vertex_position", 0u );
			auto normal = writer.declInput<sdw::Vec3>( "vertex_normal", 1u );
			auto texcoord = writer.declInput<sdw::Vec2>( "vertex_texcoord", 2u );
			auto tangent = writer.declInput<sdw::Vec4>( "tangent", 3u );

			auto out_position = writer.declOutput<sdw::Vec3>( "out_vertex_position", 0u );
			auto out_normal = writer.declOutput<sdw::Vec3>( "out_vertex_normal", 1u );
			auto out_texcoord = writer.declOutput<sdw::Vec2>( "out_vertex_texcoord", 2u );
			auto out_tangent = writer.declOutput<sdw::Vec4>( "out_vertex_tangent", 3u );

			auto camera = sdw::Ubo{ writer, "camera", 0, 0 };
			camera.declMember<sdw::Vec4>( "camera_position" );
			camera.declMember<sdw::Mat4>( "camera_projection" );
			camera.declMember<sdw::Mat4>( "camera_view" );
			camera.end();

			auto transform = sdw::Ubo{ writer, "transform", 1, 0 };
			transform.declMember<sdw::Mat4>( "transform_model" );
			transform.declMember<sdw::Mat4>( "transform_inverted_model" );
			transform.end();

			auto out = writer.getOut();

			writer.implementFunction<void>( "main", [&]()
				{
					using namespace sdw;

					auto model_space_position =
						writer.declLocale( "model_space_position",
							transform.getMember<Mat4>( "transform_model" ) * vec4( position, 1.f ) );

					out_position = model_space_position.xyz() / model_space_position.w();
					out_normal = normalize(
						transpose( mat3( transform.getMember<Mat4>( "transform_inverted_model" ) ) ) * normal );
					out_texcoord = texcoord;
					out_tangent = tangent;

					out.vtx.position = camera.getMember<Mat4>( "camera_projection" ) *
						camera.getMember<Mat4>( "camera_view" ) * vec4( out_position, 1.f );
				} );
			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			auto writer = sdw::FragmentWriter{}; auto in_position = writer.declInput<sdw::Vec3>( "in_position", 0u );
			auto in_normal = writer.declInput<sdw::Vec3>( "in_normal", 1u );
			auto in_texcoord = writer.declInput<sdw::Vec2>( "in_texcoord", 2u );
			auto in_tangent = writer.declInput<sdw::Vec4>( "in_tangent", 3u );

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

			auto getEmissiveColor = writer.implementFunction<sdw::Vec4>( "getEmissiveColor", [&]()
				{
					if ( hasEmissiveMap )
						writer.returnStmt( emissive_sampler.sample( in_texcoord ) *
							material.getMember<sdw::Vec4>( "emissive_factor" ) );
					else
						writer.returnStmt( sdw::vec4( 0._f, 0.f, 0.f, 0.f ) );
				} );

			auto getNormal = writer.implementFunction<sdw::Vec3>( "getNormal", [&]()
				{
					if ( hasNormalMap )
					{
						auto tangent_normal =
							writer.declLocale( "tangent_normal",
								normal_sampler.sample( in_texcoord ).xyz() * 2.f - 1.f );

						auto N = writer.declLocale( "N", sdw::normalize( in_normal ) );
						auto T = writer.declLocale( "T", sdw::normalize( in_tangent.xyz() ) );
						auto B = writer.declLocale( "B", -sdw::normalize( sdw::cross( N, T ) ) );

						auto TBN = writer.declLocale<sdw::Mat3>( "TBN", sdw::mat3( T, B, N ) );

						writer.returnStmt( sdw::normalize( TBN * tangent_normal ) );
					}
					else
						writer.returnStmt( in_normal );
				} );

			writer.implementFunction<void>( "main", [&]()
				{
					auto N = writer.declLocale<sdw::Vec3>( "N", sdw::normalize( getNormal() ) );
					auto V = writer.declLocale<sdw::Vec3>( "V",
						camera.getMember<sdw::Vec4>( "position" ).xyz() -
						in_position );

					frag_color = base_color_sampler.sample( in_texcoord ) + getEmissiveColor();
				} );
			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts );
		testEnd();
	}

	void onlyGeometry( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "onlyGeometry" );
		using namespace sdw;
		{
			GeometryWriter writer;
			writer.inputLayout( ast::stmt::InputLayout::eTriangleList );
			writer.outputLayout( ast::stmt::OutputLayout::eTriangleStrip, 3u );

			auto in = writer.getIn();
			auto out = writer.getOut();

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					out.vtx.position = in.vtx[0].position;
					EmitVertex( writer );

					out.vtx.position = in.vtx[1].position;
					EmitVertex( writer );

					out.vtx.position = in.vtx[2].position;
					EmitVertex( writer );

					EndPrimitive( writer );
				} );
			test::writeShader( writer
				, testCounts
				, true, false, false );
			test::writeShader( writer
				, testCounts
				, false, false, true );
		}
		testEnd();
	}

	void basicGeometry( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "basicGeometry" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			// Inputs
			uint32_t index = 0u;
			auto position = writer.declInput< Vec4 >( "position", index++ );

			// Outputs
			index = 0u;
			auto vtx_position = writer.declOutput< Vec3 >( "vtx_position", index++ );
			auto out = writer.getOut();

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					vtx_position = position.xyz();
					out.vtx.position = position;
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			GeometryWriter writer;
			writer.inputLayout( ast::stmt::InputLayout::eTriangleList );
			writer.outputLayout( ast::stmt::OutputLayout::eTriangleStrip, 3u );

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto mvp = voxelizeUbo.declMember< sdw::Mat4 >( "mvp" );
			voxelizeUbo.end();

			uint32_t index = 0u;
			auto vtx_position = writer.declInputArray< Vec3 >( "vtx_position", index++, 3u );
			auto in = writer.getIn();

			index = 0u;
			auto geo_position = writer.declOutput< Vec3 >( "geo_position", index++ );
			auto out = writer.getOut();

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto pos = writer.declLocale< Vec4 >( "pos" );

					pos = mvp * in.vtx[0].position;
					geo_position = pos.xyz();
					out.vtx.position = pos;
					EmitVertex( writer );

					pos = mvp * in.vtx[1].position;
					geo_position = pos.xyz();
					out.vtx.position = pos;
					EmitVertex( writer );

					pos = mvp * in.vtx[2].position;
					geo_position = pos.xyz();
					out.vtx.position = pos;
					EmitVertex( writer );

					EndPrimitive( writer );
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			uint32_t index = 0u;
			auto geo_position = writer.declInput< Vec3 >( "geo_position", index++ );

			auto pxl_fragColor( writer.declOutput< Vec4 >( "pxl_fragColor", 0 ) );

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					pxl_fragColor = vec4( geo_position, 1.0f );
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
		testEnd();
	}

	void voxelGeometry( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "voxelGeometry" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			// Inputs
			uint32_t index = 0u;
			auto position = writer.declInput< Vec4 >( "position", index++ );
			auto normal = writer.declInput< Vec3 >( "normal", index++ );
			auto uv = writer.declInput< Vec3 >( "uv", index++ );

			// Outputs
			index = 0u;
			auto vtx_position = writer.declOutput< Vec3 >( "vtx_position", index++ );
			auto vtx_normal = writer.declOutput< Vec3 >( "vtx_normal", index++ );
			auto vtx_texture = writer.declOutput< Vec3 >( "vtx_texture", index++ );
			auto out = writer.getOut();

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					vtx_position = position.xyz();
					vtx_normal = normal.xyz();
					vtx_texture = uv.xyz();
					out.vtx.position = position;
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			GeometryWriter writer;
			writer.inputLayout( ast::stmt::InputLayout::eTriangleList );
			writer.outputLayout( ast::stmt::OutputLayout::eTriangleStrip, 3u );

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			uint32_t index = 0u;
			auto vtx_position = writer.declInputArray< Vec3 >( "vtx_position", index++, 3u );
			auto vtx_normal = writer.declInputArray< Vec3 >( "vtx_normal", index++, 3u );
			auto vtx_texture = writer.declInputArray< Vec3 >( "vtx_texture", index++, 3u );
			auto in = writer.getIn();

			index = 0u;
			auto geo_position = writer.declOutput< Vec3 >( "geo_position", index++ );
			auto geo_normal = writer.declOutput< Vec3 >( "geo_normal", index++ );
			auto geo_texture = writer.declOutput< Vec3 >( "geo_texture", index++ );
			auto geo_axis = writer.declOutput< UInt >( "geo_axis", index++, uint32_t( sdw::var::Flag::eFlat ) ); //indicate which axis the projection uses
			auto geo_aabb = writer.declOutput< Vec4 >( "geo_aabb", index++, uint32_t( sdw::var::Flag::eFlat ) );
			auto out = writer.getOut();

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto faceNormal = writer.declLocale( "faceNormal"
						, normalize( cross( vtx_position[1] - vtx_position[0], vtx_position[2] - vtx_position[0] ) ) );
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
							in.vtx[0].position,
							in.vtx[1].position,
							in.vtx[2].position,
						} );

					//Find the axis the maximize the projected area of this triangle
					IF( writer, NdotXAxis > NdotYAxis && NdotXAxis > NdotZAxis )
					{
						proj = c3d_vpX;
						geo_axis = 1_u;
					}
					ELSEIF( NdotYAxis > NdotXAxis && NdotYAxis > NdotZAxis )
					{
						proj = c3d_vpY;
						geo_axis = 2_u;
					}
					ELSE
					{
						proj = c3d_vpZ;
						geo_axis = 3_u;
					}
					FI;

					auto pos = writer.declLocaleArray< Vec4 >( "pos", 3u );

					//transform vertices to clip space
					pos[0] = proj * pos[0];
					pos[1] = proj * pos[1];
					pos[2] = proj * pos[2];

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

					geo_aabb = aabb;

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
					geo_position = pos[0].xyz();
					geo_normal = vtx_normal[0];
					geo_texture = vtx_texture[0];
					EmitVertex( writer );

					out.vtx.position = pos[1];
					geo_position = pos[1].xyz();
					geo_normal = vtx_normal[1];
					geo_texture = vtx_texture[1];
					EmitVertex( writer );

					out.vtx.position = pos[2];
					geo_position = pos[2].xyz();
					geo_normal = vtx_normal[2];
					geo_texture = vtx_texture[2];
					EmitVertex( writer );

					EndPrimitive( writer );
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			auto pxl_voxelVisibility = writer.declImage< WUImg3DR8 >( "pxl_voxelVisibility", 0u, 1u );

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			uint32_t index = 0u;
			auto geo_position = writer.declInput< Vec3 >( "geo_position", index++ );
			auto geo_normal = writer.declInput< Vec3 >( "geo_normal", index++ );
			auto geo_texture = writer.declInput< Vec3 >( "geo_texture", index++ );
			auto geo_axis = writer.declInput< UInt >( "geo_axis", index++, uint32_t( sdw::var::Flag::eFlat ) ); //indicate which axis the projection uses
			auto geo_aabb = writer.declInput< Vec4 >( "geo_aabb", index++, uint32_t( sdw::var::Flag::eFlat ) );
			auto in = writer.getIn();

			auto pxl_fragColor( writer.declOutput< Vec4 >( "pxl_fragColor", 0 ) );

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					IF( writer
						, geo_position.x() < geo_aabb.x()
						|| geo_position.y() < geo_aabb.y()
						|| geo_position.x() > geo_aabb.z()
						|| geo_position.y() > geo_aabb.w() )
					{
						writer.discard();
					}
					FI;

					auto width = writer.declLocale( "width"
						, writer.cast< Int >( c3d_size.x() ) );
					auto temp = writer.declLocale( "temp"
						, ivec3( writer.cast< Int >( in.fragCoord.x() )
							, writer.cast< Int >( in.fragCoord.y() )
							, width * writer.cast< Int >( in.fragCoord.z() ) ) );
					auto texcoord = writer.declLocale< IVec3 >( "texcoord" );

					IF( writer, geo_axis == 1 )
					{
						texcoord.x() = width - temp.z();
						texcoord.z() = temp.x();
						texcoord.y() = temp.y();
					}
					ELSEIF( geo_axis == 2 )
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
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		testEnd();
	}

	void clipDistance( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "clipDistance" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			auto position = writer.declInput< Vec4 >( "position", 0u );
			auto cfg = writer.declUniformBuffer( "Config", 0u, 0u );
			auto mvps = cfg.declMember< sdw::Mat4 >( "mvps", 6u );
			auto tiles = cfg.declMember< sdw::Vec4 >( "tiles" );
			auto instances = cfg.declMember< sdw::UVec4 >( "instances", 6u );
			cfg.end();
			auto in = writer.getIn();
			auto out = writer.getOut();

			writer.implementMain( [&]()
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
						, mvps[tileIndex] * position );
					out.vtx.position = p;

					out.vtx.clipDistance[0] = dot( vec4( 1.0_f, 0.0_f, 0.0_f, -tileMin.x() ), p );
					out.vtx.clipDistance[1] = dot( vec4( -1.0_f, 0.0_f, 0.0_f, tileMax.x() ), p );
					out.vtx.clipDistance[2] = dot( vec4( 0.0_f, -1.0_f, 0.0_f, -tileMin.y() ), p );
					out.vtx.clipDistance[3] = dot( vec4( 0.0_f, 1.0_f, 0.0_f, tileMax.y() ), p );
				} );
			test::writeShader( writer
				, testCounts );
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
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
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
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
		testEnd();
	}

	struct Voxel
		: public sdw::StructInstance
	{
		Voxel( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, colorMask{ getMember< sdw::UInt >( "colorMask" ) }
			, normalMask{ getMember< sdw::UInt >( "normalMask" ) }
		{
		}

		Voxel & operator=( Voxel const & rhs )
		{
			StructInstance::operator=( rhs );
			return *this;
		}

		static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
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

		static std::unique_ptr< sdw::Struct > declare( sdw::ShaderWriter & writer )
		{
			return std::make_unique< sdw::Struct >( writer
				, makeType( writer.getTypesCache() ) );
		}

		// Raw values
		sdw::UInt colorMask;
		sdw::UInt normalMask;

		static uint32_t constexpr DataSize = 8u;

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
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
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
				, true, false, false );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
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

			auto SMAADetectHorizontalCornerPattern = writer.implementFunction< Void >( "SMAADetectHorizontalCornerPattern"
				, [&]( SampledImage2DRgba32 const & edgesTex
					, Vec2 const & weights
					, Vec2 const & texcoord
					, Vec2 const & d )
				{
				}
				, InSampledImage2DRgba32{ writer, "edgesTex" }
				, InVec2{ writer, "weights" }
				, InVec2{ writer, "texcoord" }
				, InVec2{ writer, "d" } );

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto factor = writer.declLocale( "factor"
						, r * s.lod( tex, 0.0_f, ivec2( 0_i, -2_i ) ).r() );
				} );
			test::writeShader( writer
				, testCounts
				, true, false, false );
		}
		testEnd();
	}}

sdwTestSuiteMain( TestWriterShader )
{
	sdwTestSuiteBegin();
	reference( testCounts );
	vertex( testCounts );
	fragment( testCounts );
	compute( testCounts );
	params( testCounts );
	swizzles( testCounts );
	arrayAccesses( testCounts );
	removeGamma( testCounts );
	conversions( testCounts );
	returns( testCounts );
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
	onlyGeometry( testCounts );
	basicGeometry( testCounts );
	voxelGeometry( testCounts );
	simpleStore( testCounts );
	voxelToTexture( testCounts );
	clipDistance( testCounts );
	imageArray( testCounts );
	textureOffset( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterShader )
