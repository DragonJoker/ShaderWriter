#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/Ubo.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	template< typename T >
	void testUboRaw( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUboRaw" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ubo bo{ writer, "UBO", 1u, 1u };
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
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testUboRawArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUboRawArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ubo bo{ writer, "UBO", 1u, 1u };
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
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testUboRawOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUboRawOptionalDisabled" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDis" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ubo bo{ writer, "UBO", 1u, 1u };
			auto value = bo.template declMember< T >( name, false );
			bo.end();
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, false );
			check( !retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testUboRawOptionalDisabledArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUboRawOptionalDisabledArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDisArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ubo bo{ writer, "UBO", 1u, 1u };
			auto value = bo.template declMember< T >( name, 4u, false );
			bo.end();
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			check( !retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testUboRawOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUboRawOptionalEnabled" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEn" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ubo bo{ writer, "UBO", 1u, 1u };
			auto value = bo.template declMember< T >( name, true );
			bo.end();
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, true );
			check( retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testUboRawOptionalEnabledArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUboRawOptionalEnabledArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEnArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Ubo bo{ writer, "UBO", 1u, 1u };
			auto value = bo.template declMember< T >( name, 4u, true );
			bo.end();
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			check( retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testUboHelper( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testUboHelper" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			sdw::UboHelperStd140T< sdw::StructFieldT< T, "member" > > bo{ writer, "UBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();

#endif
	}

	template< typename T >
	void testUboHelperArray( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testUboHelperArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			sdw::UboHelperStd140T< sdw::StructFieldArrayT< T, "member", 4u > > bo{ writer, "UBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();

#endif
	}

	template< typename T >
	void testUbo( test::sdw_test::TestCounts & testCounts )
	{
		testUboRaw< T >( testCounts );
		testUboRawArray< T >( testCounts );
		testUboRawOptionalDisabled< T >( testCounts );
		testUboRawOptionalDisabledArray< T >( testCounts );
		testUboRawOptionalEnabled< T >( testCounts );
		testUboRawOptionalEnabledArray< T >( testCounts );
		testUboHelper< T >( testCounts );
		testUboHelperArray< T >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterUboDeclarations )
{
	sdwTestSuiteBegin();
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
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterUboDeclarations )
