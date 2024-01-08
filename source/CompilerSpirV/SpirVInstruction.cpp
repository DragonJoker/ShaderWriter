/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVInstruction.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>

#include <algorithm>
#include <map>

namespace spirv
{
	//*************************************************************************

	namespace insthlp
	{
		template< typename IterT >
		static UInt32List deserializePackedName( ast::ShaderAllocatorBlock * alloc
			, BufferItT< IterT > & buffer )
		{
			auto value = buffer.popValue();
			UInt32List result{ alloc };

			while ( ( value & 0xFF000000 ) != 0u )
			{
				result.push_back( value );
				value = buffer.popValue();
			}

			result.push_back( value );
			return result;
		}

		static UInt32List const & packString( NamesCache & nameCache
			, std::string const & name )
		{
			auto it = nameCache.find( name );

			if ( it == nameCache.end() )
			{
				UInt32List packed{ nameCache.get_allocator() };
				uint32_t word{ 0u };
				uint32_t offset{ 0u };
				size_t i = 0u;

				while ( i < name.size() )
				{
					if ( i != 0 && ( i % 4u ) == 0u )
					{
						packed.push_back( word );
						word = 0u;
						offset = 0u;
					}

					word |= ( uint32_t( name[i] ) & 0x000000FF ) << offset;
					++i;
					offset += 8u;
				}

				if ( word )
				{
					packed.push_back( word );
				}

				if ( name.empty()
					|| ( i != 0 && ( i % 4u ) == 0u ) )
				{
					packed.push_back( 0u );
				}

				it = nameCache.try_emplace( name, packed ).first;
			}

			return it->second;
		}

		static std::string unpackString( UInt32List const & packed )
		{
			std::string result{};

			for ( auto w : packed )
			{
				for ( uint32_t j = 0; j < 4; j++, w >>= 8 )
				{
					auto c = char( w & 0xff );

					if ( c == '\0' )
					{
						return result;
					}

					result += c;
				}
			}

			AST_Failure( "Non terminated string" );
			return std::string{};
		}

		static Instruction::Configuration const & getConfig( spv::Op opCode )
		{
			static Instruction::Configuration dummy{};

			switch ( opCode )
			{
			case spv::OpSource:
				return SourceInstruction::Config;
			case spv::OpSourceExtension:
				return SourceExtensionInstruction::Config;
			case spv::OpName:
				return NameInstruction::Config;
			case spv::OpString:
				return StringInstruction::Config;
			case spv::OpMemberName:
				return MemberNameInstruction::Config;
			case spv::OpExtension:
				return ExtensionInstruction::Config;
			case spv::OpExtInstImport:
				return ExtInstImportInstruction::Config;
			case spv::OpExtInst:
				return ExtInstInstruction::Config;
			case spv::OpMemoryModel:
				return MemoryModelInstruction::Config;
			case spv::OpEntryPoint:
				return EntryPointInstruction::Config;
			case spv::OpExecutionMode:
				return ExecutionModeInstruction::Config;
			case spv::OpCapability:
				return CapabilityInstruction::Config;
			case spv::OpTypeVoid:
				return VoidTypeInstruction::Config;
			case spv::OpTypeBool:
				return BooleanTypeInstruction::Config;
			case spv::OpTypeInt:
				return IntTypeInstruction::Config;
			case spv::OpTypeFloat:
				return FloatTypeInstruction::Config;
			case spv::OpTypeVector:
				return VectorTypeInstruction::Config;
			case spv::OpTypeMatrix:
				return MatrixTypeInstruction::Config;
			case spv::OpTypeImage:
				return ImageTypeInstruction::Config;
			case spv::OpTypeSampler:
				return SamplerTypeInstruction::Config;
			case spv::OpTypeSampledImage:
				return TextureTypeInstruction::Config;
			case spv::OpTypeArray:
				return ArrayTypeInstruction::Config;
			case spv::OpTypeRuntimeArray:
				return RuntimeArrayTypeInstruction::Config;
			case spv::OpTypeStruct:
				return StructTypeInstruction::Config;
			case spv::OpTypePointer:
				return PointerTypeInstruction::Config;
			case spv::OpTypeFunction:
				return FunctionTypeInstruction::Config;
			case spv::OpConstantTrue:
				return ConstantTrueInstruction::Config;
			case spv::OpConstantFalse:
				return ConstantFalseInstruction::Config;
			case spv::OpConstant:
				return ConstantInstruction::Config;
			case spv::OpConstantComposite:
				return ConstantCompositeInstruction::Config;
			case spv::OpSpecConstantTrue:
				return SpecConstantTrueInstruction::Config;
			case spv::OpSpecConstantFalse:
				return SpecConstantFalseInstruction::Config;
			case spv::OpSpecConstant:
				return SpecConstantInstruction::Config;
			case spv::OpSpecConstantComposite:
				return SpecConstantCompositeInstruction::Config;
			case spv::OpSpecConstantOp:
				return SpecConstantOpInstruction::Config;
			case spv::OpFunction:
				return FunctionInstruction::Config;
			case spv::OpFunctionParameter:
				return FunctionParameterInstruction::Config;
			case spv::OpFunctionEnd:
				return FunctionEndInstruction::Config;
			case spv::OpFunctionCall:
				return FunctionCallInstruction::Config;
			case spv::OpVariable:
				return VariableInstruction::Config;
			case spv::OpImageTexelPointer:
				return ImageTexelPointerInstruction::Config;
			case spv::OpLoad:
				return LoadInstruction::Config;
			case spv::OpStore:
				return StoreInstruction::Config;
			case spv::OpCopyMemory:
				return CopyMemoryInstruction::Config;
			case spv::OpAccessChain:
				return AccessChainInstruction::Config;
			case spv::OpDecorate:
				return DecorateInstruction::Config;
			case spv::OpMemberDecorate:
				return MemberDecorateInstruction::Config;
			case spv::OpVectorShuffle:
				return VectorShuffleInstruction::Config;
			case spv::OpCompositeConstruct:
				return CompositeConstructInstruction::Config;
			case spv::OpCompositeExtract:
				return CompositeExtractInstruction::Config;
			case spv::OpTranspose:
				return IntrinsicInstructionT< spv::OpTranspose >::Config;
			case spv::OpImageSampleImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleImplicitLod >::Config;
			case spv::OpImageSampleExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleExplicitLod >::Config;
			case spv::OpImageSampleDrefImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleDrefImplicitLod >::Config;
			case spv::OpImageSampleDrefExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleDrefExplicitLod >::Config;
			case spv::OpImageSampleProjImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjImplicitLod >::Config;
			case spv::OpImageSampleProjExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjExplicitLod >::Config;
			case spv::OpImageSampleProjDrefImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjDrefImplicitLod >::Config;
			case spv::OpImageSampleProjDrefExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjDrefExplicitLod >::Config;
			case spv::OpImageFetch:
				return TextureAccessInstructionT< spv::OpImageFetch >::Config;
			case spv::OpImageGather:
				return TextureAccessInstructionT< spv::OpImageGather >::Config;
			case spv::OpImageDrefGather:
				return TextureAccessInstructionT< spv::OpImageDrefGather >::Config;
			case spv::OpImageRead:
				return ImageAccessInstructionT< spv::OpImageRead >::Config;
			case spv::OpImageWrite:
				return ImageAccessInstructionT< spv::OpImageWrite >::Config;
			case spv::OpImage:
				return ImageInstruction::Config;
			case spv::OpImageQueryFormat:
				return ImageAccessInstructionT< spv::OpImageQueryFormat >::Config;
			case spv::OpImageQueryOrder:
				return ImageAccessInstructionT< spv::OpImageQueryOrder >::Config;
			case spv::OpImageQuerySizeLod:
				return ImageAccessInstructionT< spv::OpImageQuerySizeLod >::Config;
			case spv::OpImageQuerySize:
				return ImageAccessInstructionT< spv::OpImageQuerySize >::Config;
			case spv::OpImageQueryLod:
				return ImageAccessInstructionT< spv::OpImageQueryLod >::Config;
			case spv::OpImageQueryLevels:
				return ImageAccessInstructionT< spv::OpImageQueryLevels >::Config;
			case spv::OpImageQuerySamples:
				return ImageAccessInstructionT< spv::OpImageQuerySamples >::Config;
			case spv::OpConvertFToU:
				return UnInstructionT< spv::OpConvertFToU >::Config;
			case spv::OpConvertFToS:
				return UnInstructionT< spv::OpConvertFToS >::Config;
			case spv::OpConvertSToF:
				return UnInstructionT< spv::OpConvertSToF >::Config;
			case spv::OpConvertUToF:
				return UnInstructionT< spv::OpConvertUToF >::Config;
			case spv::OpUConvert:
				return UnInstructionT< spv::OpUConvert >::Config;
			case spv::OpSConvert:
				return UnInstructionT< spv::OpSConvert >::Config;
			case spv::OpFConvert:
				return UnInstructionT< spv::OpFConvert >::Config;
			case spv::OpQuantizeToF16:
				return UnInstructionT< spv::OpQuantizeToF16 >::Config;
			case spv::OpConvertPtrToU:
				return UnInstructionT< spv::OpConvertPtrToU >::Config;
			case spv::OpSatConvertSToU:
				return UnInstructionT< spv::OpSatConvertSToU >::Config;
			case spv::OpSatConvertUToS:
				return UnInstructionT< spv::OpSatConvertUToS >::Config;
			case spv::OpConvertUToPtr:
				return UnInstructionT< spv::OpConvertUToPtr >::Config;
			case spv::OpPtrCastToGeneric:
				return UnInstructionT< spv::OpPtrCastToGeneric >::Config;
			case spv::OpGenericCastToPtr:
				return UnInstructionT< spv::OpGenericCastToPtr >::Config;
			case spv::OpGenericCastToPtrExplicit:
				return UnInstructionT< spv::OpGenericCastToPtrExplicit >::Config;
			case spv::OpBitcast:
				return UnInstructionT< spv::OpBitcast >::Config;
			case spv::OpSNegate:
				return UnInstructionT< spv::OpSNegate >::Config;
			case spv::OpFNegate:
				return UnInstructionT< spv::OpFNegate >::Config;
			case spv::OpIAdd:
				return BinInstructionT < spv::OpIAdd >::Config;
			case spv::OpFAdd:
				return BinInstructionT < spv::OpFAdd >::Config;
			case spv::OpISub:
				return BinInstructionT < spv::OpISub >::Config;
			case spv::OpFSub:
				return BinInstructionT < spv::OpFSub >::Config;
			case spv::OpIMul:
				return BinInstructionT < spv::OpIMul >::Config;
			case spv::OpFMul:
				return BinInstructionT < spv::OpFMul >::Config;
			case spv::OpUDiv:
				return BinInstructionT < spv::OpUDiv >::Config;
			case spv::OpSDiv:
				return BinInstructionT < spv::OpSDiv >::Config;
			case spv::OpFDiv:
				return BinInstructionT < spv::OpFDiv >::Config;
			case spv::OpUMod:
				return BinInstructionT < spv::OpUMod >::Config;
			case spv::OpSRem:
				return BinInstructionT < spv::OpSRem >::Config;
			case spv::OpSMod:
				return BinInstructionT < spv::OpSMod >::Config;
			case spv::OpFRem:
				return BinInstructionT < spv::OpFRem >::Config;
			case spv::OpFMod:
				return BinInstructionT < spv::OpFMod >::Config;
			case spv::OpVectorTimesScalar:
				return BinInstructionT  < spv::OpVectorTimesScalar >::Config;
			case spv::OpMatrixTimesScalar:
				return BinInstructionT  < spv::OpMatrixTimesScalar >::Config;
			case spv::OpVectorTimesMatrix:
				return BinInstructionT  < spv::OpVectorTimesMatrix >::Config;
			case spv::OpMatrixTimesVector:
				return BinInstructionT < spv::OpMatrixTimesVector >::Config;
			case spv::OpMatrixTimesMatrix:
				return BinInstructionT  < spv::OpMatrixTimesMatrix >::Config;
			case spv::OpOuterProduct:
				return IntrinsicInstructionT< spv::OpOuterProduct >::Config;
			case spv::OpDot:
				return IntrinsicInstructionT< spv::OpDot >::Config;
			case spv::OpIAddCarry:
				return IntrinsicInstructionT< spv::OpIAddCarry >::Config;
			case spv::OpISubBorrow:
				return IntrinsicInstructionT< spv::OpISubBorrow >::Config;
			case spv::OpUMulExtended:
				return IntrinsicInstructionT< spv::OpUMulExtended >::Config;
			case spv::OpSMulExtended:
				return IntrinsicInstructionT< spv::OpSMulExtended >::Config;
			case spv::OpAny:
				return IntrinsicInstructionT< spv::OpAny >::Config;
			case spv::OpAll:
				return IntrinsicInstructionT< spv::OpAll >::Config;
			case spv::OpIsNan:
				return IntrinsicInstructionT< spv::OpIsNan >::Config;
			case spv::OpIsInf:
				return IntrinsicInstructionT< spv::OpIsInf >::Config;
			case spv::OpIsFinite:
				return IntrinsicInstructionT< spv::OpIsFinite >::Config;
			case spv::OpIsNormal:
				return IntrinsicInstructionT< spv::OpIsNormal >::Config;
			case spv::OpSignBitSet:
				return IntrinsicInstructionT< spv::OpSignBitSet >::Config;
			case spv::OpLogicalEqual:
				return BinInstructionT < spv::OpLogicalEqual >::Config;
			case spv::OpLogicalNotEqual:
				return BinInstructionT < spv::OpLogicalNotEqual >::Config;
			case spv::OpLogicalOr:
				return BinInstructionT < spv::OpLogicalOr >::Config;
			case spv::OpLogicalAnd:
				return BinInstructionT < spv::OpLogicalAnd >::Config;
			case spv::OpLogicalNot:
				return UnInstructionT < spv::OpLogicalNot >::Config;
			case spv::OpSelect:
				return SelectInstruction::Config;
			case spv::OpIEqual:
				return BinInstructionT < spv::OpIEqual >::Config;
			case spv::OpINotEqual:
				return BinInstructionT < spv::OpINotEqual >::Config;
			case spv::OpUGreaterThan:
				return BinInstructionT < spv::OpUGreaterThan >::Config;
			case spv::OpSGreaterThan:
				return BinInstructionT < spv::OpSGreaterThan >::Config;
			case spv::OpUGreaterThanEqual:
				return BinInstructionT < spv::OpUGreaterThanEqual >::Config;
			case spv::OpSGreaterThanEqual:
				return BinInstructionT < spv::OpSGreaterThanEqual >::Config;
			case spv::OpULessThan:
				return BinInstructionT < spv::OpULessThan >::Config;
			case spv::OpSLessThan:
				return BinInstructionT < spv::OpSLessThan >::Config;
			case spv::OpULessThanEqual:
				return BinInstructionT < spv::OpULessThanEqual >::Config;
			case spv::OpSLessThanEqual:
				return BinInstructionT < spv::OpSLessThanEqual >::Config;
			case spv::OpFOrdEqual:
				return BinInstructionT < spv::OpFOrdEqual >::Config;
			case spv::OpFUnordEqual:
				return BinInstructionT < spv::OpFUnordEqual >::Config;
			case spv::OpFOrdNotEqual:
				return BinInstructionT < spv::OpFOrdNotEqual >::Config;
			case spv::OpFUnordNotEqual:
				return BinInstructionT < spv::OpFUnordNotEqual >::Config;
			case spv::OpFOrdLessThan:
				return BinInstructionT < spv::OpFOrdLessThan >::Config;
			case spv::OpFUnordLessThan:
				return BinInstructionT < spv::OpFUnordLessThan >::Config;
			case spv::OpFOrdGreaterThan:
				return BinInstructionT < spv::OpFOrdGreaterThan >::Config;
			case spv::OpFUnordGreaterThan:
				return BinInstructionT < spv::OpFUnordGreaterThan >::Config;
			case spv::OpFOrdLessThanEqual:
				return BinInstructionT < spv::OpFOrdLessThanEqual >::Config;
			case spv::OpFUnordLessThanEqual:
				return BinInstructionT < spv::OpFUnordLessThanEqual >::Config;
			case spv::OpFOrdGreaterThanEqual:
				return BinInstructionT < spv::OpFOrdGreaterThanEqual >::Config;
			case spv::OpFUnordGreaterThanEqual:
				return BinInstructionT < spv::OpFUnordGreaterThanEqual >::Config;
			case spv::OpShiftRightLogical:
				return BinInstructionT < spv::OpShiftRightLogical >::Config;
			case spv::OpShiftRightArithmetic:
				return BinInstructionT < spv::OpShiftRightArithmetic >::Config;
			case spv::OpShiftLeftLogical:
				return BinInstructionT < spv::OpShiftLeftLogical >::Config;
			case spv::OpBitwiseOr:
				return BinInstructionT < spv::OpBitwiseOr >::Config;
			case spv::OpBitwiseXor:
				return BinInstructionT < spv::OpBitwiseXor >::Config;
			case spv::OpBitwiseAnd:
				return BinInstructionT < spv::OpBitwiseAnd >::Config;
			case spv::OpNot:
				return UnInstructionT < spv::OpNot >::Config;
			case spv::OpBitFieldInsert:
				return IntrinsicInstructionT< spv::OpBitFieldInsert >::Config;
			case spv::OpBitFieldSExtract:
				return IntrinsicInstructionT< spv::OpBitFieldSExtract >::Config;
			case spv::OpBitFieldUExtract:
				return IntrinsicInstructionT< spv::OpBitFieldUExtract >::Config;
			case spv::OpBitReverse:
				return IntrinsicInstructionT< spv::OpBitReverse >::Config;
			case spv::OpBitCount:
				return IntrinsicInstructionT< spv::OpBitCount >::Config;
			case spv::OpDPdx:
				return IntrinsicInstructionT< spv::OpDPdx >::Config;
			case spv::OpDPdy:
				return IntrinsicInstructionT< spv::OpDPdy >::Config;
			case spv::OpFwidth:
				return IntrinsicInstructionT< spv::OpFwidth >::Config;
			case spv::OpDPdxFine:
				return IntrinsicInstructionT< spv::OpDPdxFine >::Config;
			case spv::OpDPdyFine:
				return IntrinsicInstructionT< spv::OpDPdyFine >::Config;
			case spv::OpFwidthFine:
				return IntrinsicInstructionT< spv::OpFwidthFine >::Config;
			case spv::OpDPdxCoarse:
				return IntrinsicInstructionT< spv::OpDPdxCoarse >::Config;
			case spv::OpDPdyCoarse:
				return IntrinsicInstructionT< spv::OpDPdyCoarse >::Config;
			case spv::OpFwidthCoarse:
				return IntrinsicInstructionT< spv::OpFwidthCoarse >::Config;
			case spv::OpEmitVertex:
				return VoidIntrinsicInstructionT< spv::OpEmitVertex >::Config;
			case spv::OpEndPrimitive:
				return VoidIntrinsicInstructionT< spv::OpEndPrimitive >::Config;
			case spv::OpEmitStreamVertex:
				return VoidIntrinsicInstructionT< spv::OpEmitStreamVertex >::Config;
			case spv::OpEndStreamPrimitive:
				return VoidIntrinsicInstructionT< spv::OpEndStreamPrimitive >::Config;
			case spv::OpControlBarrier:
				return VoidIntrinsicInstructionT< spv::OpControlBarrier >::Config;
			case spv::OpMemoryBarrier:
				return VoidIntrinsicInstructionT< spv::OpMemoryBarrier >::Config;
			case spv::OpAtomicLoad:
				return IntrinsicInstructionT< spv::OpAtomicLoad >::Config;
			case spv::OpAtomicStore:
				return IntrinsicInstructionT< spv::OpAtomicStore >::Config;
			case spv::OpAtomicExchange:
				return IntrinsicInstructionT< spv::OpAtomicExchange >::Config;
			case spv::OpAtomicCompareExchange:
				return IntrinsicInstructionT< spv::OpAtomicCompareExchange >::Config;
			case spv::OpAtomicCompareExchangeWeak:
				return IntrinsicInstructionT< spv::OpAtomicCompareExchangeWeak >::Config;
			case spv::OpAtomicIIncrement:
				return IntrinsicInstructionT< spv::OpAtomicIIncrement >::Config;
			case spv::OpAtomicIDecrement:
				return IntrinsicInstructionT< spv::OpAtomicIDecrement >::Config;
			case spv::OpAtomicIAdd:
				return IntrinsicInstructionT< spv::OpAtomicIAdd >::Config;
			case spv::OpAtomicFAddEXT:
				return IntrinsicInstructionT< spv::OpAtomicFAddEXT >::Config;
			case spv::OpAtomicISub:
				return IntrinsicInstructionT< spv::OpAtomicISub >::Config;
			case spv::OpAtomicSMin:
				return IntrinsicInstructionT< spv::OpAtomicSMin >::Config;
			case spv::OpAtomicUMin:
				return IntrinsicInstructionT< spv::OpAtomicUMin >::Config;
			case spv::OpAtomicSMax:
				return IntrinsicInstructionT< spv::OpAtomicSMax >::Config;
			case spv::OpAtomicUMax:
				return IntrinsicInstructionT< spv::OpAtomicUMax >::Config;
			case spv::OpAtomicAnd:
				return IntrinsicInstructionT< spv::OpAtomicAnd >::Config;
			case spv::OpAtomicOr:
				return IntrinsicInstructionT< spv::OpAtomicOr >::Config;
			case spv::OpAtomicXor:
				return IntrinsicInstructionT< spv::OpAtomicXor >::Config;
			case spv::OpLoopMerge:
				return LoopMergeInstruction::Config;
			case spv::OpSelectionMerge:
				return SelectionMergeInstruction::Config;
			case spv::OpLabel:
				return LabelInstruction::Config;
			case spv::OpBranch:
				return BranchInstruction::Config;
			case spv::OpBranchConditional:
				return BranchConditionalInstruction::Config;
			case spv::OpSwitch:
				return SwitchInstruction::Config;
			case spv::OpKill:
				return KillInstruction::Config;
			case spv::OpReturn:
				return ReturnInstruction::Config;
			case spv::OpReturnValue:
				return ReturnValueInstruction::Config;
			case spv::OpImageSparseSampleImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleImplicitLod >::Config;
			case spv::OpImageSparseSampleExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleExplicitLod >::Config;
			case spv::OpImageSparseSampleDrefImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleDrefImplicitLod >::Config;
			case spv::OpImageSparseSampleDrefExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleDrefExplicitLod >::Config;
			case spv::OpImageSparseSampleProjImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjImplicitLod >::Config;
			case spv::OpImageSparseSampleProjExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjExplicitLod >::Config;
			case spv::OpImageSparseSampleProjDrefImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjDrefImplicitLod >::Config;
			case spv::OpImageSparseSampleProjDrefExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjDrefExplicitLod >::Config;
			case spv::OpImageSparseFetch:
				return ImageAccessInstructionT< spv::OpImageSparseFetch >::Config;
			case spv::OpImageSparseGather:
				return ImageAccessInstructionT< spv::OpImageSparseGather >::Config;
			case spv::OpImageSparseDrefGather:
				return ImageAccessInstructionT< spv::OpImageSparseDrefGather >::Config;
			case spv::OpImageSparseTexelsResident:
				return ImageAccessInstructionT< spv::OpImageSparseTexelsResident >::Config;
			case spv::OpImageSparseRead:
				return ImageAccessInstructionT < spv::OpImageSparseRead >::Config;
			case spv::OpUndef:
				return UndefInstruction::Config;
			case spv::OpTerminateInvocation:
				return TerminateInvocationInstruction::Config;
			case spv::OpSubgroupAllKHR:
				return IntrinsicInstructionT< spv::OpSubgroupAllKHR >::Config;
			case spv::OpSubgroupAnyKHR:
				return IntrinsicInstructionT< spv::OpSubgroupAnyKHR >::Config;
			case spv::OpSubgroupAllEqualKHR:
				return IntrinsicInstructionT< spv::OpSubgroupAllEqualKHR >::Config;
			case spv::OpGroupNonUniformRotateKHR:
				return IntrinsicInstructionT< spv::OpGroupNonUniformRotateKHR >::Config;
			case spv::OpReportIntersectionKHR:
				return IntrinsicInstructionT< spv::OpReportIntersectionKHR >::Config;
			case spv::OpIsHelperInvocationEXT:
				return IntrinsicInstructionT< spv::OpIsHelperInvocationEXT >::Config;
			case spv::OpTraceRayKHR:
				return VoidIntrinsicInstructionT< spv::OpTraceRayKHR >::Config;
			case spv::OpExecuteCallableKHR:
				return VoidIntrinsicInstructionT< spv::OpExecuteCallableKHR >::Config;
			case spv::OpWritePackedPrimitiveIndices4x8NV:
				return WritePackedPrimitiveIndices4x8Instruction::Config;
			case spv::OpSetMeshOutputsEXT:
				return SetMeshOutputsInstruction::Config;
			case spv::OpEmitMeshTasksEXT:
				return EmitMeshTasksInstruction::Config;
			case spv::OpGroupNonUniformElect:
				return GroupNonUniformElectInstruction::Config;
			case spv::OpGroupNonUniformAll:
				return GroupNonUniformAllInstruction::Config;
			case spv::OpGroupNonUniformAny:
				return GroupNonUniformAnyInstruction::Config;
			case spv::OpGroupNonUniformAllEqual:
				return GroupNonUniformAllEqualInstruction::Config;
			case spv::OpGroupNonUniformBroadcast:
				return GroupNonUniformBroadcastInstruction::Config;
			case spv::OpGroupNonUniformBroadcastFirst:
				return GroupNonUniformBroadcastFirstInstruction::Config;
			case spv::OpGroupNonUniformBallot:
				return GroupNonUniformBallotInstruction::Config;
			case spv::OpGroupNonUniformInverseBallot:
				return GroupNonUniformInverseBallotInstruction::Config;
			case spv::OpGroupNonUniformBallotBitExtract:
				return GroupNonUniformBallotBitExtractInstruction::Config;
			case spv::OpGroupNonUniformBallotBitCount:
				return GroupNonUniformBallotBitCountInstruction::Config;
			case spv::OpGroupNonUniformBallotFindLSB:
				return GroupNonUniformBallotFindLSBInstruction::Config;
			case spv::OpGroupNonUniformBallotFindMSB:
				return GroupNonUniformBallotFindMSBInstruction::Config;
			case spv::OpGroupNonUniformShuffle:
				return GroupNonUniformShuffleInstruction::Config;
			case spv::OpGroupNonUniformShuffleXor:
				return GroupNonUniformShuffleXorInstruction::Config;
			case spv::OpGroupNonUniformShuffleUp:
				return GroupNonUniformShuffleUpInstruction::Config;
			case spv::OpGroupNonUniformShuffleDown:
				return GroupNonUniformShuffleDownInstruction::Config;
			case spv::OpGroupNonUniformFAdd:
				return IntrinsicInstructionT< spv::OpGroupNonUniformFAdd >::Config;
			case spv::OpGroupNonUniformIAdd:
				return IntrinsicInstructionT< spv::OpGroupNonUniformIAdd >::Config;
			case spv::OpGroupNonUniformFMul:
				return IntrinsicInstructionT< spv::OpGroupNonUniformFMul >::Config;
			case spv::OpGroupNonUniformIMul:
				return IntrinsicInstructionT< spv::OpGroupNonUniformIMul >::Config;
			case spv::OpGroupNonUniformFMin:
				return IntrinsicInstructionT< spv::OpGroupNonUniformFMin >::Config;
			case spv::OpGroupNonUniformSMin:
				return IntrinsicInstructionT< spv::OpGroupNonUniformSMin >::Config;
			case spv::OpGroupNonUniformUMin:
				return IntrinsicInstructionT< spv::OpGroupNonUniformUMin >::Config;
			case spv::OpGroupNonUniformFMax:
				return IntrinsicInstructionT< spv::OpGroupNonUniformFMax >::Config;
			case spv::OpGroupNonUniformSMax:
				return IntrinsicInstructionT< spv::OpGroupNonUniformSMax >::Config;
			case spv::OpGroupNonUniformUMax:
				return IntrinsicInstructionT< spv::OpGroupNonUniformUMax >::Config;
			case spv::OpGroupNonUniformBitwiseAnd:
				return IntrinsicInstructionT< spv::OpGroupNonUniformBitwiseAnd >::Config;
			case spv::OpGroupNonUniformLogicalAnd:
				return IntrinsicInstructionT< spv::OpGroupNonUniformLogicalAnd >::Config;
			case spv::OpGroupNonUniformBitwiseOr:
				return IntrinsicInstructionT< spv::OpGroupNonUniformBitwiseOr >::Config;
			case spv::OpGroupNonUniformLogicalOr:
				return IntrinsicInstructionT< spv::OpGroupNonUniformLogicalOr >::Config;
			case spv::OpGroupNonUniformBitwiseXor:
				return IntrinsicInstructionT< spv::OpGroupNonUniformBitwiseXor >::Config;
			case spv::OpGroupNonUniformLogicalXor:
				return IntrinsicInstructionT< spv::OpGroupNonUniformLogicalXor >::Config;
			case spv::OpSubgroupBallotKHR:
				return IntrinsicInstructionT< spv::OpSubgroupBallotKHR >::Config;
			case spv::OpSubgroupReadInvocationKHR:
				return IntrinsicInstructionT< spv::OpSubgroupReadInvocationKHR >::Config;
			case spv::OpSubgroupFirstInvocationKHR:
				return IntrinsicInstructionT< spv::OpSubgroupFirstInvocationKHR >::Config;
			case spv::OpGroupNonUniformQuadBroadcast:
				return GroupNonUniformQuadBroadcastInstruction::Config;
			case spv::OpGroupNonUniformQuadSwap:
				return GroupNonUniformQuadSwapInstruction::Config;
			default:
				AST_Failure( "Unsupported Instruction operator" );
				return dummy;
			}
		}

		static Op makeOp( spv::Op op )
		{
			Op result{};
			result.setOp( op );
			return result;
		}
	}

	//*************************************************************************

	size_t ValueIdHasher::operator()( ValueId const & value )const noexcept
	{
		auto hash = std::hash< spv::Id >{}( value.id );
		ast::type::hashCombine( hash, value.isPointer() );
		return hash;
	}

	//*************************************************************************

	size_t ValueIdListHasher::operator()( ValueIdList const & value )const noexcept
	{
		assert( !value.empty() );
		auto hash = ValueIdHasher{}( value[0] );

		std::for_each( value.begin() + 1u
			, value.end()
			, [&hash]( ValueId const & id )
			{
				ast::type::hashCombine( hash, ValueIdHasher{}( id ) );
			} );

		return hash;
	}

	//*************************************************************************

	size_t IdListHasher::operator()( IdList const & list )const noexcept
	{
		assert( !list.empty() );
		auto hash = std::hash< spv::Id >{}( list[0] );

		std::for_each( list.begin() + 1u
			, list.end()
			, [&hash]( spv::Id id )
			{
				ast::type::hashCombine( hash, id );
			} );

		return hash;
	}

	//*************************************************************************

	size_t DebugIdHasher::operator()( TypeId const & value )const noexcept
	{
		auto hash = std::hash< spv::Id >{}( value.id.id );
		ast::type::hashCombine( hash, value.id.isPointer() );
		return hash;
	}

	//*************************************************************************

	size_t DebugIdListHasher::operator()( TypeIdList const & value )const noexcept
	{
		assert( !value.empty() );
		auto hash = DebugIdHasher{}( value[0] );

		std::for_each( value.begin() + 1u
			, value.end()
			, [&hash]( DebugId const & id )
			{
				ast::type::hashCombine( hash, DebugIdHasher{}( id ) );
			} );

		return hash;
	}

	//*************************************************************************

	IdList convert( ValueIdList const & in )
	{
		IdList result{ in.get_allocator() };
		result.reserve( in.size() );

		for ( auto & v : in )
		{
			result.push_back( v.id );
		}

		return result;
	}

	ValueIdList convert( IdList const & in )
	{
		ValueIdList result{ in.get_allocator() };
		result.reserve( in.size() );

		for ( auto & v : in )
		{
			result.emplace_back( v );
		}

		return result;
	}

	ValueIdList convert( DebugIdList const & in )
	{
		ValueIdList result{ in.get_allocator() };
		result.reserve( in.size() );

		for ( auto & v : in )
		{
			result.push_back( v.id );
		}

		return result;
	}

	DebugIdList toTypeId( ValueIdList const & in )
	{
		DebugIdList result{ in.get_allocator() };
		result.reserve( in.size() );

		for ( auto & v : in )
		{
			result.emplace_back( v.id );
		}

		return result;
	}

	ast::type::Storage convert( spv::StorageClass in )
	{
		switch ( in )
		{
		case spv::StorageClassUniformConstant:
			return ast::type::Storage::eUniformConstant;
		case spv::StorageClassInput:
			return ast::type::Storage::eInput;
		case spv::StorageClassUniform:
			return ast::type::Storage::eUniform;
		case spv::StorageClassOutput:
			return ast::type::Storage::eOutput;
		case spv::StorageClassWorkgroup:
			return ast::type::Storage::eWorkgroup;
		case spv::StorageClassCrossWorkgroup:
			return ast::type::Storage::eCrossWorkgroup;
		case spv::StorageClassPrivate:
			return ast::type::Storage::ePrivate;
		case spv::StorageClassFunction:
			return ast::type::Storage::eFunction;
		case spv::StorageClassGeneric:
			return ast::type::Storage::eGeneric;
		case spv::StorageClassPushConstant:
			return ast::type::Storage::ePushConstant;
		case spv::StorageClassAtomicCounter:
			return ast::type::Storage::eAtomicCounter;
		case spv::StorageClassImage:
			return ast::type::Storage::eImage;
		case spv::StorageClassStorageBuffer:
			return ast::type::Storage::eStorageBuffer;
		case spv::StorageClassCallableDataKHR:
			return ast::type::Storage::eCallableData;
		case spv::StorageClassIncomingCallableDataKHR:
			return ast::type::Storage::eIncomingCallableData;
		case spv::StorageClassRayPayloadKHR:
			return ast::type::Storage::eRayPayload;
		case spv::StorageClassHitAttributeKHR:
			return ast::type::Storage::eHitAttribute;
		case spv::StorageClassIncomingRayPayloadKHR:
			return ast::type::Storage::eIncomingRayPayload;
		case spv::StorageClassShaderRecordBufferKHR:
			return ast::type::Storage::eShaderRecordBuffer;
		case spv::StorageClassPhysicalStorageBuffer:
			return ast::type::Storage::ePhysicalStorageBuffer;
		case spv::StorageClassCodeSectionINTEL:
			return ast::type::Storage::eCodeSection;
		case spv::StorageClassTaskPayloadWorkgroupEXT:
			return ast::type::Storage::eTaskPayloadWorkgroup;
		default:
			AST_Failure( "Unsupported spv::StorageClass" );
			return ast::type::Storage::eFunction;
		}
	}

