#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/HLSL/HlslStmtVisitor.hpp>
#include <ShaderWriter/HLSL/HlslImageAccessFunctions.hpp>

namespace
{
	void testImageSizeBufferF()
	{
		testBegin( "testImageSizeBufferF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeBufferF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeBufferI()
	{
		testBegin( "testImageSizeBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeBufferU()
	{
		testBegin( "testImageSizeBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize1DF()
	{
		testBegin( "testImageSize1DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize1DF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize1DI()
	{
		testBegin( "testImageSize1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize1DU()
	{
		testBegin( "testImageSize1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize1DArrayF()
	{
		testBegin( "testImageSize1DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize1DArrayF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize1DArrayI()
	{
		testBegin( "testImageSize1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize1DArrayU()
	{
		testBegin( "testImageSize1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DF()
	{
		testBegin( "testImageSize2DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DRectF()
	{
		testBegin( "testImageSize2DRectF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DRectF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DI()
	{
		testBegin( "testImageSize2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DRectI()
	{
		testBegin( "testImageSize2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DU()
	{
		testBegin( "testImageSize2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DRectU()
	{
		testBegin( "testImageSize2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DArrayF()
	{
		testBegin( "testImageSize2DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DArrayF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DArrayI()
	{
		testBegin( "testImageSize2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DArrayU()
	{
		testBegin( "testImageSize2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize3DF()
	{
		testBegin( "testImageSize3DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize3DF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize3DI()
	{
		testBegin( "testImageSize3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize3DU()
	{
		testBegin( "testImageSize3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeCubeF()
	{
		testBegin( "testImageSizeCubeF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeCubeF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeCubeI()
	{
		testBegin( "testImageSizeCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeCubeU()
	{
		testBegin( "testImageSizeCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeCubeArrayF()
	{
		testBegin( "testImageSizeCubeArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeCubeArrayF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeCubeArrayI()
	{
		testBegin( "testImageSizeCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSizeCubeArrayU()
	{
		testBegin( "testImageSizeCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSizeCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DMSF()
	{
		testBegin( "testImageSize2DMSF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DMSF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DMSI()
	{
		testBegin( "testImageSize2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DMSU()
	{
		testBegin( "testImageSize2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DMSArrayF()
	{
		testBegin( "testImageSize2DMSArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DMSArrayF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DMSArrayI()
	{
		testBegin( "testImageSize2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSize2DMSArrayU()
	{
		testBegin( "testImageSize2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSize2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSamples2DMSF()
	{
		testBegin( "testImageSamples2DMSF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSamples2DMSF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSamples2DMSI()
	{
		testBegin( "testImageSamples2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSamples2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSamples2DMSU()
	{
		testBegin( "testImageSamples2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSamples2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSamples2DMSArrayF()
	{
		testBegin( "testImageSamples2DMSArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSamples2DMSArrayF = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSamples2DMSArrayI()
	{
		testBegin( "testImageSamples2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSamples2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageSamples2DMSArrayU()
	{
		testBegin( "testImageSamples2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageSamples2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageLoadBufferF()
	{
		testBegin( "testImageLoadBufferF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadBufferI()
	{
		testBegin( "testImageLoadBufferI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadBufferU()
	{
		testBegin( "testImageLoadBufferU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad1DF()
	{
		testBegin( "testImageLoad1DF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad1DI()
	{
		testBegin( "testImageLoad1DI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad1DU()
	{
		testBegin( "testImageLoad1DU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad1DArrayF()
	{
		testBegin( "testImageLoad1DArrayF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad1DArrayI()
	{
		testBegin( "testImageLoad1DArrayI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad1DArrayU()
	{
		testBegin( "testImageLoad1DArrayU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DF()
	{
		testBegin( "testImageLoad2DF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DRectF()
	{
		testBegin( "testImageLoad2DRectF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DI()
	{
		testBegin( "testImageLoad2DI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DRectI()
	{
		testBegin( "testImageLoad2DRectI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DU()
	{
		testBegin( "testImageLoad2DU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DRectU()
	{
		testBegin( "testImageLoad2DRectU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DArrayF()
	{
		testBegin( "testImageLoad2DArrayF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DArrayI()
	{
		testBegin( "testImageLoad2DArrayI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DArrayU()
	{
		testBegin( "testImageLoad2DArrayU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad3DF()
	{
		testBegin( "testImageLoad3DF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad3DI()
	{
		testBegin( "testImageLoad3DI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad3DU()
	{
		testBegin( "testImageLoad3DU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadCubeF()
	{
		testBegin( "testImageLoadCubeF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadCubeI()
	{
		testBegin( "testImageLoadCubeI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadCubeU()
	{
		testBegin( "testImageLoadCubeU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadCubeArrayF()
	{
		testBegin( "testImageLoadCubeArrayF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadCubeArrayI()
	{
		testBegin( "testImageLoadCubeArrayI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoadCubeArrayU()
	{
		testBegin( "testImageLoadCubeArrayU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DMSF()
	{
		testBegin( "testImageLoad2DMSF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DMSI()
	{
		testBegin( "testImageLoad2DMSI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DMSU()
	{
		testBegin( "testImageLoad2DMSU" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DMSArrayF()
	{
		testBegin( "testImageLoad2DMSArrayF" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DMSArrayI()
	{
		testBegin( "testImageLoad2DMSArrayI" );
		using namespace sdw;
		testEnd();
	}

	void testImageLoad2DMSArrayU()
	{
		testBegin( "testImageLoad2DMSArrayU" );
		using namespace sdw;
		testEnd();
	}

	void testImageAtomicAddBufferU()
	{
		testBegin( "testImageAtomicAddBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DU()
	{
		testBegin( "testImageAtomicAdd1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayU()
	{
		testBegin( "testImageAtomicAdd1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DU()
	{
		testBegin( "testImageAtomicAdd2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectU()
	{
		testBegin( "testImageAtomicAdd2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayU()
	{
		testBegin( "testImageAtomicAdd2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DU()
	{
		testBegin( "testImageAtomicAdd3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeU()
	{
		testBegin( "testImageAtomicAddCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayU()
	{
		testBegin( "testImageAtomicAddCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSU()
	{
		testBegin( "testImageAtomicAdd2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayU()
	{
		testBegin( "testImageAtomicAdd2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddBufferI()
	{
		testBegin( "testImageAtomicAddBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DI()
	{
		testBegin( "testImageAtomicAdd1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayI()
	{
		testBegin( "testImageAtomicAdd1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DI()
	{
		testBegin( "testImageAtomicAdd2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectI()
	{
		testBegin( "testImageAtomicAdd2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayI()
	{
		testBegin( "testImageAtomicAdd2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DI()
	{
		testBegin( "testImageAtomicAdd3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeI()
	{
		testBegin( "testImageAtomicAddCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayI()
	{
		testBegin( "testImageAtomicAddCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSI()
	{
		testBegin( "testImageAtomicAdd2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayI()
	{
		testBegin( "testImageAtomicAdd2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferU()
	{
		testBegin( "testImageAtomicMinBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DU()
	{
		testBegin( "testImageAtomicMin1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayU()
	{
		testBegin( "testImageAtomicMin1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DU()
	{
		testBegin( "testImageAtomicMin2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectU()
	{
		testBegin( "testImageAtomicMin2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayU()
	{
		testBegin( "testImageAtomicMin2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DU()
	{
		testBegin( "testImageAtomicMin3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeU()
	{
		testBegin( "testImageAtomicMinCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayU()
	{
		testBegin( "testImageAtomicMinCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSU()
	{
		testBegin( "testImageAtomicMin2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayU()
	{
		testBegin( "testImageAtomicMin2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferI()
	{
		testBegin( "testImageAtomicMinBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DI()
	{
		testBegin( "testImageAtomicMin1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayI()
	{
		testBegin( "testImageAtomicMin1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DI()
	{
		testBegin( "testImageAtomicMin2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectI()
	{
		testBegin( "testImageAtomicMin2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayI()
	{
		testBegin( "testImageAtomicMin2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DI()
	{
		testBegin( "testImageAtomicMin3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeI()
	{
		testBegin( "testImageAtomicMinCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayI()
	{
		testBegin( "testImageAtomicMinCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSI()
	{
		testBegin( "testImageAtomicMin2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayI()
	{
		testBegin( "testImageAtomicMin2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferU()
	{
		testBegin( "testImageAtomicMaxBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DU()
	{
		testBegin( "testImageAtomicMax1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayU()
	{
		testBegin( "testImageAtomicMax1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DU()
	{
		testBegin( "testImageAtomicMax2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectU()
	{
		testBegin( "testImageAtomicMax2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayU()
	{
		testBegin( "testImageAtomicMax2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DU()
	{
		testBegin( "testImageAtomicMax3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeU()
	{
		testBegin( "testImageAtomicMaxCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayU()
	{
		testBegin( "testImageAtomicMaxCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSU()
	{
		testBegin( "testImageAtomicMax2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayU()
	{
		testBegin( "testImageAtomicMax2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferI()
	{
		testBegin( "testImageAtomicMaxBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DI()
	{
		testBegin( "testImageAtomicMax1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayI()
	{
		testBegin( "testImageAtomicMax1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DI()
	{
		testBegin( "testImageAtomicMax2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectI()
	{
		testBegin( "testImageAtomicMax2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayI()
	{
		testBegin( "testImageAtomicMax2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DI()
	{
		testBegin( "testImageAtomicMax3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeI()
	{
		testBegin( "testImageAtomicMaxCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayI()
	{
		testBegin( "testImageAtomicMaxCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSI()
	{
		testBegin( "testImageAtomicMax2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayI()
	{
		testBegin( "testImageAtomicMax2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferU()
	{
		testBegin( "testImageAtomicAndBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DU()
	{
		testBegin( "testImageAtomicAnd1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayU()
	{
		testBegin( "testImageAtomicAnd1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DU()
	{
		testBegin( "testImageAtomicAnd2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectU()
	{
		testBegin( "testImageAtomicAnd2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayU()
	{
		testBegin( "testImageAtomicAnd2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DU()
	{
		testBegin( "testImageAtomicAnd3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeU()
	{
		testBegin( "testImageAtomicAndCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayU()
	{
		testBegin( "testImageAtomicAndCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSU()
	{
		testBegin( "testImageAtomicAnd2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayU()
	{
		testBegin( "testImageAtomicAnd2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferI()
	{
		testBegin( "testImageAtomicAndBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DI()
	{
		testBegin( "testImageAtomicAnd1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayI()
	{
		testBegin( "testImageAtomicAnd1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DI()
	{
		testBegin( "testImageAtomicAnd2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectI()
	{
		testBegin( "testImageAtomicAnd2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayI()
	{
		testBegin( "testImageAtomicAnd2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DI()
	{
		testBegin( "testImageAtomicAnd3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeI()
	{
		testBegin( "testImageAtomicAndCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayI()
	{
		testBegin( "testImageAtomicAndCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSI()
	{
		testBegin( "testImageAtomicAnd2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayI()
	{
		testBegin( "testImageAtomicAnd2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferU()
	{
		testBegin( "testImageAtomicOrBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DU()
	{
		testBegin( "testImageAtomicOr1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayU()
	{
		testBegin( "testImageAtomicOr1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DU()
	{
		testBegin( "testImageAtomicOr2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectU()
	{
		testBegin( "testImageAtomicOr2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayU()
	{
		testBegin( "testImageAtomicOr2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DU()
	{
		testBegin( "testImageAtomicOr3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeU()
	{
		testBegin( "testImageAtomicOrCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayU()
	{
		testBegin( "testImageAtomicOrCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSU()
	{
		testBegin( "testImageAtomicOr2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayU()
	{
		testBegin( "testImageAtomicOr2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferI()
	{
		testBegin( "testImageAtomicOrBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DI()
	{
		testBegin( "testImageAtomicOr1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayI()
	{
		testBegin( "testImageAtomicOr1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DI()
	{
		testBegin( "testImageAtomicOr2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectI()
	{
		testBegin( "testImageAtomicOr2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayI()
	{
		testBegin( "testImageAtomicOr2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DI()
	{
		testBegin( "testImageAtomicOr3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeI()
	{
		testBegin( "testImageAtomicOrCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayI()
	{
		testBegin( "testImageAtomicOrCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSI()
	{
		testBegin( "testImageAtomicOr2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayI()
	{
		testBegin( "testImageAtomicOr2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferU()
	{
		testBegin( "testImageAtomicXorBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DU()
	{
		testBegin( "testImageAtomicXor1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayU()
	{
		testBegin( "testImageAtomicXor1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DU()
	{
		testBegin( "testImageAtomicXor2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectU()
	{
		testBegin( "testImageAtomicXor2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayU()
	{
		testBegin( "testImageAtomicXor2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DU()
	{
		testBegin( "testImageAtomicXor3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeU()
	{
		testBegin( "testImageAtomicXorCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayU()
	{
		testBegin( "testImageAtomicXorCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSU()
	{
		testBegin( "testImageAtomicXor2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayU()
	{
		testBegin( "testImageAtomicXor2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferI()
	{
		testBegin( "testImageAtomicXorBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DI()
	{
		testBegin( "testImageAtomicXor1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayI()
	{
		testBegin( "testImageAtomicXor1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DI()
	{
		testBegin( "testImageAtomicXor2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectI()
	{
		testBegin( "testImageAtomicXor2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayI()
	{
		testBegin( "testImageAtomicXor2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DI()
	{
		testBegin( "testImageAtomicXor3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeI()
	{
		testBegin( "testImageAtomicXorCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayI()
	{
		testBegin( "testImageAtomicXorCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSI()
	{
		testBegin( "testImageAtomicXor2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayI()
	{
		testBegin( "testImageAtomicXor2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferU()
	{
		testBegin( "testImageAtomicExchangeBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DU()
	{
		testBegin( "testImageAtomicExchange1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayU()
	{
		testBegin( "testImageAtomicExchange1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DU()
	{
		testBegin( "testImageAtomicExchange2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectU()
	{
		testBegin( "testImageAtomicExchange2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayU()
	{
		testBegin( "testImageAtomicExchange2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DU()
	{
		testBegin( "testImageAtomicExchange3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeU()
	{
		testBegin( "testImageAtomicExchangeCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayU()
	{
		testBegin( "testImageAtomicExchangeCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSU()
	{
		testBegin( "testImageAtomicExchange2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayU()
	{
		testBegin( "testImageAtomicExchange2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferI()
	{
		testBegin( "testImageAtomicExchangeBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DI()
	{
		testBegin( "testImageAtomicExchange1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayI()
	{
		testBegin( "testImageAtomicExchange1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DI()
	{
		testBegin( "testImageAtomicExchange2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectI()
	{
		testBegin( "testImageAtomicExchange2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayI()
	{
		testBegin( "testImageAtomicExchange2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DI()
	{
		testBegin( "testImageAtomicExchange3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeI()
	{
		testBegin( "testImageAtomicExchangeCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayI()
	{
		testBegin( "testImageAtomicExchangeCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSI()
	{
		testBegin( "testImageAtomicExchange2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayI()
	{
		testBegin( "testImageAtomicExchange2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferU()
	{
		testBegin( "testImageAtomicCompSwapBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DU()
	{
		testBegin( "testImageAtomicCompSwap1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayU()
	{
		testBegin( "testImageAtomicCompSwap1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DU()
	{
		testBegin( "testImageAtomicCompSwap2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectU()
	{
		testBegin( "testImageAtomicCompSwap2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayU()
	{
		testBegin( "testImageAtomicCompSwap2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DU()
	{
		testBegin( "testImageAtomicCompSwap3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeU()
	{
		testBegin( "testImageAtomicCompSwapCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayU()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSU()
	{
		testBegin( "testImageAtomicCompSwap2DMSU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayU()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayU = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferI()
	{
		testBegin( "testImageAtomicCompSwapBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DI()
	{
		testBegin( "testImageAtomicCompSwap1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayI()
	{
		testBegin( "testImageAtomicCompSwap1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DI()
	{
		testBegin( "testImageAtomicCompSwap2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectI()
	{
		testBegin( "testImageAtomicCompSwap2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayI()
	{
		testBegin( "testImageAtomicCompSwap2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DI()
	{
		testBegin( "testImageAtomicCompSwap3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeI()
	{
		testBegin( "testImageAtomicCompSwapCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayI()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSI()
	{
		testBegin( "testImageAtomicCompSwap2DMSI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayI()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayI = true;
			compileHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterHlslImageAccesses" );
	testImageSizeBufferF();
	testImageSizeBufferI();
	testImageSizeBufferU();
	testImageSize1DF();
	testImageSize1DI();
	testImageSizeBufferU();
	testImageSize1DArrayF();
	testImageSize1DArrayI();
	testImageSize1DArrayU();
	testImageSize2DF();
	testImageSize2DRectF();
	testImageSize2DI();
	testImageSize2DRectI();
	testImageSize2DU();
	testImageSize2DRectU();
	testImageSize2DArrayF();
	testImageSize2DArrayI();
	testImageSize2DArrayU();
	testImageSize3DF();
	testImageSize3DI();
	testImageSize3DU();
	testImageSizeCubeF();
	testImageSizeCubeI();
	testImageSizeCubeU();
	testImageSizeCubeArrayF();
	testImageSizeCubeArrayI();
	testImageSizeCubeArrayU();
	testImageSize2DMSF();
	testImageSize2DMSI();
	testImageSize2DMSU();
	testImageSize2DMSArrayF();
	testImageSize2DMSArrayI();
	testImageSize2DMSArrayU();
	testImageSamples2DMSF();
	testImageSamples2DMSI();
	testImageSamples2DMSU();
	testImageSamples2DMSArrayF();
	testImageSamples2DMSArrayI();
	testImageSamples2DMSArrayU();
	testImageLoadBufferF();
	testImageLoadBufferI();
	testImageLoadBufferU();
	testImageLoad1DF();
	testImageLoad1DI();
	testImageLoad1DU();
	testImageLoad1DArrayF();
	testImageLoad1DArrayI();
	testImageLoad1DArrayU();
	testImageLoad2DF();
	testImageLoad2DRectF();
	testImageLoad2DI();
	testImageLoad2DRectI();
	testImageLoad2DU();
	testImageLoad2DRectU();
	testImageLoad2DArrayF();
	testImageLoad2DArrayI();
	testImageLoad2DArrayU();
	testImageLoad3DF();
	testImageLoad3DI();
	testImageLoad3DU();
	testImageLoadCubeF();
	testImageLoadCubeI();
	testImageLoadCubeU();
	testImageLoadCubeArrayF();
	testImageLoadCubeArrayI();
	testImageLoadCubeArrayU();
	testImageLoad2DMSF();
	testImageLoad2DMSI();
	testImageLoad2DMSU();
	testImageLoad2DMSArrayF();
	testImageLoad2DMSArrayI();
	testImageLoad2DMSArrayU();
	testImageAtomicAddBufferU();
	testImageAtomicAdd1DU();
	testImageAtomicAdd1DArrayU();
	testImageAtomicAdd2DU();
	testImageAtomicAdd2DRectU();
	testImageAtomicAdd2DArrayU();
	testImageAtomicAdd3DU();
	testImageAtomicAddCubeU();
	testImageAtomicAddCubeArrayU();
	testImageAtomicAdd2DMSU();
	testImageAtomicAdd2DMSArrayU();
	testImageAtomicAddBufferI();
	testImageAtomicAdd1DI();
	testImageAtomicAdd1DArrayI();
	testImageAtomicAdd2DI();
	testImageAtomicAdd2DRectI();
	testImageAtomicAdd2DArrayI();
	testImageAtomicAdd3DI();
	testImageAtomicAddCubeI();
	testImageAtomicAddCubeArrayI();
	testImageAtomicAdd2DMSI();
	testImageAtomicAdd2DMSArrayI();
	testImageAtomicMinBufferU();
	testImageAtomicMin1DU();
	testImageAtomicMin1DArrayU();
	testImageAtomicMin2DU();
	testImageAtomicMin2DRectU();
	testImageAtomicMin2DArrayU();
	testImageAtomicMin3DU();
	testImageAtomicMinCubeU();
	testImageAtomicMinCubeArrayU();
	testImageAtomicMin2DMSU();
	testImageAtomicMin2DMSArrayU();
	testImageAtomicMinBufferI();
	testImageAtomicMin1DI();
	testImageAtomicMin1DArrayI();
	testImageAtomicMin2DI();
	testImageAtomicMin2DRectI();
	testImageAtomicMin2DArrayI();
	testImageAtomicMin3DI();
	testImageAtomicMinCubeI();
	testImageAtomicMinCubeArrayI();
	testImageAtomicMin2DMSI();
	testImageAtomicMin2DMSArrayI();
	testImageAtomicMaxBufferU();
	testImageAtomicMax1DU();
	testImageAtomicMax1DArrayU();
	testImageAtomicMax2DU();
	testImageAtomicMax2DRectU();
	testImageAtomicMax2DArrayU();
	testImageAtomicMax3DU();
	testImageAtomicMaxCubeU();
	testImageAtomicMaxCubeArrayU();
	testImageAtomicMax2DMSU();
	testImageAtomicMax2DMSArrayU();
	testImageAtomicMaxBufferI();
	testImageAtomicMax1DI();
	testImageAtomicMax1DArrayI();
	testImageAtomicMax2DI();
	testImageAtomicMax2DRectI();
	testImageAtomicMax2DArrayI();
	testImageAtomicMax3DI();
	testImageAtomicMaxCubeI();
	testImageAtomicMaxCubeArrayI();
	testImageAtomicMax2DMSI();
	testImageAtomicMax2DMSArrayI();
	testImageAtomicAndBufferU();
	testImageAtomicAnd1DU();
	testImageAtomicAnd1DArrayU();
	testImageAtomicAnd2DU();
	testImageAtomicAnd2DRectU();
	testImageAtomicAnd2DArrayU();
	testImageAtomicAnd3DU();
	testImageAtomicAndCubeU();
	testImageAtomicAndCubeArrayU();
	testImageAtomicAnd2DMSU();
	testImageAtomicAnd2DMSArrayU();
	testImageAtomicAndBufferI();
	testImageAtomicAnd1DI();
	testImageAtomicAnd1DArrayI();
	testImageAtomicAnd2DI();
	testImageAtomicAnd2DRectI();
	testImageAtomicAnd2DArrayI();
	testImageAtomicAnd3DI();
	testImageAtomicAndCubeI();
	testImageAtomicAndCubeArrayI();
	testImageAtomicAnd2DMSI();
	testImageAtomicAnd2DMSArrayI();
	testImageAtomicOrBufferU();
	testImageAtomicOr1DU();
	testImageAtomicOr1DArrayU();
	testImageAtomicOr2DU();
	testImageAtomicOr2DRectU();
	testImageAtomicOr2DArrayU();
	testImageAtomicOr3DU();
	testImageAtomicOrCubeU();
	testImageAtomicOrCubeArrayU();
	testImageAtomicOr2DMSU();
	testImageAtomicOr2DMSArrayU();
	testImageAtomicOrBufferI();
	testImageAtomicOr1DI();
	testImageAtomicOr1DArrayI();
	testImageAtomicOr2DI();
	testImageAtomicOr2DRectI();
	testImageAtomicOr2DArrayI();
	testImageAtomicOr3DI();
	testImageAtomicOrCubeI();
	testImageAtomicOrCubeArrayI();
	testImageAtomicOr2DMSI();
	testImageAtomicOr2DMSArrayI();
	testImageAtomicXorBufferU();
	testImageAtomicXor1DU();
	testImageAtomicXor1DArrayU();
	testImageAtomicXor2DU();
	testImageAtomicXor2DRectU();
	testImageAtomicXor2DArrayU();
	testImageAtomicXor3DU();
	testImageAtomicXorCubeU();
	testImageAtomicXorCubeArrayU();
	testImageAtomicXor2DMSU();
	testImageAtomicXor2DMSArrayU();
	testImageAtomicXorBufferI();
	testImageAtomicXor1DI();
	testImageAtomicXor1DArrayI();
	testImageAtomicXor2DI();
	testImageAtomicXor2DRectI();
	testImageAtomicXor2DArrayI();
	testImageAtomicXor3DI();
	testImageAtomicXorCubeI();
	testImageAtomicXorCubeArrayI();
	testImageAtomicXor2DMSI();
	testImageAtomicXor2DMSArrayI();
	testImageAtomicExchangeBufferU();
	testImageAtomicExchange1DU();
	testImageAtomicExchange1DArrayU();
	testImageAtomicExchange2DU();
	testImageAtomicExchange2DRectU();
	testImageAtomicExchange2DArrayU();
	testImageAtomicExchange3DU();
	testImageAtomicExchangeCubeU();
	testImageAtomicExchangeCubeArrayU();
	testImageAtomicExchange2DMSU();
	testImageAtomicExchange2DMSArrayU();
	testImageAtomicExchangeBufferI();
	testImageAtomicExchange1DI();
	testImageAtomicExchange1DArrayI();
	testImageAtomicExchange2DI();
	testImageAtomicExchange2DRectI();
	testImageAtomicExchange2DArrayI();
	testImageAtomicExchange3DI();
	testImageAtomicExchangeCubeI();
	testImageAtomicExchangeCubeArrayI();
	testImageAtomicExchange2DMSI();
	testImageAtomicExchange2DMSArrayI();
	testImageAtomicCompSwapBufferU();
	testImageAtomicCompSwap1DU();
	testImageAtomicCompSwap1DArrayU();
	testImageAtomicCompSwap2DU();
	testImageAtomicCompSwap2DRectU();
	testImageAtomicCompSwap2DArrayU();
	testImageAtomicCompSwap3DU();
	testImageAtomicCompSwapCubeU();
	testImageAtomicCompSwapCubeArrayU();
	testImageAtomicCompSwap2DMSU();
	testImageAtomicCompSwap2DMSArrayU();
	testImageAtomicCompSwapBufferI();
	testImageAtomicCompSwap1DI();
	testImageAtomicCompSwap1DArrayI();
	testImageAtomicCompSwap2DI();
	testImageAtomicCompSwap2DRectI();
	testImageAtomicCompSwap2DArrayI();
	testImageAtomicCompSwap3DI();
	testImageAtomicCompSwapCubeI();
	testImageAtomicCompSwapCubeArrayI();
	testImageAtomicCompSwap2DMSI();
	testImageAtomicCompSwap2DMSArrayI();
	testSuiteEnd();
}
