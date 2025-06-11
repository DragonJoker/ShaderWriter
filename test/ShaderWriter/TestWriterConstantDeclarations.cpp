#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
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

	template< typename T >
	void testConstantT( test::sdw_test::TestCounts & testCounts )
	{
		astOnStr( "testConstant" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "ConstantValue";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( writer ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			simpleMain( writer, value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
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
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "ConstantValue_opt";
			auto value = writer.declConstant< T >( name, test::getDefault< T >( writer ), true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == sdw::type::NotArray );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			simpleMain( writer, value );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "ConstantValue4";
			auto value = writer.declConstantArray< T >( name, test::getDefaultVector< T >( writer, 4u ) );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			arrayMain( writer, value, 4u );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
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
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto & shader = writer.getShader();
			auto name = sdw::debug::getTypeName( sdw::typeEnumV< T > ) + "ConstantValue4_opt";
			auto value = writer.declConstantArray< T >( name, test::getDefaultVector< T >( writer, 4u ), true );
			astCheck( value.isEnabled() );
			astCheck( getNonArrayKind( value.getType() ) == sdw::typeEnumV< T > );
			astCheck( getArraySize( value.getType() ) == 4u );
			auto & stmt = *shader.getStatements()->back();
			astCheck( stmt.getKind() == sdw::stmt::Kind::eSimple );
			arrayMain( writer, value, 4u );
			test::writeShader( writer, testCounts, CurrentCompilers );
		}
	}

	TEST( SDW_TestSuiteName, testConstant )
	{
		sdwTestBegin( "testConstant" );
		testConstantT< sdw::Boolean >( testCounts );
		testConstantT< sdw::Int >( testCounts );
		testConstantT< sdw::UInt >( testCounts );
		testConstantT< sdw::Float >( testCounts );
		testConstantT< sdw::Double >( testCounts );
		testConstantT< sdw::Vec2 >( testCounts );
		testConstantT< sdw::Vec3 >( testCounts );
		testConstantT< sdw::Vec4 >( testCounts );
		testConstantT< sdw::DVec2 >( testCounts );
		testConstantT< sdw::DVec3 >( testCounts );
		testConstantT< sdw::DVec4 >( testCounts );
		testConstantT< sdw::BVec2 >( testCounts );
		testConstantT< sdw::BVec3 >( testCounts );
		testConstantT< sdw::BVec4 >( testCounts );
		testConstantT< sdw::IVec2 >( testCounts );
		testConstantT< sdw::IVec3 >( testCounts );
		testConstantT< sdw::IVec4 >( testCounts );
		testConstantT< sdw::UVec2 >( testCounts );
		testConstantT< sdw::UVec3 >( testCounts );
		testConstantT< sdw::UVec4 >( testCounts );
		testConstantT< sdw::Mat2 >( testCounts );
		testConstantT< sdw::Mat2x3 >( testCounts );
		testConstantT< sdw::Mat2x4 >( testCounts );
		testConstantT< sdw::Mat3 >( testCounts );
		testConstantT< sdw::Mat3x2 >( testCounts );
		testConstantT< sdw::Mat3x4 >( testCounts );
		testConstantT< sdw::Mat4 >( testCounts );
		testConstantT< sdw::Mat4x2 >( testCounts );
		testConstantT< sdw::Mat4x3 >( testCounts );
		testConstantT< sdw::DMat2 >( testCounts );
		testConstantT< sdw::DMat2x3 >( testCounts );
		testConstantT< sdw::DMat2x4 >( testCounts );
		testConstantT< sdw::DMat3 >( testCounts );
		testConstantT< sdw::DMat3x2 >( testCounts );
		testConstantT< sdw::DMat3x4 >( testCounts );
		testConstantT< sdw::DMat4 >( testCounts );
		testConstantT< sdw::DMat4x2 >( testCounts );
		testConstantT< sdw::DMat4x3 >( testCounts );
		sdwTestEnd();
	}
}

sdwTestSuiteMain()
