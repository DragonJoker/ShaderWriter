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
	void testConstant()
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
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< typename T >
	void testSpecConstant()
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_0";
			auto value = writer.declSpecConstant< T >( name, 0u, test::getDefault< T >( shader ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSpecConstant< T >( "value", 1u, test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_2_opt";
			auto value = writer.declSpecConstant< T >( name, 2u, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< typename T >
	void testShaderInput()
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_0";
			auto value = writer.declInput< T >( name, 0u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_1";
			auto value = writer.declInputArray< T >( name, 1u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_2";
			auto value = writer.declInputArray< T >( name, 2u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_0_opt";
			auto value = writer.declInput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< typename T >
	void testShaderOutput()
	{
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0";
			auto value = writer.declOutput< T >( name, 0u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1";
			auto value = writer.declOutputArray< T >( name, 1u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_2";
			auto value = writer.declOutputArray< T >( name, 2u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0_opt";
			auto value = writer.declOutput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< typename T >
	void testLocale()
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray3";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultArray< T >( shader, 3u ) );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 3u );
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocaleArray< T >( "value", 3u, test::getDefaultArray< T >( shader, 3u ), false );
					check( !value.isEnabled() );
					check( !value[0].isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 3u );
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray3_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultArray< T >( shader, 3u ), true );
					check( value.isEnabled() );
					check( value[0].isEnabled() );
					check( value.getType()->getKind() == sdw::typeEnum< T > );
					check( value.getType()->getArraySize() == 3u );
					check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< typename T >
	void testBuiltin()
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		void testSampledImage()
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::SampledImage > )
			+ sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, DepthT, MsT );
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 1u, 1u );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declSampledImageArray< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSampledImageArray< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declSampledImageArray< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::SampledImage > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eSampledImageDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		void testImage()
	{
		auto nameBase = sdw::debug::getName( sdw::typeEnum< sdw::Image > )
			+ sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, DepthT, MsT );
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1";
			auto value = writer.declImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 1u, 1u );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2";
			auto value = writer.declImageArray< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declImageArray< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "value", 1u, 1u, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_1_1_opt";
			auto value = writer.declImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = nameBase + "Value_2_2_opt";
			auto value = writer.declImageArray< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( name, 2u, 2u, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< sdw::Image > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eImageDecl );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::ImageDecl const & >( stmt ).getDescriptorSet() == 2u );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
	void checkBoStmt( sdw::stmt::ShaderBufferDecl const & stmt )
	{
		check( stmt.getBindingPoint() == 1u );
		check( stmt.getDescriptorSet() == 1u );
	}
	void checkBoStmt( sdw::stmt::ConstantBufferDecl const & stmt )
	{
		check( stmt.getBindingPoint() == 1u );
		check( stmt.getDescriptorSet() == 1u );
	}
	void checkBoStmt( sdw::stmt::PushConstantsBufferDecl const & stmt )
	{
	}

	template< typename BOType, typename StmtType, sdw::stmt::Kind StmtKind, typename T >
	void testBo()
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, false );
			check( !retrieved.isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			check( !retrieved.isEnabled() );
			check( !retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			check( !retrieved.isEnabled() );
			check( !retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, true );
			check( retrieved.isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			check( retrieved.isEnabled() );
			check( retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			check( retrieved.isEnabled() );
			check( retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
			DummyMain;
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}

	template< typename T >
	void testUbo()
	{
		testBo< sdw::Ubo, sdw::stmt::ConstantBufferDecl, sdw::stmt::Kind::eConstantBufferDecl, T >();
	}

	template< typename T >
	void testSsbo()
	{
		testBo< sdw::Ssbo, sdw::stmt::ShaderBufferDecl, sdw::stmt::Kind::eShaderBufferDecl, T >();
	}

	template< typename T >
	void testPcb()
	{
		testBo< sdw::Pcb, sdw::stmt::PushConstantsBufferDecl, sdw::stmt::Kind::ePushConstantsBufferDecl, T >();
	}

	template< typename T >
	void testStruct()
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
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			test::writeShader( shader, sdw::ShaderType::eFragment );
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
			test::writeShader( shader, sdw::ShaderType::eFragment );
		}
	}
	void testConstants()
	{
		testBegin( "testConstants" );
		sdw::ShaderWriter writer{ false };
		testConstant< sdw::Boolean >();
		testConstant< sdw::Int >();
		testConstant< sdw::UInt >();
		testConstant< sdw::Float >();
		testConstant< sdw::Double >();
		testConstant< sdw::Vec2 >();
		testConstant< sdw::Vec3 >();
		testConstant< sdw::Vec4 >();
		testConstant< sdw::DVec2 >();
		testConstant< sdw::DVec3 >();
		testConstant< sdw::DVec4 >();
		testConstant< sdw::BVec2 >();
		testConstant< sdw::BVec3 >();
		testConstant< sdw::BVec4 >();
		testConstant< sdw::IVec2 >();
		testConstant< sdw::IVec3 >();
		testConstant< sdw::IVec4 >();
		testConstant< sdw::UVec2 >();
		testConstant< sdw::UVec3 >();
		testConstant< sdw::UVec4 >();
		testConstant< sdw::Mat2 >();
		testConstant< sdw::Mat2x3 >();
		testConstant< sdw::Mat2x4 >();
		testConstant< sdw::Mat3 >();
		testConstant< sdw::Mat3x2 >();
		testConstant< sdw::Mat3x4 >();
		testConstant< sdw::Mat4 >();
		testConstant< sdw::Mat4x2 >();
		testConstant< sdw::Mat4x3 >();
		testConstant< sdw::DMat2 >();
		testConstant< sdw::DMat2x3 >();
		testConstant< sdw::DMat2x4 >();
		testConstant< sdw::DMat3 >();
		testConstant< sdw::DMat3x2 >();
		testConstant< sdw::DMat3x4 >();
		testConstant< sdw::DMat4 >();
		testConstant< sdw::DMat4x2 >();
		testConstant< sdw::DMat4x3 >();
		testEnd();
	}

	void testSpecConstants()
	{
		testBegin( "testSpecConstants" );
		sdw::ShaderWriter writer{ false };
		testSpecConstant< sdw::Boolean >();
		testSpecConstant< sdw::Int >();
		testSpecConstant< sdw::UInt >();
		testSpecConstant< sdw::Float >();
		testSpecConstant< sdw::Double >();
		testSpecConstant< sdw::Vec2 >();
		testSpecConstant< sdw::Vec3 >();
		testSpecConstant< sdw::Vec4 >();
		testSpecConstant< sdw::DVec2 >();
		testSpecConstant< sdw::DVec3 >();
		testSpecConstant< sdw::DVec4 >();
		testSpecConstant< sdw::BVec2 >();
		testSpecConstant< sdw::BVec3 >();
		testSpecConstant< sdw::BVec4 >();
		testSpecConstant< sdw::IVec2 >();
		testSpecConstant< sdw::IVec3 >();
		testSpecConstant< sdw::IVec4 >();
		testSpecConstant< sdw::UVec2 >();
		testSpecConstant< sdw::UVec3 >();
		testSpecConstant< sdw::UVec4 >();
		testSpecConstant< sdw::Mat2 >();
		testSpecConstant< sdw::Mat2x3 >();
		testSpecConstant< sdw::Mat2x4 >();
		testSpecConstant< sdw::Mat3 >();
		testSpecConstant< sdw::Mat3x2 >();
		testSpecConstant< sdw::Mat3x4 >();
		testSpecConstant< sdw::Mat4 >();
		testSpecConstant< sdw::Mat4x2 >();
		testSpecConstant< sdw::Mat4x3 >();
		testSpecConstant< sdw::DMat2 >();
		testSpecConstant< sdw::DMat2x3 >();
		testSpecConstant< sdw::DMat2x4 >();
		testSpecConstant< sdw::DMat3 >();
		testSpecConstant< sdw::DMat3x2 >();
		testSpecConstant< sdw::DMat3x4 >();
		testSpecConstant< sdw::DMat4 >();
		testSpecConstant< sdw::DMat4x2 >();
		testSpecConstant< sdw::DMat4x3 >();
		testEnd();
	}

	void testShaderInputs()
	{
		testBegin( "testShaderInputs" );
		sdw::ShaderWriter writer{ false };
		testShaderInput< sdw::Boolean >();
		testShaderInput< sdw::Int >();
		testShaderInput< sdw::UInt >();
		testShaderInput< sdw::Float >();
		testShaderInput< sdw::Double >();
		testShaderInput< sdw::Vec2 >();
		testShaderInput< sdw::Vec3 >();
		testShaderInput< sdw::Vec4 >();
		testShaderInput< sdw::DVec2 >();
		testShaderInput< sdw::DVec3 >();
		testShaderInput< sdw::DVec4 >();
		testShaderInput< sdw::BVec2 >();
		testShaderInput< sdw::BVec3 >();
		testShaderInput< sdw::BVec4 >();
		testShaderInput< sdw::IVec2 >();
		testShaderInput< sdw::IVec3 >();
		testShaderInput< sdw::IVec4 >();
		testShaderInput< sdw::UVec2 >();
		testShaderInput< sdw::UVec3 >();
		testShaderInput< sdw::UVec4 >();
		testShaderInput< sdw::Mat2 >();
		testShaderInput< sdw::Mat2x3 >();
		testShaderInput< sdw::Mat2x4 >();
		testShaderInput< sdw::Mat3 >();
		testShaderInput< sdw::Mat3x2 >();
		testShaderInput< sdw::Mat3x4 >();
		testShaderInput< sdw::Mat4 >();
		testShaderInput< sdw::Mat4x2 >();
		testShaderInput< sdw::Mat4x3 >();
		testShaderInput< sdw::DMat2 >();
		testShaderInput< sdw::DMat2x3 >();
		testShaderInput< sdw::DMat2x4 >();
		testShaderInput< sdw::DMat3 >();
		testShaderInput< sdw::DMat3x2 >();
		testShaderInput< sdw::DMat3x4 >();
		testShaderInput< sdw::DMat4 >();
		testShaderInput< sdw::DMat4x2 >();
		testShaderInput< sdw::DMat4x3 >();
		testEnd();
	}

	void testShaderOutputs()
	{
		testBegin( "testShaderOutputs" );
		sdw::ShaderWriter writer{ false };
		testShaderOutput< sdw::Boolean >();
		testShaderOutput< sdw::Int >();
		testShaderOutput< sdw::UInt >();
		testShaderOutput< sdw::Float >();
		testShaderOutput< sdw::Double >();
		testShaderOutput< sdw::Vec2 >();
		testShaderOutput< sdw::Vec3 >();
		testShaderOutput< sdw::Vec4 >();
		testShaderOutput< sdw::DVec2 >();
		testShaderOutput< sdw::DVec3 >();
		testShaderOutput< sdw::DVec4 >();
		testShaderOutput< sdw::BVec2 >();
		testShaderOutput< sdw::BVec3 >();
		testShaderOutput< sdw::BVec4 >();
		testShaderOutput< sdw::IVec2 >();
		testShaderOutput< sdw::IVec3 >();
		testShaderOutput< sdw::IVec4 >();
		testShaderOutput< sdw::UVec2 >();
		testShaderOutput< sdw::UVec3 >();
		testShaderOutput< sdw::UVec4 >();
		testShaderOutput< sdw::Mat2 >();
		testShaderOutput< sdw::Mat2x3 >();
		testShaderOutput< sdw::Mat2x4 >();
		testShaderOutput< sdw::Mat3 >();
		testShaderOutput< sdw::Mat3x2 >();
		testShaderOutput< sdw::Mat3x4 >();
		testShaderOutput< sdw::Mat4 >();
		testShaderOutput< sdw::Mat4x2 >();
		testShaderOutput< sdw::Mat4x3 >();
		testShaderOutput< sdw::DMat2 >();
		testShaderOutput< sdw::DMat2x3 >();
		testShaderOutput< sdw::DMat2x4 >();
		testShaderOutput< sdw::DMat3 >();
		testShaderOutput< sdw::DMat3x2 >();
		testShaderOutput< sdw::DMat3x4 >();
		testShaderOutput< sdw::DMat4 >();
		testShaderOutput< sdw::DMat4x2 >();
		testShaderOutput< sdw::DMat4x3 >();
		testEnd();
	}

	void testLocales()
	{
		testBegin( "testLocales" );
		sdw::ShaderWriter writer{ false };
		testLocale< sdw::Boolean >();
		testLocale< sdw::Int >();
		testLocale< sdw::UInt >();
		testLocale< sdw::Float >();
		testLocale< sdw::Double >();
		testLocale< sdw::Vec2 >();
		testLocale< sdw::Vec3 >();
		testLocale< sdw::Vec4 >();
		testLocale< sdw::DVec2 >();
		testLocale< sdw::DVec3 >();
		testLocale< sdw::DVec4 >();
		testLocale< sdw::BVec2 >();
		testLocale< sdw::BVec3 >();
		testLocale< sdw::BVec4 >();
		testLocale< sdw::IVec2 >();
		testLocale< sdw::IVec3 >();
		testLocale< sdw::IVec4 >();
		testLocale< sdw::UVec2 >();
		testLocale< sdw::UVec3 >();
		testLocale< sdw::UVec4 >();
		testLocale< sdw::Mat2 >();
		testLocale< sdw::Mat2x3 >();
		testLocale< sdw::Mat2x4 >();
		testLocale< sdw::Mat3 >();
		testLocale< sdw::Mat3x2 >();
		testLocale< sdw::Mat3x4 >();
		testLocale< sdw::Mat4 >();
		testLocale< sdw::Mat4x2 >();
		testLocale< sdw::Mat4x3 >();
		testLocale< sdw::DMat2 >();
		testLocale< sdw::DMat2x3 >();
		testLocale< sdw::DMat2x4 >();
		testLocale< sdw::DMat3 >();
		testLocale< sdw::DMat3x2 >();
		testLocale< sdw::DMat3x4 >();
		testLocale< sdw::DMat4 >();
		testLocale< sdw::DMat4x2 >();
		testLocale< sdw::DMat4x3 >();
		testEnd();
	}

	void testBuiltins()
	{
		testBegin( "testBuiltins" );
		sdw::ShaderWriter writer{ false };
		testBuiltin< sdw::Boolean >();
		testBuiltin< sdw::Int >();
		testBuiltin< sdw::UInt >();
		testBuiltin< sdw::Float >();
		testBuiltin< sdw::Double >();
		testBuiltin< sdw::Vec2 >();
		testBuiltin< sdw::Vec3 >();
		testBuiltin< sdw::Vec4 >();
		testBuiltin< sdw::DVec2 >();
		testBuiltin< sdw::DVec3 >();
		testBuiltin< sdw::DVec4 >();
		testBuiltin< sdw::BVec2 >();
		testBuiltin< sdw::BVec3 >();
		testBuiltin< sdw::BVec4 >();
		testBuiltin< sdw::IVec2 >();
		testBuiltin< sdw::IVec3 >();
		testBuiltin< sdw::IVec4 >();
		testBuiltin< sdw::UVec2 >();
		testBuiltin< sdw::UVec3 >();
		testBuiltin< sdw::UVec4 >();
		testBuiltin< sdw::Mat2 >();
		testBuiltin< sdw::Mat2x3 >();
		testBuiltin< sdw::Mat2x4 >();
		testBuiltin< sdw::Mat3 >();
		testBuiltin< sdw::Mat3x2 >();
		testBuiltin< sdw::Mat3x4 >();
		testBuiltin< sdw::Mat4 >();
		testBuiltin< sdw::Mat4x2 >();
		testBuiltin< sdw::Mat4x3 >();
		testBuiltin< sdw::DMat2 >();
		testBuiltin< sdw::DMat2x3 >();
		testBuiltin< sdw::DMat2x4 >();
		testBuiltin< sdw::DMat3 >();
		testBuiltin< sdw::DMat3x2 >();
		testBuiltin< sdw::DMat3x4 >();
		testBuiltin< sdw::DMat4 >();
		testBuiltin< sdw::DMat4x2 >();
		testBuiltin< sdw::DMat4x3 >();
		testEnd();
	}

	void testSampledImages()
	{
		testBegin( "testSampledImages" );
		sdw::ShaderWriter writer{ false };
		testSampledImage< FImg1DRGBA32F >();
		testSampledImage< FImg1DRGBA8I >();
		testSampledImage< FImg1DRGBA8U >();
		testSampledImage< FImg2DRGBA32F >();
		testSampledImage< FImg2DRGBA8I >();
		testSampledImage< FImg2DRGBA8U >();
		testSampledImage< FImg3DRGBA32F >();
		testSampledImage< FImg3DRGBA8I >();
		testSampledImage< FImg3DRGBA8U >();
		testSampledImage< FImgRectRGBA32F >();
		testSampledImage< FImgRectRGBA8I >();
		testSampledImage< FImgRectRGBA8U >();
		testSampledImage< FImgCubeRGBA32F >();
		testSampledImage< FImgCubeRGBA8I >();
		testSampledImage< FImgCubeRGBA8U >();
		testSampledImage< FImgBufferRGBA32F >();
		testSampledImage< FImgBufferRGBA8I >();
		testSampledImage< FImgBufferRGBA8U >();
		testSampledImage< FImg1DArrayRGBA32F >();
		testSampledImage< FImg1DArrayRGBA8I >();
		testSampledImage< FImg1DArrayRGBA8U >();
		testSampledImage< FImg2DArrayRGBA32F >();
		testSampledImage< FImg2DArrayRGBA8I >();
		testSampledImage< FImg2DArrayRGBA8U >();
		testSampledImage< FImgCubeArrayRGBA32F >();
		testSampledImage< FImgCubeArrayRGBA8I >();
		testSampledImage< FImgCubeArrayRGBA8U >();
		testSampledImage< FImg1DShadowRGBA32F >();
		testSampledImage< FImg2DShadowRGBA32F >();
		testSampledImage< FImgRectShadowRGBA32F >();
		testSampledImage< FImgCubeShadowRGBA32F >();
		testSampledImage< FImg1DArrayShadowRGBA32F >();
		testSampledImage< FImg2DArrayShadowRGBA32F >();
		testSampledImage< FImgCubeArrayShadowRGBA32F >();

		testSampledImage< IImg1DRGBA32F >();
		testSampledImage< IImg1DRGBA8I >();
		testSampledImage< IImg1DRGBA8U >();
		testSampledImage< IImg2DRGBA32F >();
		testSampledImage< IImg2DRGBA8I >();
		testSampledImage< IImg2DRGBA8U >();
		testSampledImage< IImg3DRGBA32F >();
		testSampledImage< IImg3DRGBA8I >();
		testSampledImage< IImg3DRGBA8U >();
		testSampledImage< IImgRectRGBA32F >();
		testSampledImage< IImgRectRGBA8I >();
		testSampledImage< IImgRectRGBA8U >();
		testSampledImage< IImgCubeRGBA32F >();
		testSampledImage< IImgCubeRGBA8I >();
		testSampledImage< IImgCubeRGBA8U >();
		testSampledImage< IImgBufferRGBA32F >();
		testSampledImage< IImgBufferRGBA8I >();
		testSampledImage< IImgBufferRGBA8U >();
		testSampledImage< IImg1DArrayRGBA32F >();
		testSampledImage< IImg1DArrayRGBA8I >();
		testSampledImage< IImg1DArrayRGBA8U >();
		testSampledImage< IImg2DArrayRGBA32F >();
		testSampledImage< IImg2DArrayRGBA8I >();
		testSampledImage< IImg2DArrayRGBA8U >();
		testSampledImage< IImgCubeArrayRGBA32F >();
		testSampledImage< IImgCubeArrayRGBA8I >();
		testSampledImage< IImgCubeArrayRGBA8U >();

		testSampledImage< UImg1DRGBA32F >();
		testSampledImage< UImg1DRGBA8I >();
		testSampledImage< UImg1DRGBA8U >();
		testSampledImage< UImg2DRGBA32F >();
		testSampledImage< UImg2DRGBA8I >();
		testSampledImage< UImg2DRGBA8U >();
		testSampledImage< UImg3DRGBA32F >();
		testSampledImage< UImg3DRGBA8I >();
		testSampledImage< UImg3DRGBA8U >();
		testSampledImage< UImgRectRGBA32F >();
		testSampledImage< UImgRectRGBA8I >();
		testSampledImage< UImgRectRGBA8U >();
		testSampledImage< UImgCubeRGBA32F >();
		testSampledImage< UImgCubeRGBA8I >();
		testSampledImage< UImgCubeRGBA8U >();
		testSampledImage< UImgBufferRGBA32F >();
		testSampledImage< UImgBufferRGBA8I >();
		testSampledImage< UImgBufferRGBA8U >();
		testSampledImage< UImg1DArrayRGBA32F >();
		testSampledImage< UImg1DArrayRGBA8I >();
		testSampledImage< UImg1DArrayRGBA8U >();
		testSampledImage< UImg2DArrayRGBA32F >();
		testSampledImage< UImg2DArrayRGBA8I >();
		testSampledImage< UImg2DArrayRGBA8U >();
		testSampledImage< UImgCubeArrayRGBA32F >();
		testSampledImage< UImgCubeArrayRGBA8I >();
		testSampledImage< UImgCubeArrayRGBA8U >();
		testEnd();
	}

	void testImages()
	{
		testBegin( "testImages" );
		sdw::ShaderWriter writer{ false };
		testImage< FImg1DRGBA32F >();
		testImage< FImg1DRGBA8I >();
		testImage< FImg1DRGBA8U >();
		testImage< FImg2DRGBA32F >();
		testImage< FImg2DRGBA8I >();
		testImage< FImg2DRGBA8U >();
		testImage< FImg3DRGBA32F >();
		testImage< FImg3DRGBA8I >();
		testImage< FImg3DRGBA8U >();
		testImage< FImgRectRGBA32F >();
		testImage< FImgRectRGBA8I >();
		testImage< FImgRectRGBA8U >();
		testImage< FImgCubeRGBA32F >();
		testImage< FImgCubeRGBA8I >();
		testImage< FImgCubeRGBA8U >();
		testImage< FImgBufferRGBA32F >();
		testImage< FImgBufferRGBA8I >();
		testImage< FImgBufferRGBA8U >();
		testImage< FImg1DArrayRGBA32F >();
		testImage< FImg1DArrayRGBA8I >();
		testImage< FImg1DArrayRGBA8U >();
		testImage< FImg2DArrayRGBA32F >();
		testImage< FImg2DArrayRGBA8I >();
		testImage< FImg2DArrayRGBA8U >();
		testImage< FImgCubeArrayRGBA32F >();
		testImage< FImgCubeArrayRGBA8I >();
		testImage< FImgCubeArrayRGBA8U >();
		testImage< FImg1DShadowRGBA32F >();
		testImage< FImg2DShadowRGBA32F >();
		testImage< FImgRectShadowRGBA32F >();
		testImage< FImgCubeShadowRGBA32F >();
		testImage< FImg1DArrayShadowRGBA32F >();
		testImage< FImg2DArrayShadowRGBA32F >();
		testImage< FImgCubeArrayShadowRGBA32F >();

		testImage< IImg1DRGBA32F >();
		testImage< IImg1DRGBA8I >();
		testImage< IImg1DRGBA8U >();
		testImage< IImg2DRGBA32F >();
		testImage< IImg2DRGBA8I >();
		testImage< IImg2DRGBA8U >();
		testImage< IImg3DRGBA32F >();
		testImage< IImg3DRGBA8I >();
		testImage< IImg3DRGBA8U >();
		testImage< IImgRectRGBA32F >();
		testImage< IImgRectRGBA8I >();
		testImage< IImgRectRGBA8U >();
		testImage< IImgCubeRGBA32F >();
		testImage< IImgCubeRGBA8I >();
		testImage< IImgCubeRGBA8U >();
		testImage< IImgBufferRGBA32F >();
		testImage< IImgBufferRGBA8I >();
		testImage< IImgBufferRGBA8U >();
		testImage< IImg1DArrayRGBA32F >();
		testImage< IImg1DArrayRGBA8I >();
		testImage< IImg1DArrayRGBA8U >();
		testImage< IImg2DArrayRGBA32F >();
		testImage< IImg2DArrayRGBA8I >();
		testImage< IImg2DArrayRGBA8U >();
		testImage< IImgCubeArrayRGBA32F >();
		testImage< IImgCubeArrayRGBA8I >();
		testImage< IImgCubeArrayRGBA8U >();

		testImage< UImg1DRGBA32F >();
		testImage< UImg1DRGBA8I >();
		testImage< UImg1DRGBA8U >();
		testImage< UImg2DRGBA32F >();
		testImage< UImg2DRGBA8I >();
		testImage< UImg2DRGBA8U >();
		testImage< UImg3DRGBA32F >();
		testImage< UImg3DRGBA8I >();
		testImage< UImg3DRGBA8U >();
		testImage< UImgRectRGBA32F >();
		testImage< UImgRectRGBA8I >();
		testImage< UImgRectRGBA8U >();
		testImage< UImgCubeRGBA32F >();
		testImage< UImgCubeRGBA8I >();
		testImage< UImgCubeRGBA8U >();
		testImage< UImgBufferRGBA32F >();
		testImage< UImgBufferRGBA8I >();
		testImage< UImgBufferRGBA8U >();
		testImage< UImg1DArrayRGBA32F >();
		testImage< UImg1DArrayRGBA8I >();
		testImage< UImg1DArrayRGBA8U >();
		testImage< UImg2DArrayRGBA32F >();
		testImage< UImg2DArrayRGBA8I >();
		testImage< UImg2DArrayRGBA8U >();
		testImage< UImgCubeArrayRGBA32F >();
		testImage< UImgCubeArrayRGBA8I >();
		testImage< UImgCubeArrayRGBA8U >();
		testEnd();
	}

	void testUbos()
	{
		testBegin( "testUbos" );
		sdw::ShaderWriter writer{ false };
		testUbo< sdw::Int >();
		testUbo< sdw::UInt >();
		testUbo< sdw::Float >();
		testUbo< sdw::Double >();
		testUbo< sdw::Vec2 >();
		testUbo< sdw::Vec3 >();
		testUbo< sdw::Vec4 >();
		testUbo< sdw::DVec2 >();
		testUbo< sdw::DVec3 >();
		testUbo< sdw::DVec4 >();
		testUbo< sdw::IVec2 >();
		testUbo< sdw::IVec3 >();
		testUbo< sdw::IVec4 >();
		testUbo< sdw::UVec2 >();
		testUbo< sdw::UVec3 >();
		testUbo< sdw::UVec4 >();
		testUbo< sdw::Mat2 >();
		testUbo< sdw::Mat2x3 >();
		testUbo< sdw::Mat2x4 >();
		testUbo< sdw::Mat3 >();
		testUbo< sdw::Mat3x2 >();
		testUbo< sdw::Mat3x4 >();
		testUbo< sdw::Mat4 >();
		testUbo< sdw::Mat4x2 >();
		testUbo< sdw::Mat4x3 >();
		testUbo< sdw::DMat2 >();
		testUbo< sdw::DMat2x3 >();
		testUbo< sdw::DMat2x4 >();
		testUbo< sdw::DMat3 >();
		testUbo< sdw::DMat3x2 >();
		testUbo< sdw::DMat3x4 >();
		testUbo< sdw::DMat4 >();
		testUbo< sdw::DMat4x2 >();
		testUbo< sdw::DMat4x3 >();
		testEnd();
	}

	void testSsbos()
	{
		testBegin( "testSsbos" );
		sdw::ShaderWriter writer{ false };
		testSsbo< sdw::Int >();
		testSsbo< sdw::UInt >();
		testSsbo< sdw::Float >();
		testSsbo< sdw::Double >();
		testSsbo< sdw::Vec2 >();
		testSsbo< sdw::Vec3 >();
		testSsbo< sdw::Vec4 >();
		testSsbo< sdw::DVec2 >();
		testSsbo< sdw::DVec3 >();
		testSsbo< sdw::DVec4 >();
		testSsbo< sdw::IVec2 >();
		testSsbo< sdw::IVec3 >();
		testSsbo< sdw::IVec4 >();
		testSsbo< sdw::UVec2 >();
		testSsbo< sdw::UVec3 >();
		testSsbo< sdw::UVec4 >();
		testSsbo< sdw::Mat2 >();
		testSsbo< sdw::Mat2x3 >();
		testSsbo< sdw::Mat2x4 >();
		testSsbo< sdw::Mat3 >();
		testSsbo< sdw::Mat3x2 >();
		testSsbo< sdw::Mat3x4 >();
		testSsbo< sdw::Mat4 >();
		testSsbo< sdw::Mat4x2 >();
		testSsbo< sdw::Mat4x3 >();
		testSsbo< sdw::DMat2 >();
		testSsbo< sdw::DMat2x3 >();
		testSsbo< sdw::DMat2x4 >();
		testSsbo< sdw::DMat3 >();
		testSsbo< sdw::DMat3x2 >();
		testSsbo< sdw::DMat3x4 >();
		testSsbo< sdw::DMat4 >();
		testSsbo< sdw::DMat4x2 >();
		testSsbo< sdw::DMat4x3 >();
		testEnd();
	}

	void testPcbs()
	{
		testBegin( "testPcbs" );
		sdw::ShaderWriter writer{ false };
		testPcb< sdw::Int >();
		testPcb< sdw::UInt >();
		testPcb< sdw::Float >();
		testPcb< sdw::Double >();
		testPcb< sdw::Vec2 >();
		testPcb< sdw::Vec3 >();
		testPcb< sdw::Vec4 >();
		testPcb< sdw::DVec2 >();
		testPcb< sdw::DVec3 >();
		testPcb< sdw::DVec4 >();
		testPcb< sdw::IVec2 >();
		testPcb< sdw::IVec3 >();
		testPcb< sdw::IVec4 >();
		testPcb< sdw::UVec2 >();
		testPcb< sdw::UVec3 >();
		testPcb< sdw::UVec4 >();
		testPcb< sdw::Mat2 >();
		testPcb< sdw::Mat2x3 >();
		testPcb< sdw::Mat2x4 >();
		testPcb< sdw::Mat3 >();
		testPcb< sdw::Mat3x2 >();
		testPcb< sdw::Mat3x4 >();
		testPcb< sdw::Mat4 >();
		testPcb< sdw::Mat4x2 >();
		testPcb< sdw::Mat4x3 >();
		testPcb< sdw::DMat2 >();
		testPcb< sdw::DMat2x3 >();
		testPcb< sdw::DMat2x4 >();
		testPcb< sdw::DMat3 >();
		testPcb< sdw::DMat3x2 >();
		testPcb< sdw::DMat3x4 >();
		testPcb< sdw::DMat4 >();
		testPcb< sdw::DMat4x2 >();
		testPcb< sdw::DMat4x3 >();
		testEnd();
	}

	void testStructs()
	{
		testBegin( "testStructs" );
		sdw::ShaderWriter writer{ false };
		testStruct< sdw::Boolean >();
		testStruct< sdw::Int >();
		testStruct< sdw::UInt >();
		testStruct< sdw::Float >();
		testStruct< sdw::Double >();
		testStruct< sdw::Vec2 >();
		testStruct< sdw::Vec3 >();
		testStruct< sdw::Vec4 >();
		testStruct< sdw::DVec2 >();
		testStruct< sdw::DVec3 >();
		testStruct< sdw::DVec4 >();
		testStruct< sdw::BVec2 >();
		testStruct< sdw::BVec3 >();
		testStruct< sdw::BVec4 >();
		testStruct< sdw::IVec2 >();
		testStruct< sdw::IVec3 >();
		testStruct< sdw::IVec4 >();
		testStruct< sdw::UVec2 >();
		testStruct< sdw::UVec3 >();
		testStruct< sdw::UVec4 >();
		testStruct< sdw::Mat2 >();
		testStruct< sdw::Mat2x3 >();
		testStruct< sdw::Mat2x4 >();
		testStruct< sdw::Mat3 >();
		testStruct< sdw::Mat3x2 >();
		testStruct< sdw::Mat3x4 >();
		testStruct< sdw::Mat4 >();
		testStruct< sdw::Mat4x2 >();
		testStruct< sdw::Mat4x3 >();
		testStruct< sdw::DMat2 >();
		testStruct< sdw::DMat2x3 >();
		testStruct< sdw::DMat2x4 >();
		testStruct< sdw::DMat3 >();
		testStruct< sdw::DMat3x2 >();
		testStruct< sdw::DMat3x4 >();
		testStruct< sdw::DMat4 >();
		testStruct< sdw::DMat4x2 >();
		testStruct< sdw::DMat4x3 >();
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterDeclarations" );
	testUbos();
	testConstants();
	testSpecConstants();
	testShaderInputs();
	testShaderOutputs();
	testLocales();
	testBuiltins();
	testSampledImages();
	testImages();
	testSsbos();
	testPcbs();
	testStructs();
	testSuiteEnd();
}
