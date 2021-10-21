#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain writer.implementMain( [](){} )

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
			auto instance = st.getInstance( "st" + sdw::debug::getName( sdw::typeEnum< T > ), true );
			auto retrieved = instance.template getMember< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			DummyMain;
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
			auto instance = st.getInstance( "stArray4" + sdw::debug::getName( sdw::typeEnum< T > ), true );
			auto retrieved = instance.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			check( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterStructDeclarations )
{
	sdwTestSuiteBegin();
	testStruct< sdw::Int >( testCounts );
	testStruct< sdw::UInt >( testCounts );
	testStruct< sdw::Float >( testCounts );
	testStruct< sdw::Double >( testCounts );
	testStruct< sdw::Vec2 >( testCounts );
	testStruct< sdw::Vec3 >( testCounts );
	testStruct< sdw::Vec4 >( testCounts );
	testStruct< sdw::DVec2 >( testCounts );
	testStruct< sdw::DVec3 >( testCounts );
	testStruct< sdw::DVec4 >( testCounts );
	testStruct< sdw::IVec2 >( testCounts );
	testStruct< sdw::IVec3 >( testCounts );
	testStruct< sdw::IVec4 >( testCounts );
	testStruct< sdw::UVec2 >( testCounts );
	testStruct< sdw::UVec3 >( testCounts );
	testStruct< sdw::UVec4 >( testCounts );
	testStruct< sdw::Mat2 >( testCounts );
	testStruct< sdw::Mat2x3 >( testCounts );
	testStruct< sdw::Mat2x4 >( testCounts );
	testStruct< sdw::Mat3 >( testCounts );
	testStruct< sdw::Mat3x2 >( testCounts );
	testStruct< sdw::Mat3x4 >( testCounts );
	testStruct< sdw::Mat4 >( testCounts );
	testStruct< sdw::Mat4x2 >( testCounts );
	testStruct< sdw::Mat4x3 >( testCounts );
	testStruct< sdw::DMat2 >( testCounts );
	testStruct< sdw::DMat2x3 >( testCounts );
	testStruct< sdw::DMat2x4 >( testCounts );
	testStruct< sdw::DMat3 >( testCounts );
	testStruct< sdw::DMat3x2 >( testCounts );
	testStruct< sdw::DMat3x4 >( testCounts );
	testStruct< sdw::DMat4 >( testCounts );
	testStruct< sdw::DMat4x2 >( testCounts );
	testStruct< sdw::DMat4x3 >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterStructDeclarations )
