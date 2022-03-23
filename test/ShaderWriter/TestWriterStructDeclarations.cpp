#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define BeginMain writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentIn, sdw::FragmentOut )
#define EndMain )

	template< typename T >
	void testStruct( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStruct" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct st{ writer, "ST" + sdw::debug::getName( sdw::typeEnum< T > ) };
			st.template declMember< T >( name );
			st.end();
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
			BeginMain
			{
				auto instance = st.getInstance( "st" + sdw::debug::getName( sdw::typeEnum< T > ), true );
				auto retrieved = instance.template getMember< T >( name );
				check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
				check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
				check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			}
			EndMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct st{ writer, "ST" + sdw::debug::getName( sdw::typeEnum< T > ) };
			st.template declMember< T >( name, 4u );
			st.end();
			auto & stmt = *shader.getStatements()->back();
			check( stmt.getKind() == sdw::stmt::Kind::eStructureDecl );
			BeginMain
			{
				auto instance = st.getInstance( "stArray4" + sdw::debug::getName( sdw::typeEnum< T > ), true );
				auto retrieved = instance.template getMemberArray< T >( name );
				check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
				check( getArraySize( retrieved.getType() ) == 4u );
				check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			}
			EndMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
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
