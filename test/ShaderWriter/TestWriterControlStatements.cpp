#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	void testIf( test::TestCounts & testCounts )
	{
		testBegin( "testIf" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 1_i );
				IF( writer, ctrlVar )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				FI;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testIfElse( test::TestCounts & testCounts )
	{
		testBegin( "testIfElse" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 1_i );
				IF( writer, ctrlVar )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				ELSE
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				FI;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testIfElseIf( test::TestCounts & testCounts )
	{
		testBegin( "testIfElseIf" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				ELSEIF( ctrlVar2 )
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				FI;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testIfElseIfElse( test::TestCounts & testCounts )
	{
		testBegin( "testIfElseIfElse" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				ELSEIF( ctrlVar2 )
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				ELSE
				{
					auto k = writer.declLocale< sdw::Int >( "k" );
				}
				FI;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testFor( test::TestCounts & testCounts )
	{
		testBegin( "testFor" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
				{
					auto i = writer.declLocale( "i", ctrlVar );
				}
				ROF;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testWhile( test::TestCounts & testCounts )
	{
		testBegin( "testWhile" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 20_i );
				WHILE( writer, ctrlVar )
				{
					ctrlVar = ctrlVar - 1_i;
				}
				ELIHW;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testDoWhile( test::TestCounts & testCounts )
	{
		testBegin( "testDoWhile" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 20_i );
				DOWHILE( writer, ctrlVar )
				{
					ctrlVar = ctrlVar - 1_i;
				}
				ELIHWOD;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testNestedIf( test::TestCounts & testCounts )
	{
		testBegin( "testNestedIf" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				IF( writer, ctrlVar1 )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					IF( writer, ctrlVar2 )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					FI;
				}
				FI;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testNestedIfElse( test::TestCounts & testCounts )
	{
		testBegin( "testNestedIfElse" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				IF( writer, ctrlVar1 )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					IF( writer, ctrlVar2 )
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
					IF( writer, ctrlVar2 )
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
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testNestedIfElseIf( test::TestCounts & testCounts )
	{
		testBegin( "testNestedIfElseIf" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					ELSEIF( ctrlVar4 )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					FI;
				}
				ELSEIF( ctrlVar2 )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 )
					{
						auto k = writer.declLocale< sdw::Int >( "k" );
					}
					ELSEIF( ctrlVar4 )
					{
						auto l = writer.declLocale< sdw::Int >( "l" );
					}
					FI;
				}
				FI;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testNestedIfElseIfElse( test::TestCounts & testCounts )
	{
		testBegin( "testNestedIfElseIfElse" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 1_i );
				auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 0_i );
				IF( writer, ctrlVar1 )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					ELSEIF( ctrlVar4 )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					ELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k" );
					}
					FI;
				}
				ELSEIF( ctrlVar2 )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					IF( writer, ctrlVar3 )
					{
						auto l = writer.declLocale< sdw::Int >( "l" );
					}
					ELSEIF( ctrlVar4 )
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
					IF( writer, ctrlVar3 )
					{
						auto o = writer.declLocale< sdw::Int >( "o" );
					}
					ELSEIF( ctrlVar4 )
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
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testNestedFor( test::TestCounts & testCounts )
	{
		testBegin( "testNestedFor" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
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
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testNestedWhile( test::TestCounts & testCounts )
	{
		testBegin( "testNestedWhile" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 20_i );
				WHILE( writer, ctrlVar1 )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 20_i );
					WHILE( writer, ctrlVar2 )
					{
						ctrlVar2 = ctrlVar2 - 1_i;
					}
					ELIHW;
					ctrlVar1 = ctrlVar1 - 1_i;
				}
				ELIHW;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}

	void testNestedDoWhile( test::TestCounts & testCounts )
	{
		testBegin( "testNestedDoWhile" );
		sdw::ShaderWriter writer{ false };
		writer.implementFunction< void >( "main"
			, [&]()
			{
				auto ctrlVar1 = writer.declLocale< sdw::Int >( "ctrlVar1", 20_i );
				DOWHILE( writer, ctrlVar1 )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 20_i );
					DOWHILE( writer, ctrlVar2 )
					{
						ctrlVar2 = ctrlVar2 - 1_i;
					}
					ELIHWOD;
					ctrlVar1 = ctrlVar1 - 1_i;
				}
				ELIHWOD;
			} );
		test::writeShader( writer.getShader()
			, sdw::ShaderType::eVertex
			, testCounts );
		testEnd();
	}
}

int main( int argc, char ** argv )	
{
	testSuiteBegin( "TestWriterControlStatements" );
	testIf(  testCounts );
	testIfElse(  testCounts );
	testIfElseIf(  testCounts );
	testIfElseIfElse(  testCounts );
	testFor(  testCounts );
	testWhile(  testCounts );
	testDoWhile(  testCounts );
	testNestedIf(  testCounts );
	testNestedIfElse(  testCounts );
	testNestedIfElseIf(  testCounts );
	testNestedIfElseIfElse(  testCounts );
	testNestedFor(  testCounts );
	testNestedWhile(  testCounts );
	testNestedDoWhile(  testCounts );
	testSuiteEnd();
}
