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
		testBegin( "testConstant" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( shader ) );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declConstant< T >( "value", test::getDefault< T >( shader ), false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue_opt";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( shader ), true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue4";
			auto value = writer.declConstantArray< T >( name, test::getDefaultVector< T >( shader, 4u ) );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declConstantArray< T >( "value", test::getDefaultVector< T >( shader, 4u ), false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "ConstantValue4_opt";
			auto value = writer.declConstantArray< T >( name, test::getDefaultVector< T >( shader, 4u ), true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::ePreprocDefine );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterConstantDeclarations" );
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
	testSuiteEnd();
}
