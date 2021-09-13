#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	template< typename T >
	void testSpecConstant( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSpecConstant" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_0";
			auto value = writer.declSpecConstant( name, 0u, T{} );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSpecialisationConstantDecl );
			check( static_cast< sdw::stmt::SpecialisationConstantDecl const & >( stmt ).getLocation() == 0u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					IF( writer, value )
					{
					}
					FI;
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSpecConstant( "value", 1u, T{}, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			check( shader.getStatements()->size() == count );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_2_opt";
			auto value = writer.declSpecConstant( name, 2u, T{}, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSpecialisationConstantDecl );
			check( static_cast< sdw::stmt::SpecialisationConstantDecl const & >( stmt ).getLocation() == 2u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					IF( writer, value )
					{
					}
					FI;
				} );
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterSpecConstantDeclarations )
{
	sdwTestSuiteBegin();
	testSpecConstant< bool >( testCounts );
	testSpecConstant< int32_t >( testCounts );
	testSpecConstant< uint32_t >( testCounts );
	testSpecConstant< float >( testCounts );
	testSpecConstant< double >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterSpecConstantDeclarations )
