#include "WriterCommon.hpp"

#include <ShaderWriter/TraditionalGraphicsWriter.hpp>

namespace
{
	using T = sdw::SDW_TestType;

#define DummyMainV writer.implementEntryPoint( [&]( sdw::VertexIn in, sdw::VertexOut out ){} )
#define DummyMainF writer.implementEntryPoint( [&]( sdw::FragmentIn in, sdw::FragmentOut out ){} )
#define DummyMainG writer.implementEntryPointT< 1u, sdw::PointList, sdw::PointStream >( [&]( sdw::GeometryIn in, sdw::PointList list, sdw::PointStream out ){ out.vtx.position = list[0].vtx.position;out.append(); } )

	TEST_F( SDWTest, testProgramOutputBase )
	{
		sdwTestBegin( "testProgramOutputBase" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declOutput< T >( "value", sdw::EntryPoint::eVertex, 0u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramOutputArray )
	{
		sdwTestBegin( "testProgramOutputArray" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declOutputArray< T >( "value", sdw::EntryPoint::eVertex, 1u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramOutputOptionalDisabled )
	{
		sdwTestBegin( "testProgramOutputOptionalDisabled" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutput< T >( "value", sdw::EntryPoint::eVertex, 0u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			astCheck( shader.getStatements()->size() == count );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramOutputArrayOptionalDisabled )
	{
		sdwTestBegin( "testProgramOutputArrayOptionalDisabled" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declOutputArray< T >( "value", sdw::EntryPoint::eVertex, 1u, 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			astCheck( shader.getStatements()->size() == count );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramOutputOptionalEnabled )
	{
		sdwTestBegin( "testProgramOutputOptionalEnabled" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declOutput< T >( "value", sdw::EntryPoint::eVertex, 0u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramOutputArrayOptionalEnabled )
	{
		sdwTestBegin( "testProgramOutput" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declOutputArray< T >( "value", sdw::EntryPoint::eVertex, 1u, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 1u );
			DummyMainV;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramBlendOutput )
	{
		sdwTestBegin( "testProgramBlendOutput" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declBlendOutput< T >( "value", 0u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBlendIndex() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getBlendIndex() == 1u );
			DummyMainF;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramBlendOutputArray )
	{
		sdwTestBegin( "testProgramBlendOutputArray" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declBlendOutputArray< T >( "value", 0u, 1u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isBlendIndex() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getBlendIndex() == 1u );
			DummyMainF;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramStreamOutput )
	{
		sdwTestBegin( "testProgramStreamOutput" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declStreamOutput< T >( "value", 0u, 1u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isGeometryStream() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getStreamIndex() == 1u );
			DummyMainG;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testProgramStreamOutputArray )
	{
		sdwTestBegin( "testProgramStreamOutputArray" );
		{
			sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declStreamOutputArray< T >( "value", 0u, 1u, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isShaderOutput() );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isGeometryStream() );
			auto & stmt = *shader.getStatements()->back();
			astRequire( stmt.getKind() == sdw::stmt::Kind::eInOutVariableDecl );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getLocation() == 0u );
			astCheck( static_cast< sdw::stmt::InOutVariableDecl const & >( stmt ).getStreamIndex() == 1u );
			DummyMainG;
			test::writeProgram( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
