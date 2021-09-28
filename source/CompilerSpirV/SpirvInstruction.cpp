/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvInstruction.hpp"

#include <map>

namespace spirv
{
	//*************************************************************************

	namespace
	{
		UInt32List deserializePackedName( UInt32ListCIt & buffer
			, uint32_t & index )
		{
			auto popValue = [&buffer, &index]()
			{
				auto result = *buffer;
				++buffer;
				++index;
				return result;
			};
			auto value = popValue();
			UInt32List result;

			while ( ( value & 0xFF000000 ) != 0u )
			{
				result.push_back( value );
				value = popValue();
			}

			result.push_back( value );
			return result;
		}

		UInt32List deserializePackedName( UInt32ListIt & buffer
			, uint32_t & index )
		{
			auto popValue = [&buffer, &index]()
			{
				auto result = *buffer;
				++buffer;
				++index;
				return result;
			};
			auto value = popValue();
			UInt32List result;

			while ( ( value & 0xFF000000 ) != 0u )
			{
				result.push_back( value );
				value = popValue();
			}

			result.push_back( value );
			return result;
		}

		std::vector< uint32_t > const & packString( std::string const & name )
		{
			static std::map < std::string, std::vector< uint32_t > > cache;
			auto it = cache.find( name );

			if ( it == cache.end() )
			{
				std::vector< uint32_t > packed;
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

				it = cache.emplace( name, packed ).first;
			}

			return it->second;
		}

		std::string unpackString( std::vector< uint32_t > const & packed )
		{
			std::string result;

			for ( auto w : packed )
			{
				for ( uint32_t j = 0; j < 4; j++, w >>= 8 )
				{
					char c = char( w & 0xff );

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

		Instruction::Config const & getConfig( spv::Op opCode )
		{
			static Instruction::Config dummy{};

			switch ( opCode )
			{
			case spv::OpSource:
				return SourceInstruction::config;
			case spv::OpName:
				return NameInstruction::config;
			case spv::OpMemberName:
				return MemberNameInstruction::config;
			case spv::OpExtension:
				return ExtensionInstruction::config;
			case spv::OpExtInstImport:
				return ExtInstImportInstruction::config;
			case spv::OpExtInst:
				return ExtInstInstruction::config;
			case spv::OpMemoryModel:
				return MemoryModelInstruction::config;
			case spv::OpEntryPoint:
				return EntryPointInstruction::config;
			case spv::OpExecutionMode:
				return ExecutionModeInstruction::config;
			case spv::OpCapability:
				return CapabilityInstruction::config;
			case spv::OpTypeVoid:
				return VoidTypeInstruction::config;
			case spv::OpTypeBool:
				return BooleanTypeInstruction::config;
			case spv::OpTypeInt:
				return IntTypeInstruction::config;
			case spv::OpTypeFloat:
				return FloatTypeInstruction::config;
			case spv::OpTypeVector:
				return VectorTypeInstruction::config;
			case spv::OpTypeMatrix:
				return MatrixTypeInstruction::config;
			case spv::OpTypeImage:
				return ImageTypeInstruction::config;
			case spv::OpTypeSampler:
				return SamplerTypeInstruction::config;
			case spv::OpTypeSampledImage:
				return SampledImageTypeInstruction::config;
			case spv::OpTypeArray:
				return ArrayTypeInstruction::config;
			case spv::OpTypeRuntimeArray:
				return RuntimeArrayTypeInstruction::config;
			case spv::OpTypeStruct:
				return StructTypeInstruction::config;
			case spv::OpTypePointer:
				return PointerTypeInstruction::config;
			case spv::OpTypeFunction:
				return FunctionTypeInstruction::config;
			case spv::OpConstantTrue:
				return ConstantTrueInstruction::config;
			case spv::OpConstantFalse:
				return ConstantFalseInstruction::config;
			case spv::OpConstant:
				return ConstantInstruction::config;
			case spv::OpConstantComposite:
				return ConstantCompositeInstruction::config;
			case spv::OpSpecConstantTrue:
				return SpecConstantTrueInstruction::config;
			case spv::OpSpecConstantFalse:
				return SpecConstantFalseInstruction::config;
			case spv::OpSpecConstant:
				return SpecConstantInstruction::config;
			case spv::OpSpecConstantComposite:
				return SpecConstantCompositeInstruction::config;
			case spv::OpSpecConstantOp:
				return SpecConstantOpInstruction::config;
			case spv::OpFunction:
				return FunctionInstruction::config;
			case spv::OpFunctionParameter:
				return FunctionParameterInstruction::config;
			case spv::OpFunctionEnd:
				return FunctionEndInstruction::config;
			case spv::OpFunctionCall:
				return FunctionCallInstruction::config;
			case spv::OpVariable:
				return VariableInstruction::config;
			case spv::OpImageTexelPointer:
				return ImageTexelPointerInstruction::config;
			case spv::OpLoad:
				return LoadInstruction::config;
			case spv::OpStore:
				return LoadInstruction::config;
			case spv::OpCopyMemory:
				return CopyMemoryInstruction::config;
			case spv::OpAccessChain:
				return AccessChainInstruction::config;
			case spv::OpDecorate:
				return DecorateInstruction::config;
			case spv::OpMemberDecorate:
				return MemberDecorateInstruction::config;
			case spv::OpVectorShuffle:
				return VectorShuffleInstruction::config;
			case spv::OpCompositeConstruct:
				return CompositeConstructInstruction::config;
			case spv::OpCompositeExtract:
				return CompositeExtractInstruction::config;
			case spv::OpTranspose:
				return IntrinsicInstructionT< spv::OpTranspose >::config;
			case spv::OpImageSampleImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleImplicitLod >::config;
			case spv::OpImageSampleExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleExplicitLod >::config;
			case spv::OpImageSampleDrefImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleDrefImplicitLod >::config;
			case spv::OpImageSampleDrefExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleDrefExplicitLod >::config;
			case spv::OpImageSampleProjImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjImplicitLod >::config;
			case spv::OpImageSampleProjExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjExplicitLod >::config;
			case spv::OpImageSampleProjDrefImplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjDrefImplicitLod >::config;
			case spv::OpImageSampleProjDrefExplicitLod:
				return TextureAccessInstructionT< spv::OpImageSampleProjDrefExplicitLod >::config;
			case spv::OpImageFetch:
				return TextureAccessInstructionT< spv::OpImageFetch >::config;
			case spv::OpImageGather:
				return TextureAccessInstructionT< spv::OpImageGather >::config;
			case spv::OpImageDrefGather:
				return TextureAccessInstructionT< spv::OpImageDrefGather >::config;
			case spv::OpImageRead:
				return ImageAccessInstructionT< spv::OpImageRead >::config;
			case spv::OpImageWrite:
				return ImageAccessInstructionT< spv::OpImageWrite >::config;
			case spv::OpImage:
				return ImageInstruction::config;
			case spv::OpImageQueryFormat:
				return ImageAccessInstructionT< spv::OpImageQueryFormat >::config;
			case spv::OpImageQueryOrder:
				return ImageAccessInstructionT< spv::OpImageQueryOrder >::config;
			case spv::OpImageQuerySizeLod:
				return ImageAccessInstructionT< spv::OpImageQuerySizeLod >::config;
			case spv::OpImageQuerySize:
				return ImageAccessInstructionT< spv::OpImageQuerySize >::config;
			case spv::OpImageQueryLod:
				return ImageAccessInstructionT< spv::OpImageQueryLod >::config;
			case spv::OpImageQueryLevels:
				return ImageAccessInstructionT< spv::OpImageQueryLevels >::config;
			case spv::OpImageQuerySamples:
				return ImageAccessInstructionT< spv::OpImageQuerySamples >::config;
			case spv::OpConvertFToU:
				return UnInstructionT< spv::OpConvertFToU >::config;
			case spv::OpConvertFToS:
				return UnInstructionT< spv::OpConvertFToS >::config;
			case spv::OpConvertSToF:
				return UnInstructionT< spv::OpConvertSToF >::config;
			case spv::OpConvertUToF:
				return UnInstructionT< spv::OpConvertUToF >::config;
			case spv::OpUConvert:
				return UnInstructionT< spv::OpUConvert >::config;
			case spv::OpSConvert:
				return UnInstructionT< spv::OpSConvert >::config;
			case spv::OpFConvert:
				return UnInstructionT< spv::OpFConvert >::config;
			case spv::OpQuantizeToF16:
				return UnInstructionT< spv::OpQuantizeToF16 >::config;
			case spv::OpConvertPtrToU:
				return UnInstructionT< spv::OpConvertPtrToU >::config;
			case spv::OpSatConvertSToU:
				return UnInstructionT< spv::OpSatConvertSToU >::config;
			case spv::OpSatConvertUToS:
				return UnInstructionT< spv::OpSatConvertUToS >::config;
			case spv::OpConvertUToPtr:
				return UnInstructionT< spv::OpConvertUToPtr >::config;
			case spv::OpPtrCastToGeneric:
				return UnInstructionT< spv::OpPtrCastToGeneric >::config;
			case spv::OpGenericCastToPtr:
				return UnInstructionT< spv::OpGenericCastToPtr >::config;
			case spv::OpGenericCastToPtrExplicit:
				return UnInstructionT< spv::OpGenericCastToPtrExplicit >::config;
			case spv::OpBitcast:
				return UnInstructionT< spv::OpBitcast >::config;
			case spv::OpSNegate:
				return UnInstructionT< spv::OpSNegate >::config;
			case spv::OpFNegate:
				return UnInstructionT< spv::OpFNegate >::config;
			case spv::OpIAdd:
				return UnInstructionT < spv::OpIAdd >::config;
			case spv::OpFAdd:
				return UnInstructionT < spv::OpFAdd >::config;
			case spv::OpISub:
				return UnInstructionT < spv::OpISub >::config;
			case spv::OpFSub:
				return UnInstructionT < spv::OpFSub >::config;
			case spv::OpIMul:
				return UnInstructionT < spv::OpIMul >::config;
			case spv::OpFMul:
				return UnInstructionT < spv::OpFMul >::config;
			case spv::OpUDiv:
				return UnInstructionT < spv::OpUDiv >::config;
			case spv::OpSDiv:
				return UnInstructionT < spv::OpSDiv >::config;
			case spv::OpFDiv:
				return UnInstructionT < spv::OpFDiv >::config;
			case spv::OpUMod:
				return UnInstructionT < spv::OpUMod >::config;
			case spv::OpSRem:
				return UnInstructionT < spv::OpSRem >::config;
			case spv::OpSMod:
				return UnInstructionT < spv::OpSMod >::config;
			case spv::OpFRem:
				return UnInstructionT < spv::OpFRem >::config;
			case spv::OpFMod:
				return UnInstructionT < spv::OpFMod >::config;
			case spv::OpVectorTimesScalar:
				return UnInstructionT < spv::OpVectorTimesScalar >::config;
			case spv::OpMatrixTimesScalar:
				return UnInstructionT < spv::OpMatrixTimesScalar >::config;
			case spv::OpVectorTimesMatrix:
				return UnInstructionT < spv::OpVectorTimesMatrix >::config;
			case spv::OpMatrixTimesVector:
				return UnInstructionT < spv::OpMatrixTimesVector >::config;
			case spv::OpMatrixTimesMatrix:
				return UnInstructionT < spv::OpMatrixTimesMatrix >::config;
			case spv::OpOuterProduct:
				return IntrinsicInstructionT< spv::OpOuterProduct >::config;
			case spv::OpDot:
				return IntrinsicInstructionT< spv::OpDot >::config;
			case spv::OpIAddCarry:
				return IntrinsicInstructionT< spv::OpIAddCarry >::config;
			case spv::OpISubBorrow:
				return IntrinsicInstructionT< spv::OpISubBorrow >::config;
			case spv::OpUMulExtended:
				return IntrinsicInstructionT< spv::OpUMulExtended >::config;
			case spv::OpSMulExtended:
				return IntrinsicInstructionT< spv::OpSMulExtended >::config;
			case spv::OpAny:
				return IntrinsicInstructionT< spv::OpAny >::config;
			case spv::OpAll:
				return IntrinsicInstructionT< spv::OpAll >::config;
			case spv::OpIsNan:
				return IntrinsicInstructionT< spv::OpIsNan >::config;
			case spv::OpIsInf:
				return IntrinsicInstructionT< spv::OpIsInf >::config;
			case spv::OpIsFinite:
				return IntrinsicInstructionT< spv::OpIsFinite >::config;
			case spv::OpIsNormal:
				return IntrinsicInstructionT< spv::OpIsNormal >::config;
			case spv::OpSignBitSet:
				return IntrinsicInstructionT< spv::OpSignBitSet >::config;
			case spv::OpLogicalEqual:
				return BinInstructionT < spv::OpLogicalEqual >::config;
			case spv::OpLogicalNotEqual:
				return BinInstructionT < spv::OpLogicalNotEqual >::config;
			case spv::OpLogicalOr:
				return BinInstructionT < spv::OpLogicalOr >::config;
			case spv::OpLogicalAnd:
				return BinInstructionT < spv::OpLogicalAnd >::config;
			case spv::OpLogicalNot:
				return BinInstructionT < spv::OpLogicalNot >::config;
			case spv::OpSelect:
				return SelectInstruction::config;
			case spv::OpIEqual:
				return BinInstructionT < spv::OpIEqual >::config;
			case spv::OpINotEqual:
				return BinInstructionT < spv::OpINotEqual >::config;
			case spv::OpUGreaterThan:
				return BinInstructionT < spv::OpUGreaterThan >::config;
			case spv::OpSGreaterThan:
				return BinInstructionT < spv::OpSGreaterThan >::config;
			case spv::OpUGreaterThanEqual:
				return BinInstructionT < spv::OpUGreaterThanEqual >::config;
			case spv::OpSGreaterThanEqual:
				return BinInstructionT < spv::OpSGreaterThanEqual >::config;
			case spv::OpULessThan:
				return BinInstructionT < spv::OpULessThan >::config;
			case spv::OpSLessThan:
				return BinInstructionT < spv::OpSLessThan >::config;
			case spv::OpULessThanEqual:
				return BinInstructionT < spv::OpULessThanEqual >::config;
			case spv::OpSLessThanEqual:
				return BinInstructionT < spv::OpSLessThanEqual >::config;
			case spv::OpFOrdEqual:
				return BinInstructionT < spv::OpFOrdEqual >::config;
			case spv::OpFUnordEqual:
				return BinInstructionT < spv::OpFUnordEqual >::config;
			case spv::OpFOrdNotEqual:
				return BinInstructionT < spv::OpFOrdNotEqual >::config;
			case spv::OpFUnordNotEqual:
				return BinInstructionT < spv::OpFUnordNotEqual >::config;
			case spv::OpFOrdLessThan:
				return BinInstructionT < spv::OpFOrdLessThan >::config;
			case spv::OpFUnordLessThan:
				return BinInstructionT < spv::OpFUnordLessThan >::config;
			case spv::OpFOrdGreaterThan:
				return BinInstructionT < spv::OpFOrdGreaterThan >::config;
			case spv::OpFUnordGreaterThan:
				return BinInstructionT < spv::OpFUnordGreaterThan >::config;
			case spv::OpFOrdLessThanEqual:
				return BinInstructionT < spv::OpFOrdLessThanEqual >::config;
			case spv::OpFUnordLessThanEqual:
				return BinInstructionT < spv::OpFUnordLessThanEqual >::config;
			case spv::OpFOrdGreaterThanEqual:
				return BinInstructionT < spv::OpFOrdGreaterThanEqual >::config;
			case spv::OpFUnordGreaterThanEqual:
				return BinInstructionT < spv::OpFUnordGreaterThanEqual >::config;
			case spv::OpShiftRightLogical:
				return BinInstructionT < spv::OpShiftRightLogical >::config;
			case spv::OpShiftRightArithmetic:
				return BinInstructionT < spv::OpShiftRightArithmetic >::config;
			case spv::OpShiftLeftLogical:
				return BinInstructionT < spv::OpShiftLeftLogical >::config;
			case spv::OpBitwiseOr:
				return BinInstructionT < spv::OpBitwiseOr >::config;
			case spv::OpBitwiseXor:
				return BinInstructionT < spv::OpBitwiseXor >::config;
			case spv::OpBitwiseAnd:
				return BinInstructionT < spv::OpBitwiseAnd >::config;
			case spv::OpNot:
				return UnInstructionT < spv::OpNot >::config;
			case spv::OpBitFieldInsert:
				return IntrinsicInstructionT< spv::OpBitFieldInsert >::config;
			case spv::OpBitFieldSExtract:
				return IntrinsicInstructionT< spv::OpBitFieldSExtract >::config;
			case spv::OpBitFieldUExtract:
				return IntrinsicInstructionT< spv::OpBitFieldUExtract >::config;
			case spv::OpBitReverse:
				return IntrinsicInstructionT< spv::OpBitReverse >::config;
			case spv::OpBitCount:
				return IntrinsicInstructionT< spv::OpBitCount >::config;
			case spv::OpDPdx:
				return IntrinsicInstructionT< spv::OpDPdx >::config;
			case spv::OpDPdy:
				return IntrinsicInstructionT< spv::OpDPdy >::config;
			case spv::OpFwidth:
				return IntrinsicInstructionT< spv::OpFwidth >::config;
			case spv::OpDPdxFine:
				return IntrinsicInstructionT< spv::OpDPdxFine >::config;
			case spv::OpDPdyFine:
				return IntrinsicInstructionT< spv::OpDPdyFine >::config;
			case spv::OpFwidthFine:
				return IntrinsicInstructionT< spv::OpFwidthFine >::config;
			case spv::OpDPdxCoarse:
				return IntrinsicInstructionT< spv::OpDPdxCoarse >::config;
			case spv::OpDPdyCoarse:
				return IntrinsicInstructionT< spv::OpDPdyCoarse >::config;
			case spv::OpFwidthCoarse:
				return IntrinsicInstructionT< spv::OpFwidthCoarse >::config;
			case spv::OpEmitVertex:
				return IntrinsicInstructionT< spv::OpEmitVertex >::config;
			case spv::OpEndPrimitive:
				return IntrinsicInstructionT< spv::OpEndPrimitive >::config;
			case spv::OpEmitStreamVertex:
				return IntrinsicInstructionT< spv::OpEmitStreamVertex >::config;
			case spv::OpEndStreamPrimitive:
				return IntrinsicInstructionT< spv::OpEndStreamPrimitive >::config;
			case spv::OpControlBarrier:
				return IntrinsicInstructionT< spv::OpControlBarrier >::config;
			case spv::OpMemoryBarrier:
				return IntrinsicInstructionT< spv::OpMemoryBarrier >::config;
			case spv::OpAtomicLoad:
				return IntrinsicInstructionT< spv::OpAtomicLoad >::config;
			case spv::OpAtomicStore:
				return IntrinsicInstructionT< spv::OpAtomicStore >::config;
			case spv::OpAtomicExchange:
				return IntrinsicInstructionT< spv::OpAtomicExchange >::config;
			case spv::OpAtomicCompareExchange:
				return IntrinsicInstructionT< spv::OpAtomicCompareExchange >::config;
			case spv::OpAtomicCompareExchangeWeak:
				return IntrinsicInstructionT< spv::OpAtomicCompareExchangeWeak >::config;
			case spv::OpAtomicIIncrement:
				return IntrinsicInstructionT< spv::OpAtomicIIncrement >::config;
			case spv::OpAtomicIDecrement:
				return IntrinsicInstructionT< spv::OpAtomicIDecrement >::config;
			case spv::OpAtomicIAdd:
				return IntrinsicInstructionT< spv::OpAtomicIAdd >::config;
			case spv::OpAtomicISub:
				return IntrinsicInstructionT< spv::OpAtomicISub >::config;
			case spv::OpAtomicSMin:
				return IntrinsicInstructionT< spv::OpAtomicSMin >::config;
			case spv::OpAtomicUMin:
				return IntrinsicInstructionT< spv::OpAtomicUMin >::config;
			case spv::OpAtomicSMax:
				return IntrinsicInstructionT< spv::OpAtomicSMax >::config;
			case spv::OpAtomicUMax:
				return IntrinsicInstructionT< spv::OpAtomicUMax >::config;
			case spv::OpAtomicAnd:
				return IntrinsicInstructionT< spv::OpAtomicAnd >::config;
			case spv::OpAtomicOr:
				return IntrinsicInstructionT< spv::OpAtomicOr >::config;
			case spv::OpAtomicXor:
				return IntrinsicInstructionT< spv::OpAtomicXor >::config;
			case spv::OpLoopMerge:
				return LoopMergeInstruction::config;
			case spv::OpSelectionMerge:
				return SelectionMergeInstruction::config;
			case spv::OpLabel:
				return LabelInstruction::config;
			case spv::OpBranch:
				return BranchInstruction::config;
			case spv::OpBranchConditional:
				return BranchConditionalInstruction::config;
			case spv::OpSwitch:
				return SwitchInstruction::config;
			case spv::OpKill:
				return KillInstruction::config;
			case spv::OpReturn:
				return ReturnInstruction::config;
			case spv::OpReturnValue:
				return ReturnValueInstruction::config;
			case spv::OpImageSparseSampleImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleImplicitLod >::config;
			case spv::OpImageSparseSampleExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleExplicitLod >::config;
			case spv::OpImageSparseSampleDrefImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleDrefImplicitLod >::config;
			case spv::OpImageSparseSampleDrefExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleDrefExplicitLod >::config;
			case spv::OpImageSparseSampleProjImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjImplicitLod >::config;
			case spv::OpImageSparseSampleProjExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjExplicitLod >::config;
			case spv::OpImageSparseSampleProjDrefImplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjDrefImplicitLod >::config;
			case spv::OpImageSparseSampleProjDrefExplicitLod:
				return ImageAccessInstructionT< spv::OpImageSparseSampleProjDrefExplicitLod >::config;
			case spv::OpImageSparseFetch:
				return ImageAccessInstructionT< spv::OpImageSparseFetch >::config;
			case spv::OpImageSparseGather:
				return ImageAccessInstructionT< spv::OpImageSparseGather >::config;
			case spv::OpImageSparseDrefGather:
				return ImageAccessInstructionT< spv::OpImageSparseDrefGather >::config;
			case spv::OpImageSparseTexelsResident:
				return ImageAccessInstructionT< spv::OpImageSparseTexelsResident >::config;
			case spv::OpImageSparseRead:
				return ImageAccessInstructionT < spv::OpImageSparseRead >::config;
			case spv::OpUndef:
				return UndefInstruction::config;
			default:
				AST_Failure( "Unsupported Instruction operator" );
				return dummy;
			}
		}

		Op makeOp( spv::Op op )
		{
			Op result{};
			result.op = op;
			return result;
		}
	}

	//*************************************************************************

	Instruction::Instruction( Config const & pconfig
		, spv::Op pop
		, Optional< spv::Id > preturnTypeId
		, Optional< spv::Id > presultId
		, IdList poperands
		, Optional< std::string > pname
		, Optional< std::map< int32_t, spv::Id > > plabels )
		: returnTypeId{ preturnTypeId }
		, resultId{ presultId }
		, operands{ poperands }
		, packedName{ nullopt }
		, config{ pconfig }
		, name{ pname }
		, labels{ plabels }
	{
		if ( bool( name ) )
		{
			packedName = packString( name.value() );
		}

		op.op = pop;
		op.opData.opCount = uint16_t( 1u
			+ ( bool( returnTypeId ) ? 1u : 0u )
			+ ( bool( resultId ) ? 1u : 0u )
			+ operands.size()
			+ ( bool( packedName ) ? packedName.value().size() : 0u )
			+ ( bool( labels ) ? labels.value().size() * 2u : 0u ) );

		assertType( *this, config );
	}

	Instruction::Instruction( Config const & pconfig
		, Op pop
		, UInt32ListCIt & buffer )
		: op{ pop }
		, config{ pconfig }
	{
		uint32_t index = 1u;
		auto popValue = [&buffer, &index]()
		{
			auto result = *buffer;
			++buffer;
			++index;
			return result;
		};

		if ( config.hasReturnTypeId )
		{
			returnTypeId = popValue();
		}

		if ( config.hasResultId )
		{
			resultId = popValue();
		}

		if ( config.hasName )
		{
			packedName = deserializePackedName( buffer, index );
			name = unpackString( packedName.value() );
		}

		if ( config.operandsCount )
		{
			auto count = op.opData.opCount - index;
			operands.resize( count );

			for ( auto & operand : operands )
			{
				operand = popValue();
			}
		}
		else if ( config.hasLabels )
		{
			auto count = ( op.opData.opCount - index ) / 2u;
			labels = std::map< int32_t, spv::Id >{};

			for ( auto i = 0u; i < count; ++i )
			{
				auto label = popValue();
				labels.value()[int32_t( label )] = popValue();
			}
		}
	}

	Instruction::Instruction( Config const & pconfig
		, Op pop
		, UInt32ListIt & buffer )
		: op{ pop }
		, config{ pconfig }
	{
		uint32_t index = 1u;
		auto popValue = [&buffer, &index]()
		{
			auto result = *buffer;
			++buffer;
			++index;
			return result;
		};

		if ( config.hasReturnTypeId )
		{
			returnTypeId = popValue();
		}

		if ( config.hasResultId )
		{
			resultId = popValue();
		}

		if ( config.hasName )
		{
			packedName = deserializePackedName( buffer, index );
			name = unpackString( packedName.value() );
		}

		if ( config.operandsCount )
		{
			auto count = op.opData.opCount - index;
			operands.resize( count );

			for ( auto & operand : operands )
			{
				operand = popValue();
			}
		}
		else if ( config.hasLabels )
		{
			auto count = ( op.opData.opCount - index ) / 2u;
			labels = std::map< int32_t, spv::Id >{};

			for ( auto i = 0u; i < count; ++i )
			{
				auto label = popValue();
				labels.value()[int32_t( label )] = popValue();
			}
		}
	}

	Instruction::Instruction( Config const & pconfig
		, spv::Op pop
		, UInt32ListCIt & buffer )
		: Instruction{ pconfig, makeOp( pop ), buffer }
	{
		op.opData.opCount = uint16_t( 1u
			+ ( bool( returnTypeId ) ? 1u : 0u )
			+ ( bool( resultId ) ? 1u : 0u )
			+ this->operands.size()
			+ ( bool( packedName ) ? packedName.value().size() : 0u )
			+ ( bool( labels ) ? labels.value().size() * 2u : 0u ) );
	}

	Instruction::Instruction( Config const & pconfig
		, spv::Op pop
		, UInt32ListIt & buffer )
		: Instruction{ pconfig, makeOp( pop ), buffer }
	{
		op.opData.opCount = uint16_t( 1u
			+ ( bool( returnTypeId ) ? 1u : 0u )
			+ ( bool( resultId ) ? 1u : 0u )
			+ operands.size()
			+ ( bool( packedName ) ? packedName.value().size() : 0u )
			+ ( bool( labels ) ? labels.value().size() * 2u : 0u ) );
	}

	Instruction::~Instruction()
	{
	}

	void Instruction::serialize( UInt32List & buffer
		, Instruction const & instruction )
	{
		assertType( instruction, instruction.config );

		auto pushValue = [&buffer]( uint32_t value )
		{
			buffer.push_back( value );
		};

		pushValue( instruction.op.opValue );

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
			for ( auto & label : instruction.labels.value() )
			{
				pushValue( uint32_t( label.first ) );
				pushValue( label.second );
			}
		}
	}

	InstructionPtr Instruction::deserialize( UInt32ListCIt & buffer )
	{
		auto index = 0u;
		auto popValue = [&buffer, &index]()
		{
			auto result = *buffer;
			++buffer;
			++index;
			return result;
		};
		spirv::Op op;
		op.opValue = popValue();
		assert( op.opData.opCode != spv::OpNop );
		auto & config = getConfig( spv::Op( op.opData.opCode ) );
		return std::make_unique< Instruction >( config, op, buffer );
	}

	InstructionPtr Instruction::deserialize( UInt32ListIt & buffer )
	{
		auto index = 0u;
		auto popValue = [&buffer, &index]()
		{
			auto result = *buffer;
			++buffer;
			++index;
			return result;
		};
		spirv::Op op;
		op.opValue = popValue();
		assert( op.opData.opCode != spv::OpNop );
		auto & config = getConfig( spv::Op( op.opData.opCode ) );
		return std::make_unique< Instruction >( config, op, buffer );
	}

	//*************************************************************************
}
