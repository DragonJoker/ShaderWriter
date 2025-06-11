#include "WriterCommonDebug.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderWriter/WriterDebug.hpp>

namespace test::sdw_test
{
	namespace debug_test
	{
		static std::string generateDebug( ::ast::Shader const & shader
			, ::ast::EntryPointConfig const & entryPoint
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateDebug" );
			auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
			return ::sdw::writeDebug( *statements );
		}

		static std::string generateDebugPreprocessed( ::ast::Shader const & shader
			, ::ast::EntryPointConfig const & entryPoint
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateDebug" );
			auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
			return ::sdw::writeDebugPreprocessed( shader, *statements );
		}
	}

	void testWriteDebug( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, Compilers const & compilers
		, TestCounts & testCounts )
	{
		if ( compilers.debug )
		{
			if ( astOn( "Debug statements, full" ) )
			{
				for ( auto & entryPoint : entryPoints )
				{
					astOn( printEntryPoint( entryPoint ) );

					try
					{
						auto debug = debug_test::generateDebug( shader, entryPoint, testCounts );
						displayShader( "Statements", debug, testCounts, compilers.forceDisplay, false );
						SUCCEED();
					}
					catch ( std::exception & exc )
					{
						testCounts.printError( exc.what() );
					}
				}
			}
			if ( astOn( "Debug statements, preprocessed" ) )
			{
				for ( auto & entryPoint : entryPoints )
				{
					astOn( printEntryPoint( entryPoint ) );

					try
					{
						auto debug = debug_test::generateDebugPreprocessed( shader, entryPoint, testCounts );
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
}
