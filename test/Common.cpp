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

namespace test
{
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
	void TestCounts::initialise( std::string const & name )
	{
		tclog = std::make_unique< test::LogStreambuf< test::DebugLogStreambufTraits > >( name, std::cout );
		tcout = std::make_unique< test::LogStreambuf< test::InfoLogStreambufTraits > >( name, std::cout );
		tcerr = std::make_unique< test::LogStreambuf< test::ErrorLogStreambufTraits > >( name, std::cerr );
	}

	void TestCounts::cleanup()
	{
		tclog.reset();
		tcout.reset();
		tcerr.reset();
	}

	void reportFailure( char const * const error
		, char const * const function
		, int line
		, TestCounts & testCounts )
	{
		std::cout << function << ":" << line << " - " << error << std::endl;
		++testCounts.errorCount;
	}

	int reportTestSuite( TestCounts const & testCounts )
	{
		int result;

		if ( testCounts.errorCount )
		{
			std::cout << "********************************************************************************" << std::endl;
			std::cout << "Test suite ended with some failures." << std::endl;
			std::cout << "Total checks count: " << testCounts.totalCount << std::endl;
			std::cout << "Failed checks count: " << testCounts.errorCount << std::endl;
			result = EXIT_FAILURE;
		}
		else
		{
			std::cout << "********************************************************************************" << std::endl;
			std::cout << "Test suite ended cleanly." << std::endl;
			std::cout << "Total checks count: " << testCounts.totalCount << std::endl;
			result = EXIT_SUCCESS;
		}

		return result;
	}
}
