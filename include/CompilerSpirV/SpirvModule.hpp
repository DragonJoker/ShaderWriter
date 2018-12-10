/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModule_H___
#define ___SDW_SpirvModule_H___
#pragma once

#include "spirv/spirv.hpp"

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

#include <ShaderAST/Type/TypeStruct.hpp>

#include <set>
#include <string>
#include <vector>
#include <unordered_map>

#if defined( __GNUG__ )
#	define SDW_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#	if SDW_COMPILER_VERSION < 40900
#		error "Unsupported version of GCC"
#	elif SDW_COMPILER_VERSION < 70100
#		include <experimental/optional>
namespace std
{
	using experimental::optional;
	using experimental::nullopt;
}
#	else
#		include <optional>
#	endif
#else
#	include <optional>
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

	struct IdListHasher
	{
		size_t operator()( IdList const & list )const;
	};

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
		Instruction( Config const & config
			, spv::Op op = spv::Op::OpNop
			, std::optional< spv::Id > returnTypeId = std::nullopt
			, std::optional< spv::Id > resultId = std::nullopt
			, IdList operands = IdList{}
			, std::optional< std::string > name = std::nullopt
			, std::optional< std::map< int32_t, spv::Id > > labels = std::nullopt );
		Instruction( Config const & config
			, Op op
			, UInt32ListCIt & buffer );
		static void serialize( UInt32List & buffer
			, Instruction const & instruction );
		static InstructionPtr deserialize( UInt32ListCIt & buffer );
		virtual ~Instruction();

		// Serialisable.
		Op op;
		std::optional< spv::Id > returnTypeId;
		std::optional< spv::Id > resultId;
		IdList operands;
		std::optional< UInt32List > packedName;
		// Used during construction.
		Config const & config;
		std::optional< std::string > name;
		std::optional< std::map< int32_t, spv::Id > > labels;
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

		inline InstructionT( std::optional< spv::Id > returnTypeId = std::nullopt
			, std::optional< spv::Id > resultId = std::nullopt
			, IdList operands = IdList{}
			, std::optional< std::string > name = std::nullopt
			, std::optional< std::map< int32_t, spv::Id > > labels = std::nullopt );
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

		inline VariadicInstructionT( std::optional< spv::Id > returnTypeId = std::nullopt
			, std::optional< spv::Id > resultId = std::nullopt
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

	using ExtensionInstruction = InstructionT< spv::Op::OpExtension, false, false, 0u, true, false >;
	using ExtInstImportInstruction = InstructionT< spv::Op::OpExtInstImport, false, true, 0u, true, false >;
	using SourceInstruction = InstructionT< spv::Op::OpSource, false, false, 2u, false, false >;
	using MemoryModelInstruction = InstructionT< spv::Op::OpMemoryModel, false, false, 2u, false, false >;
	using EntryPointInstruction = InstructionT< spv::Op::OpEntryPoint, true, true, dynamicOperandCount, true, false >;
	using ExecutionModeInstruction = VariadicInstructionT< spv::Op::OpExecutionMode, false, false >;
	using CapabilityInstruction = InstructionT< spv::Op::OpCapability, false, false, 1u, false, false >;
	using DecorateInstruction = VariadicInstructionT< spv::Op::OpDecorate, false, false >;
	using MemberDecorateInstruction = VariadicInstructionT< spv::Op::OpMemberDecorate, false, false >;
	using NameInstruction = InstructionT< spv::Op::OpName, false, true, 0u, true, false >;
	using MemberNameInstruction = InstructionT< spv::Op::OpMemberName, true, true, 0u, true, false >;

	using VoidTypeInstruction = InstructionT< spv::Op::OpTypeVoid, false, true, 0u, false, false >;
	using BooleanTypeInstruction = InstructionT< spv::Op::OpTypeBool, false, true, 0u, false, false >;
	using IntTypeInstruction = InstructionT< spv::Op::OpTypeInt, false, true, 2u, false, false >;
	using FloatTypeInstruction = InstructionT< spv::Op::OpTypeFloat, false, true, 1u, false, false >;
	using VectorTypeInstruction = InstructionT< spv::Op::OpTypeVector, false, true, 2u, false, false >;
	using MatrixTypeInstruction = InstructionT< spv::Op::OpTypeMatrix, false, true, 2u, false, false >;
	using SamplerTypeInstruction = InstructionT< spv::Op::OpTypeSampler, false, true, 0u, false, false >;
	using SampledImageTypeInstruction = InstructionT< spv::Op::OpTypeSampledImage, false, true, 1u, false, false >;
	using RuntimeArrayTypeInstruction = InstructionT< spv::Op::OpTypeRuntimeArray, false, true, 1u, false, false >;
	using ArrayTypeInstruction = InstructionT< spv::Op::OpTypeArray, false, true, 2u, false, false >;
	using PointerTypeInstruction = InstructionT< spv::Op::OpTypePointer, false, true, 2u, false, false >;
	using FunctionTypeInstruction = VariadicInstructionT< spv::Op::OpTypeFunction, false, true >;
	using ImageTypeInstruction = VariadicInstructionT< spv::Op::OpTypeImage, false, true >;
	using StructTypeInstruction = VariadicInstructionT< spv::Op::OpTypeStruct, false, true >;

	using ConstantInstruction = VariadicInstructionT< spv::Op::OpConstant, true, true >;
	using ConstantCompositeInstruction = VariadicInstructionT< spv::Op::OpConstantComposite, true, true >;
	using ConstantTrueInstruction = InstructionT< spv::Op::OpConstantTrue, true, true, 0u, false, false >;
	using ConstantFalseInstruction = InstructionT< spv::Op::OpConstantFalse, true, true, 0u, false, false >;
	using SpecConstantOpInstruction = VariadicInstructionT< spv::Op::OpSpecConstantOp, true, true >;
	using SpecConstantInstruction = VariadicInstructionT< spv::Op::OpSpecConstant, true, true >;
	using SpecConstantCompositeInstruction = VariadicInstructionT< spv::Op::OpSpecConstantComposite, true, true >;
	using SpecConstantTrueInstruction = InstructionT< spv::Op::OpSpecConstantTrue, true, true, 0u, false, false >;
	using SpecConstantFalseInstruction = InstructionT< spv::Op::OpSpecConstantFalse, true, true, 0u, false, false >;
	using SwitchInstruction = InstructionT< spv::Op::OpSwitch, false, false, 2u, false, true >;
	using SelectInstruction = InstructionT< spv::Op::OpSelect, true, true, 3u, false, false >;
	using LoadInstruction = InstructionT< spv::Op::OpLoad, true, true, 1u, false, false >;
	using StoreInstruction = InstructionT< spv::Op::OpStore, false, false, 2u, false, false >;
	using VariableInstruction = InstructionT< spv::Op::OpVariable, true, true, 1u, false, false >;
	using CompositeExtractInstruction = VariadicInstructionT< spv::Op::OpCompositeExtract, true, true >;
	using CompositeConstructInstruction = VariadicInstructionT< spv::Op::OpCompositeConstruct, true, true >;
	using VectorShuffleInstruction = VariadicInstructionT< spv::Op::OpVectorShuffle, true, true >;
	using AccessChainInstruction = VariadicInstructionT< spv::Op::OpAccessChain, true, true >;
	using FunctionCallInstruction = VariadicInstructionT< spv::Op::OpFunctionCall, true, true >;
	using ImageTexelPointerInstruction = VariadicInstructionT< spv::Op::OpImageTexelPointer, true, true >;
	using ImageInstruction = InstructionT< spv::Op::OpImage, true, true, 1u, false, false >;
	using ExtInstInstruction = VariadicInstructionT< spv::Op::OpExtInst, true, true >;
	using FunctionParameterInstruction = InstructionT< spv::Op::OpFunctionParameter, true, true, 0u, false, false >;
	using LabelInstruction = InstructionT< spv::Op::OpLabel, false, true, 0u, false, false >;
	using FunctionInstruction = InstructionT< spv::Op::OpFunction, true, true, 2u, false, false >;

	using KillInstruction = InstructionT< spv::Op::OpKill, false, false, 0u, false, false >;
	using BranchInstruction = InstructionT< spv::Op::OpBranch, false, false, 1u, false, false >;
	using BranchConditionalInstruction = VariadicInstructionT< spv::Op::OpBranchConditional, false, false >;
	using SelectionMergeInstruction = InstructionT< spv::Op::OpSelectionMerge, false, false, 2u, false, false >;
	using LoopMergeInstruction = InstructionT< spv::Op::OpLoopMerge, false, false, 3u, false, false >;
	using ReturnInstruction = InstructionT< spv::Op::OpReturn, false, false, 0u, false, false >;
	using ReturnValueInstruction = InstructionT< spv::Op::OpReturnValue, false, false, 1u, false, false >;
	using FunctionEndInstruction = InstructionT< spv::Op::OpFunctionEnd, false, false, 0u, false, false >;

	struct VariableInfo
	{
		spv::Id id{ 0u };
		bool lvalue{ false };
		bool rvalue{ false };
	};

	struct Block
	{
		static Block deserialize( InstructionPtr firstInstruction
			, InstructionListIt & buffer
			, InstructionListIt & end );

		spv::Id label;
		InstructionList instructions;
		InstructionPtr blockEnd;
		std::unordered_map< IdList, spv::Id, IdListHasher > accessChains;
		std::unordered_map< IdList, spv::Id, IdListHasher > vectorShuffles;
	};

	using BlockList = std::vector< Block >;

	struct ControlFlowGraph
	{
		BlockList blocks;
	};

	struct Parameter
	{
		spv::Id id;
		spv::Id type;
	};
	using ParameterList = std::vector< Parameter >;

	struct Function
	{
		// Serialisable.
		InstructionList declaration;
		ControlFlowGraph cfg;
		// Used during construction.
		InstructionList variables;
		bool hasReturn{ false };

		static Function deserialize( InstructionListIt & buffer
			, InstructionListIt & end );
	};
	using FunctionList = std::vector< Function >;

	struct Header
	{
		uint32_t magic;
		uint32_t version;
		uint32_t builder;
		uint32_t boundIds;
		uint32_t schema;
	};

	class Module
	{
	public:
		Module( ast::type::TypesCache & cache
			, spv::MemoryModel memoryModel
			, spv::ExecutionModel executionModel );
		Module( Header const & header
			, InstructionList && instructions );

		static Module deserialize( UInt32List const & spirv );

		spv::Id registerType( ast::type::TypePtr type );
		spv::Id registerPointerType( spv::Id type
			, spv::StorageClass storage );
		void decorate( spv::Id id
			, spv::Decoration decoration );
		void decorate( spv::Id id
			, IdList const & decoration );
		void decorateMember( spv::Id id
			, uint32_t index
			, spv::Decoration decoration );
		void decorateMember( spv::Id id
			, uint32_t index
			, IdList const & decoration );
		VariableInfo & registerVariable( std::string const & name
			, spv::StorageClass storage
			, ast::type::TypePtr type
			, VariableInfo & info );
		spv::Id registerSpecConstant( std::string name
			, uint32_t location
			, ast::type::TypePtr type
			, ast::expr::Literal const & value );
		spv::Id registerParameter( ast::type::TypePtr type );
		spv::Id registerMemberVariableIndex( ast::type::TypePtr type );
		spv::Id registerMemberVariable( spv::Id outer
			, std::string name
			, ast::type::TypePtr type );
		spv::Id registerLiteral( bool value );
		spv::Id registerLiteral( int32_t value );
		spv::Id registerLiteral( uint32_t value );
		spv::Id registerLiteral( float value );
		spv::Id registerLiteral( double value );
		spv::Id registerLiteral( IdList const & initialisers
			, ast::type::TypePtr type );
		void registerExtension( std::string const & name );
		void registerEntryPoint( spv::Id functionId
			, std::string const & name
			, IdList const & inputs
			, IdList const & outputs );
		void registerExecutionMode( spv::ExecutionMode mode );
		void registerExecutionMode( spv::ExecutionMode mode
			, IdList const & operands );
		spv::Id getIntermediateResult();
		void lnkIntermediateResult( spv::Id intermediate, spv::Id var );
		void putIntermediateResult( spv::Id id );
		spv::Id getNonIntermediate( spv::Id id );

		ast::type::Kind getLiteralType( spv::Id litId )const;
		spv::Id getOuterVariable( spv::Id mbrId )const;
		spv::Id loadVariable( spv::Id variable
			, ast::type::TypePtr type
			, Block & currentBlock );
		void bindVariable( spv::Id varId
			, uint32_t bindingPoint
			, uint32_t descriptorSet );
		void bindBufferVariable( std::string const & name
			, uint32_t bindingPoint
			, uint32_t descriptorSet
			, spv::Decoration structDecoration );// BufferBlock for SSBO, Block for UBO

		Function * beginFunction( std::string const & name
			, spv::Id retType
			, ast::var::VariableList const & params );
		Block newBlock();
		void endFunction();

		inline ast::type::TypesCache & getCache()
		{
			return *m_cache;
		}

	public:
		IdList header;
		InstructionList capabilities;
		InstructionList extensions;
		InstructionList imports;
		InstructionPtr memoryModel;
		InstructionPtr entryPoint;
		InstructionList executionModes;
		InstructionList debug;
		InstructionList decorations;
		InstructionList globalDeclarations;
		FunctionList functions;
		InstructionList * variables;

	private:
		spv::Id doRegisterNonArrayType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, spv::Id parentId
			, uint32_t arrayStride );
		spv::Id registerBaseType( ast::type::Kind kind
			, uint32_t mbrIndex
			, spv::Id parentId
			, uint32_t arrayStride );
		spv::Id registerBaseType( ast::type::StructPtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( ast::type::SampledImagePtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( ast::type::ImagePtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, spv::Id parentId
			, uint32_t arrayStride );

	private:
		spv::Id getNextId();

	private:
		ast::type::TypesCache * m_cache;
		spv::Id * m_currentId;
		Function * m_currentFunction{ nullptr };
		std::map< ast::type::TypePtr, spv::Id > m_registeredTypes;
		std::map< ast::type::TypePtr, spv::Id > m_registeredMemberTypes;
		std::map< std::string, spv::Id > m_registeredVariables;
		std::map< spv::Id, spv::Id > m_registeredVariablesTypes;
		std::map< std::string, std::pair< spv::Id, spv::Id > > m_registeredMemberVariables;
		std::map< uint64_t, spv::Id > m_registeredPointerTypes;
		std::map< bool, spv::Id > m_registeredBoolConstants;
		std::map< int32_t, spv::Id > m_registeredIntConstants;
		std::map< uint32_t, spv::Id > m_registeredUIntConstants;
		std::map< float, spv::Id> m_registeredFloatConstants;
		std::map< double, spv::Id > m_registeredDoubleConstants;
		std::vector< std::pair< IdList, spv::Id > > m_registeredCompositeConstants;
		std::map< spv::Id, ast::type::TypePtr > m_registeredConstants;
		std::set< spv::Id > m_intermediates;
		std::set< spv::Id > m_freeIntermediates;
		std::map< spv::Id, spv::Id > m_busyIntermediates;
		spv::ExecutionModel m_model;
		InstructionList m_pendingExecutionModes;
	};
}

#include "SpirvModule.inl"

#endif
