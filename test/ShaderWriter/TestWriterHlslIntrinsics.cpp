#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/HLSL/HlslStmtVisitor.hpp>
#include <ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp>
#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>

namespace
{
	void testRoundEven1F()
	{
		testBegin( "testRoundEven1F" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven1F = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testRoundEven2F()
	{
		testBegin( "testRoundEven2F" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven2F = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testRoundEven3F()
	{
		testBegin( "testRoundEven3F" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven3F = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testRoundEven4F()
	{
		testBegin( "testRoundEven4F" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven4F = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testRoundEven1D()
	{
		testBegin( "testRoundEven1D" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven1D = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testRoundEven2D()
	{
		testBegin( "testRoundEven2D" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven2D = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testRoundEven3D()
	{
		testBegin( "testRoundEven3D" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven3D = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testRoundEven4D()
	{
		testBegin( "testRoundEven4D" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresRoundEven4D = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testPackDouble2x32()
	{
		testBegin( "testPackDouble2x32" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresPackDouble2x32 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testPackHalf2x16()
	{
		testBegin( "testPackHalf2x16" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresPackHalf2x16 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testPackSnorm2x16()
	{
		testBegin( "testPackSnorm2x16" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresPackSnorm2x16 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testPackUnorm2x16()
	{
		testBegin( "testPackUnorm2x16" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresPackUnorm2x16 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testPackSnorm4x8()
	{
		testBegin( "testPackSnorm4x8" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresPackSnorm4x8 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testPackUnorm4x8()
	{
		testBegin( "testPackUnorm4x8" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresPackUnorm4x8 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUnpackDouble2x32()
	{
		testBegin( "testUnpackDouble2x32" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUnpackDouble2x32 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUnpackHalf2x16()
	{
		testBegin( "testUnpackHalf2x16" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUnpackHalf2x16 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUnpackSnorm2x16()
	{
		testBegin( "testUnpackSnorm2x16" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUnpackSnorm2x16 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUnpackUnorm2x16()
	{
		testBegin( "testUnpackUnorm2x16" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUnpackUnorm2x16 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUnpackSnorm4x8()
	{
		testBegin( "testUnpackSnorm4x8" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUnpackSnorm4x8 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUnpackUnorm4x8()
	{
		testBegin( "testUnpackUnorm4x8" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUnpackUnorm4x8 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testInverse2x2F()
	{
		testBegin( "testInverse2x2F" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresInverse2x2F = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testInverse2x2D()
	{
		testBegin( "testInverse2x2D" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresInverse2x2D = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testInverse3x3F()
	{
		testBegin( "testInverse3x3F" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresInverse3x3F = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testInverse3x3D()
	{
		testBegin( "testInverse3x3D" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresInverse3x3D = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testInverse4x4F()
	{
		testBegin( "testInverse4x4F" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresInverse4x4F = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testInverse4x4D()
	{
		testBegin( "testInverse4x4D" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresInverse4x4D = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUaddCarry1()
	{
		testBegin( "testUaddCarry1" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUaddCarry1 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUaddCarry2()
	{
		testBegin( "testUaddCarry2" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUaddCarry2 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUaddCarry3()
	{
		testBegin( "testUaddCarry3" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUaddCarry3 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUaddCarry4()
	{
		testBegin( "testUaddCarry4" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUaddCarry4 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUsubBorrow1()
	{
		testBegin( "testUsubBorrow1" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUsubBorrow1 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUsubBorrow2()
	{
		testBegin( "testUsubBorrow2" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUsubBorrow2 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUsubBorrow3()
	{
		testBegin( "testUsubBorrow3" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUsubBorrow3 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUsubBorrow4()
	{
		testBegin( "testUsubBorrow4" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUsubBorrow4 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUmulExtended1()
	{
		testBegin( "testUmulExtended1" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUmulExtended1 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUmulExtended2()
	{
		testBegin( "testUmulExtended2" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUmulExtended2 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUmulExtended3()
	{
		testBegin( "testUmulExtended3" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUmulExtended3 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testUmulExtended4()
	{
		testBegin( "testUmulExtended4" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresUmulExtended4 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImulExtended1()
	{
		testBegin( "testImulExtended1" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImulExtended1 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImulExtended2()
	{
		testBegin( "testImulExtended2" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImulExtended2 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImulExtended3()
	{
		testBegin( "testImulExtended3" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImulExtended3 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImulExtended4()
	{
		testBegin( "testImulExtended4" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImulExtended4 = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert1I()
	{
		testBegin( "testBitfieldInsert1I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert1I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert2I()
	{
		testBegin( "testBitfieldInsert2I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert2I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert3I()
	{
		testBegin( "testBitfieldInsert3I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert3I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert4I()
	{
		testBegin( "testBitfieldInsert4I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert4I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert1U()
	{
		testBegin( "testBitfieldInsert1U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert1U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert2U()
	{
		testBegin( "testBitfieldInsert2U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert2U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert3U()
	{
		testBegin( "testBitfieldInsert3U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert3U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldInsert4U()
	{
		testBegin( "testBitfieldInsert4U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldInsert4U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract1I()
	{
		testBegin( "testBitfieldExtract1I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract1I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract2I()
	{
		testBegin( "testBitfieldExtract2I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract2I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract3I()
	{
		testBegin( "testBitfieldExtract3I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract3I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract4I()
	{
		testBegin( "testBitfieldExtract4I" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract4I = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract1U()
	{
		testBegin( "testBitfieldExtract1U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract1U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract2U()
	{
		testBegin( "testBitfieldExtract2U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract2U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract3U()
	{
		testBegin( "testBitfieldExtract3U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract3U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testBitfieldExtract4U()
	{
		testBegin( "testBitfieldExtract4U" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresBitfieldExtract4U = true;
			writeHlslIntrinsicFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterHlslIntrinsics" );
	testRoundEven1F();
	testRoundEven2F();
	testRoundEven3F();
	testRoundEven4F();
	testRoundEven1D();
	testRoundEven2D();
	testRoundEven3D();
	testRoundEven4D();
	testPackDouble2x32();
	testPackHalf2x16();
	testPackSnorm2x16();
	testPackUnorm2x16();
	testPackSnorm4x8();
	testPackUnorm4x8();
	testUnpackDouble2x32();
	testUnpackHalf2x16();
	testUnpackSnorm2x16();
	testUnpackUnorm2x16();
	testUnpackSnorm4x8();
	testUnpackUnorm4x8();
	testInverse2x2F();
	testInverse2x2D();
	testInverse3x3F();
	testInverse3x3D();
	testInverse4x4F();
	testInverse4x4D();
	testUaddCarry1();
	testUaddCarry2();
	testUaddCarry3();
	testUaddCarry4();
	testUsubBorrow1();
	testUsubBorrow2();
	testUsubBorrow3();
	testUsubBorrow4();
	testUmulExtended1();
	testUmulExtended2();
	testUmulExtended3();
	testUmulExtended4();
	testImulExtended1();
	testImulExtended2();
	testImulExtended3();
	testImulExtended4();
	testBitfieldInsert1I();
	testBitfieldInsert2I();
	testBitfieldInsert3I();
	testBitfieldInsert4I();
	testBitfieldInsert1U();
	testBitfieldInsert2U();
	testBitfieldInsert3U();
	testBitfieldInsert4U();
	testBitfieldExtract1I();
	testBitfieldExtract2I();
	testBitfieldExtract3I();
	testBitfieldExtract4I();
	testBitfieldExtract1U();
	testBitfieldExtract2U();
	testBitfieldExtract3U();
	testBitfieldExtract4U();
	testSuiteEnd();
}
