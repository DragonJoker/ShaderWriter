/*
See LICENSE file in root folder
*/
#include "SpirvHelpers.hpp"

namespace spirv
{
	//*************************************************************************

	spv::BuiltIn getBuiltin( std::string const & name )
	{
		auto result = spv::BuiltIn( -1 );

		if ( name == "gl_Position" )
		{
			result = spv::BuiltInPosition;
		}
		else if ( name == "gl_PointSize" )
		{
			result = spv::BuiltInPointSize;
		}
		else if ( name == "gl_ClipDistance" )
		{
			result = spv::BuiltInClipDistance;
		}
		else if ( name == "gl_CullDistance" )
		{
			result = spv::BuiltInCullDistance;
		}
		else if ( name == "gl_VertexID" )
		{
			result = spv::BuiltInVertexId;
		}
		else if ( name == "gl_InstanceID" )
		{
			result = spv::BuiltInInstanceId;
		}
		else if ( name == "gl_PrimitiveID" )
		{
			result = spv::BuiltInPrimitiveId;
		}
		else if ( name == "gl_InvocationID" )
		{
			result = spv::BuiltInInvocationId;
		}
		else if ( name == "gl_Layer" )
		{
			result = spv::BuiltInLayer;
		}
		else if ( name == "gl_ViewportIndex" )
		{
			result = spv::BuiltInViewportIndex;
		}
		else if ( name == "gl_TessLevelOuter" )
		{
			result = spv::BuiltInTessLevelOuter;
		}
		else if ( name == "gl_TessLevelInner" )
		{
			result = spv::BuiltInTessLevelInner;
		}
		else if ( name == "gl_TessCoord" )
		{
			result = spv::BuiltInTessCoord;
		}
		else if ( name == "gl_PatchVertices" )
		{
			result = spv::BuiltInPatchVertices;
		}
		else if ( name == "gl_FragCoord" )
		{
			result = spv::BuiltInFragCoord;
		}
		else if ( name == "gl_PointCoord" )
		{
			result = spv::BuiltInPointCoord;
		}
		else if ( name == "gl_FrontFacing" )
		{
			result = spv::BuiltInFrontFacing;
		}
		else if ( name == "gl_SampleID" )
		{
			result = spv::BuiltInSampleId;
		}
		else if ( name == "gl_SamplePosition" )
		{
			result = spv::BuiltInSamplePosition;
		}
		else if ( name == "gl_SampleMask" )
		{
			result = spv::BuiltInSampleMask;
		}
		else if ( name == "gl_FragDepth" )
		{
			result = spv::BuiltInFragDepth;
		}
		else if ( name == "gl_HelperInvocation" )
		{
			result = spv::BuiltInHelperInvocation;
		}
		else if ( name == "gl_NumWorkgroups" )
		{
			result = spv::BuiltInNumWorkgroups;
		}
		else if ( name == "gl_WorkgroupSize" )
		{
			result = spv::BuiltInWorkgroupSize;
		}
		else if ( name == "gl_WorkgroupID" )
		{
			result = spv::BuiltInWorkgroupId;
		}
		else if ( name == "gl_LocalInvocationID" )
		{
			result = spv::BuiltInLocalInvocationId;
		}
		else if ( name == "gl_GlobalInvocationID" )
		{
			result = spv::BuiltInGlobalInvocationId;
		}
		else if ( name == "gl_LocalInvocationIndex" )
		{
			result = spv::BuiltInLocalInvocationIndex;
		}
		else if ( name == "gl_WorkDim" )
		{
			result = spv::BuiltInWorkDim;
		}
		else if ( name == "gl_GlobalSize" )
		{
			result = spv::BuiltInGlobalSize;
		}
		else if ( name == "gl_EnqueuedWorkgroupSize" )
		{
			result = spv::BuiltInEnqueuedWorkgroupSize;
		}
		else if ( name == "gl_GlobalOffset" )
		{
			result = spv::BuiltInGlobalOffset;
		}
		else if ( name == "gl_GlobalLinearID" )
		{
			result = spv::BuiltInGlobalLinearId;
		}
		else if ( name == "gl_SubgroupSize" )
		{
			result = spv::BuiltInSubgroupSize;
		}
		else if ( name == "gl_SubgroupMaxSize" )
		{
			result = spv::BuiltInSubgroupMaxSize;
		}
		else if ( name == "gl_NumSubgroups" )
		{
			result = spv::BuiltInNumSubgroups;
		}
		else if ( name == "gl_NumEnqueuedSubgroups" )
		{
			result = spv::BuiltInNumEnqueuedSubgroups;
		}
		else if ( name == "gl_SubgroupID" )
		{
			result = spv::BuiltInSubgroupId;
		}
		else if ( name == "gl_SubgroupLocalInvocationID" )
		{
			result = spv::BuiltInSubgroupLocalInvocationId;
		}
		else if ( name == "gl_VertexIndex" )
		{
			result = spv::BuiltInVertexIndex;
		}
		else if ( name == "gl_InstanceIndex" )
		{
			result = spv::BuiltInInstanceIndex;
		}
		else if ( name == "gl_SubgroupEqMaskKHR" )
		{
			result = spv::BuiltInSubgroupEqMaskKHR;
		}
		else if ( name == "gl_SubgroupGeMaskKHR" )
		{
			result = spv::BuiltInSubgroupGeMaskKHR;
		}
		else if ( name == "gl_SubgroupGtMaskKHR" )
		{
			result = spv::BuiltInSubgroupGtMaskKHR;
		}
		else if ( name == "gl_SubgroupLeMaskKHR" )
		{
			result = spv::BuiltInSubgroupLeMaskKHR;
		}
		else if ( name == "gl_SubgroupLtMaskKHR" )
		{
			result = spv::BuiltInSubgroupLtMaskKHR;
		}
		else if ( name == "gl_BaseVertex" )
		{
			result = spv::BuiltInBaseVertex;
		}
		else if ( name == "gl_BaseInstance" )
		{
			result = spv::BuiltInBaseInstance;
		}
		else if ( name == "gl_DrawIndex" )
		{
			result = spv::BuiltInDrawIndex;
		}
		else if ( name == "gl_DeviceIndex" )
		{
			result = spv::BuiltInDeviceIndex;
		}
		else if ( name == "gl_ViewIndex" )
		{
			result = spv::BuiltInViewIndex;
		}
		else if ( name == "gl_BaryCoordNoPerspAMD" )
		{
			result = spv::BuiltInBaryCoordNoPerspAMD;
		}
		else if ( name == "gl_BaryCoordNoPerspCentroidAMD" )
		{
			result = spv::BuiltInBaryCoordNoPerspCentroidAMD;
		}
		else if ( name == "gl_BaryCoordNoPerspSampleAMD" )
		{
			result = spv::BuiltInBaryCoordNoPerspSampleAMD;
		}
		else if ( name == "gl_BaryCoordSmoothAMD" )
		{
			result = spv::BuiltInBaryCoordSmoothAMD;
		}
		else if ( name == "gl_BaryCoordSmoothCentroidAMD" )
		{
			result = spv::BuiltInBaryCoordSmoothCentroidAMD;
		}
		else if ( name == "gl_BaryCoordSmoothSampleAMD" )
		{
			result = spv::BuiltInBaryCoordSmoothSampleAMD;
		}
		else if ( name == "gl_BaryCoordPullModelAMD" )
		{
			result = spv::BuiltInBaryCoordPullModelAMD;
		}
		else if ( name == "gl_FragStencilRefEXT" )
		{
			result = spv::BuiltInFragStencilRefEXT;
		}
		else if ( name == "gl_ViewportMaskNV" )
		{
			result = spv::BuiltInViewportMaskNV;
		}
		else if ( name == "gl_SecondaryPositionNV" )
		{
			result = spv::BuiltInSecondaryPositionNV;
		}
		else if ( name == "gl_SecondaryViewportMaskNV" )
		{
			result = spv::BuiltInSecondaryViewportMaskNV;
		}
		else if ( name == "gl_PositionPerViewNV" )
		{
			result = spv::BuiltInPositionPerViewNV;
		}
		else if ( name == "gl_ViewportMaskPerViewNV" )
		{
			result = spv::BuiltInViewportMaskPerViewNV;
		}

		return result;
	}

	spv::MemoryModel getMemoryModel()
	{
		return spv::MemoryModelGLSL450;
	}

	spv::ExecutionModel getExecutionModel( ast::ShaderStage kind )
	{
		spv::ExecutionModel result;

		switch ( kind )
		{
		case ast::ShaderStage::eVertex:
			result = spv::ExecutionModelVertex;
			break;
		case ast::ShaderStage::eTessellationControl:
			result = spv::ExecutionModelTessellationControl;
			break;
		case ast::ShaderStage::eTessellationEvaluation:
			result = spv::ExecutionModelTessellationEvaluation;
			break;
		case ast::ShaderStage::eGeometry:
			result = spv::ExecutionModelGeometry;
			break;
		case ast::ShaderStage::eCompute:
			result = spv::ExecutionModelGLCompute;
			break;
		case ast::ShaderStage::eFragment:
			result = spv::ExecutionModelFragment;
			break;
		default:
			assert( false && "Unsupported sdw::ShaderStage." );
			break;
		}

		return result;
	}

	std::string getTypeName( spv::Op op )
	{
		return getOpName( op );
	}

	std::string getOperatorName( spv::Op op )
	{
		return getOpName( op );
	}

	//*************************************************************************

	spv::ImageFormat getImageFormat( ast::type::ImageFormat value )
	{
		switch ( value )
		{
		case ast::type::ImageFormat::eUnknown:
			return spv::ImageFormatUnknown;
		case ast::type::ImageFormat::eRgba32f:
			return spv::ImageFormatRgba32f;
		case ast::type::ImageFormat::eRgba16f:
			return spv::ImageFormatRgba16f;
		case ast::type::ImageFormat::eRg32f:
			return spv::ImageFormatRg32f;
		case ast::type::ImageFormat::eRg16f:
			return spv::ImageFormatRg16f;
		case ast::type::ImageFormat::eR32f:
			return spv::ImageFormatR32f;
		case ast::type::ImageFormat::eR16f:
			return spv::ImageFormatR16f;
		case ast::type::ImageFormat::eRgba32i:
			return spv::ImageFormatRgba32i;
		case ast::type::ImageFormat::eRgba16i:
			return spv::ImageFormatRgba16i;
		case ast::type::ImageFormat::eRgba8i:
			return spv::ImageFormatRgba8i;
		case ast::type::ImageFormat::eRg32i:
			return spv::ImageFormatRg32i;
		case ast::type::ImageFormat::eRg16i:
			return spv::ImageFormatRg16i;
		case ast::type::ImageFormat::eRg8i:
			return spv::ImageFormatRg8i;
		case ast::type::ImageFormat::eR32i:
			return spv::ImageFormatR32i;
		case ast::type::ImageFormat::eR16i:
			return spv::ImageFormatR16i;
		case ast::type::ImageFormat::eR8i:
			return spv::ImageFormatR8i;
		case ast::type::ImageFormat::eRgba32u:
			return spv::ImageFormatRgba32ui;
		case ast::type::ImageFormat::eRgba16u:
			return spv::ImageFormatRgba16ui;
		case ast::type::ImageFormat::eRgba8u:
			return spv::ImageFormatRgba8ui;
		case ast::type::ImageFormat::eRg32u:
			return spv::ImageFormatRg32ui;
		case ast::type::ImageFormat::eRg16u:
			return spv::ImageFormatRg16ui;
		case ast::type::ImageFormat::eRg8u:
			return spv::ImageFormatRg8ui;
		case ast::type::ImageFormat::eR32u:
			return spv::ImageFormatR32ui;
		case ast::type::ImageFormat::eR16u:
			return spv::ImageFormatR16ui;
		case ast::type::ImageFormat::eR8u:
			return spv::ImageFormatR8ui;
		default:
			assert( false && "Unsupported ast::type::ImageFormat" );
			return spv::ImageFormatRgba32f;
		}
	}

