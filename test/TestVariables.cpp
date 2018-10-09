#include "Common.hpp"

#include <ASTGenerator/Variable.hpp>

namespace
{
	void testVariable()
	{
		testBegin( "testVariable" );
		for ( uint8_t i = uint8_t( ast::Type::eMin ); i < uint8_t( ast::Type::eCount ); ++i )
		{
			ast::Variable dummyVar{ ast::Type( i ), "dummyVar" };
			check( dummyVar.getType() == ast::Type( i ) );
			check( dummyVar.getName() == "dummyVar" );
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
