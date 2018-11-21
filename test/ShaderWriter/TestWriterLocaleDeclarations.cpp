#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
#define DummyMain writer.implementFunction< void >( "main", [](){} )

	template< typename T >
	void testLocale( test::TestCounts & testCounts )
	{
		testBegin( "testLocale" + ast::debug::getName( sdw::typeEnum< T > ) );
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, test::getDefault< T >( shader ) );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray12";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 6u );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == 6u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray3";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultVector< T >( shader, 3u ) );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == 3u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocale< T >( "value", false );
					check( !value.isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocale< T >( "value", sdw::Optional< T >{ test::getDefault< T >( shader ), false } );
					check( !value.isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocale< T >( "value", test::getDefault< T >( shader ), false );
					check( !value.isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocaleArray< T >( "value", 6u, false );
					check( !value.isEnabled() );
					check( !value[0].isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == 6u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto count = shader.getContainer()->size();
					auto value = writer.declLocaleArray< T >( "value", 3u, test::getDefaultVector< T >( shader, 3u ), false );
					check( !value.isEnabled() );
					check( !value[0].isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == 3u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == "value" );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					check( shader.getContainer()->size() == count );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValue_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, true );
					check( value.isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, sdw::Optional< T >{ test::getDefault< T >( shader ), true } );
					check( value.isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueAssigned_opt2";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocale< T >( name, test::getDefault< T >( shader ), true );
					check( value.isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == sdw::type::NotArray );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray12_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 6u, true );
					check( value.isEnabled() );
					check( value[0].isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == 6u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eVariableDecl );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			sdw::FragmentWriter writer{ false };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getName( sdw::typeEnum< T > ) + "LocaleValueArray3_opt";
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto value = writer.declLocaleArray< T >( name, 3u, test::getDefaultVector< T >( shader, 3u ), true );
					check( value.isEnabled() );
					check( value[0].isEnabled() );
					check( getNonArrayKind( value.getType() ) == sdw::typeEnum< T > );
					check( getArraySize( value.getType() ) == 3u );
					require( value.getExpr()->getKind() == sdw::expr::Kind::eIdentifier );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->getName() == name );
					check( static_cast< sdw::expr::Identifier const & >( *value.getExpr() ).getVariable()->isLocale() );
					auto & stmt = *shader.getContainer()->back();
					check( stmt.getKind() == sdw::stmt::Kind::eSimple );
				} );
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterLocaleDeclarations" );
	testLocale< sdw::Boolean >( testCounts );
	testLocale< sdw::Int >( testCounts );
	testLocale< sdw::UInt >( testCounts );
	testLocale< sdw::Float >( testCounts );
	testLocale< sdw::Double >( testCounts );
	testLocale< sdw::Vec2 >( testCounts );
	testLocale< sdw::Vec3 >( testCounts );
	testLocale< sdw::Vec4 >( testCounts );
	testLocale< sdw::DVec2 >( testCounts );
	testLocale< sdw::DVec3 >( testCounts );
	testLocale< sdw::DVec4 >( testCounts );
	testLocale< sdw::BVec2 >( testCounts );
	testLocale< sdw::BVec3 >( testCounts );
	testLocale< sdw::BVec4 >( testCounts );
	testLocale< sdw::IVec2 >( testCounts );
	testLocale< sdw::IVec3 >( testCounts );
	testLocale< sdw::IVec4 >( testCounts );
	testLocale< sdw::UVec2 >( testCounts );
	testLocale< sdw::UVec3 >( testCounts );
	testLocale< sdw::UVec4 >( testCounts );
	testLocale< sdw::Mat2 >( testCounts );
	testLocale< sdw::Mat2x3 >( testCounts );
	testLocale< sdw::Mat2x4 >( testCounts );
	testLocale< sdw::Mat3 >( testCounts );
	testLocale< sdw::Mat3x2 >( testCounts );
	testLocale< sdw::Mat3x4 >( testCounts );
	testLocale< sdw::Mat4 >( testCounts );
	testLocale< sdw::Mat4x2 >( testCounts );
	testLocale< sdw::Mat4x3 >( testCounts );
	testLocale< sdw::DMat2 >( testCounts );
	testLocale< sdw::DMat2x3 >( testCounts );
	testLocale< sdw::DMat2x4 >( testCounts );
	testLocale< sdw::DMat3 >( testCounts );
	testLocale< sdw::DMat3x2 >( testCounts );
	testLocale< sdw::DMat3x4 >( testCounts );
	testLocale< sdw::DMat4 >( testCounts );
	testLocale< sdw::DMat4x2 >( testCounts );
	testLocale< sdw::DMat4x3 >( testCounts );
	testSuiteEnd();
}
