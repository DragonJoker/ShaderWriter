#include "Common.hpp"

#include <ShaderAST/Debug/DebugCommon.hpp>
#include <ShaderAST/Var/Variable.hpp>

namespace
{
	std::string printVariable( ast::var::Variable const & var )
	{
		std::string result;
		result += ast::debug::getName( var.getType() ) + " " + var.getName();
		return result;
	}

	void testVariable( ast::type::Kind kind
		, uint32_t arraySize
		, test::TestCounts & testCounts )
	{
		ast::type::TypesCache cache;
		ast::type::TypePtr type;

		switch ( kind )
		{
		case ast::type::Kind::eStruct:
			type = cache.getStruct( ast::type::MemoryLayout::eStd140, "Dummy" );
			break;
		case ast::type::Kind::eImage:
			type = cache.getImage( ast::type::ImageConfiguration{} );
			break;
		case ast::type::Kind::eSampledImage:
			type = cache.getSampledImage( ast::type::ImageConfiguration{} );
			break;
		case ast::type::Kind::eSampler:
			type = cache.getSampler();
			break;
		default:
			type = cache.getBasicType( kind );
			break;
		}

		if ( arraySize != ast::type::NotArray )
		{
			type = cache.getArray( type, arraySize );
		}

		ast::var::Variable dummyVar{ type, "dummyVar" };
		testCounts.streams.cout << printVariable( dummyVar ) << std::endl;
		check( getNonArrayKind( dummyVar.getType() ) == kind );
		check( getArraySize( dummyVar.getType() ) == arraySize );
		check( dummyVar.getName() == "dummyVar" );
	}

	void testVariable( test::TestCounts & testCounts )
	{
		testBegin( "testVariable" );
		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eArray ); ++i )
		{
			testVariable( ast::type::Kind( i ), ast::type::NotArray, testCounts );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eArray ); ++i )
		{
			testVariable( ast::type::Kind( i ), ast::type::UnknownArraySize, testCounts );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eArray ); ++i )
		{
			testVariable( ast::type::Kind( i ), 3u, testCounts );
		}
		testEnd();
	}
}

testSuiteMain( TestASTVariables )
{
	testSuiteBegin();
	testVariable( testCounts );
	testSuiteEnd();
}

testSuiteLaunch( TestASTVariables )