	spv::StorageClass convert( ast::type::Storage in )
	{
		switch ( in )
		{
		case ast::type::Storage::eUniformConstant:
			return spv::StorageClassUniformConstant;
		case ast::type::Storage::eInput:
			return spv::StorageClassInput;
		case ast::type::Storage::eUniform:
			return spv::StorageClassUniform;
		case ast::type::Storage::eOutput:
			return spv::StorageClassOutput;
		case ast::type::Storage::eWorkgroup:
			return spv::StorageClassWorkgroup;
		case ast::type::Storage::eCrossWorkgroup:
			return spv::StorageClassCrossWorkgroup;
		case ast::type::Storage::ePrivate:
			return spv::StorageClassPrivate;
		case ast::type::Storage::eFunction:
			return spv::StorageClassFunction;
		case ast::type::Storage::eGeneric:
			return spv::StorageClassGeneric;
		case ast::type::Storage::ePushConstant:
			return spv::StorageClassPushConstant;
		case ast::type::Storage::eAtomicCounter:
			return spv::StorageClassAtomicCounter;
		case ast::type::Storage::eImage:
			return spv::StorageClassImage;
		case ast::type::Storage::eStorageBuffer:
			return spv::StorageClassStorageBuffer;
		case ast::type::Storage::eCallableData:
			return spv::StorageClassCallableDataKHR;
		case ast::type::Storage::eIncomingCallableData:
			return spv::StorageClassIncomingCallableDataKHR;
		case ast::type::Storage::eRayPayload:
			return spv::StorageClassRayPayloadKHR;
		case ast::type::Storage::eHitAttribute:
			return spv::StorageClassHitAttributeKHR;
		case ast::type::Storage::eIncomingRayPayload:
			return spv::StorageClassIncomingRayPayloadKHR;
		case ast::type::Storage::eShaderRecordBuffer:
			return spv::StorageClassShaderRecordBufferKHR;
		case ast::type::Storage::ePhysicalStorageBuffer:
			return spv::StorageClassPhysicalStorageBuffer;
		case ast::type::Storage::eCodeSection:
			return spv::StorageClassCodeSectionINTEL;
		case ast::type::Storage::eTaskPayloadWorkgroup:
			return spv::StorageClassTaskPayloadWorkgroupEXT;
		default:
			AST_Failure( "Unsupported ast::type::Storage" );
			return spv::StorageClassFunction;
		}
	}

