/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvFunction.hpp"

namespace spirv
{
	Function::Function( ast::ShaderAllocatorBlock * alloc
		, ValueId pid )
		: id{ pid }
		, declaration{ ModuleAllocatorT< InstructionPtr >{ alloc } }
		, cfg{ alloc }
		, variables{ ModuleAllocatorT< InstructionPtr >{ alloc } }
		, promotedParams{ ModuleAllocatorT< InstructionPtr >{ alloc } }
		, registeredVariables{ ModuleMapAllocatorT< std::string, VariableInfo >{ alloc } }
	{
	}

	Function Function::deserialize( ast::ShaderAllocatorBlock * alloc
		, InstructionList::iterator & buffer
		, InstructionList::iterator const & end )
	{
		auto popValue = [&buffer]()
		{
			auto result = std::move( *buffer );
			++buffer;
			return result;
		};
		auto isDeclarationInstruction = []( spv::Op opCode )
		{
			return opCode == spv::OpFunction
				|| opCode == spv::OpFunctionParameter
				|| opCode == spv::OpVariable;
		};

		Function result{ alloc, ValueId{} };

		while ( buffer != end )
		{
			auto instruction = popValue();

			if ( isDeclarationInstruction( spv::Op( instruction->op.opData.opCode ) ) )
			{
				result.declaration.emplace_back( std::move( instruction ) );
			}
			else
			{
				result.cfg.blocks.emplace_back( Block::deserialize( alloc, std::move( instruction ), buffer, end ) );
			}
		}
		
		return result;
	}
}
