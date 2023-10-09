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
		testBegin( "testPcbRaw" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::PushConstantBuffer bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::PushConstantBuffer bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalDisabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDis" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::PushConstantBuffer bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name, false );
			bo.end();
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, false );
			check( !retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalDisabledArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalDisabledArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDisArray" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::PushConstantBuffer bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name, 4u, false );
			bo.end();
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			check( !retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalEnabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEn" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::PushConstantBuffer bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name, true );
			bo.end();
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, true );
			check( retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();
	}

	template< typename T >
	void testPcbRawOptionalEnabledArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPcbRawOptionalEnabledArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEnArray" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::PushConstantBuffer bo{ writer, "PCB", ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name, 4u, true );
			bo.end();
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			check( retrieved.isEnabled() );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();
	}

	template< typename T >
	void testPcbHelper( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testPcbHelper" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::PushConstantBufferHelperStd140T< sdw::StructFieldT< T, "member" > > bo{ writer, "UBO" };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();

#endif
	}

	template< typename T >
	void testPcbHelperArray( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testPcbHelperArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::PushConstantBufferHelperStd140T< sdw::StructFieldArrayT< T, "member", 4u > > bo{ writer, "UBO" };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::ePushConstantsBufferDecl );
			DummyMain;

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		testEnd();

#endif
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

#define testName testConcat( TestWriterPcbDeclarations, SDW_TestType )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
	testPcb< sdw::SDW_TestType >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
