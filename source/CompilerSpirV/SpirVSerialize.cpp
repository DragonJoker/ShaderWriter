/*
See LICENSE file in root folder
*/
#include "SpirVSerialize.hpp"

namespace spirv
{
	namespace serlz
	{
		static void count( FunctionList const & values
			, size_t & result );
		static void count( BlockList const & values
			, size_t & result );
		static void count( InstructionList const & values
			, size_t & result );
		static void count( IdList const & values
			, size_t & result );

		template< typename T >
		static void count( Optional< T > const & value
			, size_t & result );

		static void count( spv::Id const &
			, size_t & result )
		{
			++result;
		}

		static void count( spirv::Op const &
			, size_t & result )
		{
			++result;
		}

		static void count( spirv::Instruction const & instruction
			, size_t & result )
		{
			count( instruction.op, result );
			count( instruction.returnTypeId, result );
			count( instruction.resultId, result );
			count( instruction.operands, result );
			count( instruction.packedName, result );
		}

		static void count( spirv::Block const & block
			, size_t & result )
		{
			count( block.instructions, result );
			count( *block.blockEnd, result );
		}

		static void count( spirv::ControlFlowGraph const & cfg
			, size_t & result )
		{
			count( cfg.blocks, result );
		}

		static void count( spirv::Function const & function
			, size_t & result )
		{
			count( function.declaration, result );
			count( function.cfg, result );
		}

		static size_t count( spirv::Module const & shaderModule )
		{
			size_t result{};
			count( shaderModule.header, result );
			count( shaderModule.capabilities, result );
			count( shaderModule.extensions, result );
			count( shaderModule.imports, result );
			count( *shaderModule.memoryModel, result );
			count( *shaderModule.entryPoint, result );
			count( shaderModule.executionModes, result );
			count( shaderModule.getDebugStringsDeclarations(), result );
			count( shaderModule.getDebugNamesDeclarations(), result );
			count( shaderModule.decorations, result );
			count( shaderModule.constantsTypes, result );
			count( shaderModule.globalDeclarations, result );
			count( shaderModule.getNonSemanticDebugDeclarations(), result );
			count( shaderModule.functions, result );
			return result;
		}

		static void count( BlockList const & values
			, size_t & result )
		{
			for ( auto const & value : values )
			{
				count( value, result );
			}
		}

		static void count( FunctionList const & values
			, size_t & result )
		{
			for ( auto const & value : values )
			{
				count( value, result );
			}
		}

		static void count( InstructionList const & values
			, size_t & result )
		{
			for ( auto const & value : values )
			{
				count( *value, result );
			}
		}

		static void count( IdList const & values
			, size_t & result )
		{
			for ( auto const & value : values )
			{
				count( value, result );
			}
		}

		template< typename T >
		static void count( Optional< T > const & value
			, size_t & result )
		{
			if ( bool( value ) )
			{
				count( value.value(), result );
			}
		}

		static void serializeResult( FunctionList const & values
			, UInt32List & result );
		static void serializeResult( BlockList const & values
			, UInt32List & result );
		static void serializeResult( InstructionList const & values
			, UInt32List & result );
		static void serializeResult( IdList const & values
			, UInt32List & result );

		template< typename T >
		static void serializeResult( Optional< T > const & value
			, UInt32List & result );

		static void serializeResult( spv::Id const & id
			, UInt32List & result )
		{
			result.push_back( id );
		}

		static void serializeResult( spirv::Instruction const & instruction
			, UInt32List & result )
		{
			Instruction::serialize( result, instruction );
		}

		static void serializeResult( spirv::Block const & block
			, UInt32List & result )
		{
			serializeResult( block.instructions, result );
			serializeResult( *block.blockEnd, result );
		}

		static void serializeResult( spirv::ControlFlowGraph const & cfg
			, UInt32List & result )
		{
			serializeResult( cfg.blocks, result );
		}

		static void serializeResult( spirv::Function const & function
			, UInt32List & result )
		{
			serializeResult( function.declaration, result );
			serializeResult( function.cfg, result );
		}

		static void serializeResult( spirv::Module const & shaderModule
			, UInt32List & result )
		{
			serializeResult( shaderModule.header, result );
			serializeResult( shaderModule.capabilities, result );
			serializeResult( shaderModule.extensions, result );
			serializeResult( shaderModule.imports, result );
			serializeResult( *shaderModule.memoryModel, result );
			serializeResult( *shaderModule.entryPoint, result );
			serializeResult( shaderModule.executionModes, result );
			serializeResult( shaderModule.getDebugStringsDeclarations(), result );
			serializeResult( shaderModule.getDebugNamesDeclarations(), result );
			serializeResult( shaderModule.decorations, result );
			serializeResult( shaderModule.constantsTypes, result );
			serializeResult( shaderModule.globalDeclarations, result );
			serializeResult( shaderModule.getNonSemanticDebugDeclarations(), result );
			serializeResult( shaderModule.functions, result );
		}

		static void serializeResult( FunctionList const & values
			, UInt32List & result )
		{
			for ( auto & value : values )
			{
				serializeResult( value, result );
			}
		}

		static void serializeResult( BlockList const & values
			, UInt32List & result )
		{
			for ( auto & value : values )
			{
				serializeResult( value, result );
			}
		}

		static void serializeResult( InstructionList const & values
			, UInt32List & result )
		{
			for ( auto & value : values )
			{
				serializeResult( *value, result );
			}
		}

		static void serializeResult( IdList const & values
			, UInt32List & result )
		{
			for ( auto & value : values )
			{
				serializeResult( value, result );
			}
		}

		template< typename T >
		static void serializeResult( Optional< T > const & value
			, UInt32List & result )
		{
			if ( bool( value ) )
			{
				serializeResult( value.value(), result );
			}
		}
	}

	UInt32List serialize( spirv::Module const & shaderModule )
	{
		UInt32List result{ shaderModule.allocator };
		auto size = serlz::count( shaderModule );
		result.reserve( size );
		serlz::serializeResult( shaderModule, result );
		return result;
	}
}
