#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	void noPayload( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noPayload" );
		using namespace sdw;
		{
			sdw::RayGenerationWriter writer{ &testCounts.allocator };

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto image = writer.declStorageImg< WFImg2DRgba32 >( "image", 1u, 0u );

			writer.implementMain( [&]( RayGenerationIn in )
				{
					image.store( ivec2( in.launchID.xy() ), vec4( 0.5_f, 0.5_f, 0.5_f, 1.0_f ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void simple( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simple" );
		using namespace sdw;
		{
			sdw::RayGenerationWriter writer{ &testCounts.allocator };

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto image = writer.declStorageImg< WFImg2DRgba32 >( "image", 1u, 0u );

			auto ubo = writer.declUniformBuffer( "GlobalUniforms", 2u, 0u );
			auto viewProj = ubo.declMember< Mat4 >( "viewProj" );
			auto viewInverse = ubo.declMember< Mat4 >( "viewInverse" );
			auto projInverse = ubo.declMember< Mat4 >( "projInverse" );
			ubo.end();

			writer.implementMain( [&]( RayGenerationIn in )
				{
					auto const pixelCenter = writer.declLocale( "pixelCenter"
						, vec2( in.launchID.xy() ) + vec2( 0.5_f ) );
					auto const inUV = writer.declLocale( "inUV"
						, pixelCenter / vec2( in.launchSize.xy() ) );
					auto d = writer.declLocale( "d"
						, inUV * 2.0_f - 1.0_f );

					auto target = writer.declLocale( "target"
						, projInverse * vec4( d.x(), d.y(), 1.0_f, 1.0_f ) );

					auto rayFlags = writer.declLocale( "rayFlags"
						, RayFlags::Opaque() );
					auto ray = writer.declLocale< RayDesc >( "ray" );
					ray.origin = vec3( viewInverse * vec4( 0.0_f, 0.0_f, 0.0_f, 1.0_f ) );
					ray.direction = vec3( viewInverse * vec4( normalize( target.xyz() ), 0.0_f ) );
					ray.tMin = 0.001_f;
					ray.tMax = 10000.0_f;
					auto prd = writer.declRayPayload< Vec3 >( "prd", 0u );
					prd.traceRay( topLevelAS	// acceleration structure
						, rayFlags				// rayFlags
						, 0xFF_u				// cullMask
						, 0_u					// sbtRecordOffset
						, 0_u					// sbtRecordStride
						, 0_u					// missIndex
						, ray );
					image.store( ivec2( in.launchID.xy() ), vec4( prd, 1.0_f ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterRayGenerationShader )
{
	sdwTestSuiteBegin();

	noPayload( testCounts );
	simple( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterRayGenerationShader )
