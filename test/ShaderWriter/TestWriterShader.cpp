#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	struct St
		: public sdw::StructInstance
	{
		St( sdw::Shader * shader
			, ast::expr::ExprPtr expr )
			: StructInstance{ shader, std::move( expr ) }
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
		St2( sdw::Shader * shader
			, ast::expr::ExprPtr expr )
			: StructInstance{ shader, std::move( expr ) }
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
		blockName.declMember( "s", S );
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
				out.gl_out.gl_Position = vec4( position.x(), position.y(), 0.0, 1.0 );
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
				writer.returnStmt( writer.paren(
					writer.paren(
						x
						* writer.paren( x * shoulderStrength + linearAngle * linearStrength )
						+ toeStrength * toeNumerator )
					/ writer.paren(
						x
						* writer.paren( x * shoulderStrength + linearStrength )
						+ toeStrength * toeDenominator ) )
					- toeNumerator / toeDenominator );
			}
			, InVec3{ writer, "x" } );

		auto sampleTex = writer.implementFunction< Vec3 >( "sampleTex"
			, [&]( SampledImage2DRgba32 const & tex
				, Vec2 const & coords )
			{
				writer.returnStmt( texture( tex, coords ).rgb() );
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
		ArraySsboT< UInt > ssbo{ writer, "Datas", writer.getTypesCache().getUInt(), ast::type::MemoryLayout::eStd140 , 0u, 0u };

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				ssbo[in.gl_GlobalInvocationID.x()]
					= ssbo[in.gl_GlobalInvocationID.x()]
					* ssbo[in.gl_GlobalInvocationID.x()];
			} );

		test::writeShader( writer
			, testCounts );
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

		auto c3d_mapDepths = writer.declSampledImageArray< FImg2DRgba32 >( "c3d_mapDepth", 1u, 0u, 4u );

		auto st = St::declare( writer );

		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & p )
			{
			}
			, InVec4Array{ writer, "p", 4u } );

		auto foo02 = writer.implementFunction< sdw::Void >( "foo02"
			, [&]( Vec4 & p )
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
				writer.returnStmt( texture( m, p ) );
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
				auto inst = st->getInstance< St >( "inst" );
				v = foo04( inst, v );
				v = foo05( c3d_mapDepths[0_u], vec2( 0.0_f, 1.0_f ) );
				auto e = writer.declLocale< Vec2 >( "e" );
				e = foo06( e );
			} );

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
				, Array< Vec4 > & offset )
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
				position.z() = texelFetch( c3d_mapDepth, ssPosition, 0_i ).r();
				auto lrtMetrics = writer.declLocale< Vec4 >( "lrtMetrics" );
				auto ltexcoord = writer.declLocale< Vec2 >( "ltexcoord" );
				auto loffset = writer.declLocaleArray< Vec4 >( "loffset", 3u );
				SMAAEdgeDetectionVS( lrtMetrics, ltexcoord, loffset );
				auto L = writer.declLocale< Float >( "L" );
				auto Lright = writer.declLocale< Float >( "Lright" );
				auto Lbottom = writer.declLocale< Float >( "Lbottom" );
				auto delta = writer.declLocale< Vec4 >( "delta" );
				delta.zw() = abs( L - vec2( Lright, Lbottom ) );
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
				, Vec4 & v
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

		//St::declare( writer );
		//St2::declare( writer );

		//auto foo01 = writer.implementFunction< St2 >( "foo01"
		//	, [&]( Vec4 const & p )
		//	{
		//		auto result = writer.declLocale< St2 >( "result" );
		//		result.a.a = p * 2.0_f;
		//		result.a.b[0] = p * 2.0_f;
		//		result.a.b[1] = p * 3.0_f;
		//		result.a.b[2] = p * 4.0_f;
		//		result.a.b[3] = p * 5.0_f;
		//		result.b = p * 6.0_f;
		//		writer.returnStmt( result );
		//	}
		//	, InVec4{ writer, "p" } );

		//auto foo02 = writer.implementFunction< Vec4 >( "foo02"
		//	, [&]( St2 const & p )
		//	{
		//		writer.returnStmt( p.a.a );
		//	}
		//	, InSt2{ writer, "p" } );

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
				//v = foo02( foo01( v ) );
				//auto r = writer.declLocale( "r"
				//	, foo01( v ) );
				//v += foo02( r );
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
					, texture( c3d_mapSkybox, vtx_texture ) );

				pxl_FragColor = vec4( removeGamma( c3d_gamma, colour.xyz() ), colour.w() );
				pxl_FragColor = vec4( removeGamma( 0.1_f, vec3( 0.0_f, 0.0_f, 0.0_f ) ), colour.w() );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	sdwTestSuiteBegin( "TestWriterShader" );
	//reference( testCounts );
	//vertex( testCounts );
	//fragment( testCounts );
	//compute( testCounts );
	//params( testCounts );
	//swizzles( testCounts );
	//arrayAccesses( testCounts );
	//removeGamma( testCounts );
	//conversions( testCounts );
	returns( testCounts );
	//outputs( testCounts );
	//skybox( testCounts );
	sdwTestSuiteEnd();
}
