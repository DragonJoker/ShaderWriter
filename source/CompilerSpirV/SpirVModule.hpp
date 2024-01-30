/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModule_H___
#define ___SDW_SpirvModule_H___
#pragma once

#include "CompilerSpirV/SpirVDebugNames.hpp"
#include "CompilerSpirV/SpirVFunction.hpp"
#include "CompilerSpirV/SpirVModuleLiterals.hpp"
#include "CompilerSpirV/SpirVModuleTypes.hpp"
#include "CompilerSpirV/SpirVNonSemanticDebug.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

#include <set>

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

	struct NameCache
	{
		using IdNames = ast::Map< spv::Id, std::string >;

		explicit NameCache( ast::ShaderAllocatorBlock * alloc );
		void add( spv::Id id, std::string name );
		void addMember( spv::Id outerId, uint32_t index, std::string name );
		void addType( spv::Id id, std::string name );

		std::string getFloatTypeName( Instruction const & instruction )const;
		std::string getIntTypeName( Instruction const & instruction )const;
		std::string getVecTypeName( Instruction const & instruction )const;
		std::string getMatTypeName( Instruction const & instruction )const;
		std::string getStructTypeName( Instruction const & instruction )const;
		std::string getArrayTypeName( Instruction const & instruction )const;
		std::string getPtrTypeName( Instruction const & instruction )const;
		std::string getRaw( spv::Id id )const;
		std::string get( spv::Id id )const;
		std::string getMember( spv::Id id, uint32_t index )const;

		IdNames names;
		IdNames types;
		using MemberList = std::map< uint32_t, std::string >;
		std::map< spv::Id, MemberList > members;
	};

	class Module
	{
	private:
		Module( ast::ShaderAllocatorBlock * alloc
			, SpirVConfig const * spirvConfig
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
			, ast::type::TypesCache & typesCache
			, NameCache & names
			, Header const & header
			, InstructionList instructions );

		uint32_t getVersion()const
		{
			return m_version;
		}

		SDWSPIRV_API static Module deserialize( ast::ShaderAllocatorBlock * allocator
			, ast::type::TypesCache & typesCache
			, NameCache & names
			, std::vector< uint32_t > const & spirv );
		SDWSPIRV_API static UInt32List serialize( spirv::Module const & shaderModule );
		SDWSPIRV_API static std::string write( spirv::Module const & shaderModule
			, NameCache & names
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
		SDWSPIRV_API void decorate( DebugId const & id
			, spv::Decoration decoration );
		SDWSPIRV_API void decorate( DebugId const & id
			, IdList const & decoration );
		SDWSPIRV_API void decorateMember( DebugId const & id
			, uint32_t index
			, spv::Decoration decoration );
		SDWSPIRV_API void decorateMember( DebugId const & id
			, uint32_t index
			, IdList const & decoration );
		SDWSPIRV_API VariableInfo registerParam( std::string name
			, bool isOutput
			, ast::type::TypePtr type );
		SDWSPIRV_API VariableInfo registerAlias( std::string name
			, ast::type::TypePtr type
			, DebugId exprResultId );
		SDWSPIRV_API VariableInfo registerVariable( Block & block
			, std::string const & name
			, ast::Builtin builtin
			, spv::StorageClass storage
			, bool isAlias
			, bool isParam
			, bool isOutParam
			, ast::type::TypePtr type
			, VariableInfo & sourceInfo
			, DebugId const & initialiser = DebugId{}
			, glsl::Statement const * debugStatement = {} );
		SDWSPIRV_API DebugId registerSpecConstant( std::string name
			, uint32_t location
			, ast::type::TypePtr type
			, ast::expr::Literal const & value );
		SDWSPIRV_API ValueId registerParameter( ast::type::TypePtr type );
		SDWSPIRV_API DebugId registerMemberVariableIndex( ast::type::TypePtr type );
		SDWSPIRV_API DebugId registerMemberVariable( DebugId outer
			, std::string const & name
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
		ValueId registerString( std::string text );
		SDWSPIRV_API spv::Id getIntermediateResult();

		SDWSPIRV_API DebugId getVariablePointer( Block & block
			, DebugId varId
			, std::string name
			, spv::StorageClass storage
			, Block & currentBlock
			, glsl::Statement const * statement
			, glsl::RangeInfo const & columns );
		SDWSPIRV_API DebugId getVariablePointer( Block & block
			, std::string const & name
			, spv::StorageClass storage
			, Block & currentBlock
			, glsl::Statement const * statement
			, glsl::RangeInfo const & columns );
		SDWSPIRV_API void storePromoted( DebugId const & variable
			, VariableInfo const & sourceInfo
			, Block & currentBlock
			, glsl::Statement const * debugStatement
			, glsl::RangeInfo const & columns );
		SDWSPIRV_API void storeVariable( DebugId const & variable
			, DebugId const & value
			, Block & currentBlock
			, glsl::Statement const * debugStatement
			, glsl::RangeInfo const & columns );
		SDWSPIRV_API DebugId loadVariable( DebugId const & variable
			, Block & currentBlock
			, glsl::Statement const * debugStatement
			, glsl::RangeInfo const & columns );
		SDWSPIRV_API void bindVariable( DebugId const & varId
			, uint32_t bindingPoint
			, uint32_t descriptorSet );
		SDWSPIRV_API void bindBufferVariable( DebugId const & variableId
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
		SDWSPIRV_API NamesCache & getNameCache()noexcept;
		SDWSPIRV_API ast::type::TypesCache & getTypesCache()const noexcept;
		SDWSPIRV_API void declareDebugAccessChain( InstructionList & instructions
			, ast::expr::Expr const & expr
			, glsl::Statement const * debugStatement
			, DebugId & resultId );
		SDWSPIRV_API ast::type::TypePtr getType( DebugId const & typeId )const;

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
		static uint32_t constexpr Version = ( ( uint32_t( ( MAIN_VERSION_MAJOR & 0x0F ) << 8 ) )
			| ( uint32_t( ( MAIN_VERSION_MINOR & 0x0F ) << 4 ) )
			| ( uint32_t( ( MAIN_VERSION_BUILD & 0x0F ) << 0 ) ) );

		ast::ShaderAllocatorBlock * allocator{};
		ValueId extGlslStd450{};

		IdList header;
		InstructionList capabilities;
		InstructionList extensions;
		InstructionList imports;
		InstructionPtr memoryModel{};
		InstructionPtr entryPoint{};
		InstructionList executionModes;
		InstructionList decorations;
		InstructionList constantsTypes;
		InstructionList globalDeclarations;
		ModuleStruct structData;
		FunctionList functions;
		InstructionList * variables{};

	private:
		void doReplaceDecoration( DebugId const & id
			, spv::Decoration oldDecoration
			, spv::Decoration newDecoration );
		void doReplaceMemberDecoration( DebugId const & id
			, uint32_t index
			, spv::Decoration oldDecoration
			, spv::Decoration newDecoration );
		void doInitialiseHeader( Header const & header );
		void doInitialiseExtensions( bool enableDebug
			, glsl::Statements const & debugStatements );
		void doInitialiseCapacities();
		void doAddDebug( std::string const & name
			, DebugId const & id );
		void doAddBuiltin( ast::Builtin builtin
			, DebugId const & id );
		void doAddVariable( Block & block
			, std::string const & name
			, DebugId const & varId
			, ast::Map< std::string, VariableInfo >::iterator & it
			, DebugId const & initialiser
			, glsl::Statement const * debugStatement = nullptr );

	private:
		using DecorationMap = ast::UnorderedMap< ValueIdList, size_t, ValueIdListHasher >;
		using DecorationMapIdMap = ast::Map< DebugId, DecorationMap >;
		using DecorationMapMbrMap = ast::UnorderedMap< ValueIdList, DecorationMap, ValueIdListHasher >;

		struct VariableDebugId
		{
			ValueId variable{};
			ValueId debug{};
		};

	private:
		uint32_t m_version{};
		spv::Id * m_currentId{};
		Function * m_currentFunction{ nullptr };
		ast::Map< std::string, VariableInfo, std::less<> > m_registeredVariables;
		ast::Map< std::string, VariableInfo, std::less<> > * m_currentScopeVariables;
		ast::UnorderedMap< DebugId, TypeId, DebugIdHasher > m_registeredVariablesTypes;
		ast::Map< std::string, std::pair< DebugId, DebugId >, std::less<> > m_registeredMemberVariables;
		spv::ExecutionModel m_model{};
		ast::Set< spv::ExecutionMode > m_registeredExecutionModes;
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
