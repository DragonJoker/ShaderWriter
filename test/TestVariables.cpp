#include "Common.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Var/Variable.hpp>

namespace
{
	std::string printVariable( ast::var::Variable const & var )
	{
		std::string result;
		result += ast::debug::getTypeName( var.getType()->getKind() ) + " " + var.getName();
		auto arraySize = var.getType()->getArraySize();

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				result += "[]";
			}
			else
			{
				result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		return result;
	}

	void testVariable()
	{
		testBegin( "testVariable" );
		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eCount ); ++i )
		{
			ast::var::Variable dummyVar{ ast::type::makeType( ast::type::Kind( i ) ), "dummyVar" };
			std::cout << printVariable( dummyVar ) << std::endl;
			check( dummyVar.getType()->getKind() == ast::type::Kind( i ) );
			check( dummyVar.getType()->getArraySize() == ast::type::NotArray );
			check( dummyVar.getName() == "dummyVar" );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eCount ); ++i )
		{
			ast::var::Variable dummyVar{ ast::type::makeType( ast::type::Kind( i ), ast::type::UnknownArraySize ), "dummyVar" };
			std::cout << printVariable( dummyVar ) << std::endl;
			check( dummyVar.getType()->getKind() == ast::type::Kind( i ) );
			check( dummyVar.getType()->getArraySize() == ast::type::UnknownArraySize );
			check( dummyVar.getName() == "dummyVar" );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eCount ); ++i )
		{
			ast::var::Variable dummyVar{ ast::type::makeType( ast::type::Kind( i ), 3u ), "dummyVar" };
			std::cout << printVariable( dummyVar ) << std::endl;
			check( dummyVar.getType()->getKind() == ast::type::Kind( i ) );
			check( dummyVar.getType()->getArraySize() == 3u );
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
