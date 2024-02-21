#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/TraditionalGraphicsWriter.hpp>

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	struct Data
		: public sdw::StructInstanceHelperT< "Data"
			, sdw::type::MemoryLayout::eStd430
			, sdw::UIntField< "isFree" >
			, sdw::UIntField< "data" > >
	{
		Data( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: StructInstanceHelperT{ writer, std::move( expr ), enabled }
		{
		}

		auto isFree()const { return getMember< "isFree" >(); }
		auto data()const { return getMember< "data" >(); }
	};

	struct QuadControl : public SDWTest
	{
	};

	TEST_F( QuadControl, testSubgroupQuadAny )
	{
		sdwTestBegin( "testSubgroupQuadAny" );
		sdw::ComputeWriter writer{ &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( 4, 4
			, [&]( sdw::ComputeIn const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAny( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAll )
	{
		sdwTestBegin( "testSubgroupQuadAll" );
		sdw::ComputeWriter writer{ &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( 4, 4
			, [&]( sdw::ComputeIn const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAll( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAnyMaximiseReconvergence )
	{
		sdwTestBegin( "testSubgroupQuadAnyMaximiseReconvergence" );
		sdw::ComputeWriter writer{ ast::stmt::FunctionFlag::eMaximalReconvergence
			, &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( 4, 4
			, [&]( sdw::ComputeIn const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAny( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAllMaximiseReconvergence )
	{
		sdwTestBegin( "testSubgroupQuadAllMaximiseReconvergence" );
		sdw::ComputeWriter writer{ ast::stmt::FunctionFlag::eMaximalReconvergence
			, &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( 4, 4
			, [&]( sdw::ComputeIn const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAll( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAnyFull )
	{
		sdwTestBegin( "testSubgroupQuadAnyFull" );
		sdw::FragmentWriter writer{ ast::stmt::FunctionFlag::eFullQuads
			, &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAny( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAllFull )
	{
		sdwTestBegin( "testSubgroupQuadAllFull" );
		sdw::FragmentWriter writer{ ast::stmt::FunctionFlag::eFullQuads
			, &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAll( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAnyMaximiseReconvergenceFull )
	{
		sdwTestBegin( "testSubgroupQuadAnyMaximiseReconvergenceFull" );
		sdw::FragmentWriter writer{ ast::stmt::FunctionFlag::eFullQuads | ast::stmt::FunctionFlag::eMaximalReconvergence
			, &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAny( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAllMaximiseReconvergenceFull )
	{
		sdwTestBegin( "testSubgroupQuadAllMaximiseReconvergenceFull" );
		sdw::FragmentWriter writer{ ast::stmt::FunctionFlag::eFullQuads | ast::stmt::FunctionFlag::eMaximalReconvergence
			, &testCounts.allocator };
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementMain( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAll( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAnyFullPipeline )
	{
		sdwTestBegin( "testSubgroupQuadAnyFull" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
		writer.enableFullQuads();
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementEntryPoint( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAny( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAllFullPipeline )
	{
		sdwTestBegin( "testSubgroupQuadAllFull" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
		writer.enableFullQuads();
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementEntryPoint( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAll( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAnyMaximiseReconvergenceFullPipeline )
	{
		sdwTestBegin( "testSubgroupQuadAnyMaximiseReconvergenceFull" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
		writer.enableFullQuads();
		writer.enableMaximalReconvergence( ast::EntryPoint::eFragment );
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementEntryPoint( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAny( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( QuadControl, testSubgroupQuadAllMaximiseReconvergenceFullPipeline )
	{
		sdwTestBegin( "testSubgroupQuadAllMaximiseReconvergenceFull" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
		writer.enableFullQuads();
		writer.enableMaximalReconvergence( ast::EntryPoint::eFragment );
		auto buffer = writer.declArrayStorageBuffer< Data >( "buffer", { 0u, 0u } );
		writer.implementEntryPoint( [&]( sdw::FragmentIn const &
			, sdw::FragmentOut const & )
			{
				auto b = writer.declLocale( "b", 0_b );
				auto base = writer.declLocale( "base", 0_u );
				sdwIF( writer, sdw::subgroupQuadAll( b ) )
				{
					base = sdw::atomicAdd( buffer[0].isFree(), 1_u );
				}
				sdwFI
				buffer[base].data() = base;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
