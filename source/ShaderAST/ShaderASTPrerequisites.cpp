#include "ShaderAST/ShaderASTPrerequisites.hpp"

namespace ast
{
	bool isRasterizerStage( ShaderStage stage )
	{
		switch ( stage )
		{
		case ast::ShaderStage::eVertex:
		case ast::ShaderStage::eTessellationControl:
		case ast::ShaderStage::eTessellationEvaluation:
		case ast::ShaderStage::eGeometry:
		case ast::ShaderStage::eFragment:
		case ast::ShaderStage::eTaskNV:
		case ast::ShaderStage::eMeshNV:
		case ast::ShaderStage::eTask:
		case ast::ShaderStage::eMesh:
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
		case ast::ShaderStage::eRayGeneration:
		case ast::ShaderStage::eRayClosestHit:
		case ast::ShaderStage::eRayMiss:
		case ast::ShaderStage::eRayIntersection:
		case ast::ShaderStage::eRayAnyHit:
		case ast::ShaderStage::eCallable:
			return true;
		default:
			return false;
		}
	}

	bool isMeshStage( ShaderStage stage )
	{
		switch ( stage )
		{
		case ast::ShaderStage::eTaskNV:
		case ast::ShaderStage::eMeshNV:
		case ast::ShaderStage::eTask:
		case ast::ShaderStage::eMesh:
			return true;
		default:
			return false;
		}
	}

	bool isMeshNVStage( ShaderStage stage )
	{
		switch ( stage )
		{
		case ast::ShaderStage::eTaskNV:
		case ast::ShaderStage::eMeshNV:
			return true;
		default:
			return false;
		}
	}

	std::string getName( Builtin value )
	{
		switch ( value )
		{
		case ast::Builtin::eNone:
			return "None";
		case ast::Builtin::ePosition:
			return "Position";
		case ast::Builtin::ePointSize:
			return "PointSize";
		case ast::Builtin::eClipDistance:
			return "ClipDistance";
		case ast::Builtin::eCullDistance:
			return "CullDistance";
		case ast::Builtin::ePrimitiveID:
			return "PrimitiveID";
		case ast::Builtin::ePrimitiveIDIn:
			return "PrimitiveIDIn";
		case ast::Builtin::eInvocationID:
			return "InvocationID";
		case ast::Builtin::eLayer:
			return "Layer";
		case ast::Builtin::eViewportIndex:
			return "ViewportIndex";
		case ast::Builtin::eTessLevelOuter:
			return "TessLevelOuter";
		case ast::Builtin::eTessLevelInner:
			return "TessLevelInner";
		case ast::Builtin::eTessCoord:
			return "TessCoord";
		case ast::Builtin::ePatchVertices:
			return "PatchVertices";
		case ast::Builtin::ePatchVerticesIn:
			return "PatchVerticesIn";
		case ast::Builtin::eFragCoord:
			return "FragCoord";
		case ast::Builtin::ePointCoord:
			return "PointCoord";
		case ast::Builtin::eFrontFacing:
			return "FrontFacing";
		case ast::Builtin::eSampleID:
			return "SampleID";
		case ast::Builtin::eSamplePosition:
			return "SamplePosition";
		case ast::Builtin::eSampleMask:
			return "SampleMask";
		case ast::Builtin::eSampleMaskIn:
			return "SampleMaskIn";
		case ast::Builtin::eFragDepth:
			return "FragDepth";
		case ast::Builtin::eHelperInvocation:
			return "HelperInvocation";
		case ast::Builtin::eNumWorkGroups:
			return "NumWorkGroups";
		case ast::Builtin::eWorkGroupSize:
			return "WorkGroupSize";
		case ast::Builtin::eWorkGroupID:
			return "WorkGroupID";
		case ast::Builtin::eLocalInvocationID:
			return "LocalInvocationID";
		case ast::Builtin::eGlobalInvocationID:
			return "GlobalInvocationID";
		case ast::Builtin::eLocalInvocationIndex:
			return "LocalInvocationIndex";
		case ast::Builtin::eWorkDim:
			return "WorkDim";
		case ast::Builtin::eGlobalSize:
			return "GlobalSize";
		case ast::Builtin::eEnqueuedWorkgroupSize:
			return "EnqueuedWorkgroupSize";
		case ast::Builtin::eGlobalLinearID:
			return "GlobalLinearID";
		case ast::Builtin::eSubgroupSize:
			return "SubgroupSize";
		case ast::Builtin::eSubgroupMaxSize:
			return "SubgroupMaxSize";
		case ast::Builtin::eNumSubgroups:
			return "NumSubgroups";
		case ast::Builtin::eNumEnqueuedSubgroups:
			return "NumEnqueuedSubgroups";
		case ast::Builtin::eSubgroupID:
			return "SubgroupID";
		case ast::Builtin::eSubgroupLocalInvocationID:
			return "SubgroupLocalInvocationID";
		case ast::Builtin::eVertexIndex:
			return "VertexIndex";
		case ast::Builtin::eInstanceIndex:
			return "InstanceIndex";
		case ast::Builtin::eInstanceID:
			return "InstanceID";
		case ast::Builtin::eSubgroupEqMask:
			return "SubgroupEqMask";
		case ast::Builtin::eSubgroupGeMask:
			return "SubgroupGeMask";
		case ast::Builtin::eSubgroupGtMask:
			return "SubgroupGtMask";
		case ast::Builtin::eSubgroupLeMask:
			return "SubgroupLeMask";
		case ast::Builtin::eSubgroupLtMask:
			return "SubgroupLtMask";
		case ast::Builtin::eBaseVertex:
			return "BaseVertex";
		case ast::Builtin::eBaseInstance:
			return "BaseInstance";
		case ast::Builtin::eDrawIndex:
			return "DrawIndex";
		case ast::Builtin::eDeviceIndex:
			return "DeviceIndex";
		case ast::Builtin::eViewIndex:
			return "ViewIndex";
		case ast::Builtin::eBaryCoordNoPerspAMD:
			return "BaryCoordNoPerspAMD";
		case ast::Builtin::eBaryCoordNoPerspCentroidAMD:
			return "BaryCoordNoPerspCentroidAMD";
		case ast::Builtin::eBaryCoordNoPerspSampleAMD:
			return "BaryCoordNoPerspSampleAMD";
		case ast::Builtin::eBaryCoordSmoothAMD:
			return "BaryCoordSmoothAMD";
		case ast::Builtin::eBaryCoordSmoothCentroidAMD:
			return "BaryCoordSmoothCentroidAMD";
		case ast::Builtin::eBaryCoordSmoothSampleAMD:
			return "BaryCoordSmoothSampleAMD";
		case ast::Builtin::eBaryCoordPullModelAMD:
			return "BaryCoordPullModelAMD";
		case ast::Builtin::eFragStencilRefEXT:
			return "FragStencilRefEXT";
		case ast::Builtin::eViewportMaskNV:
			return "ViewportMaskNV";
		case ast::Builtin::eSecondaryPositionNV:
			return "SecondaryPositionNV";
		case ast::Builtin::eSecondaryViewportMaskNV:
			return "SecondaryViewportMaskNV";
		case ast::Builtin::ePositionPerViewNV:
			return "PositionPerViewNV";
		case ast::Builtin::eViewportMaskPerViewNV:
			return "ViewportMaskPerViewNV";
		case ast::Builtin::ePrimitiveIndicesNV:
			return "PrimitiveIndicesNV";
		case ast::Builtin::ePrimitiveCountNV:
			return "PrimitiveCountNV";
		case ast::Builtin::eTaskCountNV:
			return "TaskCountNV";
		case ast::Builtin::eClipDistancePerViewNV:
			return "ClipDistancePerViewNV";
		case ast::Builtin::eCullDistancePerViewNV:
			return "CullDistancePerViewNV";
		case ast::Builtin::eLayerPerViewNV:
			return "LayerPerViewNV";
		case ast::Builtin::eMeshViewCountNV:
			return "MeshViewCountNV";
		case ast::Builtin::eMeshViewIndicesNV:
			return "MeshViewIndicesNV";
		case ast::Builtin::eLaunchID:
			return "LaunchID";
		case ast::Builtin::eLaunchSize:
			return "LaunchSize";
		case ast::Builtin::eInstanceCustomIndex:
			return "InstanceCustomIndex";
		case ast::Builtin::eGeometryIndex:
			return "GeometryIndex";
		case ast::Builtin::eWorldRayOrigin:
			return "WorldRayOrigin";
		case ast::Builtin::eWorldRayDirection:
			return "WorldRayDirection";
		case ast::Builtin::eObjectRayOrigin:
			return "ObjectRayOrigin";
		case ast::Builtin::eObjectRayDirection:
			return "ObjectRayDirection";
		case ast::Builtin::eRayTmin:
			return "RayTmin";
		case ast::Builtin::eRayTmax:
			return "RayTmax";
		case ast::Builtin::eIncomingRayFlags:
			return "IncomingRayFlags";
		case ast::Builtin::eHitKind:
			return "HitKind";
		case ast::Builtin::eObjectToWorld:
			return "ObjectToWorld";
		case ast::Builtin::eWorldToObject:
			return "WorldToObject";
		case ast::Builtin::eCullPrimitive:
			return "CullPrimitiveEXT";
		case ast::Builtin::ePrimitivePointIndices:
			return "PrimitivePointIndicesEXT";
		case ast::Builtin::ePrimitiveLineIndices:
			return "PrimitiveLineIndicesEXT";
		case ast::Builtin::ePrimitiveTriangleIndices:
			return "PrimitiveTriangleIndicesEXT";
		default:
			AST_Failure( "Unsupported ast::Builtin" );
			return "Undefined";
		}
	}

	bool isPerVertex( Builtin value
		, ShaderStage stage )
	{
		switch ( value )
		{
		case ast::Builtin::ePosition:
		case ast::Builtin::ePositionPerViewNV:
		case ast::Builtin::ePointSize:
		case ast::Builtin::eCullDistance:
		case ast::Builtin::eCullDistancePerViewNV:
			return true;
		case ast::Builtin::eClipDistance:
		case ast::Builtin::eClipDistancePerViewNV:
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
		case ast::Builtin::ePrimitiveID:
		case ast::Builtin::eLayer:
		case ast::Builtin::eLayerPerViewNV:
		case ast::Builtin::eViewportIndex:
		case ast::Builtin::eViewportMaskNV:
		case ast::Builtin::eViewportMaskPerViewNV:
			return stage == ShaderStage::eMeshNV
				|| stage == ShaderStage::eMesh;
		default:
			return false;
		}
	}
}
