/*
See LICENSE file in root folder
*/
#include "SpirvOpHelpers.hpp"

namespace spirv
{
	//*************************************************************************

	namespace
	{
		bool isFloating( ast::type::Kind kind )
		{
			return kind == ast::type::Kind::eFloat
				|| kind == ast::type::Kind::eDouble
				|| kind == ast::type::Kind::eVec2F
				|| kind == ast::type::Kind::eVec3F
				|| kind == ast::type::Kind::eVec4F
				|| kind == ast::type::Kind::eVec2D
				|| kind == ast::type::Kind::eVec3D
				|| kind == ast::type::Kind::eVec4D
				|| kind == ast::type::Kind::eMat2x2F
				|| kind == ast::type::Kind::eMat2x3F
				|| kind == ast::type::Kind::eMat2x4F
				|| kind == ast::type::Kind::eMat2x2D
				|| kind == ast::type::Kind::eMat2x3D
				|| kind == ast::type::Kind::eMat2x4D
				|| kind == ast::type::Kind::eMat3x2F
				|| kind == ast::type::Kind::eMat3x3F
				|| kind == ast::type::Kind::eMat3x4F
				|| kind == ast::type::Kind::eMat3x2D
				|| kind == ast::type::Kind::eMat3x3D
				|| kind == ast::type::Kind::eMat3x4D
				|| kind == ast::type::Kind::eMat4x2F
				|| kind == ast::type::Kind::eMat4x3F
				|| kind == ast::type::Kind::eMat4x4F
				|| kind == ast::type::Kind::eMat4x2D
				|| kind == ast::type::Kind::eMat4x3D
				|| kind == ast::type::Kind::eMat4x4D;
		}

		bool isSigned( ast::type::Kind kind )
		{
			return kind == ast::type::Kind::eInt
				|| kind == ast::type::Kind::eVec2I
				|| kind == ast::type::Kind::eVec3I
				|| kind == ast::type::Kind::eVec4I;
		}

		bool isUnsigned( ast::type::Kind kind )
		{
			return kind == ast::type::Kind::eUInt
				|| kind == ast::type::Kind::eVec2U
				|| kind == ast::type::Kind::eVec3U
				|| kind == ast::type::Kind::eVec4U;
		}

		bool isBool( ast::type::Kind kind )
		{
			return kind == ast::type::Kind::eBool
				|| kind == ast::type::Kind::eVec2B
				|| kind == ast::type::Kind::eVec3B
				|| kind == ast::type::Kind::eVec4B;
		}
	}

	//*************************************************************************

	uint16_t getOpBaseSize( spv::Op op )
	{
		uint16_t result = 0u;

		switch ( op )
		{
		case spv::OpNop:
		case spv::OpNoLine:
		case spv::OpFunctionEnd:
		case spv::OpKill:
		case spv::OpReturn:
		case spv::OpUnreachable:
		case spv::OpEmitVertex:
		case spv::OpEndPrimitive:
			result = 1u;
			break;
		case spv::OpSourceContinued:
		case spv::OpSourceExtension:
		case spv::OpDecorationGroup:
		case spv::OpGroupDecorate:
		case spv::OpGroupMemberDecorate:
		case spv::OpExtension:
		case spv::OpCapability:
		case spv::OpTypeVoid:
		case spv::OpTypeBool:
		case spv::OpTypeSampler:
		case spv::OpTypeStruct:
		case spv::OpTypeEvent:
		case spv::OpTypeDeviceEvent:
		case spv::OpTypeReserveId:
		case spv::OpTypeQueue:
		case spv::OpLabel:
		case spv::OpBranch:
		case spv::OpReturnValue:
		case spv::OpEmitStreamVertex:
		case spv::OpEndStreamPrimitive:
		case spv::OpTypeNamedBarrier:
		case spv::OpModuleProcessed:
			result = 2u;
			break;
		case spv::OpUndef:
		case spv::OpSource:
		case spv::OpName:
		case spv::OpString:
		case spv::OpDecorate:
		case spv::OpExtInstImport:
		case spv::OpMemoryModel:
		case spv::OpExecutionMode:
		case spv::OpTypeFloat:
		case spv::OpTypeSampledImage:
		case spv::OpTypeRuntimeArray:
		case spv::OpTypeOpaque:
		case spv::OpTypeFunction:
		case spv::OpTypePipe:
		case spv::OpTypeForwardPointer:
		case spv::OpConstantTrue:
		case spv::OpConstantFalse:
		case spv::OpConstant:
		case spv::OpConstantComposite:
		case spv::OpConstantNull:
		case spv::OpSpecConstantTrue:
		case spv::OpSpecConstantFalse:
		case spv::OpSpecConstant:
		case spv::OpSpecConstantComposite:
		case spv::OpStore:
		case spv::OpCopyMemory:
		case spv::OpFunctionParameter:
		case spv::OpCompositeConstruct:
		case spv::OpPhi:
		case spv::OpSelectionMerge:
		case spv::OpSwitch:
		case spv::OpLifetimeStart:
		case spv::OpLifetimeStop:
		case spv::OpMemoryBarrier:
		case spv::OpExecutionModeId:
		case spv::OpDecorateId:
			result = 3u;
			break;
		case spv::OpMemberName:
		case spv::OpLine:
		case spv::OpMemberDecorate:
		case spv::OpEntryPoint:
		case spv::OpTypeInt:
		case spv::OpTypeVector:
		case spv::OpTypeMatrix:
		case spv::OpTypeArray:
		case spv::OpTypePointer:
		case spv::OpSpecConstantOp:
		case spv::OpVariable:
		case spv::OpLoad:
		case spv::OpCopyMemorySized:
		case spv::OpAccessChain:
		case spv::OpInBoundsAccessChain:
		case spv::OpGenericPtrMemSemantics:
		case spv::OpFunctionCall:
		case spv::OpImageWrite:
		case spv::OpImage:
		case spv::OpImageQueryFormat:
		case spv::OpImageQueryOrder:
		case spv::OpImageQuerySize:
		case spv::OpImageQueryLevels:
		case spv::OpImageQuerySamples:
		case spv::OpImageSparseTexelsResident:
		case spv::OpConvertFToU:
		case spv::OpConvertFToS:
		case spv::OpConvertSToF:
		case spv::OpConvertUToF:
		case spv::OpUConvert:
		case spv::OpSConvert:
		case spv::OpFConvert:
		case spv::OpQuantizeToF16:
		case spv::OpConvertPtrToU:
		case spv::OpSatConvertSToU:
		case spv::OpSatConvertUToS:
		case spv::OpConvertUToPtr:
		case spv::OpPtrCastToGeneric:
		case spv::OpGenericCastToPtr:
		case spv::OpBitcast:
		case spv::OpCompositeExtract:
		case spv::OpCopyObject:
		case spv::OpTranspose:
		case spv::OpSNegate:
		case spv::OpFNegate:
		case spv::OpNot:
		case spv::OpBitReverse:
		case spv::OpBitCount:
		case spv::OpAny:
		case spv::OpAll:
		case spv::OpIsNan:
		case spv::OpIsInf:
		case spv::OpIsFinite:
		case spv::OpIsNormal:
		case spv::OpSignBitSet:
		case spv::OpLogicalNot:
		case spv::OpDPdx:
		case spv::OpDPdy:
		case spv::OpFwidth:
		case spv::OpDPdxFine:
		case spv::OpDPdyFine:
		case spv::OpFwidthFine:
		case spv::OpDPdxCoarse:
		case spv::OpDPdyCoarse:
		case spv::OpFwidthCoarse:
		case spv::OpLoopMerge:
		case spv::OpBranchConditional:
		case spv::OpAtomicFlagClear:
		case spv::OpControlBarrier:
		case spv::OpGroupWaitEvents:
		case spv::OpSizeOf:
		case spv::OpNamedBarrierInitialize:
		case spv::OpMemoryNamedBarrier:
			result = 4u;
			break;
		case spv::OpExtInst:
		case spv::OpPtrAccessChain:
		case spv::OpArrayLength:
		case spv::OpInBoundsPtrAccessChain:
		case spv::OpFunction:
		case spv::OpSampledImage:
		case spv::OpImageSampleImplicitLod:
		case spv::OpImageSampleProjImplicitLod:
		case spv::OpImageFetch:
		case spv::OpImageRead:
		case spv::OpImageQuerySizeLod:
		case spv::OpImageQueryLod:
		case spv::OpImageSparseSampleImplicitLod:
		case spv::OpImageSparseSampleProjImplicitLod:
		case spv::OpImageSparseFetch:
		case spv::OpImageSparseRead:
		case spv::OpGenericCastToPtrExplicit:
		case spv::OpVectorExtractDynamic:
		case spv::OpVectorShuffle:
		case spv::OpCompositeInsert:
		case spv::OpIAdd:
		case spv::OpFAdd:
		case spv::OpISub:
		case spv::OpFSub:
		case spv::OpIMul:
		case spv::OpFMul:
		case spv::OpUDiv:
		case spv::OpSDiv:
		case spv::OpFDiv:
		case spv::OpUMod:
		case spv::OpSRem:
		case spv::OpSMod:
		case spv::OpFRem:
		case spv::OpFMod:
		case spv::OpVectorTimesScalar:
		case spv::OpMatrixTimesScalar:
		case spv::OpVectorTimesMatrix:
		case spv::OpMatrixTimesVector:
		case spv::OpMatrixTimesMatrix:
		case spv::OpOuterProduct:
		case spv::OpDot:
		case spv::OpIAddCarry:
		case spv::OpISubBorrow:
		case spv::OpUMulExtended:
		case spv::OpSMulExtended:
		case spv::OpShiftRightLogical:
		case spv::OpShiftRightArithmetic:
		case spv::OpShiftLeftLogical:
		case spv::OpBitwiseOr:
		case spv::OpBitwiseXor:
		case spv::OpBitwiseAnd:
		case spv::OpLessOrGreater:
		case spv::OpOrdered:
		case spv::OpUnordered:
		case spv::OpLogicalEqual:
		case spv::OpLogicalNotEqual:
		case spv::OpLogicalOr:
		case spv::OpLogicalAnd:
		case spv::OpIEqual:
		case spv::OpINotEqual:
		case spv::OpUGreaterThan:
		case spv::OpSGreaterThan:
		case spv::OpUGreaterThanEqual:
		case spv::OpSGreaterThanEqual:
		case spv::OpULessThan:
		case spv::OpSLessThan:
		case spv::OpULessThanEqual:
		case spv::OpSLessThanEqual:
		case spv::OpFOrdEqual:
		case spv::OpFUnordEqual:
		case spv::OpFOrdNotEqual:
		case spv::OpFUnordNotEqual:
		case spv::OpFOrdLessThan:
		case spv::OpFUnordLessThan:
		case spv::OpFOrdGreaterThan:
		case spv::OpFUnordGreaterThan:
		case spv::OpFOrdLessThanEqual:
		case spv::OpFUnordLessThanEqual:
		case spv::OpFOrdGreaterThanEqual:
		case spv::OpFUnordGreaterThanEqual:
		case spv::OpAtomicStore:
		case spv::OpGroupAll:
		case spv::OpGroupAny:
			result = 5u;
			break;
		case spv::OpConstantSampler:
		case spv::OpImageTexelPointer:
		case spv::OpImageSampleDrefImplicitLod:
		case spv::OpImageSampleProjDrefImplicitLod:
		case spv::OpImageGather:
		case spv::OpImageDrefGather:
		case spv::OpImageSparseSampleDrefImplicitLod:
		case spv::OpImageSparseSampleProjDrefImplicitLod:
		case spv::OpImageSparseGather:
		case spv::OpImageSparseDrefGather:
		case spv::OpVectorInsertDynamic:
		case spv::OpBitFieldSExtract:
		case spv::OpBitFieldUExtract:
		case spv::OpSelect:
		case spv::OpAtomicLoad:
		case spv::OpAtomicIIncrement:
		case spv::OpAtomicIDecrement:
		case spv::OpAtomicFlagTestAndSet:
		case spv::OpGroupBroadcast:
		case spv::OpGroupIAdd:
		case spv::OpGroupFAdd:
		case spv::OpGroupFMin:
		case spv::OpGroupUMin:
		case spv::OpGroupSMin:
		case spv::OpGroupFMax:
		case spv::OpGroupUMax:
		case spv::OpGroupSMax:
			result = 6u;
			break;
		case spv::OpImageSampleExplicitLod:
		case spv::OpImageSampleProjExplicitLod:
		case spv::OpImageSparseSampleExplicitLod:
		case spv::OpImageSparseSampleProjExplicitLod:
		case spv::OpBitFieldInsert:
		case spv::OpAtomicExchange:
		case spv::OpAtomicIAdd:
		case spv::OpAtomicISub:
		case spv::OpAtomicSMin:
		case spv::OpAtomicUMin:
		case spv::OpAtomicSMax:
		case spv::OpAtomicUMax:
		case spv::OpAtomicAnd:
		case spv::OpAtomicOr:
		case spv::OpAtomicXor:
			result = 7u;
			break;
		case spv::OpImageSampleDrefExplicitLod:
		case spv::OpImageSampleProjDrefExplicitLod:
		case spv::OpImageSparseSampleDrefExplicitLod:
		case spv::OpImageSparseSampleProjDrefExplicitLod:
			result = 8u;
			break;
		case spv::OpTypeImage:
		case spv::OpAtomicCompareExchange:
		case spv::OpAtomicCompareExchangeWeak:
		case spv::OpGroupAsyncCopy:
			result = 9u;
			break;

			///////////////////////////////////////////////////////////////
			// Kernels
			///////////////////////////////////////////////////////////////

		case spv::OpRetainEvent:
		case spv::OpReleaseEvent:
		case spv::OpTypePipeStorage:
			result = 2u;
			break;
		case spv::OpCreateUserEvent:
		case spv::OpSetUserEventStatus:
		case spv::OpGetDefaultQueue:
			result = 3u;
			break;
		case spv::OpIsValidEvent:
		case spv::OpCaptureEventProfilingInfo:
		case spv::OpIsValidReserveId:
		case spv::OpCreatePipeFromPipeStorage:
			result = 4u;
			break;
		case spv::OpCommitReadPipe:
		case spv::OpCommitWritePipe:
			result = 5u;
			break;
		case spv::OpBuildNDRange:
		case spv::OpGetNumPipePackets:
		case spv::OpGetMaxPipePackets:
		case spv::OpGroupCommitReadPipe:
		case spv::OpGroupCommitWritePipe:
		case spv::OpConstantPipeStorage:
			result = 6u;
			break;
		case spv::OpEnqueueMarker:
		case spv::OpGetKernelWorkGroupSize:
		case spv::OpGetKernelPreferredWorkGroupSizeMultiple:
		case spv::OpReadPipe:
		case spv::OpWritePipe:
		case spv::OpReserveReadPipePackets:
		case spv::OpReserveWritePipePackets:
		case spv::OpGetKernelMaxNumSubgroups:
			result = 7u;
			break;
		case spv::OpGetKernelNDrangeSubGroupCount:
		case spv::OpGetKernelNDrangeMaxSubGroupSize:
		case spv::OpGroupReserveReadPipePackets:
		case spv::OpGroupReserveWritePipePackets:
		case spv::OpGetKernelLocalSizeForSubgroupCount:
			result = 8u;
			break;
		case spv::OpReservedReadPipe:
		case spv::OpReservedWritePipe:
			result = 9u;
			break;
		case spv::OpEnqueueKernel:
			result = 13u;
			break;

			///////////////////////////////////////////////////////////////
			// Extensions
			///////////////////////////////////////////////////////////////

		case spv::OpSubgroupBlockWriteINTEL:
		case spv::OpDecorateStringGOOGLE:
			result = 3u;
			break;
		case spv::OpSubgroupBallotKHR:
		case spv::OpSubgroupFirstInvocationKHR:
		case spv::OpSubgroupAllKHR:
		case spv::OpSubgroupAnyKHR:
		case spv::OpSubgroupAllEqualKHR:
		case spv::OpSubgroupBlockReadINTEL:
		case spv::OpSubgroupImageBlockWriteINTEL:
		case spv::OpMemberDecorateStringGOOGLE:
			result = 4u;
			break;
		case spv::OpSubgroupReadInvocationKHR:
		case spv::OpFragmentMaskFetchAMD:
		case spv::OpSubgroupShuffleINTEL:
		case spv::OpSubgroupShuffleXorINTEL:
		case spv::OpSubgroupImageBlockReadINTEL:
			result = 5u;
			break;
		case spv::OpGroupIAddNonUniformAMD:
		case spv::OpGroupFAddNonUniformAMD:
		case spv::OpGroupFMinNonUniformAMD:
		case spv::OpGroupUMinNonUniformAMD:
		case spv::OpGroupSMinNonUniformAMD:
		case spv::OpGroupFMaxNonUniformAMD:
		case spv::OpGroupUMaxNonUniformAMD:
		case spv::OpGroupSMaxNonUniformAMD:
		case spv::OpFragmentFetchAMD:
		case spv::OpSubgroupShuffleDownINTEL:
		case spv::OpSubgroupShuffleUpINTEL:
			result = 6u;
			break;
		}

		assert( result != 0u );
		return result;
	}

