#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma clang diagnostic ignored "-Wunused-function"
#pragma warning( disable:5245 )

namespace
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
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 0u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Position" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
	};

	template< sdw::var::Flag FlagT >
	struct PosTexT
		: sdw::StructInstance
	{
		PosTexT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
			, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
		{
		}

		SDW_DeclStructInstance( , PosTexT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "PosTex"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 0u );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray
					, 1u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "PosTex" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec2 texcoord;
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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "PosCol"
				, entryPoint
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

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eC
				, "PosCol" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray );
				result->declMember( "colour"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec4 position;
		sdw::Vec4 colour;
	};

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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Colour"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, 0u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Colour" );

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

	void noSpecificIO( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIO" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< VoidT > out )
				{
					writer.declLocale( "clipDistance", in.clipDistance[0]);
					writer.declLocale( "fragCoord", in.fragCoord );
					writer.declLocale( "frontFacing", in.frontFacing );
					//writer.declLocale( "layer", in.layer );
					writer.declLocale( "pointCoord", in.pointCoord );
					writer.declLocale( "primitiveID", in.primitiveID );
					writer.declLocale( "sampleID", in.sampleID );
					//writer.declLocale( "sampleMask", in.sampleMask[0]);
					writer.declLocale( "samplePosition", in.samplePosition );
					writer.declLocale( "viewportIndex", in.viewportIndex );

					out.fragDepth = 0.0_f;
					//out.sampleMask = in.sampleMask;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberInputOnly" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, VoidT >( [&]( FragmentInT< PositionT > in
				, FragmentOutT< VoidT > out )
				{
					auto col = writer.declLocale( "col", in.position );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalInputOnly" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto offpos = writer.declInput< Vec3 >( "offpos", 1u );

			writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< VoidT > out )
				{
					auto col = writer.declLocale( "col", offpos );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedInputOnly" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto offpos = writer.declInput< Vec3 >( "offpos", 1u );

			writer.implementMainT< PositionT, VoidT >( [&]( FragmentInT< PositionT > in
				, FragmentOutT< VoidT > out )
				{
					auto col = writer.declLocale( "col", in.position + offpos );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberOutputOnly" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = vec4( 1.0_f, 0.0_f, 0.0_f, 1.0_f );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalOutputOnly" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto offcol = writer.declOutput< Vec4 >( "offcol", 1u );

			writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< VoidT > out )
				{
					offcol = vec4( 0.0_f, 1.0_f, 0.0_f, 1.0_f );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedOutputOnly" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto offcol = writer.declOutput< Vec4 >( "offcol", 1u );

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = vec4( 1.0_f, 0.0_f, 0.0_f, 1.0_f );
					offcol = vec4( 0.0_f, 1.0_f, 0.0_f, 1.0_f );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberInAndOut" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, ColourT >( [&]( FragmentInT< PositionT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = vec4( in.position, 1.0_f );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalInAndOut" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto offpos = writer.declInput< Vec3 >( "offpos", 1u );
			auto offcol = writer.declOutput< Vec4 >( "offcol", 1u );

			writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< VoidT > out )
				{
					offcol = vec4( offpos, 1.0_f );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedInAndOut" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto offpos = writer.declInput< Vec3 >( "offpos", 1u );
			auto offcol = writer.declOutput< Vec4 >( "offcol", 1u );

			writer.implementMainT< PositionT, ColourT >( [&]( FragmentInT< PositionT > in
				, FragmentOutT< ColourT > out )
				{
					offcol = vec4( offpos, 1.0_f );
					out.colour = vec4( in.position, 1.0_f );
					auto uv = writer.declLocale( "uv", in.fragCoord );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void fragment( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "fragment" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };
		// Shader inputs
		UniformBuffer hdrConfig{ writer, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapDiffuse = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapDiffuse", 1u, 0u );

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
			, [&]( CombinedImage2DRgba32 const & tex
				, Vec2 const & coords )
			{
				writer.returnStmt( tex.sample( coords ).rgb() );
			}
			, InCombinedImage2DRgba32{ writer, "tex" }
			, InVec2{ writer, "coords" } );

		writer.implementMainT< PosTexT, ColourT >( [&]( FragmentInT< PosTexT > in
			, FragmentOutT< ColourT > out )
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

				out.colour = vec4( applyGamma( c3d_gamma, colour ), 1.0 );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void radianceComputer( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "radianceComputer" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		// Inputs
		auto c3d_mapEnvironment = writer.declCombinedImg< FImgCubeRgba32 >( "c3d_mapEnvironment", 1u, 0u );

		writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
			, FragmentOutT< ColourT > out )
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
				out.colour = vec4( irradiance, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void textureOffset( test::sdw_test::TestCounts & testCounts )
	{
		auto name = "textureOffset";
		testBegin( name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto tex = writer.declInput< Vec2 >( "tex", 0u );
			auto r = writer.declInput< Float >( "r", 1u );
			auto d = writer.declInput< Vec2 >( "d", 2u );
			auto s = writer.declCombinedImg< FImg2DRgba32 >( "s", 0u, 0u );

			writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT >
				, FragmentOutT< VoidT > )
				{
					auto factor = writer.declLocale( "factor"
						, r * s.lod( tex, 0.0_f, ivec2( 0_i, -2_i ) ).r() );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void skybox( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "skybox" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		// Shader inputs
		UniformBuffer hdrConfig{ writer, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapSkybox = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapSkybox", 1u, 0u );

		auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				writer.returnStmt( pow( srgb, vec3( gamma ) ) );
			}
			, InFloat{ writer, "gamma" }
			, InVec3{ writer, "srgb" } );

		writer.implementMainT< PosTexT, ColourT >( [&]( FragmentInT< PosTexT > in
			, FragmentOutT< ColourT > out )
			{
				auto colour = writer.declLocale( "colour"
					, c3d_mapSkybox.sample( in.texcoord ) );

				out.colour = vec4( removeGamma( c3d_gamma, colour.xyz() ), colour.w() );
				out.colour = vec4( removeGamma( 0.1_f, vec3( 0.0_f, 0.0_f, 0.0_f ) ), colour.w() );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void reference( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "reference" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };
		auto color1 = writer.declInput< Vec4 >( "color1", 0u );
		auto multiplier = writer.declInput< Vec4 >( "multiplier", 1u );
		auto color2 = writer.declInput< Vec4 >( "color2", 2u );
		auto color = writer.declOutput< Vec4 >( "color", 0u );

		Struct S{ writer, "S" };
		S.declMember< Int >( "b" );
		S.declMember< Vec4 >( "v", 5u );
		S.declMember< Int >( "i" );
		S.end();

		UniformBuffer blockName{ writer, "blockName", 0u, 0u };
		blockName.declStructMember( "s", S );
		blockName.declMember< Int >( "cond" );
		blockName.end();
		auto s = blockName.getMember< StructInstance >( "s" );
		auto cond = blockName.getMember< Int >( "cond" );

		writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
			, sdw::FragmentOutT< sdw::VoidT > )
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

	void terminate( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "terminate" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };
		auto offpos = writer.declInput< Vec3 >( "offpos", 1u );

		writer.implementMainT< PositionT, ColourT >( [&]( FragmentInT< PositionT > in
			, FragmentOutT< ColourT > out )
			{
				IF( writer, offpos.x() > 0.0_f )
				{
					writer.terminate();
				}
				FI;

				out.colour = vec4( in.position, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void demote( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "demote" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };
		auto offpos = writer.declInput< Vec3 >( "offpos", 1u );

		writer.implementMainT< PositionT, ColourT >( [&]( FragmentInT< PositionT > in
			, FragmentOutT< ColourT > out )
			{
				IF( writer, offpos.x() > 0.0_f )
				{
					writer.demote();
				}
				FI;

				out.colour = vec4( in.position, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterFragmentShader )
{
	sdwTestSuiteBegin();
	noSpecificIO( testCounts );
	specificMemberInputOnly( testCounts );
	specificGlobalInputOnly( testCounts );
	specificMixedInputOnly( testCounts );
	specificMemberOutputOnly( testCounts );
	specificGlobalOutputOnly( testCounts );
	specificMixedOutputOnly( testCounts );
	specificMemberInAndOut( testCounts );
	specificGlobalInAndOut( testCounts );
	specificMixedInAndOut( testCounts );
	fragment( testCounts );
	radianceComputer( testCounts );
	textureOffset( testCounts );
	skybox( testCounts );
	reference( testCounts );
	terminate( testCounts );
	demote( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterFragmentShader )
