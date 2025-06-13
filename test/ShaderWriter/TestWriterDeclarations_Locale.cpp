#include "WriterCommon.hpp"

namespace
{
	using T = sdw::SDW_TestType;

	TEST_F( SDWTest, testLocaleUnassigned )
	{
		sdwTestBegin( "testLocaleUnassigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto value = writer.declLocale< T >( "value" );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *builder.getContainer()->back();
					astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleAssigned )
	{
		sdwTestBegin( "testLocaleAssigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto value = writer.declLocale< T >( "value", test::getDefault< T >( writer ) );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *builder.getContainer()->back();
					astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleArrayUnassigned )
	{
		sdwTestBegin( "testLocaleArrayUnassigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto value = writer.declLocaleArray< T >( "value", 6u );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == 6u );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *builder.getContainer()->back();
					astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleArrayAssigned )
	{
		sdwTestBegin( "testLocaleArrayAssigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto value = writer.declLocaleArray< T >( "value", 3u, test::getDefaultVector< T >( writer, 3u ) );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == 3u );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *builder.getContainer()->back();
					astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleOptionalDisabledUnassigned )
	{
		sdwTestBegin( "testLocaleOptionalDisabledUnassigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto count = builder.getContainer()->size();
					auto value = writer.declLocale< T >( "value", false );
					astCheck( !value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					astCheck( builder.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleAssignedOptionalDisabled )
	{
		sdwTestBegin( "testLocaleAssignedOptionalDisabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto count = builder.getContainer()->size();
					auto value = writer.declLocale< T >( "value", T{ writer, makeExpr( test::getDefault< T >( writer ) ), false } );
					astCheck( !value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					astCheck( builder.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleOptionalDisabledAssigned )
	{
		sdwTestBegin( "testLocaleOptionalDisabledAssigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto count = builder.getContainer()->size();
					auto value = writer.declLocale< T >( "value", test::getDefault< T >( writer ), false );
					astCheck( !value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					astCheck( builder.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleArrayOptionalDisabledUnassigned )
	{
		sdwTestBegin( "testLocaleArrayOptionalDisabledUnassigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto count = builder.getContainer()->size();
					auto value = writer.declLocaleArray< T >( "value", 6u, false );
					astCheck( !value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == 6u );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					astCheck( builder.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleArrayOptionalDisabledAssigned )
	{
		sdwTestBegin( "testShaderInputArray" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto count = builder.getContainer()->size();
					auto value = writer.declLocaleArray< T >( "value", 3u, test::getDefaultVector< T >( writer, 3u ), false );
					astCheck( !value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == 3u );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					astCheck( builder.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleOptionalEnabledUnassigned )
	{
		sdwTestBegin( "testLocaleOptionalEnabledUnassigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto value = writer.declLocale< T >( "value", true );
					astCheck( value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *builder.getContainer()->back();
					astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleArrayOptionalEnabledUnassigned )
	{
		sdwTestBegin( "testLocaleArrayOptionalEnabledUnassigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto value = writer.declLocaleArray< T >( "value", 6u, true );
					astCheck( value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == 6u );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *builder.getContainer()->back();
					astCheck( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testLocaleArrayOptionalEnabledAssigned )
	{
		sdwTestBegin( "testLocaleArrayOptionalEnabledAssigned" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & builder = writer.getBuilder();
			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto value = writer.declLocaleArray< T >( "value", 3u, test::getDefaultVector< T >( writer, 3u ), true );
					astCheck( value.isEnabled() );
					astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
					astCheck( getArraySize( value.getType() ) == 3u );
					astRequire( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					astCheck( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *builder.getContainer()->back();
					astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
