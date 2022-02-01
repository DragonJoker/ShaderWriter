#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	void testIf( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIf" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )

			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 1_i );
				IF( writer, ctrlVar != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testIfElse( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIfElse" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 1_i );
				IF( writer, ctrlVar != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				ELSE
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testIfElseIf( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIfElseIf" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				ELSEIF( ctrlVar2 != 0_i )
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testIfElseIfElse( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIfElseIfElse" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				ELSEIF( ctrlVar2 != 0_i )
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				ELSE
				{
					auto k = writer.declLocale< sdw::Int >( "k" );
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testSwitch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSwitch" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrl = writer.declLocale< sdw::Int >( "ctrl" );
				SWITCH( writer, ctrl )
				{
					CASE( 0 )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					ESAC;
					CASE( 1 )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					ESAC;
				}
				HCTIWS;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testForPlusEqual( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testForPlusEqual" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar += 10_i )
				{
					auto i = writer.declLocale( "i", ctrlVar );
				}
				ROF;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testForPreInc( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testForPreInc" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
				{
					auto i = writer.declLocale( "i", ctrlVar );
				}
				ROF;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testForPostInc( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testForPostInc" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar++ )
				{
					auto i = writer.declLocale( "i", ctrlVar );
				}
				ROF;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testForPreDec( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testForPreDec" );
		{
			sdw::VertexWriter writer;
			writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
				{
					FOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, --ctrlVar )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					ROF;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	void testForPostDec( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testForPostDec" );
		{
			sdw::VertexWriter writer;
			writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
				{
					FOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, ctrlVar-- )
					{
					}
					ROF;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	void testForSuccessive( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testForSuccessive" );
		{
			sdw::VertexWriter writer;
			writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
				{
					FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar += 10_i )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					ROF;
					FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					ROF;
					FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar++ )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					ROF;
					FOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, --ctrlVar )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					ROF;
					FOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, ctrlVar-- )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					ROF;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	void testWhile( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testWhile" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 20_i );
				WHILE( writer, ctrlVar != 0_i )
				{
					ctrlVar = ctrlVar - 1_i;
				}
				ELIHW;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testDoWhile( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDoWhile" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 20_i );
				DOWHILE( writer, ctrlVar != 0_i )
				{
					ctrlVar = ctrlVar - 1_i;
				}
				ELIHWOD;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNestedIf( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNestedIf" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				IF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					IF( writer, ctrlVar2 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					FI;
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNestedIfElse( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNestedIfElse" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				IF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					IF( writer, ctrlVar2 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					ELSE
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					FI;
				}
				ELSE
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					IF( writer, ctrlVar2 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "j" );
					}
					ELSE
					{
						auto j = writer.declLocale< sdw::Int >( "k" );
					}
					FI;
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNestedIfElseIf( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNestedIfElseIf" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					ELSEIF( ctrlVar4 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					FI;
				}
				ELSEIF( ctrlVar2 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 != 0_i )
					{
						auto k = writer.declLocale< sdw::Int >( "k" );
					}
					ELSEIF( ctrlVar4 != 0_i )
					{
						auto l = writer.declLocale< sdw::Int >( "l" );
					}
					FI;
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNestedIfElseIfElse( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNestedIfElseIfElse" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					ELSEIF( ctrlVar4 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					ELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k" );
					}
					FI;
				}
				ELSEIF( ctrlVar2 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 != 0_i )
					{
						auto l = writer.declLocale< sdw::Int >( "l" );
					}
					ELSEIF( ctrlVar4 != 0_i )
					{
						auto m = writer.declLocale< sdw::Int >( "m" );
					}
					ELSE
					{
						auto n = writer.declLocale< sdw::Int >( "n" );
					}
					FI;
				}
				ELSE
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 != 0_i )
					{
						auto o = writer.declLocale< sdw::Int >( "o" );
					}
					ELSEIF( ctrlVar4 != 0_i )
					{
						auto p = writer.declLocale< sdw::Int >( "p" );
					}
					ELSE
					{
						auto q = writer.declLocale< sdw::Int >( "q" );
					}
					FI;
				}
				FI;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNestedFor( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNestedFor" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
				{
					FOR( writer, sdw::Int, ctrlVar2, 0_i, ctrlVar2 < 20_i, ++ctrlVar2 )
					{
						auto i = writer.declLocale( "i", ctrlVar2 );
					}
					ROF;
				}
				ROF;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNestedWhile( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNestedWhile" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 20_i );
				WHILE( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 20_i );
					WHILE( writer, ctrlVar2 != 0_i )
					{
						ctrlVar2 = ctrlVar2 - 1_i;
					}
					ELIHW;
					ctrlVar1 = ctrlVar1 - 1_i;
				}
				ELIHW;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNestedDoWhile( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNestedDoWhile" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 20_i );
				DOWHILE( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 20_i );
					DOWHILE( writer, ctrlVar2 != 0_i )
					{
						ctrlVar2 = ctrlVar2 - 1_i;
					}
					ELIHWOD;
					ctrlVar1 = ctrlVar1 - 1_i;
				}
				ELIHWOD;
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testTernary( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTernary" );
		sdw::VertexWriter writer;
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrl = writer.declLocale< sdw::Int >( "ctrl", 20_i );
				auto res1 = writer.declLocale< sdw::Int >( "res1", 20_i );
				auto res2 = writer.declLocale< sdw::Int >( "res2", 10_i );
				writer.ternary( ctrl > 10_i, res1, res2 );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterControlStatements )
{
	sdwTestSuiteBegin();
	testIf( testCounts );
	testIfElse( testCounts );
	testIfElseIf( testCounts );
	testIfElseIfElse( testCounts );
	testSwitch(testCounts );
	testForPlusEqual( testCounts );
	testForPostDec( testCounts );
	testForPostInc( testCounts );
	testForPreDec( testCounts );
	testForPreInc( testCounts );
	testForSuccessive( testCounts );
	testWhile( testCounts );
	testDoWhile( testCounts );
	testNestedIf( testCounts );
	testNestedIfElse( testCounts );
	testNestedIfElseIf( testCounts );
	testNestedIfElseIfElse( testCounts );
	testNestedFor( testCounts );
	testNestedWhile( testCounts );
	testNestedDoWhile( testCounts );
	testTernary( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterControlStatements )
