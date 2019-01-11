#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	template< typename T >
	void testSsbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSsbo" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ssbo bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementFunction< sdw::Void >( "main", [&]()
				{
					retrieved = test::getDefault< T >( writer.getShader() );
				} );
			test::writeShader( writer, testCounts, true, false );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ssbo bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementFunction< sdw::Void >( "main", [&]()
				{
					retrieved[0] = test::getDefault< T >( writer.getShader() );
				} );
			test::writeShader( writer, testCounts, true, false );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArrayUnknown" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ssbo bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMemberArray< T >( name );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementFunction< sdw::Void >( "main", [&]()
				{
					retrieved[0] = test::getDefault< T >( writer.getShader() );
				} );
			test::writeShader( writer, testCounts, true, false );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	sdwTestSuiteBegin( "TestWriterSsboDeclarations" );
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
	sdwTestSuiteEnd();
}
