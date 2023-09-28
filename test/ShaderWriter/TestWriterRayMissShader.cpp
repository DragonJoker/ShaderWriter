#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	struct HitPayload
		: sdw::StructInstance
	{
		HitPayload( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, hitValue{ getMember< sdw::Vec3 >( "hitValue" ) }
		{
		}

		SDW_DeclStructInstance( , HitPayload );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "HitPayload" );

			if ( result->empty() )
			{
				result->declMember( "hitValue"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 hitValue;
	};

	void simple( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simple" );
		using namespace sdw;
		{
			sdw::RayMissWriter writer{ &testCounts.allocator };

			auto ubo = writer.declUniformBuffer( "GlobalUniforms", 2u, 0u );
			auto clearColor = ubo.declMember< Vec4 >( "clearColor" );
			ubo.end();

			writer.implementMainT< HitPayload >( RayPayloadInT< HitPayload >{ writer, 0u }
				, [&]( RayMissIn in, RayPayloadInT< HitPayload > payload )
				{
					payload.hitValue = clearColor.xyz() * 0.8_f;
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
