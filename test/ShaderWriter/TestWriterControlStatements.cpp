#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	void testIf( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testIf" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testIfElse( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testIfElse" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testIfElseIf( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testIfElseIf" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testIfElseIfElse( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testIfElseIfElse" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testSwitch( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testSwitch" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testForPlusEqual( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testForPlusEqual" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testForPreInc( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testForPreInc" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testForPostInc( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testForPostInc" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testForPreDec( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testForPreDec" );
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testForPostDec( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testForPostDec" );
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testForSuccessive( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testForSuccessive" );
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testWhile( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testWhile" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testDoWhile( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testDoWhile" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testNestedIf( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedIf" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testNestedIfElse( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedIfElse" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testNestedIfElseIf( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedIfElseIf" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testNestedIfElseIfElse( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedIfElseIfElse" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testNestedFor( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedFor" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testNestedWhile( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedWhile" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testNestedDoWhile( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedDoWhile" );
		sdw::VertexWriter writer{ &testCounts.allocator };
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
		astTestEnd();
	}

	void testTernary( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testTernary" );
		sdw::VertexWriter writer{ &testCounts.allocator };
		writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
			{
				auto ctrl = writer.declLocale< sdw::Int >( "ctrl", 20_i );
				auto res1 = writer.declLocale< sdw::Int >( "res1", 20_i );
				auto res2 = writer.declLocale< sdw::Int >( "res2", 10_i );
				writer.ternary( ctrl > 10_i, res1, res2 );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstIfElseTrue( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstIfElseTrue" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrlVar = writer.declConstant< sdw::Int >( "ctrlVar", 1_i );
					IF( writer, ctrlVar != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					ELSE
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstIfElseFalse( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstIfElseFalse" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrlVar = writer.declConstant< sdw::Int >( "ctrlVar", 1_i );
					IF( writer, ctrlVar == 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					ELSE
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstIfElseIfTrueTrue( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstIfElseIfTrueTrue" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrlVar1 = writer.declConstant< sdw::Int >( "ctrlVar1", 1_i );
					auto ctrlVar2 = writer.declConstant< sdw::Int >( "ctrlVar2", 0_i );
					IF( writer, ctrlVar1 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					ELSEIF( ctrlVar2 == 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					ELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstIfElseIfTrueFalse( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstIfElseIfTrueFalse" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrlVar1 = writer.declConstant< sdw::Int >( "ctrlVar1", 1_i );
					auto ctrlVar2 = writer.declConstant< sdw::Int >( "ctrlVar2", 0_i );
					IF( writer, ctrlVar1 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					ELSEIF( ctrlVar2 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					ELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstIfElseIfFalseTrue( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstIfElseIfFalseTrue" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrlVar1 = writer.declConstant< sdw::Int >( "ctrlVar1", 1_i );
					auto ctrlVar2 = writer.declConstant< sdw::Int >( "ctrlVar2", 0_i );
					IF( writer, ctrlVar1 == 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					ELSEIF( ctrlVar2 == 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					ELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstIfElseIfFalseFalse( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstIfElseIfFalseFalse" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrlVar1 = writer.declConstant< sdw::Int >( "ctrlVar1", 1_i );
					auto ctrlVar2 = writer.declConstant< sdw::Int >( "ctrlVar2", 0_i );
					IF( writer, ctrlVar1 == 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					ELSEIF( ctrlVar2 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					ELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstSwitch0( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstSwitch0" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrl = writer.declConstant< sdw::Int >( "ctrl", 0_i );
					SWITCH( writer, ctrl )
					{
						CASE( 0 )
						{
							auto i = writer.declLocale< sdw::Int >( "i", 24_i );
						}
						ESAC;
						CASE( 1 )
						{
							auto j = writer.declLocale< sdw::Int >( "j", 12_i );
						}
						ESAC;
						DEFAULT
						{
							auto k = writer.declLocale< sdw::Int >( "k", 6_i );
						}
						TLUAFED;
					}
					HCTIWS;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstSwitch1( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstSwitch1" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrl = writer.declConstant< sdw::Int >( "ctrl", 1_i );
					SWITCH( writer, ctrl )
					{
						CASE( 0 )
						{
							auto i = writer.declLocale< sdw::Int >( "i", 24_i );
						}
						ESAC;
						CASE( 1 )
						{
							auto j = writer.declLocale< sdw::Int >( "j", 12_i );
						}
						ESAC;
						DEFAULT
						{
							auto k = writer.declLocale< sdw::Int >( "k", 6_i );
						}
						TLUAFED;
					}
					HCTIWS;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testConstSwitchDefault( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstSwitchDefault" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					auto ctrl = writer.declConstant< sdw::Int >( "ctrl", 2_i );
					SWITCH( writer, ctrl )
					{
						CASE( 0 )
						{
							auto i = writer.declLocale< sdw::Int >( "i", 24_i );
						}
						ESAC;
						CASE( 1 )
						{
							auto j = writer.declLocale< sdw::Int >( "j", 12_i );
						}
						ESAC;
						DEFAULT
						{
							auto k = writer.declLocale< sdw::Int >( "k", 6_i );
						}
						TLUAFED;
					}
					HCTIWS;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testAnonymousScope( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testAnonymousScope" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto i = writer.declSharedVariable< sdw::UInt >( "i" );
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					if (auto scope = makeScope( writer ) )
					{
						i = in.globalInvocationID.x();
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
	}

	void testNestedAnonymousScopes( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testNestedAnonymousScopes" );
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto i = writer.declSharedVariable< sdw::UInt >( "i" );
			auto j = writer.declSharedVariable< sdw::UInt >( "j" );
			auto k = writer.declSharedVariable< sdw::UInt >( "k" );
			auto l = writer.declSharedVariable< sdw::UInt >( "l" );
			writer.implementMain( 32u, [&]( sdw::ComputeIn in )
				{
					if (auto scope1 = makeScope( writer ) )
					{
						l = in.localInvocationIndex;
						if ( auto scope2 = makeScope( writer ) )
						{
							k = in.globalInvocationID.z();
							if ( auto scope3 = makeScope( writer ) )
							{
								j = in.globalInvocationID.y();
								if ( auto scope4 = makeScope( writer ) )
								{
									i = in.globalInvocationID.x();
								}
								j += in.globalInvocationID.y();
							}
							k += in.globalInvocationID.z();
						}
						l += in.localInvocationIndex;
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		astTestEnd();
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
	testConstIfElseTrue( testCounts );
	testConstIfElseFalse( testCounts );
	testConstIfElseIfTrueTrue( testCounts );
	testConstIfElseIfTrueFalse( testCounts );
	testConstIfElseIfFalseTrue( testCounts );
	testConstIfElseIfFalseFalse( testCounts );
	testConstSwitch0( testCounts );
	testConstSwitch1( testCounts );
	testConstSwitchDefault( testCounts );
	testAnonymousScope( testCounts );
	testNestedAnonymousScopes( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterControlStatements )
