#include "WriterCommon.hpp"

namespace
{
	using T = SDW_TestType;

	TEST_F( SDWTest, testSpecConstant )
	{
		sdwTestBegin( "testSpecConstant" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declSpecConstant( "value", 0u, T{} );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSpecialisationConstantDecl );
			astCheck( static_cast< sdw::stmt::SpecialisationConstantDecl const & >( stmt ).getLocation() == 0u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					sdwIF( writer, value )
					{
					}
					sdwFI;
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSpecConstantOptionalDisabled )
	{
		sdwTestBegin( "testSpecConstantOptionalDisabled" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSpecConstantOptionalEnabled )
	{
		sdwTestBegin( "testSpecConstantOptionalEnabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declSpecConstant( "value", 2u, T{}, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSpecialisationConstant() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eSpecialisationConstantDecl );
			astCheck( static_cast< sdw::stmt::SpecialisationConstantDecl const & >( stmt ).getLocation() == 2u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					sdwIF( writer, value )
					{
					}
					sdwFI;
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
