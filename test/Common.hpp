#pragma once

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/ImageConfiguration.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 4068 )
#pragma clang diagnostic ignored "-Wextra-semi-stmt"
#include <atomic>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#pragma warning( pop )

namespace test
{
	void printCDBConsole( std::string const & toLog
		, bool newLine );
	uint32_t getCoreCount();
	std::string getExecutableDirectory();

	struct TestCounts;
	struct TestSuite;

	struct TestStringStreams
	{
		TestStringStreams( std::string & sout );

		std::stringstream cout;
		std::unique_ptr< std::streambuf > tcout;
	};

	struct TestResults
	{
		uint32_t totalCount{ 0u };
		uint32_t errorCount{ 0u };
	};

	struct TestCounts
	{
		TestCounts( TestSuite & suite );
		virtual ~TestCounts()noexcept;

		void initialise();
		TestResults cleanup();

		uint32_t getTotalCount()
		{
			return result.totalCount;
		}

		void incTest();
		void incErr();

		std::string testName;
		uint32_t curTestErrors{ 0u };
		std::string sout;
		TestStringStreams streams;
		uint32_t nextVarId{};

	private:
		virtual void doInitialise(){}
		virtual void doCleanup(){}

	private:
		TestSuite & suite;
		TestResults result{};
		std::atomic_bool m_initialised{ false };
		std::atomic_bool m_cleaned{ true };
	};

	using TestCountsPtr = std::unique_ptr< TestCounts >;

	struct TestSuite
	{
		using TestCountsType = test::TestCounts;
		using TestSuiteLaunch = TestResults( * )( test::TestSuite &, test::TestCounts & );

		TestSuite( std::string const & name );
		~TestSuite()noexcept;

		void registerTests( std::string name
			, TestSuiteLaunch launch
			, TestCountsPtr testCounts );
		int run();

		template< typename TestSuiteT >
		void registerTests( std::string name
			, TestSuiteLaunch launch )
		{
			return registerTests( std::move( name )
				, std::move( launch )
				, std::make_unique< typename TestSuiteT::TestCountsType >( *this ) );
		}

		template< typename TestSuiteT
			, typename TestCountsT >
		void registerTests( std::string name
			, TestResults( *launch )( TestSuiteT &, TestCountsT & ) )
		{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
			return registerTests( std::move( name )
				, reinterpret_cast< TestSuiteLaunch >( launch )
				, std::make_unique< typename TestSuiteT::TestCountsType >( *this ) );
#pragma GCC diagnostic pop
		}

		std::atomic_uint32_t totalCount{ 0u };
		std::atomic_uint32_t errorCount{ 0u };

	private:
		struct TestSuiteRun
		{
			TestSuiteRun( TestSuiteLaunch plaunch
				, std::string pname
				, TestCountsPtr ptestCount )
				: launch{ std::move( plaunch ) }
				, name{ std::move( pname ) }
				, testCount{ std::move( ptestCount ) }
			{
			}

			TestSuiteLaunch launch;
			std::string name;
			TestCountsPtr testCount;
		};
		using TestSuiteRunPtr = std::unique_ptr< TestSuiteRun >;

		std::string suiteName;
		std::vector< TestSuiteRunPtr > tests;
		std::unique_ptr< std::streambuf > tcout;
	};

	void beginTest( TestCounts & testCounts
		, std::string const & name );
	void endTest( TestCounts & testCounts );
	void reportFailure( char const * const error
		, char const * const function
		, int line
		, TestCounts & testCounts );

	inline void reportFailure( std::string const & error
		, char const * const function
		, int line
		, TestCounts & testCounts )
	{
		reportFailure( error.c_str(), function, line, testCounts );
	}

#	define testSuiteMain( testName )\
	static test::TestResults launch##testName( test::TestSuite & suite, test::TestCounts & testCounts )

#if defined( SDW_COMPILE_TESTS )
#	define testSuiteLaunchEx( testName, suiteType )\
	int main( int argv, char ** argc )\
	{\
		suiteType suite{ #testName };\
		suite.registerTests< suiteType >( #testName, launch##testName );\
		return suite.run();\
	}
#else
#	define testSuiteLaunchEx( testName, suiteType )
#endif

#define testSuiteLaunch( name )\
	testSuiteLaunchEx( name, test::TestSuite )

#define testStringify( x )\
	#x

#define testConcat2( x, y )\
	testStringify( x ) testStringify( y )

#define testConcat3( x, y, z )\
	testConcat2( x, y ) testStringify( z )

#define testConcat4( x, y, z, w )\
	testConcat3( x, y, z ) testStringify( w )

#define testSuiteBeginEx( testCounts )\
	testCounts.initialise();\
	try\
	{\

#define testSuiteEnd()\
	}\
	catch ( std::exception & exc )\
	{\
		test::reportFailure( std::string{ "Test failed, Unhandled exception: " } + exc.what(), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( "Test failed, Unhandled exception: Unknown", __FUNCTION__, __LINE__, testCounts );\
	}\
	return testCounts.cleanup();

#define testSuiteBegin()\
	testSuiteBeginEx( testCounts )

#define testBegin( name )\
	test::beginTest( testCounts, name );\
	try\
	{\
		auto testName = testCounts.testName

#define testEnd()\
	}\
	catch ( std::exception & exc )\
	{\
		testCounts.streams.cout << testCounts.testName << " Failed: " << exc.what() << std::endl;\
	}\
	catch ( ... )\
	{\
		testCounts.streams.cout << testCounts.testName << " Failed: Unknown unhandled exception" << std::endl;\
	}\
	test::endTest( testCounts );

#define success()\
	testCounts.incTest()

#define failure( x )\
	success();\
	test::reportFailure( x " failed.", __FUNCTION__, __LINE__, testCounts )\

#define require( x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			throw std::runtime_error{ std::string{ #x } + " failed" };\
		}\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define beginRequire( x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			throw std::runtime_error{ std::string{ #x } + " failed" };\
		}

#define endRequire\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define check( x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
		}\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcat2( x, " failed: Unhandled exception." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define checkEqual( x, y )\
	try\
	{\
		testCounts.incTest();\
		if ( ( x ) != ( y ) )\
		{\
			throw std::runtime_error{ std::string{ #x } + " == " + std::string{ #y } + " failed" };\
		}\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcat4( x, " == ", y, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define checkNotEqual( x, y )\
	try\
	{\
		testCounts.incTest();\
		if ( ( x ) == ( y ) )\
		{\
			throw std::runtime_error{ std::string{ #x } + " != " + std::string{ #y } + " failed" };\
		}\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcat4( x, " != ", y, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define checkThrow( x )\
	try\
	{\
		testCounts.incTest();\
		( x ); \
		test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
	}

#define checkNoThrow( x )\
	try\
	{\
		testCounts.incTest();\
		( x ); \
	}\
	catch ( std::exception & exc )\
	{\
		test::reportFailure( exc.what(), __FUNCTION__, __LINE__, testCounts );\
		test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}
}
