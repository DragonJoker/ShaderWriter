/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvBlock.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>

#include <algorithm>

namespace spirv
{
	//*************************************************************************

	Block::Block( Block && rhs )
		: label{ std::move( rhs.label ) }
		, instructions{ std::move( rhs.instructions ) }
		, blockEnd{ std::move( rhs.blockEnd ) }
		, accessChains{ std::move( rhs.accessChains ) }
		, vectorShuffles{ std::move( rhs.vectorShuffles ) }
		, isInterrupted{ std::move( rhs.isInterrupted ) }
	{
		rhs.label = {};
		rhs.isInterrupted = {};
	}

	Block & Block::operator=( Block && rhs )
	{
		label = std::move( rhs.label );
		instructions = std::move( rhs.instructions );
		blockEnd = std::move( rhs.blockEnd );
		accessChains = std::move( rhs.accessChains );
		vectorShuffles = std::move( rhs.vectorShuffles );
		isInterrupted = std::move( rhs.isInterrupted );

		rhs.label = {};
		rhs.isInterrupted = {};

		return *this;
	}

	Block::Block( spv::Id plabel )
		: label{ plabel }
	{
	}

	Block Block::deserialize( InstructionPtr firstInstruction
		, InstructionListIt & buffer
		, InstructionListIt const & end )
	{
		auto popValue = [&buffer]()
		{
			auto result = std::move( *buffer );
			++buffer;
			return result;
		};
		auto isLastBlockInstruction = []( spv::Op opCode )
		{
			return opCode == spv::OpBranch
				|| opCode == spv::OpBranchConditional
				|| opCode == spv::OpFunctionEnd;
		};

		spv::Op op = spv::OpNop;
		Block result;
		result.label = firstInstruction->resultId.value();
		result.instructions.emplace_back( std::move( firstInstruction ) );

		while ( buffer != end
			&& !isLastBlockInstruction( op ) )
		{
			op = spv::Op( ( *buffer )->op.opData.opCode );

			if ( !isLastBlockInstruction( op ) )
			{
				result.instructions.emplace_back( popValue() );
			}
		}

		if ( buffer != end )
		{
			result.blockEnd = popValue();
		}

		return result;
	}

	//*************************************************************************
}
