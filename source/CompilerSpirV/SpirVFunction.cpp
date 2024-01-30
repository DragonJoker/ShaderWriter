/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVFunction.hpp"

namespace spirv
{
	Function::Function( ast::ShaderAllocatorBlock * alloc
		, DebugId pid )
		: id{ std::move( pid ) }
		, declaration{ ast::StlAllocatorT< InstructionPtr >{ alloc } }
		, cfg{ alloc }
		, variables{ ast::StlAllocatorT< InstructionPtr >{ alloc } }
		, debugStart{ ast::StlAllocatorT< InstructionPtr >{ alloc } }
		, promotedParams{ alloc }
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

			if ( isDeclarationInstruction( spv::Op( instruction->op.getOpData().opCode ) ) )
			{
				result.declaration.emplace_back( std::move( instruction ) );
			}
			else if ( instruction->op.getOpData().opCode == spv::OpFunctionEnd )
			{
				result.cfg.blocks.back().instructions.push_back( std::move( result.cfg.blocks.back().blockEnd ) );
				result.cfg.blocks.back().blockEnd = std::move( instruction );
				break;
			}
			else
			{
				result.cfg.blocks.emplace_back( Block::deserialize( alloc, std::move( instruction ), buffer, end ) );
			}
		}
		
		return result;
	}
}
