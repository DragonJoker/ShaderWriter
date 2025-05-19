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
				sdwIF( writer, ctrlVar != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				sdwFI;
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
				sdwIF( writer, ctrlVar != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				sdwELSE
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				sdwFI;
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
				sdwIF( writer, ctrlVar1 != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				sdwELSEIF( ctrlVar2 != 0_i )
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				sdwFI;
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
				sdwIF( writer, ctrlVar1 != 0_i )
				{
					auto i = writer.declLocale< sdw::Int >( "i" );
				}
				sdwELSEIF( ctrlVar2 != 0_i )
				{
					auto j = writer.declLocale< sdw::Int >( "j" );
				}
				sdwELSE
				{
					auto k = writer.declLocale< sdw::Int >( "k" );
				}
				sdwFI;
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
				sdwSWITCH( writer, ctrl )
				{
					sdwCASE( 0 )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					sdwESAC;
					sdwCASE( 1 )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					sdwESAC;
				}
				sdwHCTIWS;
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
				sdwFOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar += 10_i )
				{
					auto i = writer.declLocale( "i", ctrlVar );
				}
				sdwROF;
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
				sdwFOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
				{
					auto i = writer.declLocale( "i", ctrlVar );
				}
				sdwROF;
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
				sdwFOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar++ )
				{
					auto i = writer.declLocale( "i", ctrlVar );
				}
				sdwROF;
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
					sdwFOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, --ctrlVar )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					sdwROF;
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
					sdwFOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, ctrlVar-- )
					{
					}
					sdwROF;
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
					sdwFOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar += 10_i )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					sdwROF;
					sdwFOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					sdwROF;
					sdwFOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ctrlVar++ )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					sdwROF;
					sdwFOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, --ctrlVar )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					sdwROF;
					sdwFOR( writer, sdw::Int, ctrlVar, 20_i, ctrlVar > 0_i, ctrlVar-- )
					{
						auto i = writer.declLocale( "i", ctrlVar );
					}
					sdwROF;
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
				sdwWHILE( writer, ctrlVar != 0_i )
				{
					ctrlVar = ctrlVar - 1_i;
				}
				sdwELIHW;
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
				sdwDOWHILE( writer, ctrlVar != 0_i )
				{
					ctrlVar = ctrlVar - 1_i;
				}
				sdwELIHWOD;
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
				sdwIF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					sdwIF( writer, ctrlVar2 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					sdwFI;
				}
				sdwFI;
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
				sdwIF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					sdwIF( writer, ctrlVar2 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					sdwELSE
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					sdwFI;
				}
				sdwELSE
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 1_i );
					sdwIF( writer, ctrlVar2 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "j" );
					}
					sdwELSE
					{
						auto j = writer.declLocale< sdw::Int >( "k" );
					}
					sdwFI;
				}
				sdwFI;
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
				sdwIF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					sdwIF( writer, ctrlVar3 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					sdwELSEIF( ctrlVar4 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					sdwFI;
				}
				sdwELSEIF( ctrlVar2 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					sdwIF( writer, ctrlVar3 != 0_i )
					{
						auto k = writer.declLocale< sdw::Int >( "k" );
					}
					sdwELSEIF( ctrlVar4 != 0_i )
					{
						auto l = writer.declLocale< sdw::Int >( "l" );
					}
					sdwFI;
				}
				sdwFI;
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
				sdwIF( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					sdwIF( writer, ctrlVar3 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i" );
					}
					sdwELSEIF( ctrlVar4 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j" );
					}
					sdwELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k" );
					}
					sdwFI;
				}
				sdwELSEIF( ctrlVar2 != 0_i )
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					sdwIF( writer, ctrlVar3 != 0_i )
					{
						auto l = writer.declLocale< sdw::Int >( "l" );
					}
					sdwELSEIF( ctrlVar4 != 0_i )
					{
						auto m = writer.declLocale< sdw::Int >( "m" );
					}
					sdwELSE
					{
						auto n = writer.declLocale< sdw::Int >( "n" );
					}
					sdwFI;
				}
				sdwELSE
				{
					auto ctrlVar3 = writer.declLocale< sdw::Int >( "ctrlVar3", 1_i );
					auto ctrlVar4 = writer.declLocale< sdw::Int >( "ctrlVar4", 1_i );
					sdwIF( writer, ctrlVar3 != 0_i )
					{
						auto o = writer.declLocale< sdw::Int >( "o" );
					}
					sdwELSEIF( ctrlVar4 != 0_i )
					{
						auto p = writer.declLocale< sdw::Int >( "p" );
					}
					sdwELSE
					{
						auto q = writer.declLocale< sdw::Int >( "q" );
					}
					sdwFI;
				}
				sdwFI;
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
				sdwFOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
				{
					sdwFOR( writer, sdw::Int, ctrlVar2, 0_i, ctrlVar2 < 20_i, ++ctrlVar2 )
					{
						auto i = writer.declLocale( "i", ctrlVar2 );
					}
					sdwROF;
				}
				sdwROF;
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
				sdwWHILE( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 20_i );
					sdwWHILE( writer, ctrlVar2 != 0_i )
					{
						ctrlVar2 = ctrlVar2 - 1_i;
					}
					sdwELIHW;
					ctrlVar1 = ctrlVar1 - 1_i;
				}
				sdwELIHW;
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
				sdwDOWHILE( writer, ctrlVar1 != 0_i )
				{
					auto ctrlVar2 = writer.declLocale< sdw::Int >( "ctrlVar2", 20_i );
					sdwDOWHILE( writer, ctrlVar2 != 0_i )
					{
						ctrlVar2 = ctrlVar2 - 1_i;
					}
					sdwELIHWOD;
					ctrlVar1 = ctrlVar1 - 1_i;
				}
				sdwELIHWOD;
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
					sdwIF( writer, ctrlVar != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					sdwELSE
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					sdwFI;
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
					sdwIF( writer, ctrlVar == 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					sdwELSE
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					sdwFI;
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
					sdwIF( writer, ctrlVar1 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					sdwELSEIF( ctrlVar2 == 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					sdwELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					sdwFI;
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
					sdwIF( writer, ctrlVar1 != 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					sdwELSEIF( ctrlVar2 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					sdwELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					sdwFI;
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
					sdwIF( writer, ctrlVar1 == 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					sdwELSEIF( ctrlVar2 == 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					sdwELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					sdwFI;
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
					sdwIF( writer, ctrlVar1 == 0_i )
					{
						auto i = writer.declLocale< sdw::Int >( "i", 24_i );
					}
					sdwELSEIF( ctrlVar2 != 0_i )
					{
						auto j = writer.declLocale< sdw::Int >( "j", 12_i );
					}
					sdwELSE
					{
						auto k = writer.declLocale< sdw::Int >( "k", 6_i );
					}
					sdwFI;
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
					sdwSWITCH( writer, ctrl )
					{
						sdwCASE( 0 )
						{
							auto i = writer.declLocale< sdw::Int >( "i", 24_i );
						}
						sdwESAC;
						sdwCASE( 1 )
						{
							auto j = writer.declLocale< sdw::Int >( "j", 12_i );
						}
						sdwESAC;
						sdwDEFAULT
						{
							auto k = writer.declLocale< sdw::Int >( "k", 6_i );
						}
						sdwTLUAFED;
					}
					sdwHCTIWS;
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
					sdwSWITCH( writer, ctrl )
					{
						sdwCASE( 0 )
						{
							auto i = writer.declLocale< sdw::Int >( "i", 24_i );
						}
						sdwESAC;
						sdwCASE( 1 )
						{
							auto j = writer.declLocale< sdw::Int >( "j", 12_i );
						}
						sdwESAC;
						sdwDEFAULT
						{
							auto k = writer.declLocale< sdw::Int >( "k", 6_i );
						}
						sdwTLUAFED;
					}
					sdwHCTIWS;
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
					sdwSWITCH( writer, ctrl )
					{
						sdwCASE( 0 )
						{
							auto i = writer.declLocale< sdw::Int >( "i", 24_i );
						}
						sdwESAC;
						sdwCASE( 1 )
						{
							auto j = writer.declLocale< sdw::Int >( "j", 12_i );
						}
						sdwESAC;
						sdwDEFAULT
						{
							auto k = writer.declLocale< sdw::Int >( "k", 6_i );
						}
						sdwTLUAFED;
					}
					sdwHCTIWS;
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
