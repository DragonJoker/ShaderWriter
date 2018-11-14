#pragma once

#include <ASTGenerator/Expr/ExprVisitor.hpp>
#include <ASTGenerator/Stmt/StmtVisitor.hpp>
#include <ASTGenerator/Type/ImageConfiguration.hpp>

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
		uint32_t totalCount = 0u;
		uint32_t errorCount = 0u;
	};

#define testSuiteBegin( name )\
	auto result = EXIT_SUCCESS;\
	test::TestCounts testCounts;\
	try\
	{\
		auto tcout = std::make_unique< test::LogStreambuf< test::InfoLogStreambufTraits > >( name, std::cout );\
		auto tcerr = std::make_unique< test::LogStreambuf< test::ErrorLogStreambufTraits > >( name, std::cerr );\

#define testSuiteEnd()\
		if ( testCounts.errorCount )\
		{\
			std::cout << "********************************************************************************" << std::endl;\
			std::cout << "Test suite ended with some failures." << std::endl;\
			std::cout << "Total checks count: " << testCounts.totalCount << std::endl;\
			std::cout << "Failed checks count: " << testCounts.errorCount << std::endl;\
			result = EXIT_FAILURE;\
		}\
		else\
		{\
			std::cout << "********************************************************************************" << std::endl;\
			std::cout << "Test suite ended cleanly." << std::endl;\
			std::cout << "Total checks count: " << testCounts.totalCount << std::endl;\
			result = EXIT_SUCCESS;\
		}\
	}\
	catch ( std::exception & exc )\
	{\
		std::cout << "Test failed, Unhandled exception: " << exc.what() << std::endl;\
		result = EXIT_FAILURE;\
	}\
	catch ( ... )\
	{\
		std::cout << "Test failed, Unhandled exception: Unknown." << std::endl;\
		result = EXIT_FAILURE;\
	}\
	return result;

#define testBegin( name )\
	std::string testName = name;\
	std::cout << "********************************************************************************" << std::endl;\
	std::cout << "TEST: " << name << std::endl;\
	std::cout << "********************************************************************************" << std::endl;\
	try\
	{\

#define testEnd()\
	}\
	catch ( std::exception & exc )\
	{\
		std::cout << testName << " Failed: " << exc.what() << std::endl;\
	}\
	catch ( ... )\
	{\
		std::cout << testName << " Failed: Unknown unhandled exception" << std::endl;\
	}

#define failure( x )\
	++testCounts.totalCount;\
	++testCounts.errorCount;\
	std::cout << x << " failed" << std::endl;\

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
		++testCounts.errorCount;\
		throw std::runtime_error{ std::string{ #x } + " failed" };\
	}

#define check( x )\
	try\
	{\
		++testCounts.totalCount;\
		if ( !( x ) )\
		{\
			++testCounts.errorCount;\
			std::cout << std::string{ #x } << " failed" << std::endl;\
		}\
	}\
	catch ( ... )\
	{\
		++testCounts.errorCount;\
		std::cout << std::string{ #x } << " failed: Unhandled exception" << std::endl;\
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
		++testCounts.errorCount;\
		throw std::runtime_error{ std::string{ #x } + " == " + std::string{ #y } + " failed" };\
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
		++testCounts.errorCount;\
		throw std::runtime_error{ std::string{ #x } + " != " + std::string{ #y } + " failed" };\
	}

#define checkThrow( x )\
	try\
	{\
		++testCounts.totalCount;\
		( x ); \
		++testCounts.errorCount;\
		throw std::runtime_error{ std::string{ #x } + " failed" };\
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
	catch ( ... )\
	{\
		++testCounts.errorCount;\
		throw std::runtime_error{ std::string{ #x } + " failed" };\
	}
}
