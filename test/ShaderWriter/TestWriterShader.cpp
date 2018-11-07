#include "../Common.hpp"
#include "TestWriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>
#include <ShaderWriter/PerVertex.hpp>

#include <fstream>

namespace
{
	void writeShader( sdw::Shader const & shader
		, sdw::ShaderType type
		, std::string const & name )
	{
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// Statements" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
		std::cout << sdw::writeDebug( shader ) << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// GLSL" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
		std::cout << sdw::writeGlsl( shader, type ) << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// HLSL" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
		std::cout << sdw::writeHlsl( shader, type ) << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// SPIR-V" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////////" << std::endl << std::endl;
		std::cout << sdw::writeSpirv( shader, type ) << std::endl;

		{
			auto binary = sdw::serializeSpirv( shader, type );
			FILE * stream = fopen( ( test::getExecutableDirectory() + name + ".spv" ).c_str(), "wb" );

			if ( stream )
			{
				fwrite( binary.data()
					, sizeof( uint32_t )
					, binary.size()
					, stream );
				fclose( stream );
			}
		}
	}

	void reference()
	{
		testBegin( "reference" );
		using namespace sdw;

		ShaderWriter writer{ false };
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

				IF( writer, cond )
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

		writeShader( writer.getShader()
			, sdw::ShaderType::eFragment
			, "reference" );
		testEnd();
	}

	void vertex()
	{
		testBegin( "vertex" );
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

		writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, "vertex" );
		testEnd();
	}

	void fragment()
	{
		testBegin( "fragment" );
		using namespace sdw;

		ShaderWriter writer{ false };
		// Shader inputs
		Ubo hdrConfig{ writer, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapDiffuse = writer.declSampledImage< Img2DRGBA32F >( "c3d_mapDiffuse", 1u, 0u );
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
			, [&]( SampledImage2DRgba32f const & tex
				, Vec2 const & coords )
			{
				writer.returnStmt( texture( tex, coords ).rgb() );
			}
			, InSampledImage2DRgba32f{ writer, "tex" }
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

		writeShader( writer.getShader()
			, sdw::ShaderType::eFragment
			, "fragment" );
		testEnd();
	}

	void compute()
	{
		testBegin( "compute" );
		using namespace sdw;
		ShaderWriter writer{ false };
		auto gl_GlobalInvocationID = writer.declBuiltin< UVec3 >( "gl_GlobalInvocationID" );
		Ssbo ssbo{ writer, "SSBO", 0u, 0u };
		auto uints = ssbo.declMemberArray< UInt >( "uints" );
		ssbo.end();

		writer.inputComputeLayout( 16 );
		writer.implementFunction< void >( "main"
			, [&]()
			{
				uints[gl_GlobalInvocationID.x()] = uints[gl_GlobalInvocationID.x()] * uints[gl_GlobalInvocationID.x()];
			} );

		writeShader( writer.getShader()
			, sdw::ShaderType::eCompute
			, "compute" );
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterShader" );
	reference();
	vertex();
	fragment();
	compute();
	testSuiteEnd();
}
