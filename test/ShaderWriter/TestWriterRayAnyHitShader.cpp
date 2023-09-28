#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

// HLSL doesn't support buffer references
#undef CurrentCompilers
#define CurrentCompilers Compilers_NoHLSL

namespace
{
	struct HitPayload
		: sdw::StructInstance
	{
		HitPayload( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, hitValue{ getMember< sdw::Vec3 >( "hitValue" ) }
			, seed{ getMember< sdw::UInt >( "seed" ) }
			, depth{ getMember< sdw::Int >( "depth" ) }
			, attenuation{ getMember< sdw::Vec3 >( "attenuation" ) }
			, done{ getMember< sdw::Int >( "done" ) }
			, rayOrigin{ getMember< sdw::Vec3 >( "rayOrigin" ) }
			, rayDir{ getMember< sdw::Vec3 >( "rayDir" ) }
		{
		}

		SDW_DeclStructInstance( , HitPayload );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "HitPayload" );

			if ( result->empty() )
			{
				result->declMember( "hitValue"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "seed"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "depth"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
				result->declMember( "attenuation"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "done"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
				result->declMember( "rayOrigin"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "rayDir"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );

				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 hitValue;
		sdw::UInt seed;
		sdw::Int depth;
		sdw::Vec3 attenuation;
		sdw::Int done;
		sdw::Vec3 rayOrigin;
		sdw::Vec3 rayDir;
	};

	struct ObjDesc
		: sdw::StructInstance
	{
		ObjDesc( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, txtOffset{ getMember< sdw::Int >( "txtOffset" ) }
			, vertexAddress{ getMember< sdw::UInt64 >( "vertexAddress" ) }
			, indexAddress{ getMember< sdw::UInt64 >( "indexAddress" ) }
			, materialAddress{ getMember< sdw::UInt64 >( "materialAddress" ) }
			, materialIndexAddress{ getMember< sdw::UInt64 >( "materialIndexAddress" ) }
		{
		}

		SDW_DeclStructInstance( , ObjDesc );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "ObjDesc" );

			if ( result->empty() )
			{
				result->declMember( "txtOffset"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
				result->declMember( "vertexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "indexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "materialAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "materialIndexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Int txtOffset;
		sdw::UInt64 vertexAddress;
		sdw::UInt64 indexAddress;
		sdw::UInt64 materialAddress;
		sdw::UInt64 materialIndexAddress;
	};

	struct Vertex
		: sdw::StructInstance
	{
		Vertex( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, pos{ getMember< sdw::Vec3 >( "pos" ) }
			, nrm{ getMember< sdw::Vec3 >( "nrm" ) }
			, color{ getMember< sdw::Vec3 >( "color" ) }
			, texCoord{ getMember< sdw::Vec2 >( "texCoord" ) }
		{
		}

		SDW_DeclStructInstance( , Vertex );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "Vertex" );

			if ( result->empty() )
			{
				result->declMember( "pos"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "nrm"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "color"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "texCoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 pos;
		sdw::Vec3 nrm;
		sdw::Vec3 color;
		sdw::Vec2 texCoord;
	};

	struct WaveFrontMaterial
		: sdw::StructInstance
	{
		WaveFrontMaterial( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, ambient{ getMember< sdw::Vec3 >( "ambient" ) }
			, diffuse{ getMember< sdw::Vec3 >( "diffuse" ) }
			, specular{ getMember< sdw::Vec3 >( "specular" ) }
			, transmittance{ getMember< sdw::Vec3 >( "transmittance" ) }
			, emission{ getMember< sdw::Vec3 >( "emission" ) }
			, shininess{ getMember< sdw::Float >( "shininess" ) }
			, ior{ getMember< sdw::Float >( "ior" ) }
			, dissolve{ getMember< sdw::Float >( "dissolve" ) }
			, illum{ getMember< sdw::Int >( "illum" ) }
			, textureId{ getMember< sdw::Int >( "textureId" ) }
		{
		}

		SDW_DeclStructInstance( , WaveFrontMaterial );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eScalar
				, "WaveFrontMaterial" );

			if ( result->empty() )
			{
				result->declMember( "ambient"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "diffuse"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "specular"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "transmittance"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "emission"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "shininess"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "ior"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "dissolve"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "illum"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
				result->declMember( "textureId"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 ambient;
		sdw::Vec3 diffuse;
		sdw::Vec3 specular;
		sdw::Vec3 transmittance;
		sdw::Vec3 emission;
		sdw::Float shininess;
		sdw::Float ior;       // index of refraction
		sdw::Float dissolve;  // 1 == opaque; 0 == fully transparent
		sdw::Int illum;       // illumination model (see http://www.fileformat.info/format/material/)
		sdw::Int textureId;
	};

	void simple( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simple" );
		using namespace sdw;
		{
			sdw::RayAnyHitWriter writer{ &testCounts.allocator };

			auto objDescs = writer.declArrayStorageBuffer< ObjDesc >( "ObjDescs", 0u, 1u );

			auto Vertices = writer.declBufferReference< ArrayStorageBufferT< Vertex > >( "Vertices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto Indices = writer.declBufferReference< ArrayStorageBufferT< UInt > >( "Indices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto Materials = writer.declBufferReference< ArrayStorageBufferT< WaveFrontMaterial > >( "Materials", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );
			auto MatIndices = writer.declBufferReference< ArrayStorageBufferT< Int > >( "MatIndices", ast::type::MemoryLayout::eScalar, ast::type::Storage::ePhysicalStorageBuffer );

			// Generate a random unsigned int in [0, 2^24) given the previous RNG state
			// using the Numerical Recipes linear congruential generator
			auto lcg = writer.implementFunction< UInt >( "lcg"
				, [&]( UInt prev )
				{
					auto LCG_A = 1664525_u;
					auto LCG_C = 1013904223_u;
					prev = ( LCG_A * prev + LCG_C );
					writer.returnStmt( prev & 0x00FFFFFF_u );
				}
				, InOutUInt{ writer, "prev" } );

			// Generate a random float in [0, 1) given the previous RNG state
			auto rnd = writer.implementFunction< Float >( "rnd"
				, [&]( UInt prev )
				{
					writer.returnStmt( writer.cast< Float >( lcg( prev ) ) / writer.cast< Float >( 0x01000000_i ) );
				}
				, InOutUInt{ writer, "prev" } );
			
			writer.implementMainT< HitPayload, Vec2 >( RayPayloadInT< HitPayload >{ writer, 0u }
				, HitAttributeT< Vec2 >{ writer }
				, [&]( RayAnyHitIn in
					, RayPayloadInT< HitPayload > prd
					, HitAttributeT< Vec2 > attribs )
				{
					  // Object of this instance
					auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< UInt >( in.instanceCustomIndex )] );
					auto matIndices = MatIndices( "matIndices", objResource.materialIndexAddress );
					auto materials = Materials( "materials", objResource.materialAddress );

					auto matIdx = writer.declLocale( "matIdx", matIndices[writer.cast< UInt >( in.primitiveID )] );
					auto mat = writer.declLocale( "mat", materials[writer.cast< UInt >( matIdx )] );

					IF( writer, mat.illum == 4_i )
					{
						writer.returnStmt();
					}
					FI;

					auto seed = writer.declLocale( "seed", prd.seed );  // We don't want to modify the PRD

					IF( writer, mat.dissolve == 0.0_f )
					{
						writer.ignoreIntersection();
					}
					ELSEIF( rnd( seed ) > mat.dissolve )
					{
						writer.ignoreIntersection();
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

sdwTestSuiteMain( TestWriterAnyHitShader )
{
	sdwTestSuiteBegin();

	simple( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterAnyHitShader )
