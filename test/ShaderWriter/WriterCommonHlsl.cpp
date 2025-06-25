#include "WriterCommonHlsl.hpp"

#include "CompileHLSL.hpp"

namespace test::sdw_test
{
	namespace hlsl_test
	{
		static std::string generateHlsl( ::ast::Shader const & shader
			, ::ast::PreprocessResult & preprocessResult
			, ::ast::ShaderStage stage
			, ::ast::SpecialisationInfo const & specialisation
			, uint32_t infoIndex
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateHlsl" );
			return hlsl::compilePreprocessedHlsl( shader
				, preprocessResult
				, stage
				, specialisation
				, hlsl::HlslConfig{ testCounts.getHlslVersion( infoIndex ), stage, false } );
		}

		static void testWriteOnIndex( ::ast::Shader const & shader
			, ::ast::PreprocessResult & preprocessResult
			, ::ast::ShaderStage stage
			, ::ast::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerHlsl

			auto validate = [&]()
				{
					std::string errors;
					std::string hlsl;

					try
					{
						hlsl = generateHlsl( shader, preprocessResult, stage, specialisation, infoIndex, testCounts );
					}
					catch ( hlsl::UnsupportedExtensionException & )
					{
						return;
					}
					catch ( std::exception & exc )
					{
						testCounts.printError( exc.what() );
						return;
					}

					displayShader( "HLSL", hlsl, testCounts, compilers.forceDisplay, true );
					bool isCompiled = compileHlsl( hlsl
						, stage
						, errors
						, testCounts
						, infoIndex );
					astCheck( isCompiled )
					if ( !isCompiled )
						testCounts.printError( "\n" + printShader( "HLSL", hlsl, true ) + errors );

					if ( isCompiled && compilers.forceDisplay )
					{
						testCounts.printBlock( printShader( "HLSL", hlsl, true ) );
					}
				};
			auto shaderModel = testCounts.getHlslVersion( infoIndex );
			auto major = shaderModel / 10u;
			auto minor = shaderModel % 10u;
			auto model = std::to_string( major ) + "_" + std::to_string( minor );
			astOn( "HLSL Shader Model " + model );
			astCheckNoThrow( validate() )
#endif
		}
	}

	void testWriteHlsl( ::ast::Shader const & shader
		, ::ast::PreprocessResult & preprocessResult
		, ::ast::ShaderStage stage
		, ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
		if ( compilers.hlsl )
		{
			auto count = testCounts.getHlslInfosSize();
			for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
			{
				hlsl_test::testWriteOnIndex( shader
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