	InstructionPtr makeExtension( std::string const & name )
	{
		return makeInstruction< ExtensionInstruction >( name );
	}

	InstructionPtr makeFunctionType( spv::Id returnTypeId
		, IdList const & functionTypesId )
	{
		return makeInstruction< FunctionTypeInstruction >( returnTypeId
			, functionTypesId );
	}

	void getBinOpOperands( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs
		, IdList & operands
		, spv::Op & opCode )
	{
		bool needsMatchingVector;
		bool switchParams{ false };
		opCode = getBinOpCode( exprKind
			, lhsTypeKind
			, rhsTypeKind
			, switchParams
			, needsMatchingVector );

		if ( switchParams )
		{
			std::swap( lhs, rhs );
		}

		operands = makeOperands( lhs, rhs );
	}

	IdList makeBinOpOperands( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs )
	{
		IdList result;
		spv::Op opCode;
		getBinOpOperands( exprKind, lhsTypeKind, rhsTypeKind, lhs, rhs, result, opCode );
		return makeOperands( spv::Id( opCode ), result );
	}

	InstructionPtr makeImageTypeInstruction( ast::type::ImageConfiguration const & config
		, spv::Id resultId
		, spv::Id sampledTypeId )
	{
		IdList operands;
		operands.push_back( sampledTypeId );
		operands.push_back( spv::Id( config.dimension ) );
		operands.push_back( config.isDepth == ast::type::Trinary::eTrue
			? 1u
			: ( config.isDepth == ast::type::Trinary::eFalse
				? 0u
				: 2u ) );
		operands.push_back( config.isArrayed ? 1u : 0u );
		operands.push_back( config.isMS ? 1u : 0u );
		operands.push_back( config.isSampled == ast::type::Trinary::eTrue
			? 1u
			: ( config.isDepth == ast::type::Trinary::eFalse
				? 2u
				: 0u ) );
		operands.push_back( uint32_t( getImageFormat( config.format ) ) );
		// Only available in kernel mode.
		// operands.push_back( uint32_t( config.accessKind ) );

		return makeInstruction< ImageTypeInstruction >( resultId
			, operands );
	}

