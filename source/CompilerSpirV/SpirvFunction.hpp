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
		ValueId varId;
		ValueId loadedId;
	};

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

		Variable( ast::ShaderAllocatorBlock * alloc )
			: decorations{ ModuleAllocatorT< spv::Id >{ alloc } }
		{
		}

		ast::var::VariablePtr var;
		IdList decorations;
	};

	using VariablePtr = std::shared_ptr< Variable >;
	using VariableArray = Vector< VariablePtr >;

	struct VarUsage
	{
		VarUsage( ast::ShaderAllocatorBlock * alloc )
			: use{ ModuleAllocatorT< VariablePtr >{ alloc } }
		{
		}

		VariableArray use;
		VariablePtr set;
	};

	using VarUsageArray = Vector< VarUsage >;
	using UsedVars = Set< VariablePtr >;

	struct BlockStruct
	{
		explicit BlockStruct( ast::ShaderAllocatorBlock * alloc
			, BlockType ptype )
			: type{ ptype }
			, usages{ ModuleAllocatorT< VarUsage >{ alloc } }
			, ownVars{ ModuleAllocatorT< VariablePtr >{ alloc } }
			, allVars{ &ownVars }
		{
		}

		BlockType type{};
		VarUsageArray usages;
		VariableArray ownVars;
		VariableArray * allVars{};
	};

	using BlockStructPtr = std::unique_ptr< BlockStruct >;
	using BlockStructMap = Map< uint32_t, BlockStructPtr >;

	using TypeMap = Map< uint32_t, ast::type::TypePtr >;

	struct ModuleStruct
	{
		ModuleStruct( ast::ShaderAllocatorBlock * alloc )
			: types{ ModuleMapAllocatorT< uint32_t, ast::type::TypePtr >{ alloc } }
			, functionScopes{ ModuleMapAllocatorT< uint32_t, BlockStructPtr >{ alloc } }
		{
		}

		TypeMap types;
		BlockStructPtr globalScope;
		BlockStructMap functionScopes;
	};

	using IdSet = Set< spv::Id >;

	struct Parameter
	{
		spv::Id id;
		spv::Id type;
	};

	using ParameterList = Vector< Parameter >;
	using BlockList = Vector< Block >;

	struct ControlFlowGraph
	{
		ControlFlowGraph( ast::ShaderAllocatorBlock * alloc )
			: blocks{ ModuleAllocatorT< Block >{ alloc } }
		{
		}

		BlockList blocks;
	};

	struct Function
	{
		Function( Function const & rhs ) = delete;
		Function & operator=( Function const & rhs ) = delete;
		SDWSPIRV_API Function( Function && rhs ) = default;
		SDWSPIRV_API Function & operator=( Function && rhs ) = default;

		SDWSPIRV_API Function( ast::ShaderAllocatorBlock * alloc
			, DebugId id );
		SDWSPIRV_API static Function deserialize( ast::ShaderAllocatorBlock * alloc
			, InstructionList::iterator & buffer
			, InstructionList::iterator const & end );

		DebugId id{};
		ValueId debugDeclId{};
		ValueId debugNameId{};
		ValueId debugTypeId{};
		ValueId debugLineId{};
		ValueId debugColumnId{};
		ValueId debugFlagId{};
		// Serialisable.
		InstructionList declaration;
		ControlFlowGraph cfg;
		// Used during construction.
		InstructionList variables;
		InstructionList debugStart;
		InstructionList promotedParams;
		Map< std::string, VariableInfo > registeredVariables;
	};

	using FunctionList = Vector< Function >;
}

#endif
