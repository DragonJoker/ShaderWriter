#include "Common.hpp"
#include "TestWriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/PerVertex.hpp>

namespace
{
	void f01()
	{
		testBegin( "Vertex Shader" );
		using namespace sdw;

		ShaderWriter writer{ false };
		auto position = writer.declInput< Vec2 >( "position", 0u );
		auto texcoord = writer.declInput< Vec2 >( "texcoord", 1u );

		// Shader outputs
		auto vtx_texture = writer.declOutput< Vec2 >( "vtx_texture", 0u );
		auto out = gl_PerVertex{ writer };

		writer.implementFunction< void >( "main", [&]()
			{
				vtx_texture = texcoord;
				out.gl_Position() = vec4( position.x(), position.y(), 0.0, 1.0 );
			} );

		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader() ) << std::endl;
		std::cout << sdw::writeHlsl( writer.getShader() ) << std::endl;
		testEnd();
	}

	void f02()
	{
		testBegin( "Fragment Shader" );
		using namespace sdw;

		ShaderWriter writer{ false };
		// Shader inputs
		Ubo hdrConfig{ writer, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapDiffuse = writer.declSampler< SamplerType::e2D >( "c3d_mapDiffuse", 1u, 0u );
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

		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto hdrColor = writer.declLocale( "hdrColor"
					, texture( c3d_mapDiffuse, vtx_texture ).rgb() );
				hdrColor *= vec3( exposureBias ); // Hardcoded Exposure Adjustment.

				auto current = writer.declLocale( "current"
					, uncharted2ToneMap( hdrColor * c3d_exposure ) );

				auto whiteScale = writer.declLocale( "whiteScale"
					, vec3( 1.0_f ) / uncharted2ToneMap( vec3( linearWhitePointValue ) ) );
				auto colour = writer.declLocale( "colour"
					, current * whiteScale );

				pxl_rgb = vec4( applyGamma( c3d_gamma, colour ), 1.0 );
			} );

		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader() ) << std::endl;
		std::cout << sdw::writeHlsl( writer.getShader() ) << std::endl;
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterShader" );
	f01();
	f02();
	testSuiteEnd();
}