	std::string getOpName( spv::Op op )
	{
		std::string result;

		switch ( op )
		{
		case spv::OpNop:
			result = "OpNop";
			break;
		case spv::OpUndef:
			result = "OpUndef";
			break;
		case spv::OpSourceContinued:
			result = "OpSourceContinued";
			break;
		case spv::OpSource:
			result = "OpSource";
			break;
		case spv::OpSourceExtension:
			result = "OpSourceExtension";
			break;
		case spv::OpName:
			result = "OpName";
			break;
		case spv::OpMemberName:
			result = "OpMemberName";
			break;
		case spv::OpString:
			result = "OpString";
			break;
		case spv::OpLine:
			result = "OpLine";
			break;
		case spv::OpExtension:
			result = "OpExtension";
			break;
		case spv::OpExtInstImport:
			result = "OpExtInstImport";
			break;
		case spv::OpExtInst:
			result = "OpExtInst";
			break;
		case spv::OpMemoryModel:
			result = "OpMemoryModel";
			break;
		case spv::OpEntryPoint:
			result = "OpEntryPoint";
			break;
		case spv::OpExecutionMode:
			result = "OpExecutionMode";
			break;
		case spv::OpCapability:
			result = "OpCapability";
			break;
		case spv::OpTypeVoid:
			result = "OpTypeVoid";
			break;
		case spv::OpTypeBool:
			result = "OpTypeBool";
			break;
		case spv::OpTypeInt:
			result = "OpTypeInt";
			break;
		case spv::OpTypeFloat:
			result = "OpTypeFloat";
			break;
		case spv::OpTypeVector:
			result = "OpTypeVector";
			break;
		case spv::OpTypeMatrix:
			result = "OpTypeMatrix";
			break;
		case spv::OpTypeImage:
			result = "OpTypeImage";
			break;
		case spv::OpTypeSampler:
			result = "OpTypeSampler";
			break;
		case spv::OpTypeSampledImage:
			result = "OpTypeSampledImage";
			break;
		case spv::OpTypeArray:
			result = "OpTypeArray";
			break;
		case spv::OpTypeRuntimeArray:
			result = "OpTypeRuntimeArray";
			break;
		case spv::OpTypeStruct:
			result = "OpTypeStruct";
			break;
		case spv::OpTypeOpaque:
			result = "OpTypeOpaque";
			break;
		case spv::OpTypePointer:
			result = "OpTypePointer";
			break;
		case spv::OpTypeFunction:
			result = "OpTypeFunction";
			break;
		case spv::OpTypeEvent:
			result = "OpTypeEvent";
			break;
		case spv::OpTypeDeviceEvent:
			result = "OpTypeDeviceEvent";
			break;
		case spv::OpTypeReserveId:
			result = "OpTypeReserveId";
			break;
		case spv::OpTypeQueue:
			result = "OpTypeQueue";
			break;
		case spv::OpTypePipe:
			result = "OpTypePipe";
			break;
		case spv::OpTypeForwardPointer:
			result = "OpTypeForwardPointer";
			break;
		case spv::OpConstantTrue:
			result = "OpConstantTrue";
			break;
		case spv::OpConstantFalse:
			result = "OpConstantFalse";
			break;
		case spv::OpConstant:
			result = "OpConstant";
			break;
		case spv::OpConstantComposite:
			result = "OpConstantComposite";
			break;
		case spv::OpConstantSampler:
			result = "OpConstantSampler";
			break;
		case spv::OpConstantNull:
			result = "OpConstantNull";
			break;
		case spv::OpSpecConstantTrue:
			result = "OpSpecConstantTrue";
			break;
		case spv::OpSpecConstantFalse:
			result = "OpSpecConstantFalse";
			break;
		case spv::OpSpecConstant:
			result = "OpSpecConstant";
			break;
		case spv::OpSpecConstantComposite:
			result = "OpSpecConstantComposite";
			break;
		case spv::OpSpecConstantOp:
			result = "OpSpecConstantOp";
			break;
		case spv::OpFunction:
			result = "OpFunction";
			break;
		case spv::OpFunctionParameter:
			result = "OpFunctionParameter";
			break;
		case spv::OpFunctionEnd:
			result = "OpFunctionEnd";
			break;
		case spv::OpFunctionCall:
			result = "OpFunctionCall";
			break;
		case spv::OpVariable:
			result = "OpVariable";
			break;
		case spv::OpImageTexelPointer:
			result = "OpImageTexelPointer";
			break;
		case spv::OpLoad:
			result = "OpLoad";
			break;
		case spv::OpStore:
			result = "OpStore";
			break;
		case spv::OpCopyMemory:
			result = "OpCopyMemory";
			break;
		case spv::OpCopyMemorySized:
			result = "OpCopyMemorySized";
			break;
		case spv::OpAccessChain:
			result = "OpAccessChain";
			break;
		case spv::OpInBoundsAccessChain:
			result = "OpInBoundsAccessChain";
			break;
		case spv::OpPtrAccessChain:
			result = "OpPtrAccessChain";
			break;
		case spv::OpArrayLength:
			result = "OpArrayLength";
			break;
		case spv::OpGenericPtrMemSemantics:
			result = "OpGenericPtrMemSemantics";
			break;
		case spv::OpInBoundsPtrAccessChain:
			result = "OpInBoundsPtrAccessChain";
			break;
		case spv::OpDecorate:
			result = "OpDecorate";
			break;
		case spv::OpMemberDecorate:
			result = "OpMemberDecorate";
			break;
		case spv::OpDecorationGroup:
			result = "OpDecorationGroup";
			break;
		case spv::OpGroupDecorate:
			result = "OpGroupDecorate";
			break;
		case spv::OpGroupMemberDecorate:
			result = "OpGroupMemberDecorate";
			break;
		case spv::OpVectorExtractDynamic:
			result = "OpVectorExtractDynamic";
			break;
		case spv::OpVectorInsertDynamic:
			result = "OpVectorInsertDynamic";
			break;
		case spv::OpVectorShuffle:
			result = "OpVectorShuffle";
			break;
		case spv::OpCompositeConstruct:
			result = "OpCompositeConstruct";
			break;
		case spv::OpCompositeExtract:
			result = "OpCompositeExtract";
			break;
		case spv::OpCompositeInsert:
			result = "OpCompositeInsert";
			break;
		case spv::OpCopyObject:
			result = "OpCopyObject";
			break;
		case spv::OpTranspose:
			result = "OpTranspose";
			break;
		case spv::OpSampledImage:
			result = "OpSampledImage";
			break;
		case spv::OpImageSampleImplicitLod:
			result = "OpImageSampleImplicitLod";
			break;
		case spv::OpImageSampleExplicitLod:
			result = "OpImageSampleExplicitLod";
			break;
		case spv::OpImageSampleDrefImplicitLod:
			result = "OpImageSampleDrefImplicitLod";
			break;
		case spv::OpImageSampleDrefExplicitLod:
			result = "OpImageSampleDrefExplicitLod";
			break;
		case spv::OpImageSampleProjImplicitLod:
			result = "OpImageSampleProjImplicitLod";
			break;
		case spv::OpImageSampleProjExplicitLod:
			result = "OpImageSampleProjExplicitLod";
			break;
		case spv::OpImageSampleProjDrefImplicitLod:
			result = "OpImageSampleProjDrefImplicitLod";
			break;
		case spv::OpImageSampleProjDrefExplicitLod:
			result = "OpImageSampleProjDrefExplicitLod";
			break;
		case spv::OpImageFetch:
			result = "OpImageFetch";
			break;
		case spv::OpImageGather:
			result = "OpImageGather";
			break;
		case spv::OpImageDrefGather:
			result = "OpImageDrefGather";
			break;
		case spv::OpImageRead:
			result = "OpImageRead";
			break;
		case spv::OpImageWrite:
			result = "OpImageWrite";
			break;
		case spv::OpImage:
			result = "OpImage";
			break;
		case spv::OpImageQueryFormat:
			result = "OpImageQueryFormat";
			break;
		case spv::OpImageQueryOrder:
			result = "OpImageQueryOrder";
			break;
		case spv::OpImageQuerySizeLod:
			result = "OpImageQuerySizeLod";
			break;
		case spv::OpImageQuerySize:
			result = "OpImageQuerySize";
			break;
		case spv::OpImageQueryLod:
			result = "OpImageQueryLod";
			break;
		case spv::OpImageQueryLevels:
			result = "OpImageQueryLevels";
			break;
		case spv::OpImageQuerySamples:
			result = "OpImageQuerySamples";
			break;
		case spv::OpConvertFToU:
			result = "OpConvertFToU";
			break;
		case spv::OpConvertFToS:
			result = "OpConvertFToS";
			break;
		case spv::OpConvertSToF:
			result = "OpConvertSToF";
			break;
		case spv::OpConvertUToF:
			result = "OpConvertUToF";
			break;
		case spv::OpUConvert:
			result = "OpUConvert";
			break;
		case spv::OpSConvert:
			result = "OpSConvert";
			break;
		case spv::OpFConvert:
			result = "OpFConvert";
			break;
		case spv::OpQuantizeToF16:
			result = "OpQuantizeToF16";
			break;
		case spv::OpConvertPtrToU:
			result = "OpConvertPtrToU";
			break;
		case spv::OpSatConvertSToU:
			result = "OpSatConvertSToU";
			break;
		case spv::OpSatConvertUToS:
			result = "OpSatConvertUToS";
			break;
		case spv::OpConvertUToPtr:
			result = "OpConvertUToPtr";
			break;
		case spv::OpPtrCastToGeneric:
			result = "OpPtrCastToGeneric";
			break;
		case spv::OpGenericCastToPtr:
			result = "OpGenericCastToPtr";
			break;
		case spv::OpGenericCastToPtrExplicit:
			result = "OpGenericCastToPtrExplicit";
			break;
		case spv::OpBitcast:
			result = "OpBitcast";
			break;
		case spv::OpSNegate:
			result = "OpSNegate";
			break;
		case spv::OpFNegate:
			result = "OpFNegate";
			break;
		case spv::OpIAdd:
			result = "OpIAdd";
			break;
		case spv::OpFAdd:
			result = "OpFAdd";
			break;
		case spv::OpISub:
			result = "OpISub";
			break;
		case spv::OpFSub:
			result = "OpFSub";
			break;
		case spv::OpIMul:
			result = "OpIMul";
			break;
		case spv::OpFMul:
			result = "OpFMul";
			break;
		case spv::OpUDiv:
			result = "OpUDiv";
			break;
		case spv::OpSDiv:
			result = "OpSDiv";
			break;
		case spv::OpFDiv:
			result = "OpFDiv";
			break;
		case spv::OpUMod:
			result = "OpUMod";
			break;
		case spv::OpSRem:
			result = "OpSRem";
			break;
		case spv::OpSMod:
			result = "OpSMod";
			break;
		case spv::OpFRem:
			result = "OpFRem";
			break;
		case spv::OpFMod:
			result = "OpFMod";
			break;
		case spv::OpVectorTimesScalar:
			result = "OpVectorTimesScalar";
			break;
		case spv::OpMatrixTimesScalar:
			result = "OpMatrixTimesScalar";
			break;
		case spv::OpVectorTimesMatrix:
			result = "OpVectorTimesMatrix";
			break;
		case spv::OpMatrixTimesVector:
			result = "OpMatrixTimesVector";
			break;
		case spv::OpMatrixTimesMatrix:
			result = "OpMatrixTimesMatrix";
			break;
		case spv::OpOuterProduct:
			result = "OpOuterProduct";
			break;
		case spv::OpDot:
			result = "OpDot";
			break;
		case spv::OpIAddCarry:
			result = "OpIAddCarry";
			break;
		case spv::OpISubBorrow:
			result = "OpISubBorrow";
			break;
		case spv::OpUMulExtended:
			result = "OpUMulExtended";
			break;
		case spv::OpSMulExtended:
			result = "OpSMulExtended";
			break;
		case spv::OpAny:
			result = "OpAny";
			break;
		case spv::OpAll:
			result = "OpAll";
			break;
		case spv::OpIsNan:
			result = "OpIsNan";
			break;
		case spv::OpIsInf:
			result = "OpIsInf";
			break;
		case spv::OpIsFinite:
			result = "OpIsFinite";
			break;
		case spv::OpIsNormal:
			result = "OpIsNormal";
			break;
		case spv::OpSignBitSet:
			result = "OpSignBitSet";
			break;
		case spv::OpLessOrGreater:
			result = "OpLessOrGreater";
			break;
		case spv::OpOrdered:
			result = "OpOrdered";
			break;
		case spv::OpUnordered:
			result = "OpUnordered";
			break;
		case spv::OpLogicalEqual:
			result = "OpLogicalEqual";
			break;
		case spv::OpLogicalNotEqual:
			result = "OpLogicalNotEqual";
			break;
		case spv::OpLogicalOr:
			result = "OpLogicalOr";
			break;
		case spv::OpLogicalAnd:
			result = "OpLogicalAnd";
			break;
		case spv::OpLogicalNot:
			result = "OpLogicalNot";
			break;
		case spv::OpSelect:
			result = "OpSelect";
			break;
		case spv::OpIEqual:
			result = "OpIEqual";
			break;
		case spv::OpINotEqual:
			result = "OpINotEqual";
			break;
		case spv::OpUGreaterThan:
			result = "OpUGreaterThan";
			break;
		case spv::OpSGreaterThan:
			result = "OpSGreaterThan";
			break;
		case spv::OpUGreaterThanEqual:
			result = "OpUGreaterThanEqual";
			break;
		case spv::OpSGreaterThanEqual:
			result = "OpSGreaterThanEqual";
			break;
		case spv::OpULessThan:
			result = "OpULessThan";
			break;
		case spv::OpSLessThan:
			result = "OpSLessThan";
			break;
		case spv::OpULessThanEqual:
			result = "OpULessThanEqual";
			break;
		case spv::OpSLessThanEqual:
			result = "OpSLessThanEqual";
			break;
		case spv::OpFOrdEqual:
			result = "OpFOrdEqual";
			break;
		case spv::OpFUnordEqual:
			result = "OpFUnordEqual";
			break;
		case spv::OpFOrdNotEqual:
			result = "OpFOrdNotEqual";
			break;
		case spv::OpFUnordNotEqual:
			result = "OpFUnordNotEqual";
			break;
		case spv::OpFOrdLessThan:
			result = "OpFOrdLessThan";
			break;
		case spv::OpFUnordLessThan:
			result = "OpFUnordLessThan";
			break;
		case spv::OpFOrdGreaterThan:
			result = "OpFOrdGreaterThan";
			break;
		case spv::OpFUnordGreaterThan:
			result = "OpFUnordGreaterThan";
			break;
		case spv::OpFOrdLessThanEqual:
			result = "OpFOrdLessThanEqual";
			break;
		case spv::OpFUnordLessThanEqual:
			result = "OpFUnordLessThanEqual";
			break;
		case spv::OpFOrdGreaterThanEqual:
			result = "OpFOrdGreaterThanEqual";
			break;
		case spv::OpFUnordGreaterThanEqual:
			result = "OpFUnordGreaterThanEqual";
			break;
		case spv::OpShiftRightLogical:
			result = "OpShiftRightLogical";
			break;
		case spv::OpShiftRightArithmetic:
			result = "OpShiftRightArithmetic";
			break;
		case spv::OpShiftLeftLogical:
			result = "OpShiftLeftLogical";
			break;
		case spv::OpBitwiseOr:
			result = "OpBitwiseOr";
			break;
		case spv::OpBitwiseXor:
			result = "OpBitwiseXor";
			break;
		case spv::OpBitwiseAnd:
			result = "OpBitwiseAnd";
			break;
		case spv::OpNot:
			result = "OpNot";
			break;
		case spv::OpBitFieldInsert:
			result = "OpBitFieldInsert";
			break;
		case spv::OpBitFieldSExtract:
			result = "OpBitFieldSExtract";
			break;
		case spv::OpBitFieldUExtract:
			result = "OpBitFieldUExtract";
			break;
		case spv::OpBitReverse:
			result = "OpBitReverse";
			break;
		case spv::OpBitCount:
			result = "OpBitCount";
			break;
		case spv::OpDPdx:
			result = "OpDPdx";
			break;
		case spv::OpDPdy:
			result = "OpDPdy";
			break;
		case spv::OpFwidth:
			result = "OpFwidth";
			break;
		case spv::OpDPdxFine:
			result = "OpDPdxFine";
			break;
		case spv::OpDPdyFine:
			result = "OpDPdyFine";
			break;
		case spv::OpFwidthFine:
			result = "OpFwidthFine";
			break;
		case spv::OpDPdxCoarse:
			result = "OpDPdxCoarse";
			break;
		case spv::OpDPdyCoarse:
			result = "OpDPdyCoarse";
			break;
		case spv::OpFwidthCoarse:
			result = "OpFwidthCoarse";
			break;
		case spv::OpEmitVertex:
			result = "OpEmitVertex";
			break;
		case spv::OpEndPrimitive:
			result = "OpEndPrimitive";
			break;
		case spv::OpEmitStreamVertex:
			result = "OpEmitStreamVertex";
			break;
		case spv::OpEndStreamPrimitive:
			result = "OpEndStreamPrimitive";
			break;
		case spv::OpControlBarrier:
			result = "OpControlBarrier";
			break;
		case spv::OpMemoryBarrier:
			result = "OpMemoryBarrier";
			break;
		case spv::OpAtomicLoad:
			result = "OpAtomicLoad";
			break;
		case spv::OpAtomicStore:
			result = "OpAtomicStore";
			break;
		case spv::OpAtomicExchange:
			result = "OpAtomicExchange";
			break;
		case spv::OpAtomicCompareExchange:
			result = "OpAtomicCompareExchange";
			break;
		case spv::OpAtomicCompareExchangeWeak:
			result = "OpAtomicCompareExchangeWeak";
			break;
		case spv::OpAtomicIIncrement:
			result = "OpAtomicIIncrement";
			break;
		case spv::OpAtomicIDecrement:
			result = "OpAtomicIDecrement";
			break;
		case spv::OpAtomicIAdd:
			result = "OpAtomicIAdd";
			break;
		case spv::OpAtomicISub:
			result = "OpAtomicISub";
			break;
		case spv::OpAtomicSMin:
			result = "OpAtomicSMin";
			break;
		case spv::OpAtomicUMin:
			result = "OpAtomicUMin";
			break;
		case spv::OpAtomicSMax:
			result = "OpAtomicSMax";
			break;
		case spv::OpAtomicUMax:
			result = "OpAtomicUMax";
			break;
		case spv::OpAtomicAnd:
			result = "OpAtomicAnd";
			break;
		case spv::OpAtomicOr:
			result = "OpAtomicOr";
			break;
		case spv::OpAtomicXor:
			result = "OpAtomicXor";
			break;
		case spv::OpPhi:
			result = "OpPhi";
			break;
		case spv::OpLoopMerge:
			result = "OpLoopMerge";
			break;
		case spv::OpSelectionMerge:
			result = "OpSelectionMerge";
			break;
		case spv::OpLabel:
			result = "OpLabel";
			break;
		case spv::OpBranch:
			result = "OpBranch";
			break;
		case spv::OpBranchConditional:
			result = "OpBranchConditional";
			break;
		case spv::OpSwitch:
			result = "OpSwitch";
			break;
		case spv::OpKill:
			result = "OpKill";
			break;
		case spv::OpReturn:
			result = "OpReturn";
			break;
		case spv::OpReturnValue:
			result = "OpReturnValue";
			break;
		case spv::OpUnreachable:
			result = "OpUnreachable";
			break;
		case spv::OpLifetimeStart:
			result = "OpLifetimeStart";
			break;
		case spv::OpLifetimeStop:
			result = "OpLifetimeStop";
			break;
		case spv::OpGroupAsyncCopy:
			result = "OpGroupAsyncCopy";
			break;
		case spv::OpGroupWaitEvents:
			result = "OpGroupWaitEvents";
			break;
		case spv::OpGroupAll:
			result = "OpGroupAll";
			break;
		case spv::OpGroupAny:
			result = "OpGroupAny";
			break;
		case spv::OpGroupBroadcast:
			result = "OpGroupBroadcast";
			break;
		case spv::OpGroupIAdd:
			result = "OpGroupIAdd";
			break;
		case spv::OpGroupFAdd:
			result = "OpGroupFAdd";
			break;
		case spv::OpGroupFMin:
			result = "OpGroupFMin";
			break;
		case spv::OpGroupUMin:
			result = "OpGroupUMin";
			break;
		case spv::OpGroupSMin:
			result = "OpGroupSMin";
			break;
		case spv::OpGroupFMax:
			result = "OpGroupFMax";
			break;
		case spv::OpGroupUMax:
			result = "OpGroupUMax";
			break;
		case spv::OpGroupSMax:
			result = "OpGroupSMax";
			break;
		case spv::OpReadPipe:
			result = "OpReadPipe";
			break;
		case spv::OpWritePipe:
			result = "OpWritePipe";
			break;
		case spv::OpReservedReadPipe:
			result = "OpReservedReadPipe";
			break;
		case spv::OpReservedWritePipe:
			result = "OpReservedWritePipe";
			break;
		case spv::OpReserveReadPipePackets:
			result = "OpReserveReadPipePackets";
			break;
		case spv::OpReserveWritePipePackets:
			result = "OpReserveWritePipePackets";
			break;
		case spv::OpCommitReadPipe:
			result = "OpCommitReadPipe";
			break;
		case spv::OpCommitWritePipe:
			result = "OpCommitWritePipe";
			break;
		case spv::OpIsValidReserveId:
			result = "OpIsValidReserveId";
			break;
		case spv::OpGetNumPipePackets:
			result = "OpGetNumPipePackets";
			break;
		case spv::OpGetMaxPipePackets:
			result = "OpGetMaxPipePackets";
			break;
		case spv::OpGroupReserveReadPipePackets:
			result = "OpGroupReserveReadPipePackets";
			break;
		case spv::OpGroupReserveWritePipePackets:
			result = "OpGroupReserveWritePipePackets";
			break;
		case spv::OpGroupCommitReadPipe:
			result = "OpGroupCommitReadPipe";
			break;
		case spv::OpGroupCommitWritePipe:
			result = "OpGroupCommitWritePipe";
			break;
		case spv::OpEnqueueMarker:
			result = "OpEnqueueMarker";
			break;
		case spv::OpEnqueueKernel:
			result = "OpEnqueueKernel";
			break;
		case spv::OpGetKernelNDrangeSubGroupCount:
			result = "OpGetKernelNDrangeSubGroupCount";
			break;
		case spv::OpGetKernelNDrangeMaxSubGroupSize:
			result = "OpGetKernelNDrangeMaxSubGroupSize";
			break;
		case spv::OpGetKernelWorkGroupSize:
			result = "OpGetKernelWorkGroupSize";
			break;
		case spv::OpGetKernelPreferredWorkGroupSizeMultiple:
			result = "OpGetKernelPreferredWorkGroupSizeMultiple";
			break;
		case spv::OpRetainEvent:
			result = "OpRetainEvent";
			break;
		case spv::OpReleaseEvent:
			result = "OpReleaseEvent";
			break;
		case spv::OpCreateUserEvent:
			result = "OpCreateUserEvent";
			break;
		case spv::OpIsValidEvent:
			result = "OpIsValidEvent";
			break;
		case spv::OpSetUserEventStatus:
			result = "OpSetUserEventStatus";
			break;
		case spv::OpCaptureEventProfilingInfo:
			result = "OpCaptureEventProfilingInfo";
			break;
		case spv::OpGetDefaultQueue:
			result = "OpGetDefaultQueue";
			break;
		case spv::OpBuildNDRange:
			result = "OpBuildNDRange";
			break;
		case spv::OpImageSparseSampleImplicitLod:
			result = "OpImageSparseSampleImplicitLod";
			break;
		case spv::OpImageSparseSampleExplicitLod:
			result = "OpImageSparseSampleExplicitLod";
			break;
		case spv::OpImageSparseSampleDrefImplicitLod:
			result = "OpImageSparseSampleDrefImplicitLod";
			break;
		case spv::OpImageSparseSampleDrefExplicitLod:
			result = "OpImageSparseSampleDrefExplicitLod";
			break;
		case spv::OpImageSparseSampleProjImplicitLod:
			result = "OpImageSparseSampleProjImplicitLod";
			break;
		case spv::OpImageSparseSampleProjExplicitLod:
			result = "OpImageSparseSampleProjExplicitLod";
			break;
		case spv::OpImageSparseSampleProjDrefImplicitLod:
			result = "OpImageSparseSampleProjDrefImplicitLod";
			break;
		case spv::OpImageSparseSampleProjDrefExplicitLod:
			result = "OpImageSparseSampleProjDrefExplicitLod";
			break;
		case spv::OpImageSparseFetch:
			result = "OpImageSparseFetch";
			break;
		case spv::OpImageSparseGather:
			result = "OpImageSparseGather";
			break;
		case spv::OpImageSparseDrefGather:
			result = "OpImageSparseDrefGather";
			break;
		case spv::OpImageSparseTexelsResident:
			result = "OpImageSparseTexelsResident";
			break;
		case spv::OpNoLine:
			result = "OpNoLine";
			break;
		case spv::OpAtomicFlagTestAndSet:
			result = "OpAtomicFlagTestAndSet";
			break;
		case spv::OpAtomicFlagClear:
			result = "OpAtomicFlagClear";
			break;
		case spv::OpImageSparseRead:
			result = "OpImageSparseRead";
			break;
		case spv::OpSizeOf:
			result = "OpSizeOf";
			break;
		case spv::OpTypePipeStorage:
			result = "OpTypePipeStorage";
			break;
		case spv::OpConstantPipeStorage:
			result = "OpConstantPipeStorage";
			break;
		case spv::OpCreatePipeFromPipeStorage:
			result = "OpCreatePipeFromPipeStorage";
			break;
		case spv::OpGetKernelLocalSizeForSubgroupCount:
			result = "OpGetKernelLocalSizeForSubgroupCount";
			break;
		case spv::OpGetKernelMaxNumSubgroups:
			result = "OpGetKernelMaxNumSubgroups";
			break;
		case spv::OpTypeNamedBarrier:
			result = "OpTypeNamedBarrier";
			break;
		case spv::OpNamedBarrierInitialize:
			result = "OpNamedBarrierInitialize";
			break;
		case spv::OpMemoryNamedBarrier:
			result = "OpMemoryNamedBarrier";
			break;
		case spv::OpModuleProcessed:
			result = "OpModuleProcessed";
			break;
		case spv::OpExecutionModeId:
			result = "OpExecutionModeId";
			break;
		case spv::OpDecorateId:
			result = "OpDecorateId";
			break;
		case spv::OpSubgroupBallotKHR:
			result = "OpSubgroupBallotKHR";
			break;
		case spv::OpSubgroupFirstInvocationKHR:
			result = "OpSubgroupFirstInvocationKHR";
			break;
		case spv::OpSubgroupAllKHR:
			result = "OpSubgroupAllKHR";
			break;
		case spv::OpSubgroupAnyKHR:
			result = "OpSubgroupAnyKHR";
			break;
		case spv::OpSubgroupAllEqualKHR:
			result = "OpSubgroupAllEqualKHR";
			break;
		case spv::OpSubgroupReadInvocationKHR:
			result = "OpSubgroupReadInvocationKHR";
			break;
		case spv::OpGroupIAddNonUniformAMD:
			result = "OpGroupIAddNonUniformAMD";
			break;
		case spv::OpGroupFAddNonUniformAMD:
			result = "OpGroupFAddNonUniformAMD";
			break;
		case spv::OpGroupFMinNonUniformAMD:
			result = "OpGroupFMinNonUniformAMD";
			break;
		case spv::OpGroupUMinNonUniformAMD:
			result = "OpGroupUMinNonUniformAMD";
			break;
		case spv::OpGroupSMinNonUniformAMD:
			result = "OpGroupSMinNonUniformAMD";
			break;
		case spv::OpGroupFMaxNonUniformAMD:
			result = "OpGroupFMaxNonUniformAMD";
			break;
		case spv::OpGroupUMaxNonUniformAMD:
			result = "OpGroupUMaxNonUniformAMD";
			break;
		case spv::OpGroupSMaxNonUniformAMD:
			result = "OpGroupSMaxNonUniformAMD";
			break;
		case spv::OpFragmentMaskFetchAMD:
			result = "OpFragmentMaskFetchAMD";
			break;
		case spv::OpFragmentFetchAMD:
			result = "OpFragmentFetchAMD";
			break;
		case spv::OpSubgroupShuffleINTEL:
			result = "OpSubgroupShuffleINTEL";
			break;
		case spv::OpSubgroupShuffleDownINTEL:
			result = "OpSubgroupShuffleDownINTEL";
			break;
		case spv::OpSubgroupShuffleUpINTEL:
			result = "OpSubgroupShuffleUpINTEL";
			break;
		case spv::OpSubgroupShuffleXorINTEL:
			result = "OpSubgroupShuffleXorINTEL";
			break;
		case spv::OpSubgroupBlockReadINTEL:
			result = "OpSubgroupBlockReadINTEL";
			break;
		case spv::OpSubgroupBlockWriteINTEL:
			result = "OpSubgroupBlockWriteINTEL";
			break;
		case spv::OpSubgroupImageBlockReadINTEL:
			result = "OpSubgroupImageBlockReadINTEL";
			break;
		case spv::OpSubgroupImageBlockWriteINTEL:
			result = "OpSubgroupImageBlockWriteINTEL";
			break;
		case spv::OpDecorateStringGOOGLE:
			result = "OpDecorateStringGOOGLE";
			break;
		case spv::OpMemberDecorateStringGOOGLE:
			result = "OpMemberDecorateStringGOOGLE";
			break;
		}

		return result;
	}

	spv::Op getOpCode( ast::type::Kind kind )
	{
		spv::Op result;

		switch ( kind )
		{
		case ast::type::Kind::eVoid:
			result = spv::OpTypeVoid;
			break;
		case ast::type::Kind::eFunction:
			result = spv::OpTypeFunction;
			break;
		case ast::type::Kind::eStruct:
			result = spv::OpTypeStruct;
			break;
		case ast::type::Kind::eBool:
			result = spv::OpTypeBool;
			break;
		case ast::type::Kind::eInt:
		case ast::type::Kind::eUInt:
			result = spv::OpTypeInt;
			break;
		case ast::type::Kind::eFloat:
		case ast::type::Kind::eDouble:
			result = spv::OpTypeFloat;
			break;
		case ast::type::Kind::eVec2B:
		case ast::type::Kind::eVec3B:
		case ast::type::Kind::eVec4B:
		case ast::type::Kind::eVec2I:
		case ast::type::Kind::eVec3I:
		case ast::type::Kind::eVec4I:
		case ast::type::Kind::eVec2U:
		case ast::type::Kind::eVec3U:
		case ast::type::Kind::eVec4U:
		case ast::type::Kind::eVec2F:
		case ast::type::Kind::eVec3F:
		case ast::type::Kind::eVec4F:
		case ast::type::Kind::eVec2D:
		case ast::type::Kind::eVec3D:
		case ast::type::Kind::eVec4D:
			result = spv::OpTypeVector;
			break;
		case ast::type::Kind::eMat2x2F:
		case ast::type::Kind::eMat2x3F:
		case ast::type::Kind::eMat2x4F:
		case ast::type::Kind::eMat3x2F:
		case ast::type::Kind::eMat3x3F:
		case ast::type::Kind::eMat3x4F:
		case ast::type::Kind::eMat4x2F:
		case ast::type::Kind::eMat4x3F:
		case ast::type::Kind::eMat4x4F:
		case ast::type::Kind::eMat2x2D:
		case ast::type::Kind::eMat2x3D:
		case ast::type::Kind::eMat2x4D:
		case ast::type::Kind::eMat3x2D:
		case ast::type::Kind::eMat3x3D:
		case ast::type::Kind::eMat3x4D:
		case ast::type::Kind::eMat4x2D:
		case ast::type::Kind::eMat4x3D:
		case ast::type::Kind::eMat4x4D:
			result = spv::OpTypeMatrix;
			break;
		case ast::type::Kind::eImage:
			result = spv::OpTypeImage;
			break;
		case ast::type::Kind::eSampledImage:
			result = spv::OpTypeSampledImage;
			break;
		case ast::type::Kind::eSampler:
			result = spv::OpTypeSampler;
			break;
		default:
			assert( false && "Unsupported ast::type::Kind" );
			break;
		}

		return result;
	}

