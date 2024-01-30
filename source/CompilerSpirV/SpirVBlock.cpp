/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVBlock.hpp"
#include "CompilerSpirV/SpirVHelpers.hpp"
#include "CompilerSpirV/SpirVModule.hpp"
#include "CompilerSpirV/SpirVModuleTypes.hpp"
#include "CompilerSpirV/SpirVNonSemanticDebug.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>
#include <ShaderAST/Type/TypePointer.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

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

	Block::Block( Block && rhs )noexcept
		: label{ rhs.label }
		, instructions{ std::move( rhs.instructions ) }
		, blockEnd{ std::move( rhs.blockEnd ) }
		, allocator{ rhs.allocator }
		, variables{ std::move( rhs.variables ) }
		, accessChains{ std::move( rhs.accessChains ) }
		, isInterrupted{ rhs.isInterrupted }
	{
		rhs.label = {};
		rhs.isInterrupted = {};
		rhs.allocator = {};
	}

	Block & Block::operator=( Block && rhs )noexcept
	{
		label = rhs.label;
		instructions = std::move( rhs.instructions );
		blockEnd = std::move( rhs.blockEnd );
		allocator = rhs.allocator;
		variables = std::move( rhs.variables );
		accessChains = std::move( rhs.accessChains );
		isInterrupted = rhs.isInterrupted;

		rhs.label = {};
		rhs.isInterrupted = {};
		rhs.allocator = {};

		return *this;
	}

	Block::Block( ast::ShaderAllocatorBlock * alloc
		, spv::Id plabel )
		: label{ plabel }
		, instructions{ alloc }
		, allocator{ alloc }
		, variables{ ast::StlMapAllocatorT< DebugId, DebugId >{ alloc } }
		, accessChains{ ast::StlPairAllocatorT< DebugIdList, DebugId >{ alloc } }
	{
	}

	DebugId Block::loadVariable( DebugId const & variableId
		, Module & shaderModule
		, ModuleTypes & types
		, glsl::Statement const * debugStatement
		, glsl::RangeInfo const & columns
		, debug::NonSemanticDebug & nonSemanticDebug )
	{
		auto [it, res] = variables.try_emplace( variableId, variableId );

		if ( variableId.isPointer() )
		{
			if ( res )
			{
				auto type = static_cast< ast::type::Pointer const & >( *variableId->type ).getPointerType();
				nonSemanticDebug.makeLineExtension( instructions, debugStatement, columns );

				if ( !hasRuntimeArray( type ) )
				{
					auto typeId = types.registerType( type, nullptr );
					DebugId resultId{ shaderModule.getIntermediateResult(), typeId->type };

					if ( variableId.getStorage() == ast::type::Storage::ePhysicalStorageBuffer )
					{
						// Loading from PhysicalStorageBuffer needs to set the alignment
						auto structType = getStructType( type );
						instructions.push_back( makeInstruction< LoadInstruction >( shaderModule.getNameCache()
							, typeId.id
							, resultId.id
							, makeOperands( allocator
								, variableId
								, ValueId{ spv::Id( spv::MemoryAccessAlignedMask ) }
								, ValueId{ ast::type::getAlignment( type
									, ( structType
										? structType->getMemoryLayout()
										: ast::type::MemoryLayout::eScalar ) ) } ) ) );
					}
					else
					{
						instructions.push_back( makeInstruction< LoadInstruction >( shaderModule.getNameCache()
							, typeId.id
							, resultId.id
							, makeOperands( allocator
								, variableId
								, ValueId{ spv::Id( spv::MemoryAccessMaskNone ) } ) ) );
					}

					nonSemanticDebug.makeValueInstruction( instructions, resultId, variableId );
					it->second = resultId;
					return resultId;
				}
			}
		}

		return it->second;
	}

	void Block::storeVariable( DebugId const & variable
		, DebugId value
		, Module & shaderModule
		, ModuleTypes & types
		, glsl::Statement const * debugStatement
		, glsl::RangeInfo const & columns
		, debug::NonSemanticDebug & nonSemanticDebug )
	{
		assert( variable.isPointer() );

		if ( value.isPointer() )
		{
			value = loadVariable( value, shaderModule, types, debugStatement, columns, nonSemanticDebug );
		}

		nonSemanticDebug.makeLineExtension( instructions, debugStatement, columns );
		instructions.push_back( makeInstruction< StoreInstruction >( shaderModule.getNameCache()
			, variable.id
			, value.id ) );
		nonSemanticDebug.makeValueInstruction( instructions, variable, value );

		modifyVariable( variable );
	}

	void Block::modifyVariable( DebugId const & variable )
	{
		// Remove the variable from the cache.
		if ( auto it = variables.find( variable );
			it != variables.end() )
		{
			variables.erase( it );
		}

		DebugIdList work{ allocator };
		auto accit = accessChains.begin();

		while ( accit != accessChains.end() )
		{
			if ( accit->first.front() == variable // The access chains for which the variable is the source.
				|| accit->second == variable ) // The access chain that represents this variable.
			{
				work.emplace_back( accit->first.front() );
				accit = accessChains.erase( accit );
			}
			else
			{
				++accit;
			}
		}

		for ( auto const & id : work )
		{
			modifyVariable( id );
		}
	}

	DebugId Block::writeAccessChain( ValueIdList const & accessChain
		, ast::expr::Expr const & expr
		, Module & shaderModule
		, glsl::Statement const * debugStatement )
	{
		auto debugAccessChain = toTypeId( accessChain );
		auto it = std::find_if( accessChains.begin()
			, accessChains.end()
			, [&debugAccessChain]( std::pair< DebugIdList, DebugId > const & lookup )
			{
				static DebugIdListHasher const hasher{};
				return hasher( debugAccessChain ) == hasher( lookup.first );
			} );

		if ( it == accessChains.end() )
		{
			spv::StorageClass storageClass{};

			if ( accessChain.front().isPointer() )
			{
				storageClass = convert( accessChain.front().getStorage() );
			}
			else
			{
				auto var = ast::findIdentifier( expr )->getVariable();
				storageClass = getStorageClass( shaderModule.getVersion(), var );
			}

			// Register the type pointed to.
			auto rawTypeId = shaderModule.registerType( expr.getType(), nullptr );
			// Register the pointer to the type.
			auto pointerTypeId = shaderModule.registerPointerType( rawTypeId
				, storageClass );
			// Reserve the ID for the result.
			DebugId resultId{ shaderModule.getIntermediateResult(), pointerTypeId->type };
			// Write access chain => resultId = pointerTypeId( outer.members + index ).
			writeAccessChain( resultId, pointerTypeId, accessChain, shaderModule );
			it = std::next( accessChains.begin(), ptrdiff_t( accessChains.size() - 1u ) );
			shaderModule.declareDebugAccessChain( instructions
				, expr
				, debugStatement
				, resultId );
		}

		return it->second;
	}

	void Block::writeAccessChain( DebugId const & accessChainId
		, DebugId const & pointerTypeId
		, ValueIdList const & accessChainOperands
		, Module & shaderModule )
	{
		auto debugAccessChain = toTypeId( accessChainOperands );
		instructions.emplace_back( makeInstruction< AccessChainInstruction >( shaderModule.getNameCache()
			, pointerTypeId.id
			, accessChainId.id
			, accessChainOperands ) );
		accessChains.emplace_back( debugAccessChain, accessChainId );
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
				|| opCode == spv::OpFunctionEnd
				|| opCode == spv::OpReturn
				|| opCode == spv::OpReturnValue
				|| opCode == spv::OpEmitMeshTasksEXT
				|| opCode == spv::OpTerminateInvocation
				|| opCode == spv::OpIgnoreIntersectionKHR
				|| opCode == spv::OpIgnoreIntersectionNV
				|| opCode == spv::OpTerminateRayKHR
				|| opCode == spv::OpTerminateRayNV
				|| opCode == spv::OpKill;
		};

		spv::Op op = spv::OpNop;
		Block result{ alloc };
		result.label = firstInstruction->resultId.value();
		result.instructions.emplace_back( std::move( firstInstruction ) );

		while ( buffer != end
			&& !isLastBlockInstruction( op ) )
		{
			op = spv::Op( ( *buffer )->op.getOpData().opCode);

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
