#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/UniformBuffer.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

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
	writer.implementMain( 32u, [&]( sdw::ComputeIn in )\
	{\
		writer.declLocale( "var", value );\
	} )

#define DummyMainArray\
	writer.implementMain( 32u, [&]( sdw::ComputeIn in )\
	{\
		writer.declLocale( "var", value[0] );\
	} )

	using T = sdw::SDW_TestType;

	TEST_F( SDWTest, testUboRaw )
	{
		sdwTestBegin( "testUboRaw" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", 1u, 1u ) };
			auto value = bo.template declMember< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_member";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template declMember< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUboRawArray )
	{
		sdwTestBegin( "testUboRawArray" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", 1u, 1u ) };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberArray";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUboRawOptionalDisabled )
	{
		sdwTestBegin( "testUboRawOptionalDisabled" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDis";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", 1u, 1u ) };
			auto value = bo.template declMember< T >( name, false );
			bo.end();
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, false );
			astCheck( !retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDis";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template declMember< T >( name, false );
			bo.end();
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, false );
			astCheck( !retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUboRawOptionalDisabledArray )
	{
		sdwTestBegin( "testUboRawOptionalDisabledArray" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDisArray";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", 1u, 1u ) };
			auto value = bo.template declMember< T >( name, 4u, false );
			bo.end();
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			astCheck( !retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptDisArray";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template declMember< T >( name, 4u, false );
			bo.end();
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, false );
			astCheck( !retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUboRawOptionalEnabled )
	{
		sdwTestBegin( "testUboRawOptionalEnabled" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEn";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", 1u, 1u ) };
			auto value = bo.template declMember< T >( name, true );
			bo.end();
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, true );
			astCheck( retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEn";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template declMember< T >( name, true );
			bo.end();
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name, true );
			astCheck( retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUboRawOptionalEnabledArray )
	{
		sdwTestBegin( "testUboRawOptionalEnabledArray" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEnArray";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", 1u, 1u ) };
			auto value = bo.template declMember< T >( name, 4u, true );
			bo.end();
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			astCheck( retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "m_memberOptEnArray";
			sdw::UniformBuffer bo{ writer.declUniformBuffer( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template declMember< T >( name, 4u, true );
			bo.end();
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name, true );
			astCheck( retrieved.isEnabled() );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUboHelper )
	{
#if SDW_EnableStructHelper
		using UboType = sdw::UniformBufferHelperStd140T< sdw::StructFieldT< T, "member" > >;

		sdwTestBegin( "testUboHelper" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			UboType bo{ writer.declUniformBuffer< UboType >( "UBO", 1u, 1u ) };
			auto value = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			UboType bo{ writer.declUniformBuffer< UboType >( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()

#endif
	}

	TEST_F( SDWTest, testUboHelperArray )
	{
#if SDW_EnableStructHelper
		using UboType = sdw::UniformBufferHelperStd140T< sdw::StructFieldArrayT< T, "member", 4u > >;

		sdwTestBegin( "testUboHelperArray" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			UboType bo{ writer.declUniformBuffer< UboType >( "UBO", 1u, 1u ) };
			auto value = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			UboType bo{ writer.declUniformBuffer< UboType >( "UBO", { .binding = 1u, .set = 1u } ) };
			auto value = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eConstantBufferDecl );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ConstantBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()

#endif
	}
}

sdwTestSuiteMain()
