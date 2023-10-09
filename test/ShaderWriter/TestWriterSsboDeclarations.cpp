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
		testBegin( "testSsboRaw" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMember< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
		testEnd();
	}

	template< typename T >
	void testSsboRawArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSsboRawArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMember< T >( name, 4u );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 4u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
		testEnd();
	}

	template< typename T >
	void testSsboRawArrayRuntime( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSsboRawArrayRuntime" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			std::string const name = "member" + sdw::debug::getTypeName( sdw::typeEnumV< T > );
			sdw::StorageBuffer bo{ writer, "Datas", 1u, 1u, ast::type::MemoryLayout::eStd140 };
			auto value = bo.template declMemberArray< T >( name );
			bo.end();
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::UnknownArraySize );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			auto retrieved = bo.template getMemberArray< T >( name );
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
		testEnd();
	}

	template< typename T >
	void testSsboHelper( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testSsboHelper" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldT< T, "member" > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
		testEnd();

#endif
	}

	template< typename T >
	void testSsboHelperArray( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testSsboHelperArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", 4u > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
		testEnd();

#endif
	}

	template< typename T >
	void testSsboHelperArrayRuntime( test::sdw_test::TestCounts & testCounts )
	{
#if SDW_EnableStructHelper

		testBegin( "testSsboHelperArrayRuntime" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			sdw::StorageBufferHelperStd430T< sdw::StructFieldArrayT< T, "member", ast::type::UnknownArraySize > > bo{ writer, "SSBO", 1u, 1u };
			auto retrieved = bo.template getMember< "member" >();
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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
			check( getNonArrayKind( retrieved.getType() ) == sdw::typeEnumV< T > );
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

#define testName testConcat( TestWriterSsboDeclarations, SDW_TestType )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
	testSsbo< sdw::SDW_TestType >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
