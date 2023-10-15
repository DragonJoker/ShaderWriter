/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVFunction.hpp"

namespace spirv
{
	Function::Function( ast::ShaderAllocatorBlock * alloc
		, DebugId pid )
		: id{ pid }
		, declaration{ ast::StlAllocatorT< InstructionPtr >{ alloc } }
		, cfg{ alloc }
		, variables{ ast::StlAllocatorT< InstructionPtr >{ alloc } }
		, debugStart{ ast::StlAllocatorT< InstructionPtr >{ alloc } }
		, promotedParams{ ast::StlAllocatorT< InstructionPtr >{ alloc } }
		, registeredVariables{ ast::StlMapAllocatorT< std::string, VariableInfo >{ alloc } }
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

		Function result{ alloc, DebugId{} };

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
