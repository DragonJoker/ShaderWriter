#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	struct Voxel
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , Voxel );

		Voxel( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, colorMask{ getMember< sdw::UInt >( "colorMask" ) }
			, normalMask{ getMember< sdw::UInt >( "normalMask" ) }
		{
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd430
				, "Voxel" );

			if ( result->empty() )
			{
				result->declMember( "colorMask", ast::type::Kind::eUInt );
				result->declMember( "normalMask", ast::type::Kind::eUInt );
			}

			return result;
		}

		// Raw values
		sdw::UInt colorMask;
		sdw::UInt normalMask;

	private:
		using sdw::StructInstance::getMember;
		using sdw::StructInstance::getMemberArray;
	};

	void emptyMain( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "emptyMain" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, 16u, [&]( ComputeIn in )
			{
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void builtins( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "builtins" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, 16u, [&]( ComputeIn in )
			{
				writer.declLocale( "globalInvocationID", in.globalInvocationID );
				writer.declLocale( "localInvocationID", in.localInvocationID );
				writer.declLocale( "localInvocationIndex", in.localInvocationIndex );
				writer.declLocale( "numWorkGroups", in.numWorkGroups );
				writer.declLocale( "workGroupID", in.workGroupID );
				writer.declLocale( "workGroupSize", in.workGroupSize );
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void readWorkGroupSize( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "readWorkGroupSize" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, 16u, [&]( ComputeIn in )
			{
				auto value = writer.declLocale( "value"
					, in.workGroupSize.x() + in.workGroupSize.y() + in.workGroupSize.z() );
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void compute( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "compute" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };
		ArrayStorageBufferT< UInt > ssbo{ writer, "Datas", writer.getTypesCache().getUInt32(), ast::type::MemoryLayout::eStd140 , 0u, 0u, true };
		auto img = writer.declStorageImg< RWUImg2DR32 >( "img", 1u, 0u );

		writer.implementMainT< VoidT >( 16u, 16u, [&]( ComputeIn in )
			{
				ssbo[in.globalInvocationID.x()]
					= ssbo[in.globalInvocationID.x()]
					* ssbo[in.globalInvocationID.x()];
				img.store( ivec2( in.globalInvocationID.xy() )
					, ssbo[in.globalInvocationID.x()] );
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );

#if !defined( __APPLE__ )
		// Disabled on apple since somebody somewhere thinks putting an ivec3 inside an uint3 intrinsic is doable :/.
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
#endif

		testEnd();
	}

	void swizzles( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "swizzles" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto c3d_mapDepth = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapDepth", 1u, 0u );

		auto SMAAEdgeDetectionVS = writer.implementFunction< sdw::Void >( "SMAAEdgeDetectionVS"
			, [&]( Vec4 const & rtMetrics
				, Vec2 const & texcoord
				, Array< Vec4 > offset )
			{
				offset[0] = fma( rtMetrics.xyxy(), vec4( -1.0_f, 0.0, 0.0, -1.0 ), vec4( texcoord.xy(), texcoord.xy() ) );
				offset[1] = fma( rtMetrics.xyxy(), vec4( 1.0_f, 0.0, 0.0, 1.0 ), vec4( texcoord.xy(), texcoord.xy() ) );
				offset[2] = fma( rtMetrics.xyxy(), vec4( -2.0_f, 0.0, 0.0, -2.0 ), vec4( texcoord.xy(), texcoord.xy() ) );
			}
			, InVec4{ writer, "rtMetrics" }
			, InVec2{ writer, "texcoord" }
			, OutVec4Array{ writer, "offset", 3u } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto csPosition = writer.declLocale< Vec4 >( "csPosition" );
				csPosition.xyz() /= csPosition.w();
				csPosition.x() /= fma( csPosition.x(), 0.5_f, 0.5_f );
				auto csPositions = writer.declLocaleArray< Vec4 >( "csPositions", 4u );
				csPositions[0].xyz() /= csPositions[1].w();
				auto ssPosition = writer.declLocale< IVec2 >( "ssPosition" );
				auto position = writer.declLocale< Vec3 >( "position" );
				position.z() = c3d_mapDepth.fetch( ssPosition, 0_i ).r();
				auto lrtMetrics = writer.declLocale< Vec4 >( "lrtMetrics" );
				auto ltexcoord = writer.declLocale< Vec2 >( "ltexcoord" );
				auto loffset = writer.declLocaleArray< Vec4 >( "loffset", 3u );
				SMAAEdgeDetectionVS( lrtMetrics, ltexcoord, loffset );
				auto L = writer.declLocale< Float >( "L" );
				auto Lright = writer.declLocale< Float >( "Lright" );
				auto Lbottom = writer.declLocale< Float >( "Lbottom" );
				auto delta = writer.declLocale< Vec4 >( "delta" );
				delta.zw() = abs( L - vec2( Lright, Lbottom ) );
				auto texcoord = writer.declLocale< Vec2 >( "texcoord" );
				auto a = writer.declLocale< Vec4 >( "a" );
				a.wz() = c3d_mapDepth.lod( texcoord, 0.0_f ).xz();
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void conversions( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "conversions" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto o = writer.declLocaleArray( "o"
					, 6u
					, std::vector< Float >{
						{
							-1.0_f, -0.6667_f, -0.3333_f, 0.3333_f, 0.6667_f, 1.0_f
						} } );
				auto offset = writer.declLocale( "offset"
					, sdw::fma( vec2( o[0] )
						, vec2( 1.0_f )
						, vec2( 0.0_f ) ) );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void simpleStore( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simpleStore" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto kernelImage =
				writer.declStorageImg<RWFImg2DRgba32>( "kernelImage", 0, 0 );

			writer.implementMainT< VoidT >( 32u, [&]( ComputeIn in )
				{
					IVec2 iuv = writer.declLocale(
						"iuv", ivec2( writer.cast<Int>( in.globalInvocationID.x() ),
							writer.cast<Int>( in.globalInvocationID.y() ) ) );

					kernelImage.store( iuv, vec4( 1.0_f ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void voxelToTexture( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "voxelToTexture" );
		using namespace sdw;
		sdw::ShaderArray shaders;

		{
			enum IDs : uint32_t
			{
				eVoxelUbo,
				eVoxels,
				eResult,
			};

			using namespace sdw;
			sdw::ComputeWriter writer{ &testCounts.allocator };

			// Inputs
			sdw::UniformBuffer voxelizer{ writer
				, "VoxelUbo"
				, eVoxelUbo
				, 0u };
			auto c3d_voxelTransform = voxelizer.declMember< sdw::Mat4 >( "c3d_voxelTransform" );
			auto c3d_voxelCenter = voxelizer.declMember< sdw::Vec4 >( "c3d_voxelCenter" );
			auto c3d_voxelSize = voxelizer.declMember< sdw::Float >( "c3d_voxelSize" );
			auto c3d_voxelSizeInverse = voxelizer.declMember< sdw::Float >( "c3d_voxelSizeInverse" );
			auto c3d_voxelResolution = voxelizer.declMember< sdw::Float >( "c3d_voxelResolution" );
			auto c3d_voxelResolutionInverse = voxelizer.declMember< sdw::Float >( "c3d_voxelResolutionInverse" );
			voxelizer.end();

			auto voxels( writer.declArrayStorageBuffer< Voxel >( "voxels"
				, eVoxels
				, 0u ) );

			// Outputs
			auto result( writer.declStorageImg< RWFImg3DRgba32 >( "result"
				, eResult
				, 0u ) );

			auto decodeColor = writer.implementFunction< Vec4 >( "decodeColor"
				, [&]( UInt const & colorMask )
				{
					auto hdrRange = writer.declConstant( "hdrRange", 10.0_f );

					auto color = writer.declLocale< Vec4 >( "color" );
					auto hdr = writer.declLocale( "hdr"
						, writer.cast< Float >( ( colorMask >> 24u ) & 0x0000007f_u ) );
					color.r() = writer.cast< Float >( ( colorMask >> 16u ) & 0x000000ff_u );
					color.g() = writer.cast< Float >( ( colorMask >> 8u ) & 0x000000ff_u );
					color.b() = writer.cast< Float >( colorMask & 0x000000ff_u );

					hdr /= 127.0f;
					color.rgb() /= vec3( 255.0_f );

					color.rgb() *= hdr * hdrRange;

					color.a() = writer.cast< Float >( ( colorMask >> 31u ) & 0x00000001_u );

					writer.returnStmt( color );
				}
				, InUInt{ writer, "colorMask" } );

			auto unflatten = writer.implementFunction< UVec3 >( "unflatten3D"
				, [&]( UInt idx
					, UVec3 const & dim )
				{
					auto z = writer.declLocale( "z"
						, idx / ( dim.x() * dim.y() ) );
					idx -= ( z * dim.x() * dim.y() );
					auto y = writer.declLocale( "y"
						, idx / dim.x() );
					auto x = writer.declLocale( "x"
						, idx % dim.x() );
					writer.returnStmt( uvec3( x, y, z ) );
				}
				, InUInt{ writer, "idx" }
				, InUVec3{ writer, "dim" } );

			writer.implementMainT< VoidT >( 256u, [&]( ComputeIn in )
				{
					auto color = writer.declLocale( "color"
						, decodeColor( voxels[in.globalInvocationID.x()].colorMask ) );

					IF( writer, color.a() > 0.0_f )
					{
						auto coord = writer.declLocale( "coord"
							, ivec3( unflatten( in.globalInvocationID.x()
								, uvec3( writer.cast< UInt >( c3d_voxelResolution ) ) ) ) );
						result.store( coord, color );
					}
					FI;

					voxels[in.globalInvocationID.x()].colorMask = 0_u;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void imageArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "imageArray" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto srcImage = writer.declStorageImg<RFImg2DRgba32>( "srcImage", 0, 0 );
			auto dstImage = writer.declStorageImgArray<RWFImg2DRgba32>( "dstImage", 1, 0, 4u );

			writer.implementMainT< VoidT >( 32u, [&]( ComputeIn in )
				{
					IVec2 iuv = writer.declLocale(
						"iuv", ivec2( writer.cast<Int>( in.globalInvocationID.x() ),
							writer.cast<Int>( in.globalInvocationID.y() ) ) );

					dstImage[1].store( iuv, srcImage.load( iuv ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void accessChainAlias( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "accessChainAlias" );
		using namespace sdw;
		ShaderArray shaders;
		{
			auto writer = ComputeWriter{};

			sdw::UniformBuffer ubo{ writer, "Wow", 0u, 0u };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

			writer.implementMainT< VoidT >( 16u, 16u, [&]( ComputeIn in )
				{
					auto tmp = writer.declLocale( "tmp"
						, normalize( transpose( mat3( mtx ) ) * pos ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void duplicateLoadTest( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "duplicateLoadTest" );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			auto foo = writer.implementFunction< sdw::Vec4 >( "foo"
				, [&]( Vec3 const & t
					, Vec2 const & dir )
				{
					auto coord = writer.declLocale< Vec4 >( "coord" );
					coord.xyz() = fma( t, vec3( dir, 1.0_f ), coord.xyz() );
					writer.returnStmt( coord );
				}
				, InVec3{ writer, "t" }
				, InVec2{ writer, "dir" } );

			writer.implementMainT< VoidT >( 16u, 16u, [&]( ComputeIn in )
				{
					auto t = writer.declLocale( "t", vec3( 0.5_f ) );
					auto dir = writer.declLocale( "dir", vec2( 1.0_f ) );
					foo( t, dir );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void subgroupEmptyMain( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupEmptyMain" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, 16u, [&]( SubgroupIn in )
			{
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void subgroupBuiltins( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupBuiltins" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, 16u, [&]( SubgroupIn in )
			{
				writer.declLocale( "globalInvocationID", in.globalInvocationID );
				writer.declLocale( "localInvocationID", in.localInvocationID );
				writer.declLocale( "localInvocationIndex", in.localInvocationIndex );
				writer.declLocale( "numWorkGroups", in.numWorkGroups );
				writer.declLocale( "workGroupID", in.workGroupID );
				writer.declLocale( "workGroupSize", in.workGroupSize );
				writer.declLocale( "numSubgroups", in.numSubgroups );
				writer.declLocale( "subgroupID", in.subgroupID );
				writer.declLocale( "subgroupSize", in.subgroupSize );
				writer.declLocale( "subgroupInvocationID", in.subgroupInvocationID );
				writer.declLocale( "subgroupEqMask", in.subgroupEqMask );
				writer.declLocale( "subgroupGeMask", in.subgroupGeMask );
				writer.declLocale( "subgroupLeMask", in.subgroupLeMask );
				writer.declLocale( "subgroupLtMask", in.subgroupLtMask );
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void subgroupCompute( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupCompute" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };
		ArrayStorageBufferT< UInt > ssbo{ writer, "Datas", writer.getTypesCache().getUInt32(), ast::type::MemoryLayout::eStd140 , 0u, 0u, true };
		auto img = writer.declStorageImg< RWUImg2DR32 >( "img", 1u, 0u );

		writer.implementMainT< VoidT >( 16u, 16u, [&]( SubgroupIn in )
			{
				ssbo[in.subgroupInvocationID]
					= ssbo[in.subgroupInvocationID];
				img.store( ivec2( in.subgroupInvocationID )
					, ssbo[in.subgroupInvocationID] );
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );

#if !defined( __APPLE__ )
		// Disabled on apple since somebody somewhere thinks putting an ivec3 inside an uint3 intrinsic is doable :/.
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
#endif

		testEnd();
	}

	void subgroupSimpleStore( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupSimpleStore" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto kernelImage =
				writer.declStorageImg<RWFImg2DRgba32>( "kernelImage", 0, 0 );

			writer.implementMainT< VoidT >( 32u, [&]( SubgroupIn in )
				{
					IVec2 iuv = writer.declLocale(
						"iuv", ivec2( writer.cast<Int>( in.subgroupInvocationID ),
							writer.cast<Int>( in.subgroupInvocationID ) ) );

					kernelImage.store( iuv, vec4( 1.0_f ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterComputeShader )
{
	sdwTestSuiteBegin();
	emptyMain( testCounts );
	builtins( testCounts );
	readWorkGroupSize( testCounts );
	compute( testCounts );
	swizzles( testCounts );
	conversions( testCounts );
	simpleStore( testCounts );
	voxelToTexture( testCounts );
	imageArray( testCounts );
	accessChainAlias( testCounts );
	duplicateLoadTest( testCounts );
	subgroupEmptyMain( testCounts );
	subgroupBuiltins( testCounts );
	subgroupCompute( testCounts );
	subgroupSimpleStore( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterComputeShader )
