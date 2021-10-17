/*
See LICENSE file in root folder
*/
#include "SpirvSerialize.hpp"

namespace spirv
{
	namespace
	{
		template< typename T >
		void count( std::vector< T > const & values
			, size_t & result );

		template< typename T >
		void count( Optional< T > const & value
			, size_t & result );

		void count( spv::Id const & id
			, size_t & result )
		{
			++result;
		}

		void count( spirv::Op const & op
			, size_t & result )
		{
			++result;
		}

		void count( spirv::InstructionPtr const & instruction
			, size_t & result )
		{
			count( instruction->op, result );
			count( instruction->returnTypeId, result );
			count( instruction->resultId, result );
			count( instruction->operands, result );
			count( instruction->packedName, result );
		}

		void count( spirv::Block const & block
			, size_t & result )
		{
			count( block.instructions, result );
			count( block.blockEnd, result );
		}

		void count( spirv::ControlFlowGraph const & cfg
			, size_t & result )
		{
			count( cfg.blocks, result );
		}

		void count( spirv::Function const & function
			, size_t & result )
		{
			count( function.declaration, result );
			count( function.cfg, result );
		}

		size_t count( spirv::Module const & module )
		{
			size_t result{};
			count( module.header, result );
			count( module.capabilities, result );
			count( module.extensions, result );
			count( module.imports, result );
			count( module.memoryModel, result );
			count( module.entryPoint, result );
			count( module.executionModes, result );
			count( module.debug, result );
			count( module.decorations, result );
			count( module.globalDeclarations, result );
			count( module.functions, result );
			return result;
		}

		template< typename T >
		void count( std::vector< T > const & values
			, size_t & result )
		{
			for ( auto & value : values )
			{
				count( value, result );
			}
		}

		template< typename T >
		void count( Optional< T > const & value
			, size_t & result )
		{
			if ( bool( value ) )
			{
				count( value.value(), result );
			}
		}

		template< typename T >
		void serializeResult( std::vector< T > const & values
			, std::vector< uint32_t > & result );

		template< typename T >
		void serializeResult( Optional< T > const & value
			, std::vector< uint32_t > & result );

		void serializeResult( spv::Id const & id
			, std::vector< uint32_t > & result )
		{
			result.push_back( id );
		}

		void serializeResult( spirv::InstructionPtr const & instruction
			, std::vector< uint32_t > & result )
		{
			Instruction::serialize( result, *instruction );
		}

		void serializeResult( spirv::Block const & block
			, std::vector< uint32_t > & result )
		{
			serializeResult( block.instructions, result );
			serializeResult( block.blockEnd, result );
		}

		void serializeResult( spirv::ControlFlowGraph const & cfg
			, std::vector< uint32_t > & result )
		{
			serializeResult( cfg.blocks, result );
		}

		void serializeResult( spirv::Function const & function
			, std::vector< uint32_t > & result )
		{
			serializeResult( function.declaration, result );
			serializeResult( function.cfg, result );
		}

		void serializeResult( spirv::Module const & module
			, std::vector< uint32_t > & result )
		{
			serializeResult( module.header, result );
			serializeResult( module.capabilities, result );
			serializeResult( module.extensions, result );
			serializeResult( module.imports, result );
			serializeResult( module.memoryModel, result );
			serializeResult( module.entryPoint, result );
			serializeResult( module.executionModes, result );
			serializeResult( module.debug, result );
			serializeResult( module.decorations, result );
			serializeResult( module.globalDeclarations, result );
			serializeResult( module.functions, result );
		}

		template< typename T >
		void serializeResult( std::vector< T > const & values
			, std::vector< uint32_t > & result )
		{
			for ( auto & value : values )
			{
				serializeResult( value, result );
			}
		}

		template< typename T >
		void serializeResult( Optional< T > const & value
			, std::vector< uint32_t > & result )
		{
			if ( bool( value ) )
			{
				serializeResult( value.value(), result );
			}
		}
	}

	std::vector< uint32_t > serialize( spirv::Module const & module )
	{
		std::vector< uint32_t > result;
		auto size = count( module );
		result.reserve( size );
		serializeResult( module, result );
		return result;
	}
}
