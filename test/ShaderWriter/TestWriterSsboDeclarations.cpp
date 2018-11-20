#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ASTGenerator/Debug/DebugCommon.hpp>
#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>
#include <ShaderWriter/Intrinsics.hpp>
#include <ShaderWriter/Sampler.hpp>
#include <ShaderWriter/Shader.hpp>
#include <ShaderWriter/StructuredSsbo.hpp>
#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

namespace
{
#define DummyMain writer.implementFunction< void >( "main", [](){} )

	template< typename T >
	void testSsbo( test::TestCounts & testCounts )
	{
		testBegin( "testSsbo" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type" };
			type.declMember< T >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "SSBO", type, 1u, 1u };
			auto value = bo[0].getMember< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type" };
			type.declMember< T >( name, 4u );
			type.end();
			sdw::StructuredSsbo bo{ writer, "SSBO", type, 1u, 1u };
			auto value = bo[0].getMember< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterSsboDeclarations" );
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
	testSuiteEnd();
}
