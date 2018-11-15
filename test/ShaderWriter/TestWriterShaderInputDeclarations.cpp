#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>
#include <ShaderWriter/Intrinsics.hpp>
#include <ShaderWriter/Sampler.hpp>
#include <ShaderWriter/Shader.hpp>
#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

namespace
{
#define DummyMain writer.implementFunction< void >( "main", [](){} )

	template< typename T >
	void testShaderInput( test::TestCounts & testCounts )
	{
		testBegin( "testShaderInput" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_0";
			auto value = writer.declInput< T >( name, 0u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_1";
			auto value = writer.declInputArray< T >( name, 1u, 6u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInputArray< T >( "value", 1u, 6u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_0_opt";
			auto value = writer.declInput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_1_opt";
			auto value = writer.declInputArray< T >( name, 1u, 6u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
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
	testSuiteBegin( "TestWriterShaderInputDeclarations" );
	testShaderInput< sdw::Int >( testCounts );
	testShaderInput< sdw::UInt >( testCounts );
	testShaderInput< sdw::Float >( testCounts );
	testShaderInput< sdw::Vec2 >( testCounts );
	testShaderInput< sdw::Vec3 >( testCounts );
	testShaderInput< sdw::Vec4 >( testCounts );
	testShaderInput< sdw::IVec2 >( testCounts );
	testShaderInput< sdw::IVec3 >( testCounts );
	testShaderInput< sdw::IVec4 >( testCounts );
	testShaderInput< sdw::UVec2 >( testCounts );
	testShaderInput< sdw::UVec3 >( testCounts );
	testShaderInput< sdw::UVec4 >( testCounts );
	testShaderInput< sdw::Mat2 >( testCounts );
	testShaderInput< sdw::Mat2x3 >( testCounts );
	testShaderInput< sdw::Mat2x4 >( testCounts );
	testShaderInput< sdw::Mat3 >( testCounts );
	testShaderInput< sdw::Mat3x2 >( testCounts );
	testShaderInput< sdw::Mat3x4 >( testCounts );
	testShaderInput< sdw::Mat4 >( testCounts );
	testShaderInput< sdw::Mat4x2 >( testCounts );
	testShaderInput< sdw::Mat4x3 >( testCounts );
	testSuiteEnd();
}
