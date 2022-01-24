/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModule_H___
#define ___SDW_SpirvModule_H___
#pragma once

#include "SpirvFunction.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

#include <set>
#include <unordered_set>

namespace spirv
{
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
		SDWSPIRV_API Module( ast::type::TypesCache & cache
			, SpirVConfig const & spirvConfig
			, spv::AddressingModel addressingModel
			, spv::MemoryModel memoryModel
			, spv::ExecutionModel executionModel );
		SDWSPIRV_API Module( Header const & header
			, InstructionList instructions );

		uint32_t getVersion()const
		{
			return m_version;
		}

		SDWSPIRV_API static Module deserialize( UInt32List const & spirv );
		SDWSPIRV_API static std::vector< uint32_t > serialize( spirv::Module const & module );
		SDWSPIRV_API static std::string write( spirv::Module const & module
			, bool writeHeader );

		SDWSPIRV_API ValueId registerType( ast::type::TypePtr type );
		SDWSPIRV_API ValueId registerPointerType( ValueId type
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
		SDWSPIRV_API VariableInfo registerParam( std::string const & name
			, bool isOutput
			, ast::type::TypePtr type );
		SDWSPIRV_API VariableInfo registerAlias( std::string const & name
			, ast::type::TypePtr type
			, ValueId exprResultId );
		SDWSPIRV_API VariableInfo registerVariable( std::string const & name
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
		SDWSPIRV_API ValueId registerLiteral( int32_t value );
		SDWSPIRV_API ValueId registerLiteral( uint32_t value );
		SDWSPIRV_API ValueId registerLiteral( uint64_t value );
		SDWSPIRV_API ValueId registerLiteral( float value );
		SDWSPIRV_API ValueId registerLiteral( double value );
		SDWSPIRV_API ValueId registerLiteral( ValueIdList const & initialisers
			, ast::type::TypePtr type );
		SDWSPIRV_API void registerExtension( std::string const & name );
		SDWSPIRV_API void registerEntryPoint( ValueId functionId
			, std::string const & name
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
		SDWSPIRV_API void registerExecutionMode( ast::type::OutputTopology topology
			, uint32_t maxVertices
			, uint32_t maxPrimitives );
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
		SDWSPIRV_API void bindVariable( ValueId varId
			, uint32_t bindingPoint
			, uint32_t descriptorSet );
		SDWSPIRV_API void bindBufferVariable( std::string const & name
			, uint32_t bindingPoint
			, uint32_t descriptorSet
			, spv::Decoration structDecoration );// BufferBlock for SSBO, Block for UBO

		SDWSPIRV_API Function * beginFunction( std::string const & name
			, ValueId retType
			, ast::var::VariableList const & params );
		SDWSPIRV_API Block newBlock();
		SDWSPIRV_API void endFunction();

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
		ModuleStruct structData;
		FunctionList functions;
		InstructionList * variables;

	private:
		ValueId doRegisterNonArrayType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, ValueId parentId );
		ValueId registerType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, ValueId parentId
			, uint32_t arrayStride );
		ValueId registerBaseType( ast::type::Kind kind
			, uint32_t mbrIndex
			, ValueId parentId
			, uint32_t arrayStride );
		ValueId registerBaseType( ast::type::StructPtr type
			, uint32_t mbrIndex
			, ValueId parentId );
		ValueId registerBaseType( ast::type::SampledImagePtr type
			, uint32_t mbrIndex
			, ValueId parentId );
		ValueId registerBaseType( ast::type::ImagePtr type
			, uint32_t mbrIndex
			, ValueId parentId );
		ValueId registerBaseType( ast::type::AccelerationStructurePtr type
			, uint32_t mbrIndex
			, ValueId parentId );
		ValueId registerBaseType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, ValueId parentId
			, uint32_t arrayStride );

	private:
		void initialiseHeader( Header const & header );
		void initialiseExtensions();
		void initialiseCapacities();
		bool deserializeInfos( spv::Op opCode
			, InstructionList::iterator & current
			, InstructionList::iterator end );
		bool deserializeFuncs( spv::Op opCode
			, InstructionList::iterator & current
			, InstructionList::iterator end );
		InstructionList * selectInstructionsList( spv::Op opCode );
		spv::Id getNextId();
		void addDebug( std::string const & name
			, ValueId id );
		void addBuiltin( ast::Builtin builtin
			, ValueId id );
		bool addMbrBuiltin( ast::Builtin pbuiltin
			, ValueId outer
			, uint32_t mbrIndex );
		void addVariable( std::string const & name
			, ValueId varId
			, std::map< std::string, VariableInfo >::iterator & it
			, ValueId initialiser );

	private:
		uint32_t m_version;
		ast::type::TypesCache * m_cache;
		spv::Id * m_currentId;
		Function * m_currentFunction{ nullptr };
		std::map< ast::type::TypePtr, ValueId > m_registeredTypes;
		std::map< ast::type::TypePtr, ValueId > m_registeredMemberTypes;
		std::map< std::string, VariableInfo > m_registeredVariables;
		std::map< std::string, VariableInfo > * m_currentScopeVariables;
		std::unordered_map< ValueId, ValueId, ValueIdHasher > m_registeredVariablesTypes;
		std::map< std::string, std::pair< ValueId, ValueId > > m_registeredMemberVariables;
		std::map< uint64_t, ValueId > m_registeredPointerTypes;
		std::map< uint64_t, ValueId > m_registeredForwardPointerTypes;
		std::unordered_map< ValueIdList, ValueId, ValueIdListHasher > m_registeredFunctionTypes;
		std::map< bool, ValueId > m_registeredBoolConstants;
		std::map< int32_t, ValueId > m_registeredIntConstants;
		std::map< uint32_t, ValueId > m_registeredUIntConstants;
		std::map< uint64_t, ValueId > m_registeredUInt64Constants;
		std::map< float, ValueId > m_registeredFloatConstants;
		std::map< double, ValueId > m_registeredDoubleConstants;
		std::vector< std::pair< ValueIdList, ValueId > > m_registeredCompositeConstants;
		std::unordered_map< ValueId, ast::type::TypePtr, ValueIdHasher > m_registeredConstants;
		std::unordered_set< spv::Id > m_intermediates;
		std::unordered_set< spv::Id > m_freeIntermediates;
		std::unordered_map< spv::Id, ValueId > m_busyIntermediates;
		spv::ExecutionModel m_model;
		InstructionList m_pendingExecutionModes;
		std::map< spv::Id, IdSet > m_varDecorations;
		std::map< spv::Id, IdSet > m_mbrDecorations;
		ValueIdSet m_entryPointIO;
	};
}

#endif
