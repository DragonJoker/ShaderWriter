#include "Common.hpp"
#include "WriterCommon.hpp"

#define SDW_PreferredMeshShadingExtension SDW_MeshShadingNV

#include <ShaderWriter/ModernGraphicsWriterEXT.hpp>
#include <ShaderWriter/ModernGraphicsWriterNV.hpp>
#include <ShaderWriter/ModernGraphicsWriter.hpp>
#include <ShaderWriter/RayTraceWriter.hpp>
#include <ShaderWriter/TraditionalGraphicsWriter.hpp>
#include <ShaderWriter/CompositeTypes/IOStructHelper.hpp>
#include <ShaderWriter/CompositeTypes/IOStructInstanceHelper.hpp>
#include <ShaderWriter/CompositeTypes/PushConstantBuffer.hpp>

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

#define RayTraceCompilers Compilers_NoHLSL
#define MeshEXTCompilers Compilers_SPIRV

namespace
{
	namespace common
	{
		template< sdw::var::Flag FlagT >
		using ColourTStructT = sdw::IOStructInstanceHelperT< FlagT
			, "Colour"
			, sdw::IOVec4Field< "colour", 0u > >;
		template< sdw::var::Flag FlagT >
		using PosColStructT = sdw::MixedStructInstanceHelperT< FlagT
			, "PosCol"
			, sdw::type::MemoryLayout::eStd430
			, sdw::IOVec4Field< "position", 0u >
			, sdw::IOVec4Field< "colour", 1u > >;

		template< sdw::var::Flag FlagT >
		struct ColourT
			: public ColourTStructT< FlagT >
		{
			ColourT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: ColourTStructT< FlagT >{ writer, std::move( expr ), enabled }
			{
			}

			auto colour()const { return this->template getMember< "colour" >(); }
		};

		template< sdw::var::Flag FlagT >
		struct PosColT
			: public PosColStructT< FlagT >
		{
			PosColT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: PosColStructT< FlagT >{ writer, std::move( expr ), enabled }
			{
			}

			auto position()const { return this->template getMember< "position" >(); }
			auto colour()const { return this->template getMember< "colour" >(); }
		};

		using PosCol = PosColT< sdw::var::Flag::eNone >;
	}

