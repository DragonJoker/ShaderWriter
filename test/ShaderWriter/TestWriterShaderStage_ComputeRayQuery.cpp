#include "WriterCommon.hpp"

#include <ShaderWriter/BaseTypes/RayQuery.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using Compute = SDWTest;

	TEST_F( SDWTest, base )
	{
		sdwTestBegin( "base" );
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMain( 32u, [&writer]( sdw::ComputeIn const & in )
			{
				auto rayDesc = writer.declLocale< sdw::RayDesc >( "rayDesc" );
				rayDesc.origin = vec3( 0.0_f, 0.0_f, 0.0_f );
				rayDesc.direction = vec3( 0.0_f, 0.0_f, 1.0_f );
				rayDesc.tMin = 0.001_f;
				rayDesc.tMax = 1000.0_f;

				auto rayQuery = writer.declRayQuery( "q"
					, sdw::type::RayFlag::eCullNonOpaque | sdw::type::RayFlag::eSkipProceduralPrimitives | sdw::type::RayFlag::eAcceptFirstHitAndEndSearch );
				writer.declLocale( "flags", rayQuery.getRayFlags() );
				writer.declLocale( "rayOrigin", rayQuery.getWorldRayOrigin() );
				writer.declLocale( "rayDir", rayQuery.getWorldRayDirection() );
			} );
		sdwTestEnd()
	}

	TEST_F( SDWTest, simpleTriangleHitMiss )
	{
		sdwTestBegin( "simpleTriangleHitMiss" );
		sdw::ComputeWriter writer{ &testCounts.allocator };
		{
			auto as = writer.declAccelerationStructure( "as", 0u, 0u );
			auto output = writer.declStorageImg< sdw::RWImage2DR16 >( "output", 1u, 0u );

			auto parseRay = [&output, &writer]( sdw::RayQuery q, sdw::U32Vec2 const & pixel )
				{

					// Proceed() below is where behind-the-scenes traversal happens,
					// including the heaviest of any driver inlined code.
					// In this simplest of scenarios, Proceed() only needs
					// to be called once rather than a loop:
					// Based on the template specialization above,
					// traversal completion is guaranteed.
					q.proceed();

					// Examine and act on the result of the traversal.
					// Was a hit committed?
					sdwIF( writer, q.isCommittedStatusTriangle() )
					{
						output.store( i32vec2( pixel ), q.committedRayT() );
					}
					// sdw::type::CommittedStatus::eNone
					// From cullMask, sdw::type::CommittedStatus::eProceduralPrimitive can't happen.
					sdwELSE
					{
						output.store( i32vec2( pixel ), 0.0_f );
					}
						sdwFI
				};

			writer.implementMain( 32u, [&writer, &as, &parseRay]( sdw::ComputeIn const & in )
				{
					auto rayDesc = writer.declLocale< sdw::RayDesc >( "rayDesc" );
					rayDesc.origin = vec3( 0.0_f, 0.0_f, 0.0_f );
					rayDesc.direction = vec3( 0.0_f, 0.0_f, 1.0_f );
					rayDesc.tMin = 0.001_f;
					rayDesc.tMax = 1000.0_f;

					auto rayQuery = writer.declRayQuery( "q"
						, sdw::type::RayFlag::eCullNonOpaque | sdw::type::RayFlag::eSkipProceduralPrimitives | sdw::type::RayFlag::eAcceptFirstHitAndEndSearch );
					rayQuery.traceRay( as, 0u, 0xFF_u, rayDesc );
					parseRay( std::move( rayQuery ), in.globalInvocationID.xy() );
				} );
		}
		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, fullControlFlow )
	{
		sdwTestBegin( "fullControlFlow" );
		sdw::ComputeWriter writer{ &testCounts.allocator };
		{
			auto as = writer.declAccelerationStructure( "as", 0u, 0u );
			auto broken = writer.declArrayStorageBuffer< sdw::UInt >( "broken", 1u, 0u );
			auto ok = writer.declArrayStorageBuffer< sdw::UInt >( "ok", 2u, 0u );
			auto output = writer.declStorageImg< sdw::RWImage2DR16 >( "output", 3u, 0u );

			writer.implementMain( 32u, [&writer, &broken, &ok, &as, &output]( sdw::ComputeIn const & in )
				{
					auto rayDesc = writer.declLocale< sdw::RayDesc >( "rayDesc" );
					rayDesc.origin = vec3( 0.0_f, 0.0_f, 0.0_f );
					rayDesc.direction = vec3( 0.0_f, 0.0_f, 1.0_f );
					rayDesc.tMin = 0.001_f;
					rayDesc.tMax = 1000.0_f;

					auto q = writer.declRayQuery( "q", sdw::type::RayFlag::eNone );
					q.traceRay( as, 0u, 0xFF_u, rayDesc );
					sdwWHILE( writer, q.proceed() )
					{
						sdwSWITCH( writer, q.candidateType() )
						{
						sdwCASE( writer, uint32_t( sdw::type::CandidateType::eProceduralPrimitive ) )
							{
								auto tHit = writer.declLocale( "tHit", 0.0_f );

								// For procedural primitives, opacity is handled manually -
								// if an intersection is determined to not be opaque, just don't consider it
								// as a candidate.
								sdwIF( writer, ( q.getRayTMin() <= tHit ) && ( tHit <= q.committedRayT() ) )
								{
									sdwIF( writer, !q.candidateProceduralPrimitiveNonOpaque() )
									{
										q.commitProceduralPrimitiveHit( tHit );
									}
									sdwFI
								}
								sdwFI
								writer.caseBreakStmt();
							}
							sdwESAC
						sdwCASE( writer, uint32_t( sdw::type::CandidateType::eNonOpaqueTriangle ) )
							{
								sdwIF( writer, ok[q.candidateInstanceIndex() * 1000_u + q.candidatePrimitiveIndex()] != 0_u )
								{
									q.commitNonOpaqueTriangleHit();
								}
								sdwFI
								sdwIF( writer, broken[q.candidateInstanceIndex() * 1000_u + q.candidatePrimitiveIndex()] != 0_u )
								{
									// Stop traversing and next call to Proceed() will return FALSE.
									// Post-traversal results will just be based on what has been encountered so far.
									q.abort();
								}
								sdwFI
								writer.caseBreakStmt();
							}
							sdwESAC
						}
						sdwHCTIWS
					}
					sdwELIHW
					sdwSWITCH( writer, q.committedStatus() )
					{
						sdwCASE( writer, uint32_t( sdw::type::CommittedStatus::eTriangle ) )
						{
							output.store( i32vec2( in.globalInvocationID.xy() ), 0.0_f );
							writer.caseBreakStmt();
						}
						sdwESAC
					sdwCASE( writer, uint32_t( sdw::type::CommittedStatus::eProceduralPrimitive ) )
						{
							output.store( i32vec2( in.globalInvocationID.xy() ), 0.5_f );
							writer.caseBreakStmt();
						}
						sdwESAC
					sdwCASE( writer, uint32_t( sdw::type::CommittedStatus::eNone ) )
						{
							output.store( i32vec2( in.globalInvocationID.xy() ), 0.0_f );
							writer.caseBreakStmt();
						}
						sdwESAC
					}
					sdwHCTIWS
				} );
		}
		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, fullControlFlowIfs )
	{
		sdwTestBegin( "fullControlFlowIfs" );
		sdw::ComputeWriter writer{ &testCounts.allocator };
		{
			auto as = writer.declAccelerationStructure( "as", 0u, 0u );
			auto broken = writer.declArrayStorageBuffer< sdw::UInt >( "broken", 1u, 0u );
			auto ok = writer.declArrayStorageBuffer< sdw::UInt >( "ok", 2u, 0u );
			auto output = writer.declStorageImg< sdw::RWImage2DR16 >( "output", 3u, 0u );

			writer.implementMain( 32u, [&writer, &broken, &ok, &as, &output]( sdw::ComputeIn const & in )
				{
					auto rayDesc = writer.declLocale< sdw::RayDesc >( "rayDesc" );
					rayDesc.origin = vec3( 0.0_f, 0.0_f, 0.0_f );
					rayDesc.direction = vec3( 0.0_f, 0.0_f, 1.0_f );
					rayDesc.tMin = 0.001_f;
					rayDesc.tMax = 1000.0_f;

					auto q = writer.declRayQuery( "q", sdw::type::RayFlag::eNone );
					q.traceRay( as, 0u, 0xFF_u, rayDesc );
					sdwWHILE( writer, q.proceed() )
					{
						sdwIF( writer, q.isCandidateTypeProceduralPrimitive() )
						{
							auto tHit = writer.declLocale( "tHit", 0.0_f );

							// For procedural primitives, opacity is handled manually -
							// if an intersection is determined to not be opaque, just don't consider it
							// as a candidate.
							sdwIF( writer, ( q.getRayTMin() <= tHit ) && ( tHit <= q.committedRayT() ) )
							{
								sdwIF( writer, !q.candidateProceduralPrimitiveNonOpaque() )
								{
									q.commitProceduralPrimitiveHit( tHit );
								}
								sdwFI
							}
							sdwFI
						}
						sdwELSEIF( q.isCandidateTypeNonOpaqueTriangle() )
						{
							writer.declLocale( "t", q.candidateTriangleRayT() );
							writer.declLocale( "bary", q.candidateTriangleBarycentrics() );
							writer.declLocale( "front", q.candidateTriangleFrontFace() );
							writer.declLocale( "id", q.candidateInstanceID() );
							writer.declLocale( "contrib", q.candidateInstanceContributionToHitGroupIndex() );
							writer.declLocale( "geom", q.candidateGeometryIndex() );
							writer.declLocale( "objRayOrig", q.candidateObjectRayOrigin() );
							writer.declLocale( "objRayDir", q.candidateObjectRayDirection() );
							writer.declLocale( "objToWorld", q.candidateObjectToWorld() );
							writer.declLocale( "worldToObj", q.candidateWorldToObject() );
							auto prim = writer.declLocale( "prim", q.candidatePrimitiveIndex() );
							auto index = writer.declLocale( "index", q.candidateInstanceIndex() );

							sdwIF( writer, ok[index * 1000_u + prim] != 0_u )
							{
								q.commitNonOpaqueTriangleHit();
							}
							sdwFI
							sdwIF( writer, broken[index * 1000_u + prim] != 0_u )
							{
								// Stop traversing and next call to Proceed() will return FALSE.
								// Post-traversal results will just be based on what has been encountered so far.
								q.abort();
							}
							sdwFI
							writer.caseBreakStmt();
						}
						sdwFI
					}
					sdwELIHW
					sdwIF( writer, q.isCommittedStatusTriangle() )
					{
						writer.declLocale( "t", q.committedRayT() );
						writer.declLocale( "bary", q.committedTriangleBarycentrics() );
						writer.declLocale( "front", q.committedTriangleFrontFace() );
						writer.declLocale( "id", q.committedInstanceID() );
						writer.declLocale( "contrib", q.committedInstanceContributionToHitGroupIndex() );
						writer.declLocale( "geom", q.committedGeometryIndex() );
						writer.declLocale( "objRayOrig", q.committedObjectRayOrigin() );
						writer.declLocale( "objRayDir", q.committedObjectRayDirection() );
						writer.declLocale( "objToWorld", q.committedObjectToWorld() );
						writer.declLocale( "worldToObj", q.committedWorldToObject() );
						writer.declLocale( "prim", q.committedPrimitiveIndex() );
						writer.declLocale( "index", q.committedInstanceIndex() );

						output.store( i32vec2( in.globalInvocationID.xy() ), 0.0_f );
					}
					sdwELSEIF( q.isCommittedStatusProceduralPrimitive() )
					{
						output.store( i32vec2( in.globalInvocationID.xy() ), 0.5_f );
					}
					sdwELSEIF( q.isCommittedStatusNone() )
					{
						output.store( i32vec2( in.globalInvocationID.xy() ), 0.0_f );
					}
					sdwFI
				} );
		}
		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
