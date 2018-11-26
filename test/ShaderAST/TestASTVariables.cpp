#include "../Common.hpp"

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
		ast::type::TypePtr type;

		switch ( kind )
		{
		case ast::type::Kind::eStruct:
			type = ast::type::makeStructType( ast::type::MemoryLayout::eStd140, "Dummy" );
			break;
		case ast::type::Kind::eImage:
			type = ast::type::getImage( ast::type::ImageConfiguration{} );
			break;
		case ast::type::Kind::eSampledImage:
			type = ast::type::getSampledImage( ast::type::ImageConfiguration{} );
			break;
		case ast::type::Kind::eSampler:
			type = ast::type::getSampler();
			break;
		default:
			type = ast::type::makeType( kind );
			break;
		}

		if ( arraySize != ast::type::NotArray )
		{
			type = ast::type::makeArrayType( type, arraySize );
		}

		ast::var::Variable dummyVar{ type, "dummyVar" };
		std::cout << printVariable( dummyVar ) << std::endl;
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

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestASTVariables" );
	testVariable( testCounts );
	testSuiteEnd();
}
