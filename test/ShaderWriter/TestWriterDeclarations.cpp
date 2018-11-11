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
	void testConstant( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( shader ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declConstant< T >( "value", test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue_opt";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue4";
			auto value = writer.declConstantArray< T >( name, test::getDefaultVector< T >( shader, 4u ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declConstantArray< T >( "value", test::getDefaultVector< T >( shader, 4u ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue4_opt";
			auto value = writer.declConstantArray< T >( name, test::getDefaultVector< T >( shader, 4u ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< typename T >
	void testSpecConstant( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_0";
			auto value = writer.declSpecConstant< T >( name, 0u, test::getDefault< T >( shader ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSpecConstant< T >( "value", 1u, test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_2_opt";
			auto value = writer.declSpecConstant< T >( name, 2u, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< typename T >
	void testShaderInput( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
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
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_1";
			auto value = writer.declInputArray< T >( name, 1u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_2";
			auto value = writer.declInputArray< T >( name, 2u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
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
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInputArray< T >( "value", 1u, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInputArray< T >( "value", 2u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
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
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_1_opt";
			auto value = writer.declInputArray< T >( name, 1u, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_2_opt";
			auto value = writer.declInputArray< T >( name, 2u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< typename T >
	void testShaderOutput( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0";
			auto value = writer.declOutput< T >( name, 0u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1";
			auto value = writer.declOutputArray< T >( name, 1u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_2";
			auto value = writer.declOutputArray< T >( name, 2u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutputArray< T >( "value", 1u, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutputArray< T >( "value", 2u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0_opt";
			auto value = writer.declOutput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1_opt";
			auto value = writer.declOutputArray< T >( name, 1u, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_2_opt";
			auto value = writer.declOutputArray< T >( name, 2u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< typename T >
	void testLocale( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, test::getDefault< T >( shader ) );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray12";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 12u );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 12u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray3";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultVector< T >( shader, 3u ) );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 3u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocale< T >( "value", false );
					check( !value.isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocale< T >( "value", sdw::Optional< T >{ test::getDefault< T >( shader ), false } );
					check( !value.isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocale< T >( "value", test::getDefault< T >( shader ), false );
					check( !value.isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocaleArray< T >( "value", 12u, false );
					check( !value.isEnabled() );
					check( !value[0].isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 12u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocaleArray< T >( "value", 3u, test::getDefaultVector< T >( shader, 3u ), false );
					check( !value.isEnabled() );
					check( !value[0].isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 3u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, true );
					check( value.isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, sdw::Optional< T >{ test::getDefault< T >( shader ), true } );
					check( value.isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned_opt2";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, test::getDefault< T >( shader ), true );
					check( value.isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray12_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 12u, true );
					check( value.isEnabled() );
					check( value[0].isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 12u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray3_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultVector< T >( shader, 3u ), true );
					check( value.isEnabled() );
					check( value[0].isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 3u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< typename T >
	void testBuiltin( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue";
			auto value = writer.declBuiltin< T >( name );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValueArray12";
			auto value = writer.declBuiltinArray< T >( name, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValueArray";
			auto value = writer.declBuiltinArray< T >( name );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue_optDis";
			auto value = writer.declBuiltin< T >( name, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValueArray12_optDis";
			auto value = writer.declBuiltinArray< T >( name, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValueArray_optDis";
			auto value = writer.declBuiltinArray< T >( name, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue_opt";
			auto value = writer.declBuiltin< T >( name, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValueArray12_opt";
			auto value = writer.declBuiltinArray< T >( name, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			++count;
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValueArray_opt";
			auto value = writer.declBuiltinArray< T >( name, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	void testSampledImage( ast::type::ImageFormat format
		, test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::SampledImage > )
			+ sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u, format );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declSampledImageArray< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u, format );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, false, format );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImageArray< SampledT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, 12u, false, format );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u, true, format );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declSampledImageArray< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u, true, format );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	void testImage( ast::type::ImageFormat format
		, test::TestCounts & testCounts )
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::Image > )
			+ sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declImage< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u, format );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declImageArray< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u, format );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, false, format );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declImageArray< SampledT, DimT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, 12u, false, format );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declImage< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 1u, 1u, true, format );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declImageArray< SampledT, DimT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u, true, format );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == 12u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< typename BOType >
	BOType createBo( sdw::ShaderWriter & writer );
	template<>
	sdw::Ubo createBo< sdw::Ubo >( sdw::ShaderWriter & writer )
	{
		return sdw::Ubo{ writer, "UBO", 1u, 1u };

	}
	template<>
	sdw::Ssbo createBo< sdw::Ssbo >( sdw::ShaderWriter & writer )
	{
		return sdw::Ssbo{ writer, "SSBO", 1u, 1u };
	}
	template<>
	sdw::Pcb createBo< sdw::Pcb >( sdw::ShaderWriter & writer )
	{
		return sdw::Pcb{ writer, "PCB" };
	}
	void checkBoStmt( sdw::stmt::ShaderBufferDecl const & stmt
		, test::TestCounts & testCounts )
	{
		check( stmt.getBindingPoint() == 1u );
		check( stmt.getDescriptorSet() == 1u );
	}
	void checkBoStmt( sdw::stmt::ConstantBufferDecl const & stmt
		, test::TestCounts & testCounts )
	{
		check( stmt.getBindingPoint() == 1u );
		check( stmt.getDescriptorSet() == 1u );
	}
	void checkBoStmt( sdw::stmt::PushConstantsBufferDecl const & stmt
		, test::TestCounts & testCounts )
	{
	}

	template< typename BOType, typename StmtType, sdw::stmt::Kind StmtKind, typename T >
	void testBo( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name );
			bo.end();
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArrayUnknown" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMemberArray< T >( name );
			bo.end();
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDis" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, false );
			bo.end();
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, false );
			check( !retrieved.isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDisArray" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, 4u, false );
			bo.end();
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			check( !retrieved.isEnabled() );
			check( !retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDisArrayUnknown" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMemberArray< T >( name, false );
			bo.end();
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			check( !retrieved.isEnabled() );
			check( !retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEn" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, true );
			bo.end();
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, true );
			check( retrieved.isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEnArray" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, 4u, true );
			bo.end();
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			check( retrieved.isEnabled() );
			check( retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEnArrayUnknown" + sdw::debug::getName( sdw::typeEnum< T > );
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMemberArray< T >( name, true );
			bo.end();
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			check( retrieved.isEnabled() );
			check( retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ), testCounts );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}

	template< typename T >
	void testUbo( test::TestCounts & testCounts )
	{
		testBo< sdw::Ubo, sdw::stmt::ConstantBufferDecl, sdw::stmt::Kind::eConstantBufferDecl, T >( testCounts );
	}

	template< typename T >
	void testSsbo( test::TestCounts & testCounts )
	{
		testBo< sdw::Ssbo, sdw::stmt::ShaderBufferDecl, sdw::stmt::Kind::eShaderBufferDecl, T >( testCounts );
	}

	template< typename T >
	void testPcb( test::TestCounts & testCounts )
	{
		testBo< sdw::Pcb, sdw::stmt::PushConstantsBufferDecl, sdw::stmt::Kind::ePushConstantsBufferDecl, T >( testCounts );
	}

	template< typename T >
	void testStruct( test::TestCounts & testCounts )
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct st{ writer, "ST" + sdw::debug::getName( sdw::typeEnum< T > ) };
			st.declMember< T >( name );
			st.end();
			auto instance = st.getInstance( "st" + sdw::debug::getName( sdw::typeEnum< T > ) );
			auto retrieved = instance.getMember< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct st{ writer, "ST" + sdw::debug::getName( sdw::typeEnum< T > ) };
			st.declMember< T >( name, 4u );
			st.end();
			auto instance = st.getInstance( "stArray4" + sdw::debug::getName( sdw::typeEnum< T > ) );
			auto retrieved = instance.getMemberArray< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArrayUnknown" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct st{ writer, "ST" + sdw::debug::getName( sdw::typeEnum< T > ) };
			st.declMemberArray< T >( name );
			st.end();
			auto instance = st.getInstance( "stArray" + sdw::debug::getName( sdw::typeEnum< T > ) );
			auto retrieved = instance.getMemberArray< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment, testCounts );
		}
	}
	void testConstants( test::TestCounts & testCounts )
	{
		testBegin( "testConstants" );
		testConstant< sdw::Boolean >( testCounts );
		testConstant< sdw::Int >( testCounts );
		testConstant< sdw::UInt >( testCounts );
		testConstant< sdw::Float >( testCounts );
		testConstant< sdw::Double >( testCounts );
		testConstant< sdw::Vec2 >( testCounts );
		testConstant< sdw::Vec3 >( testCounts );
		testConstant< sdw::Vec4 >( testCounts );
		testConstant< sdw::DVec2 >( testCounts );
		testConstant< sdw::DVec3 >( testCounts );
		testConstant< sdw::DVec4 >( testCounts );
		testConstant< sdw::BVec2 >( testCounts );
		testConstant< sdw::BVec3 >( testCounts );
		testConstant< sdw::BVec4 >( testCounts );
		testConstant< sdw::IVec2 >( testCounts );
		testConstant< sdw::IVec3 >( testCounts );
		testConstant< sdw::IVec4 >( testCounts );
		testConstant< sdw::UVec2 >( testCounts );
		testConstant< sdw::UVec3 >( testCounts );
		testConstant< sdw::UVec4 >( testCounts );
		testConstant< sdw::Mat2 >( testCounts );
		testConstant< sdw::Mat2x3 >( testCounts );
		testConstant< sdw::Mat2x4 >( testCounts );
		testConstant< sdw::Mat3 >( testCounts );
		testConstant< sdw::Mat3x2 >( testCounts );
		testConstant< sdw::Mat3x4 >( testCounts );
		testConstant< sdw::Mat4 >( testCounts );
		testConstant< sdw::Mat4x2 >( testCounts );
		testConstant< sdw::Mat4x3 >( testCounts );
		testConstant< sdw::DMat2 >( testCounts );
		testConstant< sdw::DMat2x3 >( testCounts );
		testConstant< sdw::DMat2x4 >( testCounts );
		testConstant< sdw::DMat3 >( testCounts );
		testConstant< sdw::DMat3x2 >( testCounts );
		testConstant< sdw::DMat3x4 >( testCounts );
		testConstant< sdw::DMat4 >( testCounts );
		testConstant< sdw::DMat4x2 >( testCounts );
		testConstant< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testSpecConstants( test::TestCounts & testCounts )
	{
		testBegin( "testSpecConstants" );
		testSpecConstant< sdw::Boolean >( testCounts );
		testSpecConstant< sdw::Int >( testCounts );
		testSpecConstant< sdw::UInt >( testCounts );
		testSpecConstant< sdw::Float >( testCounts );
		testSpecConstant< sdw::Double >( testCounts );
		testSpecConstant< sdw::Vec2 >( testCounts );
		testSpecConstant< sdw::Vec3 >( testCounts );
		testSpecConstant< sdw::Vec4 >( testCounts );
		testSpecConstant< sdw::DVec2 >( testCounts );
		testSpecConstant< sdw::DVec3 >( testCounts );
		testSpecConstant< sdw::DVec4 >( testCounts );
		testSpecConstant< sdw::BVec2 >( testCounts );
		testSpecConstant< sdw::BVec3 >( testCounts );
		testSpecConstant< sdw::BVec4 >( testCounts );
		testSpecConstant< sdw::IVec2 >( testCounts );
		testSpecConstant< sdw::IVec3 >( testCounts );
		testSpecConstant< sdw::IVec4 >( testCounts );
		testSpecConstant< sdw::UVec2 >( testCounts );
		testSpecConstant< sdw::UVec3 >( testCounts );
		testSpecConstant< sdw::UVec4 >( testCounts );
		testSpecConstant< sdw::Mat2 >( testCounts );
		testSpecConstant< sdw::Mat2x3 >( testCounts );
		testSpecConstant< sdw::Mat2x4 >( testCounts );
		testSpecConstant< sdw::Mat3 >( testCounts );
		testSpecConstant< sdw::Mat3x2 >( testCounts );
		testSpecConstant< sdw::Mat3x4 >( testCounts );
		testSpecConstant< sdw::Mat4 >( testCounts );
		testSpecConstant< sdw::Mat4x2 >( testCounts );
		testSpecConstant< sdw::Mat4x3 >( testCounts );
		testSpecConstant< sdw::DMat2 >( testCounts );
		testSpecConstant< sdw::DMat2x3 >( testCounts );
		testSpecConstant< sdw::DMat2x4 >( testCounts );
		testSpecConstant< sdw::DMat3 >( testCounts );
		testSpecConstant< sdw::DMat3x2 >( testCounts );
		testSpecConstant< sdw::DMat3x4 >( testCounts );
		testSpecConstant< sdw::DMat4 >( testCounts );
		testSpecConstant< sdw::DMat4x2 >( testCounts );
		testSpecConstant< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testShaderInputs( test::TestCounts & testCounts )
	{
		testBegin( "testShaderInputs" );
		testShaderInput< sdw::Boolean >( testCounts );
		testShaderInput< sdw::Int >( testCounts );
		testShaderInput< sdw::UInt >( testCounts );
		testShaderInput< sdw::Float >( testCounts );
		testShaderInput< sdw::Double >( testCounts );
		testShaderInput< sdw::Vec2 >( testCounts );
		testShaderInput< sdw::Vec3 >( testCounts );
		testShaderInput< sdw::Vec4 >( testCounts );
		testShaderInput< sdw::DVec2 >( testCounts );
		testShaderInput< sdw::DVec3 >( testCounts );
		testShaderInput< sdw::DVec4 >( testCounts );
		testShaderInput< sdw::BVec2 >( testCounts );
		testShaderInput< sdw::BVec3 >( testCounts );
		testShaderInput< sdw::BVec4 >( testCounts );
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
		testShaderInput< sdw::DMat2 >( testCounts );
		testShaderInput< sdw::DMat2x3 >( testCounts );
		testShaderInput< sdw::DMat2x4 >( testCounts );
		testShaderInput< sdw::DMat3 >( testCounts );
		testShaderInput< sdw::DMat3x2 >( testCounts );
		testShaderInput< sdw::DMat3x4 >( testCounts );
		testShaderInput< sdw::DMat4 >( testCounts );
		testShaderInput< sdw::DMat4x2 >( testCounts );
		testShaderInput< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testShaderOutputs( test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutputs" );
		testShaderOutput< sdw::Boolean >( testCounts );
		testShaderOutput< sdw::Int >( testCounts );
		testShaderOutput< sdw::UInt >( testCounts );
		testShaderOutput< sdw::Float >( testCounts );
		testShaderOutput< sdw::Double >( testCounts );
		testShaderOutput< sdw::Vec2 >( testCounts );
		testShaderOutput< sdw::Vec3 >( testCounts );
		testShaderOutput< sdw::Vec4 >( testCounts );
		testShaderOutput< sdw::DVec2 >( testCounts );
		testShaderOutput< sdw::DVec3 >( testCounts );
		testShaderOutput< sdw::DVec4 >( testCounts );
		testShaderOutput< sdw::BVec2 >( testCounts );
		testShaderOutput< sdw::BVec3 >( testCounts );
		testShaderOutput< sdw::BVec4 >( testCounts );
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
		testShaderOutput< sdw::DMat2 >( testCounts );
		testShaderOutput< sdw::DMat2x3 >( testCounts );
		testShaderOutput< sdw::DMat2x4 >( testCounts );
		testShaderOutput< sdw::DMat3 >( testCounts );
		testShaderOutput< sdw::DMat3x2 >( testCounts );
		testShaderOutput< sdw::DMat3x4 >( testCounts );
		testShaderOutput< sdw::DMat4 >( testCounts );
		testShaderOutput< sdw::DMat4x2 >( testCounts );
		testShaderOutput< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testLocales( test::TestCounts & testCounts )
	{
		testBegin( "testLocales" );
		testLocale< sdw::Boolean >( testCounts );
		testLocale< sdw::Int >( testCounts );
		testLocale< sdw::UInt >( testCounts );
		testLocale< sdw::Float >( testCounts );
		testLocale< sdw::Double >( testCounts );
		testLocale< sdw::Vec2 >( testCounts );
		testLocale< sdw::Vec3 >( testCounts );
		testLocale< sdw::Vec4 >( testCounts );
		testLocale< sdw::DVec2 >( testCounts );
		testLocale< sdw::DVec3 >( testCounts );
		testLocale< sdw::DVec4 >( testCounts );
		testLocale< sdw::BVec2 >( testCounts );
		testLocale< sdw::BVec3 >( testCounts );
		testLocale< sdw::BVec4 >( testCounts );
		testLocale< sdw::IVec2 >( testCounts );
		testLocale< sdw::IVec3 >( testCounts );
		testLocale< sdw::IVec4 >( testCounts );
		testLocale< sdw::UVec2 >( testCounts );
		testLocale< sdw::UVec3 >( testCounts );
		testLocale< sdw::UVec4 >( testCounts );
		testLocale< sdw::Mat2 >( testCounts );
		testLocale< sdw::Mat2x3 >( testCounts );
		testLocale< sdw::Mat2x4 >( testCounts );
		testLocale< sdw::Mat3 >( testCounts );
		testLocale< sdw::Mat3x2 >( testCounts );
		testLocale< sdw::Mat3x4 >( testCounts );
		testLocale< sdw::Mat4 >( testCounts );
		testLocale< sdw::Mat4x2 >( testCounts );
		testLocale< sdw::Mat4x3 >( testCounts );
		testLocale< sdw::DMat2 >( testCounts );
		testLocale< sdw::DMat2x3 >( testCounts );
		testLocale< sdw::DMat2x4 >( testCounts );
		testLocale< sdw::DMat3 >( testCounts );
		testLocale< sdw::DMat3x2 >( testCounts );
		testLocale< sdw::DMat3x4 >( testCounts );
		testLocale< sdw::DMat4 >( testCounts );
		testLocale< sdw::DMat4x2 >( testCounts );
		testLocale< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testBuiltins( test::TestCounts & testCounts )
	{
		testBegin( "testBuiltins" );
		testBuiltin< sdw::Boolean >( testCounts );
		testBuiltin< sdw::Int >( testCounts );
		testBuiltin< sdw::UInt >( testCounts );
		testBuiltin< sdw::Float >( testCounts );
		testBuiltin< sdw::Double >( testCounts );
		testBuiltin< sdw::Vec2 >( testCounts );
		testBuiltin< sdw::Vec3 >( testCounts );
		testBuiltin< sdw::Vec4 >( testCounts );
		testBuiltin< sdw::DVec2 >( testCounts );
		testBuiltin< sdw::DVec3 >( testCounts );
		testBuiltin< sdw::DVec4 >( testCounts );
		testBuiltin< sdw::BVec2 >( testCounts );
		testBuiltin< sdw::BVec3 >( testCounts );
		testBuiltin< sdw::BVec4 >( testCounts );
		testBuiltin< sdw::IVec2 >( testCounts );
		testBuiltin< sdw::IVec3 >( testCounts );
		testBuiltin< sdw::IVec4 >( testCounts );
		testBuiltin< sdw::UVec2 >( testCounts );
		testBuiltin< sdw::UVec3 >( testCounts );
		testBuiltin< sdw::UVec4 >( testCounts );
		testBuiltin< sdw::Mat2 >( testCounts );
		testBuiltin< sdw::Mat2x3 >( testCounts );
		testBuiltin< sdw::Mat2x4 >( testCounts );
		testBuiltin< sdw::Mat3 >( testCounts );
		testBuiltin< sdw::Mat3x2 >( testCounts );
		testBuiltin< sdw::Mat3x4 >( testCounts );
		testBuiltin< sdw::Mat4 >( testCounts );
		testBuiltin< sdw::Mat4x2 >( testCounts );
		testBuiltin< sdw::Mat4x3 >( testCounts );
		testBuiltin< sdw::DMat2 >( testCounts );
		testBuiltin< sdw::DMat2x3 >( testCounts );
		testBuiltin< sdw::DMat2x4 >( testCounts );
		testBuiltin< sdw::DMat3 >( testCounts );
		testBuiltin< sdw::DMat3x2 >( testCounts );
		testBuiltin< sdw::DMat3x4 >( testCounts );
		testBuiltin< sdw::DMat4 >( testCounts );
		testBuiltin< sdw::DMat4x2 >( testCounts );
		testBuiltin< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testSampledImages( test::TestCounts & testCounts )
	{
		testBegin( "testSampledImages" );

		for ( uint32_t i = 0u; i <= uint32_t( ast::type::ImageFormat::eR8u ); ++i )
		{
			auto format = ast::type::ImageFormat( i );
			testSampledImage< FImg1D >( format, testCounts );
			testSampledImage< FImg2D >( format, testCounts );
			testSampledImage< FImg3D >( format, testCounts );
			testSampledImage< FImgRect >( format, testCounts );
			testSampledImage< FImgCube >( format, testCounts );
			testSampledImage< FImgBuffer >( format, testCounts );
			testSampledImage< FImg1DArray >( format, testCounts );
			testSampledImage< FImg2DArray >( format, testCounts );
			testSampledImage< FImgCubeArray >( format, testCounts );
			testSampledImage< FImg2DMS >( format, testCounts );
			testSampledImage< FImg2DMSArray >( format, testCounts );
			testSampledImage< FImg1DShadow >( format, testCounts );
			testSampledImage< FImg2DShadow >( format, testCounts );
			testSampledImage< FImgRectShadow >( format, testCounts );
			testSampledImage< FImgCubeShadow >( format, testCounts );
			testSampledImage< FImg1DArrayShadow >( format, testCounts );
			testSampledImage< FImg2DArrayShadow >( format, testCounts );
			testSampledImage< FImgCubeArrayShadow >( format, testCounts );

			testSampledImage< IImg1D >( format, testCounts );
			testSampledImage< IImg2D >( format, testCounts );
			testSampledImage< IImg3D >( format, testCounts );
			testSampledImage< IImgRect >( format, testCounts );
			testSampledImage< IImgCube >( format, testCounts );
			testSampledImage< IImgBuffer >( format, testCounts );
			testSampledImage< IImg1DArray >( format, testCounts );
			testSampledImage< IImg2DArray >( format, testCounts );
			testSampledImage< IImgCubeArray >( format, testCounts );
			testSampledImage< IImg2DMS >( format, testCounts );
			testSampledImage< IImg2DMSArray >( format, testCounts );

			testSampledImage< UImg1D >( format, testCounts );
			testSampledImage< UImg2D >( format, testCounts );
			testSampledImage< UImg3D >( format, testCounts );
			testSampledImage< UImgRect >( format, testCounts );
			testSampledImage< UImgCube >( format, testCounts );
			testSampledImage< UImgBuffer >( format, testCounts );
			testSampledImage< UImg1DArray >( format, testCounts );
			testSampledImage< UImg2DArray >( format, testCounts );
			testSampledImage< UImgCubeArray >( format, testCounts );
			testSampledImage< UImg2DMS >( format, testCounts );
			testSampledImage< UImg2DMSArray >( format, testCounts );
		}

		testEnd();
	}

	void testImages( test::TestCounts & testCounts )
	{
		testBegin( "testImages" );

		for ( uint32_t i = 0u; i <= uint32_t( ast::type::ImageFormat::eR8u ); ++i )
		{
			auto format = ast::type::ImageFormat( i );
			testImage< FImg1D >( format, testCounts );
			testImage< FImg2D >( format, testCounts );
			testImage< FImg3D >( format, testCounts );
			testImage< FImgRect >( format, testCounts );
			testImage< FImgCube >( format, testCounts );
			testImage< FImgBuffer >( format, testCounts );
			testImage< FImg1DArray >( format, testCounts );
			testImage< FImg2DArray >( format, testCounts );
			testImage< FImgCubeArray >( format, testCounts );
			testImage< FImg2DMS >( format, testCounts );
			testImage< FImg2DMSArray >( format, testCounts );

			testImage< IImg1D >( format, testCounts );
			testImage< IImg2D >( format, testCounts );
			testImage< IImg3D >( format, testCounts );
			testImage< IImgRect >( format, testCounts );
			testImage< IImgCube >( format, testCounts );
			testImage< IImgBuffer >( format, testCounts );
			testImage< IImg1DArray >( format, testCounts );
			testImage< IImg2DArray >( format, testCounts );
			testImage< IImgCubeArray >( format, testCounts );
			testImage< IImg2DMS >( format, testCounts );
			testImage< IImg2DMSArray >( format, testCounts );

			testImage< UImg1D >( format, testCounts );
			testImage< UImg2D >( format, testCounts );
			testImage< UImg3D >( format, testCounts );
			testImage< UImgRect >( format, testCounts );
			testImage< UImgCube >( format, testCounts );
			testImage< UImgBuffer >( format, testCounts );
			testImage< UImg1DArray >( format, testCounts );
			testImage< UImg2DArray >( format, testCounts );
			testImage< UImgCubeArray >( format, testCounts );
			testImage< UImg2DMS >( format, testCounts );
			testImage< UImg2DMSArray >( format, testCounts );
		}

		testEnd();
	}

	void testUbos( test::TestCounts & testCounts )
	{
		testBegin( "testUbos" );
		testUbo< sdw::Int >( testCounts );
		testUbo< sdw::UInt >( testCounts );
		testUbo< sdw::Float >( testCounts );
		testUbo< sdw::Double >( testCounts );
		testUbo< sdw::Vec2 >( testCounts );
		testUbo< sdw::Vec3 >( testCounts );
		testUbo< sdw::Vec4 >( testCounts );
		testUbo< sdw::DVec2 >( testCounts );
		testUbo< sdw::DVec3 >( testCounts );
		testUbo< sdw::DVec4 >( testCounts );
		testUbo< sdw::IVec2 >( testCounts );
		testUbo< sdw::IVec3 >( testCounts );
		testUbo< sdw::IVec4 >( testCounts );
		testUbo< sdw::UVec2 >( testCounts );
		testUbo< sdw::UVec3 >( testCounts );
		testUbo< sdw::UVec4 >( testCounts );
		testUbo< sdw::Mat2 >( testCounts );
		testUbo< sdw::Mat2x3 >( testCounts );
		testUbo< sdw::Mat2x4 >( testCounts );
		testUbo< sdw::Mat3 >( testCounts );
		testUbo< sdw::Mat3x2 >( testCounts );
		testUbo< sdw::Mat3x4 >( testCounts );
		testUbo< sdw::Mat4 >( testCounts );
		testUbo< sdw::Mat4x2 >( testCounts );
		testUbo< sdw::Mat4x3 >( testCounts );
		testUbo< sdw::DMat2 >( testCounts );
		testUbo< sdw::DMat2x3 >( testCounts );
		testUbo< sdw::DMat2x4 >( testCounts );
		testUbo< sdw::DMat3 >( testCounts );
		testUbo< sdw::DMat3x2 >( testCounts );
		testUbo< sdw::DMat3x4 >( testCounts );
		testUbo< sdw::DMat4 >( testCounts );
		testUbo< sdw::DMat4x2 >( testCounts );
		testUbo< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testSsbos( test::TestCounts & testCounts )
	{
		testBegin( "testSsbos" );
		testSsbo< sdw::Int >( testCounts );
		testSsbo< sdw::UInt >( testCounts );
		testSsbo< sdw::Float >( testCounts );
		testSsbo< sdw::Double >( testCounts );
		testSsbo< sdw::Vec2 >( testCounts );
		testSsbo< sdw::Vec3 >( testCounts );
		testSsbo< sdw::Vec4 >( testCounts );
		testSsbo< sdw::DVec2 >( testCounts );
		testSsbo< sdw::DVec3 >( testCounts );
		testSsbo< sdw::DVec4 >( testCounts );
		testSsbo< sdw::IVec2 >( testCounts );
		testSsbo< sdw::IVec3 >( testCounts );
		testSsbo< sdw::IVec4 >( testCounts );
		testSsbo< sdw::UVec2 >( testCounts );
		testSsbo< sdw::UVec3 >( testCounts );
		testSsbo< sdw::UVec4 >( testCounts );
		testSsbo< sdw::Mat2 >( testCounts );
		testSsbo< sdw::Mat2x3 >( testCounts );
		testSsbo< sdw::Mat2x4 >( testCounts );
		testSsbo< sdw::Mat3 >( testCounts );
		testSsbo< sdw::Mat3x2 >( testCounts );
		testSsbo< sdw::Mat3x4 >( testCounts );
		testSsbo< sdw::Mat4 >( testCounts );
		testSsbo< sdw::Mat4x2 >( testCounts );
		testSsbo< sdw::Mat4x3 >( testCounts );
		testSsbo< sdw::DMat2 >( testCounts );
		testSsbo< sdw::DMat2x3 >( testCounts );
		testSsbo< sdw::DMat2x4 >( testCounts );
		testSsbo< sdw::DMat3 >( testCounts );
		testSsbo< sdw::DMat3x2 >( testCounts );
		testSsbo< sdw::DMat3x4 >( testCounts );
		testSsbo< sdw::DMat4 >( testCounts );
		testSsbo< sdw::DMat4x2 >( testCounts );
		testSsbo< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testPcbs( test::TestCounts & testCounts )
	{
		testBegin( "testPcbs" );
		testPcb< sdw::Int >( testCounts );
		testPcb< sdw::UInt >( testCounts );
		testPcb< sdw::Float >( testCounts );
		testPcb< sdw::Double >( testCounts );
		testPcb< sdw::Vec2 >( testCounts );
		testPcb< sdw::Vec3 >( testCounts );
		testPcb< sdw::Vec4 >( testCounts );
		testPcb< sdw::DVec2 >( testCounts );
		testPcb< sdw::DVec3 >( testCounts );
		testPcb< sdw::DVec4 >( testCounts );
		testPcb< sdw::IVec2 >( testCounts );
		testPcb< sdw::IVec3 >( testCounts );
		testPcb< sdw::IVec4 >( testCounts );
		testPcb< sdw::UVec2 >( testCounts );
		testPcb< sdw::UVec3 >( testCounts );
		testPcb< sdw::UVec4 >( testCounts );
		testPcb< sdw::Mat2 >( testCounts );
		testPcb< sdw::Mat2x3 >( testCounts );
		testPcb< sdw::Mat2x4 >( testCounts );
		testPcb< sdw::Mat3 >( testCounts );
		testPcb< sdw::Mat3x2 >( testCounts );
		testPcb< sdw::Mat3x4 >( testCounts );
		testPcb< sdw::Mat4 >( testCounts );
		testPcb< sdw::Mat4x2 >( testCounts );
		testPcb< sdw::Mat4x3 >( testCounts );
		testPcb< sdw::DMat2 >( testCounts );
		testPcb< sdw::DMat2x3 >( testCounts );
		testPcb< sdw::DMat2x4 >( testCounts );
		testPcb< sdw::DMat3 >( testCounts );
		testPcb< sdw::DMat3x2 >( testCounts );
		testPcb< sdw::DMat3x4 >( testCounts );
		testPcb< sdw::DMat4 >( testCounts );
		testPcb< sdw::DMat4x2 >( testCounts );
		testPcb< sdw::DMat4x3 >( testCounts );
		testEnd();
	}

	void testStructs( test::TestCounts & testCounts )
	{
		testBegin( "testStructs" );
		testStruct< sdw::Boolean >( testCounts );
		testStruct< sdw::Int >( testCounts );
		testStruct< sdw::UInt >( testCounts );
		testStruct< sdw::Float >( testCounts );
		testStruct< sdw::Double >( testCounts );
		testStruct< sdw::Vec2 >( testCounts );
		testStruct< sdw::Vec3 >( testCounts );
		testStruct< sdw::Vec4 >( testCounts );
		testStruct< sdw::DVec2 >( testCounts );
		testStruct< sdw::DVec3 >( testCounts );
		testStruct< sdw::DVec4 >( testCounts );
		testStruct< sdw::BVec2 >( testCounts );
		testStruct< sdw::BVec3 >( testCounts );
		testStruct< sdw::BVec4 >( testCounts );
		testStruct< sdw::IVec2 >( testCounts );
		testStruct< sdw::IVec3 >( testCounts );
		testStruct< sdw::IVec4 >( testCounts );
		testStruct< sdw::UVec2 >( testCounts );
		testStruct< sdw::UVec3 >( testCounts );
		testStruct< sdw::UVec4 >( testCounts );
		testStruct< sdw::Mat2 >( testCounts );
		testStruct< sdw::Mat2x3 >( testCounts );
		testStruct< sdw::Mat2x4 >( testCounts );
		testStruct< sdw::Mat3 >( testCounts );
		testStruct< sdw::Mat3x2 >( testCounts );
		testStruct< sdw::Mat3x4 >( testCounts );
		testStruct< sdw::Mat4 >( testCounts );
		testStruct< sdw::Mat4x2 >( testCounts );
		testStruct< sdw::Mat4x3 >( testCounts );
		testStruct< sdw::DMat2 >( testCounts );
		testStruct< sdw::DMat2x3 >( testCounts );
		testStruct< sdw::DMat2x4 >( testCounts );
		testStruct< sdw::DMat3 >( testCounts );
		testStruct< sdw::DMat3x2 >( testCounts );
		testStruct< sdw::DMat3x4 >( testCounts );
		testStruct< sdw::DMat4 >( testCounts );
		testStruct< sdw::DMat4x2 >( testCounts );
		testStruct< sdw::DMat4x3 >( testCounts );
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterDeclarations" );
	testUbos( testCounts );
	testConstants( testCounts );
	testSpecConstants( testCounts );
	testShaderInputs( testCounts );
	testShaderOutputs( testCounts );
	testLocales( testCounts );
	testBuiltins( testCounts );
	testSampledImages( testCounts );
	testImages( testCounts );
	testSsbos( testCounts );
	testPcbs( testCounts );
	testStructs( testCounts );
	testSuiteEnd();
}
