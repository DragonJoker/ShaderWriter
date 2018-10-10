#include "Common.hpp"

#include <ASTGenerator/Var/BoundVariable.hpp>
#include <ASTGenerator/Var/Variable.hpp>

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

	void testBoundVariable()
	{
		testBegin( "testBoundVariable" );
		for ( uint8_t i = uint8_t( ast::Type::eMin ); i < uint8_t( ast::Type::eConstantsBuffer ); ++i )
		{
			ast::BoundVariablePtr dummyVar;
			checkThrow( dummyVar = std::make_shared< ast::BoundVariable >( ast::Type( i ), "dummyVar", 2u, 1u ) );
		}

		for ( uint8_t i = uint8_t( ast::Type::eConstantsBuffer ); i < uint8_t( ast::Type::eCount ); ++i )
		{
			ast::BoundVariable dummyVar{ ast::Type( i ), "dummyVar", 2u, 1u };
			check( dummyVar.getType() == ast::Type( i ) );
			check( dummyVar.getName() == "dummyVar" );
			check( dummyVar.getBindingPoint() == 2u );
			check( dummyVar.getBindingSet() == 1u );
			check( dummyVar.isBound() );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestVariables" );
	testVariable();
	testBoundVariable();
	testSuiteEnd();
}
