/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModule_H___
#define ___SDW_SpirvModule_H___
#pragma once

#include "SpirvFunction.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

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
			, spv::MemoryModel memoryModel
			, spv::ExecutionModel executionModel );
		SDWSPIRV_API Module( Header const & header
			, InstructionList && instructions );

		SDWSPIRV_API static Module deserialize( UInt32List const & spirv );
		SDWSPIRV_API static std::vector< uint32_t > serialize( spirv::Module const & module );
		SDWSPIRV_API static std::string write( spirv::Module const & module
			, bool writeHeader );

		SDWSPIRV_API spv::Id registerType( ast::type::TypePtr type );
		SDWSPIRV_API spv::Id registerPointerType( spv::Id type
			, spv::StorageClass storage );
		SDWSPIRV_API void decorate( spv::Id id
			, spv::Decoration decoration );
		SDWSPIRV_API void decorate( spv::Id id
			, IdList const & decoration );
		SDWSPIRV_API void decorateMember( spv::Id id
			, uint32_t index
			, spv::Decoration decoration );
		SDWSPIRV_API void decorateMember( spv::Id id
			, uint32_t index
			, IdList const & decoration );
		SDWSPIRV_API VariableInfo & registerVariable( std::string const & name
			, spv::StorageClass storage
			, ast::type::TypePtr type
			, VariableInfo & info
			, spv::Id initialiser = 0u );
		SDWSPIRV_API spv::Id registerSpecConstant( std::string name
			, uint32_t location
			, ast::type::TypePtr type
			, ast::expr::Literal const & value );
		SDWSPIRV_API spv::Id registerParameter( ast::type::TypePtr type );
		SDWSPIRV_API spv::Id registerMemberVariableIndex( ast::type::TypePtr type );
		SDWSPIRV_API spv::Id registerMemberVariable( spv::Id outer
			, std::string name
			, ast::type::TypePtr type );
		SDWSPIRV_API spv::Id registerLiteral( bool value );
		SDWSPIRV_API spv::Id registerLiteral( int32_t value );
		SDWSPIRV_API spv::Id registerLiteral( uint32_t value );
		SDWSPIRV_API spv::Id registerLiteral( float value );
		SDWSPIRV_API spv::Id registerLiteral( double value );
		SDWSPIRV_API spv::Id registerLiteral( IdList const & initialisers
			, ast::type::TypePtr type );
		SDWSPIRV_API void registerExtension( std::string const & name );
		SDWSPIRV_API void registerEntryPoint( spv::Id functionId
			, std::string const & name
			, IdList const & inputs
			, IdList const & outputs );
		SDWSPIRV_API void registerExecutionMode( spv::ExecutionMode mode );
		SDWSPIRV_API void registerExecutionMode( spv::ExecutionMode mode
			, IdList const & operands );
		SDWSPIRV_API spv::Id getIntermediateResult();
		SDWSPIRV_API void lnkIntermediateResult( spv::Id intermediate, spv::Id var );
		SDWSPIRV_API void putIntermediateResult( spv::Id id );
		SDWSPIRV_API spv::Id getNonIntermediate( spv::Id id );

		SDWSPIRV_API ast::type::Kind getLiteralType( spv::Id litId )const;
		SDWSPIRV_API spv::Id getOuterVariable( spv::Id mbrId )const;
		SDWSPIRV_API spv::Id loadVariable( spv::Id variable
			, ast::type::TypePtr type
			, Block & currentBlock );
		SDWSPIRV_API void bindVariable( spv::Id varId
			, uint32_t bindingPoint
			, uint32_t descriptorSet );
		SDWSPIRV_API void bindBufferVariable( std::string const & name
			, uint32_t bindingPoint
			, uint32_t descriptorSet
			, spv::Decoration structDecoration );// BufferBlock for SSBO, Block for UBO

		SDWSPIRV_API Function * beginFunction( std::string const & name
			, spv::Id retType
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
			, ast::type::TypePtr type
			, spv::Id id );
		void addBuiltin( std::string const & name
			, spv::Id id );
		bool addMbrBuiltin( std::string const & name
			, spv::Id outer
			, uint32_t mbrIndex );
		void addVariable( std::string const & name
			, spv::StorageClass storage
			, ast::type::TypePtr type
			, spv::Id id
			, std::map< std::string, spv::Id >::iterator & it
			, spv::Id initialiser );

	private:
		ast::type::TypesCache * m_cache;
		spv::Id * m_currentId;
		Function * m_currentFunction{ nullptr };
		std::map< ast::type::TypePtr, spv::Id > m_registeredTypes;
		std::map< ast::type::TypePtr, spv::Id > m_registeredMemberTypes;
		std::map< std::string, spv::Id > m_registeredVariables;
		std::map< std::string, spv::Id > * m_currentScopeVariables;
		std::map< spv::Id, spv::Id > m_registeredVariablesTypes;
		std::map< std::string, std::pair< spv::Id, spv::Id > > m_registeredMemberVariables;
		std::map< uint64_t, spv::Id > m_registeredPointerTypes;
		std::unordered_map< IdList, spv::Id, IdListHasher > m_registeredFunctionTypes;
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

#endif
