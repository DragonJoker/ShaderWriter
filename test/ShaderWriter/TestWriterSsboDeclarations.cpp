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
		astTestBegin( "testSsboRaw" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
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
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 };
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
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		astTestEnd();
	}

	template< typename T >
	void testSsboRawArray( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testSsboRawArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
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
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 };
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
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		astTestEnd();
	}

	template< typename T >
	void testSsboRawArrayRuntime( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testSsboRawArrayRuntime" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMemberArray< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::UnknownArraySize );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", { .binding = 1u, .set = 1u }, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMemberArray< T >( name );
			bo.end();
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::UnknownArraySize );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		astTestEnd();
	}

	template< typename T >
	void testSsboHelper( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		astTestBegin( "testSsboHelper" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldT< T, "member" > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == ast::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldT< T, "member" > > bo{ writer, "SSBO", { .binding = 1u, .set = 1u } };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == ast::type::NotArray );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		astTestEnd();

#endif
	}

	template< typename T >
	void testSsboHelperArray( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		astTestBegin( "testSsboHelperArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", 4u > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", 4u > > bo{ writer, "SSBO", { .binding = 1u, .set = 1u } };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == 4u );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		astTestEnd();

#endif
	}

	template< typename T >
	void testSsboHelperArrayRuntime( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		astTestBegin( "testSsboHelperArrayRuntime" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", ast::type::UnknownArraySize > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", ast::type::UnknownArraySize > > bo{ writer, "SSBO", { .binding = 1u, .set = 1u } };
			auto retrieved = bo.template getMember< "member" >();
			astCheck( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( retrieved.getType() ) == sdw::type::UnknownArraySize );
			astRequire( retrieved.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *retrieved.getExpr() ).getVariable()->getName() == "member" );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eShaderBufferDecl );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getBindingPoint() == 1u );
			astCheck( static_cast< sdw::stmt::ShaderBufferDecl const & >( stmt ).getDescriptorSet() == 1u );
			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					retrieved[0] = test::getDefault< T >( writer );
				} );

			if constexpr ( std::is_same_v< T, sdw::UInt16 >
				|| std::is_same_v< T, sdw::U16Vec2 >
				|| std::is_same_v< T, sdw::U16Vec3 >
				|| std::is_same_v< T, sdw::U16Vec4 >
				|| std::is_same_v< T, sdw::Int16 >
				|| std::is_same_v< T, sdw::I16Vec2 >
				|| std::is_same_v< T, sdw::I16Vec3 >
				|| std::is_same_v< T, sdw::I16Vec4 > )
			{
				test::writeShader( writer, testCounts, Compilers_NoHLSL );
			}
			else
			{
				test::writeShader( writer, testCounts, CurrentCompilers );
			}
		}
		astTestEnd();

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

#define testName astTestConcat( TestWriterSsboDeclarations, SDW_TestType )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
	testSsbo< sdw::SDW_TestType >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
