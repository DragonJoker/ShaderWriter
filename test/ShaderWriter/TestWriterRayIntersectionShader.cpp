#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	struct Sphere
		: sdw::StructInstance
	{
		Sphere( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, center{ getMember< sdw::Vec3 >( "center" ) }
			, radius{ getMember< sdw::Float >( "radius" ) }
		{
		}

		SDW_DeclStructInstance( , Sphere );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "Sphere" );

			if ( result->empty() )
			{
				result->declMember( "center"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "radius"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 center;
		sdw::Float radius;
	};

	struct Aabb
		: sdw::StructInstance
	{
		Aabb( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, minimum{ getMember< sdw::Vec3 >( "minimum" ) }
			, maximum{ getMember< sdw::Vec3 >( "maximum" ) }
		{
		}

		SDW_DeclStructInstance( , Aabb );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "Aabb" );

			if ( result->empty() )
			{
				result->declMember( "minimum"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "maximum"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 minimum;
		sdw::Vec3 maximum;
	};

	struct Ray
		: sdw::StructInstance
	{
		Ray( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, origin{ getMember< sdw::Vec3 >( "origin" ) }
			, direction{ getMember< sdw::Vec3 >( "direction" ) }
		{
		}

		SDW_DeclStructInstance( , Ray );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "Ray" );

			if ( result->empty() )
			{
				result->declMember( "origin"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "direction"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Float hitSphere( Sphere const & ps )
		{
			if ( !m_hitSphere )
			{
				// Ray-Sphere intersection
				// http://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/
				m_hitSphere = m_writer->implementFunction< sdw::Float >( "hitSphere"
					, [&]( Sphere s
						, Ray r )
					{
						auto oc = m_writer->declLocale( "oc", r.origin - s.center );
						auto a = m_writer->declLocale( "a", dot( r.direction, r.direction ) );
						auto b = m_writer->declLocale( "b", 2.0_f * dot( oc, r.direction ) );
						auto c = m_writer->declLocale( "c", dot( oc, oc ) - s.radius * s.radius );
						auto discriminant = m_writer->declLocale( "discriminant", b * b - 4.0_f * a * c );
						IF( *m_writer, discriminant < 0.0_f )
						{
							m_writer->returnStmt( -1.0_f );
						}
						ELSE
						{
							m_writer->returnStmt( ( -b - sqrt( discriminant ) ) / ( 2.0_f * a ) );
						}
						FI;
					}
					, sdw::InParam< Sphere >{ *m_writer, "s" }
					, sdw::InParam< Ray >{ *m_writer, "r" } );
			}
			return m_hitSphere( ps, *this );
		}

		sdw::Float hitAabb( Aabb const & paabb )
		{
			if ( !m_hitAabb )
			{
				// Ray-AABB intersection
				m_hitAabb = m_writer->implementFunction< sdw::Float >( "hitAabb"
					, [&]( Aabb aabb
						, Ray r )
					{
						auto invDir = m_writer->declLocale( "invDir", vec3( 1.0_f ) / r.direction );
						auto tbot = m_writer->declLocale( "tbot", invDir * ( aabb.minimum - r.origin ) );
						auto ttop = m_writer->declLocale( "ttop", invDir * ( aabb.maximum - r.origin ) );
						auto tmin = m_writer->declLocale( "tmin", min( ttop, tbot ) );
						auto tmax = m_writer->declLocale( "tmax", max( ttop, tbot ) );
						auto t0 = m_writer->declLocale( "t0", max( tmin.x(), max( tmin.y(), tmin.z() ) ) );
						auto t1 = m_writer->declLocale( "t1", min( tmax.x(), min( tmax.y(), tmax.z() ) ) );
						m_writer->returnStmt( m_writer->ternary( t1 > max( t0, 0.0_f ), t0, -1.0_f ) );
					}
					, sdw::InParam< Aabb >{ *m_writer, "aabb" }
					, sdw::InParam< Ray >{ *m_writer, "r" } );
			}
			return m_hitAabb( paabb, *this );
		}

		sdw::Vec3 origin;
		sdw::Vec3 direction;

		sdw::Function< sdw::Float
			, sdw::InParam< Sphere >
			, sdw::InParam< Ray > > m_hitSphere;
		sdw::Function< sdw::Float
			, sdw::InParam< Aabb >
			, sdw::InParam< Ray > > m_hitAabb;
	};

	void simple( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simple" );
		using namespace sdw;
		{
			sdw::RayIntersectionWriter writer{ &testCounts.allocator };

			writer.declType< Ray >();
			writer.declType< Aabb >();
			auto allSpheres = writer.declArrayStorageBuffer< Sphere >( "allSpheres", 1u, 0u );
			auto KIND_SPHERE = writer.declConstant( "KIND_SPHERE", 0_i );
			auto KIND_CUBE = writer.declConstant( "KIND_CUBE", 1_i );

			writer.implementMain( [&]( RayIntersectionIn in )
				{
					auto ray = writer.declLocale< Ray >( "ray" );
					ray.origin = in.worldRayOrigin;
					ray.direction = in.worldRayDirection;

					// Sphere data
					auto sphere = writer.declLocale( "sphere", allSpheres[writer.cast< UInt >( in.primitiveID )] );

					auto tHit = writer.declLocale( "tHit", -1.0_f );
					auto hitKind = writer.declLocale( "hitKind", writer.ternary( in.primitiveID % 2_i == 0_i, KIND_SPHERE, KIND_CUBE ) );

					IF( writer, hitKind == KIND_SPHERE )
					{
						// Sphere intersection
						tHit = ray.hitSphere( sphere );
					}
					ELSE
					{
						// AABB intersection
						auto aabb = writer.declLocale< Aabb >( "aabb" );
						aabb.minimum = sphere.center - vec3( sphere.radius );
						aabb.maximum = sphere.center + vec3( sphere.radius );
						tHit = ray.hitAabb( aabb );
					}
					FI;

					// Report hit point
					IF( writer, tHit > 0.0_f )
					{
						auto attribs = writer.declHitAttribute< sdw::Vec2 >( "attribs" );
						attribs.reportIntersection( tHit, writer.cast< UInt >( hitKind ) );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterRayIntersectionShader )
{
	sdwTestSuiteBegin();

	simple( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterRayIntersectionShader )
