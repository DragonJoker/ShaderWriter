#include "ShaderAST/ShaderASTPrerequisites.hpp"

namespace ast
{
	bool isRasterizerStage( ShaderStage stage )
	{
		switch ( stage )
		{
		case ShaderStage::eVertex:
		case ShaderStage::eTessellationControl:
		case ShaderStage::eTessellationEvaluation:
		case ShaderStage::eGeometry:
		case ShaderStage::eFragment:
		case ShaderStage::eTaskNV:
		case ShaderStage::eMeshNV:
		case ShaderStage::eTask:
		case ShaderStage::eMesh:
			return true;
		default:
			return false;
		}
	}

	bool isComputeStage( ShaderStage stage )
	{
		return stage == ShaderStage::eCompute;
	}

	bool isRayTraceStage( ShaderStage stage )
	{
		switch ( stage )
		{
		case ShaderStage::eRayGeneration:
		case ShaderStage::eRayClosestHit:
		case ShaderStage::eRayMiss:
		case ShaderStage::eRayIntersection:
		case ShaderStage::eRayAnyHit:
		case ShaderStage::eCallable:
			return true;
		default:
			return false;
		}
	}

	bool isMeshStage( ShaderStage stage )
	{
		switch ( stage )
		{
		case ShaderStage::eTaskNV:
		case ShaderStage::eMeshNV:
		case ShaderStage::eTask:
		case ShaderStage::eMesh:
			return true;
		default:
			return false;
		}
	}

	bool isMeshNVStage( ShaderStage stage )
	{
		switch ( stage )
		{
		case ShaderStage::eTaskNV:
		case ShaderStage::eMeshNV:
			return true;
		default:
			return false;
		}
	}

	std::string getName( EntryPoint entryPoint )
	{
		switch ( entryPoint )
		{
		case EntryPoint::eNone:
			return std::string{};
		case EntryPoint::eVertex:
			return "Vert";
		case EntryPoint::eTessellationControl:
			return "Tesc";
		case EntryPoint::eTessellationEvaluation:
			return "Tese";
		case EntryPoint::eGeometry:
			return "Geom";
		case EntryPoint::eMeshNV:
		case EntryPoint::eMesh:
			return "Mesh";
		case EntryPoint::eTaskNV:
		case EntryPoint::eTask:
			return "Task";
		case EntryPoint::eFragment:
			return "Frag";
		case EntryPoint::eRayGeneration:
			return "Rgen";
		case EntryPoint::eRayAnyHit:
			return "Rany";
		case EntryPoint::eRayClosestHit:
			return "Rcls";
		case EntryPoint::eRayMiss:
			return "Rmis";
		case EntryPoint::eRayIntersection:
			return "Rint";
		case EntryPoint::eCallable:
			return "Call";
		case EntryPoint::eCompute:
			return "Comp";
		default:
			AST_Failure( "Unsupported EntryPoint" );
			return "Unknown";
		}
	}

	EntryPoint getEntryPointType( ShaderStage stage )
	{
		switch ( stage )
		{
		case ShaderStage::eVertex:
			return EntryPoint::eVertex;
		case ShaderStage::eTessellationControl:
			return EntryPoint::eTessellationControl;
		case ShaderStage::eTessellationEvaluation:
			return EntryPoint::eTessellationEvaluation;
		case ShaderStage::eGeometry:
			return EntryPoint::eGeometry;
		case ShaderStage::eFragment:
			return EntryPoint::eFragment;
		case ShaderStage::eCompute:
			return EntryPoint::eCompute;
		case ShaderStage::eTaskNV:
			return EntryPoint::eTaskNV;
		case ShaderStage::eMeshNV:
			return EntryPoint::eMeshNV;
		case ShaderStage::eTask:
			return EntryPoint::eTask;
		case ShaderStage::eMesh:
			return EntryPoint::eMesh;
		case ShaderStage::eRayGeneration:
			return EntryPoint::eRayGeneration;
		case ShaderStage::eRayAnyHit:
			return EntryPoint::eRayAnyHit;
		case ShaderStage::eRayClosestHit:
			return EntryPoint::eRayClosestHit;
		case ShaderStage::eRayMiss:
			return EntryPoint::eRayMiss;
		case ShaderStage::eRayIntersection:
			return EntryPoint::eRayIntersection;
		case ShaderStage::eCallable:
			return EntryPoint::eCallable;
		default:
			AST_Failure( "Unsupported ShaderStage" );
			return EntryPoint::eNone;
		}
	}

