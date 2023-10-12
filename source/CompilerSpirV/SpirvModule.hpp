/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModule_H___
#define ___SDW_SpirvModule_H___
#pragma once

#include "CompilerSpirV/SpirVDebugNames.hpp"
#include "CompilerSpirV/SpirvFunction.hpp"
#include "CompilerSpirV/SpirvModuleLiterals.hpp"
#include "CompilerSpirV/SpirvModuleTypes.hpp"
#include "CompilerSpirV/SpirVNonSemanticDebug.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

#include <set>
#include <unordered_set>

namespace spirv
{
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
	private:
		Module( ast::ShaderAllocatorBlock * alloc
			, glsl::StmtConfig const * stmtConfig
			, ast::type::TypesCache * typesCache );

	public:
		SDWSPIRV_API Module( ast::ShaderAllocatorBlock * alloc
			, ast::type::TypesCache & typesCache
			, SpirVConfig const & spirvConfig
			, glsl::StmtConfig const & stmtConfig
			, spv::AddressingModel addressingModel
			, spv::MemoryModel memoryModel
			, spv::ExecutionModel executionModel
			, glsl::Statements const & debugStatements );
		SDWSPIRV_API Module( ast::ShaderAllocatorBlock * alloc
			, Header const & header
			, InstructionList instructions );

		uint32_t getVersion()const
		{
			return m_version;
		}

		SDWSPIRV_API static Module deserialize( ast::ShaderAllocatorBlock * allocator
			, std::vector< uint32_t > const & spirv );
		SDWSPIRV_API static Vector< uint32_t > serialize( spirv::Module const & module );
		SDWSPIRV_API static std::string write( spirv::Module const & module
			, bool writeHeader );

		SDWSPIRV_API TypeId registerType( ast::type::TypePtr type
			, glsl::Statement const * debugStatement );
		SDWSPIRV_API TypeId registerImageType( ast::type::ImagePtr image
			, bool isComparison );
		SDWSPIRV_API TypeId registerPointerType( TypeId type
			, spv::StorageClass storage
			, bool isForward = false );
		SDWSPIRV_API DebugId mergeSamplerImage( DebugId const & image
			, DebugId const & sampler
			, Block & currentBlock );
		SDWSPIRV_API void decorate( DebugId id
			, spv::Decoration decoration );
		SDWSPIRV_API void decorate( DebugId id
			, IdList const & decoration );
		SDWSPIRV_API void decorateMember( DebugId id
			, uint32_t index
			, spv::Decoration decoration );
		SDWSPIRV_API void decorateMember( DebugId id
			, uint32_t index
			, IdList const & decoration );
		SDWSPIRV_API VariableInfo registerParam( std::string name
			, bool isOutput
			, ast::type::TypePtr type );
		SDWSPIRV_API VariableInfo registerAlias( std::string name
			, ast::type::TypePtr type
			, DebugId exprResultId );
		SDWSPIRV_API VariableInfo registerVariable( Block & block
			, std::string name
			, ast::Builtin builtin
			, spv::StorageClass storage
			, bool isAlias
			, bool isParam
			, bool isOutParam
			, ast::type::TypePtr type
			, VariableInfo & sourceInfo
			, DebugId initialiser = DebugId{}
			, glsl::Statement const * debugStatement = {} );
		SDWSPIRV_API DebugId registerSpecConstant( std::string name
			, uint32_t location
			, ast::type::TypePtr type
			, ast::expr::Literal const & value );
		SDWSPIRV_API ValueId registerParameter( ast::type::TypePtr type );
		SDWSPIRV_API DebugId registerMemberVariableIndex( ast::type::TypePtr type );
		SDWSPIRV_API DebugId registerMemberVariable( DebugId outer
			, std::string name
			, ast::type::TypePtr type );
		SDWSPIRV_API void registerExtension( std::string name );
		SDWSPIRV_API void registerEntryPoint( DebugId functionId
			, std::string name
			, ValueIdList const & inputs
			, ValueIdList const & outputs );
		SDWSPIRV_API void registerExecutionMode( spv::ExecutionMode mode );
		SDWSPIRV_API void registerExecutionMode( spv::ExecutionMode mode
			, ValueIdList const & operands );
		SDWSPIRV_API void registerExecutionMode( ast::type::InputLayout layout );
		SDWSPIRV_API void registerExecutionMode( ast::type::OutputLayout layout
			, uint32_t primCount );
		SDWSPIRV_API void registerExecutionMode( ast::type::PatchDomain domain
			, ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering order
			, uint32_t outputVertices );
		SDWSPIRV_API void registerExecutionMode( ast::type::PatchDomain domain
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering order );
		SDWSPIRV_API void registerExecutionModeNV( ast::type::OutputTopology topology
			, uint32_t maxVertices
			, uint32_t maxPrimitives );
		SDWSPIRV_API void registerExecutionMode( ast::type::OutputTopology topology
			, uint32_t maxVertices
			, uint32_t maxPrimitives );
		ValueId registerString( std::string const & text );
		SDWSPIRV_API spv::Id getIntermediateResult();
		SDWSPIRV_API void lnkIntermediateResult( DebugId intermediate, DebugId var );
		SDWSPIRV_API void putIntermediateResult( ValueId id );
		SDWSPIRV_API ValueId getNonIntermediate( ValueId id );

		SDWSPIRV_API DebugId getVariablePointer( Block & block
			, DebugId varId
			, std::string name
			, spv::StorageClass storage
			, Block & currentBlock
			, glsl::Statement const * statement );
		SDWSPIRV_API DebugId getVariablePointer( Block & block
			, std::string name
			, spv::StorageClass storage
			, ast::type::TypePtr type
			, Block & currentBlock
			, glsl::Statement const * statement );
		SDWSPIRV_API void storePromoted( DebugId variable
			, VariableInfo const & sourceInfo
			, Block & currentBlock
			, glsl::Statement const * debugStatement );
		SDWSPIRV_API void storeVariable( DebugId variable
			, DebugId value
			, InstructionList & instructions
			, glsl::Statement const * debugStatement );
		SDWSPIRV_API void storeVariable( DebugId variable
			, DebugId value
			, Block & currentBlock
			, glsl::Statement const * debugStatement );
		SDWSPIRV_API DebugId loadVariable( DebugId variable
			, InstructionList & instructions
			, glsl::Statement const * debugStatement );
		SDWSPIRV_API DebugId loadVariable( DebugId variable
			, Block & currentBlock
			, glsl::Statement const * debugStatement );
		SDWSPIRV_API void bindVariable( DebugId varId
			, uint32_t bindingPoint
			, uint32_t descriptorSet );
		SDWSPIRV_API void bindBufferVariable( DebugId variableId
			, uint32_t bindingPoint
			, uint32_t descriptorSet
			, spv::Decoration structDecoration );// BufferBlock for SSBO, Block for UBO
		SDWSPIRV_API DebugId bindBufferVariable( std::string const & name
			, uint32_t bindingPoint
			, uint32_t descriptorSet
			, spv::Decoration structDecoration );// BufferBlock for SSBO, Block for UBO

		SDWSPIRV_API Function * beginFunction( std::string name
			, TypeId retType
			, ast::var::VariableList const & params
			, glsl::Statement const * declDebugStatement
			, glsl::Statement const * scopeBeginDebugStatement
			, glsl::Statement const * firstLineStatement );
		SDWSPIRV_API Block newBlock();
		SDWSPIRV_API void endFunction();

		SDWSPIRV_API spv::Id getNextId();

		SDWSPIRV_API bool isExtGlslStd450( spv::Id id )const;
		SDWSPIRV_API bool isExtNonSemanticDebugInfo( spv::Id id )const;
		SDWSPIRV_API InstructionList const & getDebugStringsDeclarations()const noexcept;
		SDWSPIRV_API InstructionList const & getDebugNamesDeclarations()const noexcept;
		SDWSPIRV_API InstructionList const & getNonSemanticDebugDeclarations()const noexcept;
		SDWSPIRV_API Map< std::string, Vector< uint32_t > > & getNameCache()noexcept;
		SDWSPIRV_API ast::type::TypesCache & getTypesCache()const noexcept;
		SDWSPIRV_API void declareDebugAccessChain( InstructionList & instructions
			, ast::expr::Expr * expr
			, ValueIdList accessChainIds
			, glsl::Statement const * debugStatement
			, DebugId & resultId );
		SDWSPIRV_API ast::type::Kind getLiteralType( DebugId litId )const;

		template< typename ... ParamsT >
		DebugId registerLiteral( ParamsT && ... params )
		{
			return m_literals.registerLiteral( std::forward< ParamsT >( params )... );
		}

		debug::DebugNames & getDebugNames()noexcept
		{
			return m_debugNames;
		}

		debug::NonSemanticDebug & getNonSemanticDebug()noexcept
		{
			return m_nonSemanticDebug;
		}

		ModuleTypes & getTypes()noexcept
		{
			return m_types;
		}

		spv::ExecutionModel getExecutionModel()const noexcept
		{
			return m_model;
		}

	public:
		static uint32_t constexpr VendorID = 33u;
		static uint32_t constexpr Version = 0x0027u;

		ast::ShaderAllocatorBlock * allocator;
		ValueId extGlslStd450{};

		IdList header;
		InstructionList capabilities;
		InstructionList extensions;
		InstructionList imports;
		InstructionPtr memoryModel;
		InstructionPtr entryPoint;
		InstructionList executionModes;
		InstructionList decorations;
		InstructionList constantsTypes;
		InstructionList globalDeclarations;
		ModuleStruct structData;
		FunctionList functions;
		InstructionList * variables;

	private:
		void doReplaceDecoration( DebugId id
			, spv::Decoration oldDecoration
			, spv::Decoration newDecoration );
		void doReplaceMemberDecoration( DebugId id
			, uint32_t index
			, spv::Decoration oldDecoration
			, spv::Decoration newDecoration );
		void doInitialiseHeader( Header const & header );
		void doInitialiseExtensions( bool enableDebug
			, glsl::Statements const & debugStatements );
		void doInitialiseCapacities();
		bool doDeserializeInfos( spv::Op opCode
			, InstructionList::iterator & current
			, InstructionList::iterator end );
		bool doDeserializeFunc( spv::Op opCode
			, InstructionList::iterator & current
			, InstructionList::iterator end );
		InstructionList * doSelectInstructionsList( spv::Op opCode );
		void doAddDebug( std::string const & name
			, DebugId id );
		void doAddBuiltin( ast::Builtin builtin
			, DebugId id );
		void doAddVariable( Block & block
			, std::string name
			, DebugId varId
			, spv::StorageClass storage
			, Map< std::string, VariableInfo >::iterator & it
			, DebugId initialiser
			, glsl::Statement const * debugStatement = nullptr );

	private:
		using DecorationMap = UnorderedMap< ValueIdList, size_t, ValueIdListHasher >;
		using DecorationMapIdMap = Map< DebugId, DecorationMap >;
		using DecorationMapMbrMap = UnorderedMap< ValueIdList, DecorationMap, ValueIdListHasher >;

		struct VariableDebugId
		{
			ValueId variable;
			ValueId debug;
		};

	private:
		uint32_t m_version;
		spv::Id * m_currentId;
		Function * m_currentFunction{ nullptr };
		Map< std::string, VariableInfo > m_registeredVariables;
		Map< std::string, VariableInfo > * m_currentScopeVariables;
		UnorderedMap< DebugId, TypeId, DebugIdHasher > m_registeredVariablesTypes;
		Map< std::string, std::pair< DebugId, DebugId > > m_registeredMemberVariables;
		UnorderedSet< spv::Id > m_intermediates;
		UnorderedSet< spv::Id > m_freeIntermediates;
		UnorderedMap< spv::Id, ValueId > m_busyIntermediates;
		spv::ExecutionModel m_model;
		InstructionList m_pendingExecutionModes;
		ValueIdSet m_entryPointIO;
		DecorationMapIdMap varDecorations;
		DecorationMapMbrMap mbrDecorations;
		debug::DebugNames m_debugNames;
		debug::NonSemanticDebug m_nonSemanticDebug;
		ModuleTypes m_types;
		ModuleLiterals m_literals;
	};
}

#endif
