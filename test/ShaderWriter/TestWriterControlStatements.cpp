#include "../Common.hpp"
#include "TestWriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>

namespace
{
	void testIf()
	{
		testBegin( "testIf" );
		sdw::ShaderWriter writer{ false };
		auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 1_i );
		IF( writer, ctrlVar )
		{
			auto i = writer.declLocale< sdw::Int >( "i" );
		}
		FI;
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testIfElse()
	{
		testBegin( "testIfElse" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testIfElseIf()
	{
		testBegin( "testIfElseIf" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testIfElseIfElse()
	{
		testBegin( "testIfElseIfElse" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testFor()
	{
		testBegin( "testFor" );
		sdw::ShaderWriter writer{ false };
		FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
		{
			auto i = writer.declLocale( "i", ctrlVar );
		}
		ROF;
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testWhile()
	{
		testBegin( "testWhile" );
		sdw::ShaderWriter writer{ false };
		auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 20_i );
		WHILE( writer, ctrlVar )
		{
			ctrlVar = ctrlVar - 1_i;
		}
		ELIHW;
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testDoWhile()
	{
		testBegin( "testDoWhile" );
		sdw::ShaderWriter writer{ false };
		auto ctrlVar = writer.declLocale< sdw::Int >( "ctrlVar", 20_i );
		DOWHILE( writer, ctrlVar )
		{
			ctrlVar = ctrlVar - 1_i;
		}
		ELIHWOD;
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testNestedIf()
	{
		testBegin( "testNestedIf" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testNestedIfElse()
	{
		testBegin( "testNestedIfElse" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testNestedIfElseIf()
	{
		testBegin( "testNestedIfElseIf" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testNestedIfElseIfElse()
	{
		testBegin( "testNestedIfElseIfElse" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testNestedFor()
	{
		testBegin( "testNestedFor" );
		sdw::ShaderWriter writer{ false };
		FOR( writer, sdw::Int, ctrlVar, 0_i, ctrlVar < 20_i, ++ctrlVar )
		{
			FOR( writer, sdw::Int, ctrlVar2, 0_i, ctrlVar2 < 20_i, ++ctrlVar2 )
			{
				auto i = writer.declLocale( "i", ctrlVar2 );
			}
			ROF;
		}
		ROF;
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testNestedWhile()
	{
		testBegin( "testNestedWhile" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
		testEnd();
	}

	void testNestedDoWhile()
	{
		testBegin( "testNestedDoWhile" );
		sdw::ShaderWriter writer{ false };
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
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		std::cout << sdw::writeGlsl( writer.getShader(), sdw::ShaderType::eVertex ) << std::endl;
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
