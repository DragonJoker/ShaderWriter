#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/Struct.hpp>
#include <ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp>

namespace
{
#define DummyMain writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )

	template< typename T >
	void testStructuredSsbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStructuredSsbo" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			auto value = bo[0].getMember< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			auto value = bo[0].getMemberArray< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), { .binding = 1u, .set = 1u }, true };
			auto value = bo[0].getMember< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), { .binding = 1u, .set = 1u }, true };
			auto value = bo[0].getMemberArray< T >( name );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testArraySsbo( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArraySsbo" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::ArrayStorageBufferT< T > bo{ writer, "Datas", T::makeType( shader.getTypesCache() ), ast::type::MemoryLayout::eStd140, 1u, 1u, true };
			auto value = bo[0];
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			std::string const name = "m_member" + sdw::debug::getName( sdw::typeEnum< T > );
			sdw::ArrayStorageBufferT< T > bo{ writer, "Datas", T::makeType( shader.getTypesCache() ), ast::type::MemoryLayout::eStd140, { .binding = 1u, .set = 1u }, true };
			auto value = bo[0];
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			check( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}
}

#define testName testConcat( TestWriterArraySsboDeclarations, SDW_TestType )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
	testStructuredSsbo< sdw::SDW_TestType >( testCounts );
	testArraySsbo< sdw::SDW_TestType >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
