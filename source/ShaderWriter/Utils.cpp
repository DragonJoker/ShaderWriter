#include "ShaderWriter/Utils.hpp"

#include "ShaderWriter/Intrinsics.hpp"
#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	uint32_t const Utils::MaxIblReflectionLod = 4;

	Utils::Utils( Shader & shader )
		: m_shader{ shader }
	{
	}

	void Utils::declareCalcTexCoord()
	{
		m_calcTexCoord = m_shader.implementFunction< Vec2 >( "calcTexCoord"
			, [&]( Vec2 const & renderSize )
			{
				auto gl_FragCoord = m_shader.declBuiltin< Vec4 >( "gl_FragCoord" );
				m_shader.returnStmt( gl_FragCoord.xy() / renderSize );
			}
			, InVec2{ &m_shader, "renderSize" } );
	}

	void Utils::declareCalcVSPosition()
	{
		m_calcVSPosition = m_shader.implementFunction< Vec3 >( "calcVSPosition"
			, [&]( Vec2 const & uv
				, Float const & depth
				, Mat4 const & invProj )
			{
				auto csPosition = m_shader.declLocale( "csPosition"
					, vec3( uv * 2.0_f - 1.0_f, depth ) );
				auto vsPosition = m_shader.declLocale( "vsPosition"
					, invProj * vec4( csPosition, 1.0 ) );
				vsPosition.xyz() /= vsPosition.w();
				m_shader.returnStmt( vsPosition.xyz() );
			}
			, InVec2{ &m_shader, "uv" }
			, InFloat{ &m_shader, "depth" }
			, InMat4{ &m_shader, "invProj" } );
	}

	void Utils::declareCalcWSPosition()
	{
		m_calcWSPosition = m_shader.implementFunction< Vec3 >( "calcWSPosition"
			, [&]( Vec2 const & uv
				, Float const & depth
				, Mat4 const & invViewProj )
			{
				auto csPosition = m_shader.declLocale( "psPosition"
					, vec3( uv * 2.0_f - 1.0_f, depth ) );
				auto wsPosition = m_shader.declLocale( "wsPosition"
					, invViewProj * vec4( csPosition, 1.0 ) );
				wsPosition.xyz() /= wsPosition.w();
				m_shader.returnStmt( wsPosition.xyz() );
			}
			, InVec2{ &m_shader, "uv" }
			, InFloat{ &m_shader, "depth" }
			, InMat4{ &m_shader, "invViewProj" } );
	}

	void Utils::declareApplyGamma()
	{
		m_applyGamma = m_shader.implementFunction< Vec3 >( "applyGamma"
			, [&]( Float const & gamma
				, Vec3 const & hdr )
			{
				m_shader.returnStmt( pow( abs( hdr ), vec3( 1.0_f / gamma ) ) );
			}
			, InFloat{ &m_shader, "gamma" }
			, InVec3{ &m_shader, "hdr" } );
	}

	void Utils::declareRemoveGamma()
	{
		m_removeGamma = m_shader.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				m_shader.returnStmt( pow( abs( srgb ), vec3( gamma ) ) );
			}
			, InFloat{ &m_shader, "gamma" }
			, InVec3{ &m_shader, "srgb" } );
	}

	void Utils::declareLineariseDepth()
	{
		m_lineariseDepth = m_shader.implementFunction< Float >( "lineariseDepth"
			, [&]( Float const & depth
				, Float const & nearPlane
				, Float const & farPlane )
			{
				auto z = m_shader.declLocale( "z"
					, depth );
				z *= Float{ farPlane - nearPlane };
				m_shader.returnStmt( 2.0 * farPlane * nearPlane / Float{ farPlane + nearPlane - z } );
			}
			, InFloat{ &m_shader, "depth" }
			, InFloat{ &m_shader, "nearPlane" }
			, InFloat{ &m_shader, "farPlane" } );
	}

	void Utils::declareComputeAccumulation()
	{
		m_computeAccumulation = m_shader.implementFunction< Vec4 >( "computeAccumulation"
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
				//auto weight = m_shader.declLocale( "weight", 1.0_f - z );

				// (10)
				auto z = lineariseDepth( depth
					, nearPlane
					, farPlane );
				auto weight = m_shader.declLocale( "weight"
					, max( pow( clamp( 1.0_f - depth, 0.0, 1.0 ), 3.0_f ) * 3e3, 1e-2 ) );

				//// (9)
				//auto weight = m_shader.declLocale( "weight"
				//	, max( min( 0.03_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 4.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (8)
				//auto weight = m_shader.declLocale( "weight"
				//	, max( min( 10.0_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 6.0_f ) + pow( sdw::abs( z ) / 10.0_f, 3.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (7)
				//auto weight = m_shader.declLocale( "weight"
				//	, max( min( 10.0_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 6.0_f ) + pow( sdw::abs( z ) / 5.0_f, 2.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (other)
				//auto a = m_shader.declLocale( "a"
				//	, min( alpha, 1.0 ) * 8.0 + 0.01 );
				//auto b = m_shader.declLocale( "b"
				//	, -z * 0.95 + 1.0 );
				///* If your scene has a lot of content very close to the far plane,
				//then include this line (one rsqrt instruction):
				//b /= sqrt(1e4 * abs(csZ)); */
				//auto weight = m_shader.declLocale( "weight"
				//	, clamp( a * a * a * 1e8 * b * b * b, 1e-2, 3e2 ) );

				m_shader.returnStmt( vec4( colour * alpha, alpha ) * weight );
			}
			, InFloat{ &m_shader, "depth" }
			, InVec3{ &m_shader, "colour" }
			, InFloat{ &m_shader, "alpha" }
			, InFloat{ &m_shader, "nearPlane" }
			, InFloat{ &m_shader, "farPlane" } );
	}

	void Utils::declareGetMapNormal()
	{
		m_getMapNormal = m_shader.implementFunction< Vec3 >( "getMapNormal"
			, [&]( Vec2 const & uv
				, Vec3 const & normal
				, Vec3 const & position )
			{
				auto c3d_mapNormal( m_shader.getBuiltin< Sampler2D >( "c3d_mapNormal" ) );

				auto mapNormal = m_shader.declLocale( "mapNormal"
					, texture( c3d_mapNormal, uv.xy() ).xyz() );
				mapNormal = sdw::fma( mapNormal
					, vec3( 2.0_f )
					, vec3( -1.0_f ) );
				auto Q1 = m_shader.declLocale( "Q1"
					, dFdx( position ) );
				auto Q2 = m_shader.declLocale( "Q2"
					, dFdy( position ) );
				auto st1 = m_shader.declLocale( "st1"
					, dFdx( uv ) );
				auto st2 = m_shader.declLocale( "st2"
					, dFdy( uv ) );
				auto N = m_shader.declLocale( "N"
					, normalize( normal ) );
				auto T = m_shader.declLocale( "T"
					, normalize( Q1 * st2.t() - Q2 * st1.t() ) );
				auto B = m_shader.declLocale( "B"
					, -normalize( cross( N, T ) ) );
				auto tbn = m_shader.declLocale( "tbn"
					, mat3( T, B, N ) );
				m_shader.returnStmt( normalize( tbn * mapNormal ) );
			}
			, InVec2{ &m_shader, "uv" }
			, InVec3{ &m_shader, "normal" }
			, InVec3{ &m_shader, "position" } );
	}

	void Utils::declareFresnelSchlick()
	{
		m_fresnelSchlick = m_shader.implementFunction< Vec3 >( "fresnelSchlick"
			, [&]( Float const & product
				, Vec3 const & f0
				, Float const & roughness )
			{
				m_shader.returnStmt( sdw::fma( max( vec3( 1.0_f - roughness ), f0 ) - f0
					, vec3( pow( clamp( 1.0_f - product, 0.0, 1.0 ), 5.0_f ) )
					, f0 ) );
			}
			, InFloat{ &m_shader, "product" }
			, InVec3{ &m_shader, "f0" }
			, InFloat{ &m_shader, "roughness" } );
	}

	void Utils::declareComputeIBL()
	{
		m_computeIBL = m_shader.implementFunction< Vec3 >( "computeIBL"
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
				auto V = m_shader.declLocale( "V"
					, normalize( worldEye - position ) );
				auto NdotV = m_shader.declLocale( "NdotV"
					, max( dot( normal, V ), 0.0 ) );
				auto F = m_shader.declLocale( "F"
					, fresnelSchlick( NdotV, f0, roughness ) );
				auto kS = m_shader.declLocale( "kS"
					, F );
				auto kD = m_shader.declLocale( "kD"
					, vec3( 1.0_f ) - kS );
				kD *= 1.0 - metallic;
				auto irradiance = m_shader.declLocale( "irradiance"
					, texture( irradianceMap, vec3( normal.x(), -normal.y(), normal.z() ) ).rgb() );
				auto diffuseReflection = m_shader.declLocale( "diffuseReflection"
					, irradiance * baseColour );

				auto R = m_shader.declLocale( "R"
					, reflect( -V, normal ) );
				R.y() = -R.y();
				auto prefilteredColor = m_shader.declLocale( "prefilteredColor"
					, texture( prefilteredEnvMap, R, roughness * Float{ float( MaxIblReflectionLod ) } ).rgb() );
				auto envBRDFCoord = m_shader.declLocale( "envBRDFCoord"
					, vec2( NdotV, roughness ) );
				auto envBRDF = m_shader.declLocale( "envBRDF"
					, texture( brdfMap, envBRDFCoord ).rg() );
				auto specularReflection = m_shader.declLocale( "specularReflection"
					, prefilteredColor * sdw::fma( kS
						, vec3( envBRDF.x() )
						, vec3( envBRDF.y() ) ) );

				m_shader.returnStmt( sdw::fma( kD
					, diffuseReflection
					, specularReflection ) );
			}
			, InVec3{ &m_shader, "normal" }
			, InVec3{ &m_shader, "position" }
			, InVec3{ &m_shader, "albedo" }
			, InVec3{ &m_shader, "f0" }
			, InFloat{ &m_shader, "roughness" }
			, InFloat{ &m_shader, "metallic" }
			, InVec3{ &m_shader, "worldEye" }
			, InParam< SamplerCube >{ &m_shader, "irradianceMap" }
			, InParam< SamplerCube >{ &m_shader, "prefilteredEnvMap" }
			, InParam< Sampler2D >{ &m_shader, "brdfMap" } );
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
