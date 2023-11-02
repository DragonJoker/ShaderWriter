#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/TraditionalGraphicsWriter.hpp>

namespace
{
#define DummyMainV writer.implementEntryPoint( [&]( sdw::VertexIn in, sdw::VertexOut out ){} )
#define DummyMainF writer.implementEntryPoint( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )
#define DummyMainG writer.implementEntryPointT< 1u, sdw::PointList, sdw::PointStream >( [&]( sdw::GeometryIn in, sdw::PointList list, sdw::PointStream out ){ out.vtx.position = list[0].vtx.position;out.append(); } )

	template< typename T >
	void testShaderOutputBase( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutputBase" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "OutputValue_0";
			auto value = writer.declOutput< T >( name, sdw::EntryPoint::eVertex, 0u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderOutputArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutputArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "OutputValue_1";
			auto value = writer.declOutputArray< T >( name, sdw::EntryPoint::eVertex, 1u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderOutputOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutputOptionalDisabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutput< T >( "value", sdw::EntryPoint::eVertex, 0u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderOutputArrayOptionalDisabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutputArrayOptionalDisabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutputArray< T >( "value", sdw::EntryPoint::eVertex, 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderOutputOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutputOptionalEnabled" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "OutputValue_0_opt";
			auto value = writer.declOutput< T >( name, sdw::EntryPoint::eVertex, 0u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderOutputArrayOptionalEnabled( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutput" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "OutputValue_1_opt";
			auto value = writer.declOutputArray< T >( name, sdw::EntryPoint::eVertex, 1u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderBlendOutput( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderBlendOutput" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "BlendOutputValue_0";
			auto value = writer.declBlendOutput< T >( name, 0u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBlendIndex() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getBlendIndex() == 1u );
			DummyMainF;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderBlendOutputArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderBlendOutputArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "BlendOutputValue_0";
			auto value = writer.declBlendOutputArray< T >( name, 0u, 1u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBlendIndex() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getBlendIndex() == 1u );
			DummyMainF;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderStreamOutput( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderStreamOutput" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "StreamOutputValue_0";
			auto value = writer.declStreamOutput< T >( name, 0u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isGeometryStream() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getStreamIndex() == 1u );
			DummyMainG;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderStreamOutputArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderStreamOutputArray" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "StreamOutputValue_0";
			auto value = writer.declStreamOutputArray< T >( name, 0u, 1u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isGeometryStream() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getStreamIndex() == 1u );
			DummyMainG;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	template< typename T >
	void testShaderOutput( test::sdw_test::TestCounts & testCounts )
	{
		testShaderOutputBase< T >( testCounts );
		testShaderOutputArray< T >( testCounts );
		testShaderOutputOptionalDisabled< T >( testCounts );
		testShaderOutputArrayOptionalDisabled< T >( testCounts );
		testShaderOutputOptionalEnabled< T >( testCounts );
		testShaderOutputArrayOptionalEnabled< T >( testCounts );
		testShaderBlendOutput< T >( testCounts );
		testShaderBlendOutputArray< T >( testCounts );
		testShaderStreamOutput< T >( testCounts );
		testShaderStreamOutputArray< T >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterShaderOutputDeclarations )
{
	sdwTestSuiteBegin();
	testShaderOutput< sdw::Int >( testCounts );
	testShaderOutput< sdw::UInt >( testCounts );
	testShaderOutput< sdw::Float >( testCounts );
	testShaderOutput< sdw::Vec2 >( testCounts );
	testShaderOutput< sdw::Vec3 >( testCounts );
	testShaderOutput< sdw::Vec4 >( testCounts );
	testShaderOutput< sdw::IVec2 >( testCounts );
	testShaderOutput< sdw::IVec3 >( testCounts );
	testShaderOutput< sdw::IVec4 >( testCounts );
	testShaderOutput< sdw::UVec2 >( testCounts );
	testShaderOutput< sdw::UVec3 >( testCounts );
	testShaderOutput< sdw::UVec4 >( testCounts );
	testShaderOutput< sdw::Mat2 >( testCounts );
	testShaderOutput< sdw::Mat2x3 >( testCounts );
	testShaderOutput< sdw::Mat2x4 >( testCounts );
	testShaderOutput< sdw::Mat3 >( testCounts );
	testShaderOutput< sdw::Mat3x2 >( testCounts );
	testShaderOutput< sdw::Mat3x4 >( testCounts );
	testShaderOutput< sdw::Mat4 >( testCounts );
	testShaderOutput< sdw::Mat4x2 >( testCounts );
	testShaderOutput< sdw::Mat4x3 >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterShaderOutputDeclarations )
