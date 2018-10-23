#include "Common.hpp"
#include "TestWriterCommon.hpp"

#include <ShaderWriter/HLSL/HlslStmtVisitor.hpp>
#include <ShaderWriter/HLSL/HlslTextureAccessFunctions.hpp>
#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>

namespace
{
	void testTextureSizeBufferF()
	{
		testBegin( "testTextureSizeBufferF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeBufferF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eBufferF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeBufferI()
	{
		testBegin( "testTextureSizeBufferI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeBufferI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eBufferI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeBufferU()
	{
		testBegin( "testTextureSizeBufferU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeBufferU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eBufferU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DF()
	{
		testBegin( "testTextureSize1DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DShadowF()
	{
		testBegin( "testTextureSize1DShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DI()
	{
		testBegin( "testTextureSize1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DU()
	{
		testBegin( "testTextureSize1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DArrayF()
	{
		testBegin( "testTextureSize1DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DArrayShadowF()
	{
		testBegin( "testTextureSize1DArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DArrayI()
	{
		testBegin( "testTextureSize1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize1DArrayU()
	{
		testBegin( "testTextureSize1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize1DArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DF()
	{
		testBegin( "testTextureSize2DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DShadowF()
	{
		testBegin( "testTextureSize2DShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DRectF()
	{
		testBegin( "testTextureSize2DRectF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DRectF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DRectF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DRectShadowF()
	{
		testBegin( "testTextureSize2DRectShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DRectShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DRectShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DI()
	{
		testBegin( "testTextureSize2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DRectI()
	{
		testBegin( "testTextureSize2DRectI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DRectI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DRectI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DU()
	{
		testBegin( "testTextureSize2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DRectU()
	{
		testBegin( "testTextureSize2DRectU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DRectU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DRectU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DArrayF()
	{
		testBegin( "testTextureSize2DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DArrayShadowF()
	{
		testBegin( "testTextureSize2DArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DArrayI()
	{
		testBegin( "testTextureSize2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize2DArrayU()
	{
		testBegin( "testTextureSize2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize2DArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize3DF()
	{
		testBegin( "testTextureSize3DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize3DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize3DI()
	{
		testBegin( "testTextureSize3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize3DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSize3DU()
	{
		testBegin( "testTextureSize3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSize3DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeF()
	{
		testBegin( "testTextureSizeCubeF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeShadowF()
	{
		testBegin( "testTextureSizeCubeShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeI()
	{
		testBegin( "testTextureSizeCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeU()
	{
		testBegin( "testTextureSizeCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeArrayF()
	{
		testBegin( "testTextureSizeCubeArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeArrayShadowF()
	{
		testBegin( "testTextureSizeCubeArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeArrayI()
	{
		testBegin( "testTextureSizeCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureSizeCubeArrayU()
	{
		testBegin( "testTextureSizeCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureSizeCubeArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DF()
	{
		testBegin( "testTextureQueryLod1DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DShadowF()
	{
		testBegin( "testTextureQueryLod1DShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DI()
	{
		testBegin( "testTextureQueryLod1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DU()
	{
		testBegin( "testTextureQueryLod1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DArrayF()
	{
		testBegin( "testTextureQueryLod1DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DArrayShadowF()
	{
		testBegin( "testTextureQueryLod1DArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DArrayI()
	{
		testBegin( "testTextureQueryLod1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod1DArrayU()
	{
		testBegin( "testTextureQueryLod1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod1DArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, 0.0_f ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DF()
	{
		testBegin( "testTextureQueryLod2DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DShadowF()
	{
		testBegin( "testTextureQueryLod2DShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DI()
	{
		testBegin( "testTextureQueryLod2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DU()
	{
		testBegin( "testTextureQueryLod2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DArrayF()
	{
		testBegin( "testTextureQueryLod2DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DArrayShadowF()
	{
		testBegin( "testTextureQueryLod2DArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DArrayI()
	{
		testBegin( "testTextureQueryLod2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod2DArrayU()
	{
		testBegin( "testTextureQueryLod2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod2DArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod3DF()
	{
		testBegin( "testTextureQueryLod3DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod3DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod3DI()
	{
		testBegin( "testTextureQueryLod3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod3DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLod3DU()
	{
		testBegin( "testTextureQueryLod3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLod3DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeF()
	{
		testBegin( "testTextureQueryLodCubeF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeShadowF()
	{
		testBegin( "testTextureQueryLodCubeShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeI()
	{
		testBegin( "testTextureQueryLodCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeU()
	{
		testBegin( "testTextureQueryLodCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeArrayF()
	{
		testBegin( "testTextureQueryLodCubeArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeArrayI()
	{
		testBegin( "testTextureQueryLodCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeArrayU()
	{
		testBegin( "testTextureQueryLodCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLodCubeArrayShadowF()
	{
		testBegin( "testTextureQueryLodCubeArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLodCubeArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLod( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DF()
	{
		testBegin( "testTextureQueryLevels1DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DShadowF()
	{
		testBegin( "testTextureQueryLevels1DShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DI()
	{
		testBegin( "testTextureQueryLevels1DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DU()
	{
		testBegin( "testTextureQueryLevels1DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DArrayF()
	{
		testBegin( "testTextureQueryLevels1DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DArrayShadowF()
	{
		testBegin( "testTextureQueryLevels1DArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DArrayI()
	{
		testBegin( "testTextureQueryLevels1DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels1DArrayU()
	{
		testBegin( "testTextureQueryLevels1DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels1DArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DF()
	{
		testBegin( "testTextureQueryLevels2DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DShadowF()
	{
		testBegin( "testTextureQueryLevels2DShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DI()
	{
		testBegin( "testTextureQueryLevels2DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DU()
	{
		testBegin( "testTextureQueryLevels2DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DArrayF()
	{
		testBegin( "testTextureQueryLevels2DArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DArrayShadowF()
	{
		testBegin( "testTextureQueryLevels2DArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DArrayI()
	{
		testBegin( "testTextureQueryLevels2DArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels2DArrayU()
	{
		testBegin( "testTextureQueryLevels2DArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels2DArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels3DF()
	{
		testBegin( "testTextureQueryLevels3DF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels3DF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels3DI()
	{
		testBegin( "testTextureQueryLevels3DI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels3DI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevels3DU()
	{
		testBegin( "testTextureQueryLevels3DU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevels3DU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeF()
	{
		testBegin( "testTextureQueryLevelsCubeF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeShadowF()
	{
		testBegin( "testTextureQueryLevelsCubeShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeI()
	{
		testBegin( "testTextureQueryLevelsCubeI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeU()
	{
		testBegin( "testTextureQueryLevelsCubeU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeArrayF()
	{
		testBegin( "testTextureQueryLevelsCubeArrayF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeArrayF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeArrayI()
	{
		testBegin( "testTextureQueryLevelsCubeArrayI" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeArrayI = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayI >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeArrayU()
	{
		testBegin( "testTextureQueryLevelsCubeArrayU" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeArrayU = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayU >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testTextureQueryLevelsCubeArrayShadowF()
	{
		testBegin( "testTextureQueryLevelsCubeArrayShadowF" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresTextureQueryLevelsCubeArrayShadowF = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::eCubeArrayShadowF >( "s", 0u, 0u );
			auto i = writer.declLocale( "i", textureQueryLevels( s ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}

	void testProjectTexCoords2()
	{
		testBegin( "testProjectTexCoords2" );
		using namespace sdw;
		{
			auto cont = stmt::makeContainer();
			hlsl::IntrinsicsConfig config;
			config.requiresProjectTexCoords2 = true;
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DF >( "s", 0u, 0u );
			auto r = writer.declLocale( "r", textureProj( s, vec2( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
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
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DF >( "s", 0u, 0u );
			auto r = writer.declLocale( "r", textureProj( s, vec3( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
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
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e1DF >( "s", 0u, 0u );
			auto r = writer.declLocale( "r", textureProj( s, vec4( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
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
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e2DF >( "s", 0u, 0u );
			auto r = writer.declLocale( "r", textureProj( s, vec4( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
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
			writeHlslTextureAccessFunctions( cont.get(), config );
			std::cout << sdw::writeDebug( cont.get() ) << std::endl;
			std::cout << sdw::hlsl::StmtVisitor::submit( cont.get(), sdw::ShaderType::eVertex ) << std::endl;
		}
		{
			ShaderWriter writer{ false };
			auto s = writer.declSampler< SamplerType::e3DF >( "s", 0u, 0u );
			auto r = writer.declLocale( "r", textureProj( s, vec4( 0.0_f ) ) );
			std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
			std::cout << sdw::writeGlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
			std::cout << sdw::writeHlsl( writer.getShader(), ShaderType::eVertex ) << std::endl;
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterHlslTextureAccesses" );
	testTextureSizeBufferF();
	testTextureSizeBufferI();
	testTextureSizeBufferU();
	testTextureSize1DF();
	testTextureSize1DShadowF();
	testTextureSize1DI();
	testTextureSize1DU();
	testTextureSize1DArrayF();
	testTextureSize1DArrayShadowF();
	testTextureSize1DArrayI();
	testTextureSize1DArrayU();
	testTextureSize2DF();
	testTextureSize2DShadowF();
	testTextureSize2DRectF();
	testTextureSize2DRectShadowF();
	testTextureSize2DI();
	testTextureSize2DRectI();
	testTextureSize2DU();
	testTextureSize2DRectU();
	testTextureSize2DArrayF();
	testTextureSize2DArrayShadowF();
	testTextureSize2DArrayI();
	testTextureSize2DArrayU();
	testTextureSize3DF();
	testTextureSize3DI();
	testTextureSize3DU();
	testTextureSizeCubeF();
	testTextureSizeCubeShadowF();
	testTextureSizeCubeI();
	testTextureSizeCubeU();
	testTextureSizeCubeArrayF();
	testTextureSizeCubeArrayShadowF();
	testTextureSizeCubeArrayI();
	testTextureSizeCubeArrayU();
	testTextureQueryLod1DF();
	testTextureQueryLod1DShadowF();
	testTextureQueryLod1DI();
	testTextureQueryLod1DU();
	testTextureQueryLod1DArrayF();
	testTextureQueryLod1DArrayShadowF();
	testTextureQueryLod1DArrayI();
	testTextureQueryLod1DArrayU();
	testTextureQueryLod2DF();
	testTextureQueryLod2DShadowF();
	testTextureQueryLod2DI();
	testTextureQueryLod2DU();
	testTextureQueryLod2DArrayF();
	testTextureQueryLod2DArrayShadowF();
	testTextureQueryLod2DArrayI();
	testTextureQueryLod2DArrayU();
	testTextureQueryLod3DF();
	testTextureQueryLod3DI();
	testTextureQueryLod3DU();
	testTextureQueryLodCubeF();
	testTextureQueryLodCubeShadowF();
	testTextureQueryLodCubeI();
	testTextureQueryLodCubeU();
	testTextureQueryLodCubeArrayF();
	testTextureQueryLodCubeArrayShadowF();
	testTextureQueryLodCubeArrayI();
	testTextureQueryLodCubeArrayU();
	testTextureQueryLevels1DF();
	testTextureQueryLevels1DShadowF();
	testTextureQueryLevels1DI();
	testTextureQueryLevels1DU();
	testTextureQueryLevels1DArrayF();
	testTextureQueryLevels1DArrayShadowF();
	testTextureQueryLevels1DArrayI();
	testTextureQueryLevels1DArrayU();
	testTextureQueryLevels2DF();
	testTextureQueryLevels2DShadowF();
	testTextureQueryLevels2DI();
	testTextureQueryLevels2DU();
	testTextureQueryLevels2DArrayF();
	testTextureQueryLevels2DArrayShadowF();
	testTextureQueryLevels2DArrayI();
	testTextureQueryLevels2DArrayU();
	testTextureQueryLevels3DF();
	testTextureQueryLevels3DI();
	testTextureQueryLevels3DU();
	testTextureQueryLevelsCubeF();
	testTextureQueryLevelsCubeShadowF();
	testTextureQueryLevelsCubeI();
	testTextureQueryLevelsCubeU();
	testTextureQueryLevelsCubeArrayF();
	testTextureQueryLevelsCubeArrayShadowF();
	testTextureQueryLevelsCubeArrayI();
	testTextureQueryLevelsCubeArrayU();
	testProjectTexCoords2();
	testProjectTexCoords3();
	testProjectTexCoords4To1();
	testProjectTexCoords4To2();
	testProjectTexCoords4();
	testSuiteEnd();
}
