#include "WriterCommonHlsl.hpp"

#include "CompileHLSL.hpp"

namespace test::sdw_test
{
	namespace hlsl_test
	{
		static std::string printHlslModel( uint32_t version )
		{
			return "HLSL Shader Model " + std::to_string( version / 10u ) + "_" + std::to_string( version % 10u );
		}

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

			if ( !testCounts.isHlslRequested( infoIndex, compilers.hlsl.requestedModel ) )
				return;

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

					bool isCompiled = compileHlsl( hlsl
						, stage
						, errors
						, testCounts
						, infoIndex );
					astCheck( isCompiled )
					displayShader( printHlslModel( testCounts.getHlslVersion( infoIndex ) ), hlsl, testCounts, compilers.forceDisplay || !isCompiled, true );
					if ( !isCompiled )
						testCounts.printError( errors );
				};
			astOn( printHlslModel( testCounts.getHlslVersion( infoIndex ) ) );
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
		if ( compilers.hlsl.enable )
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
