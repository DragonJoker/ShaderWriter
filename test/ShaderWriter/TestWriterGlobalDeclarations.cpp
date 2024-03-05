#include "Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	template< typename T >
	void testGlobal( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testGlobal" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValue";
			auto value = writer.declGlobal< T >( name );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValueAssigned";
			auto value = writer.declGlobal< T >( name, test::getDefault< T >( writer ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValueAssignedInMain";
			auto value = writer.declGlobal< T >( name );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					value = test::getDefault< T >( writer );
					auto & sstmt = *builder.getContainer()->back();
					astCheck( sstmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValueArray12";
			auto value = writer.declGlobalArray< T >( name, 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValueArray3";
			auto value = writer.declGlobalArray< T >( name, 3u, test::getDefaultVector< T >( writer, 3u ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValueArray3AssignedInMain";
			auto value = writer.declGlobalArray< T >( name, 3u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					value[0] = test::getDefault< T >( writer );
					value[1] = test::getDefault< T >( writer );
					value[2] = test::getDefault< T >( writer );
					auto & sstmt = *builder.getContainer()->back();
					astCheck( sstmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto count = builder.getContainer()->size();
			auto value = writer.declGlobal< T >( "value", false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			astCheck( builder.getContainer()->size() == count );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto count = builder.getContainer()->size();
			auto value = writer.declGlobal< T >( "value", T{ writer, makeExpr( test::getDefault< T >( writer ) ), false } );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			astCheck( builder.getContainer()->size() == count );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto count = builder.getContainer()->size();
			auto value = writer.declGlobal< T >( "value", test::getDefault< T >( writer ), false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			astCheck( builder.getContainer()->size() == count );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto count = builder.getContainer()->size();
			auto value = writer.declGlobalArray< T >( "value", 6u, false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			astCheck( builder.getContainer()->size() == count );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto count = builder.getContainer()->size();
			auto value = writer.declGlobalArray< T >( "value", 3u, test::getDefaultVector< T >( writer, 3u ), false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			astCheck( builder.getContainer()->size() == count );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto count = builder.getContainer()->size();
			auto value = writer.declGlobalArray< T >( "value", 3u, test::getDefaultVector< T >( writer, 3u ), false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			astCheck( builder.getContainer()->size() == count );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValue_opt";
			auto value = writer.declGlobal< T >( name, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValueArray12_opt";
			auto value = writer.declGlobalArray< T >( name, 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "GlobalValueArray3_opt";
			auto value = writer.declGlobalArray< T >( name, 3u, test::getDefaultVector< T >( writer, 3u ), true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		astTestEnd();
	}
}

sdwTestSuiteMain( TestWriterGlobalDeclarations )
{
	sdwTestSuiteBegin();
	testGlobal< sdw::Boolean >( testCounts );
	testGlobal< sdw::Int >( testCounts );
	testGlobal< sdw::UInt >( testCounts );
	testGlobal< sdw::Float >( testCounts );
	testGlobal< sdw::Double >( testCounts );
	testGlobal< sdw::Vec2 >( testCounts );
	testGlobal< sdw::Vec3 >( testCounts );
	testGlobal< sdw::Vec4 >( testCounts );
	testGlobal< sdw::DVec2 >( testCounts );
	testGlobal< sdw::DVec3 >( testCounts );
	testGlobal< sdw::DVec4 >( testCounts );
	testGlobal< sdw::BVec2 >( testCounts );
	testGlobal< sdw::BVec3 >( testCounts );
	testGlobal< sdw::BVec4 >( testCounts );
	testGlobal< sdw::IVec2 >( testCounts );
	testGlobal< sdw::IVec3 >( testCounts );
	testGlobal< sdw::IVec4 >( testCounts );
	testGlobal< sdw::UVec2 >( testCounts );
	testGlobal< sdw::UVec3 >( testCounts );
	testGlobal< sdw::UVec4 >( testCounts );
	testGlobal< sdw::Mat2 >( testCounts );
	testGlobal< sdw::Mat2x3 >( testCounts );
	testGlobal< sdw::Mat2x4 >( testCounts );
	testGlobal< sdw::Mat3 >( testCounts );
	testGlobal< sdw::Mat3x2 >( testCounts );
	testGlobal< sdw::Mat3x4 >( testCounts );
	testGlobal< sdw::Mat4 >( testCounts );
	testGlobal< sdw::Mat4x2 >( testCounts );
	testGlobal< sdw::Mat4x3 >( testCounts );
	testGlobal< sdw::DMat2 >( testCounts );
	testGlobal< sdw::DMat2x3 >( testCounts );
	testGlobal< sdw::DMat2x4 >( testCounts );
	testGlobal< sdw::DMat3 >( testCounts );
	testGlobal< sdw::DMat3x2 >( testCounts );
	testGlobal< sdw::DMat3x4 >( testCounts );
	testGlobal< sdw::DMat4 >( testCounts );
	testGlobal< sdw::DMat4x2 >( testCounts );
	testGlobal< sdw::DMat4x3 >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterGlobalDeclarations )
