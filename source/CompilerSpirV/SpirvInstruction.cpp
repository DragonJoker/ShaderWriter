/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvInstruction.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>

#include <algorithm>
#include <map>

namespace spirv
{
	//*************************************************************************

	namespace
	{
		template< typename IterT >
		UInt32List deserializePackedName( BufferItT< IterT > & buffer )
		{
			auto value = buffer.popValue();
			UInt32List result;

			while ( ( value & 0xFF000000 ) != 0u )
			{
				result.push_back( value );
				value = buffer.popValue();
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
				return StoreInstruction::config;
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
				return BinInstructionT < spv::OpIAdd >::config;
			case spv::OpFAdd:
				return BinInstructionT < spv::OpFAdd >::config;
			case spv::OpISub:
				return BinInstructionT < spv::OpISub >::config;
			case spv::OpFSub:
				return BinInstructionT < spv::OpFSub >::config;
			case spv::OpIMul:
				return BinInstructionT < spv::OpIMul >::config;
			case spv::OpFMul:
				return BinInstructionT < spv::OpFMul >::config;
			case spv::OpUDiv:
				return BinInstructionT < spv::OpUDiv >::config;
			case spv::OpSDiv:
				return BinInstructionT < spv::OpSDiv >::config;
			case spv::OpFDiv:
				return BinInstructionT < spv::OpFDiv >::config;
			case spv::OpUMod:
				return BinInstructionT < spv::OpUMod >::config;
			case spv::OpSRem:
				return BinInstructionT < spv::OpSRem >::config;
			case spv::OpSMod:
				return BinInstructionT < spv::OpSMod >::config;
			case spv::OpFRem:
				return BinInstructionT < spv::OpFRem >::config;
			case spv::OpFMod:
				return BinInstructionT < spv::OpFMod >::config;
			case spv::OpVectorTimesScalar:
				return BinInstructionT  < spv::OpVectorTimesScalar >::config;
			case spv::OpMatrixTimesScalar:
				return BinInstructionT  < spv::OpMatrixTimesScalar >::config;
			case spv::OpVectorTimesMatrix:
				return BinInstructionT  < spv::OpVectorTimesMatrix >::config;
			case spv::OpMatrixTimesVector:
				return BinInstructionT < spv::OpMatrixTimesVector >::config;
			case spv::OpMatrixTimesMatrix:
				return BinInstructionT  < spv::OpMatrixTimesMatrix >::config;
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
				return VoidIntrinsicInstructionT< spv::OpEmitVertex >::config;
			case spv::OpEndPrimitive:
				return VoidIntrinsicInstructionT< spv::OpEndPrimitive >::config;
			case spv::OpEmitStreamVertex:
				return VoidIntrinsicInstructionT< spv::OpEmitStreamVertex >::config;
			case spv::OpEndStreamPrimitive:
				return VoidIntrinsicInstructionT< spv::OpEndStreamPrimitive >::config;
			case spv::OpControlBarrier:
				return VoidIntrinsicInstructionT< spv::OpControlBarrier >::config;
			case spv::OpMemoryBarrier:
				return VoidIntrinsicInstructionT< spv::OpMemoryBarrier >::config;
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

	size_t ValueIdHasher::operator()( ValueId const & value )const
	{
		auto hash = std::hash< spv::Id >{}( value.id );
		ast::type::hashCombine( hash, value.isPointer() );
		return hash;
	}

	//*************************************************************************

	size_t ValueIdListHasher::operator()( ValueIdList const & value )const
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

	size_t IdListHasher::operator()( IdList const & list )const
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

	IdList convert( ValueIdList const & in )
	{
		IdList result;
		result.reserve( in.size() );

		for ( auto & v : in )
		{
			result.push_back( v.id );
		}

		return result;
	}

	ValueIdList convert( IdList const & in )
	{
		ValueIdList result;
		result.reserve( in.size() );

		for ( auto & v : in )
		{
			result.push_back( { v } );
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
		default:
			AST_Failure( "Unsupported ast::type::Storage" );
			return spv::StorageClassFunction;
		}
	}

	//*************************************************************************

	Instruction::Instruction( Config const & pconfig
		, spv::Op pop
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList poperands
		, Optional< std::string > pname
		, Optional< std::map< int32_t, spv::Id > > plabels )
		: returnTypeId{ preturnTypeId ? Optional< spv::Id >{ preturnTypeId->id } : std::nullopt }
		, resultId{ presultId ? Optional< spv::Id >{ presultId->id } : std::nullopt }
		, operands{ convert( poperands ) }
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
		, BufferCIt & buffer )
		: op{ pop }
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
			packedName = deserializePackedName( buffer );
			name = unpackString( packedName.value() );
		}

		auto index = 1u + buffer.index - save;

		if ( config.operandsCount )
		{
			auto count = op.opData.opCount - index;
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
			auto count = ( op.opData.opCount - index ) / 2u;
			labels = std::map< int32_t, spv::Id >{};

			for ( auto i = 0u; i < count; ++i )
			{
				auto label = buffer.popValue();
				labels.value()[int32_t( label )] = buffer.popValue();
			}
		}
	}

	Instruction::Instruction( Config const & pconfig
		, Op pop
		, BufferIt & buffer )
		: op{ pop }
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
			packedName = deserializePackedName( buffer );
			name = unpackString( packedName.value() );
		}

		auto index = buffer.index - save;

		if ( config.operandsCount )
		{
			auto count = op.opData.opCount - index;
			operands.resize( count );

			for ( auto & operand : operands )
			{
				operand = buffer.popValue();
			}
		}
		else if ( config.hasLabels )
		{
			auto count = ( op.opData.opCount - index ) / 2u;
			labels = std::map< int32_t, spv::Id >{};

			for ( auto i = 0u; i < count; ++i )
			{
				auto label = buffer.popValue();
				labels.value()[int32_t( label )] = buffer.popValue();
			}
		}
	}

	Instruction::Instruction( Config const & pconfig
		, spv::Op pop
		, BufferCIt & buffer )
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
		, BufferIt & buffer )
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

	InstructionPtr Instruction::deserialize( BufferCIt & buffer )
	{
		spirv::Op op;
		op.opValue = buffer.popValue();
		assert( op.opData.opCode != spv::OpNop );
		auto & config = getConfig( spv::Op( op.opData.opCode ) );
		return std::make_unique< Instruction >( config, op, buffer );
	}

	InstructionPtr Instruction::deserialize( BufferIt & buffer )
	{
		spirv::Op op;
		op.opValue = buffer.popValue();
		assert( op.opData.opCode != spv::OpNop );
		auto & config = getConfig( spv::Op( op.opData.opCode ) );
		return std::make_unique< Instruction >( config, op, buffer );
	}

	//*************************************************************************
}
