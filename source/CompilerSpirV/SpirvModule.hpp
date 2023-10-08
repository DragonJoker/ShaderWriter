/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModule_H___
#define ___SDW_SpirvModule_H___
#pragma once

#include "CompilerSpirV/SpirvFunction.hpp"
#include "CompilerSpirV/SpirVStmtDebugVisitor.hpp"

#include "CompilerSpirV/spirv/NonSemantic.Shader.DebugInfo.100.hpp"

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
		Module( ast::ShaderAllocatorBlock * alloc );

	public:
		SDWSPIRV_API Module( ast::ShaderAllocatorBlock * alloc
			, ast::type::TypesCache & typesCache
			, SpirVConfig const & spirvConfig
			, spv::AddressingModel addressingModel
			, spv::MemoryModel memoryModel
			, spv::ExecutionModel executionModel
			, debug::DebugStatements const & debugStatements );
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

		SDWSPIRV_API TypeId registerType( ast::type::TypePtr type );
		SDWSPIRV_API TypeId registerType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		SDWSPIRV_API TypeId registerImageType( ast::type::ImagePtr image
			, bool isComparison );
		SDWSPIRV_API TypeId registerPointerType( TypeId type
			, spv::StorageClass storage
			, bool isForward = false );
		SDWSPIRV_API void decorate( ValueId id
			, spv::Decoration decoration );
		SDWSPIRV_API void decorate( ValueId id
			, IdList const & decoration );
		SDWSPIRV_API void decorateMember( ValueId id
			, uint32_t index
			, spv::Decoration decoration );
		SDWSPIRV_API void decorateMember( ValueId id
			, uint32_t index
			, IdList const & decoration );
		SDWSPIRV_API VariableInfo registerParam( std::string name
			, bool isOutput
			, ast::type::TypePtr type );
		SDWSPIRV_API VariableInfo registerAlias( std::string name
			, ast::type::TypePtr type
			, ValueId exprResultId );
		SDWSPIRV_API VariableInfo registerVariable( std::string name
			, ast::Builtin builtin
			, spv::StorageClass storage
			, bool isAlias
			, bool isParam
			, bool isOutParam
			, ast::type::TypePtr type
			, VariableInfo & sourceInfo
			, ValueId initialiser = {} );
		SDWSPIRV_API ValueId registerSpecConstant( std::string name
			, uint32_t location
			, ast::type::TypePtr type
			, ast::expr::Literal const & value );
		SDWSPIRV_API ValueId registerParameter( ast::type::TypePtr type );
		SDWSPIRV_API ValueId registerMemberVariableIndex( ast::type::TypePtr type );
		SDWSPIRV_API ValueId registerMemberVariable( ValueId outer
			, std::string name
			, ast::type::TypePtr type );
		SDWSPIRV_API ValueId registerLiteral( bool value );
		SDWSPIRV_API ValueId registerLiteral( int8_t value );
		SDWSPIRV_API ValueId registerLiteral( int16_t value );
		SDWSPIRV_API ValueId registerLiteral( int32_t value );
		SDWSPIRV_API ValueId registerLiteral( uint8_t value );
		SDWSPIRV_API ValueId registerLiteral( uint16_t value );
		SDWSPIRV_API ValueId registerLiteral( uint32_t value );
		SDWSPIRV_API ValueId registerLiteral( int64_t value );
		SDWSPIRV_API ValueId registerLiteral( uint64_t value );
		SDWSPIRV_API ValueId registerLiteral( float value );
		SDWSPIRV_API ValueId registerLiteral( double value );
		SDWSPIRV_API ValueId registerLiteral( ValueIdList const & initialisers
			, ast::type::TypePtr type );
		SDWSPIRV_API void registerExtension( std::string name );
		SDWSPIRV_API void registerEntryPoint( ValueId functionId
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
		SDWSPIRV_API void lnkIntermediateResult( ValueId intermediate, ValueId var );
		SDWSPIRV_API void putIntermediateResult( ValueId id );
		SDWSPIRV_API ValueId getNonIntermediate( ValueId id );

		SDWSPIRV_API ast::type::Kind getLiteralType( ValueId litId )const;
		SDWSPIRV_API ValueId getOuterVariable( ValueId mbrId )const;
		SDWSPIRV_API ValueId getVariablePointer( ValueId varId
			, std::string name
			, spv::StorageClass storage
			, Block & currentBlock );
		SDWSPIRV_API ValueId getVariablePointer( std::string name
			, spv::StorageClass storage
			, ast::type::TypePtr type
			, Block & currentBlock );
		SDWSPIRV_API void storePromoted( ValueId variable
			, VariableInfo const & sourceInfo
			, Block & currentBlock );
		SDWSPIRV_API void storeVariable( ValueId variable
			, ValueId value
			, InstructionList & instructions );
		SDWSPIRV_API void storeVariable( ValueId variable
			, ValueId value
			, Block & currentBlock );
		SDWSPIRV_API ValueId loadVariable( ValueId variable
			, InstructionList & instructions );
		SDWSPIRV_API ValueId loadVariable( ValueId variable
			, Block & currentBlock );
		SDWSPIRV_API ValueId mergeSamplerImage( ValueId const & image
			, ValueId const & sampler
			, Block & currentBlock );
		SDWSPIRV_API void bindVariable( ValueId varId
			, uint32_t bindingPoint
			, uint32_t descriptorSet );
		SDWSPIRV_API ValueId bindBufferVariable( std::string const & name
			, uint32_t bindingPoint
			, uint32_t descriptorSet
			, spv::Decoration structDecoration );// BufferBlock for SSBO, Block for UBO

		SDWSPIRV_API Function * beginFunction( std::string name
			, TypeId retType
			, ast::var::VariableList const & params );
		SDWSPIRV_API Block newBlock();
		SDWSPIRV_API void endFunction();

		SDWSPIRV_API ValueId makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
			, ValueIdList operands );
		SDWSPIRV_API ValueId makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
			, Block & block
			, ValueIdList operands );
		SDWSPIRV_API void makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
			, ValueId const & resultId
			, ValueIdList operands );
		SDWSPIRV_API void makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
			, ValueId const & resultId
			, Block & block
			, ValueIdList operands );
		SDWSPIRV_API ValueId registerDebugVariable( std::string const & name
			, ast::type::TypePtr type
			, uint64_t varFlags
			, ValueId const & variableId
			, debug::DebugStatement const * debugStatement );
		SDWSPIRV_API ValueId registerDebugMemberVariable( std::string const & name
			, ast::type::TypePtr type
			, uint64_t varFlags
			, debug::DebugStatement const * debugStatement );

		SDWSPIRV_API spv::Id getNextId();

		inline ast::type::TypesCache & getTypesCache()
		{
			return *m_typesCache;
		}

	public:
		ast::ShaderAllocatorBlock * allocator;
		Map< std::string, Vector< uint32_t > > nameCache;
		ValueId extGlslStd450{};
		ValueId extDebugInfo{};
		ValueId debugSourceId{};
		ValueId globalScopeId{};

		IdList header;
		InstructionList capabilities;
		InstructionList extensions;
		InstructionList imports;
		InstructionPtr memoryModel;
		InstructionPtr entryPoint;
		InstructionList executionModes;
		InstructionList debugString;
		InstructionList debug;
		InstructionList decorations;
		InstructionList constantsTypes;
		InstructionList globalDeclarations;
		InstructionList debugDeclarations;
		ModuleStruct structData;
		FunctionList functions;
		InstructionList * variables;

	private:
		TypeId doRegisterNonArrayType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterTypeRec( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId
			, uint32_t arrayStride );
		TypeId doRegisterBaseType( ast::type::Kind kind
			, uint32_t mbrIndex
			, TypeId parentId
			, uint32_t arrayStride );
		TypeId doRegisterBaseType( ast::type::StructPtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::SamplerPtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::CombinedImagePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::ImagePtr type
			, ast::type::Trinary isComparison );
		TypeId doRegisterBaseType( ast::type::ImagePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::SampledImagePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::AccelerationStructurePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId
			, uint32_t arrayStride );
		void doReplaceDecoration( ValueId id
			, spv::Decoration oldDecoration
			, spv::Decoration newDecoration );
		void doReplaceMemberDecoration( ValueId id
			, uint32_t index
			, spv::Decoration oldDecoration
			, spv::Decoration newDecoration );
		void doInitialiseHeader( Header const & header );
		void doInitialiseExtensions( bool enableDebug );
		void doInitialiseCapacities();
		void doInitialiseDebug( bool isDebugEnabled
			, debug::DebugStatements const & debugStatements );
		bool doDeserializeInfos( spv::Op opCode
			, InstructionList::iterator & current
			, InstructionList::iterator end );
		bool doDeserializeFuncs( spv::Op opCode
			, InstructionList::iterator & current
			, InstructionList::iterator end );
		InstructionList * doSelectInstructionsList( spv::Op opCode );
		void doAddDebug( std::string const & name
			, ValueId id );
		void doAddBuiltin( ast::Builtin builtin
			, ValueId id );
		bool doAddMbrBuiltin( ast::Builtin pbuiltin
			, ValueId outer
			, uint32_t mbrIndex );
		void doAddVariable( std::string name
			, ValueId varId
			, Map< std::string, VariableInfo >::iterator & it
			, ValueId initialiser );

	private:
		using DecorationMap = UnorderedMap< ValueIdList, size_t, ValueIdListHasher >;
		using DecorationMapIdMap = Map< ValueId, DecorationMap >;
		using DecorationMapMbrMap = UnorderedMap< ValueIdList, DecorationMap, ValueIdListHasher >;

	private:
		uint32_t m_version;
		ast::type::TypesCache * m_typesCache;
		spv::Id * m_currentId;
		Function * m_currentFunction{ nullptr };
		Map< ast::type::TypePtr, TypeId > m_registeredTypes;
		Map< ast::type::TypePtr, TypeId > m_registeredMemberTypes;
		Map< std::string, VariableInfo > m_registeredVariables;
		UnorderedMap< ValueId, UnorderedMap< ValueId, ValueId, ValueIdHasher >, ValueIdHasher > m_registeredSamplerImages;
		UnorderedMap< size_t, TypeId > m_registeredImageTypes;
		Map< std::string, VariableInfo > * m_currentScopeVariables;
		UnorderedMap< ValueId, TypeId, ValueIdHasher > m_registeredVariablesTypes;
		Map< std::string, std::pair< ValueId, ValueId > > m_registeredMemberVariables;
		Map< uint64_t, TypeId > m_registeredPointerTypes;
		Map< uint64_t, TypeId > m_registeredForwardPointerTypes;
		UnorderedMap< TypeIdList, TypeId, TypeIdListHasher > m_registeredFunctionTypes;
		Map< bool, ValueId > m_registeredBoolConstants;
		Map< int8_t, ValueId > m_registeredInt8Constants;
		Map< int16_t, ValueId > m_registeredInt16Constants;
		Map< int32_t, ValueId > m_registeredInt32Constants;
		Map< int64_t, ValueId > m_registeredInt64Constants;
		Map< uint8_t, ValueId > m_registeredUInt8Constants;
		Map< uint16_t, ValueId > m_registeredUInt16Constants;
		Map< uint32_t, ValueId > m_registeredUInt32Constants;
		Map< uint64_t, ValueId > m_registeredUInt64Constants;
		Map< float, ValueId > m_registeredFloatConstants;
		Map< double, ValueId > m_registeredDoubleConstants;
		Vector< std::pair< ValueIdList, ValueId > > m_registeredCompositeConstants;
		UnorderedMap< ValueId, ast::type::TypePtr, ValueIdHasher > m_registeredConstants;
		UnorderedSet< spv::Id > m_intermediates;
		UnorderedSet< spv::Id > m_freeIntermediates;
		UnorderedMap< spv::Id, ValueId > m_busyIntermediates;
		spv::ExecutionModel m_model;
		InstructionList m_pendingExecutionModes;
		ValueIdSet m_entryPointIO;
		DecorationMapIdMap varDecorations;
		DecorationMapMbrMap mbrDecorations;
		TypeId m_voidType{};
		ValueId m_currentScopeId{};
		ValueId m_debugInfoNone{};
	};
}

#endif