	InstructionPtr makeBaseTypeInstruction( ast::type::Kind kind
		, spv::Id id )
	{
		assert( !isStructType( kind )
			&& !isSamplerType( kind )
			&& !isImageType( kind )
			&& !isSampledImageType( kind ) );
		IdList operands;

		switch ( kind )
		{
		case ast::type::Kind::eVoid:
			return makeInstruction< VoidTypeInstruction >( id );
		case ast::type::Kind::eBoolean:
			return makeInstruction< BooleanTypeInstruction >( id );
		case ast::type::Kind::eInt:
			return makeInstruction< IntTypeInstruction >( id, 32u, 1u );
		case ast::type::Kind::eUInt:
			return makeInstruction< IntTypeInstruction >( id, 32u, 0u );
		case ast::type::Kind::eFloat:
			return makeInstruction< FloatTypeInstruction >( id, 32u );
		case ast::type::Kind::eDouble:
			return makeInstruction< FloatTypeInstruction >( id, 64u );
		case ast::type::Kind::eHalf:
			return makeInstruction< FloatTypeInstruction >( id, 16u );
		default:
			assert( false && "Unexpected type kind" );
		}

		return nullptr;
	}

	InstructionPtr makeIntrinsicInstruction( spv::Op op
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::OpEmitStreamVertex:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEmitStreamVertex > >( operands );
		case spv::OpEndStreamPrimitive:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEndStreamPrimitive > >( operands );
		case spv::OpEmitVertex:
			assert( operands.empty() );
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEmitVertex > >( operands );
		case spv::OpEndPrimitive:
			assert( operands.empty() );
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpEndPrimitive > >( operands );
		case spv::OpControlBarrier:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpControlBarrier > >( operands );
		case spv::OpMemoryBarrier:
			return makeInstruction< VoidIntrinsicInstructionT< spv::OpMemoryBarrier > >( operands );
		default:
			assert( false && "Unexpected intrinsic call Op" );
		}

