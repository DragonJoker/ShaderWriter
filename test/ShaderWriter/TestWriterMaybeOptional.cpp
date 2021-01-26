#include "WriterCommon.hpp"

#include "CompileGLSL.hpp"
#include "CompileHLSL.hpp"

#include <ShaderWriter/MaybeOptional/MaybeOptional.hpp>

namespace test
{
	sdw::MaybeOptional< sdw::Int > dummyFunc( sdw::MaybeOptional< sdw::Int > const & a
		, sdw::MaybeOptional< sdw::Int > const & b )
	{
		if ( isAnyOptional( a, b ) )
		{
			return sdw::Optional< sdw::Int >{ *sdw::findWriter( a, b )
				, sdw::makeExpr( *sdw::findWriter( a, b ), a + b )
				, areOptionalEnabled( a, b ) };
		}

		return sdw::Int{ *sdw::findWriter( a, b )
			, sdw::makeExpr( *sdw::findWriter( a, b ), a + b ) };
	}
	
	sdw::MaybeOptional< sdw::Int > dummyFunc( sdw::MaybeOptional< sdw::Array< sdw::Int > > const & a
		, sdw::MaybeOptional< sdw::Array< sdw::Int > > const & b )
	{
		if ( isAnyOptional( a, b ) )
		{
			return sdw::Optional< sdw::Int >{ *sdw::findWriter( a, b )
				, sdw::makeExpr( *sdw::findWriter( a, b ), a[0] + b[0] )
				, areOptionalEnabled( a, b ) };
		}

		return sdw::Int{ *sdw::findWriter( a, b )
			, sdw::makeExpr( *sdw::findWriter( a, b ), a[0] + b[0] ) };
	}

	void testMaybeOptional( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMaybeOptional" );
		using namespace sdw;
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i );
					auto b = writer.declLocale( "b", 1_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i, true );
					auto b = writer.declLocale( "b", 1_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i, false );
					auto b = writer.declLocale( "b", 1_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i );
					auto b = writer.declLocale( "b", 1_i, true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i );
					auto b = writer.declLocale( "b", 1_i, false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i, true );
					auto b = writer.declLocale( "b", 1_i, true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i, true );
					auto b = writer.declLocale( "b", 1_i, false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i, false );
					auto b = writer.declLocale( "b", 1_i, true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i, false );
					auto b = writer.declLocale( "b", 1_i, false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}

	void testMaybeOptionalArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMaybeOptionalArray" );
		using namespace sdw;
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ) );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ), true );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ), false );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ) );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ), true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ) );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ), false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ), true );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ), true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ), true );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ), false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ), false );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ), true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer, 2u ), false );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer, 2u ), false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}

	void testMaybeOptionalDefaultValue( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMaybeOptionalDefaultValue" );
		using namespace sdw;
		{
			VertexWriter writer;
			auto a = writer.declInput< Int >( "a", 0u, true );
			check( a.isEnabled() );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto b = writer.declLocale( "b", 1_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInput< Int >( "a", 0u, true, 0_i );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto b = writer.declLocale( "b", 1_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInput< Int >( "a", 0u, false );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto b = writer.declLocale( "b", 1_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInput< Int >( "a", 0u, false, 0_i );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto b = writer.declLocale( "b", 1_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto b = writer.declInput< Int >( "b", 0u, true );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto b = writer.declInput< Int >( "b", 0u, true, 1_i );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto b = writer.declInput< Int >( "b", 0u, false );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto b = writer.declInput( "b", 0u, false, 1_i );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocale( "a", 0_i );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInput( "a", 0u, false, 0_i );
			auto b = writer.declInput( "b", 1u, false, 1_i );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInput( "a", 0u, false, 0_i );
			auto b = writer.declInput< Int >( "b", 1u, false );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInput< Int >( "a", 0u, false );
			auto b = writer.declInput( "b", 1u, false, 1_i );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInput< Int >( "a", 0u, false );
			auto b = writer.declInput< Int >( "b", 1u, false );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}

	void testMaybeOptionalArrayDefaultValue( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMaybeOptionalArrayDefaultValue" );
		using namespace sdw;
		{
			VertexWriter writer;
			auto a = writer.declInputArray( "a", 0u, 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
			auto b = writer.declInputArray( "b", 1u, 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto b = writer.declInputArray( "b", 1u, 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray< Int >( "a", 2u, false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto b = writer.declInputArray( "b", 1u, 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray< Int >( "a", 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInputArray( "a", 0u, 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto b = writer.declLocaleArray< Int >( "b", 2u, false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			auto a = writer.declInputArray( "a", 0u, 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto b = writer.declLocaleArray< Int >( "b", 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray< Int >( "a", 2u, false );
					auto b = writer.declLocaleArray< Int >( "b", 2u, false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray< Int >( "a", 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
					auto b = writer.declLocaleArray< Int >( "b", 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray< Int >( "a", 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
					auto b = writer.declLocaleArray< Int >( "b", 2u, false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer;
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray< Int >( "a", 2u, false );
					auto b = writer.declLocaleArray< Int >( "b", 2u, false, test::getDefaultVector< Int >( writer, 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterMaybeOptional )
{
	sdwTestSuiteBegin();
	testMaybeOptional( testCounts );
	testMaybeOptionalArray( testCounts );
	testMaybeOptionalDefaultValue( testCounts );
	testMaybeOptionalArrayDefaultValue( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterMaybeOptional )
