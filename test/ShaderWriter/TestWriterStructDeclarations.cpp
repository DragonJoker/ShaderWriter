#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define BeginMain writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentIn, sdw::FragmentOut )
#define EndMain )

	template< typename T >
	void testStruct( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStruct" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::Struct st{ writer, "ST" + sdw::debug::getTypeName( sdw::typeEnumV< T > ) };
			st.template declMember< T >( name );
			st.end();
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
			BeginMain
			{
				auto instance = st.getInstance( "st" + sdw::debug::getTypeName( sdw::typeEnumV< T > ), true );
				auto retrieved = instance.template getMember< T >( name );
				check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
				check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
				check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			}
			EndMain;

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
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::Struct st{ writer, "ST" + sdw::debug::getTypeName( sdw::typeEnumV< T > ) };
			st.template declMember< T >( name, 4u );
			st.end();
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
			BeginMain
			{
				auto instance = st.getInstance( "stArray4" + sdw::debug::getTypeName( sdw::typeEnumV< T > ), true );
				auto retrieved = instance.template getMemberArray< T >( name );
				check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
				check( getArraySize( retrieved.getType() ) == 4u );
				check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			}
			EndMain;

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
}

#define testName testConcat( TestWriterStructDeclarations, SDW_TestType )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
	testStruct< sdw::SDW_TestType >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
