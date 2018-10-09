#include <ASTGenerator/ASTGeneratorPrerequisites.hpp>

#include <iostream>
#include <stdexcept>

namespace test
{
#define testSuiteBegin( name )\
	auto result = EXIT_SUCCESS;\
	try\
	{\

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
