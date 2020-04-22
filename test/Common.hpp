#pragma once

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/ImageConfiguration.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#include <iostream>
#include <stdexcept>
#include <fstream>

namespace test
{
	std::string getExecutableDirectory();

	template< typename LogStreambufTraits >
	class LogStreambuf
		: public std::streambuf
	{
	public:
		using string_type = std::string;
		using ostream_type = std::ostream;
		using streambuf_type = std::streambuf;
		using int_type = std::streambuf::int_type;
		using traits_type = std::streambuf::traits_type;

		explicit inline LogStreambuf( std::string const & name
			, std::ostream & stream )
			: m_stream{ stream }
			, m_fstream{ getExecutableDirectory() + name + ".log" }
		{
			m_old = m_stream.rdbuf( this );
		}

		inline ~LogStreambuf()
		{
			m_stream.rdbuf( m_old );
		}

		inline int_type overflow( int_type c = traits_type::eof() )override
		{
			if ( traits_type::eq_int_type( c, traits_type::eof() ) )
			{
				do_sync();
			}
			else if ( c == '\n' )
			{
				do_sync();
			}
			else if ( c == '\r' )
			{
				m_buffer += '\r';
				do_sync_no_nl();
			}
			else
			{
				m_buffer += traits_type::to_char_type( c );
			}

			return c;
		}

		inline int do_sync()
		{
			LogStreambufTraits::log( m_fstream, m_buffer );
			m_buffer.clear();
			return 0;
		}

		inline int do_sync_no_nl()
		{
			LogStreambufTraits::logNoNL( m_fstream, m_buffer );
			m_buffer.clear();
			return 0;
		}

	private:
		string_type m_buffer;
		ostream_type & m_stream;
		streambuf_type * m_old;
		std::ofstream m_fstream;
	};

	struct DebugLogStreambufTraits
	{
		static inline void log( std::ostream & stream
			, std::string const & text )
		{
			stream << "DEBUG: " << text << std::endl;
			printf( "%s\n", text.c_str() );
		}

		static inline void logNoNL( std::ostream & stream
			, std::string const & text )
		{
			stream << "DEBUG: " << text;
			printf( "%s", text.c_str() );
		}
	};

	struct InfoLogStreambufTraits
	{
		static inline void log( std::ostream & stream
			, std::string const & text )
		{
			stream << text << std::endl;
			printf( "%s\n", text.c_str() );
		}

		static inline void logNoNL( std::ostream & stream
			, std::string const & text )
		{
			stream << text;
			printf( "%s", text.c_str() );
		}
	};

	struct ErrorLogStreambufTraits
	{
		static inline void log( std::ostream & stream
			, std::string const & text )
		{
			stream << "ERROR: " << text << std::endl;
			printf( "%s\n", text.c_str() );
		}

		static inline void logNoNL( std::ostream & stream
			, std::string const & text )
		{
			stream << "ERROR: " << text;
			printf( "%s", text.c_str() );
		}
	};

	struct TestCounts
	{
		void initialise( std::string const & name );
		void cleanup();

		std::string testName;
		uint32_t totalCount = 0u;
		uint32_t errorCount = 0u;
		uint32_t curTestErrors = 0u;

	private:
		std::unique_ptr< std::streambuf > tclog;
		std::unique_ptr< std::streambuf > tcout;
		std::unique_ptr< std::streambuf > tcerr;
	};

	int reportTestSuite( TestCounts const & testCounts );
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


#define testStringify( x )\
	#x

#define testConcat2( x, y )\
	testStringify( x ) testStringify( y )

#define testConcat3( x, y, z )\
	testConcat2( x, y ) testStringify( z )

#define testConcat4( x, y, z, w )\
	testConcat3( x, y, z ) testStringify( w )

#define testSuiteBeginEx( name, testCounts )\
	testCounts.initialise( name );\
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
	auto result = test::reportTestSuite( testCounts );\
	testCounts.cleanup();\
	return result;

#define testSuiteBegin( name )\
	test::TestCounts testCounts;\
	testSuiteBeginEx( name, testCounts )

#define testBegin( name )\
	test::beginTest( testCounts, name );\
	try\
	{\
		auto testName = testCounts.testName

#define testEnd()\
	}\
	catch ( std::exception & exc )\
	{\
		std::cout << testCounts.testName << " Failed: " << exc.what() << std::endl;\
	}\
	catch ( ... )\
	{\
		std::cout << testCounts.testName << " Failed: Unknown unhandled exception" << std::endl;\
	}\
	test::endTest( testCounts );

#define failure( x )\
	++testCounts.totalCount;\
	test::reportFailure( x " failed.", __FUNCTION__, __LINE__, testCounts );\

#define require( x )\
	try\
	{\
		++testCounts.totalCount;\
		if ( !( x ) )\
		{\
			throw std::runtime_error{ std::string{ #x } + " failed" };\
		}\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define check( x )\
	try\
	{\
		++testCounts.totalCount;\
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
		++testCounts.totalCount;\
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
		++testCounts.totalCount;\
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
		++testCounts.totalCount;\
		( x ); \
		test::reportFailure( testConcat2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
	}

#define checkNoThrow( x )\
	try\
	{\
		++testCounts.totalCount;\
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
