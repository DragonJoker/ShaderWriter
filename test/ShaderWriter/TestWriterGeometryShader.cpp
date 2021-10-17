#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	struct GeomOutputPos
		: sdw::StructInstance
	{
		GeomOutputPos( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
		{
		}

		SDW_DeclStructInstance( , GeomOutputPos );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd430, "GeomOutputPos" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray
					, 0u
					, ast::var::Flag::eShaderOutput );
			}

			return result;
		}

		sdw::Vec3 position;
	};

	void onlyGeometry( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "onlyGeometry" );
		using namespace sdw;
		{
			GeometryWriter writer;
			writer.inputLayout( ast::type::InputLayout::eTriangleList );

			auto in = writer.getIn();

			writer.implementMainT< GeomOutputPos, ast::type::OutputLayout::eTriangleStrip, 3u >( [&]( sdw::OutputStreamT< GeomOutputPos > out )
				{
					out.position = in.vtx[0].position.xyz();
					out.vtx.position = in.vtx[0].position;
					out.append();

					out.position = in.vtx[1].position.xyz();
					out.vtx.position = in.vtx[1].position;
					out.append();

					out.position = in.vtx[2].position.xyz();
					out.vtx.position = in.vtx[2].position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void basicGeometry( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "basicGeometry" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			// Inputs
			uint32_t index = 0u;
			auto position = writer.declInput< Vec4 >( "position", index++ );

			// Outputs
			index = 0u;
			auto vtx_position = writer.declOutput< Vec3 >( "vtx_position", index++ );
			auto out = writer.getOut();

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					vtx_position = position.xyz();
					out.vtx.position = position;
				} );
			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			GeometryWriter writer;
			writer.inputLayout( ast::type::InputLayout::eTriangleList );

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto mvp = voxelizeUbo.declMember< sdw::Mat4 >( "mvp" );
			voxelizeUbo.end();

			uint32_t index = 0u;
			auto vtx_position = writer.declInputArray< Vec3 >( "vtx_position", index++, 3u );
			auto in = writer.getIn();
			auto out = writer.getOut();

			writer.implementMainT< GeomOutputPos, ast::type::OutputLayout::eTriangleStrip, 3u >( [&]( sdw::OutputStreamT< GeomOutputPos > out )
				{
					auto pos = writer.declLocale< Vec4 >( "pos" );

					pos = mvp * in.vtx[0].position;
					out.position = pos.xyz();
					out.vtx.position = pos;
					out.append();

					pos = mvp * in.vtx[1].position;
					out.position = pos.xyz();
					out.vtx.position = pos;
					out.append();

					pos = mvp * in.vtx[2].position;
					out.position = pos.xyz();
					out.vtx.position = pos;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			uint32_t index = 0u;
			auto geo_position = writer.declInput< Vec3 >( "geo_position", index++ );

			auto pxl_fragColor( writer.declOutput< Vec4 >( "pxl_fragColor", 0 ) );

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					pxl_fragColor = vec4( geo_position, 1.0f );
				} );
			test::writeShader( writer
				, testCounts );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
		testEnd();
	}

	void voxelGeometry( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "voxelGeometry" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			VertexWriter writer;
			// Inputs
			uint32_t index = 0u;
			auto position = writer.declInput< Vec4 >( "position", index++ );
			auto normal = writer.declInput< Vec3 >( "normal", index++ );
			auto uv = writer.declInput< Vec3 >( "uv", index++ );

			// Outputs
			index = 0u;
			auto vtx_position = writer.declOutput< Vec3 >( "vtx_position", index++ );
			auto vtx_normal = writer.declOutput< Vec3 >( "vtx_normal", index++ );
			auto vtx_texture = writer.declOutput< Vec3 >( "vtx_texture", index++ );
			auto out = writer.getOut();

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					vtx_position = position.xyz();
					vtx_normal = normal.xyz();
					vtx_texture = uv.xyz();
					out.vtx.position = position;
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			GeometryWriter writer;
			writer.inputLayout( ast::type::InputLayout::eTriangleList );

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			uint32_t index = 0u;
			auto vtx_position = writer.declInputArray< Vec3 >( "vtx_position", index++, 3u );
			auto vtx_normal = writer.declInputArray< Vec3 >( "vtx_normal", index++, 3u );
			auto vtx_texture = writer.declInputArray< Vec3 >( "vtx_texture", index++, 3u );
			auto in = writer.getIn();

			struct GeomOutput
				: sdw::StructInstance
			{
				GeomOutput( ShaderWriter & writer
					, sdw::expr::ExprPtr expr
					, bool enabled = true )
					: sdw::StructInstance{ writer, std::move( expr ), enabled }
					, position{ getMember< Vec3 >( "position" ) }
					, normal{ getMember< Vec3 >( "normal" ) }
					, texcoord{ getMember< Vec3 >( "texcoord" ) }
					, axis{ getMember< UInt >( "axis" ) }
					, aabb{ getMember< Vec4 >( "aabb" ) }
				{
				}

				SDW_DeclStructInstance( , GeomOutput );

				static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
				{
					auto result = cache.getStruct( ast::type::MemoryLayout::eStd430, "GeomOutput" );

					if ( result->empty() )
					{
						uint32_t index = 0u;
						result->declMember( "position"
							, ast::type::Kind::eVec3F
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderOutput );
						result->declMember( "normal"
							, ast::type::Kind::eVec3F
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderOutput );
						result->declMember( "texcoord"
							, ast::type::Kind::eVec3F
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderOutput );
						result->declMember( "axis"
							, ast::type::Kind::eUInt
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderOutput );
						result->declMember( "aabb"
							, ast::type::Kind::eVec4F
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderOutput );
					}

					return result;
				}

				sdw::Vec3 position;
				sdw::Vec3 normal;
				sdw::Vec3 texcoord;
				sdw::UInt axis;
				sdw::Vec4 aabb;
			};
			auto out = writer.getOut();

			writer.implementMainT< GeomOutput, ast::type::OutputLayout::eTriangleStrip, 3u >( [&]( sdw::OutputStreamT< GeomOutput > out )
				{
					auto faceNormal = writer.declLocale( "faceNormal"
						, normalize( cross( vtx_position[1] - vtx_position[0], vtx_position[2] - vtx_position[0] ) ) );
					auto NdotXAxis = writer.declLocale( "NdotXAxis"
						, abs( faceNormal.x() ) );
					auto NdotYAxis = writer.declLocale( "NdotYAxis"
						, abs( faceNormal.y() ) );
					auto NdotZAxis = writer.declLocale( "NdotZAxis"
						, abs( faceNormal.z() ) );
					auto proj = writer.declLocale< Mat4 >( "proj" );
					auto curPosition = writer.declLocaleArray( "curPosition"
						, 3u
						, std::vector< sdw::Vec4 >
						{
							in.vtx[0].position,
							in.vtx[1].position,
							in.vtx[2].position,
						} );
					auto axis = writer.declLocale( "axis", 0_u );

					//Find the axis the maximize the projected area of this triangle
					IF( writer, NdotXAxis > NdotYAxis && NdotXAxis > NdotZAxis )
					{
						proj = c3d_vpX;
						axis = 1_u;
					}
					ELSEIF( NdotYAxis > NdotXAxis && NdotYAxis > NdotZAxis )
					{
						proj = c3d_vpY;
						axis = 2_u;
					}
					ELSE
					{
						proj = c3d_vpZ;
						axis = 3_u;
					}
					FI;

					auto pos = writer.declLocaleArray< Vec4 >( "pos", 3u );

					//transform vertices to clip space
					pos[0] = proj * pos[0];
					pos[1] = proj * pos[1];
					pos[2] = proj * pos[2];

					//Next we enlarge the triangle to enable conservative rasterization
					auto aabb = writer.declLocale< Vec4 >( "aabb" );
					auto hPixel = writer.declLocale< Vec2 >( "hPixel"
						, vec2( 1.0_f ) / c3d_size );
					auto pl = writer.declLocale< Float >( "pl"
						, 1.4142135637309_f / c3d_size.x() );

					//calculate AABB of this triangle
					aabb.xy() = pos[0].xy();
					aabb.zw() = pos[0].xy();

					aabb.xy() = min( pos[1].xy(), aabb.xy() );
					aabb.zw() = max( pos[1].xy(), aabb.zw() );

					aabb.xy() = min( pos[2].xy(), aabb.xy() );
					aabb.zw() = max( pos[2].xy(), aabb.zw() );

					//Enlarge half-pixel
					aabb.xy() -= hPixel;
					aabb.zw() += hPixel;

					//find 3 triangle edge plane
					auto e0 = writer.declLocale( "e0"
						, vec3( pos[1].xy() - pos[0].xy(), 0 ) );
					auto e1 = writer.declLocale( "e1"
						, vec3( pos[2].xy() - pos[1].xy(), 0 ) );
					auto e2 = writer.declLocale( "e2"
						, vec3( pos[0].xy() - pos[2].xy(), 0 ) );
					auto n0 = writer.declLocale( "n0"
						, cross( e0, vec3( 0.0_f, 0, 1 ) ) );
					auto n1 = writer.declLocale( "n1"
						, cross( e1, vec3( 0.0_f, 0, 1 ) ) );
					auto n2 = writer.declLocale( "n2"
						, cross( e2, vec3( 0.0_f, 0, 1 ) ) );

					//dilate the triangle
					pos[0].xy() = pos[0].xy() + pl * ( ( e2.xy() / dot( e2.xy(), n0.xy() ) ) + ( e0.xy() / dot( e0.xy(), n2.xy() ) ) );
					pos[1].xy() = pos[1].xy() + pl * ( ( e0.xy() / dot( e0.xy(), n1.xy() ) ) + ( e1.xy() / dot( e1.xy(), n0.xy() ) ) );
					pos[2].xy() = pos[2].xy() + pl * ( ( e1.xy() / dot( e1.xy(), n2.xy() ) ) + ( e2.xy() / dot( e2.xy(), n1.xy() ) ) );

					out.vtx.position = pos[0];
					out.position = pos[0].xyz();
					out.normal = vtx_normal[0];
					out.texcoord = vtx_texture[0];
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.vtx.position = pos[1];
					out.position = pos[1].xyz();
					out.normal = vtx_normal[1];
					out.texcoord = vtx_texture[1];
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.vtx.position = pos[2];
					out.position = pos[2].xyz();
					out.normal = vtx_normal[2];
					out.texcoord = vtx_texture[2];
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			auto pxl_voxelVisibility = writer.declImage< WUImg3DR8 >( "pxl_voxelVisibility", 0u, 1u );

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			uint32_t index = 0u;
			auto geo_position = writer.declInput< Vec3 >( "geo_position", index++ );
			auto geo_normal = writer.declInput< Vec3 >( "geo_normal", index++ );
			auto geo_texture = writer.declInput< Vec3 >( "geo_texture", index++ );
			auto geo_axis = writer.declInput< UInt >( "geo_axis", index++, uint32_t( sdw::var::Flag::eFlat ) ); //indicate which axis the projection uses
			auto geo_aabb = writer.declInput< Vec4 >( "geo_aabb", index++, uint32_t( sdw::var::Flag::eFlat ) );
			auto in = writer.getIn();

			auto pxl_fragColor( writer.declOutput< Vec4 >( "pxl_fragColor", 0 ) );

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					IF( writer
						, geo_position.x() < geo_aabb.x()
						|| geo_position.y() < geo_aabb.y()
						|| geo_position.x() > geo_aabb.z()
						|| geo_position.y() > geo_aabb.w() )
					{
						writer.discard();
					}
					FI;

					auto width = writer.declLocale( "width"
						, writer.cast< Int >( c3d_size.x() ) );
					auto temp = writer.declLocale( "temp"
						, ivec3( writer.cast< Int >( in.fragCoord.x() )
							, writer.cast< Int >( in.fragCoord.y() )
							, width * writer.cast< Int >( in.fragCoord.z() ) ) );
					auto texcoord = writer.declLocale< IVec3 >( "texcoord" );

					IF( writer, geo_axis == 1 )
					{
						texcoord.x() = width - temp.z();
						texcoord.z() = temp.x();
						texcoord.y() = temp.y();
					}
					ELSEIF( geo_axis == 2 )
					{
						texcoord.z() = temp.y();
						texcoord.y() = width - temp.z();
						texcoord.x() = temp.x();
					}
					ELSE
					{
						texcoord = temp;
					}
					FI;

					pxl_voxelVisibility.store( texcoord, 1_u );
				} );
			test::writeShader( writer
				, testCounts
				, true, false, true );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterGeometryShader )
{
	sdwTestSuiteBegin();
	onlyGeometry( testCounts );
	basicGeometry( testCounts );
	voxelGeometry( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterGeometryShader )
