/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvBlock.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>

#include <algorithm>

namespace spirv
{
	//*************************************************************************

	size_t IdListHasher::operator()( IdList const & list )const
	{
		assert( !list.empty() );
		auto hash = std::hash< spv::Id >{}( list[0] );

		std::for_each( list.begin() + 1u
			, list.end()
			, [&hash]( spv::Id id )
			{
				ast::type::hashCombine( hash, id );
			} );

		return hash;
	}

	//*************************************************************************

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
			op = spv::Op( ( *buffer )->op.opCode );

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
