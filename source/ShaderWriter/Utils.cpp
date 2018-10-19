/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Utils.hpp"

#include "ShaderWriter/Intrinsics.hpp"
#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	uint32_t const Utils::MaxIblReflectionLod = 4;

	Utils::Utils( ShaderWriter & writer )
		: m_writer{ writer }
	{
	}

	void Utils::declareCalcTexCoord()
	{
		m_calcTexCoord = m_writer.implementFunction< Vec2 >( "calcTexCoord"
			, [&]( Vec2 const & renderSize )
			{
				auto gl_FragCoord = m_writer.declBuiltin< Vec4 >( "gl_FragCoord" );
				m_writer.returnStmt( gl_FragCoord.xy() / renderSize );
			}
			, InVec2{ m_writer, "renderSize" } );
	}

	void Utils::declareCalcVSPosition()
	{
		m_calcVSPosition = m_writer.implementFunction< Vec3 >( "calcVSPosition"
			, [&]( Vec2 const & uv
				, Float const & depth
				, Mat4 const & invProj )
			{
				auto csPosition = m_writer.declLocale( "csPosition"
					, vec3( uv * 2.0_f - 1.0_f, depth ) );
				auto vsPosition = m_writer.declLocale( "vsPosition"
					, invProj * vec4( csPosition, 1.0 ) );
				vsPosition.xyz() /= vsPosition.w();
				m_writer.returnStmt( vsPosition.xyz() );
			}
			, InVec2{ m_writer, "uv" }
			, InFloat{ m_writer, "depth" }
			, InMat4{ m_writer, "invProj" } );
	}

	void Utils::declareCalcWSPosition()
	{
		m_calcWSPosition = m_writer.implementFunction< Vec3 >( "calcWSPosition"
			, [&]( Vec2 const & uv
				, Float const & depth
				, Mat4 const & invViewProj )
			{
				auto csPosition = m_writer.declLocale( "psPosition"
					, vec3( uv * 2.0_f - 1.0_f, depth ) );
				auto wsPosition = m_writer.declLocale( "wsPosition"
					, invViewProj * vec4( csPosition, 1.0 ) );
				wsPosition.xyz() /= wsPosition.w();
				m_writer.returnStmt( wsPosition.xyz() );
			}
			, InVec2{ m_writer, "uv" }
			, InFloat{ m_writer, "depth" }
			, InMat4{ m_writer, "invViewProj" } );
	}

	void Utils::declareApplyGamma()
	{
		m_applyGamma = m_writer.implementFunction< Vec3 >( "applyGamma"
			, [&]( Float const & gamma
				, Vec3 const & hdr )
			{
				m_writer.returnStmt( pow( abs( hdr ), vec3( 1.0_f / gamma ) ) );
			}
			, InFloat{ m_writer, "gamma" }
			, InVec3{ m_writer, "hdr" } );
	}

	void Utils::declareRemoveGamma()
	{
		m_removeGamma = m_writer.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				m_writer.returnStmt( pow( abs( srgb ), vec3( gamma ) ) );
			}
			, InFloat{ m_writer, "gamma" }
			, InVec3{ m_writer, "srgb" } );
	}

	void Utils::declareLineariseDepth()
	{
		m_lineariseDepth = m_writer.implementFunction< Float >( "lineariseDepth"
			, [&]( Float const & depth
				, Float const & nearPlane
				, Float const & farPlane )
			{
				auto z = m_writer.declLocale( "z"
					, depth );
				z *= Float{ farPlane - nearPlane };
				m_writer.returnStmt( 2.0 * farPlane * nearPlane / Float{ farPlane + nearPlane - z } );
			}
			, InFloat{ m_writer, "depth" }
			, InFloat{ m_writer, "nearPlane" }
			, InFloat{ m_writer, "farPlane" } );
	}

	void Utils::declareComputeAccumulation()
	{
		m_computeAccumulation = m_writer.implementFunction< Vec4 >( "computeAccumulation"
			, [&]( Float const & depth
				, Vec3 const & colour
				, Float const & alpha
				, Float const & nearPlane
				, Float const & farPlane )
			{
				//// Naive
				//auto z = utils.lineariseDepth( z
				//	, nearPlane
				//	, farPlane );
				//auto weight = m_writer.declLocale( "weight", 1.0_f - z );

				// (10)
				auto z = lineariseDepth( depth
					, nearPlane
					, farPlane );
				auto weight = m_writer.declLocale( "weight"
					, max( pow( clamp( 1.0_f - depth, 0.0_f, 1.0_f ), 3.0_f ) * 3e3_f, 1e-2_f ) );

				//// (9)
				//auto weight = m_writer.declLocale( "weight"
				//	, max( min( 0.03_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 4.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (8)
				//auto weight = m_writer.declLocale( "weight"
				//	, max( min( 10.0_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 6.0_f ) + pow( sdw::abs( z ) / 10.0_f, 3.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (7)
				//auto weight = m_writer.declLocale( "weight"
				//	, max( min( 10.0_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 6.0_f ) + pow( sdw::abs( z ) / 5.0_f, 2.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (other)
				//auto a = m_writer.declLocale( "a"
				//	, min( alpha, 1.0 ) * 8.0 + 0.01 );
				//auto b = m_writer.declLocale( "b"
				//	, -z * 0.95 + 1.0 );
				///* If your scene has a lot of content very close to the far plane,
				//then include this line (one rsqrt instruction):
				//b /= sqrt(1e4 * abs(csZ)); */
				//auto weight = m_writer.declLocale( "weight"
				//	, clamp( a * a * a * 1e8 * b * b * b, 1e-2, 3e2 ) );

				m_writer.returnStmt( vec4( colour * alpha, alpha ) * weight );
			}
			, InFloat{ m_writer, "depth" }
			, InVec3{ m_writer, "colour" }
			, InFloat{ m_writer, "alpha" }
			, InFloat{ m_writer, "nearPlane" }
			, InFloat{ m_writer, "farPlane" } );
	}

	void Utils::declareGetMapNormal()
	{
		m_getMapNormal = m_writer.implementFunction< Vec3 >( "getMapNormal"
			, [&]( Vec2 const & uv
				, Vec3 const & normal
				, Vec3 const & position )
			{
				auto c3d_mapNormal( m_writer.getBuiltin< Sampler2D >( "c3d_mapNormal" ) );

				auto mapNormal = m_writer.declLocale( "mapNormal"
					, texture( c3d_mapNormal, uv.xy() ).xyz() );
				mapNormal = sdw::fma( mapNormal
					, vec3( 2.0_f )
					, vec3( -1.0_f ) );
				auto Q1 = m_writer.declLocale( "Q1"
					, dFdx( position ) );
				auto Q2 = m_writer.declLocale( "Q2"
					, dFdy( position ) );
				auto st1 = m_writer.declLocale( "st1"
					, dFdx( uv ) );
				auto st2 = m_writer.declLocale( "st2"
					, dFdy( uv ) );
				auto N = m_writer.declLocale( "N"
					, normalize( normal ) );
				auto T = m_writer.declLocale( "T"
					, normalize( Q1 * st2.t() - Q2 * st1.t() ) );
				auto B = m_writer.declLocale( "B"
					, -normalize( cross( N, T ) ) );
				auto tbn = m_writer.declLocale( "tbn"
					, mat3( T, B, N ) );
				m_writer.returnStmt( normalize( tbn * mapNormal ) );
			}
			, InVec2{ m_writer, "uv" }
			, InVec3{ m_writer, "normal" }
			, InVec3{ m_writer, "position" } );
	}

	void Utils::declareFresnelSchlick()
	{
		m_fresnelSchlick = m_writer.implementFunction< Vec3 >( "fresnelSchlick"
			, [&]( Float const & product
				, Vec3 const & f0
				, Float const & roughness )
			{
				m_writer.returnStmt( sdw::fma( max( vec3( 1.0_f - roughness ), f0 ) - f0
					, vec3( pow( clamp( 1.0_f - product, 0.0_f, 1.0_f ), 5.0_f ) )
					, f0 ) );
			}
			, InFloat{ m_writer, "product" }
			, InVec3{ m_writer, "f0" }
			, InFloat{ m_writer, "roughness" } );
	}

	void Utils::declareComputeIBL()
	{
		m_computeIBL = m_writer.implementFunction< Vec3 >( "computeIBL"
			, [&]( Vec3 const & normal
				, Vec3 const & position
				, Vec3 const & baseColour
				, Vec3 const & f0
				, Float const & roughness
				, Float const & metallic
				, Vec3 const & worldEye
				, SamplerCube const & irradianceMap
				, SamplerCube const & prefilteredEnvMap
				, Sampler2D const & brdfMap )
			{
				auto V = m_writer.declLocale( "V"
					, normalize( worldEye - position ) );
				auto NdotV = m_writer.declLocale( "NdotV"
					, max( dot( normal, V ), 0.0_f ) );
				auto F = m_writer.declLocale( "F"
					, fresnelSchlick( NdotV, f0, roughness ) );
				auto kS = m_writer.declLocale( "kS"
					, F );
				auto kD = m_writer.declLocale( "kD"
					, vec3( 1.0_f ) - kS );
				kD *= 1.0 - metallic;
				auto irradiance = m_writer.declLocale( "irradiance"
					, texture( irradianceMap, vec3( normal.x(), -normal.y(), normal.z() ) ).rgb() );
				auto diffuseReflection = m_writer.declLocale( "diffuseReflection"
					, irradiance * baseColour );

				auto R = m_writer.declLocale( "R"
					, reflect( -V, normal ) );
				R.y() = -R.y();
				auto prefilteredColor = m_writer.declLocale( "prefilteredColor"
					, texture( prefilteredEnvMap, R, roughness * Float{ float( MaxIblReflectionLod ) } ).rgb() );
				auto envBRDFCoord = m_writer.declLocale( "envBRDFCoord"
					, vec2( NdotV, roughness ) );
				auto envBRDF = m_writer.declLocale( "envBRDF"
					, texture( brdfMap, envBRDFCoord ).rg() );
				auto specularReflection = m_writer.declLocale( "specularReflection"
					, prefilteredColor * sdw::fma( kS
						, vec3( envBRDF.x() )
						, vec3( envBRDF.y() ) ) );

				m_writer.returnStmt( sdw::fma( kD
					, diffuseReflection
					, specularReflection ) );
			}
			, InVec3{ m_writer, "normal" }
			, InVec3{ m_writer, "position" }
			, InVec3{ m_writer, "albedo" }
			, InVec3{ m_writer, "f0" }
			, InFloat{ m_writer, "roughness" }
			, InFloat{ m_writer, "metallic" }
			, InVec3{ m_writer, "worldEye" }
			, InParam< SamplerCube >{ m_writer, "irradianceMap" }
			, InParam< SamplerCube >{ m_writer, "prefilteredEnvMap" }
			, InParam< Sampler2D >{ m_writer, "brdfMap" } );
	}

	Vec2 Utils::calcTexCoord( Vec2 const & renderSize )
	{
		return m_calcTexCoord( renderSize );
	}

	Vec3 Utils::calcVSPosition( Vec2 const & uv
		, Float const & depth
		, Mat4 const & invProj )
	{
		return m_calcVSPosition( uv
			, depth
			, invProj );
	}

	Vec3 Utils::calcWSPosition( Vec2 const & uv
		, Float const & depth
		, Mat4 const & invViewProj )
	{
		return m_calcWSPosition( uv
			, depth
			, invViewProj );
	}

	Vec3 Utils::applyGamma( Float const & gamma
		, Vec3 const & hdr )
	{
		return m_applyGamma( gamma, hdr );
	}

	Vec3 Utils::removeGamma( Float const & gamma
		, Vec3 const & srgb )
	{
		return m_removeGamma( gamma, srgb );
	}

	Vec3 Utils::getMapNormal( Vec2 const & uv
		, Vec3 const & normal
		, Vec3 const & position )
	{
		return getFunctionCall< Vec3 >( "getMapNormal"
			, uv
			, normal
			, position );
	}

	Float Utils::lineariseDepth( Float const & depth
		, Float const & nearPlane
		, Float const & farPlane )
	{
		return m_lineariseDepth( depth
			, nearPlane
			, farPlane );
	}

	Vec4 Utils::computeAccumulation( Float const & depth
		, Vec3 const & colour
		, Float const & alpha
		, Float const & nearPlane
		, Float const & farPlane )
	{
		return m_computeAccumulation( depth
			, colour
			, alpha
			, nearPlane
			, farPlane );
	}

	Vec3 Utils::fresnelSchlick( Float const & product
		, Vec3 const & f0
		, Float const & roughness )
	{
		return m_fresnelSchlick( product
			, f0
			, roughness );
	}

	Vec3 Utils::computeMetallicIBL( Vec3 const & normal
		, Vec3 const & position
		, Vec3 const & albedo
		, Float const & metallic
		, Float const & roughness
		, Vec3 const & worldEye
		, SamplerCube const & irradianceMap
		, SamplerCube const & prefilteredEnvMap
		, Sampler2D const & brdfMap )
	{
		return m_computeIBL( normal
			, position
			, albedo
			, mix( vec3( 0.04_f ), albedo, metallic )
			, roughness
			, metallic
			, worldEye
			, irradianceMap
			, prefilteredEnvMap
			, brdfMap );
	}

	Vec3 Utils::computeSpecularIBL( Vec3 const & normal
		, Vec3 const & position
		, Vec3 const & diffuse
		, Vec3 const & specular
		, Float const & glossiness
		, Vec3 const & worldEye
		, SamplerCube const & irradianceMap
		, SamplerCube const & prefilteredEnvMap
		, Sampler2D const & brdfMap )
	{
		return m_computeIBL( normal
			, position
			, diffuse
			, specular
			, 1.0_f - glossiness
			, length( specular )
			, worldEye
			, irradianceMap
			, prefilteredEnvMap
			, brdfMap );
	}
}