	spv::Op getOpCode( ast::type::TypePtr type )
	{
		spv::Op result;
		auto arraySize = getArraySize( type );

		if ( arraySize == ast::type::NotArray )
		{
			result = getOpCode( type->getKind() );
		}
		else if ( arraySize != ast::type::UnknownArraySize )
		{
			result = spv::OpTypeArray;
		}
		else
		{
			result = spv::OpTypeRuntimeArray;
		}

		return result;
	}

	bool isAnyBool( ast::type::Kind typeKind )
	{
		return isBool( typeKind );
	}

	bool isAnySigned( ast::type::Kind typeKind )
	{
		return isSigned( typeKind );
	}

	bool isAnyUnsigned( ast::type::Kind typeKind )
	{
		return isUnsigned( typeKind );
	}

	bool isAnyBool( ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind )
	{
		return isBool( lhsTypeKind )
			|| isBool( rhsTypeKind );
	}

	bool isAnySigned( ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind )
	{
		return isSigned( lhsTypeKind )
			|| isSigned( rhsTypeKind );
	}

	bool isAnyUnsigned( ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind )
	{
		return isUnsigned( lhsTypeKind )
			|| isUnsigned( rhsTypeKind );
	}

	bool isAnyFloating( ast::type::Kind typeKind )
	{
		return isFloating( typeKind );
	}

