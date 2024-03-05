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
		std::string result{ "Unknown" };

		switch ( entryPoint )
		{
		case EntryPoint::eNone:
			result = std::string{};
			break;
		case EntryPoint::eVertex:
			result = "Vert";
			break;
		case EntryPoint::eTessellationControl:
			result = "Tesc";
			break;
		case EntryPoint::eTessellationEvaluation:
			result = "Tese";
			break;
		case EntryPoint::eGeometry:
			result = "Geom";
			break;
		case EntryPoint::eMeshNV:
		case EntryPoint::eMesh:
			result = "Mesh";
			break;
		case EntryPoint::eTaskNV:
		case EntryPoint::eTask:
			result = "Task";
			break;
		case EntryPoint::eFragment:
			result = "Frag";
			break;
		case EntryPoint::eRayGeneration:
			result = "Rgen";
			break;
		case EntryPoint::eRayAnyHit:
			result = "Rany";
			break;
		case EntryPoint::eRayClosestHit:
			result = "Rcls";
			break;
		case EntryPoint::eRayMiss:
			result = "Rmis";
			break;
		case EntryPoint::eRayIntersection:
			result = "Rint";
			break;
		case EntryPoint::eCallable:
			result = "Call";
			break;
		case EntryPoint::eCompute:
			result = "Comp";
			break;
		default:
			AST_Failure( "Unsupported EntryPoint" );
		}

		return result;
	}

	EntryPoint getEntryPointType( ShaderStage stage )
	{
		EntryPoint result{};

		switch ( stage )
		{
		case ShaderStage::eVertex:
			result = EntryPoint::eVertex;
			break;
		case ShaderStage::eTessellationControl:
			result = EntryPoint::eTessellationControl;
			break;
		case ShaderStage::eTessellationEvaluation:
			result = EntryPoint::eTessellationEvaluation;
			break;
		case ShaderStage::eGeometry:
			result = EntryPoint::eGeometry;
			break;
		case ShaderStage::eFragment:
			result = EntryPoint::eFragment;
			break;
		case ShaderStage::eCompute:
			result = EntryPoint::eCompute;
			break;
		case ShaderStage::eTaskNV:
			result = EntryPoint::eTaskNV;
			break;
		case ShaderStage::eMeshNV:
			result = EntryPoint::eMeshNV;
			break;
		case ShaderStage::eTask:
			result = EntryPoint::eTask;
			break;
		case ShaderStage::eMesh:
			result = EntryPoint::eMesh;
			break;
		case ShaderStage::eRayGeneration:
			result = EntryPoint::eRayGeneration;
			break;
		case ShaderStage::eRayAnyHit:
			result = EntryPoint::eRayAnyHit;
			break;
		case ShaderStage::eRayClosestHit:
			result = EntryPoint::eRayClosestHit;
			break;
		case ShaderStage::eRayMiss:
			result = EntryPoint::eRayMiss;
			break;
		case ShaderStage::eRayIntersection:
			result = EntryPoint::eRayIntersection;
			break;
		case ShaderStage::eCallable:
			result = EntryPoint::eCallable;
			break;
		default:
			AST_Failure( "Unsupported ShaderStage" );
		}

		return result;
	}

	ShaderStage getShaderStage( EntryPoint entryPoint )
	{
		ShaderStage result{ ShaderStage::eCompute };

		switch ( entryPoint )
		{
		case EntryPoint::eVertex:
			result = ShaderStage::eVertex;
			break;
		case EntryPoint::eTessellationControl:
			result = ShaderStage::eTessellationControl;
			break;
		case EntryPoint::eTessellationEvaluation:
			result = ShaderStage::eTessellationEvaluation;
			break;
		case EntryPoint::eGeometry:
			result = ShaderStage::eGeometry;
			break;
		case EntryPoint::eFragment:
			result = ShaderStage::eFragment;
			break;
		case EntryPoint::eCompute:
			result = ShaderStage::eCompute;
			break;
		case EntryPoint::eTaskNV:
			result = ShaderStage::eTaskNV;
			break;
		case EntryPoint::eMeshNV:
			result = ShaderStage::eMeshNV;
			break;
		case EntryPoint::eTask:
			result = ShaderStage::eTask;
			break;
		case EntryPoint::eMesh:
			result = ShaderStage::eMesh;
			break;
		case EntryPoint::eRayGeneration:
			result = ShaderStage::eRayGeneration;
			break;
		case EntryPoint::eRayAnyHit:
			result = ShaderStage::eRayAnyHit;
			break;
		case EntryPoint::eRayClosestHit:
			result = ShaderStage::eRayClosestHit;
			break;
		case EntryPoint::eRayMiss:
			result = ShaderStage::eRayMiss;
			break;
		case EntryPoint::eRayIntersection:
			result = ShaderStage::eRayIntersection;
			break;
		case EntryPoint::eCallable:
			result = ShaderStage::eCallable;
			break;
		default:
			AST_Failure( "Unsupported EntryPoint" );
		}

		return result;
	}

	std::string getName( Builtin value )
	{
		std::string result{ "Undefined" };

		switch ( value )
		{
		case Builtin::eNone:
			result = "None";
			break;
		case Builtin::ePosition:
			result = "Position";
			break;
		case Builtin::ePointSize:
			result = "PointSize";
			break;
		case Builtin::eClipDistance:
			result = "ClipDistance";
			break;
		case Builtin::eCullDistance:
			result = "CullDistance";
			break;
		case Builtin::ePrimitiveID:
			result = "PrimitiveID";
			break;
		case Builtin::ePrimitiveIDIn:
			result = "PrimitiveIDIn";
			break;
		case Builtin::eInvocationID:
			result = "InvocationID";
			break;
		case Builtin::eLayer:
			result = "Layer";
			break;
		case Builtin::eViewportIndex:
			result = "ViewportIndex";
			break;
		case Builtin::eTessLevelOuter:
			result = "TessLevelOuter";
			break;
		case Builtin::eTessLevelInner:
			result = "TessLevelInner";
			break;
		case Builtin::eTessCoord:
			result = "TessCoord";
			break;
		case Builtin::ePatchVertices:
			result = "PatchVertices";
			break;
		case Builtin::ePatchVerticesIn:
			result = "PatchVerticesIn";
			break;
		case Builtin::eFragCoord:
			result = "FragCoord";
			break;
		case Builtin::ePointCoord:
			result = "PointCoord";
			break;
		case Builtin::eFrontFacing:
			result = "FrontFacing";
			break;
		case Builtin::eSampleID:
			result = "SampleID";
			break;
		case Builtin::eSamplePosition:
			result = "SamplePosition";
			break;
		case Builtin::eSampleMask:
			result = "SampleMask";
			break;
		case Builtin::eSampleMaskIn:
			result = "SampleMaskIn";
			break;
		case Builtin::eFragDepth:
			result = "FragDepth";
			break;
		case Builtin::eHelperInvocation:
			result = "HelperInvocation";
			break;
		case Builtin::eNumWorkGroups:
			result = "NumWorkGroups";
			break;
		case Builtin::eWorkGroupSize:
			result = "WorkGroupSize";
			break;
		case Builtin::eWorkGroupID:
			result = "WorkGroupID";
			break;
		case Builtin::eLocalInvocationID:
			result = "LocalInvocationID";
			break;
		case Builtin::eGlobalInvocationID:
			result = "GlobalInvocationID";
			break;
		case Builtin::eLocalInvocationIndex:
			result = "LocalInvocationIndex";
			break;
		case Builtin::eWorkDim:
			result = "WorkDim";
			break;
		case Builtin::eGlobalSize:
			result = "GlobalSize";
			break;
		case Builtin::eEnqueuedWorkgroupSize:
			result = "EnqueuedWorkgroupSize";
			break;
		case Builtin::eGlobalLinearID:
			result = "GlobalLinearID";
			break;
		case Builtin::eSubgroupSize:
			result = "SubgroupSize";
			break;
		case Builtin::eSubgroupMaxSize:
			result = "SubgroupMaxSize";
			break;
		case Builtin::eNumSubgroups:
			result = "NumSubgroups";
			break;
		case Builtin::eNumEnqueuedSubgroups:
			result = "NumEnqueuedSubgroups";
			break;
		case Builtin::eSubgroupID:
			result = "SubgroupID";
			break;
		case Builtin::eSubgroupLocalInvocationID:
			result = "SubgroupLocalInvocationID";
			break;
		case Builtin::eVertexIndex:
			result = "VertexIndex";
			break;
		case Builtin::eInstanceIndex:
			result = "InstanceIndex";
			break;
		case Builtin::eInstanceID:
			result = "InstanceID";
			break;
		case Builtin::eSubgroupEqMask:
			result = "SubgroupEqMask";
			break;
		case Builtin::eSubgroupGeMask:
			result = "SubgroupGeMask";
			break;
		case Builtin::eSubgroupGtMask:
			result = "SubgroupGtMask";
			break;
		case Builtin::eSubgroupLeMask:
			result = "SubgroupLeMask";
			break;
		case Builtin::eSubgroupLtMask:
			result = "SubgroupLtMask";
			break;
		case Builtin::eBaseVertex:
			result = "BaseVertex";
			break;
		case Builtin::eBaseInstance:
			result = "BaseInstance";
			break;
		case Builtin::eDrawIndex:
			result = "DrawIndex";
			break;
		case Builtin::eDeviceIndex:
			result = "DeviceIndex";
			break;
		case Builtin::eViewIndex:
			result = "ViewIndex";
			break;
		case Builtin::eBaryCoordNoPerspAMD:
			result = "BaryCoordNoPerspAMD";
			break;
		case Builtin::eBaryCoordNoPerspCentroidAMD:
			result = "BaryCoordNoPerspCentroidAMD";
			break;
		case Builtin::eBaryCoordNoPerspSampleAMD:
			result = "BaryCoordNoPerspSampleAMD";
			break;
		case Builtin::eBaryCoordSmoothAMD:
			result = "BaryCoordSmoothAMD";
			break;
		case Builtin::eBaryCoordSmoothCentroidAMD:
			result = "BaryCoordSmoothCentroidAMD";
			break;
		case Builtin::eBaryCoordSmoothSampleAMD:
			result = "BaryCoordSmoothSampleAMD";
			break;
		case Builtin::eBaryCoordPullModelAMD:
			result = "BaryCoordPullModelAMD";
			break;
		case Builtin::eFragStencilRefEXT:
			result = "FragStencilRefEXT";
			break;
		case Builtin::eViewportMaskNV:
			result = "ViewportMaskNV";
			break;
		case Builtin::eSecondaryPositionNV:
			result = "SecondaryPositionNV";
			break;
		case Builtin::eSecondaryViewportMaskNV:
			result = "SecondaryViewportMaskNV";
			break;
		case Builtin::ePositionPerViewNV:
			result = "PositionPerViewNV";
			break;
		case Builtin::eViewportMaskPerViewNV:
			result = "ViewportMaskPerViewNV";
			break;
		case Builtin::ePrimitiveIndicesNV:
			result = "PrimitiveIndicesNV";
			break;
		case Builtin::ePrimitiveCountNV:
			result = "PrimitiveCountNV";
			break;
		case Builtin::eTaskCountNV:
			result = "TaskCountNV";
			break;
		case Builtin::eClipDistancePerViewNV:
			result = "ClipDistancePerViewNV";
			break;
		case Builtin::eCullDistancePerViewNV:
			result = "CullDistancePerViewNV";
			break;
		case Builtin::eLayerPerViewNV:
			result = "LayerPerViewNV";
			break;
		case Builtin::eMeshViewCountNV:
			result = "MeshViewCountNV";
			break;
		case Builtin::eMeshViewIndicesNV:
			result = "MeshViewIndicesNV";
			break;
		case Builtin::eLaunchID:
			result = "LaunchID";
			break;
		case Builtin::eLaunchSize:
			result = "LaunchSize";
			break;
		case Builtin::eInstanceCustomIndex:
			result = "InstanceCustomIndex";
			break;
		case Builtin::eGeometryIndex:
			result = "GeometryIndex";
			break;
		case Builtin::eWorldRayOrigin:
			result = "WorldRayOrigin";
			break;
		case Builtin::eWorldRayDirection:
			result = "WorldRayDirection";
			break;
		case Builtin::eObjectRayOrigin:
			result = "ObjectRayOrigin";
			break;
		case Builtin::eObjectRayDirection:
			result = "ObjectRayDirection";
			break;
		case Builtin::eRayTmin:
			result = "RayTmin";
			break;
		case Builtin::eRayTmax:
			result = "RayTmax";
			break;
		case Builtin::eIncomingRayFlags:
			result = "IncomingRayFlags";
			break;
		case Builtin::eHitKind:
			result = "HitKind";
			break;
		case Builtin::eObjectToWorld:
			result = "ObjectToWorld";
			break;
		case Builtin::eWorldToObject:
			result = "WorldToObject";
			break;
		case Builtin::eCullPrimitive:
			result = "CullPrimitiveEXT";
			break;
		case Builtin::ePrimitivePointIndices:
			result = "PrimitivePointIndicesEXT";
			break;
		case Builtin::ePrimitiveLineIndices:
			result = "PrimitiveLineIndicesEXT";
			break;
		case Builtin::ePrimitiveTriangleIndices:
			result = "PrimitiveTriangleIndicesEXT";
			break;
		default:
			AST_Failure( "Unsupported Builtin" );
		}

		return result;
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
