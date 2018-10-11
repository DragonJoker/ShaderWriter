#if 0
#include "ShaderWriter/Utils.hpp"

#include "ShaderWriter/Intrinsics.hpp"

namespace sdw
{
	uint32_t const Utils::MaxIblReflectionLod = 4;

	Utils::Utils( Shader & shader )
		: m_container{ writer }
	{
	}

	void Utils::declareCalcTexCoord()
	{
		m_calcTexCoord = m_container.implementFunction< Vec2 >( cuT( "calcTexCoord" )
			, [&]( Vec2 const & renderSize )
			{
				auto gl_FragCoord = m_container.declBuiltin< Vec4 >( cuT( "gl_FragCoord" ) );
				m_container.returnStmt( gl_FragCoord.xy() / renderSize );
			}
			, InVec2{ &m_container, cuT( "renderSize" ) } );
	}

	void Utils::declareCalcVSPosition()
	{
		m_calcVSPosition = m_container.implementFunction< Vec3 >( cuT( "calcVSPosition" )
			, [&]( Vec2 const & uv
				, Float const & depth
				, Mat4 const & invProj )
			{
				auto csPosition = m_container.declLocale( cuT( "csPosition" )
					, vec3( uv * 2.0f - 1.0f
						, ( m_container.isZeroToOneDepth()
							? depth
							: depth * 2.0f - 1.0f ) ) );
				auto vsPosition = m_container.declLocale( cuT( "vsPosition" )
					, invProj * vec4( csPosition, 1.0 ) );
				vsPosition.xyz() /= vsPosition.w();
				m_container.returnStmt( vsPosition.xyz() );
			}
			, InVec2{ &m_container, cuT( "uv" ) }
			, InFloat{ &m_container, cuT( "depth" ) }
			, InMat4{ &m_container, cuT( "invProj" ) } );
	}

	void Utils::declareCalcWSPosition()
	{
		m_calcWSPosition = m_container.implementFunction< Vec3 >( cuT( "calcWSPosition" )
			, [&]( Vec2 const & uv
				, Float const & depth
				, Mat4 const & invViewProj )
			{
				auto csPosition = m_container.declLocale( cuT( "psPosition" )
					, vec3( uv * 2.0f - 1.0f
						, ( m_container.isZeroToOneDepth()
							? depth
							: depth * 2.0f - 1.0f ) ) );
				auto wsPosition = m_container.declLocale( cuT( "wsPosition" )
					, invViewProj * vec4( csPosition, 1.0 ) );
				wsPosition.xyz() /= wsPosition.w();
				m_container.returnStmt( wsPosition.xyz() );
			}
			, InVec2{ &m_container, cuT( "uv" ) }
			, InFloat{ &m_container, cuT( "depth" ) }
			, InMat4{ &m_container, cuT( "invViewProj" ) } );
	}

	void Utils::declareApplyGamma()
	{
		m_applyGamma = m_container.implementFunction< Vec3 >( cuT( "applyGamma" )
			, [&]( Float const & gamma
				, Vec3 const & hdr )
			{
				m_container.returnStmt( pow( abs( hdr ), vec3( 1.0_f / gamma ) ) );
			}
			, InFloat{ &m_container, cuT( "gamma" ) }
			, InVec3{ &m_container, cuT( "hdr" ) } );
	}

	void Utils::declareRemoveGamma()
	{
		m_removeGamma = m_container.implementFunction< Vec3 >( cuT( "removeGamma" )
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				m_container.returnStmt( pow( abs( srgb ), vec3( gamma ) ) );
			}
			, InFloat{ &m_container, cuT( "gamma" ) }
			, InVec3{ &m_container, cuT( "srgb" ) } );
	}

	void Utils::declareLineariseDepth()
	{
		m_lineariseDepth = m_container.implementFunction< Float >( cuT( "lineariseDepth" )
			, [&]( Float const & depth
				, Float const & nearPlane
				, Float const & farPlane )
			{
				auto z = m_container.declLocale( cuT( "z" )
					, ( m_container.isZeroToOneDepth()
						? depth
						: depth * 2.0_f - 1.0_f ) );
				z *= m_container.paren( farPlane - nearPlane );
				m_container.returnStmt( 2.0 * farPlane * nearPlane / m_container.paren( farPlane + nearPlane - z ) );
			}
			, InFloat{ &m_container, cuT( "depth" ) }
			, InFloat{ &m_container, cuT( "nearPlane" ) }
			, InFloat{ &m_container, cuT( "farPlane" ) } );
	}

	void Utils::declareComputeAccumulation()
	{
		m_computeAccumulation = m_container.implementFunction< Vec4 >( cuT( "computeAccumulation" )
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
				//auto weight = m_container.declLocale( cuT( "weight" ), 1.0_f - z );

				// (10)
				auto z = lineariseDepth( depth
					, nearPlane
					, farPlane );
				auto weight = m_container.declLocale( cuT( "weight" )
					, max( pow( clamp( 1.0_f - depth, 0.0, 1.0 ), 3.0_f ) * 3e3, 1e-2 ) );

				//// (9)
				//auto weight = m_container.declLocale( cuT( "weight" )
				//	, max( min( 0.03_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 4.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (8)
				//auto weight = m_container.declLocale( cuT( "weight" )
				//	, max( min( 10.0_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 6.0_f ) + pow( sdw::abs( z ) / 10.0_f, 3.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (7)
				//auto weight = m_container.declLocale( cuT( "weight" )
				//	, max( min( 10.0_f / writer.paren( pow( sdw::abs( z ) / 200.0_f, 6.0_f ) + pow( sdw::abs( z ) / 5.0_f, 2.0_f ) + 1e-5 ), 3e3 ), 1e-2 ) );

				//// (other)
				//auto a = m_container.declLocale( cuT( "a" )
				//	, min( alpha, 1.0 ) * 8.0 + 0.01 );
				//auto b = m_container.declLocale( cuT( "b" )
				//	, -z * 0.95 + 1.0 );
				///* If your scene has a lot of content very close to the far plane,
				//then include this line (one rsqrt instruction):
				//b /= sqrt(1e4 * abs(csZ)); */
				//auto weight = m_container.declLocale( cuT( "weight" )
				//	, clamp( a * a * a * 1e8 * b * b * b, 1e-2, 3e2 ) );

				m_container.returnStmt( vec4( colour * alpha, alpha ) * weight );
			}
			, InFloat{ &m_container, cuT( "depth" ) }
			, InVec3{ &m_container, cuT( "colour" ) }
			, InFloat{ &m_container, cuT( "alpha" ) }
			, InFloat{ &m_container, cuT( "nearPlane" ) }
			, InFloat{ &m_container, cuT( "farPlane" ) } );
	}

	void Utils::declareGetMapNormal()
	{
		m_getMapNormal = m_container.implementFunction< Vec3 >( cuT( "getMapNormal" )
			, [&]( Vec2 const & uv
				, Vec3 const & normal
				, Vec3 const & position )
			{
				auto c3d_mapNormal( m_container.getBuiltin< Sampler2D >( cuT( "c3d_mapNormal" ) ) );

				auto mapNormal = m_container.declLocale( cuT( "mapNormal" )
					, texture( c3d_mapNormal, uv.xy() ).xyz() );
				mapNormal = sdw::fma( mapNormal
					, vec3( 2.0_f )
					, vec3( -1.0_f ) );
				auto Q1 = m_container.declLocale( cuT( "Q1" )
					, dFdx( position ) );
				auto Q2 = m_container.declLocale( cuT( "Q2" )
					, dFdy( position ) );
				auto st1 = m_container.declLocale( cuT( "st1" )
					, dFdx( uv ) );
				auto st2 = m_container.declLocale( cuT( "st2" )
					, dFdy( uv ) );
				auto N = m_container.declLocale( cuT( "N" )
					, normalize( normal ) );
				auto T = m_container.declLocale( cuT( "T" )
					, normalize( Q1 * st2.t() - Q2 * st1.t() ) );
				auto B = m_container.declLocale( cuT( "B" )
					, -normalize( cross( N, T ) ) );
				auto tbn = m_container.declLocale( cuT( "tbn" )
					, mat3( T, B, N ) );
				m_container.returnStmt( normalize( tbn * mapNormal ) );
			}
			, InVec2{ &m_container, cuT( "uv" ) }
			, InVec3{ &m_container, cuT( "normal" ) }
			, InVec3{ &m_container, cuT( "position" ) } );
	}

	void Utils::declareFresnelSchlick()
	{
		m_fresnelSchlick = m_container.implementFunction< Vec3 >( cuT( "fresnelSchlick" )
			, [&]( Float const & product
				, Vec3 const & f0
				, Float const & roughness )
			{
				m_container.returnStmt( sdw::fma( max( vec3( 1.0_f - roughness ), f0 ) - f0
					, vec3( pow( clamp( 1.0_f - product, 0.0, 1.0 ), 5.0_f ) )
					, f0 ) );
			}
			, InFloat{ &m_container, cuT( "product" ) }
			, InVec3{ &m_container, cuT( "f0" ) }
			, InFloat{ &m_container, cuT( "roughness" ) } );
	}

	void Utils::declareComputeIBL()
	{
		m_computeIBL = m_container.implementFunction< Vec3 >( cuT( "computeIBL" )
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
				auto V = m_container.declLocale( cuT( "V" )
					, normalize( worldEye - position ) );
				auto NdotV = m_container.declLocale( cuT( "NdotV" )
					, max( dot( normal, V ), 0.0 ) );
				auto F = m_container.declLocale( cuT( "F" )
					, fresnelSchlick( NdotV, f0, roughness ) );
				auto kS = m_container.declLocale( cuT( "kS" )
					, F );
				auto kD = m_container.declLocale( cuT( "kD" )
					, vec3( 1.0_f ) - kS );
				kD *= 1.0 - metallic;
				auto irradiance = m_container.declLocale( cuT( "irradiance" )
					, texture( irradianceMap, vec3( normal.x(), -normal.y(), normal.z() ) ).rgb() );
				auto diffuseReflection = m_container.declLocale( cuT( "diffuseReflection" )
					, irradiance * baseColour );

				auto R = m_container.declLocale( cuT( "R" )
					, reflect( -V, normal ) );
				R.y() = -R.y();
				auto prefilteredColor = m_container.declLocale( cuT( "prefilteredColor" )
					, texture( prefilteredEnvMap, R, roughness * MaxIblReflectionLod ).rgb() );
				auto envBRDFCoord = m_container.declLocale( cuT( "envBRDFCoord" )
					, vec2( NdotV, roughness ) );
				auto envBRDF = m_container.declLocale( cuT( "envBRDF" )
					, texture( brdfMap, envBRDFCoord ).rg() );
				auto specularReflection = m_container.declLocale( cuT( "specularReflection" )
					, prefilteredColor * sdw::fma( kS
						, vec3( envBRDF.x() )
						, vec3( envBRDF.y() ) ) );

				m_container.returnStmt( sdw::fma( kD
					, diffuseReflection
					, specularReflection ) );
			}
			, InVec3{ &m_container, cuT( "normal" ) }
			, InVec3{ &m_container, cuT( "position" ) }
			, InVec3{ &m_container, cuT( "albedo" ) }
			, InVec3{ &m_container, cuT( "f0" ) }
			, InFloat{ &m_container, cuT( "roughness" ) }
			, InFloat{ &m_container, cuT( "metallic" ) }
			, InVec3{ &m_container, cuT( "worldEye" ) }
			, InParam< SamplerCube >{ &m_container, cuT( "irradianceMap" ) }
			, InParam< SamplerCube >{ &m_container, cuT( "prefilteredEnvMap" ) }
			, InParam< Sampler2D >{ &m_container, cuT( "brdfMap" ) } );
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
		return writeFunctionCall< Vec3 >( &m_container
			, cuT( "getMapNormal" )
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
#endif
