#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	using T = sdw::SDW_TestType;

	void dummyMain( sdw::FragmentWriter & writer )
	{
		writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
			{
			} );
	}

	template< typename T >
	void simpleMain( sdw::FragmentWriter & writer
		, T const & value )
	{
		writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
			{
				auto outValue = writer.declLocale< T >( "outValue", value );
			} );
	}

	template< typename T >
	void arrayMain( sdw::FragmentWriter & writer
		, sdw::Array< T > const & value
		, uint32_t size )
	{
		writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
			{
				auto outValue = writer.declLocaleArray< T >( "outValue", size );
				for ( uint32_t i = 0u; i < size; ++i )
				{
					outValue[i] = value[i];
				}
			} );
	}

	TEST_F( SDWTest, testConstant )
	{
		sdwTestBegin( "testConstant" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declConstant< T >( "value", test::getDefault< T >( writer ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			simpleMain( writer, value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testConstantOptionalDisabled )
	{
		sdwTestBegin( "testConstantOptionalDisabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declConstant< T >( "value", test::getDefault< T >( writer ), false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			astCheck( shader.getStatements()->size() == count );
			dummyMain( writer );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testConstantOptionalEnabled )
	{
		sdwTestBegin( "testConstantOptionalEnabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declConstant< T >( "value", test::getDefault< T >( writer ), true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			simpleMain( writer, value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testConstantArray )
	{
		sdwTestBegin( "testConstantArray" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declConstantArray< T >( "value", test::getDefaultVector< T >( writer, 4u ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			arrayMain( writer, value, 4u );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testConstantArrayOptionalDisabled )
	{
		sdwTestBegin( "testConstantArrayOptionalDisabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto count = shader.getStatements()->size();
			auto value = writer.declConstantArray< T >( "value", test::getDefaultVector< T >( writer, 4u ), false );
			astCheck( !value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			astCheck( shader.getStatements()->size() == count );
			dummyMain( writer );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testConstantArrayOptionalEnabled )
	{
		sdwTestBegin( "testConstantArrayOptionalEnabled" );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto value = writer.declConstantArray< T >( "value", test::getDefaultVector< T >( writer, 4u ), true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			arrayMain( writer, value, 4u );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
