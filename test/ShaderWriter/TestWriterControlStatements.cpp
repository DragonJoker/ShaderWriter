#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	TEST( SDW_TestSuiteName, testIf )
	{
		sdwTestBegin( "testIf" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testIfElse )
	{
		sdwTestBegin( "testIfElse" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testIfElseIf )
	{
		sdwTestBegin( "testIfElseIf" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testIfElseIfElse )
	{
		sdwTestBegin( "testIfElseIfElse" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testSwitch )
	{
		sdwTestBegin( "testSwitch" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testForPlusEqual )
	{
		sdwTestBegin( "testForPlusEqual" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testForPreInc )
	{
		sdwTestBegin( "testForPreInc" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testForPostInc )
	{
		sdwTestBegin( "testForPostInc" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testForPreDec )
	{
		sdwTestBegin( "testForPreDec" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testForPostDec )
	{
		sdwTestBegin( "testForPostDec" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testForSuccessive )
	{
		sdwTestBegin( "testForSuccessive" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testWhile )
	{
		sdwTestBegin( "testWhile" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testDoWhile )
	{
		sdwTestBegin( "testDoWhile" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedIf )
	{
		sdwTestBegin( "testNestedIf" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedIfElse )
	{
		sdwTestBegin( "testNestedIfElse" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedIfElseIf )
	{
		sdwTestBegin( "testNestedIfElseIf" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedIfElseIfElse )
	{
		sdwTestBegin( "testNestedIfElseIfElse" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedFor )
	{
		sdwTestBegin( "testNestedFor" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedWhile )
	{
		sdwTestBegin( "testNestedWhile" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedDoWhile )
	{
		sdwTestBegin( "testNestedDoWhile" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testTernary )
	{
		sdwTestBegin( "testTernary" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstIfElseTrue )
	{
		sdwTestBegin( "testConstIfElseTrue" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstIfElseFalse )
	{
		sdwTestBegin( "testConstIfElseFalse" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstIfElseIfTrueTrue )
	{
		sdwTestBegin( "testConstIfElseIfTrueTrue" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstIfElseIfTrueFalse )
	{
		sdwTestBegin( "testConstIfElseIfTrueFalse" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstIfElseIfFalseTrue )
	{
		sdwTestBegin( "testConstIfElseIfFalseTrue" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstIfElseIfFalseFalse )
	{
		sdwTestBegin( "testConstIfElseIfFalseFalse" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstSwitch0 )
	{
		sdwTestBegin( "testConstSwitch0" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstSwitch1 )
	{
		sdwTestBegin( "testConstSwitch1" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testConstSwitchDefault )
	{
		sdwTestBegin( "testConstSwitchDefault" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testAnonymousScope )
	{
		sdwTestBegin( "testAnonymousScope" );
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
		sdwTestEnd();
	}

	TEST( SDW_TestSuiteName, testNestedAnonymousScopes )
	{
		sdwTestBegin( "testNestedAnonymousScopes" );
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
		sdwTestEnd();
	}
}

sdwTestSuiteMain()
