/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvBlock_H___
#define ___SDW_SpirvBlock_H___
#pragma once

#include "SpirVInstruction.hpp"

#include <GlslCommon/GlslStatementsHelpers.hpp>

namespace spirv
{
	namespace debug
	{
		class NonSemanticDebug;
	}

	class ModuleTypes;

	struct VariableInfo
	{
		explicit VariableInfo( DebugId pid = DebugId{}
			, bool pisAlias = false
			, bool pisParam = false
			, bool pisOutParam = false )
			: id{ std::move( pid ) }
			, isAlias{ pisAlias }
			, isParam{ pisParam }
			, isOutParam{ pisOutParam }
		{
		}

		bool needsStoreOnPromote()const;

		DebugId const * operator->()const
		{
			return &id;
		}

		DebugId id;
		bool isAlias;
		bool isParam;
		bool isOutParam;
		bool lvalue{ false };
		bool rvalue{ false };
	};

	struct Block
	{
		Block( Block const & rhs ) = delete;
		Block & operator=( Block const & rhs ) = delete;
		SDWSPIRV_API Block( Block && rhs )noexcept;
		SDWSPIRV_API Block & operator=( Block && rhs )noexcept;
		SDWSPIRV_API ~Block()noexcept = default;

		SDWSPIRV_API explicit Block( ast::ShaderAllocatorBlock * alloc
			, spv::Id plabel = {} );

		SDWSPIRV_API DebugId loadVariable( DebugId const & variable
			, Module & shaderModule
			, ModuleTypes & types
			, glsl::Statement const * debugStatement
			, glsl::RangeInfo const & columns
			, debug::NonSemanticDebug & nonSemanticDebug );
		SDWSPIRV_API void storeVariable( DebugId const & variable
			, DebugId value
			, Module & shaderModule
			, ModuleTypes & types
			, glsl::Statement const * debugStatement
			, glsl::RangeInfo const & columns
			, debug::NonSemanticDebug & nonSemanticDebug );
		SDWSPIRV_API void modifyVariable( DebugId const & variable );
		SDWSPIRV_API DebugId writeAccessChain( ValueIdList const & accessChain
			, ast::expr::Expr const & expr
			, Module & shaderModule
			, glsl::Statement const * debugStatement );
		SDWSPIRV_API void writeAccessChain( DebugId const & accessChainId
			, DebugId const & pointerTypeId
			, ValueIdList const & accessChainOperands
			, Module & shaderModule );

		SDWSPIRV_API static Block deserialize( ast::ShaderAllocatorBlock * alloc
			, InstructionPtr firstInstruction
			, InstructionList::iterator & buffer
			, InstructionList::iterator const & end );

		// Serialisable.
		spv::Id label{};
		InstructionList instructions;
		InstructionPtr blockEnd{};
		// Used during construction.
		ast::ShaderAllocatorBlock * allocator;
		ast::Map< DebugId, DebugId > variables;
		ast::Vector< std::pair< DebugIdList, DebugId > > accessChains;
		bool isInterrupted{};
	};
}

#endif
