#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

namespace
{
	void testRoundEven1F()
	{
		testBegin( "testRoundEven1F" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testRoundEven2F()
	{
		testBegin( "testRoundEven2F" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testRoundEven3F()
	{
		testBegin( "testRoundEven3F" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testRoundEven4F()
	{
		testBegin( "testRoundEven4F" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testRoundEven1D()
	{
		testBegin( "testRoundEven1D" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testRoundEven2D()
	{
		testBegin( "testRoundEven2D" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testRoundEven3D()
	{
		testBegin( "testRoundEven3D" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testRoundEven4D()
	{
		testBegin( "testRoundEven4D" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testPackDouble2x32()
	{
		testBegin( "testPackDouble2x32" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UVec2 >( "v" );
					auto r = writer.declLocale< Double >( "r" );
					r = packDouble2x32( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testPackHalf2x16()
	{
		testBegin( "testPackHalf2x16" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packHalf2x16( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testPackSnorm2x16()
	{
		testBegin( "testPackSnorm2x16" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm2x16( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testPackUnorm2x16()
	{
		testBegin( "testPackUnorm2x16" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm2x16( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testPackSnorm4x8()
	{
		testBegin( "testPackSnorm4x8" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm4x8( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testPackUnorm4x8()
	{
		testBegin( "testPackUnorm4x8" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm4x8( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testUnpackDouble2x32()
	{
		testBegin( "testUnpackDouble2x32" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					auto r = writer.declLocale< UVec2 >( "r" );
					r = unpackDouble2x32( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testUnpackHalf2x16()
	{
		testBegin( "testUnpackHalf2x16" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackHalf2x16( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testUnpackSnorm2x16()
	{
		testBegin( "testUnpackSnorm2x16" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackSnorm2x16( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testUnpackUnorm2x16()
	{
		testBegin( "testUnpackUnorm2x16" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackUnorm2x16( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testUnpackSnorm4x8()
	{
		testBegin( "testUnpackSnorm4x8" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackSnorm4x8( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testUnpackUnorm4x8()
	{
		testBegin( "testUnpackUnorm4x8" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackUnorm4x8( v );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	template< typename ValueT >
	void testLessThan( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThan( lhs, rhs ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testLessThan2F()
	{
		testBegin( "testLessThan2F" );
		testLessThan< sdw::Vec2 >( testName );
		testEnd();
	}

	void testLessThan3F()
	{
		testBegin( "testLessThan3F" );
		testLessThan< sdw::Vec3 >( testName );
		testEnd();
	}

	void testLessThan4F()
	{
		testBegin( "testLessThan4F" );
		testLessThan< sdw::Vec4 >( testName );
		testEnd();
	}

	void testLessThan2D()
	{
		testBegin( "testLessThan2D" );
		testLessThan< sdw::DVec2 >( testName );
		testEnd();
	}

	void testLessThan3D()
	{
		testBegin( "testLessThan3D" );
		testLessThan< sdw::DVec3 >( testName );
		testEnd();
	}

	void testLessThan4D()
	{
		testBegin( "testLessThan4D" );
		testLessThan< sdw::DVec4 >( testName );
		testEnd();
	}

	void testLessThan2I()
	{
		testBegin( "testLessThan2I" );
		testLessThan< sdw::IVec2 >( testName );
		testEnd();
	}

	void testLessThan3I()
	{
		testBegin( "testLessThan3I" );
		testLessThan< sdw::IVec3 >( testName );
		testEnd();
	}

	void testLessThan4I()
	{
		testBegin( "testLessThan4I" );
		testLessThan< sdw::IVec4 >( testName );
		testEnd();
	}

	void testLessThan2U()
	{
		testBegin( "testLessThan2U" );
		testLessThan< sdw::UVec2 >( testName );
		testEnd();
	}

	void testLessThan3U()
	{
		testBegin( "testLessThan3U" );
		testLessThan< sdw::UVec3 >( testName );
		testEnd();
	}

	void testLessThan4U()
	{
		testBegin( "testLessThan4U" );
		testLessThan< sdw::UVec4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testLessThanEqual( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testLessThanEqual2F()
	{
		testBegin( "testLessThanEqual2F" );
		testLessThanEqual< sdw::Vec2 >( testName );
		testEnd();
	}

	void testLessThanEqual3F()
	{
		testBegin( "testLessThanEqual3F" );
		testLessThanEqual< sdw::Vec3 >( testName );
		testEnd();
	}

	void testLessThanEqual4F()
	{
		testBegin( "testLessThanEqual4F" );
		testLessThanEqual< sdw::Vec4 >( testName );
		testEnd();
	}

	void testLessThanEqual2D()
	{
		testBegin( "testLessThanEqual2D" );
		testLessThanEqual< sdw::DVec2 >( testName );
		testEnd();
	}

	void testLessThanEqual3D()
	{
		testBegin( "testLessThanEqual3D" );
		testLessThanEqual< sdw::DVec3 >( testName );
		testEnd();
	}

	void testLessThanEqual4D()
	{
		testBegin( "testLessThanEqual4D" );
		testLessThanEqual< sdw::DVec4 >( testName );
		testEnd();
	}

	void testLessThanEqual2I()
	{
		testBegin( "testLessThanEqual2I" );
		testLessThanEqual< sdw::IVec2 >( testName );
		testEnd();
	}

	void testLessThanEqual3I()
	{
		testBegin( "testLessThanEqual3I" );
		testLessThanEqual< sdw::IVec3 >( testName );
		testEnd();
	}

	void testLessThanEqual4I()
	{
		testBegin( "testLessThanEqual4I" );
		testLessThanEqual< sdw::IVec4 >( testName );
		testEnd();
	}

	void testLessThanEqual2U()
	{
		testBegin( "testLessThanEqual2U" );
		testLessThanEqual< sdw::UVec2 >( testName );
		testEnd();
	}

	void testLessThanEqual3U()
	{
		testBegin( "testLessThanEqual3U" );
		testLessThanEqual< sdw::UVec3 >( testName );
		testEnd();
	}

	void testLessThanEqual4U()
	{
		testBegin( "testLessThanEqual4U" );
		testLessThanEqual< sdw::UVec4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testGreaterThan( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThan( lhs, rhs ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testGreaterThan2F()
	{
		testBegin( "testGreaterThan2F" );
		testGreaterThan< sdw::Vec2 >( testName );
		testEnd();
	}

	void testGreaterThan3F()
	{
		testBegin( "testGreaterThan3F" );
		testGreaterThan< sdw::Vec3 >( testName );
		testEnd();
	}

	void testGreaterThan4F()
	{
		testBegin( "testGreaterThan4F" );
		testGreaterThan< sdw::Vec4 >( testName );
		testEnd();
	}

	void testGreaterThan2D()
	{
		testBegin( "testGreaterThan2D" );
		testGreaterThan< sdw::DVec2 >( testName );
		testEnd();
	}

	void testGreaterThan3D()
	{
		testBegin( "testGreaterThan3D" );
		testGreaterThan< sdw::DVec3 >( testName );
		testEnd();
	}

	void testGreaterThan4D()
	{
		testBegin( "testGreaterThan4D" );
		testGreaterThan< sdw::DVec4 >( testName );
		testEnd();
	}

	void testGreaterThan2I()
	{
		testBegin( "testGreaterThan2I" );
		testGreaterThan< sdw::IVec2 >( testName );
		testEnd();
	}

	void testGreaterThan3I()
	{
		testBegin( "testGreaterThan3I" );
		testGreaterThan< sdw::IVec3 >( testName );
		testEnd();
	}

	void testGreaterThan4I()
	{
		testBegin( "testGreaterThan4I" );
		testGreaterThan< sdw::IVec4 >( testName );
		testEnd();
	}

	void testGreaterThan2U()
	{
		testBegin( "testGreaterThan2U" );
		testGreaterThan< sdw::UVec2 >( testName );
		testEnd();
	}

	void testGreaterThan3U()
	{
		testBegin( "testGreaterThan3U" );
		testGreaterThan< sdw::UVec3 >( testName );
		testEnd();
	}

	void testGreaterThan4U()
	{
		testBegin( "testGreaterThan4U" );
		testGreaterThan< sdw::UVec4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testGreaterThanEqual( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testGreaterThanEqual2F()
	{
		testBegin( "testGreaterThanEqual2F" );
		testGreaterThanEqual< sdw::Vec2 >( testName );
		testEnd();
	}

	void testGreaterThanEqual3F()
	{
		testBegin( "testGreaterThanEqual3F" );
		testGreaterThanEqual< sdw::Vec3 >( testName );
		testEnd();
	}

	void testGreaterThanEqual4F()
	{
		testBegin( "testGreaterThanEqual4F" );
		testGreaterThanEqual< sdw::Vec4 >( testName );
		testEnd();
	}

	void testGreaterThanEqual2D()
	{
		testBegin( "testGreaterThanEqual2D" );
		testGreaterThanEqual< sdw::DVec2 >( testName );
		testEnd();
	}

	void testGreaterThanEqual3D()
	{
		testBegin( "testGreaterThanEqual3D" );
		testGreaterThanEqual< sdw::DVec3 >( testName );
		testEnd();
	}

	void testGreaterThanEqual4D()
	{
		testBegin( "testGreaterThanEqual4D" );
		testGreaterThanEqual< sdw::DVec4 >( testName );
		testEnd();
	}

	void testGreaterThanEqual2I()
	{
		testBegin( "testGreaterThanEqual2I" );
		testGreaterThanEqual< sdw::IVec2 >( testName );
		testEnd();
	}

	void testGreaterThanEqual3I()
	{
		testBegin( "testGreaterThanEqual3I" );
		testGreaterThanEqual< sdw::IVec3 >( testName );
		testEnd();
	}

	void testGreaterThanEqual4I()
	{
		testBegin( "testGreaterThanEqual4I" );
		testGreaterThanEqual< sdw::IVec4 >( testName );
		testEnd();
	}

	void testGreaterThanEqual2U()
	{
		testBegin( "testGreaterThanEqual2U" );
		testGreaterThanEqual< sdw::UVec2 >( testName );
		testEnd();
	}

	void testGreaterThanEqual3U()
	{
		testBegin( "testGreaterThanEqual3U" );
		testGreaterThanEqual< sdw::UVec3 >( testName );
		testEnd();
	}

	void testGreaterThanEqual4U()
	{
		testBegin( "testGreaterThanEqual4U" );
		testGreaterThanEqual< sdw::UVec4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testEqual( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, equal( lhs, rhs ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testEqual2F()
	{
		testBegin( "testEqual2F" );
		testEqual< sdw::Vec2 >( testName );
		testEnd();
	}

	void testEqual3F()
	{
		testBegin( "testEqual3F" );
		testEqual< sdw::Vec3 >( testName );
		testEnd();
	}

	void testEqual4F()
	{
		testBegin( "testEqual4F" );
		testEqual< sdw::Vec4 >( testName );
		testEnd();
	}

	void testEqual2D()
	{
		testBegin( "testEqual2D" );
		testEqual< sdw::DVec2 >( testName );
		testEnd();
	}

	void testEqual3D()
	{
		testBegin( "testEqual3D" );
		testEqual< sdw::DVec3 >( testName );
		testEnd();
	}

	void testEqual4D()
	{
		testBegin( "testEqual4D" );
		testEqual< sdw::DVec4 >( testName );
		testEnd();
	}

	void testEqual2I()
	{
		testBegin( "testEqual2I" );
		testEqual< sdw::IVec2 >( testName );
		testEnd();
	}

	void testEqual3I()
	{
		testBegin( "testEqual3I" );
		testEqual< sdw::IVec3 >( testName );
		testEnd();
	}

	void testEqual4I()
	{
		testBegin( "testEqual4I" );
		testEqual< sdw::IVec4 >( testName );
		testEnd();
	}

	void testEqual2U()
	{
		testBegin( "testEqual2U" );
		testEqual< sdw::UVec2 >( testName );
		testEnd();
	}

	void testEqual3U()
	{
		testBegin( "testEqual3U" );
		testEqual< sdw::UVec3 >( testName );
		testEnd();
	}

	void testEqual4U()
	{
		testBegin( "testEqual4U" );
		testEqual< sdw::UVec4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testNotEqual( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, notEqual( lhs, rhs ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testNotEqual2F()
	{
		testBegin( "testNotEqual2F" );
		testNotEqual< sdw::Vec2 >( testName );
		testEnd();
	}

	void testNotEqual3F()
	{
		testBegin( "testNotEqual3F" );
		testNotEqual< sdw::Vec3 >( testName );
		testEnd();
	}

	void testNotEqual4F()
	{
		testBegin( "testNotEqual4F" );
		testNotEqual< sdw::Vec4 >( testName );
		testEnd();
	}

	void testNotEqual2D()
	{
		testBegin( "testNotEqual2D" );
		testNotEqual< sdw::DVec2 >( testName );
		testEnd();
	}

	void testNotEqual3D()
	{
		testBegin( "testNotEqual3D" );
		testNotEqual< sdw::DVec3 >( testName );
		testEnd();
	}

	void testNotEqual4D()
	{
		testBegin( "testNotEqual4D" );
		testNotEqual< sdw::DVec4 >( testName );
		testEnd();
	}

	void testNotEqual2I()
	{
		testBegin( "testNotEqual2I" );
		testNotEqual< sdw::IVec2 >( testName );
		testEnd();
	}

	void testNotEqual3I()
	{
		testBegin( "testNotEqual3I" );
		testNotEqual< sdw::IVec3 >( testName );
		testEnd();
	}

	void testNotEqual4I()
	{
		testBegin( "testNotEqual4I" );
		testNotEqual< sdw::IVec4 >( testName );
		testEnd();
	}

	void testNotEqual2U()
	{
		testBegin( "testNotEqual2U" );
		testNotEqual< sdw::UVec2 >( testName );
		testEnd();
	}

	void testNotEqual3U()
	{
		testBegin( "testNotEqual3U" );
		testNotEqual< sdw::UVec3 >( testName );
		testEnd();
	}

	void testNotEqual4U()
	{
		testBegin( "testNotEqual4U" );
		testNotEqual< sdw::UVec4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testNot( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto operand = writer.declLocale< ValueT >( "operand" );
					auto res = writer.declLocale( "res"
						, not( operand ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testNot2()
	{
		testBegin( "testNot2" );
		testNot< sdw::BVec2 >( testName );
		testEnd();
	}

	void testNot3()
	{
		testBegin( "testNot3" );
		testNot< sdw::BVec3 >( testName );
		testEnd();
	}

	void testNot4()
	{
		testBegin( "testNot4" );
		testNot< sdw::BVec4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testMatrixCompMult( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, matrixCompMult( lhs, rhs ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testMatrixCompMult2x2F()
	{
		testBegin( "testMatrixCompMult2x2F" );
		testMatrixCompMult< sdw::Mat2 >( testName );
		testEnd();
	}

	void testMatrixCompMult2x3F()
	{
		testBegin( "testMatrixCompMult2x3F" );
		testMatrixCompMult< sdw::Mat2x3 >( testName );
		testEnd();
	}

	void testMatrixCompMult2x4F()
	{
		testBegin( "testMatrixCompMult2x4F" );
		testMatrixCompMult< sdw::Mat2x4 >( testName );
		testEnd();
	}

	void testMatrixCompMult3x2F()
	{
		testBegin( "testMatrixCompMult3x2F" );
		testMatrixCompMult< sdw::Mat3x2 >( testName );
		testEnd();
	}

	void testMatrixCompMult3x3F()
	{
		testBegin( "testMatrixCompMult3x3F" );
		testMatrixCompMult< sdw::Mat3 >( testName );
		testEnd();
	}

	void testMatrixCompMult3x4F()
	{
		testBegin( "testMatrixCompMult3x4F" );
		testMatrixCompMult< sdw::Mat3x4 >( testName );
		testEnd();
	}

	void testMatrixCompMult4x2F()
	{
		testBegin( "testMatrixCompMult4x2F" );
		testMatrixCompMult< sdw::Mat4x2 >( testName );
		testEnd();
	}

	void testMatrixCompMult4x3F()
	{
		testBegin( "testMatrixCompMult4x3F" );
		testMatrixCompMult< sdw::Mat4x3 >( testName );
		testEnd();
	}

	void testMatrixCompMult4x4F()
	{
		testBegin( "testMatrixCompMult4x4F" );
		testMatrixCompMult< sdw::Mat4 >( testName );
		testEnd();
	}

	void testMatrixCompMult2x2D()
	{
		testBegin( "testMatrixCompMult2x2D" );
		testMatrixCompMult< sdw::DMat2 >( testName );
		testEnd();
	}

	void testMatrixCompMult2x3D()
	{
		testBegin( "testMatrixCompMult2x3D" );
		testMatrixCompMult< sdw::DMat2x3 >( testName );
		testEnd();
	}

	void testMatrixCompMult2x4D()
	{
		testBegin( "testMatrixCompMult2x4D" );
		testMatrixCompMult< sdw::DMat2x4 >( testName );
		testEnd();
	}

	void testMatrixCompMult3x2D()
	{
		testBegin( "testMatrixCompMult3x2D" );
		testMatrixCompMult< sdw::DMat3x2 >( testName );
		testEnd();
	}

	void testMatrixCompMult3x3D()
	{
		testBegin( "testMatrixCompMult3x3D" );
		testMatrixCompMult< sdw::DMat3 >( testName );
		testEnd();
	}

	void testMatrixCompMult3x4D()
	{
		testBegin( "testMatrixCompMult3x4D" );
		testMatrixCompMult< sdw::DMat3x4 >( testName );
		testEnd();
	}

	void testMatrixCompMult4x2D()
	{
		testBegin( "testMatrixCompMult4x2D" );
		testMatrixCompMult< sdw::DMat4x2 >( testName );
		testEnd();
	}

	void testMatrixCompMult4x3D()
	{
		testBegin( "testMatrixCompMult4x3D" );
		testMatrixCompMult< sdw::DMat4x3 >( testName );
		testEnd();
	}

	void testMatrixCompMult4x4D()
	{
		testBegin( "testMatrixCompMult4x4D" );
		testMatrixCompMult< sdw::DMat4 >( testName );
		testEnd();
	}

	template< typename ValueT >
	void testMatrixMult( std::string const & testName )
	{
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lhs * rhs );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
	}

	void testMatrixMult2x2F()
	{
		testBegin( "testMatrixMult2x2F" );
		testMatrixMult< sdw::Mat2 >( testName );
		testEnd();
	}

	void testMatrixMult3x3F()
	{
		testBegin( "testMatrixMult3x3F" );
		testMatrixMult< sdw::Mat3 >( testName );
		testEnd();
	}

	void testMatrixMult4x4F()
	{
		testBegin( "testMatrixMult4x4F" );
		testMatrixMult< sdw::Mat4 >( testName );
		testEnd();
	}

	void testMatrixMult2x2D()
	{
		testBegin( "testMatrixMult2x2D" );
		testMatrixMult< sdw::DMat2 >( testName );
		testEnd();
	}

	void testMatrixMult3x3D()
	{
		testBegin( "testMatrixMult3x3D" );
		testMatrixMult< sdw::DMat3 >( testName );
		testEnd();
	}

	void testMatrixMult4x4D()
	{
		testBegin( "testMatrixMult4x4D" );
		testMatrixMult< sdw::DMat4 >( testName );
		testEnd();
	}

	void testInverse2x2F()
	{
		testBegin( "testInverse2x2F" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat2 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testInverse2x2D()
	{
		testBegin( "testInverse2x2D" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat2 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testInverse3x3F()
	{
		testBegin( "testInverse3x3F" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat3 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testInverse3x3D()
	{
		testBegin( "testInverse3x3D" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat3 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testInverse4x4F()
	{
		testBegin( "testInverse4x4F" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat4 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testInverse4x4D()
	{
		testBegin( "testInverse4x4D" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat4 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testUaddCarry1()
	{
		testBegin( "testUaddCarry1" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto c = writer.declLocale< UInt >( "c" );
					auto r = writer.declLocale< UInt >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUaddCarry2()
	{
		testBegin( "testUaddCarry2" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto c = writer.declLocale< UVec2 >( "c" );
					auto r = writer.declLocale< UVec2 >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUaddCarry3()
	{
		testBegin( "testUaddCarry3" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto c = writer.declLocale< UVec3 >( "c" );
					auto r = writer.declLocale< UVec3 >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUaddCarry4()
	{
		testBegin( "testUaddCarry4" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto c = writer.declLocale< UVec4 >( "c" );
					auto r = writer.declLocale< UVec4 >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUsubBorrow1()
	{
		testBegin( "testUsubBorrow1" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto b = writer.declLocale< UInt >( "b" );
					auto r = writer.declLocale< UInt >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUsubBorrow2()
	{
		testBegin( "testUsubBorrow2" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto b = writer.declLocale< UVec2 >( "b" );
					auto r = writer.declLocale< UVec2 >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUsubBorrow3()
	{
		testBegin( "testUsubBorrow3" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto b = writer.declLocale< UVec3 >( "b" );
					auto r = writer.declLocale< UVec3 >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUsubBorrow4()
	{
		testBegin( "testUsubBorrow4" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto b = writer.declLocale< UVec4 >( "b" );
					auto r = writer.declLocale< UVec4 >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUmulExtended1()
	{
		testBegin( "testUmulExtended1" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto h = writer.declLocale< UInt >( "h" );
					auto l = writer.declLocale< UInt >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUmulExtended2()
	{
		testBegin( "testUmulExtended2" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto h = writer.declLocale< UVec2 >( "h" );
					auto l = writer.declLocale< UVec2 >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUmulExtended3()
	{
		testBegin( "testUmulExtended3" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto h = writer.declLocale< UVec3 >( "h" );
					auto l = writer.declLocale< UVec3 >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testUmulExtended4()
	{
		testBegin( "testUmulExtended4" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto h = writer.declLocale< UVec4 >( "h" );
					auto l = writer.declLocale< UVec4 >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testImulExtended1()
	{
		testBegin( "testImulExtended1" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto y = writer.declLocale< Int >( "y" );
					auto h = writer.declLocale< Int >( "h" );
					auto l = writer.declLocale< Int >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testImulExtended2()
	{
		testBegin( "testImulExtended2" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto y = writer.declLocale< IVec2 >( "y" );
					auto h = writer.declLocale< IVec2 >( "h" );
					auto l = writer.declLocale< IVec2 >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testImulExtended3()
	{
		testBegin( "testImulExtended3" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto y = writer.declLocale< IVec3 >( "y" );
					auto h = writer.declLocale< IVec3 >( "h" );
					auto l = writer.declLocale< IVec3 >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testImulExtended4()
	{
		testBegin( "testImulExtended4" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto y = writer.declLocale< IVec4 >( "y" );
					auto h = writer.declLocale< IVec4 >( "h" );
					auto l = writer.declLocale< IVec4 >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment
				, false );
		}
		testEnd();
	}

	void testBitfieldInsert1I()
	{
		testBegin( "testBitfieldInsert1I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto y = writer.declLocale< Int >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldInsert2I()
	{
		testBegin( "testBitfieldInsert2I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto y = writer.declLocale< IVec2 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldInsert3I()
	{
		testBegin( "testBitfieldInsert3I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto y = writer.declLocale< IVec3 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldInsert4I()
	{
		testBegin( "testBitfieldInsert4I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto y = writer.declLocale< IVec4 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldInsert1U()
	{
		testBegin( "testBitfieldInsert1U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldInsert2U()
	{
		testBegin( "testBitfieldInsert2U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldInsert3U()
	{
		testBegin( "testBitfieldInsert3U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldInsert4U()
	{
		testBegin( "testBitfieldInsert4U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract1I()
	{
		testBegin( "testBitfieldExtract1I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract2I()
	{
		testBegin( "testBitfieldExtract2I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract3I()
	{
		testBegin( "testBitfieldExtract3I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract4I()
	{
		testBegin( "testBitfieldExtract4I" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract1U()
	{
		testBegin( "testBitfieldExtract1U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract2U()
	{
		testBegin( "testBitfieldExtract2U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract3U()
	{
		testBegin( "testBitfieldExtract3U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}

	void testBitfieldExtract4U()
	{
		testBegin( "testBitfieldExtract4U" );
		using namespace sdw;
		{
			ShaderWriter writer{ false };
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer.getShader()
				, sdw::ShaderType::eFragment );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterIntrinsics" );
	testRoundEven1F();
	testRoundEven2F();
	testRoundEven3F();
	testRoundEven4F();
	testRoundEven1D();
	testRoundEven2D();
	testRoundEven3D();
	testRoundEven4D();
	testPackDouble2x32();
	testPackHalf2x16();
	testPackSnorm2x16();
	testPackUnorm2x16();
	testPackSnorm4x8();
	testPackUnorm4x8();
	testUnpackDouble2x32();
	testUnpackHalf2x16();
	testUnpackSnorm2x16();
	testUnpackUnorm2x16();
	testUnpackSnorm4x8();
	testUnpackUnorm4x8();
	testLessThan2F();
	testLessThan3F();
	testLessThan4F();
	testLessThan2D();
	testLessThan3D();
	testLessThan4D();
	testLessThan2I();
	testLessThan3I();
	testLessThan4I();
	testLessThan2U();
	testLessThan3U();
	testLessThan4U();
	testLessThanEqual2F();
	testLessThanEqual3F();
	testLessThanEqual4F();
	testLessThanEqual2D();
	testLessThanEqual3D();
	testLessThanEqual4D();
	testLessThanEqual2I();
	testLessThanEqual3I();
	testLessThanEqual4I();
	testLessThanEqual2U();
	testLessThanEqual3U();
	testLessThanEqual4U();
	testGreaterThan2F();
	testGreaterThan3F();
	testGreaterThan4F();
	testGreaterThan2D();
	testGreaterThan3D();
	testGreaterThan4D();
	testGreaterThan2I();
	testGreaterThan3I();
	testGreaterThan4I();
	testGreaterThan2U();
	testGreaterThan3U();
	testGreaterThan4U();
	testGreaterThanEqual2F();
	testGreaterThanEqual3F();
	testGreaterThanEqual4F();
	testGreaterThanEqual2D();
	testGreaterThanEqual3D();
	testGreaterThanEqual4D();
	testGreaterThanEqual2I();
	testGreaterThanEqual3I();
	testGreaterThanEqual4I();
	testGreaterThanEqual2U();
	testGreaterThanEqual3U();
	testGreaterThanEqual4U();
	testEqual2F();
	testEqual3F();
	testEqual4F();
	testEqual2D();
	testEqual3D();
	testEqual4D();
	testEqual2I();
	testEqual3I();
	testEqual4I();
	testEqual2U();
	testEqual3U();
	testEqual4U();
	testNotEqual2F();
	testNotEqual3F();
	testNotEqual4F();
	testNotEqual2D();
	testNotEqual3D();
	testNotEqual4D();
	testNotEqual2I();
	testNotEqual3I();
	testNotEqual4I();
	testNotEqual2U();
	testNotEqual3U();
	testNotEqual4U();
	testNot2();
	testNot3();
	testNot4();
	testMatrixCompMult2x2F();
	testMatrixCompMult2x3F();
	testMatrixCompMult2x4F();
	testMatrixCompMult3x2F();
	testMatrixCompMult3x3F();
	testMatrixCompMult3x4F();
	testMatrixCompMult4x2F();
	testMatrixCompMult4x3F();
	testMatrixCompMult4x4F();
	testMatrixCompMult2x2D();
	testMatrixCompMult2x3D();
	testMatrixCompMult2x4D();
	testMatrixCompMult3x2D();
	testMatrixCompMult3x3D();
	testMatrixCompMult3x4D();
	testMatrixCompMult4x2D();
	testMatrixCompMult4x3D();
	testMatrixCompMult4x4D();
	testMatrixMult2x2F();
	testMatrixMult3x3F();
	testMatrixMult4x4F();
	testMatrixMult2x2D();
	testMatrixMult3x3D();
	testMatrixMult4x4D();
	testInverse2x2F();
	testInverse2x2D();
	testInverse3x3F();
	testInverse3x3D();
	testInverse4x4F();
	testInverse4x4D();
	testUaddCarry1();
	testUaddCarry2();
	testUaddCarry3();
	testUaddCarry4();
	testUsubBorrow1();
	testUsubBorrow2();
	testUsubBorrow3();
	testUsubBorrow4();
	testUmulExtended1();
	testUmulExtended2();
	testUmulExtended3();
	testUmulExtended4();
	testImulExtended1();
	testImulExtended2();
	testImulExtended3();
	testImulExtended4();
	testBitfieldInsert1I();
	testBitfieldInsert2I();
	testBitfieldInsert3I();
	testBitfieldInsert4I();
	testBitfieldInsert1U();
	testBitfieldInsert2U();
	testBitfieldInsert3U();
	testBitfieldInsert4U();
	testBitfieldExtract1I();
	testBitfieldExtract2I();
	testBitfieldExtract3I();
	testBitfieldExtract4I();
	testBitfieldExtract1U();
	testBitfieldExtract2U();
	testBitfieldExtract3U();
	testBitfieldExtract4U();
	testSuiteEnd();
}
