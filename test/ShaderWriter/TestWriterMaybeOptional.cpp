#include "WriterCommon.hpp"

#include "CompileGLSL.hpp"
#include "CompileHLSL.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>
#include <ShaderWriter/MaybeOptional/MaybeOptional.hpp>

#include "spirv_cpp.hpp"
#include "spirv_cross_util.hpp"
#include "spirv_glsl.hpp"
#include "spirv_hlsl.hpp"

#define SDW_Test_DisplayShaders 0

namespace test
{
	sdw::MaybeOptional< sdw::Int > dummyFunc( sdw::MaybeOptional< sdw::Int > const & a
		, sdw::MaybeOptional< sdw::Int > const & b )
	{
		if ( isAnyOptional( a, b ) )
		{
			return sdw::Optional< sdw::Int >{ sdw::findShader( a, b )
				, sdw::makeExpr( a + b )
				, areOptionalEnabled( a, b ) };
		}

		return sdw::Int{ sdw::findShader( a, b )
			, sdw::makeExpr( a + b ) };
	}
	
	sdw::MaybeOptional< sdw::Int > dummyFunc( sdw::MaybeOptional< sdw::Array< sdw::Int > > const & a
		, sdw::MaybeOptional< sdw::Array< sdw::Int > > const & b )
	{
		if ( isAnyOptional( a, b ) )
		{
			return sdw::Optional< sdw::Int >{ sdw::findShader( a, b )
				, sdw::makeExpr( a[0] + b[0] )
				, areOptionalEnabled( a, b ) };
		}

		return sdw::Int{ sdw::findShader( a, b )
			, sdw::makeExpr( a[0] + b[0] ) };
	}

	void testMaybeOptional( test::TestCounts & testCounts )
	{
		testBegin( "testMaybeOptional" );
		using namespace sdw;
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
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

	void testMaybeOptionalArray( test::TestCounts & testCounts )
	{
		testBegin( "testMaybeOptionalArray" );
		using namespace sdw;
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ) );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( !c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), true );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), false );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ) );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ) );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ) );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), true );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), true );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), false );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), true );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		{
			VertexWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto a = writer.declLocaleArray( "a", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), false );
					auto b = writer.declLocaleArray( "b", 2u, test::getDefaultVector< Int >( writer.getShader(), 2u ), false );
					auto c = writer.declLocale( "c", dummyFunc( a, b ) );
					check( c.isOptional() );
					check( !c.isEnabled() );
				} );
			test::writeShader( writer, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterMaybeOptional" );
	testMaybeOptional( testCounts );
	testMaybeOptionalArray( testCounts );
	testSuiteEnd();
}
