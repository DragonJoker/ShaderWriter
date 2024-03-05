#include "Common.hpp"
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
	void testConstant( test::sdw_test::TestCounts & testCounts )
	{
		astTestBegin( "testConstant" + ast::debug::getTypeName( sdw::typeEnumV< T > ) );
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
		astTestEnd();
	}
}

sdwTestSuiteMain( TestWriterConstantDeclarations )
{
	sdwTestSuiteBegin();
	testConstant< sdw::Boolean >( testCounts );
	testConstant< sdw::Int >( testCounts );
	testConstant< sdw::UInt >( testCounts );
	testConstant< sdw::Float >( testCounts );
	testConstant< sdw::Double >( testCounts );
	testConstant< sdw::Vec2 >( testCounts );
	testConstant< sdw::Vec3 >( testCounts );
	testConstant< sdw::Vec4 >( testCounts );
	testConstant< sdw::DVec2 >( testCounts );
	testConstant< sdw::DVec3 >( testCounts );
	testConstant< sdw::DVec4 >( testCounts );
	testConstant< sdw::BVec2 >( testCounts );
	testConstant< sdw::BVec3 >( testCounts );
	testConstant< sdw::BVec4 >( testCounts );
	testConstant< sdw::IVec2 >( testCounts );
	testConstant< sdw::IVec3 >( testCounts );
	testConstant< sdw::IVec4 >( testCounts );
	testConstant< sdw::UVec2 >( testCounts );
	testConstant< sdw::UVec3 >( testCounts );
	testConstant< sdw::UVec4 >( testCounts );
	testConstant< sdw::Mat2 >( testCounts );
	testConstant< sdw::Mat2x3 >( testCounts );
	testConstant< sdw::Mat2x4 >( testCounts );
	testConstant< sdw::Mat3 >( testCounts );
	testConstant< sdw::Mat3x2 >( testCounts );
	testConstant< sdw::Mat3x4 >( testCounts );
	testConstant< sdw::Mat4 >( testCounts );
	testConstant< sdw::Mat4x2 >( testCounts );
	testConstant< sdw::Mat4x3 >( testCounts );
	testConstant< sdw::DMat2 >( testCounts );
	testConstant< sdw::DMat2x3 >( testCounts );
	testConstant< sdw::DMat2x4 >( testCounts );
	testConstant< sdw::DMat3 >( testCounts );
	testConstant< sdw::DMat3x2 >( testCounts );
	testConstant< sdw::DMat3x4 >( testCounts );
	testConstant< sdw::DMat4 >( testCounts );
	testConstant< sdw::DMat4x2 >( testCounts );
	testConstant< sdw::DMat4x3 >( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterConstantDeclarations )
