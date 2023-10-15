/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVBlock.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>
#include <ShaderAST/Type/TypePointer.hpp>

#include <algorithm>

namespace spirv
{
	//*************************************************************************

	bool VariableInfo::needsStoreOnPromote()const
	{
		return isAlias
			|| ( isParam
				&& !isOutParam
				&& !isOpaqueType( id->type )
				&& ( !id.isPointer() || ( id.getStorage() != ast::type::Storage::eFunction ) ) );
	}

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

	Block::Block( ast::ShaderAllocatorBlock * alloc
		, spv::Id plabel )
		: label{ plabel }
		, instructions{ alloc }
		, accessChains{ ast::StlMapAllocatorT< ValueIdList, ValueId >{ alloc } }
		, vectorShuffles{ ast::StlMapAllocatorT< ValueIdList, ValueId >{ alloc } }
	{
	}

	Block Block::deserialize( ast::ShaderAllocatorBlock * alloc
		, InstructionPtr firstInstruction
		, InstructionList::iterator & buffer
		, InstructionList::iterator const & end )
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
		Block result{ alloc };
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