	//*************************************************************************

	Instruction::Instruction( NamesCache & nameCache
		, Configuration const & pconfig
		, spv::Op pop
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, IdList poperands
		, Optional< std::string > pname
		, Optional< ast::Map< int32_t, spv::Id > > plabels )
		: returnTypeId{ preturnTypeId ? Optional< spv::Id >{ preturnTypeId->id } : std::nullopt }
		, resultId{ presultId ? Optional< spv::Id >{ presultId->id } : std::nullopt }
		, operands{ std::move( poperands ) }
		, config{ pconfig }
		, name{ std::move( pname ) }
		, labels{ std::move( plabels ) }
	{
		if ( bool( name ) )
		{
			packedName = insthlp::packString( nameCache, name.value() );
		}

		op.setOpData( pop
			, uint16_t( 1u
				+ ( bool( returnTypeId ) ? 1u : 0u )
				+ ( bool( resultId ) ? 1u : 0u )
				+ operands.size()
				+ ( bool( packedName ) ? packedName.value().size() : 0u )
				+ ( bool( labels ) ? labels.value().size() * 2u : 0u ) ) );
		assertType( *this, config );
	}

	Instruction::Instruction( NamesCache & nameCache
		, Configuration const & pconfig
		, spv::Op pop
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList const & poperands
		, Optional< std::string > pname
		, Optional< ast::Map< int32_t, spv::Id > > plabels )
		: Instruction{ nameCache
			, pconfig
			, pop
			, std::move( preturnTypeId )
			, std::move( presultId )
			, convert( poperands )
			, std::move( pname )
			, std::move( plabels ) }
	{
	}

	Instruction::Instruction( NamesCache & nameCache
		, Configuration const & pconfig
		, spv::Op pop
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId )
		: Instruction{ nameCache
			, pconfig
			, pop
			, std::move( preturnTypeId )
			, std::move( presultId )
			, IdList{ nameCache.get_allocator() } }
	{
	}

