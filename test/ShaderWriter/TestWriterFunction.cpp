#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/Ubo.hpp>

namespace
{
	struct St
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , St );

		St( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, a{ getMember< sdw::Vec4 >( "a" ) }
			, b{ getMemberArray< sdw::Vec4 >( "b" ) }
		{
		}

		static std::unique_ptr< sdw::Struct > declare( sdw::ShaderWriter & writer )
		{
			return std::make_unique< sdw::Struct >( writer, makeType( writer.getTypesCache() ) );
		}

		static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140, "St" );

			if ( result->empty() )
			{
				result->declMember( "a", ast::type::Kind::eVec4F );
				result->declMember( "b", ast::type::Kind::eVec4F, 4u );
			}

			return result;
		}

		sdw::Vec4 a;
		sdw::Array< sdw::Vec4 > b;
	};
	using InSt = sdw::InParam< St >;

	struct St2
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , St2 );

		St2( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, a{ getMember< St >( "a" ) }
			, b{ getMember< sdw::Vec4 >( "b" ) }
		{
		}

		static std::unique_ptr< sdw::Struct > declare( sdw::ShaderWriter & writer )
		{
			return std::make_unique< sdw::Struct >( writer, makeType( writer.getTypesCache() ) );
		}

		static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140, "St2" );

			if ( result->empty() )
			{
				result->declMember( "a", St::makeType( cache ) );
				result->declMember( "b", ast::type::Kind::eVec4F );
			}

			return result;
		}

		St a;
		sdw::Vec4 b;
	};
	using InSt2 = sdw::InParam< St2 >;

	void paramInArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInArray" );
		using namespace sdw;
		FragmentWriter writer;
		
		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & p )
			{
			}
			, InVec4Array{ writer, "p", 4u } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto va = writer.declLocaleArray< Vec4 >( "va", 4u );
				foo01( va );
			} );
		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void paramInOutVec4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInOutVec4" );
		using namespace sdw;
		FragmentWriter writer;

		auto foo02 = writer.implementFunction< sdw::Void >( "foo02"
			, [&]( Vec4 p )
			{
				p = p + vec4( 1.0_f );
			}
			, InOutVec4{ writer, "p" } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				foo02( v );
			} );
		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void paramInMat4InVec4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInMat4InVec4" );
		using namespace sdw;
		FragmentWriter writer;

		Ubo ubo{ writer, "Matrices", 0u, 0u };
		auto c3d_viewMatrix = ubo.declMember< Mat4 >( "c3d_viewMatrix" );
		ubo.end();

		auto foo03 = writer.implementFunction< Vec4 >( "foo03"
			, [&]( Mat4 const & m
				, Vec4 const & p )
			{
				writer.returnStmt( m * p );
			}
			, InMat4{ writer, "m" }
			, InVec4{ writer, "p" } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto m = writer.declLocale< Mat4 >( "m" );
				foo03( m, v );
				auto r = writer.declLocale< Vec4 >( "r"
					, foo03( c3d_viewMatrix, v ) );
			} );
		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void paramInStInVec4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInStInVec4" );
		using namespace sdw;
		FragmentWriter writer;

		auto st = St::declare( writer );

		auto foo04 = writer.implementFunction< Vec4 >( "foo04"
			, [&]( St const & m
				, Vec4 const & p )
			{
				FOR( writer, UInt, i, 0_u, i < 4_u, ++i )
				{
					m.b[i] *= p;
				}
				ROF;
				writer.returnStmt( m.a * p );
			}
			, InSt{ writer, "m" }
			, InVec4{ writer, "p" } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto inst = st->getInstance< St >( "inst", true );
				v = foo04( inst, v );
			} );
		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void paramInSpImgInVec2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInSpImgInVec2" );
		using namespace sdw;
		FragmentWriter writer;

		auto c3d_maps = writer.declSampledImageArray< FImg2DRgba32 >( "c3d_maps", 1u, 0u, 4u );

		auto foo05 = writer.implementFunction< Vec4 >( "foo05"
			, [&]( SampledImage2DRgba32 const & sim
				, Vec2 const & pos )
			{
				writer.returnStmt( sim.sample( pos ) );
			}
			, InSampledImage2DRgba32{ writer, "sim" }
			, InVec2{ writer, "pos" } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				v = foo05( c3d_maps[0_u], vec2( 0.0_f, 1.0_f ) );
			} );
		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void paramInVec4Ass( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInVec4Ass" );
		using namespace sdw;
		FragmentWriter writer;

		auto foo06 = writer.implementFunction< Vec2 >( "foo06"
			, [&]( Vec2 const & e )
			{
				e.r() = e.r() * abs( 5.0_f * e.r() - 5.0 * 0.75 );
				writer.returnStmt( round( e ) );
			}
			, InVec2{ writer, "e" } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				//auto e = writer.declLocale< Vec2 >( "e" );
				//e = foo06( e );
			} );
		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void params( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "params" );
		using namespace sdw;
		FragmentWriter writer;

		Ubo ubo{ writer, "Matrices", 0u, 0u };
		auto c3d_viewMatrix = ubo.declMember< Mat4 >( "c3d_viewMatrix" );
		ubo.end();

		auto c3d_maps = writer.declSampledImageArray< FImg2DRgba32 >( "c3d_maps", 1u, 0u, 4u );

		auto st = St::declare( writer );

		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & arr )
			{
			}
			, InVec4Array{ writer, "arr", 4u } );

		auto foo02 = writer.implementFunction< sdw::Void >( "foo02"
			, [&]( Vec4 pos )
			{
				pos = pos + vec4( 1.0_f );
			}
			, InOutVec4{ writer, "pos" } );

		auto foo03 = writer.implementFunction< Vec4 >( "foo03"
			, [&]( Mat4 const & mtx
				, Vec4 const & pos )
			{
				writer.returnStmt( mtx * pos );
			}
			, InMat4{ writer, "mtx" }
			, InVec4{ writer, "pos" } );

		auto foo04 = writer.implementFunction< Vec4 >( "foo04"
			, [&]( St const & str
				, Vec4 const & pos )
			{
				FOR( writer, UInt, i, 0_u, i < 4_u, ++i )
				{
					str.b[i] *= pos;
				}
				ROF;
				writer.returnStmt( str.a * pos );
			}
			, InSt{ writer, "str" }
			, InVec4{ writer, "pos" } );

		auto foo05 = writer.implementFunction< Vec4 >( "foo05"
			, [&]( SampledImage2DRgba32 const & sim
				, Vec2 const & pos )
			{
				writer.returnStmt( sim.sample( pos ) );
			}
			, InSampledImage2DRgba32{ writer, "sim" }
			, InVec2{ writer, "pos" } );

		auto foo06 = writer.implementFunction< Vec2 >( "foo06"
			, [&]( Vec2 const & pos )
			{
				pos.r() = pos.r() * abs( 5.0_f * pos.r() - 5.0 * 0.75 );
				writer.returnStmt( round( pos ) );
			}
			, InVec2{ writer, "pos" } );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto va = writer.declLocaleArray< Vec4 >( "va", 4u );
				auto m = writer.declLocale< Mat4 >( "m" );
				foo01( va );
				foo02( v );
				foo03( m, v );
				auto r = writer.declLocale< Vec4 >( "r"
					, foo03( c3d_viewMatrix, v ) );
				auto inst = st->getInstance< St >( "inst", true );
				v = foo04( inst, v );
				v = foo05( c3d_maps[0_u], vec2( 0.0_f, 1.0_f ) );
				auto e = writer.declLocale< Vec2 >( "e" );
				e = foo06( e );
			} );

		test::expectError( "must be a memory object declaration"
			, testCounts );
		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void arrayAccesses( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arrayAccesses" );
		using namespace sdw;
		ComputeWriter writer;

		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & p
				, Vec4 v
				, Int const & i )
			{
				auto j = writer.declLocale< Int >( "j" );
				v = p[j];
			}
			, InVec4Array{ writer, "p", 4u }
			, OutVec4{ writer, "v" }
			, InInt{ writer, "i" } );

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto p = writer.declLocaleArray< Vec4 >( "p", 4u );
				auto v = writer.declLocale< Vec4 >( "v" );
				auto i = writer.declLocale< Int >( "i" );
				foo01( p, v, i );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void removeGamma( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "removeGamma" );
		using namespace sdw;
		ComputeWriter writer;

		auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				IF( writer, gamma < 0.0_f )
				{
					writer.returnStmt( srgb );
				}
				FI;

				writer.returnStmt( pow( srgb, vec3( gamma ) ) );
			}
			, InFloat{ writer, "gamma" }
			, InVec3{ writer, "srgb" } );

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto f = writer.declLocale< Float >( "f" );
				auto v = writer.declLocale< Vec3 >( "v" );
				v = removeGamma( f, v );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}

	void returns( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "returns" );
		using namespace sdw;
		ComputeWriter writer;

		St::declare( writer );
		St2::declare( writer );

		auto foo01 = writer.implementFunction< St2 >( "foo01"
			, [&]( Vec4 const & p )
			{
				auto result = writer.declLocale< St2 >( "result" );
				result.a.a = p * 2.0_f;
				result.a.b[0] = p * 2.0_f;
				result.a.b[1] = p * 3.0_f;
				result.a.b[2] = p * 4.0_f;
				result.a.b[3] = p * 5.0_f;
				result.b = p * 6.0_f;
				writer.returnStmt( result );
			}
			, InVec4{ writer, "p" } );

		auto foo02 = writer.implementFunction< Vec4 >( "foo02"
			, [&]( St2 const & p )
			{
				writer.returnStmt( p.a.a );
			}
			, InSt2{ writer, "p" } );

		auto foo03 = writer.implementFunction< Float >( "foo03"
			, [&]( Vec4 const & p )
			{
				IF( writer, p.x() )
				{
					writer.returnStmt( p.y() );
				}
				ELSE
				{
					writer.returnStmt( p.z() );
				}
				FI;
			}
			, InVec4{ writer, "p" } );

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				v = foo02( foo01( v ) );
				auto r = writer.declLocale( "r"
					, foo01( v ) );
				v += foo02( r );
				foo03( v );
			} );

		test::writeShader( writer
			, testCounts );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterFunction )
{
	sdwTestSuiteBegin();
	paramInArray( testCounts );
	paramInOutVec4( testCounts );
	paramInMat4InVec4( testCounts );
	paramInStInVec4( testCounts );
	paramInSpImgInVec2( testCounts );
	paramInVec4Ass( testCounts );
	params( testCounts );
	arrayAccesses( testCounts );
	removeGamma( testCounts );
	returns( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterFunction )
