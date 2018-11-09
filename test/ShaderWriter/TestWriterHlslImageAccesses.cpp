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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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
			writeHlslImageAccessFunctions( cont.get(), config );
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

	void testImageAtomicAddBufferFU()
	{
		testBegin( "testImageAtomicAddBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddBufferIU()
	{
		testBegin( "testImageAtomicAddBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddBufferUU()
	{
		testBegin( "testImageAtomicAddBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DFU()
	{
		testBegin( "testImageAtomicAdd1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DIU()
	{
		testBegin( "testImageAtomicAdd1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DUU()
	{
		testBegin( "testImageAtomicAdd1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayFU()
	{
		testBegin( "testImageAtomicAdd1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayIU()
	{
		testBegin( "testImageAtomicAdd1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayUU()
	{
		testBegin( "testImageAtomicAdd1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DFU()
	{
		testBegin( "testImageAtomicAdd2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectFU()
	{
		testBegin( "testImageAtomicAdd2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DIU()
	{
		testBegin( "testImageAtomicAdd2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectIU()
	{
		testBegin( "testImageAtomicAdd2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DUU()
	{
		testBegin( "testImageAtomicAdd2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectUU()
	{
		testBegin( "testImageAtomicAdd2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayFU()
	{
		testBegin( "testImageAtomicAdd2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayIU()
	{
		testBegin( "testImageAtomicAdd2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayUU()
	{
		testBegin( "testImageAtomicAdd2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DFU()
	{
		testBegin( "testImageAtomicAdd3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DIU()
	{
		testBegin( "testImageAtomicAdd3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DUU()
	{
		testBegin( "testImageAtomicAdd3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeFU()
	{
		testBegin( "testImageAtomicAddCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeIU()
	{
		testBegin( "testImageAtomicAddCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeUU()
	{
		testBegin( "testImageAtomicAddCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayFU()
	{
		testBegin( "testImageAtomicAddCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayIU()
	{
		testBegin( "testImageAtomicAddCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayUU()
	{
		testBegin( "testImageAtomicAddCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSFU()
	{
		testBegin( "testImageAtomicAdd2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSIU()
	{
		testBegin( "testImageAtomicAdd2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSUU()
	{
		testBegin( "testImageAtomicAdd2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayFU()
	{
		testBegin( "testImageAtomicAdd2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayIU()
	{
		testBegin( "testImageAtomicAdd2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayUU()
	{
		testBegin( "testImageAtomicAdd2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddBufferFI()
	{
		testBegin( "testImageAtomicAddBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddBufferII()
	{
		testBegin( "testImageAtomicAddBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddBufferUI()
	{
		testBegin( "testImageAtomicAddBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DFI()
	{
		testBegin( "testImageAtomicAdd1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DII()
	{
		testBegin( "testImageAtomicAdd1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DUI()
	{
		testBegin( "testImageAtomicAdd1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayFI()
	{
		testBegin( "testImageAtomicAdd1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayII()
	{
		testBegin( "testImageAtomicAdd1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd1DArrayUI()
	{
		testBegin( "testImageAtomicAdd1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DFI()
	{
		testBegin( "testImageAtomicAdd2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectFI()
	{
		testBegin( "testImageAtomicAdd2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DII()
	{
		testBegin( "testImageAtomicAdd2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectII()
	{
		testBegin( "testImageAtomicAdd2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DUI()
	{
		testBegin( "testImageAtomicAdd2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DRectUI()
	{
		testBegin( "testImageAtomicAdd2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayFI()
	{
		testBegin( "testImageAtomicAdd2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayII()
	{
		testBegin( "testImageAtomicAdd2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DArrayUI()
	{
		testBegin( "testImageAtomicAdd2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DFI()
	{
		testBegin( "testImageAtomicAdd3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DII()
	{
		testBegin( "testImageAtomicAdd3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd3DUI()
	{
		testBegin( "testImageAtomicAdd3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeFI()
	{
		testBegin( "testImageAtomicAddCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeII()
	{
		testBegin( "testImageAtomicAddCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeUI()
	{
		testBegin( "testImageAtomicAddCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayFI()
	{
		testBegin( "testImageAtomicAddCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayII()
	{
		testBegin( "testImageAtomicAddCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAddCubeArrayUI()
	{
		testBegin( "testImageAtomicAddCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAddCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSFI()
	{
		testBegin( "testImageAtomicAdd2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSII()
	{
		testBegin( "testImageAtomicAdd2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSUI()
	{
		testBegin( "testImageAtomicAdd2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayFI()
	{
		testBegin( "testImageAtomicAdd2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayII()
	{
		testBegin( "testImageAtomicAdd2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAdd2DMSArrayUI()
	{
		testBegin( "testImageAtomicAdd2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAdd2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferFU()
	{
		testBegin( "testImageAtomicMinBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferIU()
	{
		testBegin( "testImageAtomicMinBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferUU()
	{
		testBegin( "testImageAtomicMinBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DFU()
	{
		testBegin( "testImageAtomicMin1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DIU()
	{
		testBegin( "testImageAtomicMin1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DUU()
	{
		testBegin( "testImageAtomicMin1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayFU()
	{
		testBegin( "testImageAtomicMin1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayIU()
	{
		testBegin( "testImageAtomicMin1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayUU()
	{
		testBegin( "testImageAtomicMin1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DFU()
	{
		testBegin( "testImageAtomicMin2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectFU()
	{
		testBegin( "testImageAtomicMin2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DIU()
	{
		testBegin( "testImageAtomicMin2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectIU()
	{
		testBegin( "testImageAtomicMin2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DUU()
	{
		testBegin( "testImageAtomicMin2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectUU()
	{
		testBegin( "testImageAtomicMin2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayFU()
	{
		testBegin( "testImageAtomicMin2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayIU()
	{
		testBegin( "testImageAtomicMin2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayUU()
	{
		testBegin( "testImageAtomicMin2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DFU()
	{
		testBegin( "testImageAtomicMin3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DIU()
	{
		testBegin( "testImageAtomicMin3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DUU()
	{
		testBegin( "testImageAtomicMin3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeFU()
	{
		testBegin( "testImageAtomicMinCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeIU()
	{
		testBegin( "testImageAtomicMinCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeUU()
	{
		testBegin( "testImageAtomicMinCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayFU()
	{
		testBegin( "testImageAtomicMinCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayIU()
	{
		testBegin( "testImageAtomicMinCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayUU()
	{
		testBegin( "testImageAtomicMinCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSFU()
	{
		testBegin( "testImageAtomicMin2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSIU()
	{
		testBegin( "testImageAtomicMin2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSUU()
	{
		testBegin( "testImageAtomicMin2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayFU()
	{
		testBegin( "testImageAtomicMin2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayIU()
	{
		testBegin( "testImageAtomicMin2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayUU()
	{
		testBegin( "testImageAtomicMin2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferFI()
	{
		testBegin( "testImageAtomicMinBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferII()
	{
		testBegin( "testImageAtomicMinBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinBufferUI()
	{
		testBegin( "testImageAtomicMinBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DFI()
	{
		testBegin( "testImageAtomicMin1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DII()
	{
		testBegin( "testImageAtomicMin1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DUI()
	{
		testBegin( "testImageAtomicMin1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayFI()
	{
		testBegin( "testImageAtomicMin1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayII()
	{
		testBegin( "testImageAtomicMin1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin1DArrayUI()
	{
		testBegin( "testImageAtomicMin1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DFI()
	{
		testBegin( "testImageAtomicMin2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectFI()
	{
		testBegin( "testImageAtomicMin2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DII()
	{
		testBegin( "testImageAtomicMin2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectII()
	{
		testBegin( "testImageAtomicMin2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DUI()
	{
		testBegin( "testImageAtomicMin2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DRectUI()
	{
		testBegin( "testImageAtomicMin2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayFI()
	{
		testBegin( "testImageAtomicMin2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayII()
	{
		testBegin( "testImageAtomicMin2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DArrayUI()
	{
		testBegin( "testImageAtomicMin2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DFI()
	{
		testBegin( "testImageAtomicMin3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DII()
	{
		testBegin( "testImageAtomicMin3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin3DUI()
	{
		testBegin( "testImageAtomicMin3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeFI()
	{
		testBegin( "testImageAtomicMinCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeII()
	{
		testBegin( "testImageAtomicMinCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeUI()
	{
		testBegin( "testImageAtomicMinCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayFI()
	{
		testBegin( "testImageAtomicMinCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayII()
	{
		testBegin( "testImageAtomicMinCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMinCubeArrayUI()
	{
		testBegin( "testImageAtomicMinCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMinCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSFI()
	{
		testBegin( "testImageAtomicMin2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSII()
	{
		testBegin( "testImageAtomicMin2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSUI()
	{
		testBegin( "testImageAtomicMin2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayFI()
	{
		testBegin( "testImageAtomicMin2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayII()
	{
		testBegin( "testImageAtomicMin2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMin2DMSArrayUI()
	{
		testBegin( "testImageAtomicMin2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMin2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferFU()
	{
		testBegin( "testImageAtomicMaxBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferIU()
	{
		testBegin( "testImageAtomicMaxBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferUU()
	{
		testBegin( "testImageAtomicMaxBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DFU()
	{
		testBegin( "testImageAtomicMax1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DIU()
	{
		testBegin( "testImageAtomicMax1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DUU()
	{
		testBegin( "testImageAtomicMax1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayFU()
	{
		testBegin( "testImageAtomicMax1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayIU()
	{
		testBegin( "testImageAtomicMax1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayUU()
	{
		testBegin( "testImageAtomicMax1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DFU()
	{
		testBegin( "testImageAtomicMax2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectFU()
	{
		testBegin( "testImageAtomicMax2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DIU()
	{
		testBegin( "testImageAtomicMax2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectIU()
	{
		testBegin( "testImageAtomicMax2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DUU()
	{
		testBegin( "testImageAtomicMax2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectUU()
	{
		testBegin( "testImageAtomicMax2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayFU()
	{
		testBegin( "testImageAtomicMax2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayIU()
	{
		testBegin( "testImageAtomicMax2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayUU()
	{
		testBegin( "testImageAtomicMax2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DFU()
	{
		testBegin( "testImageAtomicMax3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DIU()
	{
		testBegin( "testImageAtomicMax3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DUU()
	{
		testBegin( "testImageAtomicMax3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeFU()
	{
		testBegin( "testImageAtomicMaxCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeIU()
	{
		testBegin( "testImageAtomicMaxCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeUU()
	{
		testBegin( "testImageAtomicMaxCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayFU()
	{
		testBegin( "testImageAtomicMaxCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayIU()
	{
		testBegin( "testImageAtomicMaxCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayUU()
	{
		testBegin( "testImageAtomicMaxCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSFU()
	{
		testBegin( "testImageAtomicMax2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSIU()
	{
		testBegin( "testImageAtomicMax2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSUU()
	{
		testBegin( "testImageAtomicMax2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayFU()
	{
		testBegin( "testImageAtomicMax2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayIU()
	{
		testBegin( "testImageAtomicMax2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayUU()
	{
		testBegin( "testImageAtomicMax2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferFI()
	{
		testBegin( "testImageAtomicMaxBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferII()
	{
		testBegin( "testImageAtomicMaxBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxBufferUI()
	{
		testBegin( "testImageAtomicMaxBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DFI()
	{
		testBegin( "testImageAtomicMax1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DII()
	{
		testBegin( "testImageAtomicMax1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DUI()
	{
		testBegin( "testImageAtomicMax1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayFI()
	{
		testBegin( "testImageAtomicMax1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayII()
	{
		testBegin( "testImageAtomicMax1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax1DArrayUI()
	{
		testBegin( "testImageAtomicMax1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DFI()
	{
		testBegin( "testImageAtomicMax2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectFI()
	{
		testBegin( "testImageAtomicMax2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DII()
	{
		testBegin( "testImageAtomicMax2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectII()
	{
		testBegin( "testImageAtomicMax2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DUI()
	{
		testBegin( "testImageAtomicMax2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DRectUI()
	{
		testBegin( "testImageAtomicMax2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayFI()
	{
		testBegin( "testImageAtomicMax2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayII()
	{
		testBegin( "testImageAtomicMax2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DArrayUI()
	{
		testBegin( "testImageAtomicMax2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DFI()
	{
		testBegin( "testImageAtomicMax3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DII()
	{
		testBegin( "testImageAtomicMax3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax3DUI()
	{
		testBegin( "testImageAtomicMax3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeFI()
	{
		testBegin( "testImageAtomicMaxCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeII()
	{
		testBegin( "testImageAtomicMaxCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeUI()
	{
		testBegin( "testImageAtomicMaxCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayFI()
	{
		testBegin( "testImageAtomicMaxCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayII()
	{
		testBegin( "testImageAtomicMaxCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMaxCubeArrayUI()
	{
		testBegin( "testImageAtomicMaxCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMaxCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSFI()
	{
		testBegin( "testImageAtomicMax2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSII()
	{
		testBegin( "testImageAtomicMax2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSUI()
	{
		testBegin( "testImageAtomicMax2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayFI()
	{
		testBegin( "testImageAtomicMax2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayII()
	{
		testBegin( "testImageAtomicMax2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicMax2DMSArrayUI()
	{
		testBegin( "testImageAtomicMax2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicMax2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferFU()
	{
		testBegin( "testImageAtomicAndBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferIU()
	{
		testBegin( "testImageAtomicAndBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferUU()
	{
		testBegin( "testImageAtomicAndBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DFU()
	{
		testBegin( "testImageAtomicAnd1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DIU()
	{
		testBegin( "testImageAtomicAnd1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DUU()
	{
		testBegin( "testImageAtomicAnd1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayFU()
	{
		testBegin( "testImageAtomicAnd1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayIU()
	{
		testBegin( "testImageAtomicAnd1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayUU()
	{
		testBegin( "testImageAtomicAnd1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DFU()
	{
		testBegin( "testImageAtomicAnd2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectFU()
	{
		testBegin( "testImageAtomicAnd2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DIU()
	{
		testBegin( "testImageAtomicAnd2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectIU()
	{
		testBegin( "testImageAtomicAnd2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DUU()
	{
		testBegin( "testImageAtomicAnd2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectUU()
	{
		testBegin( "testImageAtomicAnd2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayFU()
	{
		testBegin( "testImageAtomicAnd2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayIU()
	{
		testBegin( "testImageAtomicAnd2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayUU()
	{
		testBegin( "testImageAtomicAnd2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DFU()
	{
		testBegin( "testImageAtomicAnd3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DIU()
	{
		testBegin( "testImageAtomicAnd3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DUU()
	{
		testBegin( "testImageAtomicAnd3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeFU()
	{
		testBegin( "testImageAtomicAndCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeIU()
	{
		testBegin( "testImageAtomicAndCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeUU()
	{
		testBegin( "testImageAtomicAndCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayFU()
	{
		testBegin( "testImageAtomicAndCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayIU()
	{
		testBegin( "testImageAtomicAndCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayUU()
	{
		testBegin( "testImageAtomicAndCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSFU()
	{
		testBegin( "testImageAtomicAnd2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSIU()
	{
		testBegin( "testImageAtomicAnd2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSUU()
	{
		testBegin( "testImageAtomicAnd2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayFU()
	{
		testBegin( "testImageAtomicAnd2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayIU()
	{
		testBegin( "testImageAtomicAnd2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayUU()
	{
		testBegin( "testImageAtomicAnd2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferFI()
	{
		testBegin( "testImageAtomicAndBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferII()
	{
		testBegin( "testImageAtomicAndBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndBufferUI()
	{
		testBegin( "testImageAtomicAndBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DFI()
	{
		testBegin( "testImageAtomicAnd1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DII()
	{
		testBegin( "testImageAtomicAnd1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DUI()
	{
		testBegin( "testImageAtomicAnd1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayFI()
	{
		testBegin( "testImageAtomicAnd1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayII()
	{
		testBegin( "testImageAtomicAnd1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd1DArrayUI()
	{
		testBegin( "testImageAtomicAnd1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DFI()
	{
		testBegin( "testImageAtomicAnd2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectFI()
	{
		testBegin( "testImageAtomicAnd2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DII()
	{
		testBegin( "testImageAtomicAnd2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectII()
	{
		testBegin( "testImageAtomicAnd2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DUI()
	{
		testBegin( "testImageAtomicAnd2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DRectUI()
	{
		testBegin( "testImageAtomicAnd2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayFI()
	{
		testBegin( "testImageAtomicAnd2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayII()
	{
		testBegin( "testImageAtomicAnd2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DArrayUI()
	{
		testBegin( "testImageAtomicAnd2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DFI()
	{
		testBegin( "testImageAtomicAnd3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DII()
	{
		testBegin( "testImageAtomicAnd3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd3DUI()
	{
		testBegin( "testImageAtomicAnd3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeFI()
	{
		testBegin( "testImageAtomicAndCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeII()
	{
		testBegin( "testImageAtomicAndCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeUI()
	{
		testBegin( "testImageAtomicAndCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayFI()
	{
		testBegin( "testImageAtomicAndCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayII()
	{
		testBegin( "testImageAtomicAndCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAndCubeArrayUI()
	{
		testBegin( "testImageAtomicAndCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAndCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSFI()
	{
		testBegin( "testImageAtomicAnd2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSII()
	{
		testBegin( "testImageAtomicAnd2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSUI()
	{
		testBegin( "testImageAtomicAnd2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayFI()
	{
		testBegin( "testImageAtomicAnd2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayII()
	{
		testBegin( "testImageAtomicAnd2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicAnd2DMSArrayUI()
	{
		testBegin( "testImageAtomicAnd2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicAnd2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferFU()
	{
		testBegin( "testImageAtomicOrBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferIU()
	{
		testBegin( "testImageAtomicOrBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferUU()
	{
		testBegin( "testImageAtomicOrBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DFU()
	{
		testBegin( "testImageAtomicOr1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DIU()
	{
		testBegin( "testImageAtomicOr1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DUU()
	{
		testBegin( "testImageAtomicOr1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayFU()
	{
		testBegin( "testImageAtomicOr1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayIU()
	{
		testBegin( "testImageAtomicOr1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayUU()
	{
		testBegin( "testImageAtomicOr1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DFU()
	{
		testBegin( "testImageAtomicOr2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectFU()
	{
		testBegin( "testImageAtomicOr2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DIU()
	{
		testBegin( "testImageAtomicOr2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectIU()
	{
		testBegin( "testImageAtomicOr2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DUU()
	{
		testBegin( "testImageAtomicOr2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectUU()
	{
		testBegin( "testImageAtomicOr2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayFU()
	{
		testBegin( "testImageAtomicOr2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayIU()
	{
		testBegin( "testImageAtomicOr2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayUU()
	{
		testBegin( "testImageAtomicOr2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DFU()
	{
		testBegin( "testImageAtomicOr3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DIU()
	{
		testBegin( "testImageAtomicOr3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DUU()
	{
		testBegin( "testImageAtomicOr3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeFU()
	{
		testBegin( "testImageAtomicOrCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeIU()
	{
		testBegin( "testImageAtomicOrCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeUU()
	{
		testBegin( "testImageAtomicOrCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayFU()
	{
		testBegin( "testImageAtomicOrCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayIU()
	{
		testBegin( "testImageAtomicOrCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayUU()
	{
		testBegin( "testImageAtomicOrCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSFU()
	{
		testBegin( "testImageAtomicOr2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSIU()
	{
		testBegin( "testImageAtomicOr2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSUU()
	{
		testBegin( "testImageAtomicOr2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayFU()
	{
		testBegin( "testImageAtomicOr2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayIU()
	{
		testBegin( "testImageAtomicOr2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayUU()
	{
		testBegin( "testImageAtomicOr2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferFI()
	{
		testBegin( "testImageAtomicOrBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferII()
	{
		testBegin( "testImageAtomicOrBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrBufferUI()
	{
		testBegin( "testImageAtomicOrBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DFI()
	{
		testBegin( "testImageAtomicOr1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DII()
	{
		testBegin( "testImageAtomicOr1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DUI()
	{
		testBegin( "testImageAtomicOr1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayFI()
	{
		testBegin( "testImageAtomicOr1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayII()
	{
		testBegin( "testImageAtomicOr1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr1DArrayUI()
	{
		testBegin( "testImageAtomicOr1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DFI()
	{
		testBegin( "testImageAtomicOr2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectFI()
	{
		testBegin( "testImageAtomicOr2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DII()
	{
		testBegin( "testImageAtomicOr2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectII()
	{
		testBegin( "testImageAtomicOr2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DUI()
	{
		testBegin( "testImageAtomicOr2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DRectUI()
	{
		testBegin( "testImageAtomicOr2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayFI()
	{
		testBegin( "testImageAtomicOr2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayII()
	{
		testBegin( "testImageAtomicOr2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DArrayUI()
	{
		testBegin( "testImageAtomicOr2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DFI()
	{
		testBegin( "testImageAtomicOr3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DII()
	{
		testBegin( "testImageAtomicOr3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr3DUI()
	{
		testBegin( "testImageAtomicOr3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeFI()
	{
		testBegin( "testImageAtomicOrCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeII()
	{
		testBegin( "testImageAtomicOrCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeUI()
	{
		testBegin( "testImageAtomicOrCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayFI()
	{
		testBegin( "testImageAtomicOrCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayII()
	{
		testBegin( "testImageAtomicOrCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOrCubeArrayUI()
	{
		testBegin( "testImageAtomicOrCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOrCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSFI()
	{
		testBegin( "testImageAtomicOr2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSII()
	{
		testBegin( "testImageAtomicOr2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSUI()
	{
		testBegin( "testImageAtomicOr2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayFI()
	{
		testBegin( "testImageAtomicOr2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayII()
	{
		testBegin( "testImageAtomicOr2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicOr2DMSArrayUI()
	{
		testBegin( "testImageAtomicOr2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicOr2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferFU()
	{
		testBegin( "testImageAtomicXorBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferIU()
	{
		testBegin( "testImageAtomicXorBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferUU()
	{
		testBegin( "testImageAtomicXorBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DFU()
	{
		testBegin( "testImageAtomicXor1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DIU()
	{
		testBegin( "testImageAtomicXor1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DUU()
	{
		testBegin( "testImageAtomicXor1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayFU()
	{
		testBegin( "testImageAtomicXor1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayIU()
	{
		testBegin( "testImageAtomicXor1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayUU()
	{
		testBegin( "testImageAtomicXor1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DFU()
	{
		testBegin( "testImageAtomicXor2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectFU()
	{
		testBegin( "testImageAtomicXor2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DIU()
	{
		testBegin( "testImageAtomicXor2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectIU()
	{
		testBegin( "testImageAtomicXor2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DUU()
	{
		testBegin( "testImageAtomicXor2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectUU()
	{
		testBegin( "testImageAtomicXor2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayFU()
	{
		testBegin( "testImageAtomicXor2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayIU()
	{
		testBegin( "testImageAtomicXor2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayUU()
	{
		testBegin( "testImageAtomicXor2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DFU()
	{
		testBegin( "testImageAtomicXor3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DIU()
	{
		testBegin( "testImageAtomicXor3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DUU()
	{
		testBegin( "testImageAtomicXor3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeFU()
	{
		testBegin( "testImageAtomicXorCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeIU()
	{
		testBegin( "testImageAtomicXorCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeUU()
	{
		testBegin( "testImageAtomicXorCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayFU()
	{
		testBegin( "testImageAtomicXorCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayIU()
	{
		testBegin( "testImageAtomicXorCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayUU()
	{
		testBegin( "testImageAtomicXorCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSFU()
	{
		testBegin( "testImageAtomicXor2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSIU()
	{
		testBegin( "testImageAtomicXor2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSUU()
	{
		testBegin( "testImageAtomicXor2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayFU()
	{
		testBegin( "testImageAtomicXor2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayIU()
	{
		testBegin( "testImageAtomicXor2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayUU()
	{
		testBegin( "testImageAtomicXor2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferFI()
	{
		testBegin( "testImageAtomicXorBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferII()
	{
		testBegin( "testImageAtomicXorBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorBufferUI()
	{
		testBegin( "testImageAtomicXorBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DFI()
	{
		testBegin( "testImageAtomicXor1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DII()
	{
		testBegin( "testImageAtomicXor1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DUI()
	{
		testBegin( "testImageAtomicXor1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayFI()
	{
		testBegin( "testImageAtomicXor1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayII()
	{
		testBegin( "testImageAtomicXor1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor1DArrayUI()
	{
		testBegin( "testImageAtomicXor1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DFI()
	{
		testBegin( "testImageAtomicXor2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectFI()
	{
		testBegin( "testImageAtomicXor2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DII()
	{
		testBegin( "testImageAtomicXor2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectII()
	{
		testBegin( "testImageAtomicXor2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DUI()
	{
		testBegin( "testImageAtomicXor2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DRectUI()
	{
		testBegin( "testImageAtomicXor2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayFI()
	{
		testBegin( "testImageAtomicXor2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayII()
	{
		testBegin( "testImageAtomicXor2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DArrayUI()
	{
		testBegin( "testImageAtomicXor2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DFI()
	{
		testBegin( "testImageAtomicXor3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DII()
	{
		testBegin( "testImageAtomicXor3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor3DUI()
	{
		testBegin( "testImageAtomicXor3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeFI()
	{
		testBegin( "testImageAtomicXorCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeII()
	{
		testBegin( "testImageAtomicXorCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeUI()
	{
		testBegin( "testImageAtomicXorCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayFI()
	{
		testBegin( "testImageAtomicXorCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayII()
	{
		testBegin( "testImageAtomicXorCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXorCubeArrayUI()
	{
		testBegin( "testImageAtomicXorCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXorCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSFI()
	{
		testBegin( "testImageAtomicXor2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSII()
	{
		testBegin( "testImageAtomicXor2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSUI()
	{
		testBegin( "testImageAtomicXor2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayFI()
	{
		testBegin( "testImageAtomicXor2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayII()
	{
		testBegin( "testImageAtomicXor2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicXor2DMSArrayUI()
	{
		testBegin( "testImageAtomicXor2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicXor2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferFU()
	{
		testBegin( "testImageAtomicExchangeBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferIU()
	{
		testBegin( "testImageAtomicExchangeBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferUU()
	{
		testBegin( "testImageAtomicExchangeBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DFU()
	{
		testBegin( "testImageAtomicExchange1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DIU()
	{
		testBegin( "testImageAtomicExchange1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DUU()
	{
		testBegin( "testImageAtomicExchange1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayFU()
	{
		testBegin( "testImageAtomicExchange1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayIU()
	{
		testBegin( "testImageAtomicExchange1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayUU()
	{
		testBegin( "testImageAtomicExchange1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DFU()
	{
		testBegin( "testImageAtomicExchange2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectFU()
	{
		testBegin( "testImageAtomicExchange2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DIU()
	{
		testBegin( "testImageAtomicExchange2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectIU()
	{
		testBegin( "testImageAtomicExchange2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DUU()
	{
		testBegin( "testImageAtomicExchange2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectUU()
	{
		testBegin( "testImageAtomicExchange2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayFU()
	{
		testBegin( "testImageAtomicExchange2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayIU()
	{
		testBegin( "testImageAtomicExchange2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayUU()
	{
		testBegin( "testImageAtomicExchange2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DFU()
	{
		testBegin( "testImageAtomicExchange3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DIU()
	{
		testBegin( "testImageAtomicExchange3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DUU()
	{
		testBegin( "testImageAtomicExchange3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeFU()
	{
		testBegin( "testImageAtomicExchangeCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeIU()
	{
		testBegin( "testImageAtomicExchangeCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeUU()
	{
		testBegin( "testImageAtomicExchangeCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayFU()
	{
		testBegin( "testImageAtomicExchangeCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayIU()
	{
		testBegin( "testImageAtomicExchangeCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayUU()
	{
		testBegin( "testImageAtomicExchangeCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSFU()
	{
		testBegin( "testImageAtomicExchange2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSIU()
	{
		testBegin( "testImageAtomicExchange2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSUU()
	{
		testBegin( "testImageAtomicExchange2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayFU()
	{
		testBegin( "testImageAtomicExchange2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayIU()
	{
		testBegin( "testImageAtomicExchange2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayUU()
	{
		testBegin( "testImageAtomicExchange2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferFI()
	{
		testBegin( "testImageAtomicExchangeBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferII()
	{
		testBegin( "testImageAtomicExchangeBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeBufferUI()
	{
		testBegin( "testImageAtomicExchangeBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DFI()
	{
		testBegin( "testImageAtomicExchange1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DII()
	{
		testBegin( "testImageAtomicExchange1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DUI()
	{
		testBegin( "testImageAtomicExchange1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayFI()
	{
		testBegin( "testImageAtomicExchange1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayII()
	{
		testBegin( "testImageAtomicExchange1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange1DArrayUI()
	{
		testBegin( "testImageAtomicExchange1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DFI()
	{
		testBegin( "testImageAtomicExchange2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectFI()
	{
		testBegin( "testImageAtomicExchange2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DII()
	{
		testBegin( "testImageAtomicExchange2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectII()
	{
		testBegin( "testImageAtomicExchange2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DUI()
	{
		testBegin( "testImageAtomicExchange2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DRectUI()
	{
		testBegin( "testImageAtomicExchange2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayFI()
	{
		testBegin( "testImageAtomicExchange2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayII()
	{
		testBegin( "testImageAtomicExchange2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DArrayUI()
	{
		testBegin( "testImageAtomicExchange2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DFI()
	{
		testBegin( "testImageAtomicExchange3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DII()
	{
		testBegin( "testImageAtomicExchange3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange3DUI()
	{
		testBegin( "testImageAtomicExchange3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeFI()
	{
		testBegin( "testImageAtomicExchangeCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeII()
	{
		testBegin( "testImageAtomicExchangeCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeUI()
	{
		testBegin( "testImageAtomicExchangeCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayFI()
	{
		testBegin( "testImageAtomicExchangeCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayII()
	{
		testBegin( "testImageAtomicExchangeCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchangeCubeArrayUI()
	{
		testBegin( "testImageAtomicExchangeCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchangeCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSFI()
	{
		testBegin( "testImageAtomicExchange2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSII()
	{
		testBegin( "testImageAtomicExchange2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSUI()
	{
		testBegin( "testImageAtomicExchange2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayFI()
	{
		testBegin( "testImageAtomicExchange2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayII()
	{
		testBegin( "testImageAtomicExchange2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicExchange2DMSArrayUI()
	{
		testBegin( "testImageAtomicExchange2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicExchange2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferFU()
	{
		testBegin( "testImageAtomicCompSwapBufferFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferIU()
	{
		testBegin( "testImageAtomicCompSwapBufferIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferUU()
	{
		testBegin( "testImageAtomicCompSwapBufferUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DFU()
	{
		testBegin( "testImageAtomicCompSwap1DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DIU()
	{
		testBegin( "testImageAtomicCompSwap1DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DUU()
	{
		testBegin( "testImageAtomicCompSwap1DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayFU()
	{
		testBegin( "testImageAtomicCompSwap1DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayIU()
	{
		testBegin( "testImageAtomicCompSwap1DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayUU()
	{
		testBegin( "testImageAtomicCompSwap1DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DFU()
	{
		testBegin( "testImageAtomicCompSwap2DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectFU()
	{
		testBegin( "testImageAtomicCompSwap2DRectFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DIU()
	{
		testBegin( "testImageAtomicCompSwap2DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectIU()
	{
		testBegin( "testImageAtomicCompSwap2DRectIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DUU()
	{
		testBegin( "testImageAtomicCompSwap2DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectUU()
	{
		testBegin( "testImageAtomicCompSwap2DRectUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayFU()
	{
		testBegin( "testImageAtomicCompSwap2DArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayIU()
	{
		testBegin( "testImageAtomicCompSwap2DArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayUU()
	{
		testBegin( "testImageAtomicCompSwap2DArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DFU()
	{
		testBegin( "testImageAtomicCompSwap3DFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DIU()
	{
		testBegin( "testImageAtomicCompSwap3DIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DUU()
	{
		testBegin( "testImageAtomicCompSwap3DUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeFU()
	{
		testBegin( "testImageAtomicCompSwapCubeFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeIU()
	{
		testBegin( "testImageAtomicCompSwapCubeIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeUU()
	{
		testBegin( "testImageAtomicCompSwapCubeUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayFU()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayIU()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayUU()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSFU()
	{
		testBegin( "testImageAtomicCompSwap2DMSFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSIU()
	{
		testBegin( "testImageAtomicCompSwap2DMSIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSUU()
	{
		testBegin( "testImageAtomicCompSwap2DMSUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayFU()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayFU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayFU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayIU()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayIU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayIU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayUU()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayUU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayUU = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferFI()
	{
		testBegin( "testImageAtomicCompSwapBufferFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferII()
	{
		testBegin( "testImageAtomicCompSwapBufferII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapBufferUI()
	{
		testBegin( "testImageAtomicCompSwapBufferUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapBufferUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DFI()
	{
		testBegin( "testImageAtomicCompSwap1DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DII()
	{
		testBegin( "testImageAtomicCompSwap1DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DUI()
	{
		testBegin( "testImageAtomicCompSwap1DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayFI()
	{
		testBegin( "testImageAtomicCompSwap1DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayII()
	{
		testBegin( "testImageAtomicCompSwap1DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap1DArrayUI()
	{
		testBegin( "testImageAtomicCompSwap1DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap1DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DFI()
	{
		testBegin( "testImageAtomicCompSwap2DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectFI()
	{
		testBegin( "testImageAtomicCompSwap2DRectFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DII()
	{
		testBegin( "testImageAtomicCompSwap2DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectII()
	{
		testBegin( "testImageAtomicCompSwap2DRectII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DUI()
	{
		testBegin( "testImageAtomicCompSwap2DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DRectUI()
	{
		testBegin( "testImageAtomicCompSwap2DRectUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DRectUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayFI()
	{
		testBegin( "testImageAtomicCompSwap2DArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayII()
	{
		testBegin( "testImageAtomicCompSwap2DArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DArrayUI()
	{
		testBegin( "testImageAtomicCompSwap2DArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DFI()
	{
		testBegin( "testImageAtomicCompSwap3DFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DII()
	{
		testBegin( "testImageAtomicCompSwap3DII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap3DUI()
	{
		testBegin( "testImageAtomicCompSwap3DUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap3DUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeFI()
	{
		testBegin( "testImageAtomicCompSwapCubeFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeII()
	{
		testBegin( "testImageAtomicCompSwapCubeII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeUI()
	{
		testBegin( "testImageAtomicCompSwapCubeUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayFI()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayII()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwapCubeArrayUI()
	{
		testBegin( "testImageAtomicCompSwapCubeArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwapCubeArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSFI()
	{
		testBegin( "testImageAtomicCompSwap2DMSFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSII()
	{
		testBegin( "testImageAtomicCompSwap2DMSII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSUI()
	{
		testBegin( "testImageAtomicCompSwap2DMSUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayFI()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayFI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayFI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayII()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayII" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayII = true;
			writeHlslImageAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testImageAtomicCompSwap2DMSArrayUI()
	{
		testBegin( "testImageAtomicCompSwap2DMSArrayUI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresImageAtomicCompSwap2DMSArrayUI = true;
			writeHlslImageAccessFunctions( cont.get(), config );
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
	testImageAtomicAddBufferFU();
	testImageAtomicAddBufferIU();
	testImageAtomicAddBufferUU();
	testImageAtomicAdd1DFU();
	testImageAtomicAdd1DIU();
	testImageAtomicAdd1DUU();
	testImageAtomicAdd1DArrayFU();
	testImageAtomicAdd1DArrayIU();
	testImageAtomicAdd1DArrayUU();
	testImageAtomicAdd2DFU();
	testImageAtomicAdd2DRectFU();
	testImageAtomicAdd2DIU();
	testImageAtomicAdd2DRectIU();
	testImageAtomicAdd2DUU();
	testImageAtomicAdd2DRectUU();
	testImageAtomicAdd2DArrayFU();
	testImageAtomicAdd2DArrayIU();
	testImageAtomicAdd2DArrayUU();
	testImageAtomicAdd3DFU();
	testImageAtomicAdd3DIU();
	testImageAtomicAdd3DUU();
	testImageAtomicAddCubeFU();
	testImageAtomicAddCubeIU();
	testImageAtomicAddCubeUU();
	testImageAtomicAddCubeArrayFU();
	testImageAtomicAddCubeArrayIU();
	testImageAtomicAddCubeArrayUU();
	testImageAtomicAdd2DMSFU();
	testImageAtomicAdd2DMSIU();
	testImageAtomicAdd2DMSUU();
	testImageAtomicAdd2DMSArrayFU();
	testImageAtomicAdd2DMSArrayIU();
	testImageAtomicAdd2DMSArrayUU();
	testImageAtomicAddBufferFI();
	testImageAtomicAddBufferII();
	testImageAtomicAddBufferUI();
	testImageAtomicAdd1DFI();
	testImageAtomicAdd1DII();
	testImageAtomicAdd1DUI();
	testImageAtomicAdd1DArrayFI();
	testImageAtomicAdd1DArrayII();
	testImageAtomicAdd1DArrayUI();
	testImageAtomicAdd2DFI();
	testImageAtomicAdd2DRectFI();
	testImageAtomicAdd2DII();
	testImageAtomicAdd2DRectII();
	testImageAtomicAdd2DUI();
	testImageAtomicAdd2DRectUI();
	testImageAtomicAdd2DArrayFI();
	testImageAtomicAdd2DArrayII();
	testImageAtomicAdd2DArrayUI();
	testImageAtomicAdd3DFI();
	testImageAtomicAdd3DII();
	testImageAtomicAdd3DUI();
	testImageAtomicAddCubeFI();
	testImageAtomicAddCubeII();
	testImageAtomicAddCubeUI();
	testImageAtomicAddCubeArrayFI();
	testImageAtomicAddCubeArrayII();
	testImageAtomicAddCubeArrayUI();
	testImageAtomicAdd2DMSFI();
	testImageAtomicAdd2DMSII();
	testImageAtomicAdd2DMSUI();
	testImageAtomicAdd2DMSArrayFI();
	testImageAtomicAdd2DMSArrayII();
	testImageAtomicAdd2DMSArrayUI();
	testImageAtomicMinBufferFU();
	testImageAtomicMinBufferIU();
	testImageAtomicMinBufferUU();
	testImageAtomicMin1DFU();
	testImageAtomicMin1DIU();
	testImageAtomicMin1DUU();
	testImageAtomicMin1DArrayFU();
	testImageAtomicMin1DArrayIU();
	testImageAtomicMin1DArrayUU();
	testImageAtomicMin2DFU();
	testImageAtomicMin2DRectFU();
	testImageAtomicMin2DIU();
	testImageAtomicMin2DRectIU();
	testImageAtomicMin2DUU();
	testImageAtomicMin2DRectUU();
	testImageAtomicMin2DArrayFU();
	testImageAtomicMin2DArrayIU();
	testImageAtomicMin2DArrayUU();
	testImageAtomicMin3DFU();
	testImageAtomicMin3DIU();
	testImageAtomicMin3DUU();
	testImageAtomicMinCubeFU();
	testImageAtomicMinCubeIU();
	testImageAtomicMinCubeUU();
	testImageAtomicMinCubeArrayFU();
	testImageAtomicMinCubeArrayIU();
	testImageAtomicMinCubeArrayUU();
	testImageAtomicMin2DMSFU();
	testImageAtomicMin2DMSIU();
	testImageAtomicMin2DMSUU();
	testImageAtomicMin2DMSArrayFU();
	testImageAtomicMin2DMSArrayIU();
	testImageAtomicMin2DMSArrayUU();
	testImageAtomicMinBufferFI();
	testImageAtomicMinBufferII();
	testImageAtomicMinBufferUI();
	testImageAtomicMin1DFI();
	testImageAtomicMin1DII();
	testImageAtomicMin1DUI();
	testImageAtomicMin1DArrayFI();
	testImageAtomicMin1DArrayII();
	testImageAtomicMin1DArrayUI();
	testImageAtomicMin2DFI();
	testImageAtomicMin2DRectFI();
	testImageAtomicMin2DII();
	testImageAtomicMin2DRectII();
	testImageAtomicMin2DUI();
	testImageAtomicMin2DRectUI();
	testImageAtomicMin2DArrayFI();
	testImageAtomicMin2DArrayII();
	testImageAtomicMin2DArrayUI();
	testImageAtomicMin3DFI();
	testImageAtomicMin3DII();
	testImageAtomicMin3DUI();
	testImageAtomicMinCubeFI();
	testImageAtomicMinCubeII();
	testImageAtomicMinCubeUI();
	testImageAtomicMinCubeArrayFI();
	testImageAtomicMinCubeArrayII();
	testImageAtomicMinCubeArrayUI();
	testImageAtomicMin2DMSFI();
	testImageAtomicMin2DMSII();
	testImageAtomicMin2DMSUI();
	testImageAtomicMin2DMSArrayFI();
	testImageAtomicMin2DMSArrayII();
	testImageAtomicMin2DMSArrayUI();
	testImageAtomicMaxBufferFU();
	testImageAtomicMaxBufferIU();
	testImageAtomicMaxBufferUU();
	testImageAtomicMax1DFU();
	testImageAtomicMax1DIU();
	testImageAtomicMax1DUU();
	testImageAtomicMax1DArrayFU();
	testImageAtomicMax1DArrayIU();
	testImageAtomicMax1DArrayUU();
	testImageAtomicMax2DFU();
	testImageAtomicMax2DRectFU();
	testImageAtomicMax2DIU();
	testImageAtomicMax2DRectIU();
	testImageAtomicMax2DUU();
	testImageAtomicMax2DRectUU();
	testImageAtomicMax2DArrayFU();
	testImageAtomicMax2DArrayIU();
	testImageAtomicMax2DArrayUU();
	testImageAtomicMax3DFU();
	testImageAtomicMax3DIU();
	testImageAtomicMax3DUU();
	testImageAtomicMaxCubeFU();
	testImageAtomicMaxCubeIU();
	testImageAtomicMaxCubeUU();
	testImageAtomicMaxCubeArrayFU();
	testImageAtomicMaxCubeArrayIU();
	testImageAtomicMaxCubeArrayUU();
	testImageAtomicMax2DMSFU();
	testImageAtomicMax2DMSIU();
	testImageAtomicMax2DMSUU();
	testImageAtomicMax2DMSArrayFU();
	testImageAtomicMax2DMSArrayIU();
	testImageAtomicMax2DMSArrayUU();
	testImageAtomicMaxBufferFI();
	testImageAtomicMaxBufferII();
	testImageAtomicMaxBufferUI();
	testImageAtomicMax1DFI();
	testImageAtomicMax1DII();
	testImageAtomicMax1DUI();
	testImageAtomicMax1DArrayFI();
	testImageAtomicMax1DArrayII();
	testImageAtomicMax1DArrayUI();
	testImageAtomicMax2DFI();
	testImageAtomicMax2DRectFI();
	testImageAtomicMax2DII();
	testImageAtomicMax2DRectII();
	testImageAtomicMax2DUI();
	testImageAtomicMax2DRectUI();
	testImageAtomicMax2DArrayFI();
	testImageAtomicMax2DArrayII();
	testImageAtomicMax2DArrayUI();
	testImageAtomicMax3DFI();
	testImageAtomicMax3DII();
	testImageAtomicMax3DUI();
	testImageAtomicMaxCubeFI();
	testImageAtomicMaxCubeII();
	testImageAtomicMaxCubeUI();
	testImageAtomicMaxCubeArrayFI();
	testImageAtomicMaxCubeArrayII();
	testImageAtomicMaxCubeArrayUI();
	testImageAtomicMax2DMSFI();
	testImageAtomicMax2DMSII();
	testImageAtomicMax2DMSUI();
	testImageAtomicMax2DMSArrayFI();
	testImageAtomicMax2DMSArrayII();
	testImageAtomicMax2DMSArrayUI();
	testImageAtomicAndBufferFU();
	testImageAtomicAndBufferIU();
	testImageAtomicAndBufferUU();
	testImageAtomicAnd1DFU();
	testImageAtomicAnd1DIU();
	testImageAtomicAnd1DUU();
	testImageAtomicAnd1DArrayFU();
	testImageAtomicAnd1DArrayIU();
	testImageAtomicAnd1DArrayUU();
	testImageAtomicAnd2DFU();
	testImageAtomicAnd2DRectFU();
	testImageAtomicAnd2DIU();
	testImageAtomicAnd2DRectIU();
	testImageAtomicAnd2DUU();
	testImageAtomicAnd2DRectUU();
	testImageAtomicAnd2DArrayFU();
	testImageAtomicAnd2DArrayIU();
	testImageAtomicAnd2DArrayUU();
	testImageAtomicAnd3DFU();
	testImageAtomicAnd3DIU();
	testImageAtomicAnd3DUU();
	testImageAtomicAndCubeFU();
	testImageAtomicAndCubeIU();
	testImageAtomicAndCubeUU();
	testImageAtomicAndCubeArrayFU();
	testImageAtomicAndCubeArrayIU();
	testImageAtomicAndCubeArrayUU();
	testImageAtomicAnd2DMSFU();
	testImageAtomicAnd2DMSIU();
	testImageAtomicAnd2DMSUU();
	testImageAtomicAnd2DMSArrayFU();
	testImageAtomicAnd2DMSArrayIU();
	testImageAtomicAnd2DMSArrayUU();
	testImageAtomicAndBufferFI();
	testImageAtomicAndBufferII();
	testImageAtomicAndBufferUI();
	testImageAtomicAnd1DFI();
	testImageAtomicAnd1DII();
	testImageAtomicAnd1DUI();
	testImageAtomicAnd1DArrayFI();
	testImageAtomicAnd1DArrayII();
	testImageAtomicAnd1DArrayUI();
	testImageAtomicAnd2DFI();
	testImageAtomicAnd2DRectFI();
	testImageAtomicAnd2DII();
	testImageAtomicAnd2DRectII();
	testImageAtomicAnd2DUI();
	testImageAtomicAnd2DRectUI();
	testImageAtomicAnd2DArrayFI();
	testImageAtomicAnd2DArrayII();
	testImageAtomicAnd2DArrayUI();
	testImageAtomicAnd3DFI();
	testImageAtomicAnd3DII();
	testImageAtomicAnd3DUI();
	testImageAtomicAndCubeFI();
	testImageAtomicAndCubeII();
	testImageAtomicAndCubeUI();
	testImageAtomicAndCubeArrayFI();
	testImageAtomicAndCubeArrayII();
	testImageAtomicAndCubeArrayUI();
	testImageAtomicAnd2DMSFI();
	testImageAtomicAnd2DMSII();
	testImageAtomicAnd2DMSUI();
	testImageAtomicAnd2DMSArrayFI();
	testImageAtomicAnd2DMSArrayII();
	testImageAtomicAnd2DMSArrayUI();
	testImageAtomicOrBufferFU();
	testImageAtomicOrBufferIU();
	testImageAtomicOrBufferUU();
	testImageAtomicOr1DFU();
	testImageAtomicOr1DIU();
	testImageAtomicOr1DUU();
	testImageAtomicOr1DArrayFU();
	testImageAtomicOr1DArrayIU();
	testImageAtomicOr1DArrayUU();
	testImageAtomicOr2DFU();
	testImageAtomicOr2DRectFU();
	testImageAtomicOr2DIU();
	testImageAtomicOr2DRectIU();
	testImageAtomicOr2DUU();
	testImageAtomicOr2DRectUU();
	testImageAtomicOr2DArrayFU();
	testImageAtomicOr2DArrayIU();
	testImageAtomicOr2DArrayUU();
	testImageAtomicOr3DFU();
	testImageAtomicOr3DIU();
	testImageAtomicOr3DUU();
	testImageAtomicOrCubeFU();
	testImageAtomicOrCubeIU();
	testImageAtomicOrCubeUU();
	testImageAtomicOrCubeArrayFU();
	testImageAtomicOrCubeArrayIU();
	testImageAtomicOrCubeArrayUU();
	testImageAtomicOr2DMSFU();
	testImageAtomicOr2DMSIU();
	testImageAtomicOr2DMSUU();
	testImageAtomicOr2DMSArrayFU();
	testImageAtomicOr2DMSArrayIU();
	testImageAtomicOr2DMSArrayUU();
	testImageAtomicOrBufferFI();
	testImageAtomicOrBufferII();
	testImageAtomicOrBufferUI();
	testImageAtomicOr1DFI();
	testImageAtomicOr1DII();
	testImageAtomicOr1DUI();
	testImageAtomicOr1DArrayFI();
	testImageAtomicOr1DArrayII();
	testImageAtomicOr1DArrayUI();
	testImageAtomicOr2DFI();
	testImageAtomicOr2DRectFI();
	testImageAtomicOr2DII();
	testImageAtomicOr2DRectII();
	testImageAtomicOr2DUI();
	testImageAtomicOr2DRectUI();
	testImageAtomicOr2DArrayFI();
	testImageAtomicOr2DArrayII();
	testImageAtomicOr2DArrayUI();
	testImageAtomicOr3DFI();
	testImageAtomicOr3DII();
	testImageAtomicOr3DUI();
	testImageAtomicOrCubeFI();
	testImageAtomicOrCubeII();
	testImageAtomicOrCubeUI();
	testImageAtomicOrCubeArrayFI();
	testImageAtomicOrCubeArrayII();
	testImageAtomicOrCubeArrayUI();
	testImageAtomicOr2DMSFI();
	testImageAtomicOr2DMSII();
	testImageAtomicOr2DMSUI();
	testImageAtomicOr2DMSArrayFI();
	testImageAtomicOr2DMSArrayII();
	testImageAtomicOr2DMSArrayUI();
	testImageAtomicXorBufferFU();
	testImageAtomicXorBufferIU();
	testImageAtomicXorBufferUU();
	testImageAtomicXor1DFU();
	testImageAtomicXor1DIU();
	testImageAtomicXor1DUU();
	testImageAtomicXor1DArrayFU();
	testImageAtomicXor1DArrayIU();
	testImageAtomicXor1DArrayUU();
	testImageAtomicXor2DFU();
	testImageAtomicXor2DRectFU();
	testImageAtomicXor2DIU();
	testImageAtomicXor2DRectIU();
	testImageAtomicXor2DUU();
	testImageAtomicXor2DRectUU();
	testImageAtomicXor2DArrayFU();
	testImageAtomicXor2DArrayIU();
	testImageAtomicXor2DArrayUU();
	testImageAtomicXor3DFU();
	testImageAtomicXor3DIU();
	testImageAtomicXor3DUU();
	testImageAtomicXorCubeFU();
	testImageAtomicXorCubeIU();
	testImageAtomicXorCubeUU();
	testImageAtomicXorCubeArrayFU();
	testImageAtomicXorCubeArrayIU();
	testImageAtomicXorCubeArrayUU();
	testImageAtomicXor2DMSFU();
	testImageAtomicXor2DMSIU();
	testImageAtomicXor2DMSUU();
	testImageAtomicXor2DMSArrayFU();
	testImageAtomicXor2DMSArrayIU();
	testImageAtomicXor2DMSArrayUU();
	testImageAtomicXorBufferFI();
	testImageAtomicXorBufferII();
	testImageAtomicXorBufferUI();
	testImageAtomicXor1DFI();
	testImageAtomicXor1DII();
	testImageAtomicXor1DUI();
	testImageAtomicXor1DArrayFI();
	testImageAtomicXor1DArrayII();
	testImageAtomicXor1DArrayUI();
	testImageAtomicXor2DFI();
	testImageAtomicXor2DRectFI();
	testImageAtomicXor2DII();
	testImageAtomicXor2DRectII();
	testImageAtomicXor2DUI();
	testImageAtomicXor2DRectUI();
	testImageAtomicXor2DArrayFI();
	testImageAtomicXor2DArrayII();
	testImageAtomicXor2DArrayUI();
	testImageAtomicXor3DFI();
	testImageAtomicXor3DII();
	testImageAtomicXor3DUI();
	testImageAtomicXorCubeFI();
	testImageAtomicXorCubeII();
	testImageAtomicXorCubeUI();
	testImageAtomicXorCubeArrayFI();
	testImageAtomicXorCubeArrayII();
	testImageAtomicXorCubeArrayUI();
	testImageAtomicXor2DMSFI();
	testImageAtomicXor2DMSII();
	testImageAtomicXor2DMSUI();
	testImageAtomicXor2DMSArrayFI();
	testImageAtomicXor2DMSArrayII();
	testImageAtomicXor2DMSArrayUI();
	testImageAtomicExchangeBufferFU();
	testImageAtomicExchangeBufferIU();
	testImageAtomicExchangeBufferUU();
	testImageAtomicExchange1DFU();
	testImageAtomicExchange1DIU();
	testImageAtomicExchange1DUU();
	testImageAtomicExchange1DArrayFU();
	testImageAtomicExchange1DArrayIU();
	testImageAtomicExchange1DArrayUU();
	testImageAtomicExchange2DFU();
	testImageAtomicExchange2DRectFU();
	testImageAtomicExchange2DIU();
	testImageAtomicExchange2DRectIU();
	testImageAtomicExchange2DUU();
	testImageAtomicExchange2DRectUU();
	testImageAtomicExchange2DArrayFU();
	testImageAtomicExchange2DArrayIU();
	testImageAtomicExchange2DArrayUU();
	testImageAtomicExchange3DFU();
	testImageAtomicExchange3DIU();
	testImageAtomicExchange3DUU();
	testImageAtomicExchangeCubeFU();
	testImageAtomicExchangeCubeIU();
	testImageAtomicExchangeCubeUU();
	testImageAtomicExchangeCubeArrayFU();
	testImageAtomicExchangeCubeArrayIU();
	testImageAtomicExchangeCubeArrayUU();
	testImageAtomicExchange2DMSFU();
	testImageAtomicExchange2DMSIU();
	testImageAtomicExchange2DMSUU();
	testImageAtomicExchange2DMSArrayFU();
	testImageAtomicExchange2DMSArrayIU();
	testImageAtomicExchange2DMSArrayUU();
	testImageAtomicExchangeBufferFI();
	testImageAtomicExchangeBufferII();
	testImageAtomicExchangeBufferUI();
	testImageAtomicExchange1DFI();
	testImageAtomicExchange1DII();
	testImageAtomicExchange1DUI();
	testImageAtomicExchange1DArrayFI();
	testImageAtomicExchange1DArrayII();
	testImageAtomicExchange1DArrayUI();
	testImageAtomicExchange2DFI();
	testImageAtomicExchange2DRectFI();
	testImageAtomicExchange2DII();
	testImageAtomicExchange2DRectII();
	testImageAtomicExchange2DUI();
	testImageAtomicExchange2DRectUI();
	testImageAtomicExchange2DArrayFI();
	testImageAtomicExchange2DArrayII();
	testImageAtomicExchange2DArrayUI();
	testImageAtomicExchange3DFI();
	testImageAtomicExchange3DII();
	testImageAtomicExchange3DUI();
	testImageAtomicExchangeCubeFI();
	testImageAtomicExchangeCubeII();
	testImageAtomicExchangeCubeUI();
	testImageAtomicExchangeCubeArrayFI();
	testImageAtomicExchangeCubeArrayII();
	testImageAtomicExchangeCubeArrayUI();
	testImageAtomicExchange2DMSFI();
	testImageAtomicExchange2DMSII();
	testImageAtomicExchange2DMSUI();
	testImageAtomicExchange2DMSArrayFI();
	testImageAtomicExchange2DMSArrayII();
	testImageAtomicExchange2DMSArrayUI();
	testImageAtomicCompSwapBufferFU();
	testImageAtomicCompSwapBufferIU();
	testImageAtomicCompSwapBufferUU();
	testImageAtomicCompSwap1DFU();
	testImageAtomicCompSwap1DIU();
	testImageAtomicCompSwap1DUU();
	testImageAtomicCompSwap1DArrayFU();
	testImageAtomicCompSwap1DArrayIU();
	testImageAtomicCompSwap1DArrayUU();
	testImageAtomicCompSwap2DFU();
	testImageAtomicCompSwap2DRectFU();
	testImageAtomicCompSwap2DIU();
	testImageAtomicCompSwap2DRectIU();
	testImageAtomicCompSwap2DUU();
	testImageAtomicCompSwap2DRectUU();
	testImageAtomicCompSwap2DArrayFU();
	testImageAtomicCompSwap2DArrayIU();
	testImageAtomicCompSwap2DArrayUU();
	testImageAtomicCompSwap3DFU();
	testImageAtomicCompSwap3DIU();
	testImageAtomicCompSwap3DUU();
	testImageAtomicCompSwapCubeFU();
	testImageAtomicCompSwapCubeIU();
	testImageAtomicCompSwapCubeUU();
	testImageAtomicCompSwapCubeArrayFU();
	testImageAtomicCompSwapCubeArrayIU();
	testImageAtomicCompSwapCubeArrayUU();
	testImageAtomicCompSwap2DMSFU();
	testImageAtomicCompSwap2DMSIU();
	testImageAtomicCompSwap2DMSUU();
	testImageAtomicCompSwap2DMSArrayFU();
	testImageAtomicCompSwap2DMSArrayIU();
	testImageAtomicCompSwap2DMSArrayUU();
	testImageAtomicCompSwapBufferFI();
	testImageAtomicCompSwapBufferII();
	testImageAtomicCompSwapBufferUI();
	testImageAtomicCompSwap1DFI();
	testImageAtomicCompSwap1DII();
	testImageAtomicCompSwap1DUI();
	testImageAtomicCompSwap1DArrayFI();
	testImageAtomicCompSwap1DArrayII();
	testImageAtomicCompSwap1DArrayUI();
	testImageAtomicCompSwap2DFI();
	testImageAtomicCompSwap2DRectFI();
	testImageAtomicCompSwap2DII();
	testImageAtomicCompSwap2DRectII();
	testImageAtomicCompSwap2DUI();
	testImageAtomicCompSwap2DRectUI();
	testImageAtomicCompSwap2DArrayFI();
	testImageAtomicCompSwap2DArrayII();
	testImageAtomicCompSwap2DArrayUI();
	testImageAtomicCompSwap3DFI();
	testImageAtomicCompSwap3DII();
	testImageAtomicCompSwap3DUI();
	testImageAtomicCompSwapCubeFI();
	testImageAtomicCompSwapCubeII();
	testImageAtomicCompSwapCubeUI();
	testImageAtomicCompSwapCubeArrayFI();
	testImageAtomicCompSwapCubeArrayII();
	testImageAtomicCompSwapCubeArrayUI();
	testImageAtomicCompSwap2DMSFI();
	testImageAtomicCompSwap2DMSII();
	testImageAtomicCompSwap2DMSUI();
	testImageAtomicCompSwap2DMSArrayFI();
	testImageAtomicCompSwap2DMSArrayII();
	testImageAtomicCompSwap2DMSArrayUI();
	testSuiteEnd();
}
