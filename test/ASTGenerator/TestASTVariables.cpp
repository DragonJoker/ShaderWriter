#include "../Common.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Var/Variable.hpp>

namespace
{
	std::string printVariable( ast::var::Variable const & var )
	{
		std::string result;
		result += ast::debug::getName( var.getType() ) + " " + var.getName();
		return result;
	}

	void testVariable( ast::type::Kind kind
		, uint32_t arraySize )
	{
		ast::type::TypePtr type;

		switch ( kind )
		{
		case ast::type::Kind::eStruct:
			type = ast::type::makeStructType( ast::type::MemoryLayout::eStd140, "Dummy", arraySize );
			break;
		case ast::type::Kind::eImage:
			type = ast::type::getImage( ast::type::ImageConfiguration{}, arraySize );
			break;
		case ast::type::Kind::eSampledImage:
			type = ast::type::getSampledImage( ast::type::ImageConfiguration{}, arraySize );
			break;
		default:
			type = ast::type::makeType( kind, arraySize );
			break;
		}

		ast::var::Variable dummyVar{ type, "dummyVar" };
		std::cout << printVariable( dummyVar ) << std::endl;
		check( dummyVar.getType()->getKind() == kind );
		check( dummyVar.getType()->getArraySize() == arraySize );
		check( dummyVar.getName() == "dummyVar" );
	}

	void testVariable()
	{
		testBegin( "testVariable" );
		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eCount ); ++i )
		{
			testVariable( ast::type::Kind( i ), ast::type::NotArray );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eCount ); ++i )
		{
			testVariable( ast::type::Kind( i ), ast::type::UnknownArraySize );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eCount ); ++i )
		{
			testVariable( ast::type::Kind( i ), 3u );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestVariables" );
	testVariable();
	testSuiteEnd();
}