	Instruction::Instruction( ast::ShaderAllocatorBlock * alloc
		, Configuration const & pconfig
		, Op pop
		, BufferCIt & buffer )
		: op{ pop }
		, operands{ ast::StlAllocatorT< spv::Id >{ alloc } }
		, config{ pconfig }
	{
		uint32_t save = buffer.index;

		if ( config.hasReturnTypeId )
		{
			returnTypeId = buffer.popValue();
		}

		if ( config.hasResultId )
		{
			resultId = buffer.popValue();
		}

		if ( config.hasName )
		{
			packedName = insthlp::deserializePackedName( alloc, buffer );
			name = insthlp::unpackString( packedName.value() );
		}

		auto index = 1u + buffer.index - save;

		if ( config.operandsCount )
		{
			auto count = op.getOpData().opCount - index;
			assert( config.operandsCount == dynamicOperandCount
				|| config.operandsCount == count );
			operands.resize( count );

			for ( auto & operand : operands )
			{
				operand = buffer.popValue();
			}
		}
		else if ( config.hasLabels )
		{
			auto count = ( op.getOpData().opCount - index ) / 2u;
			labels = ast::Map< int32_t, spv::Id >{ alloc };

			for ( auto i = 0u; i < count; ++i )
			{
				auto label = buffer.popValue();
				labels.value()[int32_t( label )] = buffer.popValue();
			}
		}
	}

	Instruction::Instruction( ast::ShaderAllocatorBlock * alloc
		, Configuration const & pconfig
		, Op pop
		, BufferIt & buffer )
		: op{ pop }
		, operands{ ast::StlAllocatorT< spv::Id >{ alloc } }
		, config{ pconfig }
	{
		uint32_t save = buffer.index;

		if ( config.hasReturnTypeId )
		{
			returnTypeId = buffer.popValue();
		}

		if ( config.hasResultId )
		{
			resultId = buffer.popValue();
		}

		if ( config.hasName )
		{
			packedName = insthlp::deserializePackedName( alloc, buffer );
			name = insthlp::unpackString( packedName.value() );
		}

		auto index = buffer.index - save;

		if ( config.operandsCount )
		{
			auto count = op.getOpData().opCount - index;
			operands.resize( count );

			for ( auto & operand : operands )
			{
				operand = buffer.popValue();
			}
		}
		else if ( config.hasLabels )
		{
			auto count = ( op.getOpData().opCount - index ) / 2u;
			labels = ast::Map< int32_t, spv::Id >{ alloc };

			for ( auto i = 0u; i < count; ++i )
			{
				auto label = buffer.popValue();
				labels.value()[int32_t( label )] = buffer.popValue();
			}
		}
	}

	Instruction::Instruction( ast::ShaderAllocatorBlock * alloc
		, Configuration const & pconfig
		, spv::Op pop
		, BufferCIt & buffer )
		: Instruction{ alloc, pconfig, insthlp::makeOp( pop ), buffer }
	{
		op.setOpDataCount( uint16_t( 1u
			+ ( bool( returnTypeId ) ? 1u : 0u )
			+ ( bool( resultId ) ? 1u : 0u )
			+ this->operands.size()
			+ ( bool( packedName ) ? packedName.value().size() : 0u )
			+ ( bool( labels ) ? labels.value().size() * 2u : 0u ) ) );
	}

	Instruction::Instruction( ast::ShaderAllocatorBlock * alloc
		, Configuration const & pconfig
		, spv::Op pop
		, BufferIt & buffer )
		: Instruction{ alloc, pconfig, insthlp::makeOp( pop ), buffer }
	{
		op.setOpDataCount( uint16_t( 1u
			+ ( bool( returnTypeId ) ? 1u : 0u )
			+ ( bool( resultId ) ? 1u : 0u )
			+ operands.size()
			+ ( bool( packedName ) ? packedName.value().size() : 0u )
			+ ( bool( labels ) ? labels.value().size() * 2u : 0u ) ) );
	}

	void Instruction::serialize( UInt32List & buffer
		, Instruction const & instruction )
	{
		assertType( instruction, instruction.config );

		auto pushValue = [&buffer]( uint32_t value )
		{
			buffer.push_back( value );
		};

		pushValue( instruction.op.getOpValue() );

		if ( instruction.returnTypeId )
		{
			pushValue( instruction.returnTypeId.value() );
		}
		
		if ( instruction.resultId )
		{
			pushValue( instruction.resultId.value() );
		}

		if ( instruction.packedName )
		{
			for ( auto & c : instruction.packedName.value() )
			{
				pushValue( c );
			}
		}

		if ( !instruction.operands.empty() )
		{
			for ( auto & operand : instruction.operands )
			{
				pushValue( operand );
			}
		}

		if ( instruction.labels )
		{
			for ( auto & [id, label] : instruction.labels.value() )
			{
				pushValue( uint32_t( id ) );
				pushValue( label );
			}
		}
	}

	InstructionPtr Instruction::deserialize( ast::ShaderAllocatorBlock * alloc
		, BufferCIt & buffer )
	{
		spirv::Op op;
		op.setOpValue( buffer.popValue() );
		assert( op.getOpData().opCode != spv::OpNop);
		auto & config = insthlp::getConfig( spv::Op( op.getOpData().opCode ) );
		return std::make_unique< Instruction >( alloc, config, op, buffer );
	}

	InstructionPtr Instruction::deserialize( ast::ShaderAllocatorBlock * alloc
		, BufferIt & buffer )
	{
		spirv::Op op;
		op.setOpValue( buffer.popValue() );
		assert( op.getOpData().opCode != spv::OpNop );
		auto & config = insthlp::getConfig( spv::Op( op.getOpData().opCode ) );
		return std::make_unique< Instruction >( alloc, config, op, buffer );
	}

	//*************************************************************************
}