	void basicPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "basicPipeline" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };

		sdw::UniformBuffer myUbo{ writer, "MyUbo", 0u, 0u };
		auto mvp = myUbo.declMember< sdw::Mat4 >( "mvp" );
		myUbo.end();

		// Vertex Shader
		writer.implementEntryPointT< common::PosColT, common::ColourT >( [&]( sdw::VertexInT< common::PosColT > in
			, sdw::VertexOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
				out.vtx.position = mvp * in.position();
			} );

		// Fragment Shader
		writer.implementEntryPointT< common::ColourT, common::ColourT >( [&]( sdw::FragmentInT< common::ColourT > in
			, sdw::FragmentOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void geometryPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "geometryPipeline" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };

		sdw::UniformBuffer myUbo{ writer, "MyUbo", 0u, 0u };
		auto mvp = myUbo.declMember< sdw::Mat4 >( "mvp" );
		myUbo.end();

		// Vertex Shader
		writer.implementEntryPointT< common::PosColT, common::ColourT >( [&]( sdw::VertexInT< common::PosColT > in
			, sdw::VertexOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
				out.vtx.position = in.position();
			} );

		// Geometry Shader
		writer.implementEntryPointT< 3u, sdw::TriangleListT< common::ColourT >, sdw::TriangleStreamT< common::ColourT > >( [&]( sdw::GeometryIn in
			, sdw::TriangleListT< common::ColourT > list
			, sdw::TriangleStreamT< common::ColourT > out )
			{
				out.colour() = list[0].colour();
				out.vtx.position = mvp * list[0].vtx.position;
				out.append();

				out.colour() = list[1].colour();
				out.vtx.position = mvp * list[1].vtx.position;
				out.append();

				out.colour() = list[2].colour();
				out.vtx.position = mvp * list[2].vtx.position;
				out.append();

				out.restartStrip();
			} );

		// Fragment Shader
		writer.implementEntryPointT< common::ColourT, common::ColourT >( [&]( sdw::FragmentInT< common::ColourT > in
			, sdw::FragmentOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	namespace tess
	{
		template< sdw::var::Flag FlagT >
		using PosColNmlStructT = sdw::MixedStructInstanceHelperT< FlagT
			, "PosColNml"
			, sdw::type::MemoryLayout::eStd430
			, sdw::IOVec4Field< "position", 0u >
			, sdw::IOVec3Field< "normal", 2u >
			, sdw::IOVec4Field< "colour", 3u > >;
		template< sdw::var::Flag FlagT >
		using PNTriPatchStructT = sdw::MixedStructInstanceHelperT< FlagT
			, "PNTriPatch"
			, sdw::type::MemoryLayout::eC
			, sdw::IOVec3Field< "wpB030", 0u >
			, sdw::IOVec3Field< "wpB021", 1u >
			, sdw::IOVec3Field< "wpB012", 2u >
			, sdw::IOVec3Field< "wpB003", 3u >
			, sdw::IOVec3Field< "wpB102", 4u >
			, sdw::IOVec3Field< "wpB201", 5u >
			, sdw::IOVec3Field< "wpB300", 6u >
			, sdw::IOVec3Field< "wpB210", 7u >
			, sdw::IOVec3Field< "wpB120", 8u >
			, sdw::IOVec3Field< "wpB111", 9u > >;

		template< sdw::var::Flag FlagT >
		struct PNTriPatchT
			: PNTriPatchStructT< FlagT >
		{
			PNTriPatchT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: PNTriPatchStructT< FlagT >{ writer, std::move( expr ), enabled }
			{
			}

			auto wpB030()const { return this->template getMember< "wpB030" >(); }
			auto wpB021()const { return this->template getMember< "wpB021" >(); }
			auto wpB012()const { return this->template getMember< "wpB012" >(); }
			auto wpB003()const { return this->template getMember< "wpB003" >(); }
			auto wpB102()const { return this->template getMember< "wpB102" >(); }
			auto wpB201()const { return this->template getMember< "wpB201" >(); }
			auto wpB300()const { return this->template getMember< "wpB300" >(); }
			auto wpB210()const { return this->template getMember< "wpB210" >(); }
			auto wpB120()const { return this->template getMember< "wpB120" >(); }
			auto wpB111()const { return this->template getMember< "wpB111" >(); }
		};

		template< sdw::var::Flag FlagT >
		struct PosColNmlT
			: PosColNmlStructT< FlagT >
		{
			PosColNmlT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: PosColNmlStructT< FlagT >{ writer, std::move( expr ), enabled }
			{
			}

			auto position()const { return this->template getMember< "position" >(); }
			auto normal()const { return this->template getMember< "normal" >(); }
			auto colour()const { return this->template getMember< "colour" >(); }
		};
	}

	void tessellationPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "tessellationPipeline" );
		static uint32_t constexpr maxPoints = 3u;
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };

		sdw::UniformBuffer ubo{ writer, "Wow", 0u, 0u };
		auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
		auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
		ubo.end();

		auto c3d_mapNormal = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapNormal", 1u, 0u );

		auto getTessLevel = writer.implementFunction< sdw::Float >( "getTessLevel"
			, [&]( sdw::Float const & a
				, sdw::Float const & b )
			{
				auto avgDistance = writer.declLocale( "avgDistance"
					, ( a + b ) / 2.0_f );

				IF( writer, avgDistance <= 20.0_f )
				{
					writer.returnStmt( 256.0_f );
				}
				ELSEIF( avgDistance <= 50.0_f )
				{
					writer.returnStmt( 128.0_f );
				}
				ELSEIF( avgDistance <= 100.0_f )
				{
					writer.returnStmt( 64.0_f );
				}
				FI;

				writer.returnStmt( 16.0_f );
			}
			, sdw::InFloat{ writer, "a" }
			, sdw::InFloat{ writer, "b" } );

		auto projectToPlane = writer.implementFunction< sdw::Vec3 >( "projectToPlane"
			, [&]( sdw::Vec3 const & point
				, sdw::Vec3 const & planePoint
				, sdw::Vec3 const & planeNormal )
			{
				auto v = writer.declLocale( "v"
					, point - planePoint );
				writer.returnStmt( point - dot( v, planeNormal ) * planeNormal );
			}
			, sdw::InVec3{ writer, "point" }
			, sdw::InVec3{ writer, "planePoint" }
			, sdw::InVec3{ writer, "planeNormal " } );

		auto interpolate4D = writer.implementFunction< sdw::Vec4 >( "interpolate4D"
			, [&]( sdw::Vec3 const & tessCoord
				, sdw::Vec4 const & v0
				, sdw::Vec4 const & v1
				, sdw::Vec4 const & v2 )
			{
				writer.returnStmt( vec4( tessCoord.x() ) * v0
					+ vec4( tessCoord.y() ) * v1
					+ vec4( tessCoord.z() ) * v2 );
			}
			, sdw::InVec3{ writer, "tessCoord" }
			, sdw::InVec4{ writer, "v0" }
			, sdw::InVec4{ writer, "v1" }
			, sdw::InVec4{ writer, "v2" } );

		// Vertex Shader
		writer.implementEntryPointT< tess::PosColNmlT, tess::PosColNmlT >( [&]( sdw::VertexInT< tess::PosColNmlT > in
			, sdw::VertexOutT< tess::PosColNmlT > out )
			{
				out.position() = in.position();
				out.normal() = in.normal();
				out.colour() = in.colour();
				out.vtx.position = in.position();
			} );

		// Tessellation Control Shader
		writer.implementPatchRoutineT< tess::PosColNmlT, maxPoints, tess::PNTriPatchT >( 6u
			, [&]( sdw::TessControlPatchRoutineIn in
				, sdw::TessControlListInT< tess::PosColNmlT, maxPoints > listIn
				, sdw::TrianglesTessPatchOutT< tess::PNTriPatchT > patchOut )
			{
				// The original vertices stay the same
				patchOut.wpB030() = listIn[0].position().xyz();
				patchOut.wpB003() = listIn[1].position().xyz();
				patchOut.wpB300() = listIn[2].position().xyz();

				// Edges are names according to the opposing vertex
				auto edgeB300 = writer.declLocale( "edgeB300"
					, patchOut.wpB003() - patchOut.wpB030() );
				auto edgeB030 = writer.declLocale( "edgeB030"
					, patchOut.wpB300() - patchOut.wpB003() );
				auto edgeB003 = writer.declLocale( "edgeB003"
					, patchOut.wpB030() - patchOut.wpB300() );

				// Generate two midpoints on each edge
				patchOut.wpB021() = patchOut.wpB030() + edgeB300 / 3.0f;
				patchOut.wpB012() = patchOut.wpB030() + edgeB300 * 2.0f / 3.0f;
				patchOut.wpB102() = patchOut.wpB003() + edgeB030 / 3.0f;
				patchOut.wpB201() = patchOut.wpB003() + edgeB030 * 2.0f / 3.0f;
				patchOut.wpB210() = patchOut.wpB300() + edgeB003 / 3.0f;
				patchOut.wpB120() = patchOut.wpB300() + edgeB003 * 2.0f / 3.0f;

				// Project each midpoint on the plane defined by the nearest vertex and its normal
				patchOut.wpB021() = projectToPlane( patchOut.wpB021()
					, patchOut.wpB030()
					, listIn[0].normal() );
				patchOut.wpB012() = projectToPlane( patchOut.wpB012()
					, patchOut.wpB003()
					, listIn[1].normal() );
				patchOut.wpB102() = projectToPlane( patchOut.wpB102()
					, patchOut.wpB003()
					, listIn[1].normal() );
				patchOut.wpB201() = projectToPlane( patchOut.wpB201()
					, patchOut.wpB300()
					, listIn[2].normal() );
				patchOut.wpB210() = projectToPlane( patchOut.wpB210()
					, patchOut.wpB300()
					, listIn[2].normal() );
				patchOut.wpB120() = projectToPlane( patchOut.wpB120()
					, patchOut.wpB030()
					, listIn[0].normal() );

				// Handle the center
				auto center = writer.declLocale( "center"
					, ( patchOut.wpB003()
						+ patchOut.wpB030()
						+ patchOut.wpB300() ) / 3.0f );
				patchOut.wpB111() = ( patchOut.wpB021()
					+ patchOut.wpB012()
					+ patchOut.wpB102()
					+ patchOut.wpB201()
					+ patchOut.wpB210()
					+ patchOut.wpB120() ) / 6.0f;
				patchOut.wpB111() += ( patchOut.wpB111() - center ) / 2.0f;

				// Calculate the distance from the camera to the three control points
				auto eyeToVertexDistance0 = writer.declLocale( "eyeToVertexDistance0"
					, distance( pos, listIn[0].position().xyz() ) );
				auto eyeToVertexDistance1 = writer.declLocale( "eyeToVertexDistance1"
					, distance( pos, listIn[1].position().xyz() ) );
				auto eyeToVertexDistance2 = writer.declLocale( "eyeToVertexDistance2"
					, distance( pos, listIn[2].position().xyz() ) );

				// Calculate the tessellation levels
				patchOut.tessLevelOuter[0] = getTessLevel( eyeToVertexDistance1, eyeToVertexDistance2 );
				patchOut.tessLevelOuter[1] = getTessLevel( eyeToVertexDistance2, eyeToVertexDistance0 );
				patchOut.tessLevelOuter[2] = getTessLevel( eyeToVertexDistance0, eyeToVertexDistance1 );
				patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[2];
			} );

		writer.implementEntryPointT< tess::PosColNmlT, maxPoints, common::ColourT >( sdw::type::Partitioning::eEqual
			, sdw::type::OutputTopology::ePoint
			, sdw::type::PrimitiveOrdering::eCCW
			, 3u
			, [&]( sdw::TessControlMainIn in
				, sdw::TessControlListInT< tess::PosColNmlT, maxPoints > listIn
				, sdw::TrianglesTessControlListOutT< common::ColourT > listOut )
			{
				listOut.colour() = listIn[in.invocationID].colour();
			} );

		// Tessellation Evaluation Shader
		writer.implementEntryPointT< common::ColourT, maxPoints, tess::PNTriPatchT, common::ColourT >( 6u
			, sdw::type::Partitioning::eEqual
			, sdw::type::PrimitiveOrdering::eCCW
			, [&]( sdw::TessEvalMainIn mainIn
				, sdw::TessEvalListInT< common::ColourT, maxPoints > listIn
				, sdw::TrianglesTessPatchInT< tess::PNTriPatchT > patchIn
				, sdw::TessEvalDataOutT< common::ColourT > out )
			{
				// Interpolate the attributes of the output vertex using the barycentric coordinates
				out.colour() = interpolate4D( patchIn.tessCoord
					, listIn[0].colour()
					, listIn[1].colour()
					, listIn[2].colour() );

				auto u = writer.declLocale( "u"
					, patchIn.tessCoord.x() );
				auto v = writer.declLocale( "v"
					, patchIn.tessCoord.y() );
				auto w = writer.declLocale( "w"
					, patchIn.tessCoord.z() );

				auto uPow3 = writer.declLocale( "uPow3"
					, pow( u, 3.0_f ) );
				auto vPow3 = writer.declLocale( "vPow3"
					, pow( v, 3.0_f ) );
				auto wPow3 = writer.declLocale( "wPow3"
					, pow( w, 3.0_f ) );
				auto uPow2 = writer.declLocale( "uPow2"
					, pow( u, 2.0_f ) );
				auto vPow2 = writer.declLocale( "vPow2"
					, pow( v, 2.0_f ) );
				auto wPow2 = writer.declLocale( "wPow2"
					, pow( w, 2.0_f ) );

				auto pos = writer.declLocale( "pos"
					, patchIn.wpB300() * wPow3
						+ patchIn.wpB030() * uPow3
						+ patchIn.wpB003() * vPow3
						+ patchIn.wpB210() * 3.0f * wPow2 * u
						+ patchIn.wpB120() * 3.0f * w * uPow2
						+ patchIn.wpB201() * 3.0f * wPow2 * v
						+ patchIn.wpB021() * 3.0f * uPow2 * v
						+ patchIn.wpB102() * 3.0f * w * vPow2
						+ patchIn.wpB012() * 3.0f * u * vPow2
						+ patchIn.wpB111() * 6.0f * w * u * v );

				out.vtx.position = mtx * vec4( pos, 1.0f );
			} );

		// Fragment Shader
		writer.implementEntryPointT< common::ColourT, common::ColourT >( [&]( sdw::FragmentInT< common::ColourT > in
			, sdw::FragmentOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	namespace raytrace
	{
		struct HitPayload
			: sdw::StructInstanceHelperT< "HitPayload"
				, sdw::type::MemoryLayout::eStd430
				, sdw::Vec3Field< "color" > >
		{
			HitPayload( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: StructInstanceHelperT{ writer, std::move( expr ), enabled }
			{
			}

			auto color()const { return getMember< "color" >(); }
		};

		struct ObjDesc
			: sdw::StructInstanceHelperT< "ObjDesc"
				, sdw::type::MemoryLayout::eStd430
				, sdw::Int32Field< "txtOffset" >
				, sdw::UInt64Field< "vertexAddress" >
				, sdw::UInt64Field< "indexAddress" >
				, sdw::UInt64Field< "materialAddress" >
				, sdw::UInt64Field< "materialIndexAddress" > >
		{
			ObjDesc( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: StructInstanceHelperT{ writer, std::move( expr ), enabled }
			{
			}

			auto txtOffset()const { return getMember< "txtOffset" >(); }
			auto vertexAddress()const { return getMember< "vertexAddress" >(); }
			auto indexAddress()const { return getMember< "indexAddress" >(); }
			auto materialAddress()const { return getMember< "materialAddress" >(); }
			auto materialIndexAddress()const { return getMember< "materialIndexAddress" >(); }
		};

		struct Vertex
			: sdw::StructInstanceHelperT< "Vertex"
				, sdw::type::MemoryLayout::eScalar
				, sdw::Vec3Field< "pos" >
				, sdw::Vec3Field< "nrm" >
				, sdw::Vec3Field< "color" >
				, sdw::Vec2Field< "texCoord" > >
		{
			Vertex( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: StructInstanceHelperT{ writer, std::move( expr ), enabled }
			{
			}
		
			auto pos()const { return getMember< "pos" >(); }
			auto nrm()const { return getMember< "nrm" >(); }
			auto color()const { return getMember< "color" >(); }
			auto texCoord()const { return getMember< "texCoord" >(); }
		};
	}

	void rayTracePipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "rayTracePipeline" );
		sdw::RayTraceWriter writer{ &testCounts.allocator };

		auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
		auto image = writer.declStorageImg< WFImg2DRgba32 >( "image", 1u, 0u );

		auto ubo = writer.declUniformBuffer( "GlobalUniforms", 2u, 0u );
		auto viewProj = ubo.declMember< sdw::Mat4 >( "viewProj" );
		auto viewInverse = ubo.declMember< sdw::Mat4 >( "viewInverse" );
		auto projInverse = ubo.declMember< sdw::Mat4 >( "projInverse" );
		auto clearColor = ubo.declMember< sdw::Vec4 >( "clearColor" );
		ubo.end();

		auto objDescs = writer.declArrayStorageBuffer< raytrace::ObjDesc >( "ObjDescs", 0u, 1u );
		auto Vertices = writer.declBufferReference< sdw::ArrayStorageBufferT< raytrace::Vertex > >( "Vertices", sdw::type::MemoryLayout::eScalar, sdw::type::Storage::ePhysicalStorageBuffer );
		auto Indices = writer.declBufferReference< sdw::ArrayStorageBufferT< sdw::IVec3 > >( "Indices", sdw::type::MemoryLayout::eScalar, sdw::type::Storage::ePhysicalStorageBuffer );

		auto traceRay = writer.implementFunction< sdw::Vec3 >( "traceRay"
			, [&]( sdw::Vec2 const samplePos )
			{
				auto target = writer.declLocale( "target"
					, projInverse * vec4( samplePos.x(), samplePos.y(), 1.0_f, 1.0_f ) );
				auto rayFlags = writer.declLocale( "rayFlags"
					, sdw::RayFlags::Opaque() );
				auto ray = writer.declLocale< sdw::RayDesc >( "ray" );
				ray.origin = vec3( viewInverse * vec4( 0.0_f, 0.0_f, 0.0_f, 1.0_f ) );
				ray.direction = vec3( viewInverse * vec4( normalize( target.xyz() ), 0.0_f ) );
				ray.tMin = 0.001_f;
				ray.tMax = 10000.0_f;
				auto rayPayload = writer.declRayPayload< raytrace::HitPayload >( "rayPayload", 0u );
				rayPayload.traceRay( topLevelAS	// acceleration structure
					, rayFlags					// rayFlags
					, 0xFF_u					// cullMask
					, 0_u						// sbtRecordOffset
					, 0_u						// sbtRecordStride
					, 0_u						// missIndex
					, ray );
				writer.returnStmt( rayPayload.color() );
			}
			, sdw::InVec2{ writer, "samplePos" } );

		// Ray Generation shader
		writer.implementEntryPoint( [&]( sdw::RayGenerationIn in )
			{
				auto const pixelCenter = writer.declLocale( "pixelCenter"
					, vec2( in.launchID.xy() ) + vec2( 0.5_f ) );
				auto const inUV = writer.declLocale( "inUV"
					, pixelCenter / vec2( in.launchSize.xy() ) );
				auto samplePos = writer.declLocale( "samplePos"
					, inUV * 2.0_f - 1.0_f );
				image.store( ivec2( in.launchID.xy() ), vec4( traceRay( samplePos ), 1.0_f ) );
			} );

		// Ray Closest Hit shader
		writer.implementEntryPointT< raytrace::HitPayload, sdw::Vec2 >( sdw::RayPayloadInT< raytrace::HitPayload >{ writer, 0u }
			, sdw::HitAttributeT< sdw::Vec2 >{ writer }
			, [&]( sdw::RayClosestHitIn in
				, sdw::RayPayloadInT< raytrace::HitPayload > prd
				, sdw::HitAttributeT< sdw::Vec2 > attribs )
			{
				// Object data
				auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< sdw::UInt >( in.instanceCustomIndex )] );
				auto indices = Indices( "indices", objResource.indexAddress() );
				auto vertices = Vertices( "vertices", objResource.vertexAddress() );

				// Indices of the triangle
				auto ind = writer.declLocale( "ind", indices[writer.cast< sdw::UInt >( in.primitiveID )] );

				// Vertex of the triangle
				auto v0 = writer.declLocale( "v0", vertices[writer.cast< sdw::UInt >( ind.x() )] );
				auto v1 = writer.declLocale( "v1", vertices[writer.cast< sdw::UInt >( ind.y() )] );
				auto v2 = writer.declLocale( "v2", vertices[writer.cast< sdw::UInt >( ind.z() )] );

				auto const barycentrics = writer.declLocale( "barycentrics"
					, vec3( 1.0_f - attribs.x() - attribs.y(), attribs.x(), attribs.y() ) );

				// Computing the coordinates of the hit position
				auto const pos = writer.declLocale( "pos", v0.pos() * barycentrics.x() + v1.pos() * barycentrics.y() + v2.pos() * barycentrics.z() );
				auto const worldPos = writer.declLocale( "worldPos", in.objectToWorld * vec4( pos, 1.0 ) );  // Transforming the position to world space

				prd.color() = worldPos;
			} );

		// Ray Miss shader
		writer.implementEntryPointT< raytrace::HitPayload >( sdw::RayPayloadInT< raytrace::HitPayload >{ writer, 0u }
			, [&]( sdw::RayMissIn in
				, sdw::RayPayloadInT< raytrace::HitPayload > payload )
			{
				payload.color() = clearColor.xyz() * 0.8_f;
			} );

		test::writeProgram( writer
			, testCounts, RayTraceCompilers );
		testEnd();
	}

	namespace mesh
	{
		static uint32_t const ThreadsPerWave = 32u;

		template< sdw::var::Flag FlagT >
		using PayloadStructT = sdw::IOStructInstanceHelperT< FlagT
			, "Payload"
			, sdw::IOUIntArrayField< "meshletIndices", ast::type::Struct::InvalidLocation, ThreadsPerWave > >;

		struct Meshlet
			: public sdw::StructInstanceHelperT< "Meshlet"
				, sdw::type::MemoryLayout::eStd430
				, sdw::UIntField< "vertCount" >
				, sdw::UIntField< "vertOffset" >
				, sdw::UIntField< "primCount" >
				, sdw::UIntField< "primOffset" > >
		{
			Meshlet( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: StructInstanceHelperT{ writer, std::move( expr ), enabled }
			{
			}

			auto vertCount()const { return getMember< "vertCount" >(); }
			auto vertOffset()const { return getMember< "vertOffset" >(); }
			auto primCount()const { return getMember< "primCount" >(); }
			auto primOffset()const { return getMember< "primOffset" >(); }
		};

		struct TriIndex
			: public sdw::StructInstanceHelperT< "TriIndex"
			, sdw::type::MemoryLayout::eStd430
			, sdw::U32Vec3Field< "index" > >
		{
			TriIndex( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: StructInstanceHelperT{ writer, std::move( expr ), enabled }
			{
			}

			auto index()const { return getMember< "index" >(); }
		};

		struct VtxIndex
			: public sdw::StructInstanceHelperT< "VtxIndex"
				, sdw::type::MemoryLayout::eStd430
				, sdw::UIntField< "index" > >
		{
			VtxIndex( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: StructInstanceHelperT{ writer, std::move( expr ), enabled }
			{
			}

			auto index()const { return getMember< "index" >(); }
		};

		struct CullData
			: public sdw::StructInstanceHelperT< "CullData"
				, sdw::type::MemoryLayout::eStd430
				, sdw::Vec4Field< "boundingSphere" > >
		{
			CullData( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: StructInstanceHelperT{ writer, std::move( expr ), enabled }
			{
			}

			auto boundingSphere()const { return getMember< "boundingSphere" >(); }
		};

		template< sdw::var::Flag FlagT >
		struct PayloadT
			: public PayloadStructT< FlagT >
		{
			PayloadT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: PayloadStructT< FlagT >{ writer, std::move( expr ), enabled }
			{
			}

			auto meshletIndices()const { return this->template getMember< "meshletIndices" >(); }
		};
	}

	void taskMeshPipelineEXT( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "taskMeshPipelineEXT" );
		sdw::ModernGraphicsWriterEXT writer{ &testCounts.allocator };

		auto ModelUbo = writer.declUniformBuffer( "ModelUbo", 1u, 0u );
		auto mvp = ModelUbo.declMember< sdw::Mat4 >( "mvp" );
		auto world = ModelUbo.declMember< sdw::Mat4 >( "world" );
		auto scale = ModelUbo.declMember< sdw::Float >( "scale" );
		auto cullPlanes = ModelUbo.declMember< sdw::Vec4 >( "cullPlanes", 6u );
		ModelUbo.end();

		auto vertices = writer.declArrayStorageBuffer< common::PosCol >( "bufferVertices", 0u, 1u );
		auto meshlets = writer.declArrayStorageBuffer< mesh::Meshlet >( "bufferMeshlets", 1u, 1u );
		auto vertexIndices = writer.declArrayStorageBuffer< mesh::VtxIndex >( "bufferVertexIndices", 2u, 1u );
		auto primitiveIndices = writer.declArrayStorageBuffer< mesh::TriIndex >( "bufferPrimitiveIndices", 3u, 1u );
		auto meshletCullData = writer.declArrayStorageBuffer< mesh::CullData >( "bufferMeshletCullData", 4u, 1u );

		auto isVisible = writer.implementFunction< sdw::Boolean >( "isVisible"
			, [&]( mesh::CullData cullData )
			{
				auto center = writer.declLocale( "center", vec4( cullData.boundingSphere().xyz(), 1.0_f ) * world );
				auto radius = writer.declLocale( "radius", cullData.boundingSphere().w() * scale );

				for ( int i = 0; i < 6; ++i )
				{
					IF( writer, dot( center, cullPlanes[i] ) < -radius )
					{
						writer.returnStmt( sdw::Boolean{ false } );
					}
					FI;
				}

				writer.returnStmt( sdw::Boolean{ true } );
			}
			, sdw::InParam< mesh::CullData >{ writer, "cullData" } );

		// Task Shader
		writer.implementEntryPointT< mesh::PayloadT >( mesh::ThreadsPerWave, 1u, 1u
			, sdw::TaskPayloadOutEXTT< mesh::PayloadT >{ writer }
			, [&]( sdw::TaskSubgroupInEXT in
				, sdw::TaskPayloadOutEXTT< mesh::PayloadT > payload )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID.x() );
				auto baseId = writer.declLocale( "baseId", in.workGroupID.x() );
				auto meshletId = writer.declLocale( "meshletId", ( baseId * 32u + laneId ) );
				auto visible = writer.declLocale( "visible"
					, isVisible( meshletCullData[meshletId] ) );
				auto vote = writer.declLocale( "vote", subgroupBallot( visible ) );
				auto tasks = writer.declLocale( "tasks", subgroupBallotBitCount( vote ) );
				auto idxOffset = writer.declLocale( "idxOffset", subgroupBallotExclusiveBitCount( vote ) );

				// Compact visible meshlets into the export payload array
				IF( writer, visible )
				{
					payload.meshletIndices()[idxOffset] = meshletId;
				}
				FI;

				payload.dispatchMesh( tasks, 1_u, 1_u );
			} );

		// Mesh Shader
		writer.implementEntryPointT< mesh::PayloadT, common::ColourT, sdw::VoidT >( 32u, 1u, 1u
			, sdw::TaskPayloadInEXTT< mesh::PayloadT >{ writer }
			, sdw::MeshVertexListOutT< common::ColourT >{ writer, 252u }
			, sdw::TrianglesMeshEXTPrimitiveListOut{ writer, 84u }
			, [&]( sdw::MeshSubgroupInEXT in
				, sdw::TaskPayloadInEXTT< mesh::PayloadT > payload
				, sdw::MeshVertexListOutT< common::ColourT > vtxOut
				, sdw::TrianglesMeshEXTPrimitiveListOut primOut )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID.x() );
				auto meshletId = writer.declLocale( "meshletId", payload.meshletIndices()[laneId] );
				auto meshlet = writer.declLocale( "meshlet", meshlets[meshletId] );

				primOut.setMeshOutputCounts( meshlet.vertCount(), meshlet.primCount() );

				IF( writer, laneId < meshlet.primCount() )
				{
					primOut[laneId].primitiveIndex = primitiveIndices[meshlet.primOffset() + laneId].index();
				}
				FI;

				IF( writer, laneId < meshlet.vertCount() )
				{
					auto vertexIndex = writer.declLocale( "vertexIndex", vertexIndices[meshlet.vertOffset() + laneId].index() );
					auto vertex = writer.declLocale( "vertex", vertices[vertexIndex] );

					vtxOut[laneId].position = mvp * vertex.position();
					vtxOut[laneId].colour() = vertex.colour();
				}
				FI;
			} );

		// Fragment Shader
		writer.implementEntryPointT< common::ColourT, common::ColourT >( [&]( sdw::FragmentInT< common::ColourT > in
			, sdw::FragmentOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
			} );

		test::writeProgram( writer
			, testCounts, MeshEXTCompilers );
		test::validateProgram( writer
			, testCounts, MeshEXTCompilers );
		testEnd();
	}

	void taskMeshPipelineNV( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "taskMeshPipelineNV" );
		sdw::ModernGraphicsWriterNV writer{ &testCounts.allocator };

		auto ModelUbo = writer.declUniformBuffer( "ModelUbo", 1u, 0u );
		auto mvp = ModelUbo.declMember< sdw::Mat4 >( "mvp" );
		auto world = ModelUbo.declMember< sdw::Mat4 >( "world" );
		auto scale = ModelUbo.declMember< sdw::Float >( "scale" );
		auto cullPlanes = ModelUbo.declMember< sdw::Vec4 >( "cullPlanes", 6u );
		ModelUbo.end();

		auto vertices = writer.declArrayStorageBuffer< common::PosCol >( "bufferVertices", 0u, 1u );
		auto meshlets = writer.declArrayStorageBuffer< mesh::Meshlet >( "bufferMeshlets", 1u, 1u );
		auto vertexIndices = writer.declArrayStorageBuffer< mesh::VtxIndex >( "bufferVertexIndices", 2u, 1u );
		auto primitiveIndices = writer.declArrayStorageBuffer< mesh::TriIndex >( "bufferPrimitiveIndices", 3u, 1u );
		auto meshletCullData = writer.declArrayStorageBuffer< mesh::CullData >( "bufferMeshletCullData", 4u, 1u );

		auto isVisible = writer.implementFunction< sdw::Boolean >( "isVisible"
			, [&]( mesh::CullData cullData )
			{
				auto center = writer.declLocale( "center", vec4( cullData.boundingSphere().xyz(), 1.0_f ) * world );
				auto radius = writer.declLocale( "radius", cullData.boundingSphere().w() * scale );

				for ( int i = 0; i < 6; ++i )
				{
					IF( writer, dot( center, cullPlanes[i] ) < -radius )
					{
						writer.returnStmt( sdw::Boolean{ false } );
					}
					FI;
				}

				writer.returnStmt( sdw::Boolean{ true } );
			}
			, sdw::InParam< mesh::CullData >{ writer, "cullData" } );

		// Task Shader
		writer.implementEntryPointT< mesh::PayloadT >( mesh::ThreadsPerWave
			, sdw::TaskPayloadOutNVT< mesh::PayloadT >{ writer }
			, [&]( sdw::TaskSubgroupInNV in
				, sdw::TaskPayloadOutNVT< mesh::PayloadT > payload )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto baseId = writer.declLocale( "baseId", in.workGroupID );
				auto meshletId = writer.declLocale( "meshletId", ( baseId * 32u + laneId ) );
				auto visible = writer.declLocale( "visible"
					, isVisible( meshletCullData[meshletId] ) );
				auto vote = writer.declLocale( "vote", subgroupBallot( visible ) );
				auto tasks = writer.declLocale( "tasks", subgroupBallotBitCount( vote ) );
				auto idxOffset = writer.declLocale( "idxOffset", subgroupBallotExclusiveBitCount( vote ) );

				// Compact visible meshlets into the export payload array
				IF( writer, visible )
				{
					payload.meshletIndices()[idxOffset] = meshletId;
				}
				FI;

				payload.dispatchMesh( tasks );
			} );

		// Mesh Shader
		writer.implementEntryPointT< mesh::PayloadT, common::ColourT, sdw::VoidT >( 32u
			, sdw::TaskPayloadInNVT< mesh::PayloadT >{ writer }
			, sdw::MeshVertexListOutT< common::ColourT >{ writer, 252u }
			, sdw::TrianglesMeshNVPrimitiveListOut{ writer, 84u }
			, [&]( sdw::MeshSubgroupInNV in
				, sdw::TaskPayloadInNVT< mesh::PayloadT > payload
				, sdw::MeshVertexListOutT< common::ColourT > vtxOut
				, sdw::TrianglesMeshNVPrimitiveListOut primOut )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto meshletId = writer.declLocale( "meshletId", payload.meshletIndices()[laneId] );
				auto meshlet = writer.declLocale( "meshlet", meshlets[meshletId] );

				primOut.setMeshOutputCounts( meshlet.vertCount(), meshlet.primCount() );

				IF( writer, laneId < meshlet.primCount() )
				{
					primOut[laneId].primitiveIndex = primitiveIndices[meshlet.primOffset() + laneId].index();
				}
				FI;

				IF( writer, laneId < meshlet.vertCount() )
				{
					auto vertexIndex = writer.declLocale( "vertexIndex", vertexIndices[meshlet.vertOffset() + laneId].index() );
					auto vertex = writer.declLocale( "vertex", vertices[vertexIndex] );

					vtxOut[laneId].position = mvp * vertex.position();
					vtxOut[laneId].colour() = vertex.colour();
				}
				FI;
			} );

		// Fragment Shader
		writer.implementEntryPointT< common::ColourT, common::ColourT >( [&]( sdw::FragmentInT< common::ColourT > in
			, sdw::FragmentOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void taskMeshPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "taskMeshPipeline" );
		sdw::ModernGraphicsWriter writer{ &testCounts.allocator };

		auto ModelUbo = writer.declUniformBuffer( "ModelUbo", 1u, 0u );
		auto mvp = ModelUbo.declMember< sdw::Mat4 >( "mvp" );
		auto world = ModelUbo.declMember< sdw::Mat4 >( "world" );
		auto scale = ModelUbo.declMember< sdw::Float >( "scale" );
		auto cullPlanes = ModelUbo.declMember< sdw::Vec4 >( "cullPlanes", 6u );
		ModelUbo.end();

		auto vertices = writer.declArrayStorageBuffer< common::PosCol >( "bufferVertices", 0u, 1u );
		auto meshlets = writer.declArrayStorageBuffer< mesh::Meshlet >( "bufferMeshlets", 1u, 1u );
		auto vertexIndices = writer.declArrayStorageBuffer< mesh::VtxIndex >( "bufferVertexIndices", 2u, 1u );
		auto primitiveIndices = writer.declArrayStorageBuffer< mesh::TriIndex >( "bufferPrimitiveIndices", 3u, 1u );
		auto meshletCullData = writer.declArrayStorageBuffer< mesh::CullData >( "bufferMeshletCullData", 4u, 1u );

		auto isVisible = writer.implementFunction< sdw::Boolean >( "isVisible"
			, [&]( mesh::CullData cullData )
			{
				auto center = writer.declLocale( "center", vec4( cullData.boundingSphere().xyz(), 1.0_f ) * world );
				auto radius = writer.declLocale( "radius", cullData.boundingSphere().w() * scale );

				for ( int i = 0; i < 6; ++i )
				{
					IF( writer, dot( center, cullPlanes[i] ) < -radius )
					{
						writer.returnStmt( sdw::Boolean{ false } );
					}
					FI;
				}

				writer.returnStmt( sdw::Boolean{ true } );
			}
			, sdw::InParam< mesh::CullData >{ writer, "cullData" } );

		// Task Shader
		writer.implementEntryPointT< mesh::PayloadT >( SDW_MeshLocalSize( mesh::ThreadsPerWave, 1u, 1u )
			, sdw::TaskPayloadOutT< mesh::PayloadT >{ writer }
			, [&]( sdw::TaskSubgroupIn in
				, sdw::TaskPayloadOutT< mesh::PayloadT > payload )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto baseId = writer.declLocale( "baseId", in.workGroupID );
				auto meshletId = writer.declLocale( "meshletId", ( baseId * 32u + laneId ) );
				auto visible = writer.declLocale( "visible"
					, isVisible( meshletCullData[meshletId] ) );
				auto vote = writer.declLocale( "vote", subgroupBallot( visible ) );
				auto tasks = writer.declLocale( "tasks", subgroupBallotBitCount( vote ) );
				auto idxOffset = writer.declLocale( "idxOffset", subgroupBallotExclusiveBitCount( vote ) );

				// Compact visible meshlets into the export payload array
				IF( writer, visible )
				{
					payload.meshletIndices()[idxOffset] = meshletId;
				}
				FI;

				payload.dispatchMesh( SDW_MeshLocalSize( tasks, 1_u, 1_u ) );
			} );

		// Mesh Shader
		writer.implementEntryPointT< mesh::PayloadT, common::ColourT, sdw::VoidT >( SDW_MeshLocalSize( 32u, 1u, 1u )
			, sdw::TaskPayloadInT< mesh::PayloadT >{ writer }
			, sdw::MeshVertexListOutT< common::ColourT >{ writer, 252u }
			, sdw::TrianglesMeshPrimitiveListOut{ writer, 84u }
			, [&]( sdw::MeshSubgroupIn in
				, sdw::TaskPayloadInT< mesh::PayloadT > payload
				, sdw::MeshVertexListOutT< common::ColourT > vtxOut
				, sdw::TrianglesMeshPrimitiveListOut primOut )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto meshletId = writer.declLocale( "meshletId", payload.meshletIndices()[laneId] );
				auto meshlet = writer.declLocale( "meshlet", meshlets[meshletId] );

				primOut.setMeshOutputCounts( meshlet.vertCount(), meshlet.primCount() );

				IF( writer, laneId < meshlet.primCount() )
				{
					primOut[laneId].primitiveIndex = primitiveIndices[meshlet.primOffset() + laneId].index();
				}
				FI;

				IF( writer, laneId < meshlet.vertCount() )
				{
					auto vertexIndex = writer.declLocale( "vertexIndex", vertexIndices[meshlet.vertOffset() + laneId].index() );
					auto vertex = writer.declLocale( "vertex", vertices[vertexIndex] );

					vtxOut[laneId].position = mvp * vertex.position();
					vtxOut[laneId].colour() = vertex.colour();
				}
				FI;
			} );

		// Fragment Shader
		writer.implementEntryPointT< common::ColourT, common::ColourT >( [&]( sdw::FragmentInT< common::ColourT > in
			, sdw::FragmentOutT< common::ColourT > out )
			{
				out.colour() = in.colour();
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterProgram )
{
	sdwTestSuiteBegin();
	basicPipeline( testCounts );
	geometryPipeline( testCounts );
	tessellationPipeline( testCounts );
	rayTracePipeline( testCounts );
	taskMeshPipelineEXT( testCounts );
	taskMeshPipelineNV( testCounts );
	taskMeshPipeline( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterProgram )
