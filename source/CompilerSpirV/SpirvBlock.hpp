/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvBlock_H___
#define ___SDW_SpirvBlock_H___
#pragma once

#include "SpirvInstruction.hpp"

namespace spirv
{
	struct VariableInfo
	{
		VariableInfo( ValueId pid = {}
			, bool pisAlias = false
			, bool pisParam = false
			, bool pisOutParam = false )
			: id{ pid }
			, isAlias{ pisAlias }
			, isParam{ pisParam }
			, isOutParam{ pisOutParam }
		{
		}

		bool needsStoreOnPromote()const;

		ValueId const * operator->()const
		{
			return &id;
		}

		ValueId id;
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
		SDWSPIRV_API Block( Block && rhs );
		SDWSPIRV_API Block & operator=( Block && rhs );
		SDWSPIRV_API explicit Block( ast::ShaderAllocatorBlock * alloc
			, spv::Id plabel = {} );

		SDWSPIRV_API static Block deserialize( ast::ShaderAllocatorBlock * alloc
			, InstructionPtr firstInstruction
			, InstructionList::iterator & buffer
			, InstructionList::iterator const & end );

		// Serialisable.
		spv::Id label{};
		InstructionList instructions;
		InstructionPtr blockEnd{};
		// Used during construction.
		UnorderedMap< ValueIdList, ValueId, ValueIdListHasher > accessChains;
		UnorderedMap< ValueIdList, ValueId, ValueIdListHasher > vectorShuffles;
		bool isInterrupted{};
	};
}

#endif
