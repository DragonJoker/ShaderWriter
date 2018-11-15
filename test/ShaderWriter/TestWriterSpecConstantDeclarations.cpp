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
	void testSpecConstant( test::TestCounts & testCounts )
	{
		testBegin( "testSpecConstant" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_0";
			auto value = writer.declSpecConstant< T >( name, 0u, test::getDefault< T >( shader ) );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eInit );
			check( static_cast< sdw::expr::Init const & >( *value.getExpr() ).getIdentifier()->getVariable()->getName() == name );
			check( static_cast< sdw::expr::Init const & >( *value.getExpr() ).getIdentifier()->getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declSpecConstant< T >( "value", 1u, test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eInit );
			check( static_cast< sdw::expr::Init const & >( *value.getExpr() ).getIdentifier()->getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Init const & >( *value.getExpr() ).getIdentifier()->getVariable()->isShaderConstant() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "SpecConstantValue_2_opt";
			auto value = writer.declSpecConstant< T >( name, 2u, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( value.getType()->getKind() == sdw::typeEnum< T > );
			check( value.getType()->getArraySize() == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Init const & >( *value.getExpr() ).getIdentifier()->getVariable()->getName() == name );
			check( static_cast< sdw::expr::Init const & >( *value.getExpr() ).getIdentifier()->getVariable()->isShaderConstant() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 2u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterSpecConstantDeclarations" );
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
	testSuiteEnd();
}
