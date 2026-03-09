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

	using RayMiss = SDWTest;

	TEST_F( RayMiss, construction )
	{
		sdwTestBegin( "construction" );
		{
			sdw::RayMissWriter writer{ &testCounts.allocator };
		}
		{
			sdw::RayMissWriter writer{ 0u, &testCounts.allocator };
		}
		{
			sdw::RayMissWriter writer{ ast::stmt::FunctionFlag::eNone, &testCounts.allocator };
		}
		{
			sdw::RayMissWriter writer{ ast::stmt::FunctionFlag::eMaximalReconvergence, &testCounts.allocator };
		}
		{
			ast::ShaderBuilder builder{ ast::ShaderStage::eRayMiss, &testCounts.allocator };
			sdw::RayMissWriter writer{ builder };
		}
		{
			ast::ShaderBuilder builder{ ast::ShaderStage::eRayMiss, &testCounts.allocator };
			sdw::RayMissWriter writer{ builder, 0u };
		}
		{
			ast::ShaderBuilder builder{ ast::ShaderStage::eRayMiss, &testCounts.allocator };
			sdw::RayMissWriter writer{ builder, ast::stmt::FunctionFlag::eNone };
		}
		{
			ast::ShaderBuilder builder{ ast::ShaderStage::eRayMiss, &testCounts.allocator };
			sdw::RayMissWriter writer{ builder, ast::stmt::FunctionFlag::eMaximalReconvergence };
		}
		sdwTestEnd()
	}

	TEST_F( RayMiss, simple )
	{
		sdwTestBegin( "simple" );
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
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
