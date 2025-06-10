#include "WriterCommon.hpp"

namespace
{
	TEST( SDW_TestSuiteName, singlePostIncrement )
	{
		sdwTestBegin( "singlePostIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto i = writer.declLocale( "i", 0_u );
				i++;
				auto j = writer.declLocale( "j", i );
				astCheckEqual( writer.getBuilder().getContainer()->size(), 3u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, singlePreIncrement )
	{
		sdwTestBegin( "singlePreIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto i = writer.declLocale( "i", 0_u );
				++i;
				auto j = writer.declLocale( "j", i );
				astCheckEqual( writer.getBuilder().getContainer()->size(), 3u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, assignPostIncrement )
	{
		sdwTestBegin( "assignPostIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto i = writer.declLocale( "i", 0_u );
				auto j = writer.declLocale( "j", i++ );
				astCheckEqual( writer.getBuilder().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, assignPreIncrement )
	{
		sdwTestBegin( "assignPreIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto i = writer.declLocale( "i", 0_u );
				auto j = writer.declLocale( "j", ++i );
				astCheckEqual( writer.getBuilder().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, condPostIncrement )
	{
		sdwTestBegin( "condPostIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto i = writer.declLocale( "i", 0_u );
				writer.ifStmt( sdw::makeCondition( i++ )
					, [&]()
					{
						auto j = writer.declLocale( "j", i );
					} );
				astCheckEqual( writer.getBuilder().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, condPreIncrement )
	{
		sdwTestBegin( "condPreIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto i = writer.declLocale( "i", 0_u );
				sdwIF( writer, ++i )
				{
					auto j = writer.declLocale( "j", i );
				}
				sdwFI;
				astCheckEqual( writer.getBuilder().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, loopPostIncrement )
	{
		sdwTestBegin( "loopPostIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				{
					auto & writerInt = ( writer );
					writerInt.pushScope();
					auto iName = writerInt.registerLoopVar( "i", Int::makeType( writerInt.getTypesCache() ) );
					Int i{ writerInt, sdw::makeExpr( writerInt, iName ), true };
					writerInt.forStmt( sdw::makeInit( iName
						, sdw::makeExpr( writerInt, 0_i ) )
						, sdw::makeCondition( i < 12_i )
						, sdw::makeExpr( writerInt, i++ )
						, [&]()
						{
							auto j = writer.declLocale( "j", i );
						} );
					astCheckEqual( writer.getBuilder().getContainer()->size(), 1u );
					astCheckEqual( writer.getBuilder().getContainer()->back()->getKind(), stmt::Kind::eFor );
					writerInt.popScope();
				}
				astCheckEqual( writer.getBuilder().getContainer()->size(), 1u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, loopPreIncrement )
	{
		sdwTestBegin( "loopPreIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				sdwFOR( writer, Int, i, 0_i, i < 12_i, ++i )
				{
					auto j = writer.declLocale( "j", i );
				}
				sdwROF
				astCheckEqual( writer.getBuilder().getContainer()->size(), 1u );
				astBeginRequire( writer.getBuilder().getContainer()->back()->getKind() == stmt::Kind::eCompound );
					astCheckEqual( static_cast< stmt::Container const & >( *writer.getBuilder().getContainer()->back() ).size(), 1u );
					astBeginRequire( static_cast< stmt::Container const & >( *writer.getBuilder().getContainer()->back() ).back()->getKind() == stmt::Kind::eFor );
					astCheckEqual( static_cast< stmt::For const & >( *static_cast< stmt::Container const & >( *writer.getBuilder().getContainer()->back() ).back() ).size(), 1u );
					astEndRequire;
				astEndRequire;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd();
	}
}

sdwTestSuiteMain()
