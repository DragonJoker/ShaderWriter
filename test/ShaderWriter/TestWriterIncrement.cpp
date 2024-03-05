#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	void singlePostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "singlePostIncrement" );
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
		astTestEnd();
	}

	void singlePreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "singlePreIncrement" );
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
		astTestEnd();
	}

	void assignPostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "assignPostIncrement" );
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
		astTestEnd();
	}

	void assignPreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "assignPreIncrement" );
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
		astTestEnd();
	}

	void condPostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "condPostIncrement" );
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
		astTestEnd();
	}

	void condPreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "condPreIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto i = writer.declLocale( "i", 0_u );
				IF( writer, ++i )
				{
					auto j = writer.declLocale( "j", i );
				}
				FI;
				astCheckEqual( writer.getBuilder().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void loopPostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "loopPostIncrement" );
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
		astTestEnd();
	}

	void loopPreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "loopPreIncrement" );
		using namespace sdw;

		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				FOR( writer, Int, i, 0_i, i < 12_i, ++i )
				{
					auto j = writer.declLocale( "j", i );
				}
				ROF;
				astCheckEqual( writer.getBuilder().getContainer()->size(), 1u );
				astBeginRequire( writer.getBuilder().getContainer()->back()->getKind() == stmt::Kind::eContainer );
					astCheckEqual( static_cast< stmt::Container const & >( *writer.getBuilder().getContainer()->back() ).size(), 1u );
					astBeginRequire( static_cast< stmt::Container const & >( *writer.getBuilder().getContainer()->back() ).back()->getKind() == stmt::Kind::eFor );
					astCheckEqual( static_cast< stmt::For const & >( *static_cast< stmt::Container const & >( *writer.getBuilder().getContainer()->back() ).back() ).size(), 1u );
					astEndRequire;
				astEndRequire;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		astTestEnd();
	}
}

sdwTestSuiteMain( TestWriterIncrement )
{
	sdwTestSuiteBegin();
	singlePostIncrement( testCounts );
	singlePreIncrement( testCounts );
	assignPostIncrement( testCounts );
	assignPreIncrement( testCounts );
	condPostIncrement( testCounts );
	condPreIncrement( testCounts );
	loopPostIncrement( testCounts );
	loopPreIncrement( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterIncrement )
