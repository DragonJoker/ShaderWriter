#include "Common.hpp"
#include "TestWriterCommon.hpp"

namespace
{
	void testIf()
	{
		testBegin( "testIf" );
		sdw::Shader shader;
		auto ctrlVar = shader.declLocale< sdw::Int >( "ctrlVar", 1_i );
		IF( shader, ctrlVar )
		{
			auto i = shader.declLocale< sdw::Int >( "i" );
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testIfElse()
	{
		testBegin( "testIfElse" );
		sdw::Shader shader;
		auto ctrlVar = shader.declLocale< sdw::Int >( "ctrlVar", 1_i );
		IF( shader, ctrlVar )
		{
			auto i = shader.declLocale< sdw::Int >( "i" );
		}
		ELSE
		{
			auto j = shader.declLocale< sdw::Int >( "j" );
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testIfElseIf()
	{
		testBegin( "testIfElseIf" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 1_i );
		auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 0_i );
		IF( shader, ctrlVar1 )
		{
			auto i = shader.declLocale< sdw::Int >( "i" );
		}
		ELSEIF( ctrlVar2 )
		{
			auto j = shader.declLocale< sdw::Int >( "j" );
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testIfElseIfElse()
	{
		testBegin( "testIfElseIfElse" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 1_i );
		auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 0_i );
		IF( shader, ctrlVar1 )
		{
			auto i = shader.declLocale< sdw::Int >( "i" );
		}
		ELSEIF( ctrlVar2 )
		{
			auto j = shader.declLocale< sdw::Int >( "j" );
		}
		ELSE
		{
			auto k = shader.declLocale< sdw::Int >( "k" );
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testFor()
	{
		testBegin( "testFor" );
		sdw::Shader shader;
		FOR( shader, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
		{
			auto i = shader.declLocale( "i", ctrlVar );
		}
		ROF;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testWhile()
	{
		testBegin( "testWhile" );
		sdw::Shader shader;
		auto ctrlVar = shader.declLocale< sdw::Int >( "ctrlVar", 20_i );
		WHILE( shader, ctrlVar )
		{
			ctrlVar = ctrlVar - 1_i;
		}
		ELIHW;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testDoWhile()
	{
		testBegin( "testDoWhile" );
		sdw::Shader shader;
		auto ctrlVar = shader.declLocale< sdw::Int >( "ctrlVar", 20_i );
		DOWHILE( shader, ctrlVar )
		{
			ctrlVar = ctrlVar - 1_i;
		}
		ELIHWOD;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testNestedIf()
	{
		testBegin( "testNestedIf" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 1_i );
		IF( shader, ctrlVar1 )
		{
			auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 1_i );
			IF( shader, ctrlVar2 )
			{
				auto i = shader.declLocale< sdw::Int >( "i" );
			}
			FI;
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testNestedIfElse()
	{
		testBegin( "testNestedIfElse" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 1_i );
		IF( shader, ctrlVar1 )
		{
			auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 1_i );
			IF( shader, ctrlVar2 )
			{
				auto i = shader.declLocale< sdw::Int >( "i" );
			}
			ELSE
			{
				auto j = shader.declLocale< sdw::Int >( "j" );
			}
			FI;
		}
		ELSE
		{
			auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 1_i );
			IF( shader, ctrlVar2 )
			{
				auto i = shader.declLocale< sdw::Int >( "j" );
			}
			ELSE
			{
				auto j = shader.declLocale< sdw::Int >( "k" );
			}
			FI;
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testNestedIfElseIf()
	{
		testBegin( "testNestedIfElseIf" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 1_i );
		auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 0_i );
		IF( shader, ctrlVar1 )
		{
			auto ctrlVar3 = shader.declLocale< sdw::Int >( "ctrlVar3", 1_i );
			auto ctrlVar4 = shader.declLocale< sdw::Int >( "ctrlVar4", 1_i );
			IF( shader, ctrlVar3 )
			{
				auto i = shader.declLocale< sdw::Int >( "i" );
			}
			ELSEIF( ctrlVar4 )
			{
				auto j = shader.declLocale< sdw::Int >( "j" );
			}
			FI;
		}
		ELSEIF( ctrlVar2 )
		{
			auto ctrlVar3 = shader.declLocale< sdw::Int >( "ctrlVar3", 1_i );
			auto ctrlVar4 = shader.declLocale< sdw::Int >( "ctrlVar4", 1_i );
			IF( shader, ctrlVar3 )
			{
				auto k = shader.declLocale< sdw::Int >( "k" );
			}
			ELSEIF( ctrlVar4 )
			{
				auto l = shader.declLocale< sdw::Int >( "l" );
			}
			FI;
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testNestedIfElseIfElse()
	{
		testBegin( "testNestedIfElseIfElse" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 1_i );
		auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 0_i );
		IF( shader, ctrlVar1 )
		{
			auto ctrlVar3 = shader.declLocale< sdw::Int >( "ctrlVar3", 1_i );
			auto ctrlVar4 = shader.declLocale< sdw::Int >( "ctrlVar4", 1_i );
			IF( shader, ctrlVar3 )
			{
				auto i = shader.declLocale< sdw::Int >( "i" );
			}
			ELSEIF( ctrlVar4 )
			{
				auto j = shader.declLocale< sdw::Int >( "j" );
			}
			ELSE
			{
				auto k = shader.declLocale< sdw::Int >( "k" );
			}
			FI;
		}
		ELSEIF( ctrlVar2 )
		{
			auto ctrlVar3 = shader.declLocale< sdw::Int >( "ctrlVar3", 1_i );
			auto ctrlVar4 = shader.declLocale< sdw::Int >( "ctrlVar4", 1_i );
			IF( shader, ctrlVar3 )
			{
				auto l = shader.declLocale< sdw::Int >( "l" );
			}
			ELSEIF( ctrlVar4 )
			{
				auto m = shader.declLocale< sdw::Int >( "m" );
			}
			ELSE
			{
				auto n = shader.declLocale< sdw::Int >( "n" );
			}
			FI;
		}
		ELSE
		{
			auto ctrlVar3 = shader.declLocale< sdw::Int >( "ctrlVar3", 1_i );
			auto ctrlVar4 = shader.declLocale< sdw::Int >( "ctrlVar4", 1_i );
			IF( shader, ctrlVar3 )
			{
				auto o = shader.declLocale< sdw::Int >( "o" );
			}
			ELSEIF( ctrlVar4 )
			{
				auto p = shader.declLocale< sdw::Int >( "p" );
			}
			ELSE
			{
				auto q = shader.declLocale< sdw::Int >( "q" );
			}
			FI;
		}
		FI;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testNestedFor()
	{
		testBegin( "testNestedFor" );
		sdw::Shader shader;
		FOR( shader, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
		{
			FOR( shader, sdw::Int, ctrlVar2, 0_i, ctrlVar2 < 20_i, ++ctrlVar2 )
			{
				auto i = shader.declLocale( "i", ctrlVar2 );
			}
			ROF;
		}
		ROF;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testNestedWhile()
	{
		testBegin( "testNestedWhile" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 20_i );
		WHILE( shader, ctrlVar1 )
		{
			auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 20_i );
			WHILE( shader, ctrlVar2 )
			{
				ctrlVar2 = ctrlVar2 - 1_i;
			}
			ELIHW;
			ctrlVar1 = ctrlVar1 - 1_i;
		}
		ELIHW;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testNestedDoWhile()
	{
		testBegin( "testNestedDoWhile" );
		sdw::Shader shader;
		auto ctrlVar1 = shader.declLocale< sdw::Int >( "ctrlVar1", 20_i );
		DOWHILE( shader, ctrlVar1 )
		{
			auto ctrlVar2 = shader.declLocale< sdw::Int >( "ctrlVar2", 20_i );
			DOWHILE( shader, ctrlVar2 )
			{
				ctrlVar2 = ctrlVar2 - 1_i;
			}
			ELIHWOD;
			ctrlVar1 = ctrlVar1 - 1_i;
		}
		ELIHWOD;
		std::cout << sdw::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}
}

int main( int argc, char ** argv )	
{
	testSuiteBegin( "TestWriterControlStatements" );
	testIf();
	testIfElse();
	testIfElseIf();
	testIfElseIfElse();
	testFor();
	testWhile();
	testDoWhile();
	testNestedIf();
	testNestedIfElse();
	testNestedIfElseIf();
	testNestedIfElseIfElse();
	testNestedFor();
	testNestedWhile();
	testNestedDoWhile();
	testSuiteEnd();
}
