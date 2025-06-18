#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/Struct.hpp>
#include <ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp>

namespace
{
	template< typename T >
	inline bool constexpr isInt16Type = std::is_same_v< T, sdw::Int16 >
		|| std::is_same_v< T, sdw::I16Vec2 >
		|| std::is_same_v< T, sdw::I16Vec3 >
		|| std::is_same_v< T, sdw::I16Vec4 >;
	template< typename T >
	inline bool constexpr isUInt16Type = std::is_same_v< T, sdw::UInt16 >
		|| std::is_same_v< T, sdw::U16Vec2 >
		|| std::is_same_v< T, sdw::U16Vec3 >
		|| std::is_same_v< T, sdw::U16Vec4 >;

	template< typename T, typename Enable = void >
	struct CompilerHolderT;

	template< typename T >
	struct CompilerHolderT< T, std::enable_if_t< !isInt16Type< T > && !isUInt16Type< T > > >
	{
		static constexpr test::Compilers value = CurrentCompilers;
	};

	template< typename T >
	struct CompilerHolderT< T, std::enable_if_t< isInt16Type< T > || isUInt16Type< T > > >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DVec2 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DVec3 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DVec4 >
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

	TEST_F( SDWTest, testStructuredSsbo )
	{
		sdwTestBegin( "testStructuredSsbo" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboIn{ writer, "ssboIn", type.getType(), 1u, 1u, true };
			auto valueIn = ssboIn[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboOut{ writer, "ssboOut", type.getType(), 2u, 1u, true };
			auto valueOut = ssboOut[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboIn{ writer, "ssboIn", type.getType(), { .binding = 1u, .set = 1u }, true };
			auto valueIn = ssboIn[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboOut{ writer, "ssboOut", type.getType(), { .binding = 2u, .set = 1u }, true };
			auto valueOut = ssboOut[0].getMember< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testStructuredSsboArray )
	{
		sdwTestBegin( "testStructuredSsboArray" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboIn{ writer, "ssboIn", type.getType(), 1u, 1u, true };
			auto valueIn = ssboIn[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == 4u );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboOut{ writer, "ssboOut", type.getType(), 2u, 1u, true };
			auto valueOut = ssboOut[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == 4u );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< T >( name, 4u );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboIn{ writer, "ssboIn", type.getType(), { .binding = 1u, .set = 1u }, true };
			auto valueIn = ssboIn[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == 4u );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			sdw::ArrayStorageBufferT< sdw::StructInstance > ssboOut{ writer, "ssboOut", type.getType(), { .binding = 2u, .set = 1u }, true };
			auto valueOut = ssboOut[0].getMemberArray< T >( name );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == 4u );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testArraySsbo )
	{
		sdwTestBegin( "testArraySsbo" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::ArrayStorageBufferT< T > ssboIn{ writer, "ssboIn", T::makeType( shader.getTypesCache() ), ast::type::MemoryLayout::eStd140, 1u, 1u, true };
			auto valueIn = ssboIn[0];
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			sdw::ArrayStorageBufferT< T > ssboOut{ writer, "ssboOut", T::makeType( shader.getTypesCache() ), ast::type::MemoryLayout::eStd140, 2u, 1u, true };
			auto valueOut = ssboOut[0];
			astCheck( valueOut.getType()->hasExplicitLayout() );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::ArrayStorageBufferT< T > ssboIn{ writer, "ssboIn", T::makeType( shader.getTypesCache() ), ast::type::MemoryLayout::eStd140, { .binding = 1u, .set = 1u }, true };
			auto valueIn = ssboIn[0];
			astCheck( valueIn.getType()->hasExplicitLayout() );
			astCheck( getNonArrayKind( valueIn.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueIn.getType() ) == sdw::type::NotArray );
			astRequire( valueIn.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtIn = *shader.getStatements()->back();
			astRequire( stmtIn.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtIn ).getDescriptorSet() == 1u );
			sdw::ArrayStorageBufferT< T > ssboOut{ writer, "ssboOut", T::makeType( shader.getTypesCache() ), ast::type::MemoryLayout::eStd140, { .binding = 2u, .set = 1u }, true };
			auto valueOut = ssboOut[0];
			astCheck( valueOut.getType()->hasExplicitLayout() );
			astCheck( getNonArrayKind( valueOut.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( valueOut.getType() ) == sdw::type::NotArray );
			astRequire( valueOut.getExpr()->getKind() == sdw::expr::Kind::eArrayAccess );
			auto & stmtOut = *shader.getStatements()->back();
			astRequire( stmtOut.getKind() == sdw::stmt::Kind::eShaderStructBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getBindingPoint() == 2u );
			astCheck( static_cast< sdw::stmt::ShaderStructBufferDecl const & >( stmtOut ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
