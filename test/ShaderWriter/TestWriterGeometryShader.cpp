#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

#undef CurrentCompilers
#define CurrentCompilers Compilers_All

namespace
{
	template< ast::var::Flag FlagT >
	struct PositionT
		: sdw::StructInstance
	{
		PositionT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
		{
		}

		SDW_DeclStructInstance( , PositionT );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd430
				, ( FlagT == ast::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "Position" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray
					, 0u
					, FlagT );
			}

			return result;
		}

		sdw::Vec3 position;
	};
	using InputPosition = PositionT< ast::var::Flag::eShaderInput >;
	using OutputPosition = PositionT< ast::var::Flag::eShaderOutput >;

	void noSpecificIO( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIO" );
		using namespace sdw;
		{
			GeometryWriter writer;

			writer.implementMainT< PointList, PointStream, 1u >( [&]( PointList in
				, PointStream out )
				{
					out.vtx.position = in.vtx[0].position;
					out.append();
					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificOutputOnly" );
		using namespace sdw;
		{
			GeometryWriter writer;
			using MyTriangleStream = sdw::TriangleStreamT< OutputPosition >;

			writer.implementMainT< TriangleList, MyTriangleStream, 3u >( [&]( TriangleList in
				, MyTriangleStream out )
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
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificInputOnly" );
		using namespace sdw;
		{
			GeometryWriter writer;
			using MyTriangleList = sdw::TriangleListT< InputPosition >;

			writer.implementMainT< MyTriangleList, TriangleStream, 3u >( [&]( MyTriangleList in
				, TriangleStream out )
				{
					out.vtx.position = vec4( in[0].position, 0.0_f ) + in.vtx[0].position;
					out.append();

					out.vtx.position = vec4( in[1].position, 0.0_f ) + in.vtx[1].position;
					out.append();

					out.vtx.position = vec4( in[2].position, 0.0_f ) + in.vtx[2].position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificInAndOut" );
		using namespace sdw;
		{
			GeometryWriter writer;
			using MyTriangleList = sdw::TriangleListT< InputPosition >;
			using MyTriangleStream = sdw::TriangleStreamT< OutputPosition >;

			writer.implementMainT< MyTriangleList, MyTriangleStream, 3u >( [&]( MyTriangleList in
				, MyTriangleStream out )
				{
					out.position = in[0].position;
					out.vtx.position = in.vtx[0].position;
					out.append();

					out.position = in[1].position;
					out.vtx.position = in.vtx[1].position;
					out.append();

					out.position = in[2].position;
					out.vtx.position = in.vtx[2].position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void basicPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "basicPipeline" );
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
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			GeometryWriter writer;

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto mvp = voxelizeUbo.declMember< sdw::Mat4 >( "mvp" );
			voxelizeUbo.end();

			using MyTriangleList = sdw::TriangleListT< InputPosition >;
			using MyTriangleStream = sdw::TriangleStreamT< OutputPosition >;

			writer.implementMainT< MyTriangleList, MyTriangleStream, 3u >( [&]( MyTriangleList in
				, MyTriangleStream out )
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
				, testCounts
				, CurrentCompilers );
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
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts );
		testEnd();
	}

	void voxelPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "voxelPipeline" );
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
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			GeometryWriter writer;

			sdw::Ubo voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			struct GeomInput
				: sdw::StructInstance
			{
				GeomInput( ShaderWriter & writer
					, sdw::expr::ExprPtr expr
					, bool enabled = true )
					: sdw::StructInstance{ writer, std::move( expr ), enabled }
					, position{ getMember< Vec3 >( "position" ) }
					, normal{ getMember< Vec3 >( "normal" ) }
					, texcoord{ getMember< Vec3 >( "texcoord" ) }
				{
				}

				SDW_DeclStructInstance( , GeomInput );

				static ast::type::StructPtr makeType( ast::type::TypesCache & cache )
				{
					auto result = cache.getStruct( ast::type::MemoryLayout::eStd430, "GeomInput" );

					if ( result->empty() )
					{
						uint32_t index = 0u;
						result->declMember( "position"
							, ast::type::Kind::eVec3F
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderInput );
						result->declMember( "normal"
							, ast::type::Kind::eVec3F
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderInput );
						result->declMember( "texcoord"
							, ast::type::Kind::eVec3F
							, ast::type::NotArray
							, index++
							, ast::var::Flag::eShaderInput );
					}

					return result;
				}

				sdw::Vec3 position;
				sdw::Vec3 normal;
				sdw::Vec3 texcoord;
			};

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

			using MyTriangleList = sdw::TriangleListT< GeomInput >;
			using MyTriangleStream = sdw::TriangleStreamT< GeomOutput >;

			writer.implementMainT< MyTriangleList, MyTriangleStream, 3u >( [&]( MyTriangleList in
				, MyTriangleStream out )
				{
					auto faceNormal = writer.declLocale( "faceNormal"
						, normalize( cross( in[1].position - in[0].position, in[2].position - in[0].position ) ) );
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
					pos[0] = proj * curPosition[0];
					pos[1] = proj * curPosition[1];
					pos[2] = proj * curPosition[2];

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
					out.normal = in[0].normal;
					out.texcoord = in[0].texcoord;
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.vtx.position = pos[1];
					out.position = pos[1].xyz();
					out.normal = in[1].normal;
					out.texcoord = in[1].texcoord;
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.vtx.position = pos[2];
					out.position = pos[2].xyz();
					out.normal = in[2].normal;
					out.texcoord = in[2].texcoord;
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			auto pxl_voxelVisibility = writer.declImage< WUImg3DR8 >( "pxl_voxelVisibility", 1u, 1u );

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

			auto pxl_fragColor( writer.declOutput< Vec4 >( "pxl_fragColor", 0u ) );

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
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterGeometryShader )
{
	sdwTestSuiteBegin();
	noSpecificIO( testCounts );
	specificInputOnly( testCounts );
	specificOutputOnly( testCounts );
	specificInAndOut( testCounts );
	basicPipeline( testCounts );
	voxelPipeline( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterGeometryShader )
