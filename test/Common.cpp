#include "Common.hpp"

#if defined( _WIN32 )
#	include <Windows.h>
#elif defined( __linux__ )
#	include <unistd.h>
#	include <dirent.h>
#	include <pwd.h>
#elif defined( __APPLE__ )
#include <mach-o/dyld.h>
#endif

#include <thread>

namespace test
{
	//*********************************************************************************************

#if defined( _WIN32 )
	static char constexpr PathSeparator = '\\';
#else
	static char constexpr PathSeparator = '/';
#endif

	namespace
	{
		std::string getPath( std::string const & path )
		{
			return path.substr( 0, path.find_last_of( PathSeparator ) );
		}
	}

#if defined( _WIN32 )

	uint32_t getCoreCount()
	{
		SYSTEM_INFO sysinfo = { 0 };
		::GetSystemInfo( &sysinfo );
		return uint32_t( sysinfo.dwNumberOfProcessors );
	}

	std::string getExecutableDirectory()
	{
		std::string result;
		char path[FILENAME_MAX];
		DWORD res = ::GetModuleFileNameA( nullptr
			, path
			, sizeof( path ) );

		if ( res != 0 )
		{
			result = path;
		}

		result = getPath( result ) + PathSeparator;
		return result;
	}

#elif defined( __linux__ )

	uint32_t getCoreCount()
	{
		char res[128];
		FILE * fp = popen( "/bin/cat /proc/cpuinfo | grep -c '^processor'", "r" );
		auto read = fread( res, 1, sizeof( res ) - 1, fp );
		assert( read && read < sizeof( res ) );
		pclose( fp );
		return uint32_t( res[0] );
	}

	std::string getExecutableDirectory()
	{
		std::string result;
		char path[FILENAME_MAX];
		char buffer[32];
		sprintf( buffer, "/proc/%d/exe", getpid() );
		int bytes = std::min< std::size_t >( readlink( buffer
			, path
			, sizeof( path ) )
			, sizeof( path ) - 1 );

		if ( bytes > 0 )
		{
			path[bytes] = '\0';
			result = path;
		}

		result = getPath( result ) + PathSeparator;
		return result;
	}

#elif defined( __APPLE__ )
	
	uint32_t getCoreCount()
	{
		int mib[4];
		int numCPU;
		size_t len = sizeof( numCPU ); 

		/* set the mib for hw.ncpu */
		mib[0] = CTL_HW;
		mib[1] = HW_AVAILCPU;

		/* get the number of CPUs from the system */
		sysctl( mib, 2, &numCPU, &len, NULL, 0 );

		if ( numCPU < 1 )
		{
			mib[1] = HW_NCPU;
			sysctl( mib, 2, &numCPU, &len, NULL, 0 );

			if ( numCPU < 1 )
			{
				numCPU = 1;
			}
		}

		return uint32_t( numCPU );
	}

	std::string getExecutableDirectory()
	{
		std::string result;
		char path[FILENAME_MAX]{};
		char realPath[FILENAME_MAX]{};
		uint32_t size = FILENAME_MAX;

		if ( _NSGetExecutablePath( &path[0], &size ) == 0 )
		{
			result = realpath( path, realPath );
		}

		result = getPath( result );
		return result;
	}

#endif

	//*********************************************************************************************

	TestSuite::TestSuite( std::string const & name )
		: suiteName{ name }
	{
		tclog = std::make_unique< test::LogStreambuf< test::DebugLogStreambufTraits > >( suiteName, std::clog );
		tcout = std::make_unique< test::LogStreambuf< test::InfoLogStreambufTraits > >( suiteName, std::cout );
		tcerr = std::make_unique< test::LogStreambuf< test::ErrorLogStreambufTraits > >( suiteName, std::cerr );
	}

	TestSuite::~TestSuite()
	{
		if ( errorCount )
		{
			std::cout << "********************************************************************************" << std::endl;
			std::cout << "Test suite ended with some failures." << std::endl;
			std::cout << "Total checks count: " << totalCount << std::endl;
			std::cout << "Failed checks count: " << errorCount << std::endl;
		}
		else
		{
			std::cout << "********************************************************************************" << std::endl;
			std::cout << "Test suite ended cleanly." << std::endl;
			std::cout << "Total checks count: " << totalCount << std::endl;
		}

		std::clog.flush();
		std::cout.flush();
		std::cerr.flush();
		tcerr.reset();
		tcout.reset();
		tclog.reset();
	}

	void TestSuite::registerTests( std::string name
		, TestSuite::TestSuiteLaunch launch
		, TestCountsPtr testCounts )
	{
		tests.emplace_back( std::make_unique< TestSuiteRun >( std::move( launch )
			, std::move( name )
			, std::move( testCounts ) ) );
	}

	int TestSuite::run()
	{
		std::vector< TestSuiteRunPtr > running;
		std::swap( tests, running );

		while ( !running.empty() )
		{
			std::vector< std::pair< TestSuiteRunPtr, std::thread > > threads;

			while ( !running.empty() && threads.size() < getCoreCount() )
			{
				threads.emplace_back( std::move( std::move( running.back() ) ), std::thread{} );
				running.pop_back();
				auto & current = threads.back();
				auto * run = current.first.get();

				current.second = std::thread{ [this, run]()
					{
						auto result = run->launch( *this, *run->testCount );

						if ( run->name != this->suiteName )
						{
							if ( errorCount )
							{
								run->testCount->streams.cout << "********************************************************************************" << std::endl;
								run->testCount->streams.cout << run->name << " ended with some failures." << std::endl;
								run->testCount->streams.cout << "Total Checks count: " << result.totalCount << std::endl;
								run->testCount->streams.cout << "Failed checks count: " << result.errorCount << std::endl;
							}
							else
							{
								run->testCount->streams.cout << "********************************************************************************" << std::endl;
								run->testCount->streams.cout << run->name << " ended cleanly." << std::endl;
								run->testCount->streams.cout << "Total Checks count: " << result.totalCount << std::endl;
							}

						}
					} };
			}

			for ( auto & thread : threads )
			{
				thread.second.join();
				std::cout << thread.first->testCount->streams.cout.str() << std::endl;
			}
		}

		return errorCount
			? EXIT_FAILURE
			: EXIT_SUCCESS;
	}

	//*********************************************************************************************

	TestCounts::TestCounts( TestSuite & parent )
		: suite{ parent }
		, sout{ "" }
		, streams{ sout }
	{
	}

	TestCounts::~TestCounts()
	{
	}

	void TestCounts::initialise()
	{
	}

	TestResults TestCounts::cleanup()
	{
		return result;
	}

	void TestCounts::incTest()
	{
		++suite.totalCount;
		++result.totalCount;
	}

	void TestCounts::incErr()
	{
		++suite.errorCount;
		++curTestErrors;
		++result.errorCount;
	}

	//*********************************************************************************************

	void beginTest( TestCounts & testCounts
		, std::string const & name )
	{
		testCounts.testName = name;
		testCounts.curTestErrors = 0u;
		testCounts.streams.cout << "TEST: " << testCounts.testName << std::endl;
	}

	void endTest( TestCounts & testCounts )
	{
		if ( testCounts.curTestErrors )
		{
			testCounts.streams.cout << "********************************************************************************" << std::endl;
		}
	}

	void reportFailure( char const * const error
		, char const * const function
		, int line
		, TestCounts & testCounts )
	{
		if ( !testCounts.curTestErrors )
		{
			testCounts.streams.cout << "********************************************************************************" << std::endl;
		}

		testCounts.incErr();
		testCounts.streams.cout << function << ":" << line << " - " << error << std::endl;
	}

	//*********************************************************************************************
}
