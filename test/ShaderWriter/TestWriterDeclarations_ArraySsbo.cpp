#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/Struct.hpp>
#include <ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp>

#pragma clang diagnostic ignored "-Wunused-const-variable"

namespace
{
	template< typename T, typename Enable = void >
	struct CompilerHolderT;

	template< typename T >
	struct CompilerHolderT< T, std::enable_if_t< !test::isFloat64Type< T > && !test::isInt16Type< T > && !test::isUInt16Type< T > > >
	{
		static constexpr test::Compilers value = CurrentCompilers;
	};

	template< typename T >
	struct CompilerHolderT< T, std::enable_if_t< test::isFloat64Type< T > || test::isInt16Type< T > || test::isUInt16Type< T > > >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template< typename T >
	inline constexpr test::Compilers CompilersT = CompilerHolderT< T >::value;

#define DummyMain\
	writer.implementMain( 32u, [&ssboIn, &ssboOut]( sdw::ComputeIn const & in )\
		{\
			auto value = ssboIn[in.localInvocationIndex];\
			ssboOut[in.localInvocationIndex] = value;\
		} )

	using T = sdw::SDW_TestType;

	TEST_F( SDWTest, testStructuredSsboBasicDataType )
	{
		sdwTestBegin( "testStructuredSsboBasicDataType" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto ssboIn = writer.declArrayStorageBuffer< T >( "ssboIn", 1u, 1u, true );
			auto ssboIn2 = writer.declArrayStorageBuffer< T >( "ssboIn", 1u, 1u, true );
			auto valueIn = ssboIn[0];
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer< T >( "ssboOut", 2u, 1u, true );
			auto valueOut = ssboOut[0];
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto ssboIn = writer.declArrayStorageBuffer< T >( "ssboIn", { .binding = 1u, .set = 1u }, true );
			auto ssboIn2 = writer.declArrayStorageBuffer< T >( "ssboIn", { .binding = 1u, .set = 1u }, true );
			auto valueIn = ssboIn[0];
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer< T >( "ssboOut", { .binding = 2u, .set = 1u }, true );
			auto valueOut = ssboOut[0];
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testStructuredSsboStructSingleMember )
	{
		sdwTestBegin( "testStructuredSsboStructSingleMember" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			auto ssboIn = writer.declArrayStorageBuffer( "ssboIn", 1u, 1u, type, ast::type::MemoryLayout::eStd140, true );
			auto ssboIn2 = writer.declArrayStorageBuffer( "ssboIn", 1u, 1u, type, ast::type::MemoryLayout::eStd140, true );
			auto valueIn = ssboIn[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer( "ssboOut", 2u, 1u, type, true );
			auto valueOut = ssboOut[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			auto ssboIn = writer.declArrayStorageBuffer( "ssboIn", { .binding = 1u, .set = 1u }, type, ast::type::MemoryLayout::eStd140, true );
			auto ssboIn2 = writer.declArrayStorageBuffer( "ssboIn", { .binding = 1u, .set = 1u }, type, ast::type::MemoryLayout::eStd140, true );
			auto valueIn = ssboIn[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer( "ssboOut", { .binding = 2u, .set = 1u }, type, true );
			auto valueOut = ssboOut[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testStructuredSsboStructMultipleMembers )
	{
		sdwTestBegin( "testStructuredSsboStructMultipleMembers" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name1 = "m_member1";
			std::string const name2 = "m_member2";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name1 );
			type.declMember< T >( name2 );
			type.end();
			auto ssboIn = writer.declArrayStorageBuffer( "ssboIn", 1u, 1u, type, true );
			auto ssboIn2 = writer.declArrayStorageBuffer( "ssboIn", 1u, 1u, type, true );
			auto valueIn = ssboIn[0].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer( "ssboOut", 2u, 1u, type, true );
			auto valueOut = ssboOut[0].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name1 = "m_member1";
			std::string const name2 = "m_member2";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name1 );
			type.declMember< T >( name2 );
			type.end();
			auto ssboIn = writer.declArrayStorageBuffer( "ssboIn", { .binding = 1u, .set = 1u }, type, true );
			auto ssboIn2 = writer.declArrayStorageBuffer( "ssboIn", { .binding = 1u, .set = 1u }, type, true );
			auto valueIn = ssboIn[0].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer( "ssboOut", { .binding = 2u, .set = 1u }, type, true );
			auto valueOut = ssboOut[0].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testStructuredSsboStructSingleArrayMember )
	{
		sdwTestBegin( "testStructuredSsboStructSingleArrayMember" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			auto ssboIn = writer.declArrayStorageBuffer( "ssboIn", 1u, 1u, type, true );
			auto ssboIn2 = writer.declArrayStorageBuffer( "ssboIn", 1u, 1u, type, true );
			auto valueIn = ssboIn[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == 4u );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer( "ssboOut", 2u, 1u, type, true );
			auto valueOut = ssboOut[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == 4u );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			auto ssboIn = writer.declArrayStorageBuffer( "ssboIn", { .binding = 1u, .set = 1u }, type, true );
			auto ssboIn2 = writer.declArrayStorageBuffer( "ssboIn", { .binding = 1u, .set = 1u }, type, true );
			auto valueIn = ssboIn[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == 4u );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			auto ssboOut = writer.declArrayStorageBuffer( "ssboOut", { .binding = 2u, .set = 1u }, type, true );
			auto valueOut = ssboOut[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == 4u );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
