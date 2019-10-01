/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvFunction_H___
#define ___SDW_SpirvFunction_H___
#pragma once

#include "SpirvBlock.hpp"

namespace spirv
{
	struct LoadedVariable
	{
		spv::Id varId;
		spv::Id loadedId;
	};

	using LoadedVariableArray = std::vector< LoadedVariable >;

	enum class BlockType
	{
		eGlobal,
		eFunction,
		eMax,
	};

	struct Variable
	{
		Variable( ast::var::VariablePtr var
			, IdList decorations )
			: var{ std::move( var ) }
			, decorations{ std::move( decorations ) }
		{
		}

		ast::var::VariablePtr var;
		IdList decorations;
	};

	using VariablePtr = std::shared_ptr< Variable >;
	using VariableArray = std::vector< VariablePtr >;

	struct VarUsage
	{
		VariableArray use;
		VariablePtr set;
	};

	using VarUsageArray = std::vector< VarUsage >;
	using UsedVars = std::set< VariablePtr >;

	struct BlockStruct
	{
		BlockType type;
		VariableArray * allVars;
		VarUsageArray usages;
		VariableArray ownVars;
	};

	using BlockStructMap = std::map< uint32_t, BlockStruct >;

	using TypeMap = std::map< uint32_t, ast::type::TypePtr >;

	struct ModuleStruct
	{
		TypeMap types;
		BlockStruct globalScope{ BlockType::eGlobal };
		BlockStructMap functionScopes;
	};

	using IdSet = std::set< spv::Id >;

	struct Parameter
	{
		spv::Id id;
		spv::Id type;
	};

	using ParameterList = std::vector< Parameter >;
	using BlockList = std::vector< Block >;

	struct ControlFlowGraph
	{
		BlockList blocks;
	};

	struct Function
	{
		SDWSPIRV_API Function( Function const & rhs ) = delete;
		SDWSPIRV_API Function & operator=( Function const & rhs ) = delete;
		SDWSPIRV_API Function( Function && rhs ) = default;
		SDWSPIRV_API Function & operator=( Function && rhs ) = default;
		SDWSPIRV_API Function() = default;

		SDWSPIRV_API static Function deserialize( InstructionListIt & buffer
			, InstructionListIt const & end );

		// Serialisable.
		InstructionList declaration;
		ControlFlowGraph cfg;
		// Used during construction.
		InstructionList variables;
		std::map< std::string, spv::Id > registeredVariables;
	};
}

#endif