	ShaderStage getShaderStage( EntryPoint entryPoint )
	{
		switch ( entryPoint )
		{
		case EntryPoint::eVertex:
			return ShaderStage::eVertex;
		case EntryPoint::eTessellationControl:
			return ShaderStage::eTessellationControl;
		case EntryPoint::eTessellationEvaluation:
			return ShaderStage::eTessellationEvaluation;
		case EntryPoint::eGeometry:
			return ShaderStage::eGeometry;
		case EntryPoint::eFragment:
			return ShaderStage::eFragment;
		case EntryPoint::eCompute:
			return ShaderStage::eCompute;
		case EntryPoint::eTaskNV:
			return ShaderStage::eTaskNV;
		case EntryPoint::eMeshNV:
			return ShaderStage::eMeshNV;
		case EntryPoint::eTask:
			return ShaderStage::eTask;
		case EntryPoint::eMesh:
			return ShaderStage::eMesh;
		case EntryPoint::eRayGeneration:
			return ShaderStage::eRayGeneration;
		case EntryPoint::eRayAnyHit:
			return ShaderStage::eRayAnyHit;
		case EntryPoint::eRayClosestHit:
			return ShaderStage::eRayClosestHit;
		case EntryPoint::eRayMiss:
			return ShaderStage::eRayMiss;
		case EntryPoint::eRayIntersection:
			return ShaderStage::eRayIntersection;
		case EntryPoint::eCallable:
			return ShaderStage::eCallable;
		default:
			AST_Failure( "Unsupported EntryPoint" );
			return ShaderStage::eCompute;
		}
	}

