#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	template< typename T >
	void testPcbRaw( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRaw" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Pcb bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
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
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Pcb bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
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
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalDisabled" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDis" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Pcb bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
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
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalDisabledArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalDisabledArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDisArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Pcb bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
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
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalEnabled" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEn" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Pcb bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
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
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalEnabledArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalEnabledArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEnArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Pcb bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
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
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcbHelper( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbHelper" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			sdw::PcbHelperStd140T< sdw::StructFieldT< T, "member" > > bo{ writer, "UBO" };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcbHelperArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbHelperArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			sdw::PcbHelperStd140T< sdw::StructFieldArrayT< T, "member", 4u > > bo{ writer, "UBO" };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testPcb( test::sdw_test::TestCounts & testCounts )
	{
		testPcbRaw< T >( testCounts );
		testPcbRawArray< T >( testCounts );
		testPcbRawOptionalDisabled< T >( testCounts );
		testPcbRawOptionalDisabledArray< T >( testCounts );
		testPcbRawOptionalEnabled< T >( testCounts );
		testPcbRawOptionalEnabledArray< T >( testCounts );
		testPcbHelper< T >( testCounts );
		testPcbHelperArray< T >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterPcbDeclarations )
{
	sdwTestSuiteBegin();
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
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterPcbDeclarations )
