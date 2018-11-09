/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModule_H___
#define ___SDW_SpirvModule_H___
#pragma once

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"
#include "spirv/spirv.hpp"

#include <ASTGenerator/Type/TypeStruct.hpp>

#include <optional>
#include <set>
#include <string>
#include <vector>

namespace sdw::spirv
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

	struct Instruction
	{
		Instruction( spv::Op op = spv::Op::OpNop
			, std::optional< spv::Id > resultType = std::nullopt
			, std::optional< spv::Id > resultId = std::nullopt
			, IdList operands = IdList{}
			, std::optional< std::string > name = std::nullopt
			, std::optional< std::map< int64_t, spv::Id > > labels = std::nullopt );

		// Serialisable.
		Op op;
		std::optional< spv::Id > resultType;
		std::optional< spv::Id > resultId;
		IdList operands;
		std::optional< std::vector< uint32_t > > packedName;
		// Used during construction.
		std::optional< std::string > name;
		std::optional< std::map< int64_t, spv::Id > > labels;
	};

	using InstructionList = std::vector< Instruction >;

	struct Block
	{
		spv::Id label;
		InstructionList instructions;
		Instruction blockEnd;
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
		spv::Id * currentId;
		bool hasReturn{ false };
	};
	using FunctionList = std::vector< Function >;

	class Module
	{
	public:
		Module( spv::MemoryModel memoryModel
			, spv::ExecutionModel executionModel );
		spv::Id registerType( type::TypePtr type );
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
		spv::Id registerVariable( std::string const & name
			, spv::StorageClass storage
			, type::TypePtr type );
		spv::Id registerParameter( type::TypePtr type );
		spv::Id Module::registerMemberVariableIndex( type::TypePtr type );
		spv::Id registerMemberVariable( spv::Id outer
			, std::string name
			, type::TypePtr type );
		spv::Id registerLiteral( bool value );
		spv::Id registerLiteral( int32_t value );
		spv::Id registerLiteral( uint32_t value );
		spv::Id registerLiteral( float value );
		spv::Id registerLiteral( double value );
		spv::Id registerLiteral( IdList const & initialisers
			, type::TypePtr type );
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
			, type::TypePtr type
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
			, var::VariableList const & params );
		Block newBlock();
		void endFunction();

	public:
		IdList header;
		InstructionList capabilities;
		InstructionList extensions;
		InstructionList imports;
		Instruction memoryModel;
		Instruction entryPoint;
		InstructionList executionModes;
		InstructionList debug;
		InstructionList decorations;
		InstructionList globalDeclarations;
		FunctionList functions;
		InstructionList * variables;

	private:
		spv::Id registerType( type::TypePtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( type::Kind kind
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( type::StructPtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( type::SampledImagePtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( type::ImagePtr type
			, uint32_t mbrIndex
			, spv::Id parentId );
		spv::Id registerBaseType( type::TypePtr type
			, uint32_t mbrIndex
			, spv::Id parentId );

	private:
		spv::Id * m_currentId;
		Function * m_currentFunction{ nullptr };
		std::map< type::TypePtr, spv::Id > m_registeredTypes;
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
		std::map< spv::Id, type::TypePtr > m_registeredConstants;
		std::set< spv::Id > m_intermediates;
		std::set< spv::Id > m_freeIntermediates;
		std::map< spv::Id, spv::Id > m_busyIntermediates;
		spv::ExecutionModel m_model;
		InstructionList m_pendingExecutionModes;
	};
}

#endif
