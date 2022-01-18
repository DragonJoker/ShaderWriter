#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

#undef CurrentCompilers
#define CurrentCompilers Compilers_NoHLSL

namespace
{
	struct RayLight
		: sdw::StructInstance
	{
		RayLight( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, inHitPosition{ getMember< sdw::Vec3 >( "inHitPosition" ) }
			, outLightDistance{ getMember < sdw::Float >( "outLightDistance" ) }
			, outLightDir{ getMember < sdw::Vec3 >( "outLightDir" ) }
			, outIntensity{ getMember < sdw::Float >( "outIntensity" ) }
		{
		}

		SDW_DeclStructInstance( , RayLight );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "RayLight" );

			if ( result->empty() )
			{
				result->declMember( "inHitPosition"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "outLightDistance"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "outLightDir"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "outIntensity"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 inHitPosition;
		sdw::Float outLightDistance;
		sdw::Vec3 outLightDir;
		sdw::Float outIntensity;
	};

	void lightInf( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lightInf" );
		using namespace sdw;
		{
			RayCallableWriter writer;

			auto cLight = writer.declIncomingCallableData< RayLight >( "cLight", 0u );

			auto constants = writer.declPushConstantsBuffer( "constants" );
			auto clearColor = constants.declMember< Vec4 >( "clearColor" );
			auto lightPosition = constants.declMember< Vec3 >( "lightPosition" );
			auto lightIntensity = constants.declMember< Float >( "lightIntensity" );
			auto lightDirection = constants.declMember< Vec3 >( "lightDirection" );
			auto lightSpotCutoff = constants.declMember< Float >( "lightSpotCutoff" );
			auto lightSpotOuterCutoff = constants.declMember< Float >( "lightSpotOuterCutoff" );
			auto lightType = constants.declMember< Int >( "lightType" );
			constants.end();

			writer.implementMain( [&]( RayCallableIn in )
				{
					cLight.outLightDistance = 10000000.0_f;
					cLight.outIntensity = 1.0_f;
					cLight.outLightDir = normalize( -lightDirection );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void lightPoint( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lightPoint" );
		using namespace sdw;
		{
			RayCallableWriter writer;

			auto cLight = writer.declIncomingCallableData< RayLight >( "cLight", 0u );

			auto constants = writer.declPushConstantsBuffer( "constants" );
			auto clearColor = constants.declMember< Vec4 >( "clearColor" );
			auto lightPosition = constants.declMember< Vec3 >( "lightPosition" );
			auto lightIntensity = constants.declMember< Float >( "lightIntensity" );
			auto lightDirection = constants.declMember< Vec3 >( "lightDirection" );
			auto lightSpotCutoff = constants.declMember< Float >( "lightSpotCutoff" );
			auto lightSpotOuterCutoff = constants.declMember< Float >( "lightSpotOuterCutoff" );
			auto lightType = constants.declMember< Int >( "lightType" );
			constants.end();

			writer.implementMain( [&]( RayCallableIn in )
				{
					auto lDir = writer.declLocale( "lDir", lightPosition - cLight.inHitPosition );
					cLight.outLightDistance = length( lDir );
					cLight.outIntensity = lightIntensity / ( cLight.outLightDistance * cLight.outLightDistance );
					cLight.outLightDir = normalize( lDir );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void lightSpot( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lightSpot" );
		using namespace sdw;
		{
			RayCallableWriter writer;

			auto cLight = writer.declIncomingCallableData< RayLight >( "cLight", 0u );

			auto constants = writer.declPushConstantsBuffer( "constants" );
			auto clearColor = constants.declMember< Vec4 >( "clearColor" );
			auto lightPosition = constants.declMember< Vec3 >( "lightPosition" );
			auto lightIntensity = constants.declMember< Float >( "lightIntensity" );
			auto lightDirection = constants.declMember< Vec3 >( "lightDirection" );
			auto lightSpotCutoff = constants.declMember< Float >( "lightSpotCutoff" );
			auto lightSpotOuterCutoff = constants.declMember< Float >( "lightSpotOuterCutoff" );
			auto lightType = constants.declMember< Int >( "lightType" );
			constants.end();

			writer.implementMain( [&]( RayCallableIn in )
				{
					auto lDir = writer.declLocale( "lDir", lightPosition - cLight.inHitPosition );
					cLight.outLightDistance = length( lDir );
					cLight.outIntensity = lightIntensity / ( cLight.outLightDistance * cLight.outLightDistance );
					cLight.outLightDir = normalize( lDir );
					auto theta = writer.declLocale( "theta", dot( cLight.outLightDir, normalize( -lightDirection ) ) );
					auto epsilon = writer.declLocale( "epsilon", lightSpotCutoff - lightSpotOuterCutoff );
					auto spotIntensity = writer.declLocale( "spotIntensity", clamp( ( theta - lightSpotOuterCutoff ) / epsilon, 0.0_f, 1.0_f ) );
					cLight.outIntensity *= spotIntensity;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterRayIntersectionShader )
{
	sdwTestSuiteBegin();

	lightInf( testCounts );
	lightPoint( testCounts );
	lightSpot( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterRayIntersectionShader )
