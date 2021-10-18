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
		SDWSPIRV_API explicit Block( spv::Id plabel = {} );

		SDWSPIRV_API static Block deserialize( InstructionPtr firstInstruction
			, InstructionListIt & buffer
			, InstructionListIt const & end );

		// Serialisable.
		spv::Id label{};
		InstructionList instructions{};
		InstructionPtr blockEnd{};
		// Used during construction.
		std::unordered_map< ValueIdList, ValueId, ValueIdListHasher > accessChains{};
		std::unordered_map< ValueIdList, ValueId, ValueIdListHasher > vectorShuffles{};
		bool isInterrupted{};
	};
}

#endif
