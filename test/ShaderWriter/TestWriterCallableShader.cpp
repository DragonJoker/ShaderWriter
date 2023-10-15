#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

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
			sdw::CallableWriter writer{ &testCounts.allocator };

			auto constants = writer.declPushConstantsBuffer( "constants" );
			auto clearColor = constants.declMember< Vec4 >( "clearColor" );
			auto lightPosition = constants.declMember< Vec3 >( "lightPosition" );
			auto lightIntensity = constants.declMember< Float >( "lightIntensity" );
			auto lightDirection = constants.declMember< Vec3 >( "lightDirection" );
			auto lightSpotCutoff = constants.declMember< Float >( "lightSpotCutoff" );
			auto lightSpotOuterCutoff = constants.declMember< Float >( "lightSpotOuterCutoff" );
			auto lightType = constants.declMember< Int >( "lightType" );
			constants.end();
			
			writer.implementMainT< RayLight >( CallableDataInT< RayLight >{ writer, 0u }
				, [&]( CallableIn in
					, CallableDataInT< RayLight > data )
				{
					data.outLightDistance = 10000000.0_f;
					data.outIntensity = 1.0_f;
					data.outLightDir = normalize( -lightDirection );
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
			sdw::CallableWriter writer{ &testCounts.allocator };

			auto constants = writer.declPushConstantsBuffer( "constants" );
			auto clearColor = constants.declMember< Vec4 >( "clearColor" );
			auto lightPosition = constants.declMember< Vec3 >( "lightPosition" );
			auto lightIntensity = constants.declMember< Float >( "lightIntensity" );
			auto lightDirection = constants.declMember< Vec3 >( "lightDirection" );
			auto lightSpotCutoff = constants.declMember< Float >( "lightSpotCutoff" );
			auto lightSpotOuterCutoff = constants.declMember< Float >( "lightSpotOuterCutoff" );
			auto lightType = constants.declMember< Int >( "lightType" );
			constants.end();
			
			writer.implementMainT< RayLight >( CallableDataInT< RayLight >{ writer, 0u }
				, [&]( CallableIn in
					, CallableDataInT< RayLight > data )
				{
					auto lDir = writer.declLocale( "lDir", lightPosition - data.inHitPosition );
					data.outLightDistance = length( lDir );
					data.outIntensity = lightIntensity / ( data.outLightDistance * data.outLightDistance );
					data.outLightDir = normalize( lDir );
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
			sdw::CallableWriter writer{ &testCounts.allocator };

			auto constants = writer.declPushConstantsBuffer( "constants" );
			auto clearColor = constants.declMember< Vec4 >( "clearColor" );
			auto lightPosition = constants.declMember< Vec3 >( "lightPosition" );
			auto lightIntensity = constants.declMember< Float >( "lightIntensity" );
			auto lightDirection = constants.declMember< Vec3 >( "lightDirection" );
			auto lightSpotCutoff = constants.declMember< Float >( "lightSpotCutoff" );
			auto lightSpotOuterCutoff = constants.declMember< Float >( "lightSpotOuterCutoff" );
			auto lightType = constants.declMember< Int >( "lightType" );
			constants.end();
			
			writer.implementMainT< RayLight >( CallableDataInT< RayLight >{ writer, 0u }
				, [&]( CallableIn in
					, CallableDataInT< RayLight > data )
				{
					auto lDir = writer.declLocale( "lDir", lightPosition - data.inHitPosition );
					data.outLightDistance = length( lDir );
					data.outIntensity = lightIntensity / ( data.outLightDistance * data.outLightDistance );
					data.outLightDir = normalize( lDir );
					auto theta = writer.declLocale( "theta", dot( data.outLightDir, normalize( -lightDirection ) ) );
					auto epsilon = writer.declLocale( "epsilon", lightSpotCutoff - lightSpotOuterCutoff );
					auto spotIntensity = writer.declLocale( "spotIntensity", clamp( ( theta - lightSpotOuterCutoff ) / epsilon, 0.0_f, 1.0_f ) );
					data.outIntensity *= spotIntensity;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterCallableShader )
{
	sdwTestSuiteBegin();

	lightInf( testCounts );
	lightPoint( testCounts );
	lightSpot( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterCallableShader )
