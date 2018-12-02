#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	void reference( test::TestCounts & testCounts )
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

		writer.implementFunction< void >( "main", [&]()
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

	void vertex( test::TestCounts & testCounts )
	{
		testBegin( "vertex" );
		using namespace sdw;

		VertexWriter writer;
		auto position = writer.declInput< Vec2 >( "position", 0u );
		auto texcoord = writer.declInput< Vec2 >( "texcoord", 1u );

		// Shader outputs
		auto vtx_texture = writer.declOutput< Vec2 >( "vtx_texture", 0u );
		auto out = writer.getOut();

		writer.implementFunction< void >( "main", [&]()
			{
				vtx_texture = texcoord;
				out.gl_out.gl_Position = vec4( position.x(), position.y(), 0.0, 1.0 );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void fragment( test::TestCounts & testCounts )
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

		writer.implementFunction< void >( "main"
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

	void compute( test::TestCounts & testCounts )
	{
		testBegin( "compute" );
		using namespace sdw;
		ComputeWriter writer;
		auto in = writer.getIn();
		ArraySsboT< UInt > ssbo{ writer, "Datas", ast::type::getUInt(), ast::type::MemoryLayout::eStd140 , 0u, 0u };

		writer.inputLayout( 16 );
		writer.implementFunction< void >( "main"
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

	void params( test::TestCounts & testCounts )
	{
		testBegin( "params" );
		using namespace sdw;
		ComputeWriter writer;

		auto foo1 = writer.implementFunction< Void >( "foo01"
			, [&]( Array< Vec4 > const & p )
			{
			}
			, InVec4Array{ writer, "p", 4u } );

		writer.inputLayout( 16 );
		writer.implementFunction< Void >( "main"
			, [&]()
			{
				auto v = writer.declLocaleArray< Vec4 >( "v", 4u );
				foo1( v );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterShader" );
	reference( testCounts );
	vertex( testCounts );
	fragment( testCounts );
	compute( testCounts );
	params( testCounts );
	testSuiteEnd();
}
