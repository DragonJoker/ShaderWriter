#include "WriterCommon.hpp"

namespace
{
	using T = sdw::SDW_TestType;

#define DummyMain( value ) writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )\
		{\
			auto v = writer.declLocale( "v", value );\
		} )

	TEST_F( SDWTest, testShaderInput )
	{
		sdwTestBegin( "testShaderInput" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declInput< T >( "value", 0u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain( value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputArray )
	{
		sdwTestBegin( "testShaderInputArray" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declInputArray< T >( "value", 1u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain( value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputOptionalDisabled )
	{
		sdwTestBegin( "testShaderInputOptionalDisabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInput< T >( "value", 0u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			astCheck( shader.getStatements()->size() == count );
			DummyMain( value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputArrayOptionalDisabled )
	{
		sdwTestBegin( "testShaderInputArrayOptionalDisabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInputArray< T >( "value", 1u, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			astCheck( shader.getStatements()->size() == count );
			DummyMain( value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputOptionalEnabled )
	{
		sdwTestBegin( "testShaderInputOptionalEnabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declInput< T >( "value", 0u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain( value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputArrayOptionalEnabled )
	{
		sdwTestBegin( "testShaderInputArrayOptionalEnabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declInputArray< T >( "value", 1u, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain( value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
