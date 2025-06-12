#include "Common.hpp"

#include <ShaderAST/ShaderLog.hpp>

#if defined( _WIN32 )
#	include <Windows.h>
#elif defined( __linux__ )
#	include <unistd.h>
#	include <dirent.h>
#	include <pwd.h>
#elif defined( __APPLE__ )
#	include <mach-o/dyld.h>
#	include <cpuid.h>
#	include <sys/sysctl.h>
#endif

#include <algorithm>
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

	void printCDBConsole( std::string const & toLog
		, bool newLine )
	{
		if ( ::IsDebuggerPresent() )
		{
			int length = MultiByteToWideChar( CP_UTF8, 0u, toLog.c_str(), -1, nullptr, 0u );

			if ( length > 0 )
			{
				std::vector< wchar_t > buffer( size_t( length + 1 ), wchar_t{} );
				MultiByteToWideChar( CP_UTF8, 0u, toLog.c_str(), -1, buffer.data(), length );
				std::wstring converted{ buffer.begin(), buffer.end() };
				::OutputDebugStringW( converted.c_str() );
			}

			if ( newLine )
			{
				::OutputDebugStringW( L"\n" );
			}
		}
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

	void printCDBConsole( std::string const &
		, bool )
	{
	}

	std::string getExecutableDirectory()
	{
		std::string result;
		char path[FILENAME_MAX];
		char buffer[32];
		sprintf( buffer, "/proc/%d/exe", getpid() );
		auto bytes = std::min< std::size_t >( readlink( buffer
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

	void printCDBConsole( std::string const &
		, bool )
	{
	}

	std::string getExecutableDirectory()
	{
		std::string result;
		char path[FILENAME_MAX]{};
		uint32_t size = FILENAME_MAX;

		if ( _NSGetExecutablePath( &path[0], &size ) == 0 )
		{
			char realPath[FILENAME_MAX]{};
			result = realpath( path, realPath );
		}

		result = getPath( result );
		return result;
	}

#endif

	//*********************************************************************************************

	TestTrace::TestTrace( TestCounts & testCounts, std::string_view file, int line, std::string_view message )
		: file{ file }
		, line{ line }
		, message{ message }
		, m_testCounts{ testCounts }
		, m_trace{ file.data(), line, message }
	{
		m_testCounts.doPushTrace( this );
	}

	TestTrace::~TestTrace()
	{
		m_testCounts.doPopTrace();
	}

	//*********************************************************************************************

	TestCounts::TestCounts()
		: allocatorBlock{ allocator.getBlock() }
	{
	}

	TestCounts::~TestCounts()noexcept
	{
	}

	void TestCounts::printBlock( std::string const & text )
	{
		GTEST_MESSAGE_( ( "\n" + text ).c_str(), ::testing::TestPartResult::kSuccess );
	}

	void TestCounts::printError( std::string const & text )
	{
		GTEST_MESSAGE_( ( "\n" + text ).c_str(), ::testing::TestPartResult::kNonFatalFailure );
	}

	//*********************************************************************************************
}
