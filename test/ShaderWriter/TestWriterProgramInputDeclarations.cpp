#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/TraditionalGraphicsWriter.hpp>

namespace
{
#define DummyMain( value ) writer.implementEntryPoint( [&]( sdw::FragmentIn in, sdw::FragmentOut out )\
		{\
			auto v = writer.declLocale( "v", value );\
		} )

	template< typename T >
	void testShaderInput( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderInput" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_0";
			auto value = writer.declInput< T >( name, sdw::EntryPoint::eFragment, 0u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_1";
			auto value = writer.declInputArray< T >( name, sdw::EntryPoint::eFragment, 1u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInput< T >( "value", sdw::EntryPoint::eFragment, 0u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declInputArray< T >( "value", sdw::EntryPoint::eFragment, 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			check( shader.getStatements()->size() == count );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_0_opt";
			auto value = writer.declInput< T >( name, sdw::EntryPoint::eFragment, 0u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "InputValue_1_opt";
			auto value = writer.declInputArray< T >( name, sdw::EntryPoint::eFragment, 1u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderInput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain( value );
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterShaderInputDeclarations )
{
	sdwTestSuiteBegin();
	testShaderInput< sdw::Int >( testCounts );
	testShaderInput< sdw::UInt >( testCounts );
	testShaderInput< sdw::Float >( testCounts );
	testShaderInput< sdw::Vec2 >( testCounts );
	testShaderInput< sdw::Vec3 >( testCounts );
	testShaderInput< sdw::Vec4 >( testCounts );
	testShaderInput< sdw::IVec2 >( testCounts );
	testShaderInput< sdw::IVec3 >( testCounts );
	testShaderInput< sdw::IVec4 >( testCounts );
	testShaderInput< sdw::UVec2 >( testCounts );
	testShaderInput< sdw::UVec3 >( testCounts );
	testShaderInput< sdw::UVec4 >( testCounts );
	testShaderInput< sdw::Mat2 >( testCounts );
	testShaderInput< sdw::Mat2x3 >( testCounts );
	testShaderInput< sdw::Mat2x4 >( testCounts );
	testShaderInput< sdw::Mat3 >( testCounts );
	testShaderInput< sdw::Mat3x2 >( testCounts );
	testShaderInput< sdw::Mat3x4 >( testCounts );
	testShaderInput< sdw::Mat4 >( testCounts );
	testShaderInput< sdw::Mat4x2 >( testCounts );
	testShaderInput< sdw::Mat4x3 >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterShaderInputDeclarations )
