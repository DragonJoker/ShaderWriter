#include "ShaderAST/ShaderASTPrerequisites.hpp"

namespace ast
{
	bool isPerVertex( Builtin value
		, ShaderStage stage )
	{
		switch ( value )
		{
		case ast::Builtin::ePosition:
		case ast::Builtin::ePointSize:
		case ast::Builtin::eCullDistance:
			return true;
		case ast::Builtin::eClipDistance:
			return stage != ShaderStage::eFragment;
		default:
			return false;
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
		case Builtin::eSubgroupEqMaskKHR:
			return "SubgroupEqMaskKHR";
		case Builtin::eSubgroupGeMaskKHR:
			return "SubgroupGeMaskKHR";
		case Builtin::eSubgroupGtMaskKHR:
			return "SubgroupGtMaskKHR";
		case Builtin::eSubgroupLeMaskKHR:
			return "SubgroupLeMaskKHR";
		case Builtin::eSubgroupLtMaskKHR:
			return "SubgroupLtMaskKHR";
		case Builtin::eBaseVertex:
			return "BaseVertex";
		case Builtin::eBaseInstance:
			return "BaseInstance";
		case Builtin::eDrawIndex:
			return "DrawID";
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
			return "FragStencilRef";
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
		default:
			AST_Failure( "Unsupported ast::Builtin" );
			return "Undefined";
		}
	}
}
