#include "WriterCommonGlsl.hpp"

#include "CompileGLSL.hpp"
#include "GlslToSpv.hpp"

namespace test::sdw_test
{
	namespace glsl_test
	{
		static std::string generateGlsl( ::ast::Shader const & shader
			, ::ast::PreprocessResult & preprocessResult
			, ::ast::ShaderStage stage
			, ::ast::SpecialisationInfo const & specialisation
			, glsl::GlslConfig & config
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateGlsl" );
			return glsl::compilePreprocessedGlsl( *testCounts.allocatorBlock
				, shader
				, preprocessResult
				, stage
				, specialisation
				, config );
		}

		static void testWriteOnIndex( ::ast::Shader const & shader
			, ::ast::PreprocessResult & preprocessResult
			, ::ast::ShaderStage stage
			, ::ast::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerGlsl

			auto validate = [&]()
				{
					std::string errors;
					auto config = getGlslConfig( testCounts.getGlslVersion( infoIndex ), testCounts );

					if ( isRayTraceStage( stage )
						|| stage == ast::ShaderStage::eMesh
						|| stage == ast::ShaderStage::eTask )
					{
						config.vulkanGlsl = true;
					}

					std::string glsl;

					try
					{
						glsl = generateGlsl( shader, preprocessResult, stage, specialisation, config, testCounts );
					}
					catch ( glsl::UnsupportedExtensionException & )
					{
						return;
					}
					catch ( std::exception & exc )
					{
						testCounts.printBlock( exc.what() );
						return;
					}

					bool isCompiled{ false };

					if ( config.vulkanGlsl )
					{
						if ( config.requiredExtensions.find( glsl::NV_gpu_shader5 ) != config.requiredExtensions.end() )
						{
							isCompiled = true;
						}
						else
						{
							try
							{
								compileGlslToSpv( stage, glsl, 0x00010500u );
								isCompiled = true;
							}
							catch ( std::exception & exc )
							{
								std::string err = exc.what();
								isCompiled = ( err.find( "gl_ClipDistance" ) != std::string::npos )
									|| ( err.find( "image formats must match" ) != std::string::npos );
								if ( !isCompiled )
									errors += exc.what();
							}
						}
					}
					else
					{
						isCompiled = compileGlsl( glsl
							, stage
							, errors
							, testCounts );
					}

					if ( !isCompiled )
						testCounts.printError( printShader( "GLSL", glsl, true ) + errors );

					if ( isCompiled && compilers.forceDisplay )
					{
						testCounts.printBlock( printShader( "GLSL", glsl, true ) );
					}
				};
			astOn( "GLSL version " + std::to_string( testCounts.getGlslVersion( infoIndex ) ) );
			astCheckNoThrow( validate() )

#endif
		}
	}

	void testWriteGlsl( ::ast::Shader const & shader
		, ::ast::PreprocessResult & preprocessResult
		, ::ast::ShaderStage stage
		, ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
		if ( compilers.glsl )
		{
			auto count = testCounts.getGlslInfosSize();
			for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
			{
				glsl_test::testWriteOnIndex( shader
					, preprocessResult
					, stage
					, specialisation
					, compilers
					, testCounts
					, infoIndex );
			}
		}
	}
}
