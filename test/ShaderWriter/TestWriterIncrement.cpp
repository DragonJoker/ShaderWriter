#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	void singlePostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "singlePostIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
			{
				auto i = writer.declLocale( "i", 0_u );
				i++;
				auto j = writer.declLocale( "j", i );
				checkEqual( writer.getShader().getContainer()->size(), 3u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void singlePreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "singlePreIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
			{
				auto i = writer.declLocale( "i", 0_u );
				++i;
				auto j = writer.declLocale( "j", i );
				checkEqual( writer.getShader().getContainer()->size(), 3u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void assignPostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "assignPostIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
			{
				auto i = writer.declLocale( "i", 0_u );
				auto j = writer.declLocale( "j", i++ );
				checkEqual( writer.getShader().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void assignPreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "assignPreIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
			{
				auto i = writer.declLocale( "i", 0_u );
				auto j = writer.declLocale( "j", ++i );
				checkEqual( writer.getShader().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void condPostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "condPostIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
			{
				auto i = writer.declLocale( "i", 0_u );
				writer.ifStmt( sdw::makeCondition( i++ )
					, [&]()
					{
						auto j = writer.declLocale( "j", i );
					} );
				checkEqual( writer.getShader().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void condPreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "condPreIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
			{
				auto i = writer.declLocale( "i", 0_u );
				IF( writer, ++i )
				{
					auto j = writer.declLocale( "j", i );
				}
				FI;
				checkEqual( writer.getShader().getContainer()->size(), 2u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void loopPostIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "loopPostIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
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
					checkEqual( writer.getShader().getContainer()->size(), 1u );
					checkEqual( writer.getShader().getContainer()->back()->getKind(), stmt::Kind::eFor );
					writerInt.popScope();
				}
				checkEqual( writer.getShader().getContainer()->size(), 1u );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void loopPreIncrement( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "loopPreIncrement" );
		using namespace sdw;

		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementMainT< VoidT >( [&]( ComputeInT< VoidT > in )
			{
				FOR( writer, Int, i, 0_i, i < 12_i, ++i )
				{
					auto j = writer.declLocale( "j", i );
				}
				ROF;
				checkEqual( writer.getShader().getContainer()->size(), 1u );
				beginRequire( writer.getShader().getContainer()->back()->getKind() == stmt::Kind::eContainer );
					checkEqual( static_cast< stmt::Container const & >( *writer.getShader().getContainer()->back() ).size(), 1u );
					beginRequire( static_cast< stmt::Container const & >( *writer.getShader().getContainer()->back() ).back()->getKind() == stmt::Kind::eFor );
					checkEqual( static_cast< stmt::For const & >( *static_cast< stmt::Container const & >( *writer.getShader().getContainer()->back() ).back() ).size(), 1u );
					endRequire;
				endRequire;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
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
