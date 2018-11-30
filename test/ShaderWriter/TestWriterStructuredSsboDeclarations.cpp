#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain writer.implementFunction< void >( "main", [](){} )

	template< typename T >
	void testStructuredSsbo( test::TestCounts & testCounts )
	{
		testBegin( "testStructuredSsbo" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			auto value = bo[0].getMember< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			auto value = bo[0].getMember< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterSsboDeclarations" );
	testStructuredSsbo< sdw::Int >( testCounts );
	testStructuredSsbo< sdw::UInt >( testCounts );
	testStructuredSsbo< sdw::Float >( testCounts );
	testStructuredSsbo< sdw::Double >( testCounts );
	testStructuredSsbo< sdw::Vec2 >( testCounts );
	testStructuredSsbo< sdw::Vec3 >( testCounts );
	testStructuredSsbo< sdw::Vec4 >( testCounts );
	testStructuredSsbo< sdw::DVec2 >( testCounts );
	testStructuredSsbo< sdw::DVec3 >( testCounts );
	testStructuredSsbo< sdw::DVec4 >( testCounts );
	testStructuredSsbo< sdw::IVec2 >( testCounts );
	testStructuredSsbo< sdw::IVec3 >( testCounts );
	testStructuredSsbo< sdw::IVec4 >( testCounts );
	testStructuredSsbo< sdw::UVec2 >( testCounts );
	testStructuredSsbo< sdw::UVec3 >( testCounts );
	testStructuredSsbo< sdw::UVec4 >( testCounts );
	testStructuredSsbo< sdw::Mat2 >( testCounts );
	testStructuredSsbo< sdw::Mat2x3 >( testCounts );
	testStructuredSsbo< sdw::Mat2x4 >( testCounts );
	testStructuredSsbo< sdw::Mat3 >( testCounts );
	testStructuredSsbo< sdw::Mat3x2 >( testCounts );
	testStructuredSsbo< sdw::Mat3x4 >( testCounts );
	testStructuredSsbo< sdw::Mat4 >( testCounts );
	testStructuredSsbo< sdw::Mat4x2 >( testCounts );
	testStructuredSsbo< sdw::Mat4x3 >( testCounts );
	testStructuredSsbo< sdw::DMat2 >( testCounts );
	testStructuredSsbo< sdw::DMat2x3 >( testCounts );
	testStructuredSsbo< sdw::DMat2x4 >( testCounts );
	testStructuredSsbo< sdw::DMat3 >( testCounts );
	testStructuredSsbo< sdw::DMat3x2 >( testCounts );
	testStructuredSsbo< sdw::DMat3x4 >( testCounts );
	testStructuredSsbo< sdw::DMat4 >( testCounts );
	testStructuredSsbo< sdw::DMat4x2 >( testCounts );
	testStructuredSsbo< sdw::DMat4x3 >( testCounts );
	testSuiteEnd();
}
