#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using T = sdw::SDW_TestType;

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
	writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )\
		{\
			retrieved = test::getDefault< T >( writer );\
		} )

#define DummyMainArray\
	writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )\
		{\
			retrieved[0] = test::getDefault< T >( writer );\
		} )

	TEST_F( SDWTest, testSsboRaw )
	{
		sdwTestBegin( "testSsboRaw" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::StorageBuffer bo{ writer.declStorageBuffer( "bo", 1u, 1u, ast::type::MemoryLayout::eStd140 ) };
			sdw::StorageBuffer bo2{ writer.declStorageBuffer( "bo", 1u, 1u, ast::type::MemoryLayout::eStd140 ) };
			auto value = bo.template declMember< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *value.getExpr() ).getMemberIndex() == 0 );
			auto retrieved = bo.template getMember< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::StorageBuffer bo{ writer.declStorageBuffer( "bo", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 ) };
			sdw::StorageBuffer bo2{ writer.declStorageBuffer( "bo", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 ) };
			auto value = bo.template declMember< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *value.getExpr() ).getMemberIndex() == 0 );
			auto retrieved = bo.template getMember< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSsboRawArray )
	{
		sdwTestBegin( "testSsboRawArray" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::StorageBuffer bo{ writer.declStorageBuffer( "bo", 1u, 1u, ast::type::MemoryLayout::eStd140 ) };
			sdw::StorageBuffer bo2{ writer.declStorageBuffer( "bo", 1u, 1u, ast::type::MemoryLayout::eStd140 ) };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *value.getExpr() ).getMemberIndex() == 0 );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::StorageBuffer bo{ writer.declStorageBuffer( "bo", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 ) };
			sdw::StorageBuffer bo2{ writer.declStorageBuffer( "bo", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 ) };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *value.getExpr() ).getMemberIndex() == 0 );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSsboRawArrayRuntime )
	{
		sdwTestBegin( "testSsboRawArrayRuntime" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::StorageBuffer bo{ writer.declStorageBuffer( "bo", 1u, 1u, ast::type::MemoryLayout::eStd140 ) };
			sdw::StorageBuffer bo2{ writer.declStorageBuffer( "bo", 1u, 1u, ast::type::MemoryLayout::eStd140 ) };
			auto value = bo.template declMemberArray< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::UnknownArraySize );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *value.getExpr() ).getMemberIndex() == 0 );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			// HLSL has no support for runtime arrays in structures
			test::writeShader( writer, testCounts, Compilers_NoHLSL );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::StorageBuffer bo{ writer.declStorageBuffer( "bo", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 ) };
			sdw::StorageBuffer bo2{ writer.declStorageBuffer( "bo", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 ) };
			auto value = bo.template declMemberArray< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::UnknownArraySize );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *value.getExpr() ).getMemberIndex() == 0 );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			// HLSL has no support for runtime arrays in structures
			test::writeShader( writer, testCounts, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSsboHelper )
	{
#if SDW_EnableStructHelper
		using SsboType = sdw::StorageBufferHelperStd430T< sdw::StructFieldT< T, "member" > >;

		sdwTestBegin( "testSsboHelper" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			SsboType bo{ writer.declStorageBuffer< SsboType >( "SSBO", 1u, 1u ) };
			SsboType bo2{ writer.declStorageBuffer< SsboType >( "SSBO", 1u, 1u ) };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == ast::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			SsboType bo{ writer.declStorageBuffer< SsboType >( "SSBO", { .binding = 1u, .set = 1u } ) };
			SsboType bo2{ writer.declStorageBuffer< SsboType >( "SSBO", { .binding = 1u, .set = 1u } ) };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == ast::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()

#endif
	}

	TEST_F( SDWTest, testSsboHelperArray )
	{
#if SDW_EnableStructHelper
		using SsboType = sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", 4u > >;

		sdwTestBegin( "testSsboHelperArray" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			SsboType bo{ writer.declStorageBuffer< SsboType >( "SSBO", 1u, 1u ) };
			SsboType bo2{ writer.declStorageBuffer< SsboType >( "SSBO", 1u, 1u ) };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			SsboType bo{ writer.declStorageBuffer< SsboType >( "SSBO", { .binding = 1u, .set = 1u } ) };
			SsboType bo2{ writer.declStorageBuffer< SsboType >( "SSBO", { .binding = 1u, .set = 1u } ) };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			test::writeShader( writer, testCounts, CompilersT< T > );
		}
		sdwTestEnd()

#endif
	}

	TEST_F( SDWTest, testSsboHelperArrayRuntime )
	{
#if SDW_EnableStructHelper
		using SsboType = sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", ast::type::UnknownArraySize > >;

		sdwTestBegin( "testSsboHelperArrayRuntime" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			SsboType bo{ writer.declStorageBuffer< SsboType >( "SSBO", 1u, 1u ) };
			SsboType bo2{ writer.declStorageBuffer< SsboType >( "SSBO", 1u, 1u ) };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			// HLSL has no support for runtime arrays in structures
			test::writeShader( writer, testCounts, Compilers_NoHLSL );
		}
		{
			astOn( "Joined Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			SsboType bo{ writer.declStorageBuffer< SsboType >( "SSBO", { .binding = 1u, .set = 1u } ) };
			SsboType bo2{ writer.declStorageBuffer< SsboType >( "SSBO", { .binding = 1u, .set = 1u } ) };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eMbrSelect );
			astCheck( static_cast< sdw::expr::MbrSelect const & >( *retrieved.getExpr() ).getMemberIndex() == 0 );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			DummyMainArray;
			// HLSL has no support for runtime arrays in structures
			test::writeShader( writer, testCounts, Compilers_NoHLSL );
		}
		sdwTestEnd()

#endif
	}
}

sdwTestSuiteMain()
