/*
See LICENSE file in root folder
*/
#include "SpirVOpHelpers.hpp"

namespace spirv
{
	//*************************************************************************

	namespace ophlp
	{
		static bool isFloating( ast::type::Kind kind )
		{
			return kind == ast::type::Kind::eHalf
				|| kind == ast::type::Kind::eFloat
				|| kind == ast::type::Kind::eDouble
				|| kind == ast::type::Kind::eVec2H
				|| kind == ast::type::Kind::eVec4H
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

		static bool isSigned( ast::type::Kind kind )
		{
			return kind == ast::type::Kind::eInt8
				|| kind == ast::type::Kind::eInt16
				|| kind == ast::type::Kind::eInt32
				|| kind == ast::type::Kind::eInt64
				|| kind == ast::type::Kind::eVec2I8
				|| kind == ast::type::Kind::eVec3I8
				|| kind == ast::type::Kind::eVec4I8
				|| kind == ast::type::Kind::eVec2I16
				|| kind == ast::type::Kind::eVec3I16
				|| kind == ast::type::Kind::eVec4I16
				|| kind == ast::type::Kind::eVec2I32
				|| kind == ast::type::Kind::eVec3I32
				|| kind == ast::type::Kind::eVec4I32
				|| kind == ast::type::Kind::eVec2I64
				|| kind == ast::type::Kind::eVec3I64
				|| kind == ast::type::Kind::eVec4I64;
		}

		static bool isBool( ast::type::Kind kind )
		{
			return kind == ast::type::Kind::eBoolean
				|| kind == ast::type::Kind::eVec2B
				|| kind == ast::type::Kind::eVec3B
				|| kind == ast::type::Kind::eVec4B;
		}

		static bool isAnyBool( ast::type::Kind lhsTypeKind
			, ast::type::Kind rhsTypeKind )
		{
			return isBool( lhsTypeKind )
				|| isBool( rhsTypeKind );
		}

		static bool isAnySigned( ast::type::Kind lhsTypeKind
			, ast::type::Kind rhsTypeKind )
		{
			return isSigned( lhsTypeKind )
				|| isSigned( rhsTypeKind );
		}

		static bool isAnyFloating( ast::type::Kind lhsTypeKind
			, ast::type::Kind rhsTypeKind )
		{
			return isFloating( lhsTypeKind )
				|| isFloating( rhsTypeKind );
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
		case spv::OpIgnoreIntersectionKHR:
		case spv::OpTerminateRayKHR:
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
		case spv::OpExecuteCallableKHR:
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
		case spv::OpConvertUToAccelerationStructureKHR:
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
		case spv::OpReportIntersectionKHR:
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
		case spv::OpTraceRayKHR:
			result = 12u;
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
		default:
			break;
		}

		assert( result != 0u );
		return result;
	}

	std::string getOpName( spv::Op op )
	{
		switch ( op )
		{
		case spv::OpNop:
			return "Nop";
		case spv::OpUndef:
			return "Undef";
		case spv::OpSourceContinued:
			return "SourceContinued";
		case spv::OpSource:
			return "Source";
		case spv::OpSourceExtension:
			return "SourceExtension";
		case spv::OpName:
			return "Name";
		case spv::OpMemberName:
			return "MemberName";
		case spv::OpString:
			return "String";
		case spv::OpLine:
			return "Line";
		case spv::OpExtension:
			return "Extension";
		case spv::OpExtInstImport:
			return "ExtInstImport";
		case spv::OpExtInst:
			return "ExtInst";
		case spv::OpMemoryModel:
			return "MemoryModel";
		case spv::OpEntryPoint:
			return "EntryPoint";
		case spv::OpExecutionMode:
			return "ExecutionMode";
		case spv::OpCapability:
			return "Capability";
		case spv::OpTypeVoid:
			return "TypeVoid";
		case spv::OpTypeBool:
			return "TypeBool";
		case spv::OpTypeInt:
			return "TypeInt";
		case spv::OpTypeFloat:
			return "TypeFloat";
		case spv::OpTypeVector:
			return "TypeVector";
		case spv::OpTypeMatrix:
			return "TypeMatrix";
		case spv::OpTypeImage:
			return "TypeImage";
		case spv::OpTypeSampler:
			return "TypeSampler";
		case spv::OpTypeSampledImage:
			return "TypeSampledImage";
		case spv::OpTypeArray:
			return "TypeArray";
		case spv::OpTypeRuntimeArray:
			return "TypeRuntimeArray";
		case spv::OpTypeStruct:
			return "TypeStruct";
		case spv::OpTypeOpaque:
			return "TypeOpaque";
		case spv::OpTypePointer:
			return "TypePointer";
		case spv::OpTypeFunction:
			return "TypeFunction";
		case spv::OpTypeEvent:
			return "TypeEvent";
		case spv::OpTypeDeviceEvent:
			return "TypeDeviceEvent";
		case spv::OpTypeReserveId:
			return "TypeReserveId";
		case spv::OpTypeQueue:
			return "TypeQueue";
		case spv::OpTypePipe:
			return "TypePipe";
		case spv::OpTypeForwardPointer:
			return "TypeForwardPointer";
		case spv::OpConstantTrue:
			return "ConstantTrue";
		case spv::OpConstantFalse:
			return "ConstantFalse";
		case spv::OpConstant:
			return "Constant";
		case spv::OpConstantComposite:
			return "ConstantComposite";
		case spv::OpConstantSampler:
			return "ConstantSampler";
		case spv::OpConstantNull:
			return "ConstantNull";
		case spv::OpSpecConstantTrue:
			return "SpecConstantTrue";
		case spv::OpSpecConstantFalse:
			return "SpecConstantFalse";
		case spv::OpSpecConstant:
			return "SpecConstant";
		case spv::OpSpecConstantComposite:
			return "SpecConstantComposite";
		case spv::OpSpecConstantOp:
			return "SpecConstantOp";
		case spv::OpFunction:
			return "Function";
		case spv::OpFunctionParameter:
			return "FunctionParameter";
		case spv::OpFunctionEnd:
			return "FunctionEnd";
		case spv::OpFunctionCall:
			return "FunctionCall";
		case spv::OpVariable:
			return "Variable";
		case spv::OpImageTexelPointer:
			return "ImageTexelPointer";
		case spv::OpLoad:
			return "Load";
		case spv::OpStore:
			return "Store";
		case spv::OpCopyMemory:
			return "CopyMemory";
		case spv::OpCopyMemorySized:
			return "CopyMemorySized";
		case spv::OpAccessChain:
			return "AccessChain";
		case spv::OpInBoundsAccessChain:
			return "InBoundsAccessChain";
		case spv::OpPtrAccessChain:
			return "PtrAccessChain";
		case spv::OpArrayLength:
			return "ArrayLength";
		case spv::OpGenericPtrMemSemantics:
			return "GenericPtrMemSemantics";
		case spv::OpInBoundsPtrAccessChain:
			return "InBoundsPtrAccessChain";
		case spv::OpDecorate:
			return "Decorate";
		case spv::OpMemberDecorate:
			return "MemberDecorate";
		case spv::OpDecorationGroup:
			return "DecorationGroup";
		case spv::OpGroupDecorate:
			return "GroupDecorate";
		case spv::OpGroupMemberDecorate:
			return "GroupMemberDecorate";
		case spv::OpVectorExtractDynamic:
			return "VectorExtractDynamic";
		case spv::OpVectorInsertDynamic:
			return "VectorInsertDynamic";
		case spv::OpVectorShuffle:
			return "VectorShuffle";
		case spv::OpCompositeConstruct:
			return "CompositeConstruct";
		case spv::OpCompositeExtract:
			return "CompositeExtract";
		case spv::OpCompositeInsert:
			return "CompositeInsert";
		case spv::OpCopyObject:
			return "CopyObject";
		case spv::OpTranspose:
			return "Transpose";
		case spv::OpSampledImage:
			return "SampledImage";
		case spv::OpImageSampleImplicitLod:
			return "ImageSampleImplicitLod";
		case spv::OpImageSampleExplicitLod:
			return "ImageSampleExplicitLod";
		case spv::OpImageSampleDrefImplicitLod:
			return "ImageSampleDrefImplicitLod";
		case spv::OpImageSampleDrefExplicitLod:
			return "ImageSampleDrefExplicitLod";
		case spv::OpImageSampleProjImplicitLod:
			return "ImageSampleProjImplicitLod";
		case spv::OpImageSampleProjExplicitLod:
			return "ImageSampleProjExplicitLod";
		case spv::OpImageSampleProjDrefImplicitLod:
			return "ImageSampleProjDrefImplicitLod";
		case spv::OpImageSampleProjDrefExplicitLod:
			return "ImageSampleProjDrefExplicitLod";
		case spv::OpImageFetch:
			return "ImageFetch";
		case spv::OpImageGather:
			return "ImageGather";
		case spv::OpImageDrefGather:
			return "ImageDrefGather";
		case spv::OpImageRead:
			return "ImageRead";
		case spv::OpImageWrite:
			return "ImageWrite";
		case spv::OpImage:
			return "Image";
		case spv::OpImageQueryFormat:
			return "ImageQueryFormat";
		case spv::OpImageQueryOrder:
			return "ImageQueryOrder";
		case spv::OpImageQuerySizeLod:
			return "ImageQuerySizeLod";
		case spv::OpImageQuerySize:
			return "ImageQuerySize";
		case spv::OpImageQueryLod:
			return "ImageQueryLod";
		case spv::OpImageQueryLevels:
			return "ImageQueryLevels";
		case spv::OpImageQuerySamples:
			return "ImageQuerySamples";
		case spv::OpConvertFToU:
			return "ConvertFToU";
		case spv::OpConvertFToS:
			return "ConvertFToS";
		case spv::OpConvertSToF:
			return "ConvertSToF";
		case spv::OpConvertUToF:
			return "ConvertUToF";
		case spv::OpUConvert:
			return "UConvert";
		case spv::OpSConvert:
			return "SConvert";
		case spv::OpFConvert:
			return "FConvert";
		case spv::OpQuantizeToF16:
			return "QuantizeToF16";
		case spv::OpConvertPtrToU:
			return "ConvertPtrToU";
		case spv::OpSatConvertSToU:
			return "SatConvertSToU";
		case spv::OpSatConvertUToS:
			return "SatConvertUToS";
		case spv::OpConvertUToPtr:
			return "ConvertUToPtr";
		case spv::OpPtrCastToGeneric:
			return "PtrCastToGeneric";
		case spv::OpGenericCastToPtr:
			return "GenericCastToPtr";
		case spv::OpGenericCastToPtrExplicit:
			return "GenericCastToPtrExplicit";
		case spv::OpBitcast:
			return "Bitcast";
		case spv::OpSNegate:
			return "SNegate";
		case spv::OpFNegate:
			return "FNegate";
		case spv::OpIAdd:
			return "IAdd";
		case spv::OpFAdd:
			return "FAdd";
		case spv::OpISub:
			return "ISub";
		case spv::OpFSub:
			return "FSub";
		case spv::OpIMul:
			return "IMul";
		case spv::OpFMul:
			return "FMul";
		case spv::OpUDiv:
			return "UDiv";
		case spv::OpSDiv:
			return "SDiv";
		case spv::OpFDiv:
			return "FDiv";
		case spv::OpUMod:
			return "UMod";
		case spv::OpSRem:
			return "SRem";
		case spv::OpSMod:
			return "SMod";
		case spv::OpFRem:
			return "FRem";
		case spv::OpFMod:
			return "FMod";
		case spv::OpVectorTimesScalar:
			return "VectorTimesScalar";
		case spv::OpMatrixTimesScalar:
			return "MatrixTimesScalar";
		case spv::OpVectorTimesMatrix:
			return "VectorTimesMatrix";
		case spv::OpMatrixTimesVector:
			return "MatrixTimesVector";
		case spv::OpMatrixTimesMatrix:
			return "MatrixTimesMatrix";
		case spv::OpOuterProduct:
			return "OuterProduct";
		case spv::OpDot:
			return "Dot";
		case spv::OpIAddCarry:
			return "IAddCarry";
		case spv::OpISubBorrow:
			return "ISubBorrow";
		case spv::OpUMulExtended:
			return "UMulExtended";
		case spv::OpSMulExtended:
			return "SMulExtended";
		case spv::OpAny:
			return "Any";
		case spv::OpAll:
			return "All";
		case spv::OpIsNan:
			return "IsNan";
		case spv::OpIsInf:
			return "IsInf";
		case spv::OpIsFinite:
			return "IsFinite";
		case spv::OpIsNormal:
			return "IsNormal";
		case spv::OpSignBitSet:
			return "SignBitSet";
		case spv::OpLessOrGreater:
			return "LessOrGreater";
		case spv::OpOrdered:
			return "Ordered";
		case spv::OpUnordered:
			return "Unordered";
		case spv::OpLogicalEqual:
			return "LogicalEqual";
		case spv::OpLogicalNotEqual:
			return "LogicalNotEqual";
		case spv::OpLogicalOr:
			return "LogicalOr";
		case spv::OpLogicalAnd:
			return "LogicalAnd";
		case spv::OpLogicalNot:
			return "LogicalNot";
		case spv::OpSelect:
			return "Select";
		case spv::OpIEqual:
			return "IEqual";
		case spv::OpINotEqual:
			return "INotEqual";
		case spv::OpUGreaterThan:
			return "UGreaterThan";
		case spv::OpSGreaterThan:
			return "SGreaterThan";
		case spv::OpUGreaterThanEqual:
			return "UGreaterThanEqual";
		case spv::OpSGreaterThanEqual:
			return "SGreaterThanEqual";
		case spv::OpULessThan:
			return "ULessThan";
		case spv::OpSLessThan:
			return "SLessThan";
		case spv::OpULessThanEqual:
			return "ULessThanEqual";
		case spv::OpSLessThanEqual:
			return "SLessThanEqual";
		case spv::OpFOrdEqual:
			return "FOrdEqual";
		case spv::OpFUnordEqual:
			return "FUnordEqual";
		case spv::OpFOrdNotEqual:
			return "FOrdNotEqual";
		case spv::OpFUnordNotEqual:
			return "FUnordNotEqual";
		case spv::OpFOrdLessThan:
			return "FOrdLessThan";
		case spv::OpFUnordLessThan:
			return "FUnordLessThan";
		case spv::OpFOrdGreaterThan:
			return "FOrdGreaterThan";
		case spv::OpFUnordGreaterThan:
			return "FUnordGreaterThan";
		case spv::OpFOrdLessThanEqual:
			return "FOrdLessThanEqual";
		case spv::OpFUnordLessThanEqual:
			return "FUnordLessThanEqual";
		case spv::OpFOrdGreaterThanEqual:
			return "FOrdGreaterThanEqual";
		case spv::OpFUnordGreaterThanEqual:
			return "FUnordGreaterThanEqual";
		case spv::OpShiftRightLogical:
			return "ShiftRightLogical";
		case spv::OpShiftRightArithmetic:
			return "ShiftRightArithmetic";
		case spv::OpShiftLeftLogical:
			return "ShiftLeftLogical";
		case spv::OpBitwiseOr:
			return "BitwiseOr";
		case spv::OpBitwiseXor:
			return "BitwiseXor";
		case spv::OpBitwiseAnd:
			return "BitwiseAnd";
		case spv::OpNot:
			return "Not";
		case spv::OpBitFieldInsert:
			return "BitFieldInsert";
		case spv::OpBitFieldSExtract:
			return "BitFieldSExtract";
		case spv::OpBitFieldUExtract:
			return "BitFieldUExtract";
		case spv::OpBitReverse:
			return "BitReverse";
		case spv::OpBitCount:
			return "BitCount";
		case spv::OpDPdx:
			return "DPdx";
		case spv::OpDPdy:
			return "DPdy";
		case spv::OpFwidth:
			return "Fwidth";
		case spv::OpDPdxFine:
			return "DPdxFine";
		case spv::OpDPdyFine:
			return "DPdyFine";
		case spv::OpFwidthFine:
			return "FwidthFine";
		case spv::OpDPdxCoarse:
			return "DPdxCoarse";
		case spv::OpDPdyCoarse:
			return "DPdyCoarse";
		case spv::OpFwidthCoarse:
			return "FwidthCoarse";
		case spv::OpEmitVertex:
			return "EmitVertex";
		case spv::OpEndPrimitive:
			return "EndPrimitive";
		case spv::OpEmitStreamVertex:
			return "EmitStreamVertex";
		case spv::OpEndStreamPrimitive:
			return "EndStreamPrimitive";
		case spv::OpControlBarrier:
			return "ControlBarrier";
		case spv::OpMemoryBarrier:
			return "MemoryBarrier";
		case spv::OpAtomicLoad:
			return "AtomicLoad";
		case spv::OpAtomicStore:
			return "AtomicStore";
		case spv::OpAtomicExchange:
			return "AtomicExchange";
		case spv::OpAtomicCompareExchange:
			return "AtomicCompareExchange";
		case spv::OpAtomicCompareExchangeWeak:
			return "AtomicCompareExchangeWeak";
		case spv::OpAtomicIIncrement:
			return "AtomicIIncrement";
		case spv::OpAtomicIDecrement:
			return "AtomicIDecrement";
		case spv::OpAtomicIAdd:
			return "AtomicIAdd";
		case spv::OpAtomicISub:
			return "AtomicISub";
		case spv::OpAtomicSMin:
			return "AtomicSMin";
		case spv::OpAtomicUMin:
			return "AtomicUMin";
		case spv::OpAtomicSMax:
			return "AtomicSMax";
		case spv::OpAtomicUMax:
			return "AtomicUMax";
		case spv::OpAtomicAnd:
			return "AtomicAnd";
		case spv::OpAtomicOr:
			return "AtomicOr";
		case spv::OpAtomicXor:
			return "AtomicXor";
		case spv::OpPhi:
			return "Phi";
		case spv::OpLoopMerge:
			return "LoopMerge";
		case spv::OpSelectionMerge:
			return "SelectionMerge";
		case spv::OpLabel:
			return "Label";
		case spv::OpBranch:
			return "Branch";
		case spv::OpBranchConditional:
			return "BranchConditional";
		case spv::OpSwitch:
			return "Switch";
		case spv::OpKill:
			return "Kill";
		case spv::OpReturn:
			return "Return";
		case spv::OpReturnValue:
			return "ReturnValue";
		case spv::OpUnreachable:
			return "Unreachable";
		case spv::OpLifetimeStart:
			return "LifetimeStart";
		case spv::OpLifetimeStop:
			return "LifetimeStop";
		case spv::OpGroupAsyncCopy:
			return "GroupAsyncCopy";
		case spv::OpGroupWaitEvents:
			return "GroupWaitEvents";
		case spv::OpGroupAll:
			return "GroupAll";
		case spv::OpGroupAny:
			return "GroupAny";
		case spv::OpGroupBroadcast:
			return "GroupBroadcast";
		case spv::OpGroupIAdd:
			return "GroupIAdd";
		case spv::OpGroupFAdd:
			return "GroupFAdd";
		case spv::OpGroupFMin:
			return "GroupFMin";
		case spv::OpGroupUMin:
			return "GroupUMin";
		case spv::OpGroupSMin:
			return "GroupSMin";
		case spv::OpGroupFMax:
			return "GroupFMax";
		case spv::OpGroupUMax:
			return "GroupUMax";
		case spv::OpGroupSMax:
			return "GroupSMax";
		case spv::OpReadPipe:
			return "ReadPipe";
		case spv::OpWritePipe:
			return "WritePipe";
		case spv::OpReservedReadPipe:
			return "ReservedReadPipe";
		case spv::OpReservedWritePipe:
			return "ReservedWritePipe";
		case spv::OpReserveReadPipePackets:
			return "ReserveReadPipePackets";
		case spv::OpReserveWritePipePackets:
			return "ReserveWritePipePackets";
		case spv::OpCommitReadPipe:
			return "CommitReadPipe";
		case spv::OpCommitWritePipe:
			return "CommitWritePipe";
		case spv::OpIsValidReserveId:
			return "IsValidReserveId";
		case spv::OpGetNumPipePackets:
			return "GetNumPipePackets";
		case spv::OpGetMaxPipePackets:
			return "GetMaxPipePackets";
		case spv::OpGroupReserveReadPipePackets:
			return "GroupReserveReadPipePackets";
		case spv::OpGroupReserveWritePipePackets:
			return "GroupReserveWritePipePackets";
		case spv::OpGroupCommitReadPipe:
			return "GroupCommitReadPipe";
		case spv::OpGroupCommitWritePipe:
			return "GroupCommitWritePipe";
		case spv::OpEnqueueMarker:
			return "EnqueueMarker";
		case spv::OpEnqueueKernel:
			return "EnqueueKernel";
		case spv::OpGetKernelNDrangeSubGroupCount:
			return "GetKernelNDrangeSubGroupCount";
		case spv::OpGetKernelNDrangeMaxSubGroupSize:
			return "GetKernelNDrangeMaxSubGroupSize";
		case spv::OpGetKernelWorkGroupSize:
			return "GetKernelWorkGroupSize";
		case spv::OpGetKernelPreferredWorkGroupSizeMultiple:
			return "GetKernelPreferredWorkGroupSizeMultiple";
		case spv::OpRetainEvent:
			return "RetainEvent";
		case spv::OpReleaseEvent:
			return "ReleaseEvent";
		case spv::OpCreateUserEvent:
			return "CreateUserEvent";
		case spv::OpIsValidEvent:
			return "IsValidEvent";
		case spv::OpSetUserEventStatus:
			return "SetUserEventStatus";
		case spv::OpCaptureEventProfilingInfo:
			return "CaptureEventProfilingInfo";
		case spv::OpGetDefaultQueue:
			return "GetDefaultQueue";
		case spv::OpBuildNDRange:
			return "BuildNDRange";
		case spv::OpImageSparseSampleImplicitLod:
			return "ImageSparseSampleImplicitLod";
		case spv::OpImageSparseSampleExplicitLod:
			return "ImageSparseSampleExplicitLod";
		case spv::OpImageSparseSampleDrefImplicitLod:
			return "ImageSparseSampleDrefImplicitLod";
		case spv::OpImageSparseSampleDrefExplicitLod:
			return "ImageSparseSampleDrefExplicitLod";
		case spv::OpImageSparseSampleProjImplicitLod:
			return "ImageSparseSampleProjImplicitLod";
		case spv::OpImageSparseSampleProjExplicitLod:
			return "ImageSparseSampleProjExplicitLod";
		case spv::OpImageSparseSampleProjDrefImplicitLod:
			return "ImageSparseSampleProjDrefImplicitLod";
		case spv::OpImageSparseSampleProjDrefExplicitLod:
			return "ImageSparseSampleProjDrefExplicitLod";
		case spv::OpImageSparseFetch:
			return "ImageSparseFetch";
		case spv::OpImageSparseGather:
			return "ImageSparseGather";
		case spv::OpImageSparseDrefGather:
			return "ImageSparseDrefGather";
		case spv::OpImageSparseTexelsResident:
			return "ImageSparseTexelsResident";
		case spv::OpNoLine:
			return "NoLine";
		case spv::OpAtomicFlagTestAndSet:
			return "AtomicFlagTestAndSet";
		case spv::OpAtomicFlagClear:
			return "AtomicFlagClear";
		case spv::OpImageSparseRead:
			return "ImageSparseRead";
		case spv::OpSizeOf:
			return "SizeOf";
		case spv::OpTypePipeStorage:
			return "TypePipeStorage";
		case spv::OpConstantPipeStorage:
			return "ConstantPipeStorage";
		case spv::OpCreatePipeFromPipeStorage:
			return "CreatePipeFromPipeStorage";
		case spv::OpGetKernelLocalSizeForSubgroupCount:
			return "GetKernelLocalSizeForSubgroupCount";
		case spv::OpGetKernelMaxNumSubgroups:
			return "GetKernelMaxNumSubgroups";
		case spv::OpTypeNamedBarrier:
			return "TypeNamedBarrier";
		case spv::OpNamedBarrierInitialize:
			return "NamedBarrierInitialize";
		case spv::OpMemoryNamedBarrier:
			return "MemoryNamedBarrier";
		case spv::OpModuleProcessed:
			return "ModuleProcessed";
		case spv::OpExecutionModeId:
			return "ExecutionModeId";
		case spv::OpDecorateId:
			return "DecorateId";
		case spv::OpGroupNonUniformElect:
			return "GroupNonUniformElect";
		case spv::OpGroupNonUniformAll:
			return "GroupNonUniformAll";
		case spv::OpGroupNonUniformAny:
			return "GroupNonUniformAny";
		case spv::OpGroupNonUniformAllEqual:
			return "GroupNonUniformAllEqual";
		case spv::OpGroupNonUniformBroadcast:
			return "GroupNonUniformBroadcast";
		case spv::OpGroupNonUniformBroadcastFirst:
			return "GroupNonUniformBroadcastFirst";
		case spv::OpGroupNonUniformBallot:
			return "GroupNonUniformBallot";
		case spv::OpGroupNonUniformInverseBallot:
			return "GroupNonUniformInverseBallot";
		case spv::OpGroupNonUniformBallotBitExtract:
			return "GroupNonUniformBallotBitExtract";
		case spv::OpGroupNonUniformBallotBitCount:
			return "GroupNonUniformBallotBitCount";
		case spv::OpGroupNonUniformBallotFindLSB:
			return "GroupNonUniformBallotFindLSB";
		case spv::OpGroupNonUniformBallotFindMSB:
			return "GroupNonUniformBallotFindMSB";
		case spv::OpGroupNonUniformShuffle:
			return "GroupNonUniformShuffle";
		case spv::OpGroupNonUniformShuffleXor:
			return "GroupNonUniformShuffleXor";
		case spv::OpGroupNonUniformShuffleUp:
			return "GroupNonUniformShuffleUp";
		case spv::OpGroupNonUniformShuffleDown:
			return "GroupNonUniformShuffleDown";
		case spv::OpGroupNonUniformIAdd:
			return "GroupNonUniformIAdd";
		case spv::OpGroupNonUniformFAdd:
			return "GroupNonUniformFAdd";
		case spv::OpGroupNonUniformIMul:
			return "GroupNonUniformIMul";
		case spv::OpGroupNonUniformFMul:
			return "GroupNonUniformFMul";
		case spv::OpGroupNonUniformSMin:
			return "GroupNonUniformSMin";
		case spv::OpGroupNonUniformUMin:
			return "GroupNonUniformUMin";
		case spv::OpGroupNonUniformFMin:
			return "GroupNonUniformFMin";
		case spv::OpGroupNonUniformSMax:
			return "GroupNonUniformSMax";
		case spv::OpGroupNonUniformUMax:
			return "GroupNonUniformUMax";
		case spv::OpGroupNonUniformFMax:
			return "GroupNonUniformFMax";
		case spv::OpGroupNonUniformBitwiseAnd:
			return "GroupNonUniformBitwiseAnd";
		case spv::OpGroupNonUniformBitwiseOr:
			return "GroupNonUniformBitwiseOr";
		case spv::OpGroupNonUniformBitwiseXor:
			return "GroupNonUniformBitwiseXor";
		case spv::OpGroupNonUniformLogicalAnd:
			return "GroupNonUniformLogicalAnd";
		case spv::OpGroupNonUniformLogicalOr:
			return "GroupNonUniformLogicalOr";
		case spv::OpGroupNonUniformLogicalXor:
			return "GroupNonUniformLogicalXor";
		case spv::OpGroupNonUniformQuadBroadcast:
			return "GroupNonUniformQuadBroadcast";
		case spv::OpGroupNonUniformQuadSwap:
			return "GroupNonUniformQuadSwap";
		case spv::OpCopyLogical:
			return "CopyLogical";
		case spv::OpPtrEqual:
			return "PtrEqual";
		case spv::OpPtrNotEqual:
			return "PtrNotEqual";
		case spv::OpPtrDiff:
			return "PtrDiff";
		case spv::OpColorAttachmentReadEXT:
			return "ColorAttachmentReadEXT";
		case spv::OpDepthAttachmentReadEXT:
			return "DepthAttachmentReadEXT";
		case spv::OpStencilAttachmentReadEXT:
			return "StencilAttachmentReadEXT";
		case spv::OpTerminateInvocation:
			return "TerminateInvocation";
		case spv::OpSubgroupBallotKHR:
			return "SubgroupBallotKHR";
		case spv::OpSubgroupFirstInvocationKHR:
			return "SubgroupFirstInvocationKHR";
		case spv::OpSubgroupAllKHR:
			return "SubgroupAllKHR";
		case spv::OpSubgroupAnyKHR:
			return "SubgroupAnyKHR";
		case spv::OpSubgroupAllEqualKHR:
			return "SubgroupAllEqualKHR";
		case spv::OpGroupNonUniformRotateKHR:
			return "GroupNonUniformRotateKHR";
		case spv::OpSubgroupReadInvocationKHR:
			return "SubgroupReadInvocationKHR";
		case spv::OpTraceRayKHR:
			return "TraceRayKHR";
		case spv::OpExecuteCallableKHR:
			return "ExecuteCallableKHR";
		case spv::OpConvertUToAccelerationStructureKHR:
			return "ConvertUToAccelerationStructureKHR";
		case spv::OpIgnoreIntersectionKHR:
			return "IgnoreIntersectionKHR";
		case spv::OpTerminateRayKHR:
			return "TerminateRayKHR";
		case spv::OpSDot:
			return "SDot";
		case spv::OpUDot:
			return "UDot";
		case spv::OpSUDot:
			return "SUDot";
		case spv::OpSDotAccSat:
			return "SDotAccSat";
		case spv::OpUDotAccSat:
			return "UDotAccSat";
		case spv::OpSUDotAccSat:
			return "SUDotAccSat";
		case spv::OpTypeCooperativeMatrixKHR:
			return "TypeCooperativeMatrixKHR";
		case spv::OpCooperativeMatrixLoadKHR:
			return "CooperativeMatrixLoadKHR";
		case spv::OpCooperativeMatrixStoreKHR:
			return "CooperativeMatrixStoreKHR";
		case spv::OpCooperativeMatrixMulAddKHR:
			return "CooperativeMatrixMulAddKHR";
		case spv::OpCooperativeMatrixLengthKHR:
			return "CooperativeMatrixLengthKHR";
		case spv::OpTypeRayQueryKHR:
			return "TypeRayQueryKHR";
		case spv::OpRayQueryInitializeKHR:
			return "RayQueryInitializeKHR";
		case spv::OpRayQueryTerminateKHR:
			return "RayQueryTerminateKHR";
		case spv::OpRayQueryGenerateIntersectionKHR:
			return "RayQueryGenerateIntersectionKHR";
		case spv::OpRayQueryConfirmIntersectionKHR:
			return "RayQueryConfirmIntersectionKHR";
		case spv::OpRayQueryProceedKHR:
			return "RayQueryProceedKHR";
		case spv::OpRayQueryGetIntersectionTypeKHR:
			return "RayQueryGetIntersectionTypeKHR";
		case spv::OpImageSampleWeightedQCOM:
			return "ImageSampleWeightedQCOM";
		case spv::OpImageBoxFilterQCOM:
			return "ImageBoxFilterQCOM";
		case spv::OpImageBlockMatchSSDQCOM:
			return "ImageBlockMatchSSDQCOM";
		case spv::OpImageBlockMatchSADQCOM:
			return "ImageBlockMatchSADQCOM";
		case spv::OpImageBlockMatchWindowSSDQCOM:
			return "ImageBlockMatchWindowSSDQCOM";
		case spv::OpImageBlockMatchWindowSADQCOM:
			return "ImageBlockMatchWindowSADQCOM";
		case spv::OpImageBlockMatchGatherSSDQCOM:
			return "ImageBlockMatchGatherSSDQCOM";
		case spv::OpImageBlockMatchGatherSADQCOM:
			return "ImageBlockMatchGatherSADQCOM";
		case spv::OpGroupIAddNonUniformAMD:
			return "GroupIAddNonUniformAMD";
		case spv::OpGroupFAddNonUniformAMD:
			return "GroupFAddNonUniformAMD";
		case spv::OpGroupFMinNonUniformAMD:
			return "GroupFMinNonUniformAMD";
		case spv::OpGroupUMinNonUniformAMD:
			return "GroupUMinNonUniformAMD";
		case spv::OpGroupSMinNonUniformAMD:
			return "GroupSMinNonUniformAMD";
		case spv::OpGroupFMaxNonUniformAMD:
			return "GroupFMaxNonUniformAMD";
		case spv::OpGroupUMaxNonUniformAMD:
			return "GroupUMaxNonUniformAMD";
		case spv::OpGroupSMaxNonUniformAMD:
			return "GroupSMaxNonUniformAMD";
		case spv::OpFragmentMaskFetchAMD:
			return "FragmentMaskFetchAMD";
		case spv::OpFragmentFetchAMD:
			return "FragmentFetchAMD";
		case spv::OpReadClockKHR:
			return "ReadClockKHR";
		case spv::OpFinalizeNodePayloadsAMDX:
			return "FinalizeNodePayloadsAMDX";
		case spv::OpFinishWritingNodePayloadAMDX:
			return "FinishWritingNodePayloadAMDX";
		case spv::OpInitializeNodePayloadsAMDX:
			return "InitializeNodePayloadsAMDX";
		case spv::OpGroupNonUniformQuadAllKHR:
			return "GroupNonUniformQuadAllKHR";
		case spv::OpGroupNonUniformQuadAnyKHR:
			return "GroupNonUniformQuadAnyKHR";
		case spv::OpHitObjectRecordHitMotionNV:
			return "HitObjectRecordHitMotionNV";
		case spv::OpHitObjectRecordHitWithIndexMotionNV:
			return "HitObjectRecordHitWithIndexMotionNV";
		case spv::OpHitObjectRecordMissMotionNV:
			return "HitObjectRecordMissMotionNV";
		case spv::OpHitObjectGetWorldToObjectNV:
			return "HitObjectGetWorldToObjectNV";
		case spv::OpHitObjectGetObjectToWorldNV:
			return "HitObjectGetObjectToWorldNV";
		case spv::OpHitObjectGetObjectRayDirectionNV:
			return "HitObjectGetObjectRayDirectionNV";
		case spv::OpHitObjectGetObjectRayOriginNV:
			return "HitObjectGetObjectRayOriginNV";
		case spv::OpHitObjectTraceRayMotionNV:
			return "HitObjectTraceRayMotionNV";
		case spv::OpHitObjectGetShaderRecordBufferHandleNV:
			return "HitObjectGetShaderRecordBufferHandleNV";
		case spv::OpHitObjectGetShaderBindingTableRecordIndexNV:
			return "HitObjectGetShaderBindingTableRecordIndexNV";
		case spv::OpHitObjectRecordEmptyNV:
			return "HitObjectRecordEmptyNV";
		case spv::OpHitObjectTraceRayNV:
			return "HitObjectTraceRayNV";
		case spv::OpHitObjectRecordHitNV:
			return "HitObjectRecordHitNV";
		case spv::OpHitObjectRecordHitWithIndexNV:
			return "HitObjectRecordHitWithIndexNV";
		case spv::OpHitObjectRecordMissNV:
			return "HitObjectRecordMissNV";
		case spv::OpHitObjectExecuteShaderNV:
			return "HitObjectExecuteShaderNV";
		case spv::OpHitObjectGetCurrentTimeNV:
			return "HitObjectGetCurrentTimeNV";
		case spv::OpHitObjectGetAttributesNV:
			return "HitObjectGetAttributesNV";
		case spv::OpHitObjectGetHitKindNV:
			return "HitObjectGetHitKindNV";
		case spv::OpHitObjectGetPrimitiveIndexNV:
			return "HitObjectGetPrimitiveIndexNV";
		case spv::OpHitObjectGetGeometryIndexNV:
			return "HitObjectGetGeometryIndexNV";
		case spv::OpHitObjectGetInstanceIdNV:
			return "HitObjectGetInstanceIdNV";
		case spv::OpHitObjectGetInstanceCustomIndexNV:
			return "HitObjectGetInstanceCustomIndexNV";
		case spv::OpHitObjectGetWorldRayDirectionNV:
			return "HitObjectGetWorldRayDirectionNV";
		case spv::OpHitObjectGetWorldRayOriginNV:
			return "HitObjectGetWorldRayOriginNV";
		case spv::OpHitObjectGetRayTMaxNV:
			return "HitObjectGetRayTMaxNV";
		case spv::OpHitObjectGetRayTMinNV:
			return "HitObjectGetRayTMinNV";
		case spv::OpHitObjectIsEmptyNV:
			return "HitObjectIsEmptyNV";
		case spv::OpHitObjectIsHitNV:
			return "HitObjectIsHitNV";
		case spv::OpHitObjectIsMissNV:
			return "HitObjectIsMissNV";
		case spv::OpReorderThreadWithHitObjectNV:
			return "ReorderThreadWithHitObjectNV";
		case spv::OpReorderThreadWithHintNV:
			return "ReorderThreadWithHintNV";
		case spv::OpTypeHitObjectNV:
			return "TypeHitObjectNV";
		case spv::OpImageSampleFootprintNV:
			return "ImageSampleFootprintNV";
		case spv::OpEmitMeshTasksEXT:
			return "EmitMeshTasksEXT";
		case spv::OpSetMeshOutputsEXT:
			return "SetMeshOutputsEXT";
		case spv::OpGroupNonUniformPartitionNV:
			return "GroupNonUniformPartitionNV";
		case spv::OpWritePackedPrimitiveIndices4x8NV:
			return "WritePackedPrimitiveIndices4x8NV";
		case spv::OpFetchMicroTriangleVertexPositionNV:
			return "FetchMicroTriangleVertexPositionNV";
		case spv::OpFetchMicroTriangleVertexBarycentricNV:
			return "FetchMicroTriangleVertexBarycentricNV";
		case spv::OpReportIntersectionKHR:
			return "ReportIntersectionKHR";
		case spv::OpIgnoreIntersectionNV:
			return "IgnoreIntersectionNV";
		case spv::OpTerminateRayNV:
			return "TerminateRayNV";
		case spv::OpTraceNV:
			return "TraceNV";
		case spv::OpTraceMotionNV:
			return "TraceMotionNV";
		case spv::OpTraceRayMotionNV:
			return "TraceRayMotionNV";
		case spv::OpRayQueryGetIntersectionTriangleVertexPositionsKHR:
			return "RayQueryGetIntersectionTriangleVertexPositionsKHR";
		case spv::OpTypeAccelerationStructureKHR:
			return "TypeAccelerationStructureKHR";
		case spv::OpExecuteCallableNV:
			return "ExecuteCallableNV";
		case spv::OpTypeCooperativeMatrixNV:
			return "TypeCooperativeMatrixNV";
		case spv::OpCooperativeMatrixLoadNV:
			return "CooperativeMatrixLoadNV";
		case spv::OpCooperativeMatrixStoreNV:
			return "CooperativeMatrixStoreNV";
		case spv::OpCooperativeMatrixMulAddNV:
			return "CooperativeMatrixMulAddNV";
		case spv::OpCooperativeMatrixLengthNV:
			return "CooperativeMatrixLengthNV";
		case spv::OpBeginInvocationInterlockEXT:
			return "BeginInvocationInterlockEXT";
		case spv::OpEndInvocationInterlockEXT:
			return "EndInvocationInterlockEXT";
		case spv::OpDemoteToHelperInvocation:
			return "DemoteToHelperInvocation";
		case spv::OpIsHelperInvocationEXT:
			return "IsHelperInvocationEXT";
		case spv::OpConvertUToImageNV:
			return "ConvertUToImageNV";
		case spv::OpConvertUToSamplerNV:
			return "ConvertUToSamplerNV";
		case spv::OpConvertImageToUNV:
			return "ConvertImageToUNV";
		case spv::OpConvertSamplerToUNV:
			return "ConvertSamplerToUNV";
		case spv::OpConvertUToSampledImageNV:
			return "ConvertUToSampledImageNV";
		case spv::OpConvertSampledImageToUNV:
			return "ConvertSampledImageToUNV";
		case spv::OpSamplerImageAddressingModeNV:
			return "SamplerImageAddressingModeNV";
		case spv::OpSubgroupShuffleINTEL:
			return "SubgroupShuffleINTEL";
		case spv::OpSubgroupShuffleDownINTEL:
			return "SubgroupShuffleDownINTEL";
		case spv::OpSubgroupShuffleUpINTEL:
			return "SubgroupShuffleUpINTEL";
		case spv::OpSubgroupShuffleXorINTEL:
			return "SubgroupShuffleXorINTEL";
		case spv::OpSubgroupBlockReadINTEL:
			return "SubgroupBlockReadINTEL";
		case spv::OpSubgroupBlockWriteINTEL:
			return "SubgroupBlockWriteINTEL";
		case spv::OpSubgroupImageBlockReadINTEL:
			return "SubgroupImageBlockReadINTEL";
		case spv::OpSubgroupImageBlockWriteINTEL:
			return "SubgroupImageBlockWriteINTEL";
		case spv::OpSubgroupImageMediaBlockReadINTEL:
			return "SubgroupImageMediaBlockReadINTEL";
		case spv::OpSubgroupImageMediaBlockWriteINTEL:
			return "SubgroupImageMediaBlockWriteINTEL";
		case spv::OpUCountLeadingZerosINTEL:
			return "UCountLeadingZerosINTEL";
		case spv::OpUCountTrailingZerosINTEL:
			return "UCountTrailingZerosINTEL";
		case spv::OpAbsISubINTEL:
			return "AbsISubINTEL";
		case spv::OpAbsUSubINTEL:
			return "AbsUSubINTEL";
		case spv::OpIAddSatINTEL:
			return "IAddSatINTEL";
		case spv::OpUAddSatINTEL:
			return "UAddSatINTEL";
		case spv::OpIAverageINTEL:
			return "IAverageINTEL";
		case spv::OpUAverageINTEL:
			return "UAverageINTEL";
		case spv::OpIAverageRoundedINTEL:
			return "IAverageRoundedINTEL";
		case spv::OpUAverageRoundedINTEL:
			return "UAverageRoundedINTEL";
		case spv::OpISubSatINTEL:
			return "ISubSatINTEL";
		case spv::OpUSubSatINTEL:
			return "USubSatINTEL";
		case spv::OpIMul32x16INTEL:
			return "IMul32x16INTEL";
		case spv::OpUMul32x16INTEL:
			return "UMul32x16INTEL";
		case spv::OpConstantFunctionPointerINTEL:
			return "ConstantFunctionPointerINTEL";
		case spv::OpFunctionPointerCallINTEL:
			return "FunctionPointerCallINTEL";
		case spv::OpAsmTargetINTEL:
			return "AsmTargetINTEL";
		case spv::OpAsmINTEL:
			return "AsmINTEL";
		case spv::OpAsmCallINTEL:
			return "AsmCallINTEL";
		case spv::OpAtomicFMinEXT:
			return "AtomicFMinEXT";
		case spv::OpAtomicFMaxEXT:
			return "AtomicFMaxEXT";
		case spv::OpAssumeTrueKHR:
			return "AssumeTrueKHR";
		case spv::OpExpectKHR:
			return "ExpectKHR";
		case spv::OpDecorateString:
			return "DecorateString";
		case spv::OpMemberDecorateString:
			return "MemberDecorateString";
		case spv::OpVmeImageINTEL:
			return "VmeImageINTEL";
		case spv::OpTypeVmeImageINTEL:
			return "TypeVmeImageINTEL";
		case spv::OpTypeAvcImePayloadINTEL:
			return "TypeAvcImePayloadINTEL";
		case spv::OpTypeAvcRefPayloadINTEL:
			return "TypeAvcRefPayloadINTEL";
		case spv::OpTypeAvcSicPayloadINTEL:
			return "TypeAvcSicPayloadINTEL";
		case spv::OpTypeAvcMcePayloadINTEL:
			return "TypeAvcMcePayloadINTEL";
		case spv::OpTypeAvcMceResultINTEL:
			return "TypeAvcMceResultINTEL";
		case spv::OpTypeAvcImeResultINTEL:
			return "TypeAvcImeResultINTEL";
		case spv::OpTypeAvcImeResultSingleReferenceStreamoutINTEL:
			return "TypeAvcImeResultSingleReferenceStreamoutINTEL";
		case spv::OpTypeAvcImeResultDualReferenceStreamoutINTEL:
			return "TypeAvcImeResultDualReferenceStreamoutINTEL";
		case spv::OpTypeAvcImeSingleReferenceStreaminINTEL:
			return "TypeAvcImeSingleReferenceStreaminINTEL";
		case spv::OpTypeAvcImeDualReferenceStreaminINTEL:
			return "TypeAvcImeDualReferenceStreaminINTEL";
		case spv::OpTypeAvcRefResultINTEL:
			return "TypeAvcRefResultINTEL";
		case spv::OpTypeAvcSicResultINTEL:
			return "TypeAvcSicResultINTEL";
		case spv::OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL:
			return "SubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL";
		case spv::OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL:
			return "SubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL";
		case spv::OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL:
			return "SubgroupAvcMceGetDefaultInterShapePenaltyINTEL";
		case spv::OpSubgroupAvcMceSetInterShapePenaltyINTEL:
			return "SubgroupAvcMceSetInterShapePenaltyINTEL";
		case spv::OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL:
			return "SubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL";
		case spv::OpSubgroupAvcMceSetInterDirectionPenaltyINTEL:
			return "SubgroupAvcMceSetInterDirectionPenaltyINTEL";
		case spv::OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL:
			return "SubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL";
		case spv::OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL:
			return "SubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL";
		case spv::OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL:
			return "SubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL";
		case spv::OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL:
			return "SubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL";
		case spv::OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL:
			return "SubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL";
		case spv::OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL:
			return "SubgroupAvcMceSetMotionVectorCostFunctionINTEL";
		case spv::OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL:
			return "SubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL";
		case spv::OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL:
			return "SubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL";
		case spv::OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL:
			return "SubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL";
		case spv::OpSubgroupAvcMceSetAcOnlyHaarINTEL:
			return "SubgroupAvcMceSetAcOnlyHaarINTEL";
		case spv::OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL:
			return "SubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL";
		case spv::OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL:
			return "SubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL";
		case spv::OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL:
			return "SubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL";
		case spv::OpSubgroupAvcMceConvertToImePayloadINTEL:
			return "SubgroupAvcMceConvertToImePayloadINTEL";
		case spv::OpSubgroupAvcMceConvertToImeResultINTEL:
			return "SubgroupAvcMceConvertToImeResultINTEL";
		case spv::OpSubgroupAvcMceConvertToRefPayloadINTEL:
			return "SubgroupAvcMceConvertToRefPayloadINTEL";
		case spv::OpSubgroupAvcMceConvertToRefResultINTEL:
			return "SubgroupAvcMceConvertToRefResultINTEL";
		case spv::OpSubgroupAvcMceConvertToSicPayloadINTEL:
			return "SubgroupAvcMceConvertToSicPayloadINTEL";
		case spv::OpSubgroupAvcMceConvertToSicResultINTEL:
			return "SubgroupAvcMceConvertToSicResultINTEL";
		case spv::OpSubgroupAvcMceGetMotionVectorsINTEL:
			return "SubgroupAvcMceGetMotionVectorsINTEL";
		case spv::OpSubgroupAvcMceGetInterDistortionsINTEL:
			return "SubgroupAvcMceGetInterDistortionsINTEL";
		case spv::OpSubgroupAvcMceGetBestInterDistortionsINTEL:
			return "SubgroupAvcMceGetBestInterDistortionsINTEL";
		case spv::OpSubgroupAvcMceGetInterMajorShapeINTEL:
			return "SubgroupAvcMceGetInterMajorShapeINTEL";
		case spv::OpSubgroupAvcMceGetInterMinorShapeINTEL:
			return "SubgroupAvcMceGetInterMinorShapeINTEL";
		case spv::OpSubgroupAvcMceGetInterDirectionsINTEL:
			return "SubgroupAvcMceGetInterDirectionsINTEL";
		case spv::OpSubgroupAvcMceGetInterMotionVectorCountINTEL:
			return "SubgroupAvcMceGetInterMotionVectorCountINTEL";
		case spv::OpSubgroupAvcMceGetInterReferenceIdsINTEL:
			return "SubgroupAvcMceGetInterReferenceIdsINTEL";
		case spv::OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL:
			return "SubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL";
		case spv::OpSubgroupAvcImeInitializeINTEL:
			return "SubgroupAvcImeInitializeINTEL";
		case spv::OpSubgroupAvcImeSetSingleReferenceINTEL:
			return "SubgroupAvcImeSetSingleReferenceINTEL";
		case spv::OpSubgroupAvcImeSetDualReferenceINTEL:
			return "SubgroupAvcImeSetDualReferenceINTEL";
		case spv::OpSubgroupAvcImeRefWindowSizeINTEL:
			return "SubgroupAvcImeRefWindowSizeINTEL";
		case spv::OpSubgroupAvcImeAdjustRefOffsetINTEL:
			return "SubgroupAvcImeAdjustRefOffsetINTEL";
		case spv::OpSubgroupAvcImeConvertToMcePayloadINTEL:
			return "SubgroupAvcImeConvertToMcePayloadINTEL";
		case spv::OpSubgroupAvcImeSetMaxMotionVectorCountINTEL:
			return "SubgroupAvcImeSetMaxMotionVectorCountINTEL";
		case spv::OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL:
			return "SubgroupAvcImeSetUnidirectionalMixDisableINTEL";
		case spv::OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL:
			return "SubgroupAvcImeSetEarlySearchTerminationThresholdINTEL";
		case spv::OpSubgroupAvcImeSetWeightedSadINTEL:
			return "SubgroupAvcImeSetWeightedSadINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL:
			return "SubgroupAvcImeEvaluateWithSingleReferenceINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithDualReferenceINTEL:
			return "SubgroupAvcImeEvaluateWithDualReferenceINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL:
			return "SubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL:
			return "SubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL:
			return "SubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL:
			return "SubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL:
			return "SubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL";
		case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL:
			return "SubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL";
		case spv::OpSubgroupAvcImeConvertToMceResultINTEL:
			return "SubgroupAvcImeConvertToMceResultINTEL";
		case spv::OpSubgroupAvcImeGetSingleReferenceStreaminINTEL:
			return "SubgroupAvcImeGetSingleReferenceStreaminINTEL";
		case spv::OpSubgroupAvcImeGetDualReferenceStreaminINTEL:
			return "SubgroupAvcImeGetDualReferenceStreaminINTEL";
		case spv::OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL:
			return "SubgroupAvcImeStripSingleReferenceStreamoutINTEL";
		case spv::OpSubgroupAvcImeStripDualReferenceStreamoutINTEL:
			return "SubgroupAvcImeStripDualReferenceStreamoutINTEL";
		case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL:
			return "SubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL";
		case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL:
			return "SubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL";
		case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL:
			return "SubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL";
		case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL:
			return "SubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL";
		case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL:
			return "SubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL";
		case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL:
			return "SubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL";
		case spv::OpSubgroupAvcImeGetBorderReachedINTEL:
			return "SubgroupAvcImeGetBorderReachedINTEL";
		case spv::OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL:
			return "SubgroupAvcImeGetTruncatedSearchIndicationINTEL";
		case spv::OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL:
			return "SubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL";
		case spv::OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL:
			return "SubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL";
		case spv::OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL:
			return "SubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL";
		case spv::OpSubgroupAvcFmeInitializeINTEL:
			return "SubgroupAvcFmeInitializeINTEL";
		case spv::OpSubgroupAvcBmeInitializeINTEL:
			return "SubgroupAvcBmeInitializeINTEL";
		case spv::OpSubgroupAvcRefConvertToMcePayloadINTEL:
			return "SubgroupAvcRefConvertToMcePayloadINTEL";
		case spv::OpSubgroupAvcRefSetBidirectionalMixDisableINTEL:
			return "SubgroupAvcRefSetBidirectionalMixDisableINTEL";
		case spv::OpSubgroupAvcRefSetBilinearFilterEnableINTEL:
			return "SubgroupAvcRefSetBilinearFilterEnableINTEL";
		case spv::OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL:
			return "SubgroupAvcRefEvaluateWithSingleReferenceINTEL";
		case spv::OpSubgroupAvcRefEvaluateWithDualReferenceINTEL:
			return "SubgroupAvcRefEvaluateWithDualReferenceINTEL";
		case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL:
			return "SubgroupAvcRefEvaluateWithMultiReferenceINTEL";
		case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL:
			return "SubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL";
		case spv::OpSubgroupAvcRefConvertToMceResultINTEL:
			return "SubgroupAvcRefConvertToMceResultINTEL";
		case spv::OpSubgroupAvcSicInitializeINTEL:
			return "SubgroupAvcSicInitializeINTEL";
		case spv::OpSubgroupAvcSicConfigureSkcINTEL:
			return "SubgroupAvcSicConfigureSkcINTEL";
		case spv::OpSubgroupAvcSicConfigureIpeLumaINTEL:
			return "SubgroupAvcSicConfigureIpeLumaINTEL";
		case spv::OpSubgroupAvcSicConfigureIpeLumaChromaINTEL:
			return "SubgroupAvcSicConfigureIpeLumaChromaINTEL";
		case spv::OpSubgroupAvcSicGetMotionVectorMaskINTEL:
			return "SubgroupAvcSicGetMotionVectorMaskINTEL";
		case spv::OpSubgroupAvcSicConvertToMcePayloadINTEL:
			return "SubgroupAvcSicConvertToMcePayloadINTEL";
		case spv::OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL:
			return "SubgroupAvcSicSetIntraLumaShapePenaltyINTEL";
		case spv::OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL:
			return "SubgroupAvcSicSetIntraLumaModeCostFunctionINTEL";
		case spv::OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL:
			return "SubgroupAvcSicSetIntraChromaModeCostFunctionINTEL";
		case spv::OpSubgroupAvcSicSetBilinearFilterEnableINTEL:
			return "SubgroupAvcSicSetBilinearFilterEnableINTEL";
		case spv::OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL:
			return "SubgroupAvcSicSetSkcForwardTransformEnableINTEL";
		case spv::OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL:
			return "SubgroupAvcSicSetBlockBasedRawSkipSadINTEL";
		case spv::OpSubgroupAvcSicEvaluateIpeINTEL:
			return "SubgroupAvcSicEvaluateIpeINTEL";
		case spv::OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL:
			return "SubgroupAvcSicEvaluateWithSingleReferenceINTEL";
		case spv::OpSubgroupAvcSicEvaluateWithDualReferenceINTEL:
			return "SubgroupAvcSicEvaluateWithDualReferenceINTEL";
		case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL:
			return "SubgroupAvcSicEvaluateWithMultiReferenceINTEL";
		case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL:
			return "SubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL";
		case spv::OpSubgroupAvcSicConvertToMceResultINTEL:
			return "SubgroupAvcSicConvertToMceResultINTEL";
		case spv::OpSubgroupAvcSicGetIpeLumaShapeINTEL:
			return "SubgroupAvcSicGetIpeLumaShapeINTEL";
		case spv::OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL:
			return "SubgroupAvcSicGetBestIpeLumaDistortionINTEL";
		case spv::OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL:
			return "SubgroupAvcSicGetBestIpeChromaDistortionINTEL";
		case spv::OpSubgroupAvcSicGetPackedIpeLumaModesINTEL:
			return "SubgroupAvcSicGetPackedIpeLumaModesINTEL";
		case spv::OpSubgroupAvcSicGetIpeChromaModeINTEL:
			return "SubgroupAvcSicGetIpeChromaModeINTEL";
		case spv::OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL:
			return "SubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL";
		case spv::OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL:
			return "SubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL";
		case spv::OpSubgroupAvcSicGetInterRawSadsINTEL:
			return "SubgroupAvcSicGetInterRawSadsINTEL";
		case spv::OpVariableLengthArrayINTEL:
			return "VariableLengthArrayINTEL";
		case spv::OpSaveMemoryINTEL:
			return "SaveMemoryINTEL";
		case spv::OpRestoreMemoryINTEL:
			return "RestoreMemoryINTEL";
		case spv::OpArbitraryFloatSinCosPiINTEL:
			return "ArbitraryFloatSinCosPiINTEL";
		case spv::OpArbitraryFloatCastINTEL:
			return "ArbitraryFloatCastINTEL";
		case spv::OpArbitraryFloatCastFromIntINTEL:
			return "ArbitraryFloatCastFromIntINTEL";
		case spv::OpArbitraryFloatCastToIntINTEL:
			return "ArbitraryFloatCastToIntINTEL";
		case spv::OpArbitraryFloatAddINTEL:
			return "ArbitraryFloatAddINTEL";
		case spv::OpArbitraryFloatSubINTEL:
			return "ArbitraryFloatSubINTEL";
		case spv::OpArbitraryFloatMulINTEL:
			return "ArbitraryFloatMulINTEL";
		case spv::OpArbitraryFloatDivINTEL:
			return "ArbitraryFloatDivINTEL";
		case spv::OpArbitraryFloatGTINTEL:
			return "ArbitraryFloatGTINTEL";
		case spv::OpArbitraryFloatGEINTEL:
			return "ArbitraryFloatGEINTEL";
		case spv::OpArbitraryFloatLTINTEL:
			return "ArbitraryFloatLTINTEL";
		case spv::OpArbitraryFloatLEINTEL:
			return "ArbitraryFloatLEINTEL";
		case spv::OpArbitraryFloatEQINTEL:
			return "ArbitraryFloatEQINTEL";
		case spv::OpArbitraryFloatRecipINTEL:
			return "ArbitraryFloatRecipINTEL";
		case spv::OpArbitraryFloatRSqrtINTEL:
			return "ArbitraryFloatRSqrtINTEL";
		case spv::OpArbitraryFloatCbrtINTEL:
			return "ArbitraryFloatCbrtINTEL";
		case spv::OpArbitraryFloatHypotINTEL:
			return "ArbitraryFloatHypotINTEL";
		case spv::OpArbitraryFloatSqrtINTEL:
			return "ArbitraryFloatSqrtINTEL";
		case spv::OpArbitraryFloatLogINTEL:
			return "ArbitraryFloatLogINTEL";
		case spv::OpArbitraryFloatLog2INTEL:
			return "ArbitraryFloatLog2INTEL";
		case spv::OpArbitraryFloatLog10INTEL:
			return "ArbitraryFloatLog10INTEL";
		case spv::OpArbitraryFloatLog1pINTEL:
			return "ArbitraryFloatLog1pINTEL";
		case spv::OpArbitraryFloatExpINTEL:
			return "ArbitraryFloatExpINTEL";
		case spv::OpArbitraryFloatExp2INTEL:
			return "ArbitraryFloatExp2INTEL";
		case spv::OpArbitraryFloatExp10INTEL:
			return "ArbitraryFloatExp10INTEL";
		case spv::OpArbitraryFloatExpm1INTEL:
			return "ArbitraryFloatExpm1INTEL";
		case spv::OpArbitraryFloatSinINTEL:
			return "ArbitraryFloatSinINTEL";
		case spv::OpArbitraryFloatCosINTEL:
			return "ArbitraryFloatCosINTEL";
		case spv::OpArbitraryFloatSinCosINTEL:
			return "ArbitraryFloatSinCosINTEL";
		case spv::OpArbitraryFloatSinPiINTEL:
			return "ArbitraryFloatSinPiINTEL";
		case spv::OpArbitraryFloatCosPiINTEL:
			return "ArbitraryFloatCosPiINTEL";
		case spv::OpArbitraryFloatASinINTEL:
			return "ArbitraryFloatASinINTEL";
		case spv::OpArbitraryFloatASinPiINTEL:
			return "ArbitraryFloatASinPiINTEL";
		case spv::OpArbitraryFloatACosINTEL:
			return "ArbitraryFloatACosINTEL";
		case spv::OpArbitraryFloatACosPiINTEL:
			return "ArbitraryFloatACosPiINTEL";
		case spv::OpArbitraryFloatATanINTEL:
			return "ArbitraryFloatATanINTEL";
		case spv::OpArbitraryFloatATanPiINTEL:
			return "ArbitraryFloatATanPiINTEL";
		case spv::OpArbitraryFloatATan2INTEL:
			return "ArbitraryFloatATan2INTEL";
		case spv::OpArbitraryFloatPowINTEL:
			return "ArbitraryFloatPowINTEL";
		case spv::OpArbitraryFloatPowRINTEL:
			return "ArbitraryFloatPowRINTEL";
		case spv::OpArbitraryFloatPowNINTEL:
			return "ArbitraryFloatPowNINTEL";
		case spv::OpLoopControlINTEL:
			return "LoopControlINTEL";
		case spv::OpAliasDomainDeclINTEL:
			return "AliasDomainDeclINTEL";
		case spv::OpAliasScopeDeclINTEL:
			return "AliasScopeDeclINTEL";
		case spv::OpAliasScopeListDeclINTEL:
			return "AliasScopeListDeclINTEL";
		case spv::OpFixedSqrtINTEL:
			return "FixedSqrtINTEL";
		case spv::OpFixedRecipINTEL:
			return "FixedRecipINTEL";
		case spv::OpFixedRsqrtINTEL:
			return "FixedRsqrtINTEL";
		case spv::OpFixedSinINTEL:
			return "FixedSinINTEL";
		case spv::OpFixedCosINTEL:
			return "FixedCosINTEL";
		case spv::OpFixedSinCosINTEL:
			return "FixedSinCosINTEL";
		case spv::OpFixedSinPiINTEL:
			return "FixedSinPiINTEL";
		case spv::OpFixedCosPiINTEL:
			return "FixedCosPiINTEL";
		case spv::OpFixedSinCosPiINTEL:
			return "FixedSinCosPiINTEL";
		case spv::OpFixedLogINTEL:
			return "FixedLogINTEL";
		case spv::OpFixedExpINTEL:
			return "FixedExpINTEL";
		case spv::OpPtrCastToCrossWorkgroupINTEL:
			return "PtrCastToCrossWorkgroupINTEL";
		case spv::OpCrossWorkgroupCastToPtrINTEL:
			return "CrossWorkgroupCastToPtrINTEL";
		case spv::OpReadPipeBlockingINTEL:
			return "ReadPipeBlockingINTEL";
		case spv::OpWritePipeBlockingINTEL:
			return "WritePipeBlockingINTEL";
		case spv::OpFPGARegINTEL:
			return "FPGARegINTEL";
		case spv::OpRayQueryGetRayTMinKHR:
			return "RayQueryGetRayTMinKHR";
		case spv::OpRayQueryGetRayFlagsKHR:
			return "RayQueryGetRayFlagsKHR";
		case spv::OpRayQueryGetIntersectionTKHR:
			return "RayQueryGetIntersectionTKHR";
		case spv::OpRayQueryGetIntersectionInstanceCustomIndexKHR:
			return "RayQueryGetIntersectionInstanceCustomIndexKHR";
		case spv::OpRayQueryGetIntersectionInstanceIdKHR:
			return "RayQueryGetIntersectionInstanceIdKHR";
		case spv::OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR:
			return "RayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR";
		case spv::OpRayQueryGetIntersectionGeometryIndexKHR:
			return "RayQueryGetIntersectionGeometryIndexKHR";
		case spv::OpRayQueryGetIntersectionPrimitiveIndexKHR:
			return "RayQueryGetIntersectionPrimitiveIndexKHR";
		case spv::OpRayQueryGetIntersectionBarycentricsKHR:
			return "RayQueryGetIntersectionBarycentricsKHR";
		case spv::OpRayQueryGetIntersectionFrontFaceKHR:
			return "RayQueryGetIntersectionFrontFaceKHR";
		case spv::OpRayQueryGetIntersectionCandidateAABBOpaqueKHR:
			return "RayQueryGetIntersectionCandidateAABBOpaqueKHR";
		case spv::OpRayQueryGetIntersectionObjectRayDirectionKHR:
			return "RayQueryGetIntersectionObjectRayDirectionKHR";
		case spv::OpRayQueryGetIntersectionObjectRayOriginKHR:
			return "RayQueryGetIntersectionObjectRayOriginKHR";
		case spv::OpRayQueryGetWorldRayDirectionKHR:
			return "RayQueryGetWorldRayDirectionKHR";
		case spv::OpRayQueryGetWorldRayOriginKHR:
			return "RayQueryGetWorldRayOriginKHR";
		case spv::OpRayQueryGetIntersectionObjectToWorldKHR:
			return "RayQueryGetIntersectionObjectToWorldKHR";
		case spv::OpRayQueryGetIntersectionWorldToObjectKHR:
			return "RayQueryGetIntersectionWorldToObjectKHR";
		case spv::OpAtomicFAddEXT:
			return "AtomicFAddEXT";
		case spv::OpTypeBufferSurfaceINTEL:
			return "TypeBufferSurfaceINTEL";
		case spv::OpTypeStructContinuedINTEL:
			return "TypeStructContinuedINTEL";
		case spv::OpConstantCompositeContinuedINTEL:
			return "ConstantCompositeContinuedINTEL";
		case spv::OpSpecConstantCompositeContinuedINTEL:
			return "SpecConstantCompositeContinuedINTEL";
		case spv::OpCompositeConstructContinuedINTEL:
			return "CompositeConstructContinuedINTEL";
		case spv::OpConvertFToBF16INTEL:
			return "ConvertFToBF16INTEL";
		case spv::OpConvertBF16ToFINTEL:
			return "ConvertBF16ToFINTEL";
		case spv::OpControlBarrierArriveINTEL:
			return "ControlBarrierArriveINTEL";
		case spv::OpControlBarrierWaitINTEL:
			return "ControlBarrierWaitINTEL";
		case spv::OpGroupIMulKHR:
			return "GroupIMulKHR";
		case spv::OpGroupFMulKHR:
			return "GroupFMulKHR";
		case spv::OpGroupBitwiseAndKHR:
			return "GroupBitwiseAndKHR";
		case spv::OpGroupBitwiseOrKHR:
			return "GroupBitwiseOrKHR";
		case spv::OpGroupBitwiseXorKHR:
			return "GroupBitwiseXorKHR";
		case spv::OpGroupLogicalAndKHR:
			return "GroupLogicalAndKHR";
		case spv::OpGroupLogicalOrKHR:
			return "GroupLogicalOrKHR";
		case spv::OpGroupLogicalXorKHR:
			return "GroupLogicalXorKHR";
		case spv::OpMaskedGatherINTEL:
			return "MaskedGatherINTEL";
		case spv::OpMaskedScatterINTEL:
			return "MaskedScatterINTEL";
		default:
			assert( false );
			return "Unknown";
		}
	}

	spv::Op getOpCode( ast::type::Kind kind )
	{
		spv::Op result{};

		switch ( kind )
		{
		case ast::type::Kind::eVoid:
			result = spv::OpTypeVoid;
			break;
		case ast::type::Kind::eFunction:
			result = spv::OpTypeFunction;
			break;
		case ast::type::Kind::eStruct:
		case ast::type::Kind::eRayDesc:
			result = spv::OpTypeStruct;
			break;
		case ast::type::Kind::eBoolean:
			result = spv::OpTypeBool;
			break;
		case ast::type::Kind::eInt8:
		case ast::type::Kind::eInt16:
		case ast::type::Kind::eInt32:
		case ast::type::Kind::eInt64:
		case ast::type::Kind::eUInt8:
		case ast::type::Kind::eUInt16:
		case ast::type::Kind::eUInt32:
		case ast::type::Kind::eUInt64:
			result = spv::OpTypeInt;
			break;
		case ast::type::Kind::eFloat:
		case ast::type::Kind::eDouble:
			result = spv::OpTypeFloat;
			break;
		case ast::type::Kind::eVec2B:
		case ast::type::Kind::eVec3B:
		case ast::type::Kind::eVec4B:
		case ast::type::Kind::eVec2I8:
		case ast::type::Kind::eVec3I8:
		case ast::type::Kind::eVec4I8:
		case ast::type::Kind::eVec2I16:
		case ast::type::Kind::eVec3I16:
		case ast::type::Kind::eVec4I16:
		case ast::type::Kind::eVec2I32:
		case ast::type::Kind::eVec3I32:
		case ast::type::Kind::eVec4I32:
		case ast::type::Kind::eVec2I64:
		case ast::type::Kind::eVec3I64:
		case ast::type::Kind::eVec4I64:
		case ast::type::Kind::eVec2U8:
		case ast::type::Kind::eVec3U8:
		case ast::type::Kind::eVec4U8:
		case ast::type::Kind::eVec2U16:
		case ast::type::Kind::eVec3U16:
		case ast::type::Kind::eVec4U16:
		case ast::type::Kind::eVec2U32:
		case ast::type::Kind::eVec3U32:
		case ast::type::Kind::eVec4U32:
		case ast::type::Kind::eVec2U64:
		case ast::type::Kind::eVec3U64:
		case ast::type::Kind::eVec4U64:
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
		case ast::type::Kind::eCombinedImage:
			result = spv::OpTypeSampledImage;
			break;
		case ast::type::Kind::eSampler:
			result = spv::OpTypeSampler;
			break;
		case ast::type::Kind::eAccelerationStructure:
			result = spv::OpTypeAccelerationStructureKHR;
			break;
		default:
			AST_Failure( "Unsupported ast::type::Kind" );
			break;
		}

		return result;
	}

	spv::Op getOpCode( ast::type::TypePtr type )
	{
		spv::Op result;

		if ( auto arraySize = getArraySize( type );
			arraySize == ast::type::NotArray )
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

	spv::Op getBinOpCode( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, bool & switchParams
		, bool & needMatchingVectors )
	{
		needMatchingVectors = true;
		assert( exprKind != ast::expr::Kind::eImageAccessCall
			&& exprKind != ast::expr::Kind::eIntrinsicCall
			&& exprKind != ast::expr::Kind::eCombinedImageAccessCall
			&& "Unsupported ast::expr::Kind" );
		spv::Op result{ spv::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eAdd:
		case ast::expr::Kind::eAddAssign:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFAdd
				: spv::OpIAdd;
			break;
		case ast::expr::Kind::eMinus:
		case ast::expr::Kind::eMinusAssign:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFSub
				: spv::OpISub;
			break;
		case ast::expr::Kind::eTimes:
		case ast::expr::Kind::eTimesAssign:
			result = isMatrixType( lhsTypeKind )
				? ( isMatrixType( rhsTypeKind )
					? spv::OpMatrixTimesMatrix
					: ( isVectorType( rhsTypeKind )
						? spv::OpMatrixTimesVector
						: spv::OpMatrixTimesScalar ) )
				: ( isVectorType( lhsTypeKind )
					? ( isMatrixType( rhsTypeKind )
						? spv::OpVectorTimesMatrix
						: ( isVectorType( rhsTypeKind )
							? ( ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
								? spv::OpFMul
								: spv::OpIMul )
							: spv::OpVectorTimesScalar ) )
					: ( isMatrixType( rhsTypeKind )
						? spv::OpMatrixTimesScalar
						: ( isVectorType( rhsTypeKind )
							? spv::OpVectorTimesScalar
							: ( ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
								? spv::OpFMul
								: spv::OpIMul ) ) ) );
			needMatchingVectors = !( ( isFloatType( getScalarType( lhsTypeKind ) ) || isFloatType( getScalarType( rhsTypeKind ) ) )
				&& ( isVectorType( lhsTypeKind ) || isVectorType( rhsTypeKind ) ) );
			break;
		case ast::expr::Kind::eDivide:
		case ast::expr::Kind::eDivideAssign:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFDiv
				: ( ophlp::isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSDiv
					: spv::OpUDiv );
			break;
		case ast::expr::Kind::eModulo:
		case ast::expr::Kind::eModuloAssign:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFMod
				: ( ophlp::isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSMod
					: spv::OpUMod );
			break;
		case ast::expr::Kind::eLShift:
		case ast::expr::Kind::eLShiftAssign:
			result = spv::OpShiftLeftLogical;
			break;
		case ast::expr::Kind::eRShift:
		case ast::expr::Kind::eRShiftAssign:
			result = spv::OpShiftRightLogical;
			break;
		case ast::expr::Kind::eBitAnd:
		case ast::expr::Kind::eAndAssign:
			result = spv::OpBitwiseAnd;
			break;
		case ast::expr::Kind::eBitNot:
			AST_Failure( "Unexpected ast::expr::Kind::eBitNot" );
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
			AST_Failure( "Unexpected ast::expr::Kind::eBitNot" );
			break;
		case ast::expr::Kind::eLogOr:
			result = spv::OpLogicalOr;
			needMatchingVectors = false;
			break;
		case ast::expr::Kind::eCast:
			AST_Failure( "Unexpected ast::expr::Kind::eCast" );
			break;
		case ast::expr::Kind::eInit:
			result = spv::OpStore;
			break;
		case ast::expr::Kind::eAggrInit:
			result = spv::OpStore;
			break;
		case ast::expr::Kind::eFnCall:
			AST_Failure( "Unexpected ast::expr::Kind::eFnCall" );
			break;
		case ast::expr::Kind::eEqual:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdEqual
				: ophlp::isAnyBool( lhsTypeKind, rhsTypeKind )
				? spv::OpLogicalEqual
				: spv::OpIEqual;
			break;
		case ast::expr::Kind::eGreater:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdGreaterThan
				: ( ophlp::isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSGreaterThan
					: spv::OpUGreaterThan );
			break;
		case ast::expr::Kind::eGreaterEqual:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdGreaterThanEqual
				: ( ophlp::isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSGreaterThanEqual
					: spv::OpUGreaterThanEqual );
			break;
		case ast::expr::Kind::eLess:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdLessThan
				: ( ophlp::isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSLessThan
					: spv::OpULessThan );
			break;
		case ast::expr::Kind::eLessEqual:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdLessThanEqual
				: ( ophlp::isAnySigned( lhsTypeKind, rhsTypeKind )
					? spv::OpSLessThanEqual
					: spv::OpULessThanEqual );
			break;
		case ast::expr::Kind::eNotEqual:
			result = ophlp::isAnyFloating( lhsTypeKind, rhsTypeKind )
				? spv::OpFOrdNotEqual
				: ophlp::isAnyBool( lhsTypeKind, rhsTypeKind )
				? spv::OpLogicalNotEqual
				: spv::OpINotEqual;
			break;
		case ast::expr::Kind::eComma:
			AST_Failure( "Unexpected ast::expr::Kind::eComma" );
			break;
		case ast::expr::Kind::eIdentifier:
			AST_Failure( "Unexpected ast::expr::Kind::eIdentifier" );
			break;
		case ast::expr::Kind::eLiteral:
			AST_Failure( "Unexpected ast::expr::Kind::eLiteral" );
			break;
		case ast::expr::Kind::eMbrSelect:
			AST_Failure( "Unexpected ast::expr::Kind::eMbrSelect" );
			break;
		case ast::expr::Kind::eSwitchTest:
			AST_Failure( "Unexpected ast::expr::Kind::eSwitchTest" );
			break;
		case ast::expr::Kind::eSwitchCase:
			AST_Failure( "Unexpected ast::expr::Kind::eSwitchCase" );
			break;
		case ast::expr::Kind::eQuestion:
			AST_Failure( "Unexpected ast::expr::Kind::eQuestion" );
			break;
		case ast::expr::Kind::ePreIncrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePreIncrement" );
			break;
		case ast::expr::Kind::ePreDecrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePreDecrement" );
			break;
		case ast::expr::Kind::ePostIncrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePostIncrement" );
			break;
		case ast::expr::Kind::ePostDecrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePostDecrement" );
			break;
		case ast::expr::Kind::eUnaryMinus:
			AST_Failure( "Unexpected ast::expr::Kind::eUnaryMinus" );
			break;
		case ast::expr::Kind::eUnaryPlus:
			AST_Failure( "Unexpected ast::expr::Kind::eUnaryPlus" );
			break;
		case ast::expr::Kind::eAssign:
			AST_Failure( "Unexpected ast::expr::Kind::eAssign" );
			break;
		case ast::expr::Kind::eArrayAccess:
			AST_Failure( "Unexpected ast::expr::Kind::eArrayAccess" );
			break;
		default:
			AST_Failure( "Unexpected ast::expr::Kind" );
			break;
		}

		switchParams = ( exprKind == ast::expr::Kind::eTimes || exprKind == ast::expr::Kind::eTimesAssign )
			&& ( isScalarType( lhsTypeKind ) && ( isVectorType( rhsTypeKind ) || isMatrixType( rhsTypeKind ) ) );
		return result;
	}

	spv::Op getUnOpCode( ast::expr::Kind exprKind
		, ast::type::Kind typeKind )
	{
		assert( exprKind != ast::expr::Kind::eImageAccessCall
			&& exprKind != ast::expr::Kind::eIntrinsicCall
			&& exprKind != ast::expr::Kind::eCombinedImageAccessCall
			&& "Unsupported ast::expr::Kind" );
		spv::Op result{ spv::OpNop };

		switch ( exprKind )
		{
		case ast::expr::Kind::eBitNot:
			result = spv::OpNot;
			break;
		case ast::expr::Kind::eLogNot:
			result = spv::OpLogicalNot;
			break;
		case ast::expr::Kind::eCast:
			AST_Failure( "Unexpected ast::expr::Kind::eCast" );
			break;
		case ast::expr::Kind::eComma:
			AST_Failure( "Unexpected ast::expr::Kind::eComma" );
			break;
		case ast::expr::Kind::eIdentifier:
			AST_Failure( "Unexpected ast::expr::Kind::eIdentifier" );
			break;
		case ast::expr::Kind::eLiteral:
			AST_Failure( "Unexpected ast::expr::Kind::eLiteral" );
			break;
		case ast::expr::Kind::ePreIncrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePreIncrement" );
			break;
		case ast::expr::Kind::ePreDecrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePreDecrement" );
			break;
		case ast::expr::Kind::ePostIncrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePostIncrement" );
			break;
		case ast::expr::Kind::ePostDecrement:
			AST_Failure( "Unexpected ast::expr::Kind::ePostDecrement" );
			break;
		case ast::expr::Kind::eUnaryMinus:
			result = ophlp::isFloating( typeKind )
				? spv::OpFNegate
				: spv::OpSNegate;
			break;
		case ast::expr::Kind::eUnaryPlus:
			AST_Failure( "Unexpected ast::expr::Kind::eUnaryPlus" );
			break;
		default:
			break;
		}

		return result;
	}

	//*************************************************************************
}
