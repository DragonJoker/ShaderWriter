#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain writer.implementMain( [](){} )
#define DummyMainT writer.implementMainT< sdw::PointList, sdw::PointStream, 1u >( [&]( sdw::PointList in, sdw::PointStream out ){ out.vtx.position = in.vtx[0].position;out.append(); } )

	template< typename T >
	void testShaderOutput( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testShaderOutput" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::VertexWriter writer;
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0";
			auto value = writer.declOutput< T >( name, 0u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer;
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1";
			auto value = writer.declOutputArray< T >( name, 1u, 6u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutput< T >( "value", 0u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer;
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutputArray< T >( "value", 1u, 6u, false );
			check( !value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( shader.getStatements()->size() == count );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer;
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_0_opt";
			auto value = writer.declOutput< T >( name, 0u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::VertexWriter writer;
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "OutputValue_1_opt";
			auto value = writer.declOutputArray< T >( name, 1u, 6u, true );
			check( value.isEnabled() );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == 6u );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer;
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "BlendOutputValue_0";
			auto value = writer.declBlendOutput< T >( name, 0u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBlendIndex() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getBlendIndex() == 1u );
			DummyMain;
			test::writeShader( writer, testCounts );
		}
		{
			sdw::GeometryWriter writer;
			auto in = writer.getIn();
			auto out = writer.getOut();
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "StreamOutputValue_0";
			auto value = writer.declStreamOutput< T >( name, 0u, 1u );
			check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
			check( getArraySize( value.getType() ) == sdw::type::NotArray );
			require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isGeometryStream() );
			auto & stmt = *shader.getStatements()->back();
			require( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			check( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getStreamIndex() == 1u );
			DummyMainT;
			test::writeShader( writer, testCounts );
		}
		testEnd();
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
