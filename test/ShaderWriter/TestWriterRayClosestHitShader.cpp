#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

#undef CurrentCompilers
#define CurrentCompilers Compilers_SPIRV

#undef ForceDisplayShaders
#define ForceDisplayShaders true

namespace
{
	struct ObjDesc
		: sdw::StructInstance
	{
		ObjDesc( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, txtOffset{ getMember< sdw::Int >( "txtOffset" ) }
			, vertexAddress{ getMember< sdw::UInt64 >( "vertexAddress" ) }
			, indexAddress{ getMember< sdw::UInt64 >( "indexAddress" ) }
			, materialAddress{ getMember< sdw::UInt64 >( "materialAddress" ) }
			, materialIndexAddress{ getMember< sdw::UInt64 >( "materialIndexAddress" ) }
		{
		}

		SDW_DeclStructInstance( , ObjDesc );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "ObjDesc" );

			if ( result->empty() )
			{
				result->declMember( "txtOffset"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
				result->declMember( "vertexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "indexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "materialAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "materialIndexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Int txtOffset;
		sdw::UInt64 vertexAddress;
		sdw::UInt64 indexAddress;
		sdw::UInt64 materialAddress;
		sdw::UInt64 materialIndexAddress;
	};

	struct Vertex
		: sdw::StructInstance
	{
		Vertex( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, pos{ getMember< sdw::Vec3 >( "pos" ) }
			, nrm{ getMember< sdw::Vec3 >( "nrm" ) }
			, color{ getMember< sdw::Vec3 >( "color" ) }
			, texCoord{ getMember< sdw::Vec2 >( "texCoord" ) }
		{
		}

		SDW_DeclStructInstance( , Vertex );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "Vertex" );

			if ( result->empty() )
			{
				result->declMember( "pos"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "nrm"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "color"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "texCoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 pos;
		sdw::Vec3 nrm;
		sdw::Vec3 color;
		sdw::Vec2 texCoord;
	};

	struct WaveFrontMaterial
		: sdw::StructInstance
	{
		WaveFrontMaterial( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, ambient{ getMember< sdw::Vec3 >( "ambient" ) }
			, diffuse{ getMember< sdw::Vec3 >( "diffuse" ) }
			, specular{ getMember< sdw::Vec3 >( "specular" ) }
			, transmittance{ getMember< sdw::Vec3 >( "transmittance" ) }
			, emission{ getMember< sdw::Vec3 >( "emission" ) }
			, shininess{ getMember< sdw::Float >( "shininess" ) }
			, ior{ getMember< sdw::Float >( "ior" ) }
			, dissolve{ getMember< sdw::Float >( "dissolve" ) }
			, illum{ getMember< sdw::Int >( "illum" ) }
			, textureId{ getMember< sdw::Int >( "textureId" ) }
		{
		}

		SDW_DeclStructInstance( , WaveFrontMaterial );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "WaveFrontMaterial" );

			if ( result->empty() )
			{
				result->declMember( "ambient"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "diffuse"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "specular"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "transmittance"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "emission"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "shininess"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "ior"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "dissolve"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "illum"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
				result->declMember( "textureId"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 ambient;
		sdw::Vec3 diffuse;
		sdw::Vec3 specular;
		sdw::Vec3 transmittance;
		sdw::Vec3 emission;
		sdw::Float shininess;
		sdw::Float ior;       // index of refraction
		sdw::Float dissolve;  // 1 == opaque; 0 == fully transparent
		sdw::Int illum;       // illumination model (see http://www.fileformat.info/format/material/)
		sdw::Int textureId;
	};

	void simple( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simple" );
		using namespace sdw;
		{
			RayClosestHitWriter writer;

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto attribs = writer.declHitAttribute< Vec2 >( "attribs" );

			auto prd = writer.declIncomingRayPayload< Vec3 >( "prd", 0u );

			auto objDescs = writer.declArrayShaderStorageBuffer< ObjDesc >( "ObjDescs", 0u, 1u );

			auto Vertices = writer.declBufferReference< ArraySsboT< Vertex > >( "Vertices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto Indices = writer.declBufferReference< ArraySsboT< IVec3 > >( "Indices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );

			writer.implementMain( [&]( RayClosestHitIn in )
				{
					// Object data
					auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< UInt >( in.instanceCustomIndex )] );
					auto indices = Indices( "indices", objResource.indexAddress );
					auto vertices = Vertices( "vertices", objResource.vertexAddress );

					// Indices of the triangle
					auto ind = writer.declLocale( "ind", indices[writer.cast< UInt >( in.primitiveID )] );

					// Vertex of the triangle
					auto v0 = writer.declLocale( "v0", vertices[writer.cast< UInt >( ind.x() )] );
					auto v1 = writer.declLocale( "v1", vertices[writer.cast< UInt >( ind.y() )] );
					auto v2 = writer.declLocale( "v2", vertices[writer.cast< UInt >( ind.z() )] );

					auto const barycentrics = writer.declLocale( "barycentrics"
						, vec3( 1.0_f - attribs.x() - attribs.y(), attribs.x(), attribs.y() ) );

					// Computing the coordinates of the hit position
					auto const pos = writer.declLocale( "pos", v0.pos * barycentrics.x() + v1.pos * barycentrics.y() + v2.pos * barycentrics.z() );
					auto const worldPos = writer.declLocale( "worldPos", in.objectToWorld * vec4( pos, 1.0 ) );  // Transforming the position to world space

					prd = worldPos;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void vecTimesMtx( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vecTimesMtx" );
		using namespace sdw;
		{
			RayClosestHitWriter writer;

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto attribs = writer.declHitAttribute< Vec2 >( "attribs" );

			auto prd = writer.declIncomingRayPayload< Vec3 >( "prd", 0u );

			auto objDescs = writer.declArrayShaderStorageBuffer< ObjDesc >( "ObjDescs", 0u, 1u );

			auto Vertices = writer.declBufferReference< ArraySsboT< Vertex > >( "Vertices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto Indices = writer.declBufferReference< ArraySsboT< IVec3 > >( "Indices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );

			writer.implementMain( [&]( RayClosestHitIn in )
				{
					// Object data
					auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< UInt >( in.instanceCustomIndex )] );
					auto indices = Indices( "indices", objResource.indexAddress );
					auto vertices = Vertices( "vertices", objResource.vertexAddress );

					// Indices of the triangle
					auto ind = writer.declLocale( "ind", indices[writer.cast< UInt >( in.primitiveID )] );

					// Vertex of the triangle
					auto v0 = writer.declLocale( "v0", vertices[writer.cast< UInt >( ind.x() )] );
					auto v1 = writer.declLocale( "v1", vertices[writer.cast< UInt >( ind.y() )] );
					auto v2 = writer.declLocale( "v2", vertices[writer.cast< UInt >( ind.z() )] );

					auto const barycentrics = writer.declLocale( "barycentrics"
						, vec3( 1.0_f - attribs.x() - attribs.y(), attribs.x(), attribs.y() ) );

					// Computing the coordinates of the hit position
					auto const pos = writer.declLocale( "pos", v0.pos * barycentrics.x() + v1.pos * barycentrics.y() + v2.pos * barycentrics.z() );
					auto const worldPos = writer.declLocale( "worldPos", vec3( pos * in.objectToWorld ) );  // Transforming the position to world space

					prd = worldPos;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void dynarraySamplers( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "dynarraySamplers" );
		using namespace sdw;
		{
			RayClosestHitWriter writer;

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto attribs = writer.declHitAttribute< Vec2 >( "attribs" );

			auto prd = writer.declIncomingRayPayload< Vec3 >( "prd", 0u );

			auto objDescs = writer.declArrayShaderStorageBuffer< ObjDesc >( "ObjDescs", 0u, 1u );

			auto Indices = writer.declBufferReference< ArraySsboT< IVec3 > >( "Indices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto textureSamplers = writer.declSampledImageArray< FImg2DRgba32 >( "textureSamplers", 1u, 1u, ast::type::UnknownArraySize );

			writer.implementMain( [&]( RayClosestHitIn in )
				{
					// Object data
					auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< UInt >( in.instanceCustomIndex )] );
					auto indices = Indices( "indices", objResource.indexAddress );

					// Indices of the triangle
					auto ind = writer.declLocale( "ind", writer.cast< UInt >( indices[writer.cast< UInt >( in.primitiveID )].x() ) );

					prd = textureSamplers[ind].lod( attribs.xy(), 0.0_f ).xyz();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void nonUniform( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "nonUniform" );
		using namespace sdw;
		{
			RayClosestHitWriter writer;

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto attribs = writer.declHitAttribute< Vec2 >( "attribs" );

			auto prd = writer.declIncomingRayPayload< Vec3 >( "prd", 0u );

			auto objDescs = writer.declArrayShaderStorageBuffer< ObjDesc >( "ObjDescs", 0u, 1u );

			auto Indices = writer.declBufferReference< ArraySsboT< IVec3 > >( "Indices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto textureSamplers = writer.declSampledImageArray< FImg2DRgba32 >( "textureSamplers", 1u, 1u, ast::type::UnknownArraySize );

			writer.implementMain( [&]( RayClosestHitIn in )
				{
					// Object data
					auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< UInt >( in.instanceCustomIndex )] );
					auto indices = Indices( "indices", objResource.indexAddress );

					// Indices of the triangle
					auto ind = writer.declLocale( "ind", writer.cast< UInt >( indices[writer.cast< UInt >( in.primitiveID )].x() ) );

					prd = textureSamplers[nonuniform( ind )].lod( attribs.xy(), 0.0_f ).xyz();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void wavefrontLighting( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "wavefrontLighting" );
		using namespace sdw;
		{
			RayClosestHitWriter writer;

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto attribs = writer.declHitAttribute< Vec2 >( "attribs" );

			auto prd = writer.declIncomingRayPayload< Vec3 >( "prd", 0u );
			auto isShadowed = writer.declRayPayload< Boolean >( "isShadowed", 1u );

			auto objDescs = writer.declArrayShaderStorageBuffer< ObjDesc >( "ObjDescs", 0u, 1u );
			auto textureSamplers = writer.declSampledImageArray< FImg2DRgba32 >( "textureSamplers", 1u, 1u, ast::type::UnknownArraySize );

			auto pcb = writer.declPushConstantsBuffer( "pcb" );
			auto pcClearColor = pcb.declMember< Vec4 >( "pcClearColor" );
			auto pcLightPosition = pcb.declMember< Vec3 >( "pcLightPosition" );
			auto pcLightIntensity = pcb.declMember< Float >( "pcLightIntensity" );
			auto pcLightType = pcb.declMember< Int >( "pcLightType" );
			pcb.end();

			auto Vertices = writer.declBufferReference< ArraySsboT< Vertex > >( "Vertices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto Indices = writer.declBufferReference< ArraySsboT< IVec3 > >( "Indices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto Materials = writer.declBufferReference< ArraySsboT< WaveFrontMaterial > >( "Materials", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto MatIndices = writer.declBufferReference< ArraySsboT< Int > >( "MatIndices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );

			auto computeDiffuse = writer.implementFunction< Vec3 >( "computeDiffuse"
				, [&]( WaveFrontMaterial mat
					, Vec3 lightDir
					, Vec3 normal )
				{
					// Lambertian
					auto dotNL = writer.declLocale< Float >( "dotNL", max( dot( normal, lightDir ), 0.0_f ) );
					auto c = writer.declLocale< Vec3 >( "c", mat.diffuse * dotNL );
					IF( writer, mat.illum >= 1_i )
					{
						c += mat.ambient;
					}
					FI
					writer.returnStmt( c );
				}
				, InParam< WaveFrontMaterial >{ writer, "mat" }
				, InParam< Vec3 >{ writer, "lightDir" }
				, InParam< Vec3 >{ writer, "normal" } );

			auto computeSpecular = writer.implementFunction< Vec3 >( "computeSpecular"
				, [&]( WaveFrontMaterial mat
					, Vec3 viewDir
					, Vec3 lightDir
					, Vec3 normal )
				{
					IF( writer, mat.illum < 2_i )
					{
						writer.returnStmt( vec3( 0.0_f ) );
					}
					FI;

					// Compute specular only if not in shadow
					auto const kPi = writer.declLocale( "kPi", 3.14159265_f );
					auto const kShininess = writer.declLocale( "kShininess", max( mat.shininess, 4.0_f ) );

					// Specular
					auto kEnergyConservation = writer.declLocale( "kEnergyConservation", ( 2.0 + kShininess ) / ( 2.0 * kPi ) );
					auto V = writer.declLocale( "V", normalize( -viewDir ) );
					auto R = writer.declLocale( "R", reflect( -lightDir, normal ) );
					auto specular = writer.declLocale( "specular", kEnergyConservation * pow( max( dot( V, R ), 0.0_f ), kShininess ) );

					writer.returnStmt( vec3( mat.specular * specular ) );
				}
				, InParam< WaveFrontMaterial >{ writer, "mat" }
				, InParam< Vec3 >{ writer, "viewDir" }
				, InParam< Vec3 >{ writer, "lightDir" }
				, InParam< Vec3 >{ writer, "normal" } );

			writer.implementMain( [&]( RayClosestHitIn in )
				{
					// Object data
					auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< UInt >( in.instanceCustomIndex )] );
					auto matIndices = MatIndices( "matIndices", objResource.materialIndexAddress );
					auto materials = Materials( "materials", objResource.materialAddress );
					auto indices = Indices( "indices", objResource.indexAddress );
					auto vertices = Vertices( "vertices", objResource.vertexAddress );

					// Indices of the triangle
					auto ind = writer.declLocale( "ind", indices[writer.cast< UInt >( in.primitiveID )] );

					// Vertex of the triangle
					auto v0 = writer.declLocale( "v0", vertices[writer.cast< UInt >( ind.x() )] );
					auto v1 = writer.declLocale( "v1", vertices[writer.cast< UInt >( ind.y() )] );
					auto v2 = writer.declLocale( "v2", vertices[writer.cast< UInt >( ind.z() )] );

					auto const barycentrics = writer.declLocale( "barycentrics"
						, vec3( 1.0_f - attribs.x() - attribs.y(), attribs.x(), attribs.y() ) );

					// Computing the coordinates of the hit position
					auto const pos = writer.declLocale( "pos", v0.pos * barycentrics.x() + v1.pos * barycentrics.y() + v2.pos * barycentrics.z() );
					auto const worldPos = writer.declLocale( "worldPos", in.objectToWorld * vec4( pos, 1.0 ) );  // Transforming the position to world space

					// Computing the normal at hit position
					auto const nrm = writer.declLocale( "nrm", v0.nrm * barycentrics.x() + v1.nrm * barycentrics.y() + v2.nrm * barycentrics.z() );
					auto const worldNrm = writer.declLocale( "worldNrm", normalize( vec3( nrm * in.worldToObject ) ) );  // Transforming the normal to world space

					// Vector toward the light
					auto L = writer.declLocale< Vec3 >( "L" );
					auto lightIntensity = writer.declLocale( "lightIntensity", pcLightIntensity );
					auto lightDistance = writer.declLocale( "lightDistance", 100000.0_f );

					// Point light
					IF( writer, pcLightType == 0_i )
					{
						auto lDir = writer.declLocale( "lDir", pcLightPosition - worldPos );
						lightDistance = length( lDir );
						lightIntensity = pcLightIntensity / ( lightDistance * lightDistance );
						L = normalize( lDir );
					}
					ELSE  // Directional light
					{
						L = normalize( pcLightPosition );
					}
					FI;

					// Material of the object
					auto matIdx = writer.declLocale< Int >( "matIdx", matIndices[writer.cast< UInt >( in.primitiveID )] );
					auto mat = writer.declLocale< WaveFrontMaterial >( "mat", materials[writer.cast< UInt >( matIdx )] );

					// Diffuse
					auto diffuse = writer.declLocale< Vec3 >( "diffuse", computeDiffuse( mat, L, worldNrm ) );
					IF( writer, mat.textureId >= 0_i )
					{
						auto txtId = writer.declLocale( "txtId", writer.cast< UInt >( mat.textureId + objDescs[writer.cast< UInt >( in.instanceCustomIndex )].txtOffset ) );
						auto texCoord = writer.declLocale< Vec2 >( "texCoord", v0.texCoord * barycentrics.x() + v1.texCoord * barycentrics.y() + v2.texCoord * barycentrics.z() );
						diffuse *= textureSamplers[nonuniform( txtId )].lod( texCoord, 0.0_f ).xyz();
					}
					FI;

					auto specular = writer.declLocale( "specular", vec3( 0.0_f ) );
					auto attenuation = writer.declLocale( "attenuation", 1.0_f );

					// Tracing shadow ray only if the light is visible from the surface
					IF( writer, dot( worldNrm, L ) > 0.0_f )
					{
						auto tMin = writer.declLocale( "tMin", 0.001_f );
						auto tMax = writer.declLocale( "tMax", lightDistance );
						auto origin = writer.declLocale( "origin", in.worldRayOrigin + in.worldRayDirection * in.rayTmax );
						auto rayDir = writer.declLocale( "rayDir", L );
						auto flags = writer.declLocale( "flags", RayFlags::TerminateOnFirstHit() | RayFlags::Opaque() | RayFlags::SkipClosestHitShader() );
						isShadowed = true;
						writer.traceRay( topLevelAS	// acceleration structure
							, flags					// rayFlags
							, 0xFF_u				// cullMask
							, 0_u					// sbtRecordOffset
							, 0_u					// sbtRecordStride
							, 1_u					// missIndex
							, origin				// ray origin
							, tMin					// ray min range
							, rayDir				// ray direction
							, tMax					// ray max range
							, 1_i );				// payload (location = 1)

						IF( writer, isShadowed )
						{
							attenuation = 0.3_f;
						}
						ELSE
						{
							// Specular
							specular = computeSpecular( mat, in.worldRayDirection, L, worldNrm );
						}
						FI;
					}
					FI;

					prd = vec3( lightIntensity * attenuation * ( diffuse + specular ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterRayClosestHitShader )
{
	sdwTestSuiteBegin();

	//simple( testCounts );
	//vecTimesMtx( testCounts );
	//dynarraySamplers( testCounts );
	nonUniform( testCounts );
	//wavefrontLighting( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterRayClosestHitShader )
