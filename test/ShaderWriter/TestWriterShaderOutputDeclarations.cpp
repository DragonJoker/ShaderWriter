#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain writer.implementFunction< void >( "main", [](){} )

	template< typename T >
	void testShaderOutput( test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutput" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::VertexWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0";
			auto value = writer.declOutput< T >( name, 0u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1";
			auto value = writer.declOutputArray< T >( name, 1u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutputArray< T >( "value", 1u, 6u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0_opt";
			auto value = writer.declOutput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1_opt";
			auto value = writer.declOutputArray< T >( name, 1u, 6u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterShaderOutputDeclarations" );
	testShaderOutput< sdw::Int >( testCounts );
	testShaderOutput< sdw::UInt >( testCounts );
	testShaderOutput< sdw::Float >( testCounts );
	testShaderOutput< sdw::Vec2 >( testCounts );
	testShaderOutput< sdw::Vec3 >( testCounts );
	testShaderOutput< sdw::Vec4 >( testCounts );
	testShaderOutput< sdw::IVec2 >( testCounts );
	testShaderOutput< sdw::IVec3 >( testCounts );
	testShaderOutput< sdw::IVec4 >( testCounts );
	testShaderOutput< sdw::UVec2 >( testCounts );
	testShaderOutput< sdw::UVec3 >( testCounts );
	testShaderOutput< sdw::UVec4 >( testCounts );
	testShaderOutput< sdw::Mat2 >( testCounts );
	testShaderOutput< sdw::Mat2x3 >( testCounts );
	testShaderOutput< sdw::Mat2x4 >( testCounts );
	testShaderOutput< sdw::Mat3 >( testCounts );
	testShaderOutput< sdw::Mat3x2 >( testCounts );
	testShaderOutput< sdw::Mat3x4 >( testCounts );
	testShaderOutput< sdw::Mat4 >( testCounts );
	testShaderOutput< sdw::Mat4x2 >( testCounts );
	testShaderOutput< sdw::Mat4x3 >( testCounts );
	testSuiteEnd();
}
