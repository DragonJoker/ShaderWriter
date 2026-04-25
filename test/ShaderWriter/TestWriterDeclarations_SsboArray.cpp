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

	TEST_F( SDWTest, testSsboArrayHelper )
	{
#if SDW_EnableStructHelper
		using SsboType = sdw::StorageBufferHelperStd430T< sdw::StructFieldT< T, "member" > >;

		sdwTestBegin( "testSsboArrayHelper" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto boArray = writer.declStorageBufferArray< SsboType >( "SSBO", 1u, 1u, 32u );
			auto bo = boArray[0];
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
			auto boArray = writer.declStorageBufferArray< SsboType >( "SSBO", { .binding = 1u, .set = 1u }, 32u );
			auto bo = boArray[0];
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

	TEST_F( SDWTest, testSsboArrayHelperArray )
	{
#if SDW_EnableStructHelper
		using SsboType = sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", 4u > >;

		sdwTestBegin( "testSsboArrayHelperArray" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto boArray = writer.declStorageBufferArray< SsboType >( "SSBO", 1u, 1u, 32u );
			auto bo = boArray[0];
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
			auto boArray = writer.declStorageBufferArray< SsboType >( "SSBO", { .binding = 1u, .set = 1u }, 32u );
			auto bo = boArray[0];
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

	TEST_F( SDWTest, testSsboArrayHelperArrayRuntime )
	{
#if SDW_EnableStructHelper
		using SsboType = sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", ast::type::UnknownArraySize > >;

		sdwTestBegin( "testSsboArrayHelperArrayRuntime" );
		{
			astOn( "Split Binding and Set parameters" );
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto boArray = writer.declStorageBufferArray< SsboType >( "SSBO", 1u, 1u, 32u );
			auto bo = boArray[0];
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
			auto boArray = writer.declStorageBufferArray< SsboType >( "SSBO", { .binding = 1u, .set = 1u }, 32u );
			auto bo = boArray[0];
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