		return nullptr;
	}

	InstructionPtr makeIntrinsicInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::OpFMod:
			return makeInstruction< IntrinsicInstructionT< spv::OpFMod > >( returnTypeId, resultId, operands );
		case spv::OpIsNan:
			return makeInstruction< IntrinsicInstructionT< spv::OpIsNan > >( returnTypeId, resultId, operands );
		case spv::OpIsInf:
			return makeInstruction< IntrinsicInstructionT< spv::OpIsInf > >( returnTypeId, resultId, operands );
		case spv::OpBitcast:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitcast > >( returnTypeId, resultId, operands );
		case spv::OpDot:
			return makeInstruction< IntrinsicInstructionT< spv::OpDot > >( returnTypeId, resultId, operands );
		case spv::OpMatrixTimesMatrix:
			return makeInstruction< IntrinsicInstructionT< spv::OpMatrixTimesMatrix > >( returnTypeId, resultId, operands );
		case spv::OpOuterProduct:
			return makeInstruction< IntrinsicInstructionT< spv::OpOuterProduct > >( returnTypeId, resultId, operands );
		case spv::OpTranspose:
			return makeInstruction< IntrinsicInstructionT< spv::OpTranspose > >( returnTypeId, resultId, operands );
		case spv::OpFOrdLessThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdLessThan > >( returnTypeId, resultId, operands );
		case spv::OpSLessThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpSLessThan > >( returnTypeId, resultId, operands );
		case spv::OpULessThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpULessThan > >( returnTypeId, resultId, operands );
		case spv::OpFOrdLessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpSLessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpSLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpULessThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpULessThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpFOrdGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdGreaterThan > >( returnTypeId, resultId, operands );
		case spv::OpSGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpSGreaterThan > >( returnTypeId, resultId, operands );
		case spv::OpUGreaterThan:
			return makeInstruction< IntrinsicInstructionT< spv::OpUGreaterThan > >( returnTypeId, resultId, operands );
		case spv::OpFOrdGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpSGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpSGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpUGreaterThanEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpUGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpFOrdEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdEqual > >( returnTypeId, resultId, operands );
		case spv::OpIEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpIEqual > >( returnTypeId, resultId, operands );
		case spv::OpFOrdNotEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpFOrdNotEqual > >( returnTypeId, resultId, operands );
		case spv::OpINotEqual:
			return makeInstruction< IntrinsicInstructionT< spv::OpINotEqual > >( returnTypeId, resultId, operands );
		case spv::OpAll:
			return makeInstruction< IntrinsicInstructionT< spv::OpAll > >( returnTypeId, resultId, operands );
		case spv::OpAny:
			return makeInstruction< IntrinsicInstructionT< spv::OpAny > >( returnTypeId, resultId, operands );
		case spv::OpLogicalNot:
			return makeInstruction< IntrinsicInstructionT< spv::OpLogicalNot > >( returnTypeId, resultId, operands );
		case spv::OpIAddCarry:
			return makeInstruction< IntrinsicInstructionT< spv::OpIAddCarry > >( returnTypeId, resultId, operands );
		case spv::OpISubBorrow:
			return makeInstruction< IntrinsicInstructionT< spv::OpISubBorrow > >( returnTypeId, resultId, operands );
		case spv::OpUMulExtended:
			return makeInstruction< IntrinsicInstructionT< spv::OpUMulExtended > >( returnTypeId, resultId, operands );
		case spv::OpBitFieldSExtract:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitFieldSExtract > >( returnTypeId, resultId, operands );
		case spv::OpBitFieldUExtract:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitFieldUExtract > >( returnTypeId, resultId, operands );
		case spv::OpBitFieldInsert:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitFieldInsert > >( returnTypeId, resultId, operands );
		case spv::OpBitReverse:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitReverse > >( returnTypeId, resultId, operands );
		case spv::OpBitCount:
			return makeInstruction< IntrinsicInstructionT< spv::OpBitCount > >( returnTypeId, resultId, operands );
		case spv::OpAtomicIAdd:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicIAdd > >( returnTypeId, resultId, operands );
		case spv::OpAtomicFAddEXT:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicFAddEXT > >( returnTypeId, resultId, operands );
		case spv::OpAtomicSMin:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicSMin > >( returnTypeId, resultId, operands );
		case spv::OpAtomicUMin:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicUMin > >( returnTypeId, resultId, operands );
		case spv::OpAtomicSMax:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicSMax > >( returnTypeId, resultId, operands );
		case spv::OpAtomicUMax:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicUMax > >( returnTypeId, resultId, operands );
		case spv::OpAtomicAnd:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicAnd > >( returnTypeId, resultId, operands );
		case spv::OpAtomicOr:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicOr > >( returnTypeId, resultId, operands );
		case spv::OpAtomicXor:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicXor > >( returnTypeId, resultId, operands );
		case spv::OpAtomicExchange:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicExchange > >( returnTypeId, resultId, operands );
		case spv::OpAtomicCompareExchange:
			return makeInstruction< IntrinsicInstructionT< spv::OpAtomicCompareExchange > >( returnTypeId, resultId, operands );
		case spv::OpDPdx:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdx > >( returnTypeId, resultId, operands );
		case spv::OpDPdxCoarse:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdxCoarse > >( returnTypeId, resultId, operands );
		case spv::OpDPdxFine:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdxFine > >( returnTypeId, resultId, operands );
		case spv::OpDPdy:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdy > >( returnTypeId, resultId, operands );
		case spv::OpDPdyCoarse:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdyCoarse > >( returnTypeId, resultId, operands );
		case spv::OpDPdyFine:
			return makeInstruction< IntrinsicInstructionT< spv::OpDPdyFine > >( returnTypeId, resultId, operands );
		case spv::OpFwidth:
			return makeInstruction< IntrinsicInstructionT< spv::OpFwidth > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected intrinsic call Op" );
		}

		return nullptr;
	}

	InstructionPtr makeTextureAccessInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::OpImageQuerySizeLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQuerySizeLod > >( returnTypeId, resultId, operands );
		case spv::OpImageQuerySize:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQuerySize > >( returnTypeId, resultId, operands );
		case spv::OpImageQueryLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQueryLod > >( returnTypeId, resultId, operands );
		case spv::OpImageQueryLevels:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageQueryLevels > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleImplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleDrefImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleDrefImplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleProjImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjImplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleProjDrefImplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjDrefImplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleExplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleDrefExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleDrefExplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleProjExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjExplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageSampleProjDrefExplicitLod:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageSampleProjDrefExplicitLod > >( returnTypeId, resultId, operands );
		case spv::OpImageFetch:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageFetch > >( returnTypeId, resultId, operands );
		case spv::OpImageGather:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageGather > >( returnTypeId, resultId, operands );
		case spv::OpImageDrefGather:
			return makeInstruction< TextureAccessInstructionT< spv::OpImageDrefGather > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected texture access Op" );
		}

		return nullptr;
	}

	InstructionPtr makeImageAccessInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::OpImageQuerySize:
			return makeInstruction< ImageAccessInstructionT< spv::OpImageQuerySize > >( returnTypeId, resultId, operands );
		case spv::OpImageQuerySamples:
			return makeInstruction< ImageAccessInstructionT< spv::OpImageQuerySamples > >( returnTypeId, resultId, operands );
		case spv::OpImageRead:
			return makeInstruction< ImageAccessInstructionT< spv::OpImageRead > >( returnTypeId, resultId, operands );
		case spv::OpImageWrite:
			assert( false && "OpImageWrite has its own instruction type: ImageStoreInstruction, use makeInstruction" );
			return makeInstruction< VariadicInstructionT< spv::OpImageWrite, false, false > >( operands );
		case spv::OpAtomicIAdd:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicIAdd > >( returnTypeId, resultId, operands );
		case spv::OpAtomicUMin:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicUMin > >( returnTypeId, resultId, operands );
		case spv::OpAtomicSMin:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicSMin > >( returnTypeId, resultId, operands );
		case spv::OpAtomicUMax:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicUMax > >( returnTypeId, resultId, operands );
		case spv::OpAtomicSMax:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicSMax > >( returnTypeId, resultId, operands );
		case spv::OpAtomicAnd:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicAnd > >( returnTypeId, resultId, operands );
		case spv::OpAtomicOr:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicOr > >( returnTypeId, resultId, operands );
		case spv::OpAtomicXor:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicXor > >( returnTypeId, resultId, operands );
		case spv::OpAtomicExchange:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicExchange > >( returnTypeId, resultId, operands );
		case spv::OpAtomicCompareExchange:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicCompareExchange > >( returnTypeId, resultId, operands );
		case spv::OpAtomicFAddEXT:
			return makeInstruction< ImageAccessInstructionT< spv::OpAtomicFAddEXT > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected image access Op" );
		}

		return nullptr;
	}

	InstructionPtr makeCastInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, spv::Op op
		, spv::Id operandId )
	{
		switch ( op )
		{
		case spv::OpFConvert:
			return makeInstruction< UnInstructionT< spv::OpFConvert > >( returnTypeId, resultId, operandId );
		case spv::OpConvertFToS:
			return makeInstruction< UnInstructionT< spv::OpConvertFToS > >( returnTypeId, resultId, operandId );
		case spv::OpConvertFToU:
			return makeInstruction< UnInstructionT< spv::OpConvertFToU > >( returnTypeId, resultId, operandId );
		case spv::OpConvertSToF:
			return makeInstruction< UnInstructionT< spv::OpConvertSToF > >( returnTypeId, resultId, operandId );
		case spv::OpConvertUToF:
			return makeInstruction< UnInstructionT< spv::OpConvertUToF > >( returnTypeId, resultId, operandId );
		case spv::OpBitcast:
			return makeInstruction< UnInstructionT< spv::OpBitcast > >( returnTypeId, resultId, operandId );
		default:
			assert( false && "Unexpected cast Op" );
		}

		return nullptr;
	}

	InstructionPtr makeUnInstruction( spv::Op op
		, spv::Id returnTypeId
		, spv::Id resultId
		, spv::Id operandId )
	{
		switch ( op )
		{
		case spv::OpNot:
			return makeInstruction< UnInstructionT< spv::OpNot > >( returnTypeId, resultId, operandId );
		case spv::OpLogicalNot:
			return makeInstruction< UnInstructionT< spv::OpLogicalNot > >( returnTypeId, resultId, operandId );
		case spv::OpFNegate:
			return makeInstruction< UnInstructionT< spv::OpFNegate > >( returnTypeId, resultId, operandId );
		case spv::OpSNegate:
			return makeInstruction< UnInstructionT< spv::OpSNegate > >( returnTypeId, resultId, operandId );
		default:
			assert( false && "Unexpected unary operation Op" );
		}

		return nullptr;
	}

	InstructionPtr makeUnInstruction( spv::Id returnTypeId
		, spv::Id resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind typeKind
		, spv::Id operand )
	{
		return makeUnInstruction( getUnOpCode( exprKind, typeKind )
			, returnTypeId
			, resultId
			, operand );
	}

	InstructionPtr makeBinInstruction( spv::Op op
		, spv::Id returnTypeId
		, spv::Id resultId
		, IdList const & operands )
	{
		switch ( op )
		{
		case spv::OpFAdd:
			return makeInstruction< BinInstructionT< spv::OpFAdd > >( returnTypeId, resultId, operands );
		case spv::OpIAdd:
			return makeInstruction< BinInstructionT< spv::OpIAdd > >( returnTypeId, resultId, operands );
		case spv::OpFSub:
			return makeInstruction< BinInstructionT< spv::OpFSub > >( returnTypeId, resultId, operands );
		case spv::OpISub:
			return makeInstruction< BinInstructionT< spv::OpISub > >( returnTypeId, resultId, operands );
		case spv::OpFMul:
			return makeInstruction< BinInstructionT< spv::OpFMul > >( returnTypeId, resultId, operands );
		case spv::OpIMul:
			return makeInstruction< BinInstructionT< spv::OpIMul > >( returnTypeId, resultId, operands );
		case spv::OpFDiv:
			return makeInstruction< BinInstructionT< spv::OpFDiv > >( returnTypeId, resultId, operands );
		case spv::OpSDiv:
			return makeInstruction< BinInstructionT< spv::OpSDiv > >( returnTypeId, resultId, operands );
		case spv::OpUDiv:
			return makeInstruction< BinInstructionT< spv::OpUDiv > >( returnTypeId, resultId, operands );
		case spv::OpFMod:
			return makeInstruction< BinInstructionT< spv::OpFMod > >( returnTypeId, resultId, operands );
		case spv::OpSMod:
			return makeInstruction< BinInstructionT< spv::OpSMod > >( returnTypeId, resultId, operands );
		case spv::OpUMod:
			return makeInstruction< BinInstructionT< spv::OpUMod > >( returnTypeId, resultId, operands );
		case spv::OpMatrixTimesMatrix:
			return makeInstruction< BinInstructionT< spv::OpMatrixTimesMatrix > >( returnTypeId, resultId, operands );
		case spv::OpMatrixTimesVector:
			return makeInstruction< BinInstructionT< spv::OpMatrixTimesVector > >( returnTypeId, resultId, operands );
		case spv::OpMatrixTimesScalar:
			return makeInstruction< BinInstructionT< spv::OpMatrixTimesScalar > >( returnTypeId, resultId, operands );
		case spv::OpVectorTimesScalar:
			return makeInstruction< BinInstructionT< spv::OpVectorTimesScalar > >( returnTypeId, resultId, operands );
		case spv::OpShiftLeftLogical:
			return makeInstruction< BinInstructionT< spv::OpShiftLeftLogical > >( returnTypeId, resultId, operands );
		case spv::OpShiftRightLogical:
			return makeInstruction< BinInstructionT< spv::OpShiftRightLogical > >( returnTypeId, resultId, operands );
		case spv::OpBitwiseAnd:
			return makeInstruction< BinInstructionT< spv::OpBitwiseAnd > >( returnTypeId, resultId, operands );
		case spv::OpNot:
			return makeInstruction< BinInstructionT< spv::OpNot > >( returnTypeId, resultId, operands );
		case spv::OpBitwiseOr:
			return makeInstruction< BinInstructionT< spv::OpBitwiseOr > >( returnTypeId, resultId, operands );
		case spv::OpBitwiseXor:
			return makeInstruction< BinInstructionT< spv::OpBitwiseXor > >( returnTypeId, resultId, operands );
		case spv::OpLogicalAnd:
			return makeInstruction< BinInstructionT< spv::OpLogicalAnd > >( returnTypeId, resultId, operands );
		case spv::OpLogicalOr:
			return makeInstruction< BinInstructionT< spv::OpLogicalOr > >( returnTypeId, resultId, operands );
		case spv::OpStore:
			return makeInstruction< BinInstructionT< spv::OpStore > >( returnTypeId, resultId, operands );
		case spv::OpFOrdEqual:
			return makeInstruction< BinInstructionT< spv::OpFOrdEqual > >( returnTypeId, resultId, operands );
		case spv::OpLogicalEqual:
			return makeInstruction< BinInstructionT< spv::OpLogicalEqual > >( returnTypeId, resultId, operands );
		case spv::OpIEqual:
			return makeInstruction< BinInstructionT< spv::OpIEqual > >( returnTypeId, resultId, operands );
		case spv::OpFOrdNotEqual:
			return makeInstruction< BinInstructionT< spv::OpFOrdNotEqual > >( returnTypeId, resultId, operands );
		case spv::OpLogicalNotEqual:
			return makeInstruction< BinInstructionT< spv::OpLogicalNotEqual > >( returnTypeId, resultId, operands );
		case spv::OpINotEqual:
			return makeInstruction< BinInstructionT< spv::OpINotEqual > >( returnTypeId, resultId, operands );
		case spv::OpFOrdGreaterThan:
			return makeInstruction< BinInstructionT< spv::OpFOrdGreaterThan > >( returnTypeId, resultId, operands );
		case spv::OpSGreaterThan:
			return makeInstruction< BinInstructionT< spv::OpSGreaterThan > >( returnTypeId, resultId, operands );
		case spv::OpUGreaterThan:
			return makeInstruction< BinInstructionT< spv::OpUGreaterThan > >( returnTypeId, resultId, operands );
		case spv::OpFOrdGreaterThanEqual:
			return makeInstruction< BinInstructionT< spv::OpFOrdGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpSGreaterThanEqual:
			return makeInstruction< BinInstructionT< spv::OpSGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpUGreaterThanEqual:
			return makeInstruction< BinInstructionT< spv::OpUGreaterThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpFOrdLessThan:
			return makeInstruction< BinInstructionT< spv::OpFOrdLessThan > >( returnTypeId, resultId, operands );
		case spv::OpSLessThan:
			return makeInstruction< BinInstructionT< spv::OpSLessThan > >( returnTypeId, resultId, operands );
		case spv::OpULessThan:
			return makeInstruction< BinInstructionT< spv::OpULessThan > >( returnTypeId, resultId, operands );
		case spv::OpFOrdLessThanEqual:
			return makeInstruction< BinInstructionT< spv::OpFOrdLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpSLessThanEqual:
			return makeInstruction< BinInstructionT< spv::OpSLessThanEqual > >( returnTypeId, resultId, operands );
		case spv::OpULessThanEqual:
			return makeInstruction< BinInstructionT< spv::OpULessThanEqual > >( returnTypeId, resultId, operands );
		default:
			assert( false && "Unexpected binary operation Op" );
		}

		return nullptr;
	}

	InstructionPtr makeBinInstruction( spv::Id typeId
		, spv::Id resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id lhs
		, spv::Id rhs )
	{
		IdList operands;
		spv::Op opCode;
		getBinOpOperands( exprKind, lhsTypeKind, rhsTypeKind, lhs, rhs, operands, opCode );
		return makeBinInstruction( opCode
			, typeId
			, resultId
			, operands );
	}

	//*************************************************************************
}
