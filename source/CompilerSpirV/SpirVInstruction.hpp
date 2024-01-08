/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvInstruction_H___
#define ___SDW_SpirvInstruction_H___
#pragma once

#include "spirv/spirv.hpp"
#include "compileSpirV.hpp"

#include <ShaderAST/ShaderStlTypes.hpp>
#include <ShaderAST/Type/TypePointer.hpp>
#include <ShaderAST/Type/TypeStruct.hpp>

#include <compare>
#include <map>
#include <set>
#include <string>
#include <variant>
#include <vector>

#pragma warning( push )
#pragma warning( disable: 4201 )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <iomanip>

#if defined( CompilerSpirV_Static )
#	define SDWSPIRV_API
#elif defined( _WIN32 )
#	if defined( CompilerSpirV_Exports )
#		define SDWSPIRV_API __declspec( dllexport )
#	else
#		define SDWSPIRV_API __declspec( dllimport )
#	endif
#else
#	define SDWSPIRV_API
#endif

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
	struct Op
	{
		struct OpData
		{
			uint16_t opCode;
			uint16_t opCount;
		};

		void setOpData( spv::Op code, uint16_t count )noexcept
		{
			*reinterpret_cast< OpData * >( &value ) = { uint16_t( code ), count };
		}

		void setOpDataCount( uint16_t count )noexcept
		{
			reinterpret_cast< OpData * >( &value )->opCount = count;
		}

		void setOp( spv::Op v )noexcept
		{
			value = uint32_t( v );
		}

		void setOpValue( uint32_t v )noexcept
		{
			value = v;
		}

		OpData const & getOpData()const noexcept
		{
			return *reinterpret_cast< OpData const * >( &value );
		}

		uint32_t const & getOpValue()const noexcept
		{
			return value;
		}

		spv::Op getOp()const noexcept
		{
			return *reinterpret_cast< spv::Op const * >( &value );
		}

	private:
		uint32_t value;
	};

	using IdList = ast::Vector< spv::Id >;
	using UInt32List = ast::Vector< uint32_t >;
	using UInt32ListIt = UInt32List::iterator;
	using UInt32ListCIt = UInt32List::const_iterator;
	using NamesCache = ast::Map< std::string, UInt32List >;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnull-dereference"
	struct ValueId
	{
		spv::Id id{};
		ast::type::TypePtr type{};

		explicit ValueId( spv::Id pid = {}
			, ast::type::TypePtr ptype = {} )
			: id{ pid }
			, type{ std::move( ptype ) }
		{
		}

		bool isPointer()const
		{
			return type
				&& type->getKind() == ast::type::Kind::ePointer;
		}

		ast::type::Storage getStorage()const
		{
			return ( isPointer()
				? static_cast< ast::type::Pointer const & >( *type ).getStorage()
				: ast::type::Storage::eMax );
		}

		explicit operator bool()const
		{
			return id != 0u;
		}
	};
#pragma GCC diagnostic pop

	inline bool operator==( ValueId const & lhs, ValueId const & rhs )
	{
		return lhs.id == rhs.id;
	}
	
	inline std::strong_ordering operator<=>( ValueId const & lhs, ValueId const & rhs )
	{
		return lhs.id <=> rhs.id;
	}

	using ValueIdList = ast::Vector< ValueId >;
	using ValueIdSet = ast::Set< ValueId >;

	struct ValueIdHasher
	{
		SDWSPIRV_API size_t operator()( ValueId const & value )const noexcept;
	};

	struct ValueIdListHasher
	{
		SDWSPIRV_API size_t operator()( ValueIdList const & value )const noexcept;
	};

	struct IdListHasher
	{
		SDWSPIRV_API size_t operator()( IdList const & value )const noexcept;
	};

	struct DebugId
	{
		ValueId id;
		ValueId debug;

		explicit DebugId( spv::Id pid = 0u, ast::type::TypePtr type = nullptr )
			: id{ pid, type }
			, debug{ 0u, type }
		{
		}

		explicit DebugId( ValueId pid )
			: DebugId{ pid.id, pid.type }
		{
		}

		bool isPointer()const
		{
			return id.type
				&& id.type->getKind() == ast::type::Kind::ePointer;
		}

		ast::type::Storage getStorage()const
		{
			return ( isPointer()
				? static_cast< ast::type::Pointer const & >( *id.type ).getStorage()
				: ast::type::Storage::eMax );
		}

		explicit operator bool()const
		{
			return id.id != 0u;
		}

		ValueId const * operator->()const
		{
			return &id;
		}
	};

	inline bool operator==( DebugId const & lhs, DebugId const & rhs )
	{
		return lhs.id == rhs.id;
	}

	inline std::strong_ordering operator<=>( DebugId const & lhs, DebugId const & rhs )
	{
		return lhs.id <=> rhs.id;
	}

	using DebugIdList = ast::Vector< DebugId >;

	struct DebugIdHasher
	{
		SDWSPIRV_API size_t operator()( DebugId const & value )const noexcept;
	};

	struct DebugIdListHasher
	{
		SDWSPIRV_API size_t operator()( DebugIdList const & value )const noexcept;
	};

	using TypeId = DebugId;
	using TypeIdHasher = DebugIdHasher;
	using TypeIdListHasher = DebugIdListHasher;
	using TypeIdList = DebugIdList;

	SDWSPIRV_API IdList convert( ValueIdList const & in );
	SDWSPIRV_API ValueIdList convert( IdList const & in );
	SDWSPIRV_API ValueIdList convert( DebugIdList const & in );
	SDWSPIRV_API DebugIdList toTypeId( ValueIdList const & in );
	SDWSPIRV_API ast::type::Storage convert( spv::StorageClass in );
	SDWSPIRV_API spv::StorageClass convert( ast::type::Storage in );

	static uint32_t constexpr dynamicOperandCount = ~0u;

	struct Instruction;
	using InstructionPtr = std::unique_ptr< Instruction >;

	template< typename IterT >
	struct BufferItT
	{
		IterT it;
		uint32_t index;

		BufferItT & operator++()
		{
			++it;
			++index;
		}

		uint32_t popValue()
		{
			auto result = *it;
			++it;
			++index;
			return result;
		}
		
		InstructionPtr popInstruction( ast::ShaderAllocatorBlock * alloc );
	};
	using BufferCIt = BufferItT< std::vector< uint32_t >::const_iterator >;
	using BufferIt = BufferItT< std::vector< uint32_t >::iterator >;

	struct Instruction
	{
		struct Configuration
		{
			spv::Op op;
			bool hasReturnTypeId;
			bool hasResultId;
			uint32_t operandsCount;
			bool hasName;
			bool hasLabels;
		};
		SDWSPIRV_API explicit Instruction( ast::Map< std::string, ast::Vector< uint32_t > > & nameCache
			, Configuration const & config
			, spv::Op op
			, Optional< ValueId > returnTypeId
			, Optional< ValueId > resultId
			, IdList operands
			, Optional< std::string > name = nullopt
			, Optional< ast::Map< int32_t, spv::Id > > labels = nullopt );
		SDWSPIRV_API explicit Instruction( ast::Map< std::string, ast::Vector< uint32_t > > & nameCache
			, Configuration const & config
			, spv::Op op
			, Optional< ValueId > returnTypeId
			, Optional< ValueId > resultId
			, ValueIdList const & operands
			, Optional< std::string > name = nullopt
			, Optional< ast::Map< int32_t, spv::Id > > labels = nullopt );
		SDWSPIRV_API explicit Instruction( ast::Map< std::string, ast::Vector< uint32_t > > & nameCache
			, Configuration const & config
			, spv::Op op = spv::OpNop
			, Optional< ValueId > returnTypeId = nullopt
			, Optional< ValueId > resultId = nullopt );
		SDWSPIRV_API Instruction( ast::ShaderAllocatorBlock * alloc
			, Configuration const & config
			, Op op
			, BufferIt & buffer );
		SDWSPIRV_API Instruction( ast::ShaderAllocatorBlock * alloc
			, Configuration const & config
			, Op op
			, BufferCIt & buffer );
		SDWSPIRV_API Instruction( ast::ShaderAllocatorBlock * alloc
			, Configuration const & config
			, spv::Op op
			, BufferIt & buffer );
		SDWSPIRV_API Instruction( ast::ShaderAllocatorBlock * alloc
			, Configuration const & config
			, spv::Op op
			, BufferCIt & buffer );
		SDWSPIRV_API static void serialize( UInt32List & buffer
			, Instruction const & instruction );
		SDWSPIRV_API static InstructionPtr deserialize( ast::ShaderAllocatorBlock * alloc
			, BufferCIt & buffer );
		SDWSPIRV_API static InstructionPtr deserialize( ast::ShaderAllocatorBlock * alloc
			, BufferIt & buffer );
		SDWSPIRV_API virtual ~Instruction() = default;

		// Serialisable.
		Op op;
		Optional< spv::Id > returnTypeId;
		Optional< spv::Id > resultId;
		IdList operands;
		Optional< UInt32List > packedName{ std::nullopt };
		// Used during construction.
		Configuration const & config;
		Optional< std::string > name;
		Optional< ast::Map< int32_t, spv::Id > > labels;
	};

	using InstructionPtr = std::unique_ptr< Instruction >;
	using InstructionList = ast::Vector< InstructionPtr >;

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	Instruction::Configuration makeConfig()
	{
		return Instruction::Configuration
		{
			OperatorT,
			HasReturnTypeIdT,
			HasResultIdT,
			OperandsCountT,
			HasNameT,
			HasLabelsT,
		};
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	struct InstructionT
		: public Instruction
	{
		static spv::Op constexpr Op = OperatorT;
		static bool constexpr HasReturnTypeId = HasReturnTypeIdT;
		static bool constexpr HasResultId = HasResultIdT;
		static uint32_t constexpr OperandsCount = OperandsCountT;
		static bool constexpr HasName = HasNameT;
		static bool constexpr HasLabels = HasLabelsT;
		static Configuration const Config;

		explicit InstructionT( NamesCache & nameCache
			, Optional< ValueId > preturnTypeId
			, Optional< ValueId > presultId
			, ValueIdList poperands
			, Optional< std::string > pname = nullopt
			, Optional< ast::Map< int32_t, spv::Id > > plabels = nullopt );
		explicit InstructionT( NamesCache & nameCache
			, Optional< ValueId > preturnTypeId = nullopt
			, Optional< ValueId > presultId = nullopt );
		explicit InstructionT( ast::ShaderAllocatorBlock * alloc
			, BufferIt & buffer );
		explicit InstructionT( ast::ShaderAllocatorBlock * alloc
			, BufferCIt & buffer );
	};

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	Instruction::Configuration const InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::Config = makeConfig< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >();

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	struct VariadicInstructionT
		: public InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false >
	{
		explicit VariadicInstructionT( NamesCache & nameCache
			, Optional< ValueId > preturnTypeId
			, Optional< ValueId > presultId
			, ValueIdList poperands );
		explicit VariadicInstructionT( NamesCache & nameCache
			, Optional< ValueId > preturnTypeId = nullopt
			, Optional< ValueId > presultId = nullopt );
		explicit VariadicInstructionT( ast::ShaderAllocatorBlock * alloc
			, BufferIt & buffer );
		explicit VariadicInstructionT( ast::ShaderAllocatorBlock * alloc
			, BufferCIt & buffer );
	};

	template< spv::Op OperatorT >
	using UnInstructionT = InstructionT< OperatorT, true, true, 1u, false, false >;

	template< spv::Op OperatorT >
	using BinInstructionT = InstructionT< OperatorT, true, true, 2u, false, false >;

	template< spv::Op OperatorT >
	using ImageAccessInstructionT = VariadicInstructionT< OperatorT, true, true >;

	template< spv::Op OperatorT >
	using SampledImageAccessInstructionT = VariadicInstructionT< OperatorT, true, true >;

	template< spv::Op OperatorT >
	using TextureAccessInstructionT = VariadicInstructionT< OperatorT, true, true >;

	template< spv::Op OperatorT >
	using IntrinsicInstructionT = VariadicInstructionT< OperatorT, true, true >;

	template< spv::Op OperatorT >
	using VoidIntrinsicInstructionT = VariadicInstructionT< OperatorT, false, false >;

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	using InstructionTPtr = std::unique_ptr< InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT > >;

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	struct InstructionTMaker;

	template< typename InstructionType, typename ... Params >
	inline std::unique_ptr< InstructionType > makeInstruction( NamesCache & nameCache
		, Params && ... params );

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline void assertType( Instruction const & instruction );
	inline void assertType( Instruction const & instruction
		, Instruction::Configuration const & config );
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
	using SourceExtensionInstruction = InstructionT< spv::OpSourceExtension, false, false, 0u, true, false >;
	using MemoryModelInstruction = InstructionT< spv::OpMemoryModel, false, false, 2u, false, false >;
	using EntryPointInstruction = InstructionT< spv::OpEntryPoint, true, true, dynamicOperandCount, true, false >;
	using ExecutionModeInstruction = VariadicInstructionT< spv::OpExecutionMode, false, false >;
	using CapabilityInstruction = InstructionT< spv::OpCapability, false, false, 1u, false, false >;
	using DecorateInstruction = VariadicInstructionT< spv::OpDecorate, false, false >;
	using MemberDecorateInstruction = VariadicInstructionT< spv::OpMemberDecorate, false, false >;
	using NameInstruction = InstructionT< spv::OpName, false, true, 0u, true, false >;
	using StringInstruction = InstructionT< spv::OpString, false, true, 0u, true, false >;
	using MemberNameInstruction = InstructionT< spv::OpMemberName, true, true, 0u, true, false >;

	using VoidTypeInstruction = InstructionT< spv::OpTypeVoid, false, true, 0u, false, false >;
	using BooleanTypeInstruction = InstructionT< spv::OpTypeBool, false, true, 0u, false, false >;
	using IntTypeInstruction = InstructionT< spv::OpTypeInt, false, true, 2u, false, false >;
	using FloatTypeInstruction = InstructionT< spv::OpTypeFloat, false, true, 1u, false, false >;
	using VectorTypeInstruction = InstructionT< spv::OpTypeVector, false, true, 2u, false, false >;
	using MatrixTypeInstruction = InstructionT< spv::OpTypeMatrix, false, true, 2u, false, false >;
	using SamplerTypeInstruction = InstructionT< spv::OpTypeSampler, false, true, 0u, false, false >;
	using TextureTypeInstruction = InstructionT< spv::OpTypeSampledImage, false, true, 1u, false, false >;
	using RuntimeArrayTypeInstruction = InstructionT< spv::OpTypeRuntimeArray, false, true, 1u, false, false >;
	using ArrayTypeInstruction = InstructionT< spv::OpTypeArray, false, true, 2u, false, false >;
	using ForwardPointerTypeInstruction = InstructionT< spv::OpTypeForwardPointer, false, true, 1u, false, false >;
	using PointerTypeInstruction = InstructionT< spv::OpTypePointer, false, true, 2u, false, false >;
	using AccelerationStructureTypeInstruction = InstructionT< spv::OpTypeAccelerationStructureKHR, false, true, 0u, false, false >;
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
	using LoadInstruction = VariadicInstructionT< spv::OpLoad, true, true >;
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
	using SampledImageInstruction = InstructionT< spv::OpSampledImage, true, true, 2u, false, false >;
	using ExtInstInstruction = VariadicInstructionT< spv::OpExtInst, true, true >;
	using FunctionParameterInstruction = InstructionT< spv::OpFunctionParameter, true, true, 0u, false, false >;
	using LabelInstruction = InstructionT< spv::OpLabel, false, true, 0u, false, false >;
	using FunctionInstruction = InstructionT< spv::OpFunction, true, true, 2u, false, false >;
	using CopyObjectInstruction = InstructionT< spv::OpCopyObject, true, true, 1u, false, false >;
	using GroupNonUniformElectInstruction = InstructionT< spv::OpGroupNonUniformElect, true, true, 1u, false, false >;
	using GroupNonUniformAllInstruction = InstructionT< spv::OpGroupNonUniformAll, true, true, 2u, false, false >;
	using GroupNonUniformAnyInstruction = InstructionT< spv::OpGroupNonUniformAny, true, true, 2u, false, false >;
	using GroupNonUniformAllEqualInstruction = InstructionT< spv::OpGroupNonUniformAllEqual, true, true, 2u, false, false >;
	using GroupNonUniformBroadcastInstruction = InstructionT< spv::OpGroupNonUniformBroadcast, true, true, 3u, false, false >;
	using GroupNonUniformBroadcastFirstInstruction = InstructionT< spv::OpGroupNonUniformBroadcastFirst, true, true, 2u, false, false >;
	using GroupNonUniformBallotInstruction = InstructionT< spv::OpGroupNonUniformBallot, true, true, 2u, false, false >;
	using GroupNonUniformInverseBallotInstruction = InstructionT< spv::OpGroupNonUniformInverseBallot, true, true, 2u, false, false >;
	using GroupNonUniformBallotBitExtractInstruction = InstructionT< spv::OpGroupNonUniformBallotBitExtract, true, true, 3u, false, false >;
	using GroupNonUniformBallotBitCountInstruction = InstructionT< spv::OpGroupNonUniformBallotBitCount, true, true, 3u, false, false >;
	using GroupNonUniformBallotFindLSBInstruction = InstructionT< spv::OpGroupNonUniformBallotFindLSB, true, true, 2u, false, false >;
	using GroupNonUniformBallotFindMSBInstruction = InstructionT< spv::OpGroupNonUniformBallotFindMSB, true, true, 2u, false, false >;
	using GroupNonUniformShuffleInstruction = InstructionT< spv::OpGroupNonUniformShuffle, true, true, 3u, false, false >;
	using GroupNonUniformShuffleXorInstruction = InstructionT< spv::OpGroupNonUniformShuffleXor, true, true, 3u, false, false >;
	using GroupNonUniformShuffleUpInstruction = InstructionT< spv::OpGroupNonUniformShuffleUp, true, true, 3u, false, false >;
	using GroupNonUniformShuffleDownInstruction = InstructionT< spv::OpGroupNonUniformShuffleDown, true, true, 3u, false, false >;
	using GroupNonUniformQuadBroadcastInstruction = InstructionT< spv::OpGroupNonUniformQuadBroadcast, true, true, 3u, false, false >;
	using GroupNonUniformQuadSwapInstruction = InstructionT< spv::OpGroupNonUniformQuadSwap, true, true, 3u, false, false >;
	using WritePackedPrimitiveIndices4x8Instruction = InstructionT< spv::OpWritePackedPrimitiveIndices4x8NV, false, false, 2u, false, false >;
	using EmitMeshTasksInstruction = VariadicInstructionT< spv::OpEmitMeshTasksEXT, false, false >;
	using SetMeshOutputsInstruction = InstructionT< spv::OpSetMeshOutputsEXT, false, false, 2u, false, false >;

	using DemoteInstruction = InstructionT< spv::OpDemoteToHelperInvocation, false, false, 0u, false, false >;
	using KillInstruction = InstructionT< spv::OpKill, false, false, 0u, false, false >;
	using TerminateInvocationInstruction = InstructionT< spv::OpTerminateInvocation, false, false, 0u, false, false >;
	using BranchInstruction = InstructionT< spv::OpBranch, false, false, 1u, false, false >;
	using BranchConditionalInstruction = VariadicInstructionT< spv::OpBranchConditional, false, false >;
	using SelectionMergeInstruction = InstructionT< spv::OpSelectionMerge, false, false, 2u, false, false >;
	using LoopMergeInstruction = InstructionT< spv::OpLoopMerge, false, false, 3u, false, false >;
	using ReturnInstruction = InstructionT< spv::OpReturn, false, false, 0u, false, false >;
	using ReturnValueInstruction = InstructionT< spv::OpReturnValue, false, false, 1u, false, false >;
	using UndefInstruction = InstructionT< spv::OpUndef, true, true, 0u, false, false >;
	using FunctionEndInstruction = InstructionT< spv::OpFunctionEnd, false, false, 0u, false, false >;
	using IgnoreIntersectionInstruction = InstructionT< spv::OpIgnoreIntersectionKHR, false, false, 0u, false, false >;
	using TerminateRayInstruction = InstructionT< spv::OpTerminateRayKHR, false, false, 0u, false, false >;
}

#include "SpirVInstruction.inl"
#pragma warning( pop )

#endif
