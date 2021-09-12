/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvBlock_H___
#define ___SDW_SpirvBlock_H___
#pragma once

#include "SpirvInstruction.hpp"

namespace spirv
{
	struct IdListHasher
	{
		SDWSPIRV_API size_t operator()( IdList const & list )const;
	};

	struct VariableInfo
	{
		spv::Id id{ 0u };
		bool lvalue{ false };
		bool rvalue{ false };
	};

	struct Block
	{
		Block( Block const & rhs ) = delete;
		Block & operator=( Block const & rhs ) = delete;
		SDWSPIRV_API Block( Block && rhs ) = default;
		SDWSPIRV_API Block & operator=( Block && rhs ) = default;
		SDWSPIRV_API explicit Block( spv::Id plabel = {} );

		SDWSPIRV_API static Block deserialize( InstructionPtr firstInstruction
			, InstructionListIt & buffer
			, InstructionListIt const & end );

		// Serialisable.
		spv::Id label{};
		InstructionList instructions{};
		InstructionPtr blockEnd{};
		// Used during construction.
		std::unordered_map< IdList, spv::Id, IdListHasher > accessChains{};
		std::unordered_map< IdList, spv::Id, IdListHasher > vectorShuffles{};
		bool isInterrupted{};
	};
}

#endif
