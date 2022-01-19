#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

#undef CurrentCompilers
#define CurrentCompilers Compilers_NoHLSL

namespace
{
	void noPayload( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noPayload" );
		using namespace sdw;
		{
			RayGenerationWriter writer;

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto image = writer.declImage< WFImg2DRgba32 >( "image", 1u, 0u );

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
			RayGenerationWriter writer;

			auto prd = writer.declRayPayload< Vec3 >( "prd", 0u );

			auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
			auto image = writer.declImage< WFImg2DRgba32 >( "image", 1u, 0u );

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
						, inUV * 2.0 - 1.0 );

					auto origin = writer.declLocale( "origin"
						, viewInverse * vec4( 0.0_f, 0.0_f, 0.0_f, 1.0_f ) );
					auto target = writer.declLocale( "target"
						, projInverse * vec4( d.x(), d.y(), 1.0_f, 1.0_f ) );
					auto direction = writer.declLocale( "direction"
						, viewInverse * vec4( normalize( target.xyz() ), 0.0_f ) );

					auto rayFlags = writer.declLocale( "rayFlags"
						, RayFlags::Opaque() );
					auto tMin = 0.001_f;
					auto tMax = 10000.0_f;

					prd.traceRay( topLevelAS	// acceleration structure
						, rayFlags				// rayFlags
						, 0xFF_u				// cullMask
						, 0_u					// sbtRecordOffset
						, 0_u					// sbtRecordStride
						, 0_u					// missIndex
						, origin.xyz()			// ray origin
						, tMin					// ray min range
						, direction.xyz()		// ray direction
						, tMax );				// ray max range
					image.store( ivec2( in.launchID.xy() ), vec4( prd, 1.0 ) );
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
