#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

#undef CurrentCompilers
#define CurrentCompilers Compilers_NoHLSL

namespace
{
	template< typename T >
	void testSsboRaw( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSsboRaw" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getName( sdw::typeEnum< T > );
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
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved = test::getDefault< T >( writer );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testSsboRawArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSsboRawArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getName( sdw::typeEnum< T > );
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
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testSsboRawArrayRuntime( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSsboRawArrayRuntime" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getName( sdw::typeEnum< T > );
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
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testSsboHelper( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testSsboHelper" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			sdw::SsboHelperStd430T< sdw::StructFieldT< T, "member" > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == ast::type::NotArray );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();

#endif
	}

	template< typename T >
	void testSsboHelperArray( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testSsboHelperArray" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			sdw::SsboHelperStd430T< sdw::StructFieldArrayT< T, "member", 4u > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == 4u );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();

#endif
	}

	template< typename T >
	void testSsboHelperArrayRuntime( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testSsboHelperArrayRuntime" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			sdw::SsboHelperStd430T< sdw::StructFieldArrayT< T, "member", ast::type::UnknownArraySize > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			require( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();

#endif
	}

	template< typename T >
	void testSsbo( test::sdw_test::TestCounts & testCounts )
	{
		testSsboRaw< T >( testCounts );
		testSsboRawArray< T >( testCounts );
		testSsboRawArrayRuntime< T >( testCounts );
		testSsboHelperArray< T >( testCounts );
		testSsboHelperArrayRuntime< T >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterSsboDeclarations )
{
	sdwTestSuiteBegin();
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

sdwTestSuiteLaunch( TestWriterSsboDeclarations )