	std::string getName( Builtin value )
	{
		switch ( value )
		{
		case Builtin::eNone:
			return "None";
		case Builtin::ePosition:
			return "Position";
		case Builtin::ePointSize:
			return "PointSize";
		case Builtin::eClipDistance:
			return "ClipDistance";
		case Builtin::eCullDistance:
			return "CullDistance";
		case Builtin::ePrimitiveID:
			return "PrimitiveID";
		case Builtin::ePrimitiveIDIn:
			return "PrimitiveIDIn";
		case Builtin::eInvocationID:
			return "InvocationID";
		case Builtin::eLayer:
			return "Layer";
		case Builtin::eViewportIndex:
			return "ViewportIndex";
		case Builtin::eTessLevelOuter:
			return "TessLevelOuter";
		case Builtin::eTessLevelInner:
			return "TessLevelInner";
		case Builtin::eTessCoord:
			return "TessCoord";
		case Builtin::ePatchVertices:
			return "PatchVertices";
		case Builtin::ePatchVerticesIn:
			return "PatchVerticesIn";
		case Builtin::eFragCoord:
			return "FragCoord";
		case Builtin::ePointCoord:
			return "PointCoord";
		case Builtin::eFrontFacing:
			return "FrontFacing";
		case Builtin::eSampleID:
			return "SampleID";
		case Builtin::eSamplePosition:
			return "SamplePosition";
		case Builtin::eSampleMask:
			return "SampleMask";
		case Builtin::eSampleMaskIn:
			return "SampleMaskIn";
		case Builtin::eFragDepth:
			return "FragDepth";
		case Builtin::eHelperInvocation:
			return "HelperInvocation";
		case Builtin::eNumWorkGroups:
			return "NumWorkGroups";
		case Builtin::eWorkGroupSize:
			return "WorkGroupSize";
		case Builtin::eWorkGroupID:
			return "WorkGroupID";
		case Builtin::eLocalInvocationID:
			return "LocalInvocationID";
		case Builtin::eGlobalInvocationID:
			return "GlobalInvocationID";
		case Builtin::eLocalInvocationIndex:
			return "LocalInvocationIndex";
		case Builtin::eWorkDim:
			return "WorkDim";
		case Builtin::eGlobalSize:
			return "GlobalSize";
		case Builtin::eEnqueuedWorkgroupSize:
			return "EnqueuedWorkgroupSize";
		case Builtin::eGlobalLinearID:
			return "GlobalLinearID";
		case Builtin::eSubgroupSize:
			return "SubgroupSize";
		case Builtin::eSubgroupMaxSize:
			return "SubgroupMaxSize";
		case Builtin::eNumSubgroups:
			return "NumSubgroups";
		case Builtin::eNumEnqueuedSubgroups:
			return "NumEnqueuedSubgroups";
		case Builtin::eSubgroupID:
			return "SubgroupID";
		case Builtin::eSubgroupLocalInvocationID:
			return "SubgroupLocalInvocationID";
		case Builtin::eVertexIndex:
			return "VertexIndex";
		case Builtin::eInstanceIndex:
			return "InstanceIndex";
		case Builtin::eInstanceID:
			return "InstanceID";
		case Builtin::eSubgroupEqMask:
			return "SubgroupEqMask";
		case Builtin::eSubgroupGeMask:
			return "SubgroupGeMask";
		case Builtin::eSubgroupGtMask:
			return "SubgroupGtMask";
		case Builtin::eSubgroupLeMask:
			return "SubgroupLeMask";
		case Builtin::eSubgroupLtMask:
			return "SubgroupLtMask";
		case Builtin::eBaseVertex:
			return "BaseVertex";
		case Builtin::eBaseInstance:
			return "BaseInstance";
		case Builtin::eDrawIndex:
			return "DrawIndex";
		case Builtin::eDeviceIndex:
			return "DeviceIndex";
		case Builtin::eViewIndex:
			return "ViewIndex";
		case Builtin::eBaryCoordNoPerspAMD:
			return "BaryCoordNoPerspAMD";
		case Builtin::eBaryCoordNoPerspCentroidAMD:
			return "BaryCoordNoPerspCentroidAMD";
		case Builtin::eBaryCoordNoPerspSampleAMD:
			return "BaryCoordNoPerspSampleAMD";
		case Builtin::eBaryCoordSmoothAMD:
			return "BaryCoordSmoothAMD";
		case Builtin::eBaryCoordSmoothCentroidAMD:
			return "BaryCoordSmoothCentroidAMD";
		case Builtin::eBaryCoordSmoothSampleAMD:
			return "BaryCoordSmoothSampleAMD";
		case Builtin::eBaryCoordPullModelAMD:
			return "BaryCoordPullModelAMD";
		case Builtin::eFragStencilRefEXT:
			return "FragStencilRefEXT";
		case Builtin::eViewportMaskNV:
			return "ViewportMaskNV";
		case Builtin::eSecondaryPositionNV:
			return "SecondaryPositionNV";
		case Builtin::eSecondaryViewportMaskNV:
			return "SecondaryViewportMaskNV";
		case Builtin::ePositionPerViewNV:
			return "PositionPerViewNV";
		case Builtin::eViewportMaskPerViewNV:
			return "ViewportMaskPerViewNV";
		case Builtin::ePrimitiveIndicesNV:
			return "PrimitiveIndicesNV";
		case Builtin::ePrimitiveCountNV:
			return "PrimitiveCountNV";
		case Builtin::eTaskCountNV:
			return "TaskCountNV";
		case Builtin::eClipDistancePerViewNV:
			return "ClipDistancePerViewNV";
		case Builtin::eCullDistancePerViewNV:
			return "CullDistancePerViewNV";
		case Builtin::eLayerPerViewNV:
			return "LayerPerViewNV";
		case Builtin::eMeshViewCountNV:
			return "MeshViewCountNV";
		case Builtin::eMeshViewIndicesNV:
			return "MeshViewIndicesNV";
		case Builtin::eLaunchID:
			return "LaunchID";
		case Builtin::eLaunchSize:
			return "LaunchSize";
		case Builtin::eInstanceCustomIndex:
			return "InstanceCustomIndex";
		case Builtin::eGeometryIndex:
			return "GeometryIndex";
		case Builtin::eWorldRayOrigin:
			return "WorldRayOrigin";
		case Builtin::eWorldRayDirection:
			return "WorldRayDirection";
		case Builtin::eObjectRayOrigin:
			return "ObjectRayOrigin";
		case Builtin::eObjectRayDirection:
			return "ObjectRayDirection";
		case Builtin::eRayTmin:
			return "RayTmin";
		case Builtin::eRayTmax:
			return "RayTmax";
		case Builtin::eIncomingRayFlags:
			return "IncomingRayFlags";
		case Builtin::eHitKind:
			return "HitKind";
		case Builtin::eObjectToWorld:
			return "ObjectToWorld";
		case Builtin::eWorldToObject:
			return "WorldToObject";
		case Builtin::eCullPrimitive:
			return "CullPrimitiveEXT";
		case Builtin::ePrimitivePointIndices:
			return "PrimitivePointIndicesEXT";
		case Builtin::ePrimitiveLineIndices:
			return "PrimitiveLineIndicesEXT";
		case Builtin::ePrimitiveTriangleIndices:
			return "PrimitiveTriangleIndicesEXT";
		default:
			AST_Failure( "Unsupported Builtin" );
			return "Undefined";
		}
	}

	bool isPerVertex( Builtin value
		, ShaderStage stage )
	{
		switch ( value )
		{
		case Builtin::ePosition:
		case Builtin::ePositionPerViewNV:
		case Builtin::ePointSize:
		case Builtin::eCullDistance:
		case Builtin::eCullDistancePerViewNV:
			return true;
		case Builtin::eClipDistance:
		case Builtin::eClipDistancePerViewNV:
			return stage != ShaderStage::eFragment;
		default:
			return false;
		}
	}

	bool isPerPrimitive( Builtin value
		, ShaderStage stage )
	{
		switch ( value )
		{
		case Builtin::ePrimitiveID:
		case Builtin::eLayer:
		case Builtin::eLayerPerViewNV:
		case Builtin::eViewportIndex:
		case Builtin::eViewportMaskNV:
		case Builtin::eViewportMaskPerViewNV:
			return stage == ShaderStage::eMeshNV
				|| stage == ShaderStage::eMesh;
		default:
			return false;
		}
	}
}
