/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvInstruction_H___
#define ___SDW_SpirvInstruction_H___
#pragma once

#include "spirv/spirv.hpp"
#include "compileSpirV.hpp"

#include <ShaderAST/Type/TypeStruct.hpp>

#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

#if defined( __clang__ )
#	include <optional>
namespace spirv
{
	template< typename T >
	using Optional = std::optional< T >;
	using std::nullopt;
}
#elif defined( __GNUG__ )
#	define SDW_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#	if SDW_COMPILER_VERSION < 40900
#		error "Unsupported version of GCC"
#	elif SDW_COMPILER_VERSION < 70400
#		include <experimental/optional>
namespace spirv
{
	template< typename T >
	using Optional = std::experimental::optional< T >;
	using std::experimental::nullopt;
}
#	else
#		include <optional>
namespace spirv
{
	template< typename T >
	using Optional = std::optional< T >;
	using std::nullopt;
}
#	endif
#else
#	include <optional>
namespace spirv
{
	template< typename T >
	using Optional = std::optional< T >;
	using std::nullopt;
}
#endif

namespace spirv
{
	union Op
	{
		struct
		{
			uint16_t opCode;
			uint16_t opCount;
		};
		uint32_t opValue;
		spv::Op op;
	};

	using IdList = std::vector< spv::Id >;
	using UInt32List = std::vector< uint32_t >;
	using UInt32ListIt = UInt32List::iterator;
	using UInt32ListCIt = UInt32List::const_iterator;

	static uint32_t constexpr dynamicOperandCount = ~( 0u );

	struct Instruction;
	using InstructionPtr = std::unique_ptr< Instruction >;

	struct Instruction
	{
		struct Config
		{
			spv::Op op;
			bool hasReturnTypeId;
			bool hasResultId;
			uint32_t operandsCount;
			bool hasName;
			bool hasLabels;
		};
		SDWSPIRV_API Instruction( Config const & config
			, spv::Op op = spv::OpNop
			, Optional< spv::Id > returnTypeId = nullopt
			, Optional< spv::Id > resultId = nullopt
			, IdList operands = IdList{}
			, Optional< std::string > name = nullopt
			, Optional< std::map< int32_t, spv::Id > > labels = nullopt );
		SDWSPIRV_API Instruction( Config const & config
			, Op op
			, UInt32ListIt & buffer );
		SDWSPIRV_API Instruction( Config const & config
			, Op op
			, UInt32ListCIt & buffer );
		SDWSPIRV_API Instruction( Config const & config
			, spv::Op op
			, UInt32ListIt & buffer );
		SDWSPIRV_API Instruction( Config const & config
			, spv::Op op
			, UInt32ListCIt & buffer );
		SDWSPIRV_API static void serialize( UInt32List & buffer
			, Instruction const & instruction );
		SDWSPIRV_API static InstructionPtr deserialize( UInt32ListCIt & buffer );
		SDWSPIRV_API static InstructionPtr deserialize( UInt32ListIt & buffer );
		SDWSPIRV_API virtual ~Instruction();

		// Serialisable.
		Op op;
		Optional< spv::Id > returnTypeId;
		Optional< spv::Id > resultId;
		IdList operands;
		Optional< UInt32List > packedName;
		// Used during construction.
		Config const & config;
		Optional< std::string > name;
		Optional< std::map< int32_t, spv::Id > > labels;
	};

	using InstructionPtr = std::unique_ptr< Instruction >;
	using InstructionList = std::vector< InstructionPtr >;
	using InstructionListIt = InstructionList::iterator;

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	Instruction::Config makeConfig()
	{
		return Instruction::Config
		{
			Operator,
			HasReturnTypeId,
			HasResultId,
			OperandsCount,
			HasName,
			HasLabels,
		};
	}

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	struct InstructionT
		: public Instruction
	{
		static spv::Op constexpr op = Operator;
		static bool constexpr hasReturnTypeId = HasReturnTypeId;
		static bool constexpr hasResultId = HasResultId;
		static uint32_t constexpr operandsCount = OperandsCount;
		static bool constexpr hasName = HasName;
		static bool constexpr hasLabels = HasLabels;
		static Config const config;

		inline InstructionT( Optional< spv::Id > returnTypeId = nullopt
			, Optional< spv::Id > resultId = nullopt
			, IdList operands = IdList{}
			, Optional< std::string > name = nullopt
			, Optional< std::map< int32_t, spv::Id > > labels = nullopt );
		inline InstructionT( UInt32ListIt & buffer );
		inline InstructionT( UInt32ListCIt & buffer );
	};

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	Instruction::Config const InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >::config = makeConfig< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >();

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId >
	struct VariadicInstructionT
		: public InstructionT< Operator, HasReturnTypeId, HasResultId, dynamicOperandCount, false, false >
	{
		static spv::Op constexpr op = Operator;
		static bool constexpr hasReturnTypeId = HasReturnTypeId;
		static bool constexpr hasResultId = HasResultId;
		static uint32_t constexpr operandsCount = dynamicOperandCount;
		static bool constexpr hasName = false;
		static bool constexpr hasLabels = false;

		inline VariadicInstructionT( Optional< spv::Id > returnTypeId = nullopt
			, Optional< spv::Id > resultId = nullopt
			, IdList operands = IdList{} );
		inline VariadicInstructionT( UInt32ListIt & buffer );
		inline VariadicInstructionT( UInt32ListCIt & buffer );
	};

	template< spv::Op Operator >
	using UnInstructionT = InstructionT< Operator, true, true, 1u, false, false >;

	template< spv::Op Operator >
	using BinInstructionT = InstructionT< Operator, true, true, 2u, false, false >;

	template< spv::Op Operator >
	using ImageAccessInstructionT = VariadicInstructionT< Operator, true, true >;

	template< spv::Op Operator >
	using TextureAccessInstructionT = VariadicInstructionT< Operator, true, true >;

	template< spv::Op Operator >
	using IntrinsicInstructionT = VariadicInstructionT< Operator, true, true >;

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	using InstructionTPtr = std::unique_ptr< InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels > >;

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	struct InstructionTMaker;

	template< typename InstructionType, typename ... Params >
	inline std::unique_ptr< InstructionType > makeInstruction( Params && ... params );
	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	inline void assertType( Instruction const & instruction );
	inline void assertType( Instruction const & instruction
		, Instruction::Config const & config );
	inline void assertType( Instruction const & instruction
		, spv::Op op
		, bool hasReturnTypeId
		, bool hasResultId
		, uint32_t operandsCount
		, bool hasName
		, bool hasLabels );

	using ExtensionInstruction = InstructionT< spv::OpExtension, false, false, 0u, true, false >;
	using ExtInstImportInstruction = InstructionT< spv::OpExtInstImport, false, true, 0u, true, false >;
	using SourceInstruction = InstructionT< spv::OpSource, false, false, 2u, false, false >;
	using MemoryModelInstruction = InstructionT< spv::OpMemoryModel, false, false, 2u, false, false >;
	using EntryPointInstruction = InstructionT< spv::OpEntryPoint, true, true, dynamicOperandCount, true, false >;
	using ExecutionModeInstruction = VariadicInstructionT< spv::OpExecutionMode, false, false >;
	using CapabilityInstruction = InstructionT< spv::OpCapability, false, false, 1u, false, false >;
	using DecorateInstruction = VariadicInstructionT< spv::OpDecorate, false, false >;
	using MemberDecorateInstruction = VariadicInstructionT< spv::OpMemberDecorate, false, false >;
	using NameInstruction = InstructionT< spv::OpName, false, true, 0u, true, false >;
	using MemberNameInstruction = InstructionT< spv::OpMemberName, true, true, 0u, true, false >;

	using VoidTypeInstruction = InstructionT< spv::OpTypeVoid, false, true, 0u, false, false >;
	using BooleanTypeInstruction = InstructionT< spv::OpTypeBool, false, true, 0u, false, false >;
	using IntTypeInstruction = InstructionT< spv::OpTypeInt, false, true, 2u, false, false >;
	using FloatTypeInstruction = InstructionT< spv::OpTypeFloat, false, true, 1u, false, false >;
	using VectorTypeInstruction = InstructionT< spv::OpTypeVector, false, true, 2u, false, false >;
	using MatrixTypeInstruction = InstructionT< spv::OpTypeMatrix, false, true, 2u, false, false >;
	using SamplerTypeInstruction = InstructionT< spv::OpTypeSampler, false, true, 0u, false, false >;
	using SampledImageTypeInstruction = InstructionT< spv::OpTypeSampledImage, false, true, 1u, false, false >;
	using RuntimeArrayTypeInstruction = InstructionT< spv::OpTypeRuntimeArray, false, true, 1u, false, false >;
	using ArrayTypeInstruction = InstructionT< spv::OpTypeArray, false, true, 2u, false, false >;
	using PointerTypeInstruction = InstructionT< spv::OpTypePointer, false, true, 2u, false, false >;
	using FunctionTypeInstruction = VariadicInstructionT< spv::OpTypeFunction, false, true >;
	using ImageTypeInstruction = VariadicInstructionT< spv::OpTypeImage, false, true >;
	using StructTypeInstruction = VariadicInstructionT< spv::OpTypeStruct, false, true >;

	using ConstantInstruction = VariadicInstructionT< spv::OpConstant, true, true >;
	using ConstantCompositeInstruction = VariadicInstructionT< spv::OpConstantComposite, true, true >;
	using ConstantTrueInstruction = InstructionT< spv::OpConstantTrue, true, true, 0u, false, false >;
	using ConstantFalseInstruction = InstructionT< spv::OpConstantFalse, true, true, 0u, false, false >;
	using SpecConstantOpInstruction = VariadicInstructionT< spv::OpSpecConstantOp, true, true >;
	using SpecConstantInstruction = VariadicInstructionT< spv::OpSpecConstant, true, true >;
	using SpecConstantCompositeInstruction = VariadicInstructionT< spv::OpSpecConstantComposite, true, true >;
	using SpecConstantTrueInstruction = InstructionT< spv::OpSpecConstantTrue, true, true, 0u, false, false >;
	using SpecConstantFalseInstruction = InstructionT< spv::OpSpecConstantFalse, true, true, 0u, false, false >;
	using SwitchInstruction = InstructionT< spv::OpSwitch, false, false, 2u, false, true >;
	using SelectInstruction = InstructionT< spv::OpSelect, true, true, 3u, false, false >;
	using LoadInstruction = InstructionT< spv::OpLoad, true, true, 1u, false, false >;
	using StoreInstruction = InstructionT< spv::OpStore, false, false, 2u, false, false >;
	using CopyMemoryInstruction = VariadicInstructionT< spv::OpCopyMemory, false, false >;
	using VariableInstruction = VariadicInstructionT< spv::OpVariable, true, true >;
	using CompositeExtractInstruction = VariadicInstructionT< spv::OpCompositeExtract, true, true >;
	using CompositeConstructInstruction = VariadicInstructionT< spv::OpCompositeConstruct, true, true >;
	using VectorShuffleInstruction = VariadicInstructionT< spv::OpVectorShuffle, true, true >;
	using AccessChainInstruction = VariadicInstructionT< spv::OpAccessChain, true, true >;
	using FunctionCallInstruction = VariadicInstructionT< spv::OpFunctionCall, true, true >;
	using ImageTexelPointerInstruction = VariadicInstructionT< spv::OpImageTexelPointer, true, true >;
	using ImageInstruction = InstructionT< spv::OpImage, true, true, 1u, false, false >;
	using ImageStoreInstruction = VariadicInstructionT< spv::OpImageWrite, false, false >;
	using ExtInstInstruction = VariadicInstructionT< spv::OpExtInst, true, true >;
	using FunctionParameterInstruction = InstructionT< spv::OpFunctionParameter, true, true, 0u, false, false >;
	using LabelInstruction = InstructionT< spv::OpLabel, false, true, 0u, false, false >;
	using FunctionInstruction = InstructionT< spv::OpFunction, true, true, 2u, false, false >;

	using KillInstruction = InstructionT< spv::OpKill, false, false, 0u, false, false >;
	using BranchInstruction = InstructionT< spv::OpBranch, false, false, 1u, false, false >;
	using BranchConditionalInstruction = VariadicInstructionT< spv::OpBranchConditional, false, false >;
	using SelectionMergeInstruction = InstructionT< spv::OpSelectionMerge, false, false, 2u, false, false >;
	using LoopMergeInstruction = InstructionT< spv::OpLoopMerge, false, false, 3u, false, false >;
	using ReturnInstruction = InstructionT< spv::OpReturn, false, false, 0u, false, false >;
	using ReturnValueInstruction = InstructionT< spv::OpReturnValue, false, false, 1u, false, false >;
	using UndefInstruction = InstructionT< spv::OpUndef, true, true, 0u, false, false >;
	using FunctionEndInstruction = InstructionT< spv::OpFunctionEnd, false, false, 0u, false, false >;
}

#include "SpirvInstruction.inl"

#endif
