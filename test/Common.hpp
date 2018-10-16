#pragma once

#include <ASTGenerator/ASTGeneratorPrerequisites.hpp>

#include <iostream>
#include <stdexcept>
#include <fstream>

namespace test
{
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
			, m_fstream{ name + ".log" }
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

#define testSuiteBegin( name )\
	auto result = EXIT_SUCCESS;\
	try\
	{\
		auto tcout = std::make_unique< test::LogStreambuf< test::InfoLogStreambufTraits > >( name, std::cout );\
		auto tcerr = std::make_unique< test::LogStreambuf< test::ErrorLogStreambufTraits > >( name, std::cerr );\

#define testSuiteEnd()\
	}\
	catch ( std::exception & exc )\
	{\
		std::cerr << "Test " << exc.what() << std::endl;\
		result = EXIT_FAILURE;\
	}\
	catch ( ... )\
	{\
		std::cerr << "Test failed : Unhandled exception." << std::endl;\
		result = EXIT_FAILURE;\
	}\
	return result;

#define testBegin( name )\
	std::string testName = name;\
	std::cout << "********************************************************************************" << std::endl;\
	std::cout << "TEST: " << name << std::endl;\
	std::cout << "********************************************************************************" << std::endl;\
	uint32_t errCount = 0u;\
	try\
	{\

#define testEnd()\
	}\
	catch ( std::exception & exc )\
	{\
		throw std::runtime_error{ testName + " Failed : " + exc.what() };\
	}\
	catch ( ... )\
	{\
		throw std::runtime_error{ testName + " Failed : Unknown unhandled exception" };\
	}

#define check( x )\
	try\
	{\
		if ( !( x ) )\
		{\
			throw std::runtime_error{ #x##" failed" };\
		}\
	}\
	catch ( ... )\
	{\
		throw std::runtime_error{ #x##" failed" };\
	}

#define checkEqual( x, y )\
	try\
	{\
		if ( ( x ) != ( y ) )\
		{\
			throw std::runtime_error{ #x##" == "##y##" failed" };\
		}\
	}\
	catch ( ... )\
	{\
		throw std::runtime_error{ #x##" == "##y##" failed" };\
	}

#define checkNotEqual( x, y )\
	try\
	{\
		if ( ( x ) == ( y ) )\
		{\
			throw std::runtime_error{ #x##" != "##y##" failed" };\
		}\
	}\
	catch ( ... )\
	{\
		throw std::runtime_error{ #x##" != "##y##" failed" };\
	}

#define checkThrow( x )\
	try\
	{\
		( x ); \
		throw std::runtime_error{ #x##" failed" };\
	}\
	catch ( ... )\
	{\
	}

#define checkNoThrow( x )\
	try\
	{\
		( x ); \
	}\
	catch ( ... )\
	{\
		throw std::runtime_error{ #x##" failed" };\
	}
}
