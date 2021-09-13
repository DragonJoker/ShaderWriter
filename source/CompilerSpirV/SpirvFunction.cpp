/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvFunction.hpp"

namespace spirv
{
	Function Function::deserialize( InstructionListIt & buffer
		, InstructionListIt const & end )
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

		Function result;

		while ( buffer != end )
		{
			auto instruction = popValue();

			if ( isDeclarationInstruction( spv::Op( instruction->op.opData.opCode ) ) )
			{
				result.declaration.emplace_back( std::move( instruction ) );
			}
			else
			{
				result.cfg.blocks.emplace_back( Block::deserialize( std::move( instruction ), buffer, end ) );
			}
		}
		
		return result;
	}
}
