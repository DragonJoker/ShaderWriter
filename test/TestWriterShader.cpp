#include "Common.hpp"
#include "TestWriterCommon.hpp"

#include <ShaderWriter/PerVertex.hpp>

namespace
{
	void f01()
	{
		testBegin( "Vertex Shader" );
		sdw::Shader shader;
		auto position = shader.declInput< sdw::Vec2 >( "position", 0u );
		auto texcoord = shader.declInput< sdw::Vec2 >( "texcoord", 1u );

		// Shader outputs
		auto vtx_texture = shader.declOutput< sdw::Vec2 >( "vtx_texture", 0u );
		auto out = sdw::gl_PerVertex{ shader };

		shader.implementFunction< void >( "main", [&]()
			{
				vtx_texture = texcoord;
				out.gl_Position() = vec4( position.x(), position.y(), 0.0, 1.0 );
			} );

		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void f02()
	{
		testBegin( "Fragment Shader" );
		using namespace sdw;

		Shader shader;
		// Shader inputs
		Ubo hdrConfig{ shader, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapDiffuse = shader.declSampler< SamplerType::e2D >( "c3d_mapDiffuse", 1u, 0u );
		auto vtx_texture = shader.declInput< Vec2 >( "vtx_texture", 0u );

		// Shader outputs
		auto pxl_rgb = shader.declOutput< Vec4 >( "pxl_rgb", 0 );

		auto applyGamma = shader.implementFunction< Vec3 >( "applyGamma"
			, [&]( Float const & gamma
				, Vec3 const & hdr )
			{
				shader.returnStmt( pow( abs( hdr ), vec3( 1.0_f / gamma ) ) );
			}
			, InFloat{ &shader, "gamma" }
			, InVec3{ &shader, "hdr" } );

		auto shoulderStrength = shader.declConstant< Float >( "ShoulderStrength", 0.15_f );
		auto linearStrength = shader.declConstant< Float >( "LinearStrength", 0.50_f );
		auto linearAngle = shader.declConstant< Float >( "LinearAngle", 0.10_f );
		auto toeStrength = shader.declConstant< Float >( "ToeStrength", 0.20_f );
		auto toeNumerator = shader.declConstant< Float >( "ToeNumerator", 0.02_f );
		auto toeDenominator = shader.declConstant< Float >( "ToeDenominator", 0.30_f );
		auto linearWhitePointValue = shader.declConstant< Float >( "LinearWhitePointValue", 11.2_f );
		auto exposureBias = shader.declConstant< Float >( "ExposureBias", 2.0_f );

		auto uncharted2ToneMap = shader.implementFunction< Vec3 >( "uncharted2ToneMap"
			, [&]( Vec3 const & x )
			{
				shader.returnStmt( shader.paren(
					shader.paren(
						x
						* shader.paren( x * shoulderStrength + linearAngle * linearStrength )
						+ toeStrength * toeNumerator )
					/ shader.paren(
						x
						* shader.paren( x * shoulderStrength + linearStrength )
						+ toeStrength * toeDenominator ) )
					- toeNumerator / toeDenominator );
			}
			, InVec3{ &shader, "x" } );

		shader.implementFunction< void >( "main"
			, [&]()
			{
				auto hdrColor = shader.declLocale( "hdrColor"
					, texture( c3d_mapDiffuse, vtx_texture ).rgb() );
				hdrColor *= vec3( exposureBias ); // Hardcoded Exposure Adjustment.

				auto current = shader.declLocale( "current"
					, uncharted2ToneMap( hdrColor * c3d_exposure ) );

				auto whiteScale = shader.declLocale( "whiteScale"
					, vec3( 1.0_f ) / uncharted2ToneMap( vec3( linearWhitePointValue ) ) );
				auto colour = shader.declLocale( "colour"
					, current * whiteScale );

				pxl_rgb = vec4( applyGamma( c3d_gamma, colour ), 1.0 );
			} );

		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
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
