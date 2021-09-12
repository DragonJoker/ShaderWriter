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
		Variable( ast::var::VariablePtr pvar
			, IdList pdecorations )
			: var{ std::move( pvar ) }
			, decorations{ std::move( pdecorations ) }
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
		BlockStruct( BlockType ptype )
			: type{ ptype }
			, allVars{ &ownVars }
		{
		}

		BlockType type{};
		VarUsageArray usages{};
		VariableArray ownVars{};
		VariableArray * allVars{};
	};

	using BlockStructPtr = std::unique_ptr< BlockStruct >;
	using BlockStructMap = std::map< uint32_t, BlockStructPtr >;

	using TypeMap = std::map< uint32_t, ast::type::TypePtr >;

	struct ModuleStruct
	{
		TypeMap types;
		BlockStructPtr globalScope;
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
		Function( Function const & rhs ) = delete;
		Function & operator=( Function const & rhs ) = delete;
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
