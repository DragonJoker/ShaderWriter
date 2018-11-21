#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/HLSL/HlslStmtVisitor.hpp>
#include <ShaderWriter/HLSL/HlslTextureAccessFunctions.hpp>

namespace
{
	void testProjectTexCoords2()
	{
		testBegin( "testProjectTexCoords2" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresProjectTexCoords2 = true;
			compileHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eFragment ) << std::endl;
		}
		testEnd();
	}

	void testProjectTexCoords3()
	{
		testBegin( "testProjectTexCoords3" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresProjectTexCoords3 = true;
			compileHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eFragment ) << std::endl;
		}
		testEnd();
	}

	void testProjectTexCoords4To1()
	{
		testBegin( "testProjectTexCoords4To1" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresProjectTexCoords4To1 = true;
			compileHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eFragment ) << std::endl;
		}
		testEnd();
	}

	void testProjectTexCoords4To2()
	{
		testBegin( "testProjectTexCoords4To2" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresProjectTexCoords4To2 = true;
			compileHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eFragment ) << std::endl;
		}
		testEnd();
	}

	void testProjectTexCoords4()
	{
		testBegin( "testProjectTexCoords4" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresProjectTexCoords4 = true;
			compileHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eFragment ) << std::endl;
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterHlslTextureAccesses" );
	testProjectTexCoords2();
	testProjectTexCoords3();
	testProjectTexCoords4To1();
	testProjectTexCoords4To2();
	testProjectTexCoords4();
	testSuiteEnd();
}
