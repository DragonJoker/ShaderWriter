#include "Common.hpp"
#include "TestWriterCommon.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>
#include <ShaderWriter/Intrinsics.hpp>
#include <ShaderWriter/Sampler.hpp>
#include <ShaderWriter/Shader.hpp>

namespace
{
	template< typename T >
	void testConstant( sdw::ShaderWriter & writer )
	{
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( shader ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declConstant< T >( "value", test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue_opt";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
		}
	}

	template< typename T >
	void testSpecConstant( sdw::ShaderWriter & writer )
	{
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_0";
			auto value = writer.declSpecConstant< T >( name, 0u, test::getDefault< T >( shader ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declSpecConstant< T >( "value", 1u, test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_2_opt";
			auto value = writer.declSpecConstant< T >( name, 2u, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
	}

	template< typename T >
	void testShaderInput( sdw::ShaderWriter & writer )
	{
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_0";
			auto value = writer.declInput< T >( name, 0u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_1";
			auto value = writer.declInputArray< T >( name, 1u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_2";
			auto value = writer.declInputArray< T >( name, 2u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declInput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declInputArray< T >( "value", 1u, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declInputArray< T >( "value", 2u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "InputValue_0_opt";
			auto value = writer.declInput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
	}

	template< typename T >
	void testShaderOutput( sdw::ShaderWriter & writer )
	{
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0";
			auto value = writer.declOutput< T >( name, 0u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1";
			auto value = writer.declOutputArray< T >( name, 1u, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_2";
			auto value = writer.declOutputArray< T >( name, 2u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declOutput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declOutputArray< T >( "value", 1u, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declOutputArray< T >( "value", 2u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0_opt";
			auto value = writer.declOutput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
	}

	template< typename T >
	void testLocale( sdw::ShaderWriter & writer )
	{
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue";
			auto value = writer.declLocale< T >( name );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned";
			auto value = writer.declLocale< T >( name, test::getDefault< T >( shader ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue";
			auto value = writer.declLocaleArray< T >( name, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue";
			auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultArray< T >( shader, 3u ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 3u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declLocale< T >( "value", false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declLocale< T >( "value", sdw::Optional< T >{ test::getDefault< T >( shader ), false } );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declLocale< T >( "value", test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declLocaleArray< T >( "value", 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declLocaleArray< T >( "value", 3u, test::getDefaultArray< T >( shader, 3u ), false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 3u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue_opt";
			auto value = writer.declLocale< T >( name, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned_opt";
			auto value = writer.declLocale< T >( name, sdw::Optional< T >{ test::getDefault< T >( shader ), true } );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned_opt";
			auto value = writer.declLocale< T >( name, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue_opt";
			auto value = writer.declLocaleArray< T >( name, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue_opt";
			auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultArray< T >( shader, 3u ), true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 3u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
	}

	template< typename T >
	void testBuiltin( sdw::ShaderWriter & writer )
	{
		auto & shader = writer.getShader();
		auto count = shader.getStatements()->getStatements().size();
		{
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue";
			auto value = writer.declBuiltin< T >( name );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue";
			auto value = writer.declBuiltinArray< T >( name, 12u );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue";
			auto value = writer.declBuiltinArray< T >( name );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto value = writer.declBuiltin< T >( "value", false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto value = writer.declBuiltinArray< T >( "value", 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto value = writer.declBuiltinArray< T >( "value", false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue_opt";
			auto value = writer.declBuiltin< T >( name, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue_opt";
			auto value = writer.declBuiltinArray< T >( name, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BuiltinValue_opt";
			auto value = writer.declBuiltinArray< T >( name, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBuiltin() );
			check( shader.getStatements()->getStatements().size() == count );
		}
	}

	template< sdw::SamplerType ST >
	void testSampler( sdw::ShaderWriter & writer )
	{
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::SamplerTypeTraits< ST >::TypeEnum ) + "SamplerValue_1_1";
			auto value = writer.declSampler< ST >( name, 1u, 1u );
			check( value.getType()->getKind() == sdw::SamplerTypeTraits< ST >::TypeEnum );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSampler() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingSet() == 1u );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::SamplerTypeTraits< ST >::TypeEnum ) + "SamplerValue_2_2";
			auto value = writer.declSamplerArray< ST >( name, 2u, 2u, 12u );
			check( value.getType()->getKind() == sdw::SamplerTypeTraits< ST >::TypeEnum );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSampler() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingSet() == 2u );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declSampler< ST >( "value", 1u, 1u, false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::SamplerTypeTraits< ST >::TypeEnum );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSampler() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			sdw::ShaderWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->getStatements().size();
			auto value = writer.declSamplerArray< ST >( "value", 1u, 1u, 12u, false );
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::SamplerTypeTraits< ST >::TypeEnum );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSampler() );
			check( shader.getStatements()->getStatements().size() == count );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::SamplerTypeTraits< ST >::TypeEnum ) + "SamplerValue_1_1_opt";
			auto value = writer.declSampler< ST >( name, 1u, 1u, true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::SamplerTypeTraits< ST >::TypeEnum );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSampler() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingSet() == 1u );
		}
		{
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::SamplerTypeTraits< ST >::TypeEnum ) + "SamplerValue_2_2_opt";
			auto value = writer.declSamplerArray< ST >( name, 2u, 2u, 12u, true );
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::SamplerTypeTraits< ST >::TypeEnum );
			check( value.getType()->getArraySize() == 12u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isSampler() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eSamplerDecl );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingPoint() == 2u );
			check( static_cast< sdw::stmt::SamplerDecl const & >( stmt ).getBindingSet() == 2u );
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
		check( stmt.getBindingSet() == 1u );
	}
	void checkBoStmt( sdw::stmt::ConstantBufferDecl const & stmt )
	{
		check( stmt.getBindingPoint() == 1u );
		check( stmt.getBindingSet() == 1u );
	}
	void checkBoStmt( sdw::stmt::PushConstantsBufferDecl const & stmt )
	{
	}

	template< typename BOType, typename StmtType, sdw::stmt::Kind StmtKind, typename T >
	void testBo( sdw::ShaderWriter & writer )
	{
		auto & shader = writer.getShader();
		{
			std::string const name = "m_member";
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberArray";
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, 4u );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberArrayUnknown";
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberOptDis";
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberOptDisArray";
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, 4u, false );
			bo.end();
			check( !value.isEnabled() );
			check( !value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, 4u, false );
			check( !retrieved.isEnabled() );
			check( !retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberOptDisArrayUnknown";
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberOptEn";
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberOptEnArray";
			BOType bo{ createBo< BOType >( writer ) };
			auto value = bo.template declMember< T >( name, 4u, true );
			bo.end();
			check( value.isEnabled() );
			check( value[0].isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == 4u );
			check( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, 4u, true );
			check( retrieved.isEnabled() );
			check( retrieved[0].isEnabled() );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
		{
			std::string const name = "m_memberOptEnArrayUnknown";
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
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == StmtKind );
			checkBoStmt( static_cast< StmtType const & >( stmt ) );
		}
	}

	template< typename T >
	void testUbo( sdw::ShaderWriter & writer )
	{
		testBo< sdw::Ubo, sdw::stmt::ConstantBufferDecl, sdw::stmt::Kind::eConstantBufferDecl, T >( writer );
	}

	template< typename T >
	void testSsbo( sdw::ShaderWriter & writer )
	{
		testBo< sdw::Ssbo, sdw::stmt::ShaderBufferDecl, sdw::stmt::Kind::eShaderBufferDecl, T >( writer );
	}

	template< typename T >
	void testPcb( sdw::ShaderWriter & writer )
	{
		testBo< sdw::Pcb, sdw::stmt::PushConstantsBufferDecl, sdw::stmt::Kind::ePushConstantsBufferDecl, T >( writer );
	}

	template< typename T >
	void testStruct( sdw::ShaderWriter & writer )
	{
		auto & shader = writer.getShader();
		{
			std::string const name = "m_member";
			sdw::Struct st{ writer, "ST" };
			st.declMember< T >( name );
			st.end();
			auto instance = st.getInstance( "st" );
			auto retrieved = instance.getMember< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::NotArray );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
		}
		{
			std::string const name = "m_memberArray";
			sdw::Struct st{ writer, "ST" };
			st.declMember< T >( name, 4u );
			st.end();
			auto instance = st.getInstance( "st" );
			auto retrieved = instance.getMember< T >( name, 4u );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
		}
		{
			std::string const name = "m_memberArrayUnknown";
			sdw::Struct st{ writer, "ST" };
			st.declMemberArray< T >( name );
			st.end();
			auto instance = st.getInstance( "st" );
			auto retrieved = instance.getMemberArray< T >( name );
			check( retrieved.getType()->getKind() == sdw::typeEnum< T > );
			check( retrieved.getType()->getArraySize() == sdw::type::UnknownArraySize );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
		}
	}
	void testConstants()
	{
		testBegin( "testConstants" );
		sdw::ShaderWriter writer{ false };
		testConstant< sdw::Boolean >( writer );
		testConstant< sdw::Int >( writer );
		testConstant< sdw::UInt >( writer );
		testConstant< sdw::Float >( writer );
		testConstant< sdw::Vec2 >( writer );
		testConstant< sdw::Vec3 >( writer );
		testConstant< sdw::Vec4 >( writer );
		testConstant< sdw::BVec2 >( writer );
		testConstant< sdw::BVec3 >( writer );
		testConstant< sdw::BVec4 >( writer );
		testConstant< sdw::IVec2 >( writer );
		testConstant< sdw::IVec3 >( writer );
		testConstant< sdw::IVec4 >( writer );
		testConstant< sdw::UVec2 >( writer );
		testConstant< sdw::UVec3 >( writer );
		testConstant< sdw::UVec4 >( writer );
		testConstant< sdw::Mat2 >( writer );
		testConstant< sdw::Mat3 >( writer );
		testConstant< sdw::Mat4 >( writer );
		testConstant< sdw::BMat2 >( writer );
		testConstant< sdw::BMat3 >( writer );
		testConstant< sdw::BMat4 >( writer );
		testConstant< sdw::IMat2 >( writer );
		testConstant< sdw::IMat3 >( writer );
		testConstant< sdw::IMat4 >( writer );
		testConstant< sdw::UMat2 >( writer );
		testConstant< sdw::UMat3 >( writer );
		testConstant< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testSpecConstants()
	{
		testBegin( "testSpecConstants" );
		sdw::ShaderWriter writer{ false };
		testSpecConstant< sdw::Boolean >( writer );
		testSpecConstant< sdw::Int >( writer );
		testSpecConstant< sdw::UInt >( writer );
		testSpecConstant< sdw::Float >( writer );
		testSpecConstant< sdw::Vec2 >( writer );
		testSpecConstant< sdw::Vec3 >( writer );
		testSpecConstant< sdw::Vec4 >( writer );
		testSpecConstant< sdw::BVec2 >( writer );
		testSpecConstant< sdw::BVec3 >( writer );
		testSpecConstant< sdw::BVec4 >( writer );
		testSpecConstant< sdw::IVec2 >( writer );
		testSpecConstant< sdw::IVec3 >( writer );
		testSpecConstant< sdw::IVec4 >( writer );
		testSpecConstant< sdw::UVec2 >( writer );
		testSpecConstant< sdw::UVec3 >( writer );
		testSpecConstant< sdw::UVec4 >( writer );
		testSpecConstant< sdw::Mat2 >( writer );
		testSpecConstant< sdw::Mat3 >( writer );
		testSpecConstant< sdw::Mat4 >( writer );
		testSpecConstant< sdw::BMat2 >( writer );
		testSpecConstant< sdw::BMat3 >( writer );
		testSpecConstant< sdw::BMat4 >( writer );
		testSpecConstant< sdw::IMat2 >( writer );
		testSpecConstant< sdw::IMat3 >( writer );
		testSpecConstant< sdw::IMat4 >( writer );
		testSpecConstant< sdw::UMat2 >( writer );
		testSpecConstant< sdw::UMat3 >( writer );
		testSpecConstant< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testShaderInputs()
	{
		testBegin( "testShaderInputs" );
		sdw::ShaderWriter writer{ false };
		testShaderInput< sdw::Boolean >( writer );
		testShaderInput< sdw::Int >( writer );
		testShaderInput< sdw::UInt >( writer );
		testShaderInput< sdw::Float >( writer );
		testShaderInput< sdw::Vec2 >( writer );
		testShaderInput< sdw::Vec3 >( writer );
		testShaderInput< sdw::Vec4 >( writer );
		testShaderInput< sdw::BVec2 >( writer );
		testShaderInput< sdw::BVec3 >( writer );
		testShaderInput< sdw::BVec4 >( writer );
		testShaderInput< sdw::IVec2 >( writer );
		testShaderInput< sdw::IVec3 >( writer );
		testShaderInput< sdw::IVec4 >( writer );
		testShaderInput< sdw::UVec2 >( writer );
		testShaderInput< sdw::UVec3 >( writer );
		testShaderInput< sdw::UVec4 >( writer );
		testShaderInput< sdw::Mat2 >( writer );
		testShaderInput< sdw::Mat3 >( writer );
		testShaderInput< sdw::Mat4 >( writer );
		testShaderInput< sdw::BMat2 >( writer );
		testShaderInput< sdw::BMat3 >( writer );
		testShaderInput< sdw::BMat4 >( writer );
		testShaderInput< sdw::IMat2 >( writer );
		testShaderInput< sdw::IMat3 >( writer );
		testShaderInput< sdw::IMat4 >( writer );
		testShaderInput< sdw::UMat2 >( writer );
		testShaderInput< sdw::UMat3 >( writer );
		testShaderInput< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testShaderOutputs()
	{
		testBegin( "testShaderOutputs" );
		sdw::ShaderWriter writer{ false };
		testShaderOutput< sdw::Boolean >( writer );
		testShaderOutput< sdw::Int >( writer );
		testShaderOutput< sdw::UInt >( writer );
		testShaderOutput< sdw::Float >( writer );
		testShaderOutput< sdw::Vec2 >( writer );
		testShaderOutput< sdw::Vec3 >( writer );
		testShaderOutput< sdw::Vec4 >( writer );
		testShaderOutput< sdw::BVec2 >( writer );
		testShaderOutput< sdw::BVec3 >( writer );
		testShaderOutput< sdw::BVec4 >( writer );
		testShaderOutput< sdw::IVec2 >( writer );
		testShaderOutput< sdw::IVec3 >( writer );
		testShaderOutput< sdw::IVec4 >( writer );
		testShaderOutput< sdw::UVec2 >( writer );
		testShaderOutput< sdw::UVec3 >( writer );
		testShaderOutput< sdw::UVec4 >( writer );
		testShaderOutput< sdw::Mat2 >( writer );
		testShaderOutput< sdw::Mat3 >( writer );
		testShaderOutput< sdw::Mat4 >( writer );
		testShaderOutput< sdw::BMat2 >( writer );
		testShaderOutput< sdw::BMat3 >( writer );
		testShaderOutput< sdw::BMat4 >( writer );
		testShaderOutput< sdw::IMat2 >( writer );
		testShaderOutput< sdw::IMat3 >( writer );
		testShaderOutput< sdw::IMat4 >( writer );
		testShaderOutput< sdw::UMat2 >( writer );
		testShaderOutput< sdw::UMat3 >( writer );
		testShaderOutput< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testLocales()
	{
		testBegin( "testLocales" );
		sdw::ShaderWriter writer{ false };
		testLocale< sdw::Boolean >( writer );
		testLocale< sdw::Int >( writer );
		testLocale< sdw::UInt >( writer );
		testLocale< sdw::Float >( writer );
		testLocale< sdw::Vec2 >( writer );
		testLocale< sdw::Vec3 >( writer );
		testLocale< sdw::Vec4 >( writer );
		testLocale< sdw::BVec2 >( writer );
		testLocale< sdw::BVec3 >( writer );
		testLocale< sdw::BVec4 >( writer );
		testLocale< sdw::IVec2 >( writer );
		testLocale< sdw::IVec3 >( writer );
		testLocale< sdw::IVec4 >( writer );
		testLocale< sdw::UVec2 >( writer );
		testLocale< sdw::UVec3 >( writer );
		testLocale< sdw::UVec4 >( writer );
		testLocale< sdw::Mat2 >( writer );
		testLocale< sdw::Mat3 >( writer );
		testLocale< sdw::Mat4 >( writer );
		testLocale< sdw::BMat2 >( writer );
		testLocale< sdw::BMat3 >( writer );
		testLocale< sdw::BMat4 >( writer );
		testLocale< sdw::IMat2 >( writer );
		testLocale< sdw::IMat3 >( writer );
		testLocale< sdw::IMat4 >( writer );
		testLocale< sdw::UMat2 >( writer );
		testLocale< sdw::UMat3 >( writer );
		testLocale< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testBuiltins()
	{
		testBegin( "testBuiltins" );
		sdw::ShaderWriter writer{ false };
		testBuiltin< sdw::Boolean >( writer );
		testBuiltin< sdw::Int >( writer );
		testBuiltin< sdw::UInt >( writer );
		testBuiltin< sdw::Float >( writer );
		testBuiltin< sdw::Vec2 >( writer );
		testBuiltin< sdw::Vec3 >( writer );
		testBuiltin< sdw::Vec4 >( writer );
		testBuiltin< sdw::BVec2 >( writer );
		testBuiltin< sdw::BVec3 >( writer );
		testBuiltin< sdw::BVec4 >( writer );
		testBuiltin< sdw::IVec2 >( writer );
		testBuiltin< sdw::IVec3 >( writer );
		testBuiltin< sdw::IVec4 >( writer );
		testBuiltin< sdw::UVec2 >( writer );
		testBuiltin< sdw::UVec3 >( writer );
		testBuiltin< sdw::UVec4 >( writer );
		testBuiltin< sdw::Mat2 >( writer );
		testBuiltin< sdw::Mat3 >( writer );
		testBuiltin< sdw::Mat4 >( writer );
		testBuiltin< sdw::BMat2 >( writer );
		testBuiltin< sdw::BMat3 >( writer );
		testBuiltin< sdw::BMat4 >( writer );
		testBuiltin< sdw::IMat2 >( writer );
		testBuiltin< sdw::IMat3 >( writer );
		testBuiltin< sdw::IMat4 >( writer );
		testBuiltin< sdw::UMat2 >( writer );
		testBuiltin< sdw::UMat3 >( writer );
		testBuiltin< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testSamplers()
	{
		testBegin( "testSamplers" );
		sdw::ShaderWriter writer{ false };
		testSampler< sdw::SamplerType::eBuffer >( writer );
		testSampler< sdw::SamplerType::e1D >( writer );
		testSampler< sdw::SamplerType::e2D >( writer );
		testSampler< sdw::SamplerType::e3D >( writer );
		testSampler< sdw::SamplerType::eCube >( writer );
		testSampler< sdw::SamplerType::e2DRect >( writer );
		testSampler< sdw::SamplerType::e1DArray >( writer );
		testSampler< sdw::SamplerType::e2DArray >( writer );
		testSampler< sdw::SamplerType::eCubeArray >( writer );
		testSampler< sdw::SamplerType::e1DShadow >( writer );
		testSampler< sdw::SamplerType::e2DShadow >( writer );
		testSampler< sdw::SamplerType::eCubeShadow >( writer );
		testSampler< sdw::SamplerType::e2DRectShadow >( writer );
		testSampler< sdw::SamplerType::e1DArrayShadow >( writer );
		testSampler< sdw::SamplerType::e2DArrayShadow >( writer );
		testSampler< sdw::SamplerType::eCubeArrayShadow >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testUbos()
	{
		testBegin( "testUbos" );
		sdw::ShaderWriter writer{ false };
		testUbo< sdw::Boolean >( writer );
		testUbo< sdw::Int >( writer );
		testUbo< sdw::UInt >( writer );
		testUbo< sdw::Float >( writer );
		testUbo< sdw::Vec2 >( writer );
		testUbo< sdw::Vec3 >( writer );
		testUbo< sdw::Vec4 >( writer );
		testUbo< sdw::BVec2 >( writer );
		testUbo< sdw::BVec3 >( writer );
		testUbo< sdw::BVec4 >( writer );
		testUbo< sdw::IVec2 >( writer );
		testUbo< sdw::IVec3 >( writer );
		testUbo< sdw::IVec4 >( writer );
		testUbo< sdw::UVec2 >( writer );
		testUbo< sdw::UVec3 >( writer );
		testUbo< sdw::UVec4 >( writer );
		testUbo< sdw::Mat2 >( writer );
		testUbo< sdw::Mat3 >( writer );
		testUbo< sdw::Mat4 >( writer );
		testUbo< sdw::BMat2 >( writer );
		testUbo< sdw::BMat3 >( writer );
		testUbo< sdw::BMat4 >( writer );
		testUbo< sdw::IMat2 >( writer );
		testUbo< sdw::IMat3 >( writer );
		testUbo< sdw::IMat4 >( writer );
		testUbo< sdw::UMat2 >( writer );
		testUbo< sdw::UMat3 >( writer );
		testUbo< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testSsbos()
	{
		testBegin( "testSsbos" );
		sdw::ShaderWriter writer{ false };
		testSsbo< sdw::Boolean >( writer );
		testSsbo< sdw::Int >( writer );
		testSsbo< sdw::UInt >( writer );
		testSsbo< sdw::Float >( writer );
		testSsbo< sdw::Vec2 >( writer );
		testSsbo< sdw::Vec3 >( writer );
		testSsbo< sdw::Vec4 >( writer );
		testSsbo< sdw::BVec2 >( writer );
		testSsbo< sdw::BVec3 >( writer );
		testSsbo< sdw::BVec4 >( writer );
		testSsbo< sdw::IVec2 >( writer );
		testSsbo< sdw::IVec3 >( writer );
		testSsbo< sdw::IVec4 >( writer );
		testSsbo< sdw::UVec2 >( writer );
		testSsbo< sdw::UVec3 >( writer );
		testSsbo< sdw::UVec4 >( writer );
		testSsbo< sdw::Mat2 >( writer );
		testSsbo< sdw::Mat3 >( writer );
		testSsbo< sdw::Mat4 >( writer );
		testSsbo< sdw::BMat2 >( writer );
		testSsbo< sdw::BMat3 >( writer );
		testSsbo< sdw::BMat4 >( writer );
		testSsbo< sdw::IMat2 >( writer );
		testSsbo< sdw::IMat3 >( writer );
		testSsbo< sdw::IMat4 >( writer );
		testSsbo< sdw::UMat2 >( writer );
		testSsbo< sdw::UMat3 >( writer );
		testSsbo< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testPcbs()
	{
		testBegin( "testPcbs" );
		sdw::ShaderWriter writer{ false };
		testPcb< sdw::Boolean >( writer );
		testPcb< sdw::Int >( writer );
		testPcb< sdw::UInt >( writer );
		testPcb< sdw::Float >( writer );
		testPcb< sdw::Vec2 >( writer );
		testPcb< sdw::Vec3 >( writer );
		testPcb< sdw::Vec4 >( writer );
		testPcb< sdw::BVec2 >( writer );
		testPcb< sdw::BVec3 >( writer );
		testPcb< sdw::BVec4 >( writer );
		testPcb< sdw::IVec2 >( writer );
		testPcb< sdw::IVec3 >( writer );
		testPcb< sdw::IVec4 >( writer );
		testPcb< sdw::UVec2 >( writer );
		testPcb< sdw::UVec3 >( writer );
		testPcb< sdw::UVec4 >( writer );
		testPcb< sdw::Mat2 >( writer );
		testPcb< sdw::Mat3 >( writer );
		testPcb< sdw::Mat4 >( writer );
		testPcb< sdw::BMat2 >( writer );
		testPcb< sdw::BMat3 >( writer );
		testPcb< sdw::BMat4 >( writer );
		testPcb< sdw::IMat2 >( writer );
		testPcb< sdw::IMat3 >( writer );
		testPcb< sdw::IMat4 >( writer );
		testPcb< sdw::UMat2 >( writer );
		testPcb< sdw::UMat3 >( writer );
		testPcb< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}

	void testStructs()
	{
		testBegin( "testStructs" );
		sdw::ShaderWriter writer{ false };
		testStruct< sdw::Boolean >( writer );
		testStruct< sdw::Int >( writer );
		testStruct< sdw::UInt >( writer );
		testStruct< sdw::Float >( writer );
		testStruct< sdw::Vec2 >( writer );
		testStruct< sdw::Vec3 >( writer );
		testStruct< sdw::Vec4 >( writer );
		testStruct< sdw::BVec2 >( writer );
		testStruct< sdw::BVec3 >( writer );
		testStruct< sdw::BVec4 >( writer );
		testStruct< sdw::IVec2 >( writer );
		testStruct< sdw::IVec3 >( writer );
		testStruct< sdw::IVec4 >( writer );
		testStruct< sdw::UVec2 >( writer );
		testStruct< sdw::UVec3 >( writer );
		testStruct< sdw::UVec4 >( writer );
		testStruct< sdw::Mat2 >( writer );
		testStruct< sdw::Mat3 >( writer );
		testStruct< sdw::Mat4 >( writer );
		testStruct< sdw::BMat2 >( writer );
		testStruct< sdw::BMat3 >( writer );
		testStruct< sdw::BMat4 >( writer );
		testStruct< sdw::IMat2 >( writer );
		testStruct< sdw::IMat3 >( writer );
		testStruct< sdw::IMat4 >( writer );
		testStruct< sdw::UMat2 >( writer );
		testStruct< sdw::UMat3 >( writer );
		testStruct< sdw::UMat4 >( writer );
		std::cout << sdw::writeDebug( writer.getShader() ) << std::endl;
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterDeclarations" );
	testConstants();
	testSpecConstants();
	testShaderInputs();
	testShaderOutputs();
	testLocales();
	testBuiltins();
	testSamplers();
	testUbos();
	testSsbos();
	testPcbs();
	testStructs();
	testSuiteEnd();
}
