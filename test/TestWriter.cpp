#include "Common.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>
#include <ShaderWriter/Mat2.hpp>
#include <ShaderWriter/Mat3.hpp>
#include <ShaderWriter/Mat4.hpp>
#include <ShaderWriter/Sampler.hpp>
#include <ShaderWriter/Shader.hpp>

namespace
{
	template< typename T >
	void testInput( sdw::Shader & shader )
	{
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "InputValue_0";
			auto value = shader.declInput< T >( name, 0u );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::NotArray );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "InputValue_1";
			auto value = shader.declInputArray< T >( name, 1u, 12u );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == 12u );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "InputValue_2";
			auto value = shader.declInputArray< T >( name, 2u );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::UnknownArraySize );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
		{
			sdw::Shader shader;
			auto value = shader.declInput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::NotArray );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == "value" );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			check( shader.getStatements()->getStatements().empty() );
		}
		{
			sdw::Shader shader;
			auto value = shader.declInputArray< T >( "value", 1u, 12u, false );
			check( !value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == 12u );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == "value" );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			check( shader.getStatements()->getStatements().empty() );
		}
		{
			sdw::Shader shader;
			auto value = shader.declInputArray< T >( "value", 2u, false );
			check( !value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::UnknownArraySize );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == "value" );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			check( shader.getStatements()->getStatements().empty() );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "InputValue_0_opt";
			auto value = shader.declInput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::NotArray );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "InputValue_1_opt";
			auto value = shader.declInputArray< T >( name, 1u, 12u, true );
			check( value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == 12u );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "InputValue_2_opt";
			auto value = shader.declInputArray< T >( name, 2u, true );
			check( value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::UnknownArraySize );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
	}
	
	template< typename T >
	void testOutput( sdw::Shader & shader )
	{
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "OutputValue_0";
			auto value = shader.declOutput< T >( name, 0u );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::NotArray );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "OutputValue_1";
			auto value = shader.declOutputArray< T >( name, 1u, 12u );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == 12u );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "OutputValue_2";
			auto value = shader.declOutputArray< T >( name, 2u );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::UnknownArraySize );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
		{
			sdw::Shader shader;
			auto value = shader.declOutput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::NotArray );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == "value" );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->getStatements().empty() );
		}
		{
			sdw::Shader shader;
			auto value = shader.declOutputArray< T >( "value", 1u, 12u, false );
			check( !value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == 12u );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == "value" );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->getStatements().empty() );
		}
		{
			sdw::Shader shader;
			auto value = shader.declOutputArray< T >( "value", 2u, false );
			check( !value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::UnknownArraySize );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == "value" );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->getStatements().empty() );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "OutputValue_0_opt";
			auto value = shader.declOutput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::NotArray );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "OutputValue_1_opt";
			auto value = shader.declOutputArray< T >( name, 1u, 12u, true );
			check( value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == 12u );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
		}
		{
			auto name = ast::debug::getName( sdw::TypeTraits< T >::TypeEnum ) + "OutputValue_2_opt";
			auto value = shader.declOutputArray< T >( name, 2u, true );
			check( value.isEnabled() );
			check( value.m_expr->get()->getKind() == sdw::TypeTraits< T >::TypeEnum );
			check( value.m_expr->get()->getArraySize() == ast::type::UnknownArraySize );
			check( value.m_expr->getKind() == ast::expr::Kind::eIdentifier );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->getName() == name );
			check( static_cast< ast::expr::Identifier const & >( *value.m_expr ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->getStatements().back();
			check( stmt.getKind() == ast::stmt::Kind::eInOutVariableDecl );
			check( static_cast< ast::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
		}
	}

	void testDeclarations()
	{
		testBegin( "testDeclarations" );
		sdw::Shader shader;
		testInput< sdw::Boolean >( shader );
		testInput< sdw::Int >( shader );
		testInput< sdw::UInt >( shader );
		testInput< sdw::Float >( shader );
		testInput< sdw::Vec2 >( shader );
		testInput< sdw::Vec3 >( shader );
		testInput< sdw::Vec4 >( shader );
		testInput< sdw::BVec2 >( shader );
		testInput< sdw::BVec3 >( shader );
		testInput< sdw::BVec4 >( shader );
		testInput< sdw::IVec2 >( shader );
		testInput< sdw::IVec3 >( shader );
		testInput< sdw::IVec4 >( shader );
		testInput< sdw::UVec2 >( shader );
		testInput< sdw::UVec3 >( shader );
		testInput< sdw::UVec4 >( shader );
		testInput< sdw::Mat2 >( shader );
		testInput< sdw::Mat3 >( shader );
		testInput< sdw::Mat4 >( shader );
		testInput< sdw::BMat2 >( shader );
		testInput< sdw::BMat3 >( shader );
		testInput< sdw::BMat4 >( shader );
		testInput< sdw::IMat2 >( shader );
		testInput< sdw::IMat3 >( shader );
		testInput< sdw::IMat4 >( shader );
		testInput< sdw::UMat2 >( shader );
		testInput< sdw::UMat3 >( shader );
		testInput< sdw::UMat4 >( shader );

		testOutput< sdw::Boolean >( shader );
		testOutput< sdw::Int >( shader );
		testOutput< sdw::UInt >( shader );
		testOutput< sdw::Float >( shader );
		testOutput< sdw::Vec2 >( shader );
		testOutput< sdw::Vec3 >( shader );
		testOutput< sdw::Vec4 >( shader );
		testOutput< sdw::BVec2 >( shader );
		testOutput< sdw::BVec3 >( shader );
		testOutput< sdw::BVec4 >( shader );
		testOutput< sdw::IVec2 >( shader );
		testOutput< sdw::IVec3 >( shader );
		testOutput< sdw::IVec4 >( shader );
		testOutput< sdw::UVec2 >( shader );
		testOutput< sdw::UVec3 >( shader );
		testOutput< sdw::UVec4 >( shader );
		testOutput< sdw::Mat2 >( shader );
		testOutput< sdw::Mat3 >( shader );
		testOutput< sdw::Mat4 >( shader );
		testOutput< sdw::BMat2 >( shader );
		testOutput< sdw::BMat3 >( shader );
		testOutput< sdw::BMat4 >( shader );
		testOutput< sdw::IMat2 >( shader );
		testOutput< sdw::IMat3 >( shader );
		testOutput< sdw::IMat4 >( shader );
		testOutput< sdw::UMat2 >( shader );
		testOutput< sdw::UMat3 >( shader );
		testOutput< sdw::UMat4 >( shader );
		std::cout << ast::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}

	void testDeclarationStatements()
	{
		testBegin( "testDeclarations" );
		sdw::Shader shader;
		auto InVec2_0 = shader.declInput< sdw::Vec2 >( "InVec2_0", 0u );
		auto InVec3_1 = shader.declInput< sdw::Vec3 >( "InVec3_1", 1u );
		auto InVec4_2 = shader.declInput< sdw::Vec4 >( "InVec3_2", 2u );
		auto OutVec2_0 = shader.declOutput< sdw::Vec2 >( "OutVec2_0", 0u );
		auto OutVec2_1 = shader.declOutput< sdw::Vec2 >( "OutVec2_1", 1u );
		auto BuiltinVec4 = shader.declBuiltin< sdw::Vec4 >( "BuiltinVec4" );
		auto Sampler_0_0 = shader.declSampler< sdw::SamplerType::e1D >( "Sampler_0_0", 0u, 0u );
		auto Sampler_0_1 = shader.declSampler< sdw::SamplerType::e2D >( "Sampler_0_1", 0u, 1u );
		auto Sampler_1_0 = shader.declSampler< sdw::SamplerType::eCubeArray >( "Sampler_1_0", 1u, 0u );
		InVec2_0.x();
		InVec3_1.y();
		InVec4_2.z();
		InVec2_0[0];
		InVec3_1[0];
		InVec4_2[0];
		InVec2_0 = InVec4_2.xy();
		InVec3_1 = InVec4_2.xyz();
		InVec4_2 = BuiltinVec4;
		InVec2_0 * InVec2_0;
		InVec3_1 * InVec3_1;
		InVec4_2 * InVec4_2;
		std::cout << ast::debug::StmtVisitor::submit( shader.getStatements() ) << std::endl;
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriter" );
	testDeclarations();
	testSuiteEnd();
}
