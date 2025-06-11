#include "WriterCommonGlsl.hpp"

#include "CompileGLSL.hpp"
#include "GlslToSpv.hpp"

namespace test::sdw_test
{
	namespace glsl_test
	{
		static std::string generateGlsl( ::ast::Shader const & shader
			, ::ast::EntryPointConfig const & entryPoint
			, ::ast::SpecialisationInfo const & specialisation
			, glsl::GlslConfig config
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateGlsl" );
			auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
			return glsl::compileGlsl( *testCounts.allocatorBlock
				, shader
				, statements.get()
				, entryPoint.stage
				, specialisation
				, config );
		}

		static void testWriteOnIndex( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::ast::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerGlsl

			auto validate = [&]()
				{
					for ( auto & entryPoint : entryPoints )
					{
						astOn( printEntryPoint( entryPoint ) );
						std::string errors;
						auto config = getGlslConfig( testCounts.getGlslVersion( infoIndex ) );

						if ( isRayTraceStage( entryPoint.stage )
							|| entryPoint.stage == ast::ShaderStage::eMesh
							|| entryPoint.stage == ast::ShaderStage::eTask )
						{
							config.vulkanGlsl = true;
						}

						std::string glsl;

						try
						{
							glsl = generateGlsl( shader, entryPoint, specialisation, config, testCounts );
						}
						catch ( std::exception & exc )
						{
							testCounts.printBlock( exc.what() );
							return;
						}

						bool isCompiled{ false };

						if ( isRayTraceStage( entryPoint.stage )
							|| entryPoint.stage == ast::ShaderStage::eMesh
							|| entryPoint.stage == ast::ShaderStage::eTask
							|| config.requiredExtensions.end() != config.requiredExtensions.find( glsl::EXT_separate_samplers ) )
						{
							try
							{
								compileGlslToSpv( entryPoint.stage, glsl, 150 );
								isCompiled = true;
							}
							catch ( std::exception & exc )
							{
								errors += exc.what();
							}
						}
						else
						{
							isCompiled = compileGlsl( glsl
								, entryPoint.stage
								, errors
								, testCounts );
						}

						astCheck( isCompiled )
							if ( !isCompiled )
								testCounts.printError( printShader( "GLSL", glsl, true ) + errors );

						if ( isCompiled && compilers.forceDisplay )
						{
							testCounts.printBlock( printShader( "GLSL", glsl, true ) );
						}
					}
				};
			astOn( "GLSL version " + std::to_string( testCounts.getGlslVersion( infoIndex ) ) );
			astCheckNoThrow( validate() )

#endif
		}
	}

	void testWriteGlsl( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
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
					, entryPoints
					, specialisation
					, compilers
					, testCounts
					, infoIndex );
			}
		}
	}
}
