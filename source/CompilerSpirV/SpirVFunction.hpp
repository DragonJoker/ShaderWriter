/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvFunction_H___
#define ___SDW_SpirvFunction_H___
#pragma once

#include "SpirVBlock.hpp"

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

		explicit Variable( ast::ShaderAllocatorBlock * alloc )
			: decorations{ ast::StlAllocatorT< spv::Id >{ alloc } }
		{
		}

		ast::var::VariablePtr var;
		IdList decorations;
	};

	using VariablePtr = std::shared_ptr< Variable >;
	using VariableArray = ast::Vector< VariablePtr >;

	struct VarUsage
	{
		explicit VarUsage( ast::ShaderAllocatorBlock * alloc )
			: use{ ast::StlAllocatorT< VariablePtr >{ alloc } }
		{
		}

		VariableArray use;
		VariablePtr set;
	};

	using VarUsageArray = ast::Vector< VarUsage >;
	using UsedVars = ast::Set< VariablePtr >;

	struct BlockStruct
	{
		explicit BlockStruct( ast::ShaderAllocatorBlock * alloc
			, BlockType ptype )
			: type{ ptype }
			, usages{ ast::StlAllocatorT< VarUsage >{ alloc } }
			, ownVars{ ast::StlAllocatorT< VariablePtr >{ alloc } }
			, allVars{ &ownVars }
		{
		}

		BlockType type{};
		VarUsageArray usages;
		VariableArray ownVars;
		VariableArray * allVars{};
	};

	using BlockStructPtr = std::unique_ptr< BlockStruct >;
	using BlockStructMap = ast::Map< uint32_t, BlockStructPtr >;

	using TypeMap = ast::Map< uint32_t, ast::type::TypePtr >;

	struct ModuleStruct
	{
		explicit ModuleStruct( ast::ShaderAllocatorBlock * alloc )
			: types{ ast::StlMapAllocatorT< uint32_t, ast::type::TypePtr >{ alloc } }
			, functionScopes{ ast::StlMapAllocatorT< uint32_t, BlockStructPtr >{ alloc } }
		{
		}

		TypeMap types;
		BlockStructPtr globalScope;
		BlockStructMap functionScopes;
	};

	using IdSet = ast::Set< spv::Id >;

	struct Parameter
	{
		spv::Id id;
		spv::Id type;
	};

	using ParameterList = ast::Vector< Parameter >;
	using BlockList = ast::Vector< Block >;

	struct ControlFlowGraph
	{
		explicit ControlFlowGraph( ast::ShaderAllocatorBlock * alloc )
			: blocks{ ast::StlAllocatorT< Block >{ alloc } }
		{
		}

		BlockList blocks;
	};

	struct Function
	{
		Function( Function const & rhs ) = delete;
		Function & operator=( Function const & rhs ) = delete;
		SDWSPIRV_API Function( Function && rhs )noexcept = default;
		SDWSPIRV_API Function & operator=( Function && rhs )noexcept = default;
		SDWSPIRV_API ~Function()noexcept = default;

		SDWSPIRV_API Function( ast::ShaderAllocatorBlock * alloc
			, DebugId id );
		SDWSPIRV_API static Function deserialize( ast::ShaderAllocatorBlock * alloc
			, InstructionList::iterator & buffer
			, InstructionList::iterator const & end );

		DebugId id{};
		ValueId debugTypeId{};
		// Serialisable.
		InstructionList declaration;
		ControlFlowGraph cfg;
		// Used during construction.
		InstructionList variables;
		InstructionList debugStart;
		Block promotedParams;
		ast::Map< std::string, VariableInfo, std::less<> > registeredVariables;
	};

	using FunctionList = ast::Vector< Function >;
}

#endif
