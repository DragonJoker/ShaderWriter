#include "WriterCommon.hpp"

namespace
{
	using T = sdw::SDW_TestType;

	TEST_F( SDWTest, testGlobalUnassigned )
	{
		sdwTestBegin( "testGlobalUnassigned" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobal< T >( "value" );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalAssigned )
	{
		sdwTestBegin( "testGlobalAssigned" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobal< T >( "value", test::getDefault< T >( writer ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalAssignedInMain )
	{
		sdwTestBegin( "testGlobalAssignedInMain" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobal< T >( "value" );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalArrayUnassigned )
	{
		sdwTestBegin( "testGlobalArrayUnassigned" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobalArray< T >( "value", 6u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalArrayAssigned )
	{
		sdwTestBegin( "testGlobalArrayAssigned" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobalArray< T >( "value", 3u, test::getDefaultVector< T >( writer, 3u ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalArrayAssignedInMain )
	{
		sdwTestBegin( "testGlobalArrayAssignedInMain" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobalArray< T >( "value", 3u );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalOptionalDisabledUnassigned )
	{
		sdwTestBegin( "testGlobalOptionalDisabledUnassigned" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalAssignedOptionalDisabled )
	{
		sdwTestBegin( "testGlobalAssignedOptionalDisabled" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalOptionalDisabledAssigned )
	{
		sdwTestBegin( "testGlobalOptionalDisabledAssigned" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalArrayOptionalDisabledUnassigned )
	{
		sdwTestBegin( "testGlobalArrayOptionalDisabledUnassigned" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalArrayOptionalDisabledAssigned )
	{
		sdwTestBegin( "testShaderInputArray" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalOptionalEnabledUnassigned )
	{
		sdwTestBegin( "testGlobalOptionalEnabledUnassigned" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobal< T >( "value", true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalArrayOptionalEnabledUnassigned )
	{
		sdwTestBegin( "testGlobalArrayOptionalEnabledUnassigned" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobalArray< T >( "value", 6u, true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 6u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGlobalArrayOptionalEnabledAssigned )
	{
		sdwTestBegin( "testGlobalArrayOptionalEnabledAssigned" );
		{
			sdw::FragmentWriter writer;
			auto & builder = writer.getBuilder();
			auto value = writer.declGlobalArray< T >( "value", 3u, test::getDefaultVector< T >( writer, 3u ), true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 3u );
			astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
			astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isStatic() );
			auto & stmt = *builder.getContainer()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
