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
	writer.implementMain( 32u, [&ssboArrayIn, &ssboArrayOut]( sdw::ComputeIn const & in )\
		{\
			auto value = ssboArrayIn[0][in.globalInvocationID.x()];\
			ssboArrayOut[0][in.globalInvocationID.x()] = value;\
		} )

	using T = sdw::SDW_TestType;

	TEST_F( SDWTest, testStructuredSsboArrayBasicDataType )
	{
		sdwTestBegin( "testStructuredSsboArrayBasicDataType" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto ssboArrayIn = writer.declArrayStorageBufferArray< T >( "ssboArrayIn", 0u, 0u, 32u, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray< T >( "ssboArrayIn", 0u, 0u, 32u, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0];
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray< T >( "ssboArrayOut", 32u, 0u, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u];
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto ssboArrayIn = writer.declArrayStorageBufferArray< T >( "ssboArrayIn", { .binding = 0u, .set = 0u }, 32u, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray< T >( "ssboArrayIn", { .binding = 0u, .set = 0u }, 32u, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0];
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray< T >( "ssboArrayOut", { .binding = 32u, .set = 0u }, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u];
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testStructuredSsboArrayStructSingleMember )
	{
		sdwTestBegin( "testStructuredSsboArrayStructSingleMember" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			auto ssboArrayIn = writer.declArrayStorageBufferArray( "ssboArrayIn", 0u, 0u, type, 32u, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray( "ssboArrayIn", 0u, 0u, type, 32u, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray( "ssboArrayOut", 32u, 0u, type, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u].getMember< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
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
			auto ssboArrayIn = writer.declArrayStorageBufferArray( "ssboArrayIn", { .binding = 0u, .set = 0u }, type, 32u, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray( "ssboArrayIn", { .binding = 0u, .set = 0u }, type, 32u, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray( "ssboArrayOut", { .binding = 32u, .set = 0u }, type, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u].getMember< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testStructuredSsboArrayStructMultipleMembers )
	{
		sdwTestBegin( "testStructuredSsboArrayStructMultipleMembers" );
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
			auto ssboArrayIn = writer.declArrayStorageBufferArray( "ssboArrayIn", 0u, 0u, type, 32u, ast::type::MemoryLayout::eStd140, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray( "ssboArrayIn", 0u, 0u, type, 32u, ast::type::MemoryLayout::eStd140, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray( "ssboArrayOut", 32u, 0u, type, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
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
			auto ssboArrayIn = writer.declArrayStorageBufferArray( "ssboArrayIn", { .binding = 0u, .set = 0u }, type, 32u, ast::type::MemoryLayout::eStd140, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray( "ssboArrayIn", { .binding = 0u, .set = 0u }, type, 32u, ast::type::MemoryLayout::eStd140, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray( "ssboArrayOut", { .binding = 32u, .set = 0u }, type, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u].getMember< T >( name1 );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testStructuredSsboArrayStructSingleArrayMember )
	{
		sdwTestBegin( "testStructuredSsboArrayStructSingleArrayMember" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			auto ssboArrayIn = writer.declArrayStorageBufferArray( "ssboArrayIn", 0u, 0u, type, 32u, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray( "ssboArrayIn", 0u, 0u, type, 32u, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == 4u );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray( "ssboArrayOut", 32u, 0u, type, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == 4u );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
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
			auto ssboArrayIn = writer.declArrayStorageBufferArray( "ssboArrayIn", { .binding = 0u, .set = 0u }, type, 32u, true );
			auto ssboArrayIn2 = writer.declArrayStorageBufferArray( "ssboArrayIn", { .binding = 0u, .set = 0u }, type, 32u, true );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboIn = ssboArrayIn[0];
			auto valueIn = ssboIn[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == 4u );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getBindingPoint() == 0u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtIn ).getDescriptorSet() == 0u );
			auto ssboArrayOut = writer.declArrayStorageBufferArray( "ssboArrayOut", { .binding = 32u, .set = 0u }, type, 32u, true );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			auto ssboOut = ssboArrayOut[0u];
			auto valueOut = ssboOut[0u].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == 4u );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getBindingPoint() == 32u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmtOut ).getDescriptorSet() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