	bool isAnyFloating( ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind )
	{
		return isFloating( lhsTypeKind )
			|| isFloating( rhsTypeKind );
	}

	spv::Op getBinOpCode( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, bool & switchParams
		, bool & needMatchingVectors )
	{
		needMatchingVectors = true;
		assert( exprKind != ast::expr::Kind::eImageAccessCall
			&& exprKind != ast::expr::Kind::eIntrinsicCall
			&& exprKind != ast::expr::Kind::eTextureAccessCall
			&& "Unsupported ast::expr::Kind" );
		spv::Op result{ spv::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eAdd:
		case ast::expr::Kind::eAddAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFAdd
				: spv::OpIAdd;
			break;
		case ast::expr::Kind::eMinus:
		case ast::expr::Kind::eMinusAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFSub
				: spv::OpISub;
			break;
		case ast::expr::Kind::eTimes:
		case ast::expr::Kind::eTimesAssign:
			result = isMatrixType( lhsTypeKind )
				? ( ( isMatrixType( rhsTypeKind )
					? spv::OpMatrixTimesMatrix
					: ( isVectorType( rhsTypeKind )
						? spv::OpMatrixTimesVector
						: spv::OpMatrixTimesScalar ) ) )
				: ( isVectorType( lhsTypeKind )
					? ( isMatrixType( rhsTypeKind )
						? spv::OpMatrixTimesVector
						: ( isVectorType( rhsTypeKind )
							? ( isAnyFloating( lhsTypeKind, rhsTypeKind )
								? spv::OpFMul
								: spv::OpIMul )
							: spv::OpVectorTimesScalar ) )
					: ( isMatrixType( rhsTypeKind )
						? spv::OpMatrixTimesScalar
						: ( isVectorType( rhsTypeKind )
							? spv::OpVectorTimesScalar
							: ( isAnyFloating( lhsTypeKind, rhsTypeKind )
								? spv::OpFMul
								: spv::OpIMul ) ) ) );
			needMatchingVectors = !( ( isFloatType( getScalarType( lhsTypeKind ) ) || isFloatType( getScalarType( rhsTypeKind ) ) )
				&& ( isVectorType( lhsTypeKind ) || isVectorType( rhsTypeKind ) ) );
			break;
		case ast::expr::Kind::eDivide:
		case ast::expr::Kind::eDivideAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFDiv
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSDiv
					: spv::OpUDiv );
			break;
		case ast::expr::Kind::eModulo:
		case ast::expr::Kind::eModuloAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFMod
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSMod
					: spv::OpUMod );
			break;
		case ast::expr::Kind::eLShift:
		case ast::expr::Kind::eLShiftAssign:
			result = spv::OpShiftLeftLogical;
			break;
		case ast::expr::Kind::eRShift:
		case ast::expr::Kind::eRShiftAssign:
			result = spv::OpShiftRightArithmetic;
			break;
		case ast::expr::Kind::eBitAnd:
		case ast::expr::Kind::eAndAssign:
			result = spv::OpBitwiseAnd;
			break;
		case ast::expr::Kind::eBitNot:
			assert( "Unexpected ast::expr::Kind::eBitNot" );
			break;
		case ast::expr::Kind::eNotAssign:
			result = spv::OpNot;
			break;
		case ast::expr::Kind::eBitOr:
		case ast::expr::Kind::eOrAssign:
			result = spv::OpBitwiseOr;
			break;
		case ast::expr::Kind::eBitXor:
		case ast::expr::Kind::eXorAssign:
			result = spv::OpBitwiseXor;
			break;
		case ast::expr::Kind::eLogAnd:
			result = spv::OpLogicalAnd;
			needMatchingVectors = false;
			break;
		case ast::expr::Kind::eLogNot:
			assert( "Unexpected ast::expr::Kind::eBitNot" );
			break;
		case ast::expr::Kind::eLogOr:
			result = spv::OpLogicalOr;
			needMatchingVectors = false;
			break;
		case ast::expr::Kind::eCast:
			assert( "Unexpected ast::expr::Kind::eCast" );
			break;
		case ast::expr::Kind::eInit:
			result = spv::OpStore;
			break;
		case ast::expr::Kind::eAggrInit:
			result = spv::OpStore;
			break;
		case ast::expr::Kind::eFnCall:
			assert( "Unexpected ast::expr::Kind::eFnCall" );
			break;
		case ast::expr::Kind::eEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdEqual
				: isAnyBool( lhsTypeKind, rhsTypeKind )
				? spv::OpLogicalEqual
				: spv::OpIEqual;
			break;
		case ast::expr::Kind::eGreater:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdGreaterThan
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSGreaterThan
					: spv::OpUGreaterThan );
			break;
		case ast::expr::Kind::eGreaterEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdGreaterThanEqual
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSGreaterThanEqual
					: spv::OpUGreaterThanEqual );
			break;
		case ast::expr::Kind::eLess:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdLessThan
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSLessThan
					: spv::OpULessThan );
			break;
		case ast::expr::Kind::eLessEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdLessThanEqual
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSLessThanEqual
					: spv::OpULessThanEqual );
			break;
		case ast::expr::Kind::eNotEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdNotEqual
				: isAnyBool( lhsTypeKind, rhsTypeKind )
				? spv::OpLogicalNotEqual
				: spv::OpINotEqual;
			break;
		case ast::expr::Kind::eComma:
			assert( "Unexpected ast::expr::Kind::eComma" );
			break;
		case ast::expr::Kind::eIdentifier:
			assert( "Unexpected ast::expr::Kind::eIdentifier" );
			break;
		case ast::expr::Kind::eLiteral:
			assert( "Unexpected ast::expr::Kind::eLiteral" );
			break;
		case ast::expr::Kind::eMbrSelect:
			assert( "Unexpected ast::expr::Kind::eMbrSelect" );
			break;
		case ast::expr::Kind::eSwitchTest:
			assert( "Unexpected ast::expr::Kind::eSwitchTest" );
			break;
		case ast::expr::Kind::eSwitchCase:
			assert( "Unexpected ast::expr::Kind::eSwitchCase" );
			break;
		case ast::expr::Kind::eQuestion:
			assert( "Unexpected ast::expr::Kind::eQuestion" );
			break;
		case ast::expr::Kind::ePreIncrement:
			assert( "Unexpected ast::expr::Kind::ePreIncrement" );
			break;
		case ast::expr::Kind::ePreDecrement:
			assert( "Unexpected ast::expr::Kind::ePreDecrement" );
			break;
		case ast::expr::Kind::ePostIncrement:
			assert( "Unexpected ast::expr::Kind::ePostIncrement" );
			break;
		case ast::expr::Kind::ePostDecrement:
			assert( "Unexpected ast::expr::Kind::ePostDecrement" );
			break;
		case ast::expr::Kind::eUnaryMinus:
			assert( "Unexpected ast::expr::Kind::eUnaryMinus" );
			break;
		case ast::expr::Kind::eUnaryPlus:
			assert( "Unexpected ast::expr::Kind::eUnaryPlus" );
			break;
		case ast::expr::Kind::eAssign:
			assert( "Unexpected ast::expr::Kind::eAssign" );
			break;
		case ast::expr::Kind::eArrayAccess:
			assert( "Unexpected ast::expr::Kind::eArrayAccess" );
			break;
		default:
			assert( "Unexpected ast::expr::Kind" );
			break;
		}

		switchParams = ( exprKind == ast::expr::Kind::eTimes || exprKind == ast::expr::Kind::eTimesAssign )
			&& ( ( isVectorType( lhsTypeKind ) && isMatrixType( rhsTypeKind ) )
				|| ( isScalarType( lhsTypeKind ) && ( isVectorType( rhsTypeKind ) || isMatrixType( rhsTypeKind ) ) ) );
		return result;
	}

	spv::Op getUnOpCode( ast::expr::Kind exprKind
		, ast::type::Kind typeKind )
	{
		assert( exprKind != ast::expr::Kind::eImageAccessCall
			&& exprKind != ast::expr::Kind::eIntrinsicCall
			&& exprKind != ast::expr::Kind::eTextureAccessCall
			&& "Unsupported ast::expr::Kind" );
		spv::Op result{ spv::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eBitNot:
		case ast::expr::Kind::eNotAssign:
			result = spv::OpNot;
			break;
		case ast::expr::Kind::eLogNot:
			result = spv::OpLogicalNot;
			break;
		case ast::expr::Kind::eCast:
			assert( false && "Unexpected ast::expr::Kind::eCast" );
			break;
		case ast::expr::Kind::eComma:
			assert( false && "Unexpected ast::expr::Kind::eComma" );
			break;
		case ast::expr::Kind::eIdentifier:
			assert( false && "Unexpected ast::expr::Kind::eIdentifier" );
			break;
		case ast::expr::Kind::eLiteral:
			assert( false && "Unexpected ast::expr::Kind::eLiteral" );
			break;
		case ast::expr::Kind::ePreIncrement:
			assert( false && "Unexpected ast::expr::Kind::ePreIncrement" );
			break;
		case ast::expr::Kind::ePreDecrement:
			assert( false && "Unexpected ast::expr::Kind::ePreDecrement" );
			break;
		case ast::expr::Kind::ePostIncrement:
			assert( false && "Unexpected ast::expr::Kind::ePostIncrement" );
			break;
		case ast::expr::Kind::ePostDecrement:
			assert( false && "Unexpected ast::expr::Kind::ePostDecrement" );
			break;
		case ast::expr::Kind::eUnaryMinus:
			result = isFloating( typeKind )
				? spv::OpFNegate
				: spv::OpSNegate;
			break;
		case ast::expr::Kind::eUnaryPlus:
			assert( false && "Unexpected ast::expr::Kind::eUnaryPlus" );
			break;
		default:
			break;
		}

		return result;
	}

	spv::Op getOpCode( ast::expr::Kind exprKind
		, ast::type::Kind typeKind )
	{
		assert( exprKind != ast::expr::Kind::eImageAccessCall
			&& exprKind != ast::expr::Kind::eIntrinsicCall
			&& exprKind != ast::expr::Kind::eTextureAccessCall
			&& "Unsupported ast::expr::Kind" );
		spv::Op result{ spv::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eAdd:
		case ast::expr::Kind::eAddAssign:
			result = isFloating( typeKind )
				? spv::OpFAdd
				: spv::OpIAdd;
			break;
		case ast::expr::Kind::eMinus:
		case ast::expr::Kind::eMinusAssign:
			result = isFloating( typeKind )
				? spv::OpFSub
				: spv::OpISub;
			break;
		case ast::expr::Kind::eTimes:
		case ast::expr::Kind::eTimesAssign:
			result = isFloating( typeKind )
				? spv::OpFMul
				: spv::OpIMul;
			break;
		case ast::expr::Kind::eDivide:
		case ast::expr::Kind::eDivideAssign:
			result = isFloating( typeKind )
				? spv::OpFDiv
				: ( isSigned( typeKind )
					? spv::OpSDiv
					: spv::OpUDiv );
			break;
		case ast::expr::Kind::eModulo:
		case ast::expr::Kind::eModuloAssign:
			result = isFloating( typeKind )
				? spv::OpFMod
				: ( isSigned( typeKind )
					? spv::OpSMod
					: spv::OpUMod );
			break;
		case ast::expr::Kind::eLShift:
		case ast::expr::Kind::eLShiftAssign:
			result = spv::OpShiftLeftLogical;
			break;
		case ast::expr::Kind::eRShift:
		case ast::expr::Kind::eRShiftAssign:
			result = spv::OpShiftRightArithmetic;
			break;
		case ast::expr::Kind::eBitAnd:
		case ast::expr::Kind::eAndAssign:
			result = spv::OpBitwiseAnd;
			break;
		case ast::expr::Kind::eBitNot:
		case ast::expr::Kind::eNotAssign:
			result = spv::OpNot;
			break;
		case ast::expr::Kind::eBitOr:
		case ast::expr::Kind::eOrAssign:
			result = spv::OpBitwiseOr;
			break;
		case ast::expr::Kind::eBitXor:
		case ast::expr::Kind::eXorAssign:
			result = spv::OpBitwiseXor;
			break;
		case ast::expr::Kind::eLogAnd:
			result = spv::OpLogicalAnd;
			break;
		case ast::expr::Kind::eLogNot:
			result = spv::OpLogicalNot;
			break;
		case ast::expr::Kind::eLogOr:
			result = spv::OpLogicalOr;
			break;
		case ast::expr::Kind::eCast:
			assert( false && "Unexpected ast::expr::Kind::eCast" );
			break;
		case ast::expr::Kind::eInit:
			result = spv::OpStore;
			break;
		case ast::expr::Kind::eAggrInit:
			result = spv::OpStore;
			break;
		case ast::expr::Kind::eFnCall:
			result = spv::OpFunctionCall;
			break;
		case ast::expr::Kind::eEqual:
			result = isFloating( typeKind )
				? spv::OpFOrdEqual
				: spv::OpIEqual;
			break;
		case ast::expr::Kind::eGreater:
			result = isFloating( typeKind )
				? spv::OpFOrdGreaterThan
				: ( isSigned( typeKind )
					? spv::OpSGreaterThan
					: spv::OpUGreaterThan );
			break;
		case ast::expr::Kind::eGreaterEqual:
			result = isFloating( typeKind )
				? spv::OpFOrdGreaterThanEqual
				: ( isSigned( typeKind )
					? spv::OpSGreaterThanEqual
					: spv::OpUGreaterThanEqual );
			break;
		case ast::expr::Kind::eLess:
			result = isFloating( typeKind )
				? spv::OpFOrdLessThan
				: ( isSigned( typeKind )
					? spv::OpSLessThan
					: spv::OpULessThan );
			break;
		case ast::expr::Kind::eLessEqual:
			result = isFloating( typeKind )
				? spv::OpFOrdLessThanEqual
				: ( isSigned( typeKind )
					? spv::OpSLessThanEqual
					: spv::OpULessThanEqual );
			break;
		case ast::expr::Kind::eNotEqual:
			result = isFloating( typeKind )
				? spv::OpFOrdNotEqual
				: spv::OpINotEqual;
			break;
		case ast::expr::Kind::eComma:
			assert( false && "Unexpected ast::expr::Kind::eComma" );
			break;
		case ast::expr::Kind::eIdentifier:
			assert( false && "Unexpected ast::expr::Kind::eIdentifier" );
			break;
		case ast::expr::Kind::eLiteral:
			assert( false && "Unexpected ast::expr::Kind::eLiteral" );
			break;
		case ast::expr::Kind::eMbrSelect:
			result = spv::OpAccessChain;
			break;
		case ast::expr::Kind::eSwitchTest:
			result = spv::OpSwitch;
			break;
		case ast::expr::Kind::eSwitchCase:
			result = spv::OpLabel;
			break;
		case ast::expr::Kind::eQuestion:
			result = spv::OpSelect;
			break;
		case ast::expr::Kind::ePreIncrement:
			assert( false && "Unexpected ast::expr::Kind::ePreIncrement" );
			break;
		case ast::expr::Kind::ePreDecrement:
			assert( false && "Unexpected ast::expr::Kind::ePreDecrement" );
			break;
		case ast::expr::Kind::ePostIncrement:
			assert( false && "Unexpected ast::expr::Kind::ePostIncrement" );
			break;
		case ast::expr::Kind::ePostDecrement:
			assert( false && "Unexpected ast::expr::Kind::ePostDecrement" );
			break;
		case ast::expr::Kind::eUnaryMinus:
			result = isFloating( typeKind )
				? spv::OpFNegate
				:  spv::OpSNegate;
			break;
		case ast::expr::Kind::eUnaryPlus:
			assert( false && "Unexpected ast::expr::Kind::eUnaryPlus" );
			break;
		case ast::expr::Kind::eAssign:
			result = spv::OpStore;
			break;
		case ast::expr::Kind::eArrayAccess:
			result = spv::OpAccessChain;
			break;
		default:
			break;
		}

		return result;
	}

	//*************************************************************************
}
