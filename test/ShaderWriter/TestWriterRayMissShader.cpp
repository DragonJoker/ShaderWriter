#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

#undef CurrentCompilers
#define CurrentCompilers Compilers_SPIRV

namespace
{
	void simple( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simple" );
		using namespace sdw;
		{
			RayMissWriter writer;

			auto prd = writer.declRayPayload< Vec3 >( "prd", 0u );

			auto ubo = writer.declUniformBuffer( "GlobalUniforms", 2u, 0u );
			auto clearColor = ubo.declMember< Vec4 >( "clearColor" );
			ubo.end();

			writer.implementMain( [&]( RayMissIn in )
				{
					prd = clearColor.xyz() * 0.8_f;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterRayMissShader )
{
	sdwTestSuiteBegin();

	simple( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterRayMissShader )
