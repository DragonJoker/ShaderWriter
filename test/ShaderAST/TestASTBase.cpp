#include "Common.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Shader.hpp>
#include <ShaderAST/ShaderBuilder.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#include <set>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;
	using ::toString;

	std::string toString( EntryPoint v )
	{
		return getName( v );
	}

	std::string toString( ShaderStage v )
	{
		switch ( v )
		{
		case ShaderStage::eVertex:
			return "Vertex";
		case ShaderStage::eTessellationControl:
			return "TessellationControl";
		case ShaderStage::eTessellationEvaluation:
			return "TessellationEvaluation";
		case ShaderStage::eGeometry:
			return "Geometry";
		case ShaderStage::eFragment:
			return "Fragment";
		case ShaderStage::eCompute:
			return "Compute";
		case ShaderStage::eTaskNV:
			return "TaskNV";
		case ShaderStage::eMeshNV:
			return "MeshNV";
		case ShaderStage::eTask:
			return "Task";
		case ShaderStage::eMesh:
			return "Mesh";
		case ShaderStage::eRayGeneration:
			return "RayGeneration";
		case ShaderStage::eRayAnyHit:
			return "RayAnyHit";
		case ShaderStage::eRayClosestHit:
			return "RayClosestHit";
		case ShaderStage::eRayMiss:
			return "RayMiss";
		case ShaderStage::eRayIntersection:
			return "RayIntersection";
		case ShaderStage::eCallable:
			return "Callable";
		case ShaderStage::eTraditionalGraphics:
			return "TraditionalGraphics";
		case ShaderStage::eModernGraphicsNV:
			return "ModernGraphicsNV";
		case ShaderStage::eModernGraphicsEXT:
			return "ModernGraphicsEXT";
		case ShaderStage::eRayTrace:
			return "RayTrace";
		default:
			return "Undefined";
		}
	}

	void testMemorySemantics( test::TestCounts & testCounts )
	{
		astTestBegin( "testMemorySemantics" );
		{
			type::MemorySemantics semantics{};
			astCheck( uint32_t( semantics ) == 0u )
			semantics = semantics | type::MemorySemanticsMask::eAcquire;
			astCheck( semantics == type::MemorySemanticsMask::eAcquire )
			semantics = semantics & type::MemorySemanticsMask( ~uint32_t( type::MemorySemanticsMask::eAcquire ) );
			astCheck( uint32_t( semantics ) == 0u )
			semantics = type::MemorySemanticsMask::eAcquire | semantics;
			astCheck( semantics == type::MemorySemanticsMask::eAcquire )
			semantics = type::MemorySemanticsMask::eAcquire & semantics;
			astCheck( type::MemorySemanticsMask::eAcquire == semantics )
			astCheck( type::MemorySemanticsMask::eAcquire == type::MemorySemanticsMask::eAcquire )
			auto rhs = semantics;
			astCheck( semantics == rhs )
		}
		{
			type::MemorySemantics semantics{ type::MemorySemanticsMask::eAcquire };
			astCheck( uint32_t( semantics ) == uint32_t( type::MemorySemanticsMask::eAcquire ) )
		}
		{
			type::MemorySemantics semantics{ uint32_t( type::MemorySemanticsMask::eAcquire ) };
			astCheck( uint32_t( semantics ) == uint32_t( type::MemorySemanticsMask::eAcquire ) )
		}
		{
			auto semantics{ type::MemorySemanticsMask::eAcquire | type::MemorySemanticsMask::eAcquireRelease };
			astCheck( ( uint32_t( semantics ) & uint32_t( type::MemorySemanticsMask::eAcquire ) ) == uint32_t( type::MemorySemanticsMask::eAcquire ) )
			astCheck( ( uint32_t( semantics ) & uint32_t( type::MemorySemanticsMask::eAcquireRelease ) ) == uint32_t( type::MemorySemanticsMask::eAcquireRelease ) )
			semantics = type::MemorySemanticsMask::eAcquire & type::MemorySemanticsMask::eAcquireRelease;
			astCheck( uint32_t( semantics ) == 0u )
		}
		{
			type::MemorySemantics lhs{ type::MemorySemanticsMask::eAcquire };
			type::MemorySemantics rhs{ type::MemorySemanticsMask::eAcquireRelease };
			auto semantics{ lhs | rhs };
			astCheck( ( uint32_t( semantics ) & uint32_t( type::MemorySemanticsMask::eAcquire ) ) == uint32_t( type::MemorySemanticsMask::eAcquire ) )
			astCheck( ( uint32_t( semantics ) & uint32_t( type::MemorySemanticsMask::eAcquireRelease ) ) == uint32_t( type::MemorySemanticsMask::eAcquireRelease ) )
			semantics = lhs & rhs;
			astCheck( uint32_t( semantics ) == 0u )
		}
		astTestEnd()
	}

	void testShaderStages( test::TestCounts & testCounts )
	{
		astTestBegin( "testShaderStages" );

		astCheck( isRasterizerStage( ShaderStage::eVertex ) )
		astCheck( isRasterizerStage( ShaderStage::eTessellationControl ) )
		astCheck( isRasterizerStage( ShaderStage::eTessellationEvaluation ) )
		astCheck( isRasterizerStage( ShaderStage::eGeometry ) )
		astCheck( isRasterizerStage( ShaderStage::eFragment ) )
		astCheck( isRasterizerStage( ShaderStage::eTaskNV ) )
		astCheck( isRasterizerStage( ShaderStage::eMeshNV ) )
		astCheck( isRasterizerStage( ShaderStage::eTask ) )
		astCheck( isRasterizerStage( ShaderStage::eMesh ) )
		astCheck( !isRasterizerStage( ShaderStage::eCompute ) )
		astCheck( !isRasterizerStage( ShaderStage::eRayGeneration ) )
		astCheck( !isRasterizerStage( ShaderStage::eRayAnyHit ) )
		astCheck( !isRasterizerStage( ShaderStage::eRayClosestHit ) )
		astCheck( !isRasterizerStage( ShaderStage::eRayMiss ) )
		astCheck( !isRasterizerStage( ShaderStage::eRayIntersection ) )
		astCheck( !isRasterizerStage( ShaderStage::eCallable ) )
		astCheck( !isRasterizerStage( ShaderStage::eTraditionalGraphics ) )
		astCheck( !isRasterizerStage( ShaderStage::eModernGraphicsNV ) )
		astCheck( !isRasterizerStage( ShaderStage::eModernGraphicsEXT ) )
		astCheck( !isRasterizerStage( ShaderStage::eRayTrace ) )

		astCheck( !isComputeStage( ShaderStage::eVertex ) )
		astCheck( !isComputeStage( ShaderStage::eTessellationControl ) )
		astCheck( !isComputeStage( ShaderStage::eTessellationEvaluation ) )
		astCheck( !isComputeStage( ShaderStage::eGeometry ) )
		astCheck( !isComputeStage( ShaderStage::eFragment ) )
		astCheck( !isComputeStage( ShaderStage::eTaskNV ) )
		astCheck( !isComputeStage( ShaderStage::eMeshNV ) )
		astCheck( !isComputeStage( ShaderStage::eTask ) )
		astCheck( !isComputeStage( ShaderStage::eMesh ) )
		astCheck( isComputeStage( ShaderStage::eCompute ) )
		astCheck( !isComputeStage( ShaderStage::eRayGeneration ) )
		astCheck( !isComputeStage( ShaderStage::eRayAnyHit ) )
		astCheck( !isComputeStage( ShaderStage::eRayClosestHit ) )
		astCheck( !isComputeStage( ShaderStage::eRayMiss ) )
		astCheck( !isComputeStage( ShaderStage::eRayIntersection ) )
		astCheck( !isComputeStage( ShaderStage::eCallable ) )
		astCheck( !isComputeStage( ShaderStage::eTraditionalGraphics ) )
		astCheck( !isComputeStage( ShaderStage::eModernGraphicsNV ) )
		astCheck( !isComputeStage( ShaderStage::eModernGraphicsEXT ) )
		astCheck( !isComputeStage( ShaderStage::eRayTrace ) )

		astCheck( !isRayTraceStage( ShaderStage::eVertex ) )
		astCheck( !isRayTraceStage( ShaderStage::eTessellationControl ) )
		astCheck( !isRayTraceStage( ShaderStage::eTessellationEvaluation ) )
		astCheck( !isRayTraceStage( ShaderStage::eGeometry ) )
		astCheck( !isRayTraceStage( ShaderStage::eFragment ) )
		astCheck( !isRayTraceStage( ShaderStage::eTaskNV ) )
		astCheck( !isRayTraceStage( ShaderStage::eMeshNV ) )
		astCheck( !isRayTraceStage( ShaderStage::eTask ) )
		astCheck( !isRayTraceStage( ShaderStage::eMesh ) )
		astCheck( !isRayTraceStage( ShaderStage::eCompute ) )
		astCheck( isRayTraceStage( ShaderStage::eRayGeneration ) )
		astCheck( isRayTraceStage( ShaderStage::eRayAnyHit ) )
		astCheck( isRayTraceStage( ShaderStage::eRayClosestHit ) )
		astCheck( isRayTraceStage( ShaderStage::eRayMiss ) )
		astCheck( isRayTraceStage( ShaderStage::eRayIntersection ) )
		astCheck( isRayTraceStage( ShaderStage::eCallable ) )
		astCheck( !isRayTraceStage( ShaderStage::eTraditionalGraphics ) )
		astCheck( !isRayTraceStage( ShaderStage::eModernGraphicsNV ) )
		astCheck( !isRayTraceStage( ShaderStage::eModernGraphicsEXT ) )
		astCheck( !isRayTraceStage( ShaderStage::eRayTrace ) )

		astCheck( !isMeshStage( ShaderStage::eVertex ) )
		astCheck( !isMeshStage( ShaderStage::eTessellationControl ) )
		astCheck( !isMeshStage( ShaderStage::eTessellationEvaluation ) )
		astCheck( !isMeshStage( ShaderStage::eGeometry ) )
		astCheck( !isMeshStage( ShaderStage::eFragment ) )
		astCheck( isMeshStage( ShaderStage::eTaskNV ) )
		astCheck( isMeshStage( ShaderStage::eMeshNV ) )
		astCheck( isMeshStage( ShaderStage::eTask ) )
		astCheck( isMeshStage( ShaderStage::eMesh ) )
		astCheck( !isMeshStage( ShaderStage::eCompute ) )
		astCheck( !isMeshStage( ShaderStage::eRayGeneration ) )
		astCheck( !isMeshStage( ShaderStage::eRayAnyHit ) )
		astCheck( !isMeshStage( ShaderStage::eRayClosestHit ) )
		astCheck( !isMeshStage( ShaderStage::eRayMiss ) )
		astCheck( !isMeshStage( ShaderStage::eRayIntersection ) )
		astCheck( !isMeshStage( ShaderStage::eCallable ) )
		astCheck( !isMeshStage( ShaderStage::eTraditionalGraphics ) )
		astCheck( !isMeshStage( ShaderStage::eModernGraphicsNV ) )
		astCheck( !isMeshStage( ShaderStage::eModernGraphicsEXT ) )
		astCheck( !isMeshStage( ShaderStage::eRayTrace ) )

		astCheck( !isMeshNVStage( ShaderStage::eVertex ) )
		astCheck( !isMeshNVStage( ShaderStage::eTessellationControl ) )
		astCheck( !isMeshNVStage( ShaderStage::eTessellationEvaluation ) )
		astCheck( !isMeshNVStage( ShaderStage::eGeometry ) )
		astCheck( !isMeshNVStage( ShaderStage::eFragment ) )
		astCheck( isMeshNVStage( ShaderStage::eTaskNV ) )
		astCheck( isMeshNVStage( ShaderStage::eMeshNV ) )
		astCheck( !isMeshNVStage( ShaderStage::eTask ) )
		astCheck( !isMeshNVStage( ShaderStage::eMesh ) )
		astCheck( !isMeshNVStage( ShaderStage::eCompute ) )
		astCheck( !isMeshNVStage( ShaderStage::eRayGeneration ) )
		astCheck( !isMeshNVStage( ShaderStage::eRayAnyHit ) )
		astCheck( !isMeshNVStage( ShaderStage::eRayClosestHit ) )
		astCheck( !isMeshNVStage( ShaderStage::eRayMiss ) )
		astCheck( !isMeshNVStage( ShaderStage::eRayIntersection ) )
		astCheck( !isMeshNVStage( ShaderStage::eCallable ) )
		astCheck( !isMeshNVStage( ShaderStage::eTraditionalGraphics ) )
		astCheck( !isMeshNVStage( ShaderStage::eModernGraphicsNV ) )
		astCheck( !isMeshNVStage( ShaderStage::eModernGraphicsEXT ) )
		astCheck( !isMeshNVStage( ShaderStage::eRayTrace ) )

		astTestEnd()
	}

	void testEntryPoints( test::TestCounts & testCounts )
	{
		astTestBegin( "testEntryPoints" );

		astCheck( getName( EntryPoint::eNone ).empty() )
#if SDAST_ExceptAssert
		astCheckThrow( getName( EntryPoint( 28 ) ) )
		astCheckThrow( getShaderStage( EntryPoint( 28 ) ) )
#endif
		astCheckEqual( getEntryPointType( ShaderStage::eVertex ), EntryPoint::eVertex )
		astCheckEqual( getEntryPointType( ShaderStage::eTessellationControl ), EntryPoint::eTessellationControl )
		astCheckEqual( getEntryPointType( ShaderStage::eTessellationEvaluation ), EntryPoint::eTessellationEvaluation )
		astCheckEqual( getEntryPointType( ShaderStage::eGeometry ), EntryPoint::eGeometry )
		astCheckEqual( getEntryPointType( ShaderStage::eFragment ), EntryPoint::eFragment )
		astCheckEqual( getEntryPointType( ShaderStage::eTaskNV ), EntryPoint::eTaskNV )
		astCheckEqual( getEntryPointType( ShaderStage::eMeshNV ), EntryPoint::eMeshNV )
		astCheckEqual( getEntryPointType( ShaderStage::eTask ), EntryPoint::eTask )
		astCheckEqual( getEntryPointType( ShaderStage::eMesh ), EntryPoint::eMesh )
		astCheckEqual( getEntryPointType( ShaderStage::eCompute ), EntryPoint::eCompute )
		astCheckEqual( getEntryPointType( ShaderStage::eRayGeneration ), EntryPoint::eRayGeneration )
		astCheckEqual( getEntryPointType( ShaderStage::eRayAnyHit ), EntryPoint::eRayAnyHit )
		astCheckEqual( getEntryPointType( ShaderStage::eRayClosestHit ), EntryPoint::eRayClosestHit )
		astCheckEqual( getEntryPointType( ShaderStage::eRayMiss ), EntryPoint::eRayMiss )
		astCheckEqual( getEntryPointType( ShaderStage::eRayIntersection ), EntryPoint::eRayIntersection )
		astCheckEqual( getEntryPointType( ShaderStage::eCallable ), EntryPoint::eCallable )
#if SDAST_ExceptAssert
		astCheckThrow( getEntryPointType( ShaderStage::eTraditionalGraphics ) )
		astCheckThrow( getEntryPointType( ShaderStage::eModernGraphicsNV ) )
		astCheckThrow( getEntryPointType( ShaderStage::eModernGraphicsEXT ) )
		astCheckThrow( getEntryPointType( ShaderStage::eRayTrace ) )
#endif
		astCheckEqual( getShaderStage( EntryPoint::eVertex ), ShaderStage::eVertex )
		astCheckEqual( getShaderStage( EntryPoint::eTessellationControl ), ShaderStage::eTessellationControl )
		astCheckEqual( getShaderStage( EntryPoint::eTessellationEvaluation ), ShaderStage::eTessellationEvaluation )
		astCheckEqual( getShaderStage( EntryPoint::eGeometry ), ShaderStage::eGeometry )
		astCheckEqual( getShaderStage( EntryPoint::eFragment ), ShaderStage::eFragment )
		astCheckEqual( getShaderStage( EntryPoint::eTaskNV ), ShaderStage::eTaskNV )
		astCheckEqual( getShaderStage( EntryPoint::eMeshNV ), ShaderStage::eMeshNV )
		astCheckEqual( getShaderStage( EntryPoint::eTask ), ShaderStage::eTask )
		astCheckEqual( getShaderStage( EntryPoint::eMesh ), ShaderStage::eMesh )
		astCheckEqual( getShaderStage( EntryPoint::eCompute ), ShaderStage::eCompute )
		astCheckEqual( getShaderStage( EntryPoint::eRayGeneration ), ShaderStage::eRayGeneration )
		astCheckEqual( getShaderStage( EntryPoint::eRayAnyHit ), ShaderStage::eRayAnyHit )
		astCheckEqual( getShaderStage( EntryPoint::eRayClosestHit ), ShaderStage::eRayClosestHit )
		astCheckEqual( getShaderStage( EntryPoint::eRayMiss ), ShaderStage::eRayMiss )
		astCheckEqual( getShaderStage( EntryPoint::eRayIntersection ), ShaderStage::eRayIntersection )
		astCheckEqual( getShaderStage( EntryPoint::eCallable ), ShaderStage::eCallable )

		astTestEnd()
	}

	void testBuiltins( test::TestCounts & testCounts )
	{
		astTestBegin( "testBuiltins" );

		astCheck( !isPerVertex( Builtin::eNone, ShaderStage::eVertex ) )
		astCheck( isPerVertex( Builtin::ePosition, ShaderStage::eVertex ) )
		astCheck( isPerVertex( Builtin::ePointSize, ShaderStage::eVertex ) )
		astCheck( isPerVertex( Builtin::eClipDistance, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eClipDistance, ShaderStage::eFragment ) )
		astCheck( isPerVertex( Builtin::eCullDistance, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePrimitiveID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePrimitiveIDIn, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eInvocationID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eLayer, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eViewportIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eTessLevelOuter, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eTessLevelInner, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eTessCoord, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePatchVertices, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePatchVerticesIn, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eFragCoord, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePointCoord, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eFrontFacing, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSampleID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSamplePosition, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSampleMask, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSampleMaskIn, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eFragDepth, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eHelperInvocation, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eNumWorkGroups, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eWorkGroupSize, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eWorkGroupID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eLocalInvocationID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eGlobalInvocationID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eLocalInvocationIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eWorkDim, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eGlobalSize, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eEnqueuedWorkgroupSize, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eGlobalLinearID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupSize, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupMaxSize, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eNumSubgroups, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eNumEnqueuedSubgroups, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupLocalInvocationID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eVertexIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eInstanceIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eInstanceID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupEqMask, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupGeMask, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupGtMask, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupLeMask, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSubgroupLtMask, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaseVertex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaseInstance, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eDrawIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eDeviceIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eViewIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaryCoordNoPerspAMD, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaryCoordNoPerspCentroidAMD, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaryCoordNoPerspSampleAMD, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaryCoordSmoothAMD, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaryCoordSmoothCentroidAMD, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaryCoordSmoothSampleAMD, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eBaryCoordPullModelAMD, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eFragStencilRefEXT, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eViewportMaskNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSecondaryPositionNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eSecondaryViewportMaskNV, ShaderStage::eVertex ) )
		astCheck( isPerVertex( Builtin::ePositionPerViewNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eViewportMaskPerViewNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePrimitiveIndicesNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePrimitiveCountNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eTaskCountNV, ShaderStage::eVertex ) )
		astCheck( isPerVertex( Builtin::eClipDistancePerViewNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eClipDistancePerViewNV, ShaderStage::eFragment ) )
		astCheck( isPerVertex( Builtin::eCullDistancePerViewNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eLayerPerViewNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eMeshViewCountNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eMeshViewIndicesNV, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eLaunchID, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eLaunchSize, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eInstanceCustomIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eGeometryIndex, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eWorldRayOrigin, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eWorldRayDirection, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eObjectRayOrigin, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eObjectRayDirection, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eRayTmin, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eRayTmax, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eIncomingRayFlags, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eHitKind, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eObjectToWorld, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eWorldToObject, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePrimitivePointIndices, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePrimitiveLineIndices, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::ePrimitiveTriangleIndices, ShaderStage::eVertex ) )
		astCheck( !isPerVertex( Builtin::eCullPrimitive, ShaderStage::eVertex ) )

		astCheck( !isPerPrimitive( Builtin::eNone, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePosition, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePointSize, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eClipDistance, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eCullDistance, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::ePrimitiveID, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::ePrimitiveID, ShaderStage::eMeshNV ) )
		astCheck( !isPerPrimitive( Builtin::ePrimitiveID, ShaderStage::eVertex ) )
		astCheck( !isPerPrimitive( Builtin::ePrimitiveIDIn, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eInvocationID, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eLayer, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eLayer, ShaderStage::eMeshNV ) )
		astCheck( !isPerPrimitive( Builtin::eLayer, ShaderStage::eVertex ) )
		astCheck( isPerPrimitive( Builtin::eViewportIndex, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eViewportIndex, ShaderStage::eMeshNV ) )
		astCheck( !isPerPrimitive( Builtin::eViewportIndex, ShaderStage::eVertex ) )
		astCheck( !isPerPrimitive( Builtin::eTessLevelOuter, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eTessLevelInner, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eTessCoord, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePatchVertices, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePatchVerticesIn, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eFragCoord, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePointCoord, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eFrontFacing, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSampleID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSamplePosition, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSampleMask, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSampleMaskIn, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eFragDepth, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eHelperInvocation, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eNumWorkGroups, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eWorkGroupSize, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eWorkGroupID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eLocalInvocationID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eGlobalInvocationID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eLocalInvocationIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eWorkDim, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eGlobalSize, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eEnqueuedWorkgroupSize, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eGlobalLinearID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupSize, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupMaxSize, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eNumSubgroups, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eNumEnqueuedSubgroups, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupLocalInvocationID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eVertexIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eInstanceIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eInstanceID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupEqMask, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupGeMask, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupGtMask, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupLeMask, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSubgroupLtMask, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaseVertex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaseInstance, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eDrawIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eDeviceIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eViewIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaryCoordNoPerspAMD, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaryCoordNoPerspCentroidAMD, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaryCoordNoPerspSampleAMD, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaryCoordSmoothAMD, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaryCoordSmoothCentroidAMD, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaryCoordSmoothSampleAMD, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eBaryCoordPullModelAMD, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eFragStencilRefEXT, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eViewportMaskNV, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eViewportMaskNV, ShaderStage::eMeshNV ) )
		astCheck( !isPerPrimitive( Builtin::eViewportMaskNV, ShaderStage::eVertex ) )
		astCheck( !isPerPrimitive( Builtin::eSecondaryPositionNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eSecondaryViewportMaskNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePositionPerViewNV, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eViewportMaskPerViewNV, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eViewportMaskPerViewNV, ShaderStage::eMeshNV ) )
		astCheck( !isPerPrimitive( Builtin::eViewportMaskPerViewNV, ShaderStage::eVertex ) )
		astCheck( !isPerPrimitive( Builtin::ePrimitiveIndicesNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePrimitiveCountNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eTaskCountNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eClipDistancePerViewNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eCullDistancePerViewNV, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eLayerPerViewNV, ShaderStage::eMesh ) )
		astCheck( isPerPrimitive( Builtin::eLayerPerViewNV, ShaderStage::eMeshNV ) )
		astCheck( !isPerPrimitive( Builtin::eLayerPerViewNV, ShaderStage::eVertex ) )
		astCheck( !isPerPrimitive( Builtin::eMeshViewCountNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eMeshViewIndicesNV, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eLaunchID, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eLaunchSize, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eInstanceCustomIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eGeometryIndex, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eWorldRayOrigin, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eWorldRayDirection, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eObjectRayOrigin, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eObjectRayDirection, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eRayTmin, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eRayTmax, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eIncomingRayFlags, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eHitKind, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eObjectToWorld, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eWorldToObject, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePrimitivePointIndices, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePrimitiveLineIndices, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::ePrimitiveTriangleIndices, ShaderStage::eMesh ) )
		astCheck( !isPerPrimitive( Builtin::eCullPrimitive, ShaderStage::eMesh ) )

		astCheckNoThrow( getName( Builtin::eNone ) )
		astCheckNoThrow( getName( Builtin::ePosition ) )
		astCheckNoThrow( getName( Builtin::ePointSize ) )
		astCheckNoThrow( getName( Builtin::eClipDistance ) )
		astCheckNoThrow( getName( Builtin::eCullDistance ) )
		astCheckNoThrow( getName( Builtin::ePrimitiveID ) )
		astCheckNoThrow( getName( Builtin::ePrimitiveIDIn ) )
		astCheckNoThrow( getName( Builtin::eInvocationID ) )
		astCheckNoThrow( getName( Builtin::eLayer ) )
		astCheckNoThrow( getName( Builtin::eViewportIndex ) )
		astCheckNoThrow( getName( Builtin::eTessLevelOuter ) )
		astCheckNoThrow( getName( Builtin::eTessLevelInner ) )
		astCheckNoThrow( getName( Builtin::eTessCoord ) )
		astCheckNoThrow( getName( Builtin::ePatchVertices ) )
		astCheckNoThrow( getName( Builtin::ePatchVerticesIn ) )
		astCheckNoThrow( getName( Builtin::eFragCoord ) )
		astCheckNoThrow( getName( Builtin::ePointCoord ) )
		astCheckNoThrow( getName( Builtin::eFrontFacing ) )
		astCheckNoThrow( getName( Builtin::eSampleID ) )
		astCheckNoThrow( getName( Builtin::eSamplePosition ) )
		astCheckNoThrow( getName( Builtin::eSampleMask ) )
		astCheckNoThrow( getName( Builtin::eSampleMaskIn ) )
		astCheckNoThrow( getName( Builtin::eFragDepth ) )
		astCheckNoThrow( getName( Builtin::eHelperInvocation ) )
		astCheckNoThrow( getName( Builtin::eNumWorkGroups ) )
		astCheckNoThrow( getName( Builtin::eWorkGroupSize ) )
		astCheckNoThrow( getName( Builtin::eWorkGroupID ) )
		astCheckNoThrow( getName( Builtin::eLocalInvocationID ) )
		astCheckNoThrow( getName( Builtin::eGlobalInvocationID ) )
		astCheckNoThrow( getName( Builtin::eLocalInvocationIndex ) )
		astCheckNoThrow( getName( Builtin::eWorkDim ) )
		astCheckNoThrow( getName( Builtin::eGlobalSize ) )
		astCheckNoThrow( getName( Builtin::eEnqueuedWorkgroupSize ) )
		astCheckNoThrow( getName( Builtin::eGlobalLinearID ) )
		astCheckNoThrow( getName( Builtin::eSubgroupSize ) )
		astCheckNoThrow( getName( Builtin::eSubgroupMaxSize ) )
		astCheckNoThrow( getName( Builtin::eNumSubgroups ) )
		astCheckNoThrow( getName( Builtin::eNumEnqueuedSubgroups ) )
		astCheckNoThrow( getName( Builtin::eSubgroupID ) )
		astCheckNoThrow( getName( Builtin::eSubgroupLocalInvocationID ) )
		astCheckNoThrow( getName( Builtin::eVertexIndex ) )
		astCheckNoThrow( getName( Builtin::eInstanceIndex ) )
		astCheckNoThrow( getName( Builtin::eInstanceID ) )
		astCheckNoThrow( getName( Builtin::eSubgroupEqMask ) )
		astCheckNoThrow( getName( Builtin::eSubgroupGeMask ) )
		astCheckNoThrow( getName( Builtin::eSubgroupGtMask ) )
		astCheckNoThrow( getName( Builtin::eSubgroupLeMask ) )
		astCheckNoThrow( getName( Builtin::eSubgroupLtMask ) )
		astCheckNoThrow( getName( Builtin::eBaseVertex ) )
		astCheckNoThrow( getName( Builtin::eBaseInstance ) )
		astCheckNoThrow( getName( Builtin::eDrawIndex ) )
		astCheckNoThrow( getName( Builtin::eDeviceIndex ) )
		astCheckNoThrow( getName( Builtin::eViewIndex ) )
		astCheckNoThrow( getName( Builtin::eBaryCoordNoPerspAMD ) )
		astCheckNoThrow( getName( Builtin::eBaryCoordNoPerspCentroidAMD ) )
		astCheckNoThrow( getName( Builtin::eBaryCoordNoPerspSampleAMD ) )
		astCheckNoThrow( getName( Builtin::eBaryCoordSmoothAMD ) )
		astCheckNoThrow( getName( Builtin::eBaryCoordSmoothCentroidAMD ) )
		astCheckNoThrow( getName( Builtin::eBaryCoordSmoothSampleAMD ) )
		astCheckNoThrow( getName( Builtin::eBaryCoordPullModelAMD ) )
		astCheckNoThrow( getName( Builtin::eFragStencilRefEXT ) )
		astCheckNoThrow( getName( Builtin::eViewportMaskNV ) )
		astCheckNoThrow( getName( Builtin::eSecondaryPositionNV ) )
		astCheckNoThrow( getName( Builtin::eSecondaryViewportMaskNV ) )
		astCheckNoThrow( getName( Builtin::ePositionPerViewNV ) )
		astCheckNoThrow( getName( Builtin::eViewportMaskPerViewNV ) )
		astCheckNoThrow( getName( Builtin::ePrimitiveIndicesNV ) )
		astCheckNoThrow( getName( Builtin::ePrimitiveCountNV ) )
		astCheckNoThrow( getName( Builtin::eTaskCountNV ) )
		astCheckNoThrow( getName( Builtin::eClipDistancePerViewNV ) )
		astCheckNoThrow( getName( Builtin::eCullDistancePerViewNV ) )
		astCheckNoThrow( getName( Builtin::eLayerPerViewNV ) )
		astCheckNoThrow( getName( Builtin::eMeshViewCountNV ) )
		astCheckNoThrow( getName( Builtin::eMeshViewIndicesNV ) )
		astCheckNoThrow( getName( Builtin::eLaunchID ) )
		astCheckNoThrow( getName( Builtin::eLaunchSize ) )
		astCheckNoThrow( getName( Builtin::eInstanceCustomIndex ) )
		astCheckNoThrow( getName( Builtin::eGeometryIndex ) )
		astCheckNoThrow( getName( Builtin::eWorldRayOrigin ) )
		astCheckNoThrow( getName( Builtin::eWorldRayDirection ) )
		astCheckNoThrow( getName( Builtin::eObjectRayOrigin ) )
		astCheckNoThrow( getName( Builtin::eObjectRayDirection ) )
		astCheckNoThrow( getName( Builtin::eRayTmin ) )
		astCheckNoThrow( getName( Builtin::eRayTmax ) )
		astCheckNoThrow( getName( Builtin::eIncomingRayFlags ) )
		astCheckNoThrow( getName( Builtin::eHitKind ) )
		astCheckNoThrow( getName( Builtin::eObjectToWorld ) )
		astCheckNoThrow( getName( Builtin::eWorldToObject ) )
		astCheckNoThrow( getName( Builtin::ePrimitivePointIndices ) )
		astCheckNoThrow( getName( Builtin::ePrimitiveLineIndices ) )
		astCheckNoThrow( getName( Builtin::ePrimitiveTriangleIndices ) )
		astCheckNoThrow( getName( Builtin::eCullPrimitive ) )
#if SDAST_ExceptAssert
		astCheckThrow( getName( Builtin( 1024 ) ) )
#endif

		astTestEnd()
	}

	void testAllocator( test::TestCounts & testCounts )
	{
		astTestBegin( "testAllocator" );
		if ( astOn( "Allocation block move" ) )
		{
			ShaderAllocator alloc{ AllocationMode::eNone };
			{
				auto block = alloc.getBlock();
				ShaderAllocatorBlockPtr other{ std::make_unique< ShaderAllocatorBlock >( std::move( *block.release() ) ) };
			}
			{
				auto block = alloc.getBlock();
				auto other = alloc.getBlock();
				*other = std::move( *block );
			}
		}
		if ( astOn( "Direct mode allocator" ) )
		{
			if ( astOn( "No Allocation" ) )
			{
				ShaderAllocator alloc{ AllocationMode::eNone };
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
			}
			if ( astOn( "Single 4 bytes allocation" ) )
			{
				ShaderAllocator alloc{ AllocationMode::eNone };
				auto mem = alloc.allocate( 4u, 1u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
				alloc.deallocate( mem, 4u, 1u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
			}
			if ( astOn( "Multiple count 4 bytes allocations" ) )
			{
				ShaderAllocator alloc{ AllocationMode::eNone };
				auto mem = alloc.allocate( 4u, 4u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
				alloc.deallocate( mem, 4u, 16u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
			}
			if ( astOn( "Multiple Multiple count 4 bytes allocations" ) )
			{
				ShaderAllocator alloc{ AllocationMode::eNone };
				auto mem1 = alloc.allocate( 4u, 4u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
				auto mem2 = alloc.allocate( 4u, 4u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
				auto mem3 = alloc.allocate( 4u, 4u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
				alloc.deallocate( mem3, 4u, 16u );
				alloc.deallocate( mem2, 4u, 16u );
				alloc.deallocate( mem1, 4u, 16u );
				astCheckEqual( alloc.getCursor().index, 0u )
				astCheckEqual( alloc.getCursor().offset, 0u )
			}
		}
		if ( astOn( "Incremental allocator" ) )
		{
			if ( astOn( "Without allocation blocks" ) )
			{
				if ( astOn( "No Allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 0u )
				}
				if ( astOn( "Unique Single count 4 bytes allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					auto mem = alloc.allocate( 4u, 1u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 4u )
					alloc.deallocate( mem, 4u, 1u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 4u )
				}
				if ( astOn( "Unique Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					auto mem = alloc.allocate( 4u, 4u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 16u )
					alloc.deallocate( mem, 4u, 4u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 16u )
				}
				if ( astOn( "Multiple Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					auto mem1 = alloc.allocate( 4u, 4u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 16u )
					auto mem2 = alloc.allocate( 4u, 4u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 32u )
					auto mem3 = alloc.allocate( 4u, 4u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 48u )
					alloc.deallocate( mem3, 4u, 4u );
					alloc.deallocate( mem2, 4u, 4u );
					alloc.deallocate( mem1, 4u, 4u );
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 48u )
				}
				if ( astOn( "Unique multiple count over limit allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					auto mem = alloc.allocate( 4096u, 1024u );
					astCheckEqual( alloc.getCursor().index, 1u )
					astCheckEqual( alloc.getCursor().offset, 4096u * 1024u )
					alloc.deallocate( mem, 4096u, 1024u );
					astCheckEqual( alloc.getCursor().index, 1u )
					astCheckEqual( alloc.getCursor().offset, 4096u * 1024u )
				}
			}
			if ( astOn( "Through allocation blocks" ) )
			{
				if ( astOn( "No Allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					if ( auto block = alloc.getBlock() )
					{
						astCheckEqual( alloc.getCursor().index, 0u )
						astCheckEqual( alloc.getCursor().offset, 0u )
						astCheckEqual( block->report(), 0u )
					}
				}
				if ( astOn( "Unique Single 4 bytes allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4u, 1u ) )
						astCheckEqual( alloc.getCursor().index, 0u )
						astCheckEqual( alloc.getCursor().offset, 4u )
						astCheckEqual( block->report(), 4u )
					}
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 0u )
				}
				if ( astOn( "Unique Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4u, 4u ) )
						astCheckEqual( alloc.getCursor().index, 0u )
						astCheckEqual( alloc.getCursor().offset, 16u )
						astCheckEqual( block->report(), 16u )
					}
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 0u )
				}
				if ( astOn( "Multiple Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4u, 4u ) )
						astCheckEqual( alloc.getCursor().index, 0u )
						astCheckEqual( alloc.getCursor().offset, 16u )
						astCheckNoThrow( block->allocate( 4u, 4u ) )
						astCheckEqual( alloc.getCursor().index, 0u )
						astCheckEqual( alloc.getCursor().offset, 32u )
						astCheckNoThrow( block->allocate( 4u, 4u ) )
						astCheckEqual( alloc.getCursor().index, 0u )
						astCheckEqual( alloc.getCursor().offset, 48u )
						astCheckEqual( block->report(), 48u )
					}
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 0u )
				}
				if ( astOn( "Unique multiple count over limit allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eIncremental };
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4096u, 1024u ) )
						astCheckEqual( alloc.getCursor().index, 1u )
						astCheckEqual( alloc.getCursor().offset, 4096u * 1024u )
						astCheckEqual( block->report(), 4096u * 1024u )
					}
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4096u, 1024u ) )
						astCheckEqual( alloc.getCursor().index, 1u )
						astCheckEqual( alloc.getCursor().offset, 4096u * 1024u )
						astCheckEqual( block->report(), 4096u * 1024u )
					}
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4096u, 4096u ) )
						astCheckEqual( alloc.getCursor().index, 1u )
						astCheckEqual( alloc.getCursor().offset, 4096u * 4096u )
						astCheckEqual( block->report(), 4096u * 4096u )
					}
					astCheckEqual( alloc.getCursor().index, 0u )
					astCheckEqual( alloc.getCursor().offset, 0u )
				}
			}
		}
		if ( astOn( "Buddy allocator" ) )
		{
			if ( astOn( "Without allocation blocks" ) )
			{
				if ( astOn( "No Allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
				}
				if ( astOn( "Unique Single count 4 bytes allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					auto mem = alloc.allocate( 4u, 1u );
					alloc.deallocate( mem, 4u, 1u );
				}
				if ( astOn( "Unique Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					auto mem = alloc.allocate( 4u, 4u );
					alloc.deallocate( mem, 4u, 4u );
				}
				if ( astOn( "Multiple Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					auto mem1 = alloc.allocate( 4u, 4u );
					auto mem2 = alloc.allocate( 4u, 4u );
					auto mem3 = alloc.allocate( 4u, 4u );
					alloc.deallocate( mem3, 4u, 4u );
					alloc.deallocate( mem2, 4u, 4u );
					alloc.deallocate( mem1, 4u, 4u );
				}
				if ( astOn( "Unique multiple count over limit allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					astCheckThrow( alloc.allocate( 4, 1024u * 1024u ) )
				}
				if ( astOn( "Double delete" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					auto mem = alloc.allocate( 4u, 1u );
					alloc.deallocate( mem, 4u, 1u );
					alloc.deallocate( mem, 4u, 1u );
				}
				if ( astOn( "Leak" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					alloc.allocate( 4u, 1u );
				}
			}
			if ( astOn( "Through allocation blocks" ) )
			{
				if ( astOn( "No Allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					alloc.getBlock();
				}
				if ( astOn( "Unique Single 4 bytes allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					if ( auto block = alloc.getBlock() )
					{
						auto mem = block->allocate( 4u, 1u );
						block->deallocate( mem, 4u, 1u );
					}
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4u, 1u ) )
					}
				}
				if ( astOn( "Unique Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					if ( auto block = alloc.getBlock() )
					{
						auto mem = block->allocate( 4u, 4u );
						block->deallocate( mem, 4u, 4u );
					}
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4u, 6u ) )
					}
				}
				if ( astOn( "Multiple Multiple count 4 bytes allocations" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					if ( auto block = alloc.getBlock() )
					{
						auto mem1 = block->allocate( 4u, 4u );
						auto mem2 = block->allocate( 4u, 4u );
						auto mem3 = block->allocate( 4u, 4u );
						block->deallocate( mem3, 4u, 4u );
						block->deallocate( mem2, 4u, 4u );
						block->deallocate( mem1, 4u, 4u );
					}
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4u, 4u ) )
						astCheckNoThrow( block->allocate( 4u, 4u ) )
						astCheckNoThrow( block->allocate( 4u, 4u ) )
					}
				}
				if ( astOn( "Unique multiple count over limit allocation" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					if ( auto block = alloc.getBlock() )
					{
						astCheckThrow( block->allocate( 4, 1024u * 1024u ) )
					}
				}
				if ( astOn( "Exhaust pool" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					if ( auto block = alloc.getBlock() )
					{
						astCheckNoThrow( block->allocate( 4, 1u << 17u ) )
						astCheckThrow( alloc.allocate( 4, 1u ) )
					}
				}
				if ( astOn( "Double delete" ) )
				{
					ShaderAllocator alloc{ AllocationMode::eFragmented };
					if ( auto block = alloc.getBlock() )
					{
						auto mem = block->allocate( 4u, 1u );
						block->deallocate( mem, 4u, 1u );
						block->deallocate( mem, 4u, 1u );
					}
				}
			}
		}
		astTestEnd()
	}

	void testBoInfo( test::TestCounts & testCounts )
	{
		astTestBegin( "testBoInfo" );
		if ( astOn( "Base construction" ) )
		{
			type::TypesCache typesCache;
			BoInfo block{ typesCache
				, type::MemoryLayout::eStd430
				, "test"
				, 12u
				, 18u };
			astCheckEqual( block.binding.binding, 12u )
			astCheckEqual( block.binding.set, 18u )
			astBeginRequire( block.type != nullptr )
				astCheckEqual( block.type->getName(), "test" )
			astEndRequire
		}
		if ( astOn( "Existing struct construction" ) )
		{
			type::TypesCache typesCache;
			auto structType = typesCache.getStruct( type::MemoryLayout::eStd430, "test" );
			BoInfo block{ structType
				, 12u
				, 18u };
			astCheckEqual( block.binding.binding, 12u )
			astCheckEqual( block.binding.set, 18u )
			astBeginRequire( block.type != nullptr )
				astCheckEqual( block.type->getName(), "test" )
			astEndRequire
		}
		astTestEnd()
	}

	void testAccStructInfo( test::TestCounts & testCounts )
	{
		astTestBegin( "testAccStructInfo" );
		if ( astOn( "Base construction" ) )
		{
			type::TypesCache typesCache;
			AccStructInfo block{};
			astCheckEqual( block.binding.binding, ~0u )
			astCheckEqual( block.binding.set, ~0u )
			astCheck( !block.isValid() )
		}
		if ( astOn( "Existing struct construction" ) )
		{
			type::TypesCache typesCache;
			auto structType = typesCache.getAccelerationStructure();
			AccStructInfo block{ structType
				, 12u
				, 18u };
			astCheckEqual( block.binding.binding, 12u )
			astCheckEqual( block.binding.set, 18u )
			astCheck( block.isValid() )
		}
		astTestEnd()
	}

	void testShader( test::TestCounts & testCounts )
	{
		astTestBegin( "testShader" );
		if ( astOn( "Move constructor" ) )
		{
			Shader shader{ ShaderStage::eCompute };
			{
				Shader shader2{ std::move( shader ) };
				astCheckEqual( shader2.getType(), ShaderStage::eCompute )
			}
		}
		if ( astOn( "Base" ) )
		{
			Shader shader{ ShaderStage::eCompute };
			shader.getAllocator();
			shader.getExprCache();
			shader.getStmtCache();
			auto & typesCache = shader.getTypesCache();
			auto structType = typesCache.getStruct( type::MemoryLayout::eStd430, "myStruct" );
			structType->declMember( "mbr", type::Kind::eInt32 );
			uint32_t set{};
			auto handle = shader.getOpaqueHandle();
			auto & shader2 = Shader::fromOpaqueHandle( handle );
			astCheck( &shader2 == &shader )
#if SDAST_ExceptAssert
			astCheckThrow( Shader::fromOpaqueHandle( nullptr ) )
#endif
			astCheckEqual( shader.getType(), ShaderStage::eCompute )
			if ( astOn( "Storage Buffers" ) )
			{
				astCheck( shader.getSsbos().empty() )
				astCheckThrowEx( shader.getSsboInfo( "invalid" ), std::out_of_range )
				shader.registerSsbo( "ssbo", SsboInfo{ structType, 0u, set } );
				astCheck( !shader.getSsbos().empty() )
				astCheckNoThrow( shader.getSsboInfo( "ssbo" ) )
				++set;
			}
			if ( astOn( "Uniform Buffers" ) )
			{
				astCheck( shader.getUbos().empty() )
				astCheckThrowEx( shader.getUboInfo( "invalid" ), std::out_of_range )
				shader.registerUbo( "ubo", UboInfo{ structType, 0u, set } );
				astCheck( !shader.getUbos().empty() )
				astCheckNoThrow( shader.getUboInfo( "ubo" ) )
				++set;
			}
			if ( astOn( "Push Constant Buffers" ) )
			{
				astCheck( shader.getPcbs().empty() )
				astCheckThrowEx( shader.getPcbInfo( "invalid" ), std::out_of_range )
				shader.registerPcb( "pcb", InterfaceBlock{ structType } );
				astCheck( !shader.getPcbs().empty() )
				astCheckNoThrow( shader.getPcbInfo( "pcb" ) )
			}
			if ( astOn( "Shader Records" ) )
			{
				astCheck( shader.getShaderRecords().empty() )
				astCheckThrowEx( shader.getShaderRecordInfo( "invalid" ), std::out_of_range )
				shader.registerShaderRecord( "record", ShaderRecordInfo{ structType, 0u, set } );
				astCheck( !shader.getShaderRecords().empty() )
				astCheckNoThrow( shader.getShaderRecordInfo( "record" ) )
				++set;
			}
			if ( astOn( "Constants" ) )
			{
				astCheck( shader.getConstants().empty() )
				shader.registerConstant( "constant", typesCache.getInt32() );
				astCheck( !shader.getConstants().empty() )
			}
			if ( astOn( "Samplers" ) )
			{
				astCheck( shader.getSamplers().empty() )
				shader.registerSampler( "spl", typesCache.getSampler(), 0u, set );
				astCheck( !shader.getSamplers().empty() )
				++set;
			}
			if ( astOn( "Sampled Images" ) )
			{
				astCheck( shader.getSampledImages().empty() )
				shader.registerSampledImage( "splimg", typesCache.getSampledImage( type::ImageConfiguration{} ), 0u, set );
				astCheck( !shader.getSampledImages().empty() )
				++set;
			}
			if ( astOn( "Specialisation Constants" ) )
			{
				astCheck( shader.getSpecConstants().empty() )
				shader.registerSpecConstant( "spcconstant", typesCache.getInt32(), 0u );
				astCheck( !shader.getSpecConstants().empty() )
			}
			if ( astOn( "Combined Images" ) )
			{
				astCheck( shader.getCombinedImages().empty() )
				shader.registerCombinedImage( "combimg", typesCache.getCombinedImage( type::ImageConfiguration{} ), 0u, set );
				astCheck( !shader.getCombinedImages().empty() )
				++set;
			}
			if ( astOn( "Uniform Texel Buffers" ) )
			{
				astCheck( shader.getUniformTexelBuffers().empty() )
				shader.registerUniformTexelBuffer( "untex", typesCache.getSampledImage( type::ImageConfiguration{} ), 0u, set );
				astCheck( !shader.getUniformTexelBuffers().empty() )
				++set;
			}
			if ( astOn( "Storage Images" ) )
			{
				astCheck( shader.getStorageImages().empty() )
				shader.registerStorageImage( "img", typesCache.getImage( type::ImageConfiguration{} ), 0u, set );
				astCheck( !shader.getStorageImages().empty() )
				++set;
			}
			if ( astOn( "Storage Texel Buffers" ) )
			{
				astCheck( shader.getStorageTexelBuffers().empty() )
				shader.registerStorageTexelBuffer( "strtex", typesCache.getImage( type::ImageConfiguration{} ), 0u, set );
				astCheck( !shader.getStorageTexelBuffers().empty() )
				++set;
			}
			if ( astOn( "Inputs" ) )
			{
				astCheck( shader.getAllInputs().empty() )
				astCheck( shader.getInputs( EntryPoint::eCompute ).empty() )
				astCheck( shader.getInput( EntryPoint::eCompute, "invalid" ) == nullptr )
				shader.registerInput( EntryPoint::eCompute, "input", 1u, typesCache.getUInt32() );
				shader.registerInput( EntryPoint::eCompute, "input2", 1u, typesCache.getUInt32() );
				astCheck( !shader.getAllInputs().empty() )
				astCheck( !shader.getInputs( EntryPoint::eCompute ).empty() )
				astCheck( shader.getInputs( EntryPoint::eCompute ).size() == 1u )
				astCheckThrowEx( shader.getInput( EntryPoint::eCompute, "invalid" ), std::out_of_range )
				astCheckNoThrowEx( shader.getInput( EntryPoint::eCompute, "input" ), std::out_of_range )
				astCheck( shader.getInput( EntryPoint::eCompute, "input" ) != nullptr )
			}
			if ( astOn( "Outputs" ) )
			{
				astCheck( shader.getAllOutputs().empty() )
				astCheck( shader.getOutputs( EntryPoint::eCompute ).empty() )
				astCheck( shader.getOutput( EntryPoint::eCompute, "invalid" ) == nullptr )
				shader.registerOutput( EntryPoint::eCompute, "output", 1u, typesCache.getUInt32() );
				shader.registerOutput( EntryPoint::eCompute, "output2", 1u, typesCache.getUInt32() );
				astCheck( !shader.getAllOutputs().empty() )
				astCheck( !shader.getOutputs( EntryPoint::eCompute ).empty() )
				astCheck( shader.getOutputs( EntryPoint::eCompute ).size() == 1u )
				astCheckThrowEx( shader.getOutput( EntryPoint::eCompute, "invalid" ), std::out_of_range )
				astCheckNoThrowEx( shader.getOutput( EntryPoint::eCompute, "output" ), std::out_of_range )
				astCheck( shader.getOutput( EntryPoint::eCompute, "output" ) != nullptr )
			}
			if ( astOn( "In/Outs" ) )
			{
				astCheck( shader.getInOuts().empty() )
				shader.registerInOut( "inout", typesCache.getInt32() );
				astCheck( !shader.getInOuts().empty() )
			}
			if ( astOn( "Acceleration Structure" ) )
			{
				astCheck( !shader.getAccelerationStructureInfo().isValid() )
				shader.setAccelerationStruct( typesCache.getVoid(), 0u, set );
				astCheck( shader.getAccelerationStructureInfo().isValid() )
				++set;
			}
			if ( astOn( "Tessellation Control Points" ) )
			{
				astCheck( shader.getTessellationControlPoints() == 0u )
				shader.setTessellationControlPoints( 3u );
				astCheck( shader.getTessellationControlPoints() == 3u )
			}
			if ( astOn( "Global Variables" ) )
			{
				astCheckEqual( shader.hasGlobalVariable( "invalid" ), false )
				astCheckThrow( shader.getGlobalVariable( "invalid" ) )
				astBeginRequire( shader.getStatements() != nullptr )
				astCheck( shader.getStatements()->empty() )
				astEndRequire
				auto var = var::makeVariable( { shader.getNextVarId(), "test" }, typesCache.getBool() );
				shader.registerGlobalVariable( var );
				astCheckEqual( shader.hasGlobalVariable( "test" ), true )
				astCheckEqual( shader.getGlobalVariable( "test" ), var )
			}
		}
		astTestEnd()
	}

	void testShaderBuilder( test::TestCounts & testCounts )
	{
		astTestBegin( "testShaderBuilder" );
		if ( astOn( "Base" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			builder.getAllocator();
			builder.getExprCache();
			builder.getStmtCache();
			builder.getShader();
			astCheckEqual( builder.getType(), ShaderStage::eCompute )
			astCheckEqual( builder.hasGlobalVariable( "invalid" ), false )
			astBeginRequire( builder.getContainer() != nullptr )
			astCheck( builder.getContainer()->empty() )
			astEndRequire
			astBeginRequire( builder.getGlobalContainer() != nullptr )
			astCheck( builder.getGlobalContainer()->empty() )
			astEndRequire
			astCheck( builder.getDummyExpr( builder.getTypesCache().getBool() ) )
		}
		if ( astOn( "Scope handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & shader = builder.getShader();
			auto & typesCache = builder.getTypesCache();
			if ( astWhen( "Scope is empty" ) )
			{
				builder.pushScope( builder.getStmtCache().makeContainer() );
				builder.popScope();
			}
			if ( astWhen( "Scope is not empty" ) )
			{
				auto var = var::makeVariable( { shader.getNextVarId(), "test" }, typesCache.getUInt32() );
				auto container = builder.getStmtCache().makeContainer();
				builder.push( container.get(), { var } );
				builder.pop();
			}
			if ( astWhen( "Scope is not empty" ) )
			{
				auto var = builder.registerName( "test2", typesCache.getUInt32() );
				auto container = builder.getStmtCache().makeContainer();
				builder.push( container.get(), { var } );
				builder.pop();
			}
		}
		if ( astOn( "If statement" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & exprCache = builder.getExprCache();
			auto & typesCache = builder.getTypesCache();

			astCheckThrow( builder.beginElseIf( exprCache.makeLiteral( typesCache, false ) ) )
			astCheckThrow( builder.beginElse() )
			astCheckThrow( builder.endIf() )

			astCheckNoThrow( builder.beginIf( exprCache.makeLiteral( typesCache, false ) ) )
			astCheckNoThrow( builder.beginElseIf( exprCache.makeLiteral( typesCache, true ) ) )
			astCheckNoThrow( builder.beginElse() )
			astCheckNoThrow( builder.endIf() )
			astCheckThrow( builder.beginElseIf( exprCache.makeLiteral( typesCache, false ) ) )
			astCheckThrow( builder.beginElse() )
		}
		if ( astOn( "Switch statement" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & exprCache = builder.getExprCache();
			auto & typesCache = builder.getTypesCache();

			astCheckThrow( builder.beginCase( exprCache.makeLiteral( typesCache, false ) ) )
			astCheckThrow( builder.beginDefault() )
			astCheckThrow( builder.endSwitch() )

			astCheckNoThrow( builder.beginSwitch( exprCache.makeLiteral( typesCache, false ) ) )
			astCheckNoThrow( builder.beginCase( exprCache.makeLiteral( typesCache, true ) ) )
			astCheckNoThrow( builder.beginDefault() )
			astCheckNoThrow( builder.endSwitch() )
			astCheckThrow( builder.beginCase( exprCache.makeLiteral( typesCache, false ) ) )
			astCheckThrow( builder.beginDefault() )
			astCheckThrow( builder.endSwitch() )
		}
		if ( astOn( "Functions handling" ) )
		{
			std::string name{ "func" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			auto funcType = typesCache.getFunction( typesCache.getVoid(), {} );
			auto funcType2 = typesCache.getFunction( typesCache.getUInt32(), {} );
			astCheck( !builder.hasFunction( name, stmt::FunctionFlag::eNone ) )
			astCheck( !builder.hasFunction( name, 0u ) )
			astCheckThrow( builder.getFunction( name, stmt::FunctionFlag::eNone ) )
			astCheckThrow( builder.getFunction( name, 0u ) )
			astCheckNoThrow( builder.registerFunction( name, funcType, stmt::FunctionFlag::eNone ) )
			astCheckNoThrow( builder.registerFunction( name, funcType, 0u ) )
			astCheckThrow( builder.registerFunction( name, funcType2, 0u ) )
			astCheckNoThrow( builder.getFunction( name, stmt::FunctionFlag::eNone ) )
			astCheckNoThrow( builder.getFunction( name, 0u ) )
			astCheck( builder.hasFunction( name, stmt::FunctionFlag::eNone ) )
			astCheck( builder.hasFunction( name, 0u ) )
			astCheckThrow( builder.getFunction( name, stmt::FunctionFlag::eCallableEntryPoint ) )
			astCheckThrow( builder.getFunction( name, 1u ) )
			astCheck( !builder.hasFunction( name, stmt::FunctionFlag::eCallableEntryPoint ) )
			astCheck( !builder.hasFunction( name, 1u ) )
		}
		if ( astOn( "Global variables handling" ) )
		{
			std::string name{ "glob" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerName( name, typesCache.getUInt32() );
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheckNoThrow( builder.getVariable( name, false ) )
		}
		if ( astOn( "Local variables handling" ) )
		{
			std::string name{ "loc" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasVariable( name, true ) )
			astCheck( builder.getVariable( name, true ) == nullptr )
			builder.pushScope( builder.getStmtCache().makeContainer() );
			builder.registerName( name, typesCache.getUInt32() );
			builder.registerName( name, typesCache.getUInt32(), var::Flag::eLocale );
			builder.registerName( "loc2", type::makeTessellationControlInputType( typesCache.getVoid(), 3u ), var::Flag::eLocale );
			builder.registerBlockVariable( "loc3", typesCache.getUInt32() );
			builder.registerLocale( "loc4", typesCache.getUInt32() );
			builder.registerLoopVar( "loc5", typesCache.getUInt32() );
			builder.registerParam( "loc6", typesCache.getUInt32() );
			builder.registerInParam( "loc7", typesCache.getUInt32() );
			builder.registerInOutParam( "loc8", typesCache.getUInt32() );
			builder.registerOutParam( "loc9", typesCache.getUInt32() );
			astCheck( builder.hasVariable( name, true ) )
			astCheck( builder.getVariable( name, true ) != nullptr )
			builder.popScope();
		}
		if ( astOn( "Function local variables handling" ) )
		{
			std::string name{ "loc" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			builder.pushScope( builder.getStmtCache().makeFunctionDecl( var::makeFunction( { builder.getNextVarId(), "foo" }, typesCache.getFunction( typesCache.getVoid(), {} ) ), 0u ) );
			astCheck( !builder.hasVariable( name, true ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, true ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerName( name, typesCache.getUInt32() );
			builder.registerName( name, typesCache.getUInt32(), var::Flag::eLocale );
			builder.registerName( "loc2", type::makeTessellationControlInputType( typesCache.getVoid(), 3u ), var::Flag::eLocale );
			builder.registerBlockVariable( "loc3", typesCache.getUInt32() );
			builder.registerLocale( "loc4", typesCache.getUInt32() );
			builder.registerLoopVar( "loc5", typesCache.getUInt32() );
			builder.registerParam( "loc6", typesCache.getUInt32() );
			builder.registerInParam( "loc7", typesCache.getUInt32() );
			builder.registerInOutParam( "loc8", typesCache.getUInt32() );
			builder.registerOutParam( "loc9", typesCache.getUInt32() );
			astCheck( builder.hasVariable( name, true ) )
			astCheck( builder.getVariable( name, true ) != nullptr )
			builder.popScope();
		}
		if ( astOn( "Member variables handling" ) )
		{
			std::string name{ "mbr" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			auto outer = builder.registerName( "outer", typesCache.getUInt32() );
			astCheck( !builder.hasMemberVariable( outer, name ) )
			astCheckThrow( builder.getMemberVariable( outer, name ) )
			builder.registerMember( outer, name, typesCache.getUInt32() );
			builder.registerMember( outer, name, typesCache.getUInt32() );
			astCheck( builder.hasMemberVariable( outer, name ) )
			astCheck( builder.getMemberVariable( outer, name ) != nullptr )
		}
		if ( astOn( "Function member variables handling" ) )
		{
			std::string name{ "mbr" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			auto outer = builder.registerName( "outer", typesCache.getUInt32() );
			builder.pushScope( builder.getStmtCache().makeFunctionDecl( var::makeFunction( { builder.getNextVarId(), "foo" }, typesCache.getFunction( typesCache.getVoid(), {} ) ), 0u ) );
			astCheck( !builder.hasMemberVariable( outer, name ) )
			astCheckThrow( builder.getMemberVariable( outer, name ) )
			builder.registerMember( outer, name, typesCache.getUInt32() );
			builder.registerMember( outer, name, typesCache.getUInt32() );
			astCheck( builder.hasMemberVariable( outer, name ) )
			astCheck( builder.getMemberVariable( outer, name ) != nullptr )
			builder.popScope();
		}
		if ( astOn( "Constant variables handling" ) )
		{
			std::string name{ "cst" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerStaticConstant( name, typesCache.getUInt32() );
			builder.registerStaticConstant( name, typesCache.getUInt32() );
			astCheckThrow( builder.registerStaticConstant( name, typesCache.getInt32() ) )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Specialisation constant variables handling" ) )
		{
			std::string name{ "spccst" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerSpecConstant( name, 17u, typesCache.getUInt32() );
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Acceleration structure handling" ) )
		{
			std::string name{ "accstruct" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerAccelerationStructure( name, typesCache.getUInt32(), 1u, 2u, false );
			astCheck( !builder.getShader().getAccelerationStructureInfo().isValid() )
#if SDAST_ExceptAssert
			astCheckThrow( builder.registerAccelerationStructure( name, typesCache.getUInt32(), 1u, 2u ) )
#endif
			builder.registerAccelerationStructure( name, typesCache.getAccelerationStructure(), 1u, 2u );
			astCheck( builder.getShader().getAccelerationStructureInfo().isValid() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Sampler variables handling" ) )
		{
			std::string name{ "splr" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerSampler( name, typesCache.getSampler(), 1u, 2u, false );
			astCheck( builder.getShader().getSamplers().empty() )
			builder.registerSampler( name, typesCache.getSampler(), 1u, 2u );
			astCheck( !builder.getShader().getSamplers().empty() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Sampled image variables handling" ) )
		{
			std::string name{ "spld" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerSampledImage( name, typesCache.getSampledImage( type::ImageConfiguration{} ), 1u, 2u, false );
			astCheck( builder.getShader().getSampledImages().empty() )
			builder.registerSampledImage( name, typesCache.getSampledImage( type::ImageConfiguration{} ), 1u, 2u );
			astCheck( !builder.getShader().getSampledImages().empty() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Uniform texel buffer variables handling" ) )
		{
			std::string name{ "spld" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerSampledImage( name, typesCache.getSampledImage( type::ImageConfiguration{ type::Kind::eFloat, type::ImageDim::eBuffer } ), 1u, 2u, false );
			astCheck( builder.getShader().getSampledImages().empty() )
			builder.registerSampledImage( name, typesCache.getSampledImage( type::ImageConfiguration{ type::Kind::eFloat, type::ImageDim::eBuffer } ), 1u, 2u );
			astCheck( builder.getShader().getSampledImages().empty() )
			astCheck( !builder.getShader().getUniformTexelBuffers().empty() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Combined image variables handling" ) )
		{
			std::string name{ "combimg" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerTexture( name, typesCache.getCombinedImage( type::ImageConfiguration{} ), 1u, 2u, false );
			astCheck( builder.getShader().getCombinedImages().empty() )
			builder.registerTexture( name, typesCache.getCombinedImage( type::ImageConfiguration{} ), 1u, 2u );
			astCheck( !builder.getShader().getCombinedImages().empty() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Uniform texel buffer variables handling" ) )
		{
			std::string name{ "combimg" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerTexture( name, typesCache.getCombinedImage( type::ImageConfiguration{ type::Kind::eFloat, type::ImageDim::eBuffer } ), 1u, 2u, false );
			astCheck( builder.getShader().getCombinedImages().empty() )
			builder.registerTexture( name, typesCache.getCombinedImage( type::ImageConfiguration{ type::Kind::eFloat, type::ImageDim::eBuffer } ), 1u, 2u );
			astCheck( builder.getShader().getCombinedImages().empty() )
			astCheck( !builder.getShader().getUniformTexelBuffers().empty() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Storage image variables handling" ) )
		{
			std::string name{ "strgimg" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerImage( name, typesCache.getImage( type::ImageConfiguration{} ), 1u, 2u, false );
			astCheck( builder.getShader().getStorageImages().empty() )
			builder.registerImage( name, typesCache.getImage( type::ImageConfiguration{} ), 1u, 2u );
			astCheck( !builder.getShader().getStorageImages().empty() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Storage texel buffer variables handling" ) )
		{
			std::string name{ "strgimg" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			builder.registerImage( name, typesCache.getImage( type::ImageConfiguration{ type::Kind::eFloat, type::ImageDim::eBuffer } ), 1u, 2u, false );
			astCheck( builder.getShader().getStorageImages().empty() )
			builder.registerImage( name, typesCache.getImage( type::ImageConfiguration{ type::Kind::eFloat, type::ImageDim::eBuffer } ), 1u, 2u );
			astCheck( builder.getShader().getStorageImages().empty() )
			astCheck( !builder.getShader().getStorageTexelBuffers().empty() )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Storage Buffer variables handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto const & shader = builder.getShader();
			auto & typesCache = builder.getTypesCache();
			auto structType = typesCache.getStruct( type::MemoryLayout::eStd430, "myStruct" );
			structType->declMember( "mbr", type::Kind::eInt32 );

			astCheck( shader.getSsbos().empty() )
			astCheckThrowEx( shader.getSsboInfo( "invalid" ), std::out_of_range )
			builder.registerSsbo( "ssbo", SsboInfo{ structType, 10u, 1u } );
			astCheck( !shader.getSsbos().empty() )
			astCheckNoThrow( shader.getSsboInfo( "ssbo" ) )
		}
		if ( astOn( "Uniform Buffer variables handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto const & shader = builder.getShader();
			auto & typesCache = builder.getTypesCache();
			auto structType = typesCache.getStruct( type::MemoryLayout::eStd430, "myStruct" );
			structType->declMember( "mbr", type::Kind::eInt32 );

			astCheck( shader.getUbos().empty() )
			astCheckThrowEx( shader.getUboInfo( "invalid" ), std::out_of_range )
			builder.registerUbo( "ubo", UboInfo{ structType, 10u, 1u } );
			astCheck( !shader.getUbos().empty() )
			astCheckNoThrow( shader.getUboInfo( "ubo" ) )
		}
		if ( astOn( "Push Constant Buffer variables handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto const & shader = builder.getShader();
			auto & typesCache = builder.getTypesCache();
			auto structType = typesCache.getStruct( type::MemoryLayout::eStd430, "myStruct" );
			structType->declMember( "mbr", type::Kind::eInt32 );

			astCheck( shader.getPcbs().empty() )
			astCheckThrowEx( shader.getPcbInfo( "invalid" ), std::out_of_range )
			builder.registerPcb( "pcb", InterfaceBlock{ structType } );
			astCheck( !shader.getPcbs().empty() )
			astCheckNoThrow( shader.getPcbInfo( "pcb" ) )
		}
		if ( astOn( "Shader Record variables handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto const & shader = builder.getShader();
			auto & typesCache = builder.getTypesCache();
			auto structType = typesCache.getStruct( type::MemoryLayout::eStd430, "myStruct" );
			structType->declMember( "mbr", type::Kind::eInt32 );

			astCheck( shader.getShaderRecords().empty() )
			astCheckThrowEx( shader.getShaderRecordInfo( "invalid" ), std::out_of_range )
			builder.registerShaderRecord( "record", ShaderRecordInfo{ structType, 10u, 1u } );
			astCheck( !shader.getShaderRecords().empty() )
			astCheckNoThrow( shader.getShaderRecordInfo( "record" ) )
		}
		if ( astOn( "Input variables handling" ) )
		{
			std::string name{ "input" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			astCheck( builder.getShader().getAllInputs().empty() )
			astCheck( builder.getShader().getInputs( EntryPoint::eCompute ).empty() )
			astCheck( builder.getShader().getInput( EntryPoint::eCompute, name ) == nullptr )
			builder.registerInput( EntryPoint::eCompute, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( !builder.getShader().getAllInputs().empty() )
			astCheck( !builder.getShader().getInputs( EntryPoint::eCompute ).empty() )
			astCheck( builder.getShader().getInputs( EntryPoint::eCompute ).size() == 1 )
			builder.registerInput( EntryPoint::eCompute, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( builder.getShader().getInputs( EntryPoint::eCompute ).size() == 1 )
			astCheck( builder.getShader().getInput( EntryPoint::eCompute, name ) != nullptr )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Input variables handling" ) )
		{
			std::string name{ "input" };
			ShaderBuilder builder{ ShaderStage::eFragment };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			astCheck( builder.getShader().getAllInputs().empty() )
			astCheck( builder.getShader().getInputs( EntryPoint::eFragment ).empty() )
			astCheck( builder.getShader().getInput( EntryPoint::eFragment, name ) == nullptr )
			builder.registerInput( EntryPoint::eFragment, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( !builder.getShader().getAllInputs().empty() )
			astCheck( !builder.getShader().getInputs( EntryPoint::eFragment ).empty() )
			astCheck( builder.getShader().getInputs( EntryPoint::eFragment ).size() == 1 )
			builder.registerInput( EntryPoint::eFragment, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( builder.getShader().getInputs( EntryPoint::eFragment ).size() == 1 )
			astCheck( builder.getShader().getInput( EntryPoint::eFragment, name ) != nullptr )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Output variables handling" ) )
		{
			std::string name{ "output" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			astCheck( builder.getShader().getAllOutputs().empty() )
			astCheck( builder.getShader().getOutputs( EntryPoint::eCompute ).empty() )
			astCheck( builder.getShader().getOutput( EntryPoint::eCompute, name ) == nullptr )
			builder.registerOutput( EntryPoint::eCompute, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( !builder.getShader().getAllOutputs().empty() )
			astCheck( !builder.getShader().getOutputs( EntryPoint::eCompute ).empty() )
			astCheck( builder.getShader().getOutputs( EntryPoint::eCompute ).size() == 1 )
			builder.registerOutput( EntryPoint::eCompute, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( builder.getShader().getOutputs( EntryPoint::eCompute ).size() == 1 )
			astCheck( builder.getShader().getOutput( EntryPoint::eCompute, name ) != nullptr )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Output variables handling" ) )
		{
			std::string name{ "output" };
			ShaderBuilder builder{ ShaderStage::eVertex };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			astCheck( builder.getShader().getAllOutputs().empty() )
			astCheck( builder.getShader().getOutputs( EntryPoint::eVertex ).empty() )
			astCheck( builder.getShader().getOutput( EntryPoint::eVertex, name ) == nullptr )
			builder.registerOutput( EntryPoint::eVertex, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( !builder.getShader().getAllOutputs().empty() )
			astCheck( !builder.getShader().getOutputs( EntryPoint::eVertex ).empty() )
			astCheck( builder.getShader().getOutputs( EntryPoint::eVertex ).size() == 1 )
			builder.registerOutput( EntryPoint::eVertex, name, 1u, 0u, typesCache.getUInt32() );
			astCheck( builder.getShader().getOutputs( EntryPoint::eVertex ).size() == 1 )
			astCheck( builder.getShader().getOutput( EntryPoint::eVertex, name ) != nullptr )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "In/Out variables handling" ) )
		{
			std::string name{ "inout" };
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheck( !builder.hasGlobalVariable( name ) )
			astCheck( !builder.hasVariable( name, false ) )
			astCheckThrow( builder.getVariable( name, false ) )
			astCheck( builder.getShader().getInOuts().empty() )
			builder.registerInOut( name, 0u, typesCache.getUInt32() );
			astCheck( !builder.getShader().getInOuts().empty() )
			astCheck( builder.getShader().getInOuts().size() == 1 )
			builder.registerInOut( name, 0u, typesCache.getUInt32() );
			astCheck( builder.getShader().getInOuts().size() == 1 )
			astCheck( builder.hasGlobalVariable( name ) )
			astCheck( builder.hasVariable( name, false ) )
			astCheck( builder.getVariable( name, false ) != nullptr )
		}
		if ( astOn( "Builtin variables handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & typesCache = builder.getTypesCache();
			astCheckNoThrow( builder.registerBuiltin( Builtin::eGlobalInvocationID, typesCache.getUInt32(), var::Flag::eShaderInput ) )
		}
		if ( astOn( "Statements handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & stmtCache = builder.getStmtCache();
			auto & exprCache = builder.getExprCache();
			auto & typesCache = builder.getTypesCache();
			astCheckNoThrow( builder.addStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, builder.registerName( "var", typesCache.getUInt32() ) ) ) ) )
			astCheckEqual( builder.getContainer()->size(), 1u )
			astCheckNoThrow( builder.addGlobalStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, builder.registerName( "var2", typesCache.getUInt32() ) ) ) ) )
			astCheckEqual( builder.getContainer()->size(), 2u )
			astCheckNoThrow( builder.pushScope( stmtCache.makeContainer() ) )
				astCheck( builder.getContainer()->empty() )
				astCheckNoThrow( builder.addStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, builder.registerName( "var3", typesCache.getUInt32() ) ) ) ) )
				astCheckEqual( builder.getContainer()->size(), 1u )
				astCheckNoThrow( builder.addGlobalStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, builder.registerName( "var4", typesCache.getUInt32() ) ) ) ) )
				astCheckEqual( builder.getContainer()->size(), 1u )
			astCheckNoThrow( builder.popScope() )
			astCheckEqual( builder.getContainer()->size(), 4u )
		}
		if ( astOn( "Ignored statements handling" ) )
		{
			ShaderBuilder builder{ ShaderStage::eCompute };
			auto & stmtCache = builder.getStmtCache();
			auto & exprCache = builder.getExprCache();
			auto & typesCache = builder.getTypesCache();
			astCheckNoThrow( builder.saveNextExpr() )
			astCheckNoThrow( builder.addGlobalStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, builder.registerName( "var2", typesCache.getUInt32() ) ) ) ) )
#if SDAST_ExceptAssert
			astCheckThrow( builder.saveNextExpr() )
#endif
			astCheckEqual( builder.getContainer()->size(), 0u )
			astCheck( builder.loadExpr( nullptr ) != nullptr )
			astCheck( builder.loadExpr( nullptr ) == nullptr )

			astCheckNoThrow( builder.pushScope( stmtCache.makeContainer() ) )
				astCheck( builder.getContainer()->empty() )
				astCheckNoThrow( builder.saveNextExpr() )
				astCheckNoThrow( builder.addStmt( stmtCache.makeSimple( exprCache.makeIdentifier( typesCache, builder.registerName( "var3", typesCache.getUInt32() ) ) ) ) )
#if SDAST_ExceptAssert
				astCheckThrow( builder.saveNextExpr() )
#endif
				astCheckEqual( builder.getContainer()->size(), 0u )
				astCheck( builder.loadExpr( nullptr ) != nullptr )
				astCheck( builder.loadExpr( nullptr ) == nullptr )
			astCheckNoThrow( builder.popScope() )
			astCheckEqual( builder.getContainer()->size(), 1u )
		}
		astTestEnd()
	}
}

astTestSuiteMain( TestASTBase )
{
	astTestSuiteBegin()
	testMemorySemantics( testCounts );
	testShaderStages( testCounts );
	testEntryPoints( testCounts );
	testBuiltins( testCounts );
	testAllocator( testCounts );
	testBoInfo( testCounts );
	testAccStructInfo( testCounts );
	testShader( testCounts );
	testShaderBuilder( testCounts );
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTBase )
