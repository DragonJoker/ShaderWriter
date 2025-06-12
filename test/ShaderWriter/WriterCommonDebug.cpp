#include "WriterCommonDebug.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderWriter/WriterDebug.hpp>

namespace test::sdw_test
{
	namespace debug_test
	{
		static std::string generateDebug( ::ast::Shader const & shader
			, ::ast::PreprocessResult & preprocessResult
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateDebug" );
			return ::sdw::writePreprocessedDebug( shader, preprocessResult );
		}
	}

	void testWriteDebug( ::ast::Shader const & shader
		, ::ast::PreprocessResult & preprocessResult
		, [[maybe_unused]] ::ast::ShaderStage stage
		, [[maybe_unused]] ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, TestCounts & testCounts )
	{
		if ( compilers.debug )
		{
			if ( astOn( "Debug statements" ) )
			{
				try
				{
					auto debug = debug_test::generateDebug( shader, preprocessResult, testCounts );
					displayShader( "Statements", debug, testCounts, compilers.forceDisplay, false );
					SUCCEED();
				}
				catch ( std::exception & exc )
				{
					testCounts.printError( exc.what() );
				}
			}
		}
	}
}
