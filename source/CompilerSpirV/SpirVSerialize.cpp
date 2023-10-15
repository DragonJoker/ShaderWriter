/*
See LICENSE file in root folder
*/
#include "SpirVSerialize.hpp"

namespace spirv
{
	namespace serlz
	{
		template< typename T >
		static void count( ast::Vector< T > const & values
			, size_t & result );

		template< typename T >
		static void count( Optional< T > const & value
			, size_t & result );

		static void count( spv::Id const & id
			, size_t & result )
		{
			++result;
		}

		static void count( spirv::Op const & op
			, size_t & result )
		{
			++result;
		}

		static void count( spirv::InstructionPtr const & instruction
			, size_t & result )
		{
			count( instruction->op, result );
			count( instruction->returnTypeId, result );
			count( instruction->resultId, result );
			count( instruction->operands, result );
			count( instruction->packedName, result );
		}

		static void count( spirv::Block const & block
			, size_t & result )
		{
			count( block.instructions, result );
			count( block.blockEnd, result );
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

		static size_t count( spirv::Module const & module )
		{
			size_t result{};
			count( module.header, result );
			count( module.capabilities, result );
			count( module.extensions, result );
			count( module.imports, result );
			count( module.memoryModel, result );
			count( module.entryPoint, result );
			count( module.executionModes, result );
			count( module.getDebugStringsDeclarations(), result );
			count( module.getDebugNamesDeclarations(), result );
			count( module.decorations, result );
			count( module.constantsTypes, result );
			count( module.globalDeclarations, result );
			count( module.getNonSemanticDebugDeclarations(), result );
			count( module.functions, result );
			return result;
		}

		template< typename T >
		static void count( ast::Vector< T > const & values
			, size_t & result )
		{
			for ( auto & value : values )
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

		template< typename T >
		static void serializeResult( ast::Vector< T > const & values
			, UInt32List & result );

		template< typename T >
		static void serializeResult( Optional< T > const & value
			, UInt32List & result );

		static void serializeResult( spv::Id const & id
			, UInt32List & result )
		{
			result.push_back( id );
		}

		static void serializeResult( spirv::InstructionPtr const & instruction
			, UInt32List & result )
		{
			Instruction::serialize( result, *instruction );
		}

		static void serializeResult( spirv::Block const & block
			, UInt32List & result )
		{
			serializeResult( block.instructions, result );
			serializeResult( block.blockEnd, result );
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

		static void serializeResult( spirv::Module const & module
			, UInt32List & result )
		{
			serializeResult( module.header, result );
			serializeResult( module.capabilities, result );
			serializeResult( module.extensions, result );
			serializeResult( module.imports, result );
			serializeResult( module.memoryModel, result );
			serializeResult( module.entryPoint, result );
			serializeResult( module.executionModes, result );
			serializeResult( module.getDebugStringsDeclarations(), result );
			serializeResult( module.getDebugNamesDeclarations(), result );
			serializeResult( module.decorations, result );
			serializeResult( module.constantsTypes, result );
			serializeResult( module.globalDeclarations, result );
			serializeResult( module.getNonSemanticDebugDeclarations(), result );
			serializeResult( module.functions, result );
		}

		template< typename T >
		static void serializeResult( ast::Vector< T > const & values
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

	UInt32List serialize( spirv::Module const & module )
	{
		UInt32List result{ module.allocator };
		auto size = serlz::count( module );
		result.reserve( size );
		serlz::serializeResult( module, result );
		return result;
	}
}
