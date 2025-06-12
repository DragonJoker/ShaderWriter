#include "WriterCommon.hpp"

#include <ShaderWriter/TraditionalGraphicsWriter.hpp>

namespace
{
	using T = sdw::SDW_TestType;

#define DummyMain( value ) writer.implementEntryPoint( [&]( sdw::FragmentIn in, sdw::FragmentOut out )\
		{\
			auto v = writer.declLocale( "v", value );\
		} )

	TEST_F( SDWTest, testShaderInput )
	{
		sdwTestBegin( "testShaderInput" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_0";
			auto value = writer.declInput< T >( name, sdw::EntryPoint::eFragment, 0u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputArray )
	{
		sdwTestBegin( "testShaderInputArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_1";
			auto value = writer.declInputArray< T >( name, sdw::EntryPoint::eFragment, 1u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputOptionalDisabled )
	{
		sdwTestBegin( "testShaderInputOptionalDisabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInput< T >( "value", sdw::EntryPoint::eFragment, 0u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			astCheck( shader.getStatements()->size() == count );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputArrayOptionalDisabled )
	{
		sdwTestBegin( "testShaderInputArrayOptionalDisabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInputArray< T >( "value", sdw::EntryPoint::eFragment, 1u, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			astCheck( shader.getStatements()->size() == count );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputOptionalEnabled )
	{
		sdwTestBegin( "testShaderInputOptionalEnabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_0_opt";
			auto value = writer.declInput< T >( name, sdw::EntryPoint::eFragment, 0u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testShaderInputArrayOptionalEnabled )
	{
		sdwTestBegin( "testShaderInputArrayOptionalEnabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_1_opt";
			auto value = writer.declInputArray< T >( name, sdw::EntryPoint::eFragment, 1u, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
