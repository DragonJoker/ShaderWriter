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
			return kind == ast::type::Kind::eBoolean
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
		case spv::Op::OpNop:
		case spv::Op::OpNoLine:
		case spv::Op::OpFunctionEnd:
		case spv::Op::OpKill:
		case spv::Op::OpReturn:
		case spv::Op::OpUnreachable:
		case spv::Op::OpEmitVertex:
		case spv::Op::OpEndPrimitive:
			result = 1u;
			break;
		case spv::Op::OpSourceContinued:
		case spv::Op::OpSourceExtension:
		case spv::Op::OpDecorationGroup:
		case spv::Op::OpGroupDecorate:
		case spv::Op::OpGroupMemberDecorate:
		case spv::Op::OpExtension:
		case spv::Op::OpCapability:
		case spv::Op::OpTypeVoid:
		case spv::Op::OpTypeBool:
		case spv::Op::OpTypeSampler:
		case spv::Op::OpTypeStruct:
		case spv::Op::OpTypeEvent:
		case spv::Op::OpTypeDeviceEvent:
		case spv::Op::OpTypeReserveId:
		case spv::Op::OpTypeQueue:
		case spv::Op::OpLabel:
		case spv::Op::OpBranch:
		case spv::Op::OpReturnValue:
		case spv::Op::OpEmitStreamVertex:
		case spv::Op::OpEndStreamPrimitive:
		case spv::Op::OpTypeNamedBarrier:
		case spv::Op::OpModuleProcessed:
			result = 2u;
			break;
		case spv::Op::OpUndef:
		case spv::Op::OpSource:
		case spv::Op::OpName:
		case spv::Op::OpString:
		case spv::Op::OpDecorate:
		case spv::Op::OpExtInstImport:
		case spv::Op::OpMemoryModel:
		case spv::Op::OpExecutionMode:
		case spv::Op::OpTypeFloat:
		case spv::Op::OpTypeSampledImage:
		case spv::Op::OpTypeRuntimeArray:
		case spv::Op::OpTypeOpaque:
		case spv::Op::OpTypeFunction:
		case spv::Op::OpTypePipe:
		case spv::Op::OpTypeForwardPointer:
		case spv::Op::OpConstantTrue:
		case spv::Op::OpConstantFalse:
		case spv::Op::OpConstant:
		case spv::Op::OpConstantComposite:
		case spv::Op::OpConstantNull:
		case spv::Op::OpSpecConstantTrue:
		case spv::Op::OpSpecConstantFalse:
		case spv::Op::OpSpecConstant:
		case spv::Op::OpSpecConstantComposite:
		case spv::Op::OpStore:
		case spv::Op::OpCopyMemory:
		case spv::Op::OpFunctionParameter:
		case spv::Op::OpCompositeConstruct:
		case spv::Op::OpPhi:
		case spv::Op::OpSelectionMerge:
		case spv::Op::OpSwitch:
		case spv::Op::OpLifetimeStart:
		case spv::Op::OpLifetimeStop:
		case spv::Op::OpMemoryBarrier:
		case spv::Op::OpExecutionModeId:
		case spv::Op::OpDecorateId:
			result = 3u;
			break;
		case spv::Op::OpMemberName:
		case spv::Op::OpLine:
		case spv::Op::OpMemberDecorate:
		case spv::Op::OpEntryPoint:
		case spv::Op::OpTypeInt:
		case spv::Op::OpTypeVector:
		case spv::Op::OpTypeMatrix:
		case spv::Op::OpTypeArray:
		case spv::Op::OpTypePointer:
		case spv::Op::OpSpecConstantOp:
		case spv::Op::OpVariable:
		case spv::Op::OpLoad:
		case spv::Op::OpCopyMemorySized:
		case spv::Op::OpAccessChain:
		case spv::Op::OpInBoundsAccessChain:
		case spv::Op::OpGenericPtrMemSemantics:
		case spv::Op::OpFunctionCall:
		case spv::Op::OpImageWrite:
		case spv::Op::OpImage:
		case spv::Op::OpImageQueryFormat:
		case spv::Op::OpImageQueryOrder:
		case spv::Op::OpImageQuerySize:
		case spv::Op::OpImageQueryLevels:
		case spv::Op::OpImageQuerySamples:
		case spv::Op::OpImageSparseTexelsResident:
		case spv::Op::OpConvertFToU:
		case spv::Op::OpConvertFToS:
		case spv::Op::OpConvertSToF:
		case spv::Op::OpConvertUToF:
		case spv::Op::OpUConvert:
		case spv::Op::OpSConvert:
		case spv::Op::OpFConvert:
		case spv::Op::OpQuantizeToF16:
		case spv::Op::OpConvertPtrToU:
		case spv::Op::OpSatConvertSToU:
		case spv::Op::OpSatConvertUToS:
		case spv::Op::OpConvertUToPtr:
		case spv::Op::OpPtrCastToGeneric:
		case spv::Op::OpGenericCastToPtr:
		case spv::Op::OpBitcast:
		case spv::Op::OpCompositeExtract:
		case spv::Op::OpCopyObject:
		case spv::Op::OpTranspose:
		case spv::Op::OpSNegate:
		case spv::Op::OpFNegate:
		case spv::Op::OpNot:
		case spv::Op::OpBitReverse:
		case spv::Op::OpBitCount:
		case spv::Op::OpAny:
		case spv::Op::OpAll:
		case spv::Op::OpIsNan:
		case spv::Op::OpIsInf:
		case spv::Op::OpIsFinite:
		case spv::Op::OpIsNormal:
		case spv::Op::OpSignBitSet:
		case spv::Op::OpLogicalNot:
		case spv::Op::OpDPdx:
		case spv::Op::OpDPdy:
		case spv::Op::OpFwidth:
		case spv::Op::OpDPdxFine:
		case spv::Op::OpDPdyFine:
		case spv::Op::OpFwidthFine:
		case spv::Op::OpDPdxCoarse:
		case spv::Op::OpDPdyCoarse:
		case spv::Op::OpFwidthCoarse:
		case spv::Op::OpLoopMerge:
		case spv::Op::OpBranchConditional:
		case spv::Op::OpAtomicFlagClear:
		case spv::Op::OpControlBarrier:
		case spv::Op::OpGroupWaitEvents:
		case spv::Op::OpSizeOf:
		case spv::Op::OpNamedBarrierInitialize:
		case spv::Op::OpMemoryNamedBarrier:
			result = 4u;
			break;
		case spv::Op::OpExtInst:
		case spv::Op::OpPtrAccessChain:
		case spv::Op::OpArrayLength:
		case spv::Op::OpInBoundsPtrAccessChain:
		case spv::Op::OpFunction:
		case spv::Op::OpSampledImage:
		case spv::Op::OpImageSampleImplicitLod:
		case spv::Op::OpImageSampleProjImplicitLod:
		case spv::Op::OpImageFetch:
		case spv::Op::OpImageRead:
		case spv::Op::OpImageQuerySizeLod:
		case spv::Op::OpImageQueryLod:
		case spv::Op::OpImageSparseSampleImplicitLod:
		case spv::Op::OpImageSparseSampleProjImplicitLod:
		case spv::Op::OpImageSparseFetch:
		case spv::Op::OpImageSparseRead:
		case spv::Op::OpGenericCastToPtrExplicit:
		case spv::Op::OpVectorExtractDynamic:
		case spv::Op::OpVectorShuffle:
		case spv::Op::OpCompositeInsert:
		case spv::Op::OpIAdd:
		case spv::Op::OpFAdd:
		case spv::Op::OpISub:
		case spv::Op::OpFSub:
		case spv::Op::OpIMul:
		case spv::Op::OpFMul:
		case spv::Op::OpUDiv:
		case spv::Op::OpSDiv:
		case spv::Op::OpFDiv:
		case spv::Op::OpUMod:
		case spv::Op::OpSRem:
		case spv::Op::OpSMod:
		case spv::Op::OpFRem:
		case spv::Op::OpFMod:
		case spv::Op::OpVectorTimesScalar:
		case spv::Op::OpMatrixTimesScalar:
		case spv::Op::OpVectorTimesMatrix:
		case spv::Op::OpMatrixTimesVector:
		case spv::Op::OpMatrixTimesMatrix:
		case spv::Op::OpOuterProduct:
		case spv::Op::OpDot:
		case spv::Op::OpIAddCarry:
		case spv::Op::OpISubBorrow:
		case spv::Op::OpUMulExtended:
		case spv::Op::OpSMulExtended:
		case spv::Op::OpShiftRightLogical:
		case spv::Op::OpShiftRightArithmetic:
		case spv::Op::OpShiftLeftLogical:
		case spv::Op::OpBitwiseOr:
		case spv::Op::OpBitwiseXor:
		case spv::Op::OpBitwiseAnd:
		case spv::Op::OpLessOrGreater:
		case spv::Op::OpOrdered:
		case spv::Op::OpUnordered:
		case spv::Op::OpLogicalEqual:
		case spv::Op::OpLogicalNotEqual:
		case spv::Op::OpLogicalOr:
		case spv::Op::OpLogicalAnd:
		case spv::Op::OpIEqual:
		case spv::Op::OpINotEqual:
		case spv::Op::OpUGreaterThan:
		case spv::Op::OpSGreaterThan:
		case spv::Op::OpUGreaterThanEqual:
		case spv::Op::OpSGreaterThanEqual:
		case spv::Op::OpULessThan:
		case spv::Op::OpSLessThan:
		case spv::Op::OpULessThanEqual:
		case spv::Op::OpSLessThanEqual:
		case spv::Op::OpFOrdEqual:
		case spv::Op::OpFUnordEqual:
		case spv::Op::OpFOrdNotEqual:
		case spv::Op::OpFUnordNotEqual:
		case spv::Op::OpFOrdLessThan:
		case spv::Op::OpFUnordLessThan:
		case spv::Op::OpFOrdGreaterThan:
		case spv::Op::OpFUnordGreaterThan:
		case spv::Op::OpFOrdLessThanEqual:
		case spv::Op::OpFUnordLessThanEqual:
		case spv::Op::OpFOrdGreaterThanEqual:
		case spv::Op::OpFUnordGreaterThanEqual:
		case spv::Op::OpAtomicStore:
		case spv::Op::OpGroupAll:
		case spv::Op::OpGroupAny:
			result = 5u;
			break;
		case spv::Op::OpConstantSampler:
		case spv::Op::OpImageTexelPointer:
		case spv::Op::OpImageSampleDrefImplicitLod:
		case spv::Op::OpImageSampleProjDrefImplicitLod:
		case spv::Op::OpImageGather:
		case spv::Op::OpImageDrefGather:
		case spv::Op::OpImageSparseSampleDrefImplicitLod:
		case spv::Op::OpImageSparseSampleProjDrefImplicitLod:
		case spv::Op::OpImageSparseGather:
		case spv::Op::OpImageSparseDrefGather:
		case spv::Op::OpVectorInsertDynamic:
		case spv::Op::OpBitFieldSExtract:
		case spv::Op::OpBitFieldUExtract:
		case spv::Op::OpSelect:
		case spv::Op::OpAtomicLoad:
		case spv::Op::OpAtomicIIncrement:
		case spv::Op::OpAtomicIDecrement:
		case spv::Op::OpAtomicFlagTestAndSet:
		case spv::Op::OpGroupBroadcast:
		case spv::Op::OpGroupIAdd:
		case spv::Op::OpGroupFAdd:
		case spv::Op::OpGroupFMin:
		case spv::Op::OpGroupUMin:
		case spv::Op::OpGroupSMin:
		case spv::Op::OpGroupFMax:
		case spv::Op::OpGroupUMax:
		case spv::Op::OpGroupSMax:
			result = 6u;
			break;
		case spv::Op::OpImageSampleExplicitLod:
		case spv::Op::OpImageSampleProjExplicitLod:
		case spv::Op::OpImageSparseSampleExplicitLod:
		case spv::Op::OpImageSparseSampleProjExplicitLod:
		case spv::Op::OpBitFieldInsert:
		case spv::Op::OpAtomicExchange:
		case spv::Op::OpAtomicIAdd:
		case spv::Op::OpAtomicISub:
		case spv::Op::OpAtomicSMin:
		case spv::Op::OpAtomicUMin:
		case spv::Op::OpAtomicSMax:
		case spv::Op::OpAtomicUMax:
		case spv::Op::OpAtomicAnd:
		case spv::Op::OpAtomicOr:
		case spv::Op::OpAtomicXor:
			result = 7u;
			break;
		case spv::Op::OpImageSampleDrefExplicitLod:
		case spv::Op::OpImageSampleProjDrefExplicitLod:
		case spv::Op::OpImageSparseSampleDrefExplicitLod:
		case spv::Op::OpImageSparseSampleProjDrefExplicitLod:
			result = 8u;
			break;
		case spv::Op::OpTypeImage:
		case spv::Op::OpAtomicCompareExchange:
		case spv::Op::OpAtomicCompareExchangeWeak:
		case spv::Op::OpGroupAsyncCopy:
			result = 9u;
			break;

			///////////////////////////////////////////////////////////////
			// Kernels
			///////////////////////////////////////////////////////////////

		case spv::Op::OpRetainEvent:
		case spv::Op::OpReleaseEvent:
		case spv::Op::OpTypePipeStorage:
			result = 2u;
			break;
		case spv::Op::OpCreateUserEvent:
		case spv::Op::OpSetUserEventStatus:
		case spv::Op::OpGetDefaultQueue:
			result = 3u;
			break;
		case spv::Op::OpIsValidEvent:
		case spv::Op::OpCaptureEventProfilingInfo:
		case spv::Op::OpIsValidReserveId:
		case spv::Op::OpCreatePipeFromPipeStorage:
			result = 4u;
			break;
		case spv::Op::OpCommitReadPipe:
		case spv::Op::OpCommitWritePipe:
			result = 5u;
			break;
		case spv::Op::OpBuildNDRange:
		case spv::Op::OpGetNumPipePackets:
		case spv::Op::OpGetMaxPipePackets:
		case spv::Op::OpGroupCommitReadPipe:
		case spv::Op::OpGroupCommitWritePipe:
		case spv::Op::OpConstantPipeStorage:
			result = 6u;
			break;
		case spv::Op::OpEnqueueMarker:
		case spv::Op::OpGetKernelWorkGroupSize:
		case spv::Op::OpGetKernelPreferredWorkGroupSizeMultiple:
		case spv::Op::OpReadPipe:
		case spv::Op::OpWritePipe:
		case spv::Op::OpReserveReadPipePackets:
		case spv::Op::OpReserveWritePipePackets:
		case spv::Op::OpGetKernelMaxNumSubgroups:
			result = 7u;
			break;
		case spv::Op::OpGetKernelNDrangeSubGroupCount:
		case spv::Op::OpGetKernelNDrangeMaxSubGroupSize:
		case spv::Op::OpGroupReserveReadPipePackets:
		case spv::Op::OpGroupReserveWritePipePackets:
		case spv::Op::OpGetKernelLocalSizeForSubgroupCount:
			result = 8u;
			break;
		case spv::Op::OpReservedReadPipe:
		case spv::Op::OpReservedWritePipe:
			result = 9u;
			break;
		case spv::Op::OpEnqueueKernel:
			result = 13u;
			break;

			///////////////////////////////////////////////////////////////
			// Extensions
			///////////////////////////////////////////////////////////////

		case spv::Op::OpSubgroupBlockWriteINTEL:
		case spv::Op::OpDecorateStringGOOGLE:
			result = 3u;
			break;
		case spv::Op::OpSubgroupBallotKHR:
		case spv::Op::OpSubgroupFirstInvocationKHR:
		case spv::Op::OpSubgroupAllKHR:
		case spv::Op::OpSubgroupAnyKHR:
		case spv::Op::OpSubgroupAllEqualKHR:
		case spv::Op::OpSubgroupBlockReadINTEL:
		case spv::Op::OpSubgroupImageBlockWriteINTEL:
		case spv::Op::OpMemberDecorateStringGOOGLE:
			result = 4u;
			break;
		case spv::Op::OpSubgroupReadInvocationKHR:
		case spv::Op::OpFragmentMaskFetchAMD:
		case spv::Op::OpSubgroupShuffleINTEL:
		case spv::Op::OpSubgroupShuffleXorINTEL:
		case spv::Op::OpSubgroupImageBlockReadINTEL:
			result = 5u;
			break;
		case spv::Op::OpGroupIAddNonUniformAMD:
		case spv::Op::OpGroupFAddNonUniformAMD:
		case spv::Op::OpGroupFMinNonUniformAMD:
		case spv::Op::OpGroupUMinNonUniformAMD:
		case spv::Op::OpGroupSMinNonUniformAMD:
		case spv::Op::OpGroupFMaxNonUniformAMD:
		case spv::Op::OpGroupUMaxNonUniformAMD:
		case spv::Op::OpGroupSMaxNonUniformAMD:
		case spv::Op::OpFragmentFetchAMD:
		case spv::Op::OpSubgroupShuffleDownINTEL:
		case spv::Op::OpSubgroupShuffleUpINTEL:
			result = 6u;
			break;
		}

		return result;
	}

	std::string getOpName( spv::Op op )
	{
		std::string result;

		switch ( op )
		{
		case spv::Op::OpNop:
			result = "OpNop";
			break;
		case spv::Op::OpUndef:
			result = "OpUndef";
			break;
		case spv::Op::OpSourceContinued:
			result = "OpSourceContinued";
			break;
		case spv::Op::OpSource:
			result = "OpSource";
			break;
		case spv::Op::OpSourceExtension:
			result = "OpSourceExtension";
			break;
		case spv::Op::OpName:
			result = "OpName";
			break;
		case spv::Op::OpMemberName:
			result = "OpMemberName";
			break;
		case spv::Op::OpString:
			result = "OpString";
			break;
		case spv::Op::OpLine:
			result = "OpLine";
			break;
		case spv::Op::OpExtension:
			result = "OpExtension";
			break;
		case spv::Op::OpExtInstImport:
			result = "OpExtInstImport";
			break;
		case spv::Op::OpExtInst:
			result = "OpExtInst";
			break;
		case spv::Op::OpMemoryModel:
			result = "OpMemoryModel";
			break;
		case spv::Op::OpEntryPoint:
			result = "OpEntryPoint";
			break;
		case spv::Op::OpExecutionMode:
			result = "OpExecutionMode";
			break;
		case spv::Op::OpCapability:
			result = "OpCapability";
			break;
		case spv::Op::OpTypeVoid:
			result = "OpTypeVoid";
			break;
		case spv::Op::OpTypeBool:
			result = "OpTypeBool";
			break;
		case spv::Op::OpTypeInt:
			result = "OpTypeInt";
			break;
		case spv::Op::OpTypeFloat:
			result = "OpTypeFloat";
			break;
		case spv::Op::OpTypeVector:
			result = "OpTypeVector";
			break;
		case spv::Op::OpTypeMatrix:
			result = "OpTypeMatrix";
			break;
		case spv::Op::OpTypeImage:
			result = "OpTypeImage";
			break;
		case spv::Op::OpTypeSampler:
			result = "OpTypeSampler";
			break;
		case spv::Op::OpTypeSampledImage:
			result = "OpTypeSampledImage";
			break;
		case spv::Op::OpTypeArray:
			result = "OpTypeArray";
			break;
		case spv::Op::OpTypeRuntimeArray:
			result = "OpTypeRuntimeArray";
			break;
		case spv::Op::OpTypeStruct:
			result = "OpTypeStruct";
			break;
		case spv::Op::OpTypeOpaque:
			result = "OpTypeOpaque";
			break;
		case spv::Op::OpTypePointer:
			result = "OpTypePointer";
			break;
		case spv::Op::OpTypeFunction:
			result = "OpTypeFunction";
			break;
		case spv::Op::OpTypeEvent:
			result = "OpTypeEvent";
			break;
		case spv::Op::OpTypeDeviceEvent:
			result = "OpTypeDeviceEvent";
			break;
		case spv::Op::OpTypeReserveId:
			result = "OpTypeReserveId";
			break;
		case spv::Op::OpTypeQueue:
			result = "OpTypeQueue";
			break;
		case spv::Op::OpTypePipe:
			result = "OpTypePipe";
			break;
		case spv::Op::OpTypeForwardPointer:
			result = "OpTypeForwardPointer";
			break;
		case spv::Op::OpConstantTrue:
			result = "OpConstantTrue";
			break;
		case spv::Op::OpConstantFalse:
			result = "OpConstantFalse";
			break;
		case spv::Op::OpConstant:
			result = "OpConstant";
			break;
		case spv::Op::OpConstantComposite:
			result = "OpConstantComposite";
			break;
		case spv::Op::OpConstantSampler:
			result = "OpConstantSampler";
			break;
		case spv::Op::OpConstantNull:
			result = "OpConstantNull";
			break;
		case spv::Op::OpSpecConstantTrue:
			result = "OpSpecConstantTrue";
			break;
		case spv::Op::OpSpecConstantFalse:
			result = "OpSpecConstantFalse";
			break;
		case spv::Op::OpSpecConstant:
			result = "OpSpecConstant";
			break;
		case spv::Op::OpSpecConstantComposite:
			result = "OpSpecConstantComposite";
			break;
		case spv::Op::OpSpecConstantOp:
			result = "OpSpecConstantOp";
			break;
		case spv::Op::OpFunction:
			result = "OpFunction";
			break;
		case spv::Op::OpFunctionParameter:
			result = "OpFunctionParameter";
			break;
		case spv::Op::OpFunctionEnd:
			result = "OpFunctionEnd";
			break;
		case spv::Op::OpFunctionCall:
			result = "OpFunctionCall";
			break;
		case spv::Op::OpVariable:
			result = "OpVariable";
			break;
		case spv::Op::OpImageTexelPointer:
			result = "OpImageTexelPointer";
			break;
		case spv::Op::OpLoad:
			result = "OpLoad";
			break;
		case spv::Op::OpStore:
			result = "OpStore";
			break;
		case spv::Op::OpCopyMemory:
			result = "OpCopyMemory";
			break;
		case spv::Op::OpCopyMemorySized:
			result = "OpCopyMemorySized";
			break;
		case spv::Op::OpAccessChain:
			result = "OpAccessChain";
			break;
		case spv::Op::OpInBoundsAccessChain:
			result = "OpInBoundsAccessChain";
			break;
		case spv::Op::OpPtrAccessChain:
			result = "OpPtrAccessChain";
			break;
		case spv::Op::OpArrayLength:
			result = "OpArrayLength";
			break;
		case spv::Op::OpGenericPtrMemSemantics:
			result = "OpGenericPtrMemSemantics";
			break;
		case spv::Op::OpInBoundsPtrAccessChain:
			result = "OpInBoundsPtrAccessChain";
			break;
		case spv::Op::OpDecorate:
			result = "OpDecorate";
			break;
		case spv::Op::OpMemberDecorate:
			result = "OpMemberDecorate";
			break;
		case spv::Op::OpDecorationGroup:
			result = "OpDecorationGroup";
			break;
		case spv::Op::OpGroupDecorate:
			result = "OpGroupDecorate";
			break;
		case spv::Op::OpGroupMemberDecorate:
			result = "OpGroupMemberDecorate";
			break;
		case spv::Op::OpVectorExtractDynamic:
			result = "OpVectorExtractDynamic";
			break;
		case spv::Op::OpVectorInsertDynamic:
			result = "OpVectorInsertDynamic";
			break;
		case spv::Op::OpVectorShuffle:
			result = "OpVectorShuffle";
			break;
		case spv::Op::OpCompositeConstruct:
			result = "OpCompositeConstruct";
			break;
		case spv::Op::OpCompositeExtract:
			result = "OpCompositeExtract";
			break;
		case spv::Op::OpCompositeInsert:
			result = "OpCompositeInsert";
			break;
		case spv::Op::OpCopyObject:
			result = "OpCopyObject";
			break;
		case spv::Op::OpTranspose:
			result = "OpTranspose";
			break;
		case spv::Op::OpSampledImage:
			result = "OpSampledImage";
			break;
		case spv::Op::OpImageSampleImplicitLod:
			result = "OpImageSampleImplicitLod";
			break;
		case spv::Op::OpImageSampleExplicitLod:
			result = "OpImageSampleExplicitLod";
			break;
		case spv::Op::OpImageSampleDrefImplicitLod:
			result = "OpImageSampleDrefImplicitLod";
			break;
		case spv::Op::OpImageSampleDrefExplicitLod:
			result = "OpImageSampleDrefExplicitLod";
			break;
		case spv::Op::OpImageSampleProjImplicitLod:
			result = "OpImageSampleProjImplicitLod";
			break;
		case spv::Op::OpImageSampleProjExplicitLod:
			result = "OpImageSampleProjExplicitLod";
			break;
		case spv::Op::OpImageSampleProjDrefImplicitLod:
			result = "OpImageSampleProjDrefImplicitLod";
			break;
		case spv::Op::OpImageSampleProjDrefExplicitLod:
			result = "OpImageSampleProjDrefExplicitLod";
			break;
		case spv::Op::OpImageFetch:
			result = "OpImageFetch";
			break;
		case spv::Op::OpImageGather:
			result = "OpImageGather";
			break;
		case spv::Op::OpImageDrefGather:
			result = "OpImageDrefGather";
			break;
		case spv::Op::OpImageRead:
			result = "OpImageRead";
			break;
		case spv::Op::OpImageWrite:
			result = "OpImageWrite";
			break;
		case spv::Op::OpImage:
			result = "OpImage";
			break;
		case spv::Op::OpImageQueryFormat:
			result = "OpImageQueryFormat";
			break;
		case spv::Op::OpImageQueryOrder:
			result = "OpImageQueryOrder";
			break;
		case spv::Op::OpImageQuerySizeLod:
			result = "OpImageQuerySizeLod";
			break;
		case spv::Op::OpImageQuerySize:
			result = "OpImageQuerySize";
			break;
		case spv::Op::OpImageQueryLod:
			result = "OpImageQueryLod";
			break;
		case spv::Op::OpImageQueryLevels:
			result = "OpImageQueryLevels";
			break;
		case spv::Op::OpImageQuerySamples:
			result = "OpImageQuerySamples";
			break;
		case spv::Op::OpConvertFToU:
			result = "OpConvertFToU";
			break;
		case spv::Op::OpConvertFToS:
			result = "OpConvertFToS";
			break;
		case spv::Op::OpConvertSToF:
			result = "OpConvertSToF";
			break;
		case spv::Op::OpConvertUToF:
			result = "OpConvertUToF";
			break;
		case spv::Op::OpUConvert:
			result = "OpUConvert";
			break;
		case spv::Op::OpSConvert:
			result = "OpSConvert";
			break;
		case spv::Op::OpFConvert:
			result = "OpFConvert";
			break;
		case spv::Op::OpQuantizeToF16:
			result = "OpQuantizeToF16";
			break;
		case spv::Op::OpConvertPtrToU:
			result = "OpConvertPtrToU";
			break;
		case spv::Op::OpSatConvertSToU:
			result = "OpSatConvertSToU";
			break;
		case spv::Op::OpSatConvertUToS:
			result = "OpSatConvertUToS";
			break;
		case spv::Op::OpConvertUToPtr:
			result = "OpConvertUToPtr";
			break;
		case spv::Op::OpPtrCastToGeneric:
			result = "OpPtrCastToGeneric";
			break;
		case spv::Op::OpGenericCastToPtr:
			result = "OpGenericCastToPtr";
			break;
		case spv::Op::OpGenericCastToPtrExplicit:
			result = "OpGenericCastToPtrExplicit";
			break;
		case spv::Op::OpBitcast:
			result = "OpBitcast";
			break;
		case spv::Op::OpSNegate:
			result = "OpSNegate";
			break;
		case spv::Op::OpFNegate:
			result = "OpFNegate";
			break;
		case spv::Op::OpIAdd:
			result = "OpIAdd";
			break;
		case spv::Op::OpFAdd:
			result = "OpFAdd";
			break;
		case spv::Op::OpISub:
			result = "OpISub";
			break;
		case spv::Op::OpFSub:
			result = "OpFSub";
			break;
		case spv::Op::OpIMul:
			result = "OpIMul";
			break;
		case spv::Op::OpFMul:
			result = "OpFMul";
			break;
		case spv::Op::OpUDiv:
			result = "OpUDiv";
			break;
		case spv::Op::OpSDiv:
			result = "OpSDiv";
			break;
		case spv::Op::OpFDiv:
			result = "OpFDiv";
			break;
		case spv::Op::OpUMod:
			result = "OpUMod";
			break;
		case spv::Op::OpSRem:
			result = "OpSRem";
			break;
		case spv::Op::OpSMod:
			result = "OpSMod";
			break;
		case spv::Op::OpFRem:
			result = "OpFRem";
			break;
		case spv::Op::OpFMod:
			result = "OpFMod";
			break;
		case spv::Op::OpVectorTimesScalar:
			result = "OpVectorTimesScalar";
			break;
		case spv::Op::OpMatrixTimesScalar:
			result = "OpMatrixTimesScalar";
			break;
		case spv::Op::OpVectorTimesMatrix:
			result = "OpVectorTimesMatrix";
			break;
		case spv::Op::OpMatrixTimesVector:
			result = "OpMatrixTimesVector";
			break;
		case spv::Op::OpMatrixTimesMatrix:
			result = "OpMatrixTimesMatrix";
			break;
		case spv::Op::OpOuterProduct:
			result = "OpOuterProduct";
			break;
		case spv::Op::OpDot:
			result = "OpDot";
			break;
		case spv::Op::OpIAddCarry:
			result = "OpIAddCarry";
			break;
		case spv::Op::OpISubBorrow:
			result = "OpISubBorrow";
			break;
		case spv::Op::OpUMulExtended:
			result = "OpUMulExtended";
			break;
		case spv::Op::OpSMulExtended:
			result = "OpSMulExtended";
			break;
		case spv::Op::OpAny:
			result = "OpAny";
			break;
		case spv::Op::OpAll:
			result = "OpAll";
			break;
		case spv::Op::OpIsNan:
			result = "OpIsNan";
			break;
		case spv::Op::OpIsInf:
			result = "OpIsInf";
			break;
		case spv::Op::OpIsFinite:
			result = "OpIsFinite";
			break;
		case spv::Op::OpIsNormal:
			result = "OpIsNormal";
			break;
		case spv::Op::OpSignBitSet:
			result = "OpSignBitSet";
			break;
		case spv::Op::OpLessOrGreater:
			result = "OpLessOrGreater";
			break;
		case spv::Op::OpOrdered:
			result = "OpOrdered";
			break;
		case spv::Op::OpUnordered:
			result = "OpUnordered";
			break;
		case spv::Op::OpLogicalEqual:
			result = "OpLogicalEqual";
			break;
		case spv::Op::OpLogicalNotEqual:
			result = "OpLogicalNotEqual";
			break;
		case spv::Op::OpLogicalOr:
			result = "OpLogicalOr";
			break;
		case spv::Op::OpLogicalAnd:
			result = "OpLogicalAnd";
			break;
		case spv::Op::OpLogicalNot:
			result = "OpLogicalNot";
			break;
		case spv::Op::OpSelect:
			result = "OpSelect";
			break;
		case spv::Op::OpIEqual:
			result = "OpIEqual";
			break;
		case spv::Op::OpINotEqual:
			result = "OpINotEqual";
			break;
		case spv::Op::OpUGreaterThan:
			result = "OpUGreaterThan";
			break;
		case spv::Op::OpSGreaterThan:
			result = "OpSGreaterThan";
			break;
		case spv::Op::OpUGreaterThanEqual:
			result = "OpUGreaterThanEqual";
			break;
		case spv::Op::OpSGreaterThanEqual:
			result = "OpSGreaterThanEqual";
			break;
		case spv::Op::OpULessThan:
			result = "OpULessThan";
			break;
		case spv::Op::OpSLessThan:
			result = "OpSLessThan";
			break;
		case spv::Op::OpULessThanEqual:
			result = "OpULessThanEqual";
			break;
		case spv::Op::OpSLessThanEqual:
			result = "OpSLessThanEqual";
			break;
		case spv::Op::OpFOrdEqual:
			result = "OpFOrdEqual";
			break;
		case spv::Op::OpFUnordEqual:
			result = "OpFUnordEqual";
			break;
		case spv::Op::OpFOrdNotEqual:
			result = "OpFOrdNotEqual";
			break;
		case spv::Op::OpFUnordNotEqual:
			result = "OpFUnordNotEqual";
			break;
		case spv::Op::OpFOrdLessThan:
			result = "OpFOrdLessThan";
			break;
		case spv::Op::OpFUnordLessThan:
			result = "OpFUnordLessThan";
			break;
		case spv::Op::OpFOrdGreaterThan:
			result = "OpFOrdGreaterThan";
			break;
		case spv::Op::OpFUnordGreaterThan:
			result = "OpFUnordGreaterThan";
			break;
		case spv::Op::OpFOrdLessThanEqual:
			result = "OpFOrdLessThanEqual";
			break;
		case spv::Op::OpFUnordLessThanEqual:
			result = "OpFUnordLessThanEqual";
			break;
		case spv::Op::OpFOrdGreaterThanEqual:
			result = "OpFOrdGreaterThanEqual";
			break;
		case spv::Op::OpFUnordGreaterThanEqual:
			result = "OpFUnordGreaterThanEqual";
			break;
		case spv::Op::OpShiftRightLogical:
			result = "OpShiftRightLogical";
			break;
		case spv::Op::OpShiftRightArithmetic:
			result = "OpShiftRightArithmetic";
			break;
		case spv::Op::OpShiftLeftLogical:
			result = "OpShiftLeftLogical";
			break;
		case spv::Op::OpBitwiseOr:
			result = "OpBitwiseOr";
			break;
		case spv::Op::OpBitwiseXor:
			result = "OpBitwiseXor";
			break;
		case spv::Op::OpBitwiseAnd:
			result = "OpBitwiseAnd";
			break;
		case spv::Op::OpNot:
			result = "OpNot";
			break;
		case spv::Op::OpBitFieldInsert:
			result = "OpBitFieldInsert";
			break;
		case spv::Op::OpBitFieldSExtract:
			result = "OpBitFieldSExtract";
			break;
		case spv::Op::OpBitFieldUExtract:
			result = "OpBitFieldUExtract";
			break;
		case spv::Op::OpBitReverse:
			result = "OpBitReverse";
			break;
		case spv::Op::OpBitCount:
			result = "OpBitCount";
			break;
		case spv::Op::OpDPdx:
			result = "OpDPdx";
			break;
		case spv::Op::OpDPdy:
			result = "OpDPdy";
			break;
		case spv::Op::OpFwidth:
			result = "OpFwidth";
			break;
		case spv::Op::OpDPdxFine:
			result = "OpDPdxFine";
			break;
		case spv::Op::OpDPdyFine:
			result = "OpDPdyFine";
			break;
		case spv::Op::OpFwidthFine:
			result = "OpFwidthFine";
			break;
		case spv::Op::OpDPdxCoarse:
			result = "OpDPdxCoarse";
			break;
		case spv::Op::OpDPdyCoarse:
			result = "OpDPdyCoarse";
			break;
		case spv::Op::OpFwidthCoarse:
			result = "OpFwidthCoarse";
			break;
		case spv::Op::OpEmitVertex:
			result = "OpEmitVertex";
			break;
		case spv::Op::OpEndPrimitive:
			result = "OpEndPrimitive";
			break;
		case spv::Op::OpEmitStreamVertex:
			result = "OpEmitStreamVertex";
			break;
		case spv::Op::OpEndStreamPrimitive:
			result = "OpEndStreamPrimitive";
			break;
		case spv::Op::OpControlBarrier:
			result = "OpControlBarrier";
			break;
		case spv::Op::OpMemoryBarrier:
			result = "OpMemoryBarrier";
			break;
		case spv::Op::OpAtomicLoad:
			result = "OpAtomicLoad";
			break;
		case spv::Op::OpAtomicStore:
			result = "OpAtomicStore";
			break;
		case spv::Op::OpAtomicExchange:
			result = "OpAtomicExchange";
			break;
		case spv::Op::OpAtomicCompareExchange:
			result = "OpAtomicCompareExchange";
			break;
		case spv::Op::OpAtomicCompareExchangeWeak:
			result = "OpAtomicCompareExchangeWeak";
			break;
		case spv::Op::OpAtomicIIncrement:
			result = "OpAtomicIIncrement";
			break;
		case spv::Op::OpAtomicIDecrement:
			result = "OpAtomicIDecrement";
			break;
		case spv::Op::OpAtomicIAdd:
			result = "OpAtomicIAdd";
			break;
		case spv::Op::OpAtomicISub:
			result = "OpAtomicISub";
			break;
		case spv::Op::OpAtomicSMin:
			result = "OpAtomicSMin";
			break;
		case spv::Op::OpAtomicUMin:
			result = "OpAtomicUMin";
			break;
		case spv::Op::OpAtomicSMax:
			result = "OpAtomicSMax";
			break;
		case spv::Op::OpAtomicUMax:
			result = "OpAtomicUMax";
			break;
		case spv::Op::OpAtomicAnd:
			result = "OpAtomicAnd";
			break;
		case spv::Op::OpAtomicOr:
			result = "OpAtomicOr";
			break;
		case spv::Op::OpAtomicXor:
			result = "OpAtomicXor";
			break;
		case spv::Op::OpPhi:
			result = "OpPhi";
			break;
		case spv::Op::OpLoopMerge:
			result = "OpLoopMerge";
			break;
		case spv::Op::OpSelectionMerge:
			result = "OpSelectionMerge";
			break;
		case spv::Op::OpLabel:
			result = "OpLabel";
			break;
		case spv::Op::OpBranch:
			result = "OpBranch";
			break;
		case spv::Op::OpBranchConditional:
			result = "OpBranchConditional";
			break;
		case spv::Op::OpSwitch:
			result = "OpSwitch";
			break;
		case spv::Op::OpKill:
			result = "OpKill";
			break;
		case spv::Op::OpReturn:
			result = "OpReturn";
			break;
		case spv::Op::OpReturnValue:
			result = "OpReturnValue";
			break;
		case spv::Op::OpUnreachable:
			result = "OpUnreachable";
			break;
		case spv::Op::OpLifetimeStart:
			result = "OpLifetimeStart";
			break;
		case spv::Op::OpLifetimeStop:
			result = "OpLifetimeStop";
			break;
		case spv::Op::OpGroupAsyncCopy:
			result = "OpGroupAsyncCopy";
			break;
		case spv::Op::OpGroupWaitEvents:
			result = "OpGroupWaitEvents";
			break;
		case spv::Op::OpGroupAll:
			result = "OpGroupAll";
			break;
		case spv::Op::OpGroupAny:
			result = "OpGroupAny";
			break;
		case spv::Op::OpGroupBroadcast:
			result = "OpGroupBroadcast";
			break;
		case spv::Op::OpGroupIAdd:
			result = "OpGroupIAdd";
			break;
		case spv::Op::OpGroupFAdd:
			result = "OpGroupFAdd";
			break;
		case spv::Op::OpGroupFMin:
			result = "OpGroupFMin";
			break;
		case spv::Op::OpGroupUMin:
			result = "OpGroupUMin";
			break;
		case spv::Op::OpGroupSMin:
			result = "OpGroupSMin";
			break;
		case spv::Op::OpGroupFMax:
			result = "OpGroupFMax";
			break;
		case spv::Op::OpGroupUMax:
			result = "OpGroupUMax";
			break;
		case spv::Op::OpGroupSMax:
			result = "OpGroupSMax";
			break;
		case spv::Op::OpReadPipe:
			result = "OpReadPipe";
			break;
		case spv::Op::OpWritePipe:
			result = "OpWritePipe";
			break;
		case spv::Op::OpReservedReadPipe:
			result = "OpReservedReadPipe";
			break;
		case spv::Op::OpReservedWritePipe:
			result = "OpReservedWritePipe";
			break;
		case spv::Op::OpReserveReadPipePackets:
			result = "OpReserveReadPipePackets";
			break;
		case spv::Op::OpReserveWritePipePackets:
			result = "OpReserveWritePipePackets";
			break;
		case spv::Op::OpCommitReadPipe:
			result = "OpCommitReadPipe";
			break;
		case spv::Op::OpCommitWritePipe:
			result = "OpCommitWritePipe";
			break;
		case spv::Op::OpIsValidReserveId:
			result = "OpIsValidReserveId";
			break;
		case spv::Op::OpGetNumPipePackets:
			result = "OpGetNumPipePackets";
			break;
		case spv::Op::OpGetMaxPipePackets:
			result = "OpGetMaxPipePackets";
			break;
		case spv::Op::OpGroupReserveReadPipePackets:
			result = "OpGroupReserveReadPipePackets";
			break;
		case spv::Op::OpGroupReserveWritePipePackets:
			result = "OpGroupReserveWritePipePackets";
			break;
		case spv::Op::OpGroupCommitReadPipe:
			result = "OpGroupCommitReadPipe";
			break;
		case spv::Op::OpGroupCommitWritePipe:
			result = "OpGroupCommitWritePipe";
			break;
		case spv::Op::OpEnqueueMarker:
			result = "OpEnqueueMarker";
			break;
		case spv::Op::OpEnqueueKernel:
			result = "OpEnqueueKernel";
			break;
		case spv::Op::OpGetKernelNDrangeSubGroupCount:
			result = "OpGetKernelNDrangeSubGroupCount";
			break;
		case spv::Op::OpGetKernelNDrangeMaxSubGroupSize:
			result = "OpGetKernelNDrangeMaxSubGroupSize";
			break;
		case spv::Op::OpGetKernelWorkGroupSize:
			result = "OpGetKernelWorkGroupSize";
			break;
		case spv::Op::OpGetKernelPreferredWorkGroupSizeMultiple:
			result = "OpGetKernelPreferredWorkGroupSizeMultiple";
			break;
		case spv::Op::OpRetainEvent:
			result = "OpRetainEvent";
			break;
		case spv::Op::OpReleaseEvent:
			result = "OpReleaseEvent";
			break;
		case spv::Op::OpCreateUserEvent:
			result = "OpCreateUserEvent";
			break;
		case spv::Op::OpIsValidEvent:
			result = "OpIsValidEvent";
			break;
		case spv::Op::OpSetUserEventStatus:
			result = "OpSetUserEventStatus";
			break;
		case spv::Op::OpCaptureEventProfilingInfo:
			result = "OpCaptureEventProfilingInfo";
			break;
		case spv::Op::OpGetDefaultQueue:
			result = "OpGetDefaultQueue";
			break;
		case spv::Op::OpBuildNDRange:
			result = "OpBuildNDRange";
			break;
		case spv::Op::OpImageSparseSampleImplicitLod:
			result = "OpImageSparseSampleImplicitLod";
			break;
		case spv::Op::OpImageSparseSampleExplicitLod:
			result = "OpImageSparseSampleExplicitLod";
			break;
		case spv::Op::OpImageSparseSampleDrefImplicitLod:
			result = "OpImageSparseSampleDrefImplicitLod";
			break;
		case spv::Op::OpImageSparseSampleDrefExplicitLod:
			result = "OpImageSparseSampleDrefExplicitLod";
			break;
		case spv::Op::OpImageSparseSampleProjImplicitLod:
			result = "OpImageSparseSampleProjImplicitLod";
			break;
		case spv::Op::OpImageSparseSampleProjExplicitLod:
			result = "OpImageSparseSampleProjExplicitLod";
			break;
		case spv::Op::OpImageSparseSampleProjDrefImplicitLod:
			result = "OpImageSparseSampleProjDrefImplicitLod";
			break;
		case spv::Op::OpImageSparseSampleProjDrefExplicitLod:
			result = "OpImageSparseSampleProjDrefExplicitLod";
			break;
		case spv::Op::OpImageSparseFetch:
			result = "OpImageSparseFetch";
			break;
		case spv::Op::OpImageSparseGather:
			result = "OpImageSparseGather";
			break;
		case spv::Op::OpImageSparseDrefGather:
			result = "OpImageSparseDrefGather";
			break;
		case spv::Op::OpImageSparseTexelsResident:
			result = "OpImageSparseTexelsResident";
			break;
		case spv::Op::OpNoLine:
			result = "OpNoLine";
			break;
		case spv::Op::OpAtomicFlagTestAndSet:
			result = "OpAtomicFlagTestAndSet";
			break;
		case spv::Op::OpAtomicFlagClear:
			result = "OpAtomicFlagClear";
			break;
		case spv::Op::OpImageSparseRead:
			result = "OpImageSparseRead";
			break;
		case spv::Op::OpSizeOf:
			result = "OpSizeOf";
			break;
		case spv::Op::OpTypePipeStorage:
			result = "OpTypePipeStorage";
			break;
		case spv::Op::OpConstantPipeStorage:
			result = "OpConstantPipeStorage";
			break;
		case spv::Op::OpCreatePipeFromPipeStorage:
			result = "OpCreatePipeFromPipeStorage";
			break;
		case spv::Op::OpGetKernelLocalSizeForSubgroupCount:
			result = "OpGetKernelLocalSizeForSubgroupCount";
			break;
		case spv::Op::OpGetKernelMaxNumSubgroups:
			result = "OpGetKernelMaxNumSubgroups";
			break;
		case spv::Op::OpTypeNamedBarrier:
			result = "OpTypeNamedBarrier";
			break;
		case spv::Op::OpNamedBarrierInitialize:
			result = "OpNamedBarrierInitialize";
			break;
		case spv::Op::OpMemoryNamedBarrier:
			result = "OpMemoryNamedBarrier";
			break;
		case spv::Op::OpModuleProcessed:
			result = "OpModuleProcessed";
			break;
		case spv::Op::OpExecutionModeId:
			result = "OpExecutionModeId";
			break;
		case spv::Op::OpDecorateId:
			result = "OpDecorateId";
			break;
		case spv::Op::OpSubgroupBallotKHR:
			result = "OpSubgroupBallotKHR";
			break;
		case spv::Op::OpSubgroupFirstInvocationKHR:
			result = "OpSubgroupFirstInvocationKHR";
			break;
		case spv::Op::OpSubgroupAllKHR:
			result = "OpSubgroupAllKHR";
			break;
		case spv::Op::OpSubgroupAnyKHR:
			result = "OpSubgroupAnyKHR";
			break;
		case spv::Op::OpSubgroupAllEqualKHR:
			result = "OpSubgroupAllEqualKHR";
			break;
		case spv::Op::OpSubgroupReadInvocationKHR:
			result = "OpSubgroupReadInvocationKHR";
			break;
		case spv::Op::OpGroupIAddNonUniformAMD:
			result = "OpGroupIAddNonUniformAMD";
			break;
		case spv::Op::OpGroupFAddNonUniformAMD:
			result = "OpGroupFAddNonUniformAMD";
			break;
		case spv::Op::OpGroupFMinNonUniformAMD:
			result = "OpGroupFMinNonUniformAMD";
			break;
		case spv::Op::OpGroupUMinNonUniformAMD:
			result = "OpGroupUMinNonUniformAMD";
			break;
		case spv::Op::OpGroupSMinNonUniformAMD:
			result = "OpGroupSMinNonUniformAMD";
			break;
		case spv::Op::OpGroupFMaxNonUniformAMD:
			result = "OpGroupFMaxNonUniformAMD";
			break;
		case spv::Op::OpGroupUMaxNonUniformAMD:
			result = "OpGroupUMaxNonUniformAMD";
			break;
		case spv::Op::OpGroupSMaxNonUniformAMD:
			result = "OpGroupSMaxNonUniformAMD";
			break;
		case spv::Op::OpFragmentMaskFetchAMD:
			result = "OpFragmentMaskFetchAMD";
			break;
		case spv::Op::OpFragmentFetchAMD:
			result = "OpFragmentFetchAMD";
			break;
		case spv::Op::OpSubgroupShuffleINTEL:
			result = "OpSubgroupShuffleINTEL";
			break;
		case spv::Op::OpSubgroupShuffleDownINTEL:
			result = "OpSubgroupShuffleDownINTEL";
			break;
		case spv::Op::OpSubgroupShuffleUpINTEL:
			result = "OpSubgroupShuffleUpINTEL";
			break;
		case spv::Op::OpSubgroupShuffleXorINTEL:
			result = "OpSubgroupShuffleXorINTEL";
			break;
		case spv::Op::OpSubgroupBlockReadINTEL:
			result = "OpSubgroupBlockReadINTEL";
			break;
		case spv::Op::OpSubgroupBlockWriteINTEL:
			result = "OpSubgroupBlockWriteINTEL";
			break;
		case spv::Op::OpSubgroupImageBlockReadINTEL:
			result = "OpSubgroupImageBlockReadINTEL";
			break;
		case spv::Op::OpSubgroupImageBlockWriteINTEL:
			result = "OpSubgroupImageBlockWriteINTEL";
			break;
		case spv::Op::OpDecorateStringGOOGLE:
			result = "OpDecorateStringGOOGLE";
			break;
		case spv::Op::OpMemberDecorateStringGOOGLE:
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
			result = spv::Op::OpTypeVoid;
			break;
		case ast::type::Kind::eFunction:
			result = spv::Op::OpTypeFunction;
			break;
		case ast::type::Kind::eStruct:
			result = spv::Op::OpTypeStruct;
			break;
		case ast::type::Kind::eBoolean:
			result = spv::Op::OpTypeBool;
			break;
		case ast::type::Kind::eInt:
		case ast::type::Kind::eUInt:
			result = spv::Op::OpTypeInt;
			break;
		case ast::type::Kind::eFloat:
		case ast::type::Kind::eDouble:
			result = spv::Op::OpTypeFloat;
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
			result = spv::Op::OpTypeVector;
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
			result = spv::Op::OpTypeMatrix;
			break;
		case ast::type::Kind::eImage:
			result = spv::Op::OpTypeImage;
			break;
		case ast::type::Kind::eSampledImage:
			result = spv::Op::OpTypeSampledImage;
			break;
		case ast::type::Kind::eSampler:
			result = spv::Op::OpTypeSampler;
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
			result = spv::Op::OpTypeArray;
		}
		else
		{
			result = spv::Op::OpTypeRuntimeArray;
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
		spv::Op result{ spv::Op::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eAdd:
		case ast::expr::Kind::eAddAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFAdd
				: spv::Op::OpIAdd;
			break;
		case ast::expr::Kind::eMinus:
		case ast::expr::Kind::eMinusAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFSub
				: spv::Op::OpISub;
			break;
		case ast::expr::Kind::eTimes:
		case ast::expr::Kind::eTimesAssign:
			result = isMatrixType( lhsTypeKind )
				? ( ( isMatrixType( rhsTypeKind )
					? spv::Op::OpMatrixTimesMatrix
					: ( isVectorType( rhsTypeKind )
						? spv::Op::OpMatrixTimesVector
						: spv::Op::OpMatrixTimesScalar ) ) )
				: ( isVectorType( lhsTypeKind )
					? ( isMatrixType( rhsTypeKind )
						? spv::Op::OpMatrixTimesVector
						: ( isVectorType( rhsTypeKind )
							? ( isAnyFloating( lhsTypeKind, rhsTypeKind )
								? spv::Op::OpFMul
								: spv::Op::OpIMul )
							: spv::Op::OpVectorTimesScalar ) )
					: ( isMatrixType( rhsTypeKind )
						? spv::Op::OpMatrixTimesScalar
						: ( isVectorType( lhsTypeKind )
							? spv::Op::OpVectorTimesScalar
							: ( isAnyFloating( lhsTypeKind, rhsTypeKind )
								? spv::Op::OpFMul
								: spv::Op::OpIMul ) ) ) );
			needMatchingVectors = !( ( isFloatType( getScalarType( lhsTypeKind ) ) || isFloatType( getScalarType( rhsTypeKind ) ) )
				&& ( isVectorType( lhsTypeKind ) || isVectorType( rhsTypeKind ) ) );
			break;
		case ast::expr::Kind::eDivide:
		case ast::expr::Kind::eDivideAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFDiv
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::Op::OpSDiv
					: spv::Op::OpUDiv );
			break;
		case ast::expr::Kind::eModulo:
		case ast::expr::Kind::eModuloAssign:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFMod
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::Op::OpSMod
					: spv::Op::OpUMod );
			break;
		case ast::expr::Kind::eLShift:
		case ast::expr::Kind::eLShiftAssign:
			result = spv::Op::OpShiftLeftLogical;
			break;
		case ast::expr::Kind::eRShift:
		case ast::expr::Kind::eRShiftAssign:
			result = spv::Op::OpShiftRightArithmetic;
			break;
		case ast::expr::Kind::eBitAnd:
		case ast::expr::Kind::eAndAssign:
			result = spv::Op::OpBitwiseAnd;
			break;
		case ast::expr::Kind::eBitNot:
			assert( "Unexpected ast::expr::Kind::eBitNot" );
			break;
		case ast::expr::Kind::eNotAssign:
			result = spv::Op::OpNot;
			break;
		case ast::expr::Kind::eBitOr:
		case ast::expr::Kind::eOrAssign:
			result = spv::Op::OpBitwiseOr;
			break;
		case ast::expr::Kind::eBitXor:
		case ast::expr::Kind::eXorAssign:
			result = spv::Op::OpBitwiseXor;
			break;
		case ast::expr::Kind::eLogAnd:
			result = spv::Op::OpLogicalAnd;
			needMatchingVectors = false;
			break;
		case ast::expr::Kind::eLogNot:
			assert( "Unexpected ast::expr::Kind::eBitNot" );
			break;
		case ast::expr::Kind::eLogOr:
			result = spv::Op::OpLogicalOr;
			needMatchingVectors = false;
			break;
		case ast::expr::Kind::eCast:
			assert( "Unexpected ast::expr::Kind::eCast" );
			break;
		case ast::expr::Kind::eInit:
			result = spv::Op::OpStore;
			break;
		case ast::expr::Kind::eAggrInit:
			result = spv::Op::OpStore;
			break;
		case ast::expr::Kind::eFnCall:
			assert( "Unexpected ast::expr::Kind::eFnCall" );
			break;
		case ast::expr::Kind::eEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFOrdEqual
				: isAnyBool( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpLogicalEqual
				: spv::Op::OpIEqual;
			break;
		case ast::expr::Kind::eGreater:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFOrdGreaterThan
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::Op::OpSGreaterThan
					: spv::Op::OpUGreaterThan );
			break;
		case ast::expr::Kind::eGreaterEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFOrdGreaterThanEqual
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::Op::OpSGreaterThanEqual
					: spv::Op::OpUGreaterThanEqual );
			break;
		case ast::expr::Kind::eLess:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFOrdLessThan
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::Op::OpSLessThan
					: spv::Op::OpULessThan );
			break;
		case ast::expr::Kind::eLessEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFOrdLessThanEqual
				: ( isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::Op::OpSLessThanEqual
					: spv::Op::OpULessThanEqual );
			break;
		case ast::expr::Kind::eNotEqual:
			result = isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpFOrdNotEqual
				: isAnyBool( lhsTypeKind, rhsTypeKind )
				? spv::Op::OpLogicalNotEqual
				: spv::Op::OpINotEqual;
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
		spv::Op result{ spv::Op::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eBitNot:
		case ast::expr::Kind::eNotAssign:
			result = spv::Op::OpNot;
			break;
		case ast::expr::Kind::eLogNot:
			result = spv::Op::OpLogicalNot;
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
				? spv::Op::OpFNegate
				: spv::Op::OpSNegate;
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
		spv::Op result{ spv::Op::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eAdd:
		case ast::expr::Kind::eAddAssign:
			result = isFloating( typeKind )
				? spv::Op::OpFAdd
				: spv::Op::OpIAdd;
			break;
		case ast::expr::Kind::eMinus:
		case ast::expr::Kind::eMinusAssign:
			result = isFloating( typeKind )
				? spv::Op::OpFSub
				: spv::Op::OpISub;
			break;
		case ast::expr::Kind::eTimes:
		case ast::expr::Kind::eTimesAssign:
			result = isFloating( typeKind )
				? spv::Op::OpFMul
				: spv::Op::OpIMul;
			break;
		case ast::expr::Kind::eDivide:
		case ast::expr::Kind::eDivideAssign:
			result = isFloating( typeKind )
				? spv::Op::OpFDiv
				: ( isSigned( typeKind )
					? spv::Op::OpSDiv
					: spv::Op::OpUDiv );
			break;
		case ast::expr::Kind::eModulo:
		case ast::expr::Kind::eModuloAssign:
			result = isFloating( typeKind )
				? spv::Op::OpFMod
				: ( isSigned( typeKind )
					? spv::Op::OpSMod
					: spv::Op::OpUMod );
			break;
		case ast::expr::Kind::eLShift:
		case ast::expr::Kind::eLShiftAssign:
			result = spv::Op::OpShiftLeftLogical;
			break;
		case ast::expr::Kind::eRShift:
		case ast::expr::Kind::eRShiftAssign:
			result = spv::Op::OpShiftRightArithmetic;
			break;
		case ast::expr::Kind::eBitAnd:
		case ast::expr::Kind::eAndAssign:
			result = spv::Op::OpBitwiseAnd;
			break;
		case ast::expr::Kind::eBitNot:
		case ast::expr::Kind::eNotAssign:
			result = spv::Op::OpNot;
			break;
		case ast::expr::Kind::eBitOr:
		case ast::expr::Kind::eOrAssign:
			result = spv::Op::OpBitwiseOr;
			break;
		case ast::expr::Kind::eBitXor:
		case ast::expr::Kind::eXorAssign:
			result = spv::Op::OpBitwiseXor;
			break;
		case ast::expr::Kind::eLogAnd:
			result = spv::Op::OpLogicalAnd;
			break;
		case ast::expr::Kind::eLogNot:
			result = spv::Op::OpLogicalNot;
			break;
		case ast::expr::Kind::eLogOr:
			result = spv::Op::OpLogicalOr;
			break;
		case ast::expr::Kind::eCast:
			assert( false && "Unexpected ast::expr::Kind::eCast" );
			break;
		case ast::expr::Kind::eInit:
			result = spv::Op::OpStore;
			break;
		case ast::expr::Kind::eAggrInit:
			result = spv::Op::OpStore;
			break;
		case ast::expr::Kind::eFnCall:
			result = spv::Op::OpFunctionCall;
			break;
		case ast::expr::Kind::eEqual:
			result = isFloating( typeKind )
				? spv::Op::OpFOrdEqual
				: spv::Op::OpIEqual;
			break;
		case ast::expr::Kind::eGreater:
			result = isFloating( typeKind )
				? spv::Op::OpFOrdGreaterThan
				: ( isSigned( typeKind )
					? spv::Op::OpSGreaterThan
					: spv::Op::OpUGreaterThan );
			break;
		case ast::expr::Kind::eGreaterEqual:
			result = isFloating( typeKind )
				? spv::Op::OpFOrdGreaterThanEqual
				: ( isSigned( typeKind )
					? spv::Op::OpSGreaterThanEqual
					: spv::Op::OpUGreaterThanEqual );
			break;
		case ast::expr::Kind::eLess:
			result = isFloating( typeKind )
				? spv::Op::OpFOrdLessThan
				: ( isSigned( typeKind )
					? spv::Op::OpSLessThan
					: spv::Op::OpULessThan );
			break;
		case ast::expr::Kind::eLessEqual:
			result = isFloating( typeKind )
				? spv::Op::OpFOrdLessThanEqual
				: ( isSigned( typeKind )
					? spv::Op::OpSLessThanEqual
					: spv::Op::OpULessThanEqual );
			break;
		case ast::expr::Kind::eNotEqual:
			result = isFloating( typeKind )
				? spv::Op::OpFOrdNotEqual
				: spv::Op::OpINotEqual;
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
			result = spv::Op::OpAccessChain;
			break;
		case ast::expr::Kind::eSwitchTest:
			result = spv::Op::OpSwitch;
			break;
		case ast::expr::Kind::eSwitchCase:
			result = spv::Op::OpLabel;
			break;
		case ast::expr::Kind::eQuestion:
			result = spv::Op::OpSelect;
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
				? spv::Op::OpFNegate
				:  spv::Op::OpSNegate;
			break;
		case ast::expr::Kind::eUnaryPlus:
			assert( false && "Unexpected ast::expr::Kind::eUnaryPlus" );
			break;
		case ast::expr::Kind::eAssign:
			result = spv::Op::OpStore;
			break;
		case ast::expr::Kind::eArrayAccess:
			result = spv::Op::OpAccessChain;
			break;
		default:
			break;
		}

		return result;
	}

	//*************************************************************************
}
