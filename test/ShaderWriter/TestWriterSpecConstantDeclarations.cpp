#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	template< typename T >
	void testSpecConstant( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testSpecConstant" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "SpecConstantValue_0";
			auto value = writer.declSpecConstant( name, 0u, T{} );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSpecialisationConstantDecl );
			astCheck( static_cast< sdw::stmt::SpecialisationConstantDecl const & >( stmt ).getLocation() == 0u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					IF( writer, value )
					{
					}
					FI;
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSpecConstant( "value", 1u, T{}, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			astCheck( shader.getStatements()->size() == count );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "SpecConstantValue_2_opt";
			auto value = writer.declSpecConstant( name, 2u, T{}, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSpecialisationConstantDecl );
			astCheck( static_cast< sdw::stmt::SpecialisationConstantDecl const & >( stmt ).getLocation() == 2u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					IF( writer, value )
					{
					}
					FI;
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		astTestEnd();
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
