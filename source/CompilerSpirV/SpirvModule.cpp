/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvModule.hpp"

#include "SpirvDebugHelpers.hpp"
#include "SpirvHelpers.hpp"
#include "SpirvSerialize.hpp"
#include "SpirvWrite.hpp"

#include "spirv/NonSemantic.Shader.DebugInfo.100.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#include <algorithm>

#define SDW_Spirv_IntermediatesPerBlock 0

namespace spirv
{
	//*************************************************************************

	namespace module
	{
		static ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::TypePtr qualified );

		static ast::type::StructPtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Struct const & qualified )
		{
			auto result = typesCache.getStruct( qualified.getMemoryLayout(), qualified.getName() );
			assert( result->empty() || ( result->size() == qualified.size() ) );

			if ( result->empty() && !qualified.empty() )
			{
				for ( auto & member : qualified )
				{
					auto type = getUnqualifiedType( typesCache, member.type );

					if ( type->getKind() == ast::type::Kind::eArray )
					{
						result->declMember( member.name
							, std::static_pointer_cast< ast::type::Array >( type ) );
					}
					else if ( type->getKind() == ast::type::Kind::eStruct
						|| type->getKind() == ast::type::Kind::eRayDesc )
					{
						result->declMember( member.name
							, std::static_pointer_cast< ast::type::Struct >( type ) );
					}
					else
					{
						result->declMember( member.name
							, type );
					}
				}
			}

			return result;
		}

		static ast::type::ArrayPtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Array const & qualified )
		{
			return typesCache.getArray( getUnqualifiedType( typesCache, qualified.getType() ), qualified.getArraySize() );
		}

		static ast::type::SamplerPtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Sampler const & qualified )
		{
			return typesCache.getSampler( qualified.isComparison() );
		}

		static ast::type::CombinedImagePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::CombinedImage const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return typesCache.getCombinedImage( config, qualified.isComparison() );
		}

		static ast::type::SampledImagePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::SampledImage const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return typesCache.getSampledImage( config, qualified.getDepth() );
		}

		static ast::type::ImagePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Image const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return typesCache.getImage( config );
		}

		static ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Type const & qualified )
		{
			ast::type::TypePtr result;

			if ( qualified.getRawKind() == ast::type::Kind::eArray )
			{
				result = getUnqualifiedType( typesCache, static_cast< ast::type::Array const & >( qualified ) );
			}
			else if ( qualified.getRawKind() == ast::type::Kind::eStruct
				|| qualified.getRawKind() == ast::type::Kind::eRayDesc )
			{
				result = getUnqualifiedType( typesCache, static_cast< ast::type::Struct const & >( qualified ) );
			}
			else if ( qualified.getRawKind() == ast::type::Kind::eImage )
			{
				result = getUnqualifiedType( typesCache, static_cast< ast::type::Image const & >( qualified ) );
			}
			else if ( qualified.getRawKind() == ast::type::Kind::eCombinedImage )
			{
				result = getUnqualifiedType( typesCache, static_cast< ast::type::CombinedImage const & >( qualified ) );
			}
			else if ( qualified.getRawKind() == ast::type::Kind::eSampledImage )
			{
				result = getUnqualifiedType( typesCache, static_cast< ast::type::SampledImage const & >( qualified ) );
			}
			else if ( qualified.getRawKind() == ast::type::Kind::eSampler )
			{
				result = getUnqualifiedType( typesCache, static_cast< ast::type::Sampler const & >( qualified ) );
			}
			else if ( qualified.isMember() )
			{
				result = typesCache.getBasicType( qualified.getKind() );
			}

			return result;
		}

		static ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::TypePtr qualified )
		{
			ast::type::TypePtr result = getUnqualifiedType( typesCache, *qualified );
			return result
				? result
				: qualified;
		}

		static void writeArrayStride( Module & module
			, ast::type::TypePtr elementType
			, ValueId typeId
			, uint32_t arrayStride )
		{
			auto kind = getNonArrayKind( elementType );

			if ( kind != ast::type::Kind::eImage
				&& kind != ast::type::Kind::eCombinedImage
				&& kind != ast::type::Kind::eSampler
				&& kind != ast::type::Kind::eSampledImage )
			{
				if ( !arrayStride )
				{
					arrayStride = ast::type::getSize( elementType, ast::type::MemoryLayout::eStd140 );
				}

				module.decorate( typeId
					, makeIdList( module.allocator
						, uint32_t( spv::DecorationArrayStride )
						, arrayStride ) );
			}
		}

		static Map< std::string, VariableInfo >::iterator addVariable( Map< std::string, Vector< uint32_t > > & nameCache
			, ValueId varTypeId
			, ValueId varId
			, std::string name
			, ValueId initialiser
			, Map< std::string, VariableInfo > & variables
			, InstructionList & instructions )
		{
			auto result = variables.emplace( std::move( name ), VariableInfo{} ).first;
			result->second.id = varId;
			result->second.isParam = false;
			result->second.isAlias = false;
			instructions.push_back( makeVariableInstruction( nameCache
				, varTypeId
				, varId
				, initialiser ) );
			return result;
		}

		static size_t myHash( ast::type::ImageConfiguration const & config
			, ast::type::Trinary isComparison )noexcept
		{
			size_t result = std::hash< ast::type::ImageDim >{}( config.dimension );
			result = ast::type::hashCombine( result, config.format );
			result = ast::type::hashCombine( result, config.isSampled );
			result = ast::type::hashCombine( result, config.isArrayed );
			result = ast::type::hashCombine( result, config.isMS );
			result = ast::type::hashCombine( result, isComparison );
			return result;
		}

		template< typename LitT >
		static ValueId registerLiteral( LitT value
			, ast::type::TypePtr valueType
			, Module & module
			, Map< LitT, ValueId > & registeredLitConstants
			, UnorderedMap< ValueId, ast::type::TypePtr, ValueIdHasher > & registeredConstants )
		{
			auto it = registeredLitConstants.find( value );

			if ( it == registeredLitConstants.end() )
			{
				auto type = module.registerType( valueType, nullptr );
				ValueId result{ module.getNextId(), type->type };
				module.constantsTypes.push_back( makeInstruction< ConstantInstruction >( module.nameCache
					, type.id
					, result
					, makeOperands( registeredConstants.get_allocator().getAllocator(), ValueId{ spv::Id( value ) } ) ) );
				it = registeredLitConstants.emplace( value, result ).first;
				registeredConstants.emplace( result, valueType );
			}

			return it->second;
		}
	}

	//*************************************************************************

	static uint32_t constexpr VendorID = 33u;
	static uint32_t constexpr Version = 0x0012u;

	Module::Module( ast::ShaderAllocatorBlock * alloc )
		: allocator{ alloc }
		, nameCache{ alloc }
		, header{ allocator }
		, capabilities{ allocator }
		, extensions{ allocator }
		, imports{ allocator }
		, memoryModel{}
		, executionModes{ allocator }
		, debugString{ allocator }
		, debug{ allocator }
		, decorations{ allocator }
		, constantsTypes{ allocator }
		, globalDeclarations{ allocator }
		, debugDeclarations{ allocator }
		, structData{ allocator }
		, functions{ spirv::ModuleAllocatorT< spirv::Function >{ allocator } }
		, variables{ &globalDeclarations }
		, m_version{}
		, m_typesCache{}
		, m_registeredTypes{ allocator }
		, m_registeredMemberTypes{ allocator }
		, m_registeredVariables{ allocator }
		, m_registeredSamplerImages{ allocator }
		, m_registeredImageTypes{ allocator }
		, m_currentScopeVariables{ &m_registeredVariables }
		, m_registeredVariablesTypes{ allocator }
		, m_registeredMemberVariables{ allocator }
		, m_registeredPointerTypes{ allocator }
		, m_registeredForwardPointerTypes{ allocator }
		, m_registeredFunctionTypes{ allocator }
		, m_registeredBoolConstants{ allocator }
		, m_registeredInt8Constants{ allocator }
		, m_registeredInt16Constants{ allocator }
		, m_registeredInt32Constants{ allocator }
		, m_registeredInt64Constants{ allocator }
		, m_registeredUInt8Constants{ allocator }
		, m_registeredUInt16Constants{ allocator }
		, m_registeredUInt32Constants{ allocator }
		, m_registeredUInt64Constants{ allocator }
		, m_registeredFloatConstants{ allocator }
		, m_registeredDoubleConstants{ allocator }
		, m_registeredCompositeConstants{ allocator }
		, m_registeredConstants{ allocator }
		, m_intermediates{ allocator }
		, m_freeIntermediates{ allocator }
		, m_busyIntermediates{ allocator }
		, m_model{}
		, m_pendingExecutionModes{ allocator }
		, m_entryPointIO{ allocator }
		, varDecorations{ allocator }
		, mbrDecorations{ allocator }
	{
	}

	Module::Module( ast::ShaderAllocatorBlock * alloc
		, ast::type::TypesCache & typesCache
		, SpirVConfig const & spirvConfig
		, spv::AddressingModel addressingModel
		, spv::MemoryModel pmemoryModel
		, spv::ExecutionModel pexecutionModel
		, glsl::Statements const & debugStatements )
		: Module{ alloc }
	{
		memoryModel = makeInstruction< MemoryModelInstruction >( nameCache
			, ValueId{ spv::Id( addressingModel ) }
			, ValueId{ spv::Id( pmemoryModel ) } );
		m_version = spirvConfig.specVersion;
		m_typesCache = &typesCache;
		m_model = pexecutionModel;

		doInitialiseHeader( Header{ spv::MagicNumber
			, m_version
			, ( VendorID << 16 ) | Version
			, 1u	/* Bound IDs. */
			, 0u	/* Schema. */ } );
		doInitialiseExtensions( spirvConfig.debug );
		doInitialiseCapacities();
		doInitialiseDebug( spirvConfig.debug, debugStatements );
	}

	Module::Module( ast::ShaderAllocatorBlock * alloc
		, Header const & pheader
		, InstructionList instructions )
		: Module{ alloc }
	{
		doInitialiseHeader( pheader );
		auto it = instructions.begin();

		while ( it != instructions.end() )
		{
			auto opCode = spv::Op( ( *it )->op.opData.opCode );

			if ( !doDeserializeInfos( opCode, it, instructions.end() ) )
			{
				if ( !doDeserializeFuncs( opCode, it, instructions.end() ) )
				{
					if ( auto * list = doSelectInstructionsList( opCode ) )
					{
						list->emplace_back( std::move( *it ) );
						++it;
					}
				}
			}
		}
	}

	Module Module::deserialize( ast::ShaderAllocatorBlock * allocator
		, std::vector< uint32_t > const & spirv )
	{
		BufferCIt buffer{ spirv.cbegin(), 0u };
		Header header{};
		header.magic = buffer.popValue();
		assert( header.magic == spv::MagicNumber );
		header.version = buffer.popValue();
		header.builder = buffer.popValue();
		header.boundIds = buffer.popValue();
		header.schema = buffer.popValue();
		spirv::InstructionList instructions{ allocator };

		while ( buffer.it != spirv.end() )
		{
			instructions.emplace_back( buffer.popInstruction( allocator ) );
		}

		return Module{ allocator, header, std::move( instructions ) };
	}

	std::string spirv::Module::write( spirv::Module const & module
		, bool writeHeader )
	{
		return spirv::write( module, writeHeader );
	}

	Vector< uint32_t > spirv::Module::serialize( spirv::Module const & module )
	{
		return spirv::serialize( module );
	}

	TypeId Module::registerType( ast::type::TypePtr type
		, glsl::Statement const * debugStatement )
	{
		return doRegisterTypeRec( type
			, ast::type::NotMember
			, TypeId{}
			, 0u
			, debugStatement );
	}

	TypeId Module::registerType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId parentId
		, glsl::Statement const * debugStatement )
	{
		return doRegisterTypeRec( type
			, mbrIndex
			, parentId
			, 0u
			, debugStatement );
	}

	TypeId Module::registerImageType( ast::type::ImagePtr image
		, bool isComparison )
	{
		return doRegisterBaseType( image
			, isComparison ? ast::type::Trinary::eTrue : ast::type::Trinary::eFalse );
	}

	TypeId Module::registerPointerType( TypeId type
		, spv::StorageClass storage
		, bool isForward )
	{
		uint64_t key = ( uint64_t( type.id.id ) << 33 )
			| ( ( uint64_t( type.isPointer() ) << 32 ) & 0x01 )
			| ( uint64_t( storage ) << 1 )
			| ( isForward & 0x01 );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			TypeId id{ getNextId()
				, type->type->getTypesCache().getPointerType( type->type, convert( storage ) ) };
			id.debug = type.debug;
			it = m_registeredPointerTypes.emplace( key, id ).first;

			if ( isForward )
			{
				constantsTypes.push_back( makeInstruction< ForwardPointerTypeInstruction >( nameCache
					, id.id
					, ValueId{ spv::Id( storage ) } ) );
				constantsTypes.push_back( makeInstruction< PointerTypeInstruction >( nameCache
					, id.id
					, ValueId{ spv::Id( storage ) }
					, type.id ) );
				key = ( uint64_t( type.id.id ) << 33 )
					| ( ( uint64_t( type.isPointer() ) << 32 ) & 0x01 )
					| ( uint64_t( storage ) << 1 );
				m_registeredPointerTypes.emplace( key, id );
			}
			else
			{
				constantsTypes.push_back( makeInstruction< PointerTypeInstruction >( nameCache
					, id.id
					, ValueId{ spv::Id( storage ) }
					, type.id ) );
			}
		}

		return it->second;
	}

	void Module::decorate( ValueId id, spv::Decoration decoration )
	{
		if ( decoration == spv::DecorationBufferBlock )
		{
			// Since we can't have both Block and BufferBlock decorations, replace the former with the latter.
			doReplaceDecoration( id, spv::DecorationBlock, decoration );
		}
		else
		{
			decorate( id, makeIdList( allocator, spv::Id( decoration ) ) );
		}
	}

	void Module::decorate( ValueId id
		, IdList const & pdecorations )
	{
		auto it = varDecorations.emplace( id, DecorationMap{ allocator } ).first;
		auto decos = convert( pdecorations );
		auto ires = it->second.emplace( decos, 0u );

		if ( ires.second )
		{
			ires.first->second = decorations.size();
			decorations.push_back( makeInstruction< DecorateInstruction >( nameCache
				, makeOperands( allocator, id, decos ) ) );
		}
	}

	void Module::decorateMember( ValueId id
		, uint32_t index
		, spv::Decoration decoration )
	{
		if ( decoration == spv::DecorationBufferBlock )
		{
			// Since we can't have both Block and BufferBlock decorations, replace the former with the latter.
			doReplaceMemberDecoration( id, index, spv::DecorationBlock, decoration );
		}
		else
		{
			decorateMember( id, index, makeIdList( allocator, spv::Id( decoration ) ) );
		}
	}

	void Module::decorateMember( ValueId id
		, uint32_t index
		, IdList const & pdecorations )
	{
		auto it = mbrDecorations.emplace( makeOperands( allocator, id, ValueId{ index } ), DecorationMap{ allocator } ).first;
		auto decos = convert( pdecorations );
		auto ires = it->second.emplace( decos, 0u );

		if ( ires.second )
		{
			ires.first->second = decorations.size();
			decorations.push_back( makeInstruction< MemberDecorateInstruction >( nameCache
				, makeOperands( allocator, id, index, decos ) ) );
		}
	}

	ValueId Module::getVariablePointer( ValueId varId
		, std::string name
		, spv::StorageClass storage
		, Block & currentBlock )
	{
		if ( varId.isPointer() && convert( varId.getStorage() ) != storage )
		{
			varId = loadVariable( varId, currentBlock );
			name = "SDW_Swap_" + name;
		}

		if ( !varId.isPointer() )
		{
			ValueId id{ getNextId()
				, varId.type->getTypesCache().getPointerType( varId.type, convert( storage ) ) };
			doAddDebug( name, id );
			Map< std::string, VariableInfo >::iterator it;
			doAddVariable( name, id, it, ValueId{} );
			storeVariable( it->second.id, varId, currentBlock );
			varId = it->second.id;
		}

		return varId;
	}

	ValueId Module::getVariablePointer( std::string name
		, spv::StorageClass storage
		, ast::type::TypePtr type
		, Block & currentBlock )
	{
		ValueId varId;
		Map< std::string, VariableInfo >::iterator it;

		if ( m_currentFunction )
		{
			it = m_currentScopeVariables->find( name );

			if ( it != m_currentScopeVariables->end() )
			{
				varId = it->second.id;
			}
		}

		if ( !varId )
		{
			it = m_registeredVariables.find( name );

			if ( it != m_registeredVariables.end() )
			{
				varId = it->second.id;
			}
		}

		if ( varId )
		{
			varId = getVariablePointer( varId
				, name
				, storage
				, currentBlock );
		}

		return varId;
	}

	void Module::storePromoted( ValueId variable
		, VariableInfo const & sourceInfo
		, Block & currentBlock )
	{
		if ( sourceInfo.isParam )
		{
			storeVariable( variable
				, sourceInfo.id
				, m_currentFunction->promotedParams );
		}
		else
		{
			storeVariable( variable
				, sourceInfo.id
				, currentBlock.instructions );
		}
	}

	void Module::storeVariable( ValueId variable
		, ValueId value
		, InstructionList & instructions )
	{
		assert( variable.isPointer() );

		if ( value.isPointer() )
		{
			value = loadVariable( value, instructions );
		}

		instructions.push_back( makeInstruction< StoreInstruction >( nameCache
			, variable
			, value ) );
	}

	void Module::storeVariable( ValueId variable
		, ValueId value
		, Block & currentBlock )
	{
		storeVariable( variable
			, value
			, currentBlock.instructions );
	}

	ValueId Module::loadVariable( ValueId variable
		, InstructionList & instructions )
	{
		if ( variable.isPointer() )
		{
			auto type = static_cast< ast::type::Pointer const & >( *variable.type ).getPointerType();

			if ( !hasRuntimeArray( type ) )
			{
				auto typeId = registerType( type, nullptr );
				ValueId result{ getIntermediateResult(), typeId->type };

				if ( variable.getStorage() == ast::type::Storage::ePhysicalStorageBuffer )
				{
					// Loading from PhysicalStorageBuffer needs to set the alignment
					auto structType = getStructType( type );
					instructions.push_back( makeInstruction< LoadInstruction >( nameCache
						, typeId.id
						, result
						, makeOperands( allocator
							, variable
							, ValueId{ spv::Id( spv::MemoryAccessAlignedMask ) }
							, ValueId{ ast::type::getAlignment( type
								, ( structType
									? structType->getMemoryLayout()
									: ast::type::MemoryLayout::eScalar ) ) } ) ) );
				}
				else
				{
					instructions.push_back( makeInstruction< LoadInstruction >( nameCache
						, typeId.id
						, result
						, makeOperands( allocator
							, variable
							, ValueId{ spv::Id( spv::MemoryAccessMaskNone ) } ) ) );
				}

				lnkIntermediateResult( result, variable );
				return result;
			}
		}

		return variable;
	}

	ValueId Module::loadVariable( ValueId variable
		, Block & currentBlock )
	{
		return loadVariable( variable
			, currentBlock.instructions );
	}

	ValueId Module::mergeSamplerImage( ValueId const & image
		, ValueId const & sampler
		, Block & currentBlock )
	{
		auto & imgType = static_cast< ast::type::Image const & >( *getNonArrayType( image.type ) );
		auto & splType = static_cast< ast::type::Sampler const & >( *getNonArrayType( sampler.type ) );
		auto lhsIt = m_registeredSamplerImages.emplace( image
			, UnorderedMap< ValueId, ValueId, ValueIdHasher >{ allocator } ).first;
		auto ires = lhsIt->second.emplace( sampler, ValueId{} );
		auto it = ires.first;

		if ( ires.second )
		{
			auto typeId = registerType( image.type->getTypesCache().getCombinedImage( imgType.getConfig()
				, splType.isComparison() )
				, nullptr );
			it->second = ValueId{ getNextId(), typeId->type };
			currentBlock.instructions.push_back( makeInstruction< SampledImageInstruction >( nameCache
				, typeId.id
				, it->second
				, image
				, sampler ) );
		}

		return it->second;
	}

	void Module::bindVariable( ValueId varId
		, uint32_t bindingPoint
		, uint32_t descriptorSet )
	{
		decorate( varId, makeIdList( allocator, spv::Id( spv::DecorationBinding ), bindingPoint ) );
		decorate( varId, makeIdList( allocator, spv::Id( spv::DecorationDescriptorSet ), descriptorSet ) );
	}

	void Module::bindBufferVariable( ValueId variableId
		, uint32_t bindingPoint
		, uint32_t descriptorSet
		, spv::Decoration structDecoration )
	{
		decorate( variableId, makeIdList( allocator, spv::Id( spv::DecorationBinding ), bindingPoint ) );
		decorate( variableId, makeIdList( allocator, spv::Id( spv::DecorationDescriptorSet ), descriptorSet ) );

		auto typeIt = m_registeredVariablesTypes.find( variableId );

		if ( typeIt != m_registeredVariablesTypes.end() )
		{
			auto typeId = typeIt->second;
			decorate( typeId.id, structDecoration );
		}
	}

	ValueId Module::bindBufferVariable( std::string const & name
		, uint32_t bindingPoint
		, uint32_t descriptorSet
		, spv::Decoration structDecoration )
	{
		ValueId result{};
		auto varIt = m_currentScopeVariables->find( name );

		if ( varIt != m_currentScopeVariables->end() )
		{
			result = varIt->second.id;
			bindBufferVariable( result, bindingPoint, descriptorSet, structDecoration );
		}

		return result;
	}

	VariableInfo Module::registerParam( std::string name
		, bool isOutput
		, ast::type::TypePtr type )
	{
		auto typeId = registerType( type, nullptr );
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			auto rawTypeId = registerType( type, nullptr );

			if ( m_currentFunction )
			{
				it = m_currentScopeVariables->emplace( std::move( name )
					, VariableInfo{ typeId.id, false, true, isOutput } ).first;
			}
			else
			{
				it = m_registeredVariables.emplace( std::move( name )
					, VariableInfo{ typeId.id, false, true, isOutput } ).first;
			}

			m_registeredVariablesTypes.emplace( typeId.id, rawTypeId );
		}

		return it->second;
	}

	VariableInfo Module::registerAlias( std::string name
		, ast::type::TypePtr type
		, ValueId exprResultId )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			auto rawTypeId = registerType( type, nullptr );

			if ( m_currentFunction )
			{
				it = m_currentScopeVariables->emplace( std::move( name )
					, VariableInfo{ exprResultId, true, false, false } ).first;
			}
			else
			{
				it = m_registeredVariables.emplace( std::move( name )
					, VariableInfo{ exprResultId, true, false, false } ).first;
			}

			m_registeredVariablesTypes.emplace( exprResultId, rawTypeId );
		}

		return it->second;
	}

	VariableInfo Module::registerVariable( std::string name
		, ast::Builtin builtin
		, spv::StorageClass storage
		, bool isAlias
		, bool isParam
		, bool isOutParam
		, ast::type::TypePtr type
		, VariableInfo & sourceInfo
		, ValueId initialiser
		, glsl::Statement const * debugStatement )
	{
		auto & container = m_currentScopeVariables;
		auto typeStorage = convert( storage );

		if ( typeStorage == ast::type::Storage::ePhysicalStorageBuffer )
		{
			container = &m_registeredVariables;
		}

		auto it = container->find( name );

		if ( it == container->end() )
		{
			ast::type::TypePtr varType;

			if ( typeStorage == ast::type::Storage::eFunction )
			{
				if ( auto structType = getStructType( type ) )
				{
					if ( structType->empty() )
					{
						return VariableInfo{};
					}

					if ( getArraySize( structType->back().type ) == ast::type::UnknownArraySize )
					{
						auto typeId = registerType( type, debugStatement );

						if ( storage == spv::StorageClassPhysicalStorageBuffer
							|| storage == spv::StorageClassUniform
							|| storage == spv::StorageClassStorageBuffer )
						{
							decorate( typeId.id, spv::DecorationBlock );
						}
						else
						{
							decorate( typeId.id, spv::DecorationBlock );
						}

						varType = type->getTypesCache().getPointerType( type, ast::type::Storage::ePhysicalStorageBuffer );
						varType = type->getTypesCache().getPointerType( varType, typeStorage );
						typeStorage = ast::type::Storage::ePhysicalStorageBuffer;
					}
				}
			}

			if ( !varType )
			{
				varType = type->getTypesCache().getPointerType( type, convert( storage ) );
			}

			ValueId id{ getNextId(), varType };

			if ( typeStorage == ast::type::Storage::ePhysicalStorageBuffer )
			{
				decorate( id, spv::DecorationAliasedPointer );
			}

			doAddDebug( name, id );

			if ( builtin != ast::Builtin::eNone )
			{
				doAddBuiltin( builtin, id );
			}

			doAddVariable( std::move( name ), id, it, initialiser, debugStatement );
			sourceInfo = it->second;

			if ( m_version >= v1_4 )
			{
				if ( storage != spv::StorageClassFunction )
				{
					m_entryPointIO.insert( id );
				}
			}
		}
		else
		{
			sourceInfo = it->second;

			if ( ( it->second.isParam && !isParam && ( !isPointerParam( type, isOutParam ) ) )
				|| ( it->second.isAlias && !isAlias ) )
			{
				ValueId id{ getNextId()
					, type->getTypesCache().getPointerType( ( it->second.id.isPointer()
							? static_cast< ast::type::Pointer const & >( *it->second->type ).getPointerType()
							: it->second->type )
						, convert( storage ) ) };
				it->second.isAlias = false;
				it->second.isParam = false;
				it->second.isOutParam = false;
				doAddDebug( "ptr_" + name, id );
				doAddVariable( std::move( name ), id, it, {}, debugStatement );

				if ( m_version >= v1_4 )
				{
					if ( storage != spv::StorageClassFunction )
					{
						m_entryPointIO.insert( id );
					}
				}
			}
		}

		VariableInfo result;
		result.isParam = isParam;
		result.isOutParam = isOutParam;
		result.isAlias = isAlias;
		result.id = it->second.id;

		return result;
	}

	ValueId Module::registerSpecConstant( std::string name
		, uint32_t location
		, ast::type::TypePtr type
		, ast::expr::Literal const & value )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			ValueId id{ getNextId() };
			it = m_currentScopeVariables->emplace( name, id ).first;
			auto rawTypeId = registerType( type, nullptr );
			IdList operands{ allocator };
			debug.push_back( makeInstruction< NameInstruction >( nameCache
				, id
				, name ) );

			if ( value.getLiteralType() == ast::expr::LiteralType::eBool )
			{
				if ( value.getValue< ast::expr::LiteralType::eBool >() )
				{
					constantsTypes.emplace_back( makeInstruction< SpecConstantTrueInstruction >( nameCache
						, rawTypeId.id
						, id ) );
				}
				else
				{
					constantsTypes.emplace_back( makeInstruction< SpecConstantFalseInstruction >( nameCache
						, rawTypeId.id
						, id ) );
				}
			}
			else
			{
				switch ( value.getLiteralType() )
				{
				case ast::expr::LiteralType::eInt8:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt8 >() ) );
					break;
				case ast::expr::LiteralType::eInt16:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt16 >() ) );
					break;
				case ast::expr::LiteralType::eInt32:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt32 >() ) );
					break;
				case ast::expr::LiteralType::eInt64:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt64 >() >> 32 ) );
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt64 >() & 0x00000000FFFFFFFFull ) );
					break;
				case ast::expr::LiteralType::eUInt8:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eUInt8 >() ) );
					break;
				case ast::expr::LiteralType::eUInt16:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eUInt16 >() ) );
					break;
				case ast::expr::LiteralType::eUInt32:
					operands.emplace_back( value.getValue< ast::expr::LiteralType::eUInt32 >() );
					break;
				case ast::expr::LiteralType::eUInt64:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eUInt64 >() >> 32 ) );
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eUInt64 >() & 0x00000000FFFFFFFFull ) );
					break;
				case ast::expr::LiteralType::eFloat:
				{
					operands.resize( sizeof( float ) / sizeof( uint32_t ) );
					auto dst = reinterpret_cast< float * >( operands.data() );
					*dst = value.getValue< ast::expr::LiteralType::eFloat >();
				}
				break;
				case ast::expr::LiteralType::eDouble:
				{
					operands.resize( sizeof( double ) / sizeof( uint32_t ) );
					auto dst = reinterpret_cast< double * >( operands.data() );
					*dst = value.getValue< ast::expr::LiteralType::eDouble >();
				}
				break;
				default:
					break;
				}

				constantsTypes.emplace_back( makeInstruction< SpecConstantInstruction >( nameCache
					, rawTypeId.id
					, id
					, operands ) );
			}

			decorate( id, makeIdList( allocator, spv::Id( spv::DecorationSpecId ), location ) );
			m_registeredVariablesTypes.emplace( id, rawTypeId );
			m_registeredConstants.emplace( id, value.getType() );
		}

		return it->second.id;
	}

	ValueId Module::registerParameter( ast::type::TypePtr type )
	{
		registerType( type, nullptr );
		return { getNextId() };
	}

	ValueId Module::registerMemberVariableIndex( ast::type::TypePtr type )
	{
		assert( type->isMember() );
		return registerLiteral( type->getIndex() );
	}

	ValueId Module::registerMemberVariable( ValueId outer
		, std::string name
		, ast::type::TypePtr type )
	{
		auto it = std::find_if( m_currentScopeVariables->begin()
			, m_currentScopeVariables->end()
			, [outer]( Map< std::string, VariableInfo >::value_type const & pair )
			{
				return pair.second.id == outer;
			} );
		assert( it != m_currentScopeVariables->end() );
		assert( type->isMember() );
		auto fullName = it->first + "::" + name;
		it = m_currentScopeVariables->find( fullName );

		if ( it == m_currentScopeVariables->end() )
		{
			ValueId id{ getNextId()
				, type->getTypesCache().getPointerType( type, outer.getStorage() ) };
			m_registeredMemberVariables.emplace( fullName, std::make_pair( outer, id ) );
			it = m_currentScopeVariables->emplace( fullName, VariableInfo{ id, false, false, false } ).first;
			registerLiteral( type->getIndex() );
		}

		return it->second.id;
	}

	ast::type::Kind Module::getLiteralType( ValueId litId )const
	{
		auto it = m_registeredConstants.find( litId );
		if ( it != m_registeredConstants.end() )
		{
			return it->second->getKind();
		}

		return ast::type::Kind::eUndefined;
	}

	ValueId Module::getOuterVariable( ValueId mbrId )const
	{
		auto itInner = std::find_if( m_registeredMemberVariables.begin()
			, m_registeredMemberVariables.end()
			, [mbrId]( Map< std::string, std::pair< ValueId, ValueId > >::value_type const & pair )
			{
				return pair.second.second == mbrId;
			} );
		assert( itInner != m_registeredMemberVariables.end() );
		
		auto result = itInner->second.first;
		auto itOuter = m_registeredMemberVariables.end();

		while ( ( itOuter = std::find_if( m_registeredMemberVariables.begin()
				, m_registeredMemberVariables.end()
				, [result]( Map< std::string, std::pair< ValueId, ValueId > >::value_type const & pair )
				{
					return pair.second.second == result;
				} ) ) != m_registeredMemberVariables.end() )
		{
			result = itOuter->second.first;
		}

		auto itOutermost = std::find_if( m_currentScopeVariables->begin()
			, m_currentScopeVariables->end()
			, [result]( Map< std::string, VariableInfo >::value_type const & pair )
			{
					return pair.second.id == result;
			} );
		assert( itOutermost != m_currentScopeVariables->end() );
		return itOutermost->second.id;
	}

	ValueId Module::registerLiteral( bool value )
	{
		auto it = m_registeredBoolConstants.find( value );

		if ( it == m_registeredBoolConstants.end() )
		{
			auto type = registerType( m_typesCache->getBool(), nullptr );
			ValueId result{ getNextId(), type->type };

			if ( value )
			{
				constantsTypes.push_back( makeInstruction< ConstantTrueInstruction >( nameCache
					, type.id
					, result ) );
			}
			else
			{
				constantsTypes.push_back( makeInstruction< ConstantFalseInstruction >( nameCache
					, type.id
					, result ) );
			}

			it = m_registeredBoolConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getBool() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( int8_t value )
	{
		return module::registerLiteral( value
			, m_typesCache->getInt8()
			, *this
			, m_registeredInt8Constants
			, m_registeredConstants );
	}

	ValueId Module::registerLiteral( int16_t value )
	{
		return module::registerLiteral( value
			, m_typesCache->getInt16()
			, *this
			, m_registeredInt16Constants
			, m_registeredConstants );
	}

	ValueId Module::registerLiteral( int32_t value )
	{
		return module::registerLiteral( value
			, m_typesCache->getInt32()
			, *this
			, m_registeredInt32Constants
			, m_registeredConstants );
	}

	ValueId Module::registerLiteral( uint8_t value )
	{
		return module::registerLiteral( value
			, m_typesCache->getUInt8()
			, *this
			, m_registeredUInt8Constants
			, m_registeredConstants );
	}

	ValueId Module::registerLiteral( uint16_t value )
	{
		return module::registerLiteral( value
			, m_typesCache->getUInt16()
			, *this
			, m_registeredUInt16Constants
			, m_registeredConstants );
	}

	ValueId Module::registerLiteral( uint32_t value )
	{
		return module::registerLiteral( value
			, m_typesCache->getUInt32()
			, *this
			, m_registeredUInt32Constants
			, m_registeredConstants );
	}

	ValueId Module::registerLiteral( int64_t value )
	{
		auto it = m_registeredInt64Constants.find( value );

		if ( it == m_registeredInt64Constants.end() )
		{
			auto type = registerType( m_typesCache->getInt64(), nullptr );
			ValueId result{ getNextId(), type->type };
			constantsTypes.push_back( makeInstruction< ConstantInstruction >( nameCache
				, type.id
				, result
				, makeOperands( allocator
					, ValueId{ uint32_t( ( value >> 32 ) & 0x00000000FFFFFFFFll ) }
					, ValueId{ uint32_t( value & 0x00000000FFFFFFFFll ) } ) ) );
			it = m_registeredInt64Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getInt64() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( uint64_t value )
	{
		auto it = m_registeredUInt64Constants.find( value );

		if ( it == m_registeredUInt64Constants.end() )
		{
			auto type = registerType( m_typesCache->getUInt64(), nullptr );
			ValueId result{ getNextId(), type->type };
			constantsTypes.push_back( makeInstruction< ConstantInstruction >( nameCache
				, type.id
				, result
				, makeOperands( allocator
					, ValueId{ uint32_t( ( value >> 32 ) & 0x00000000FFFFFFFFull ) }
					, ValueId{ uint32_t( value & 0x00000000FFFFFFFFull ) } ) ) );
			it = m_registeredUInt64Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getUInt64() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( float value )
	{
		auto it = m_registeredFloatConstants.find( value );

		if ( it == m_registeredFloatConstants.end() )
		{
			auto type = registerType( m_typesCache->getFloat(), nullptr );
			ValueId result{ getNextId(), type->type };
			IdList list{ allocator };
			list.resize( 1u );
			auto dst = reinterpret_cast< float * >( list.data() );
			*dst = value;
			constantsTypes.push_back( makeInstruction< ConstantInstruction >( nameCache
				, type.id
				, result
				, convert( list ) ) );
			it = m_registeredFloatConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getFloat() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( double value )
	{
		auto it = m_registeredDoubleConstants.find( value );

		if ( it == m_registeredDoubleConstants.end() )
		{
			auto type = registerType( m_typesCache->getDouble(), nullptr );
			ValueId result{ getNextId(), type->type };
			IdList list{ allocator };
			list.resize( 2u );
			auto dst = reinterpret_cast< double * >( list.data() );
			*dst = value;
			constantsTypes.push_back( makeInstruction< ConstantInstruction >( nameCache
				, type.id
				, result
				, convert( list ) ) );
			it = m_registeredDoubleConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getDouble() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( ValueIdList const & initialisers
		, ast::type::TypePtr type )
	{
		auto typeId = registerType( type, nullptr );
		auto it = std::find_if( m_registeredCompositeConstants.begin()
			, m_registeredCompositeConstants.end()
			, [&initialisers]( std::pair< ValueIdList, ValueId > const & lookup )
			{
				return lookup.first == initialisers;
			} );

		if ( it == m_registeredCompositeConstants.end() )
		{
			ValueId result{ getNextId(), typeId->type };
			constantsTypes.push_back( makeInstruction< ConstantCompositeInstruction >( nameCache
				, typeId.id
				, result
				, initialisers ) );
			m_registeredCompositeConstants.emplace_back( initialisers, result );
			it = m_registeredCompositeConstants.begin() + ptrdiff_t( m_registeredCompositeConstants.size() - 1u );
			m_registeredConstants.emplace( result, type );
		}

		return it->second;
	}

	void Module::registerExtension( std::string name )
	{
		extensions.push_back( makeInstruction< ExtensionInstruction >( nameCache
			, std::move( name ) ) );
	}

	void Module::registerEntryPoint( ValueId functionId
		, std::string name
		, ValueIdList const & inputs
		, ValueIdList const & outputs )
	{
		ValueIdSet ios{ allocator };
		ValueIdList operands{ allocator };

		for ( auto id : inputs )
		{
			ios.insert( id );
		}

		for ( auto id : outputs )
		{
			ios.insert( id );
		}

		for ( auto id : m_entryPointIO )
		{
			ios.insert( id );
		}

		operands.insert( operands.end(), ios.begin(), ios.end() );
		entryPoint = makeInstruction< EntryPointInstruction >( nameCache
			, ValueId{ spv::Id( m_model ) }
			, functionId
			, operands
			, std::move( name ) );

		switch ( m_model )
		{
		case spv::ExecutionModelVertex:
			break;
		case spv::ExecutionModelTessellationControl:
			break;
		case spv::ExecutionModelTessellationEvaluation:
			break;
		case spv::ExecutionModelGeometry:
			break;
		case spv::ExecutionModelFragment:
			registerExecutionMode( spv::ExecutionModeOriginUpperLeft );
			break;
		case spv::ExecutionModelGLCompute:
			break;
		case spv::ExecutionModelKernel:
			break;
		case spv::ExecutionModelMax:
			break;
		default:
			break;
		}

		for ( auto & executionMode : m_pendingExecutionModes )
		{
			executionModes.emplace_back( std::move( executionMode ) );
			executionModes.back()->operands[0] = functionId.id;
		}

		m_pendingExecutionModes.clear();
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode )
	{
		registerExecutionMode( mode, ValueIdList{ allocator } );
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode, ValueIdList const & operands )
	{
		if ( !entryPoint || entryPoint->operands.empty() )
		{
			m_pendingExecutionModes.push_back( makeInstruction< ExecutionModeInstruction >( nameCache
				, makeOperands( allocator, 0u, spv::Id( mode ), operands ) ) );
		}
		else
		{
			executionModes.push_back( makeInstruction< ExecutionModeInstruction >( nameCache
				, makeOperands( allocator, entryPoint->resultId.value(), spv::Id( mode ), operands ) ) );
		}
	}

	void Module::registerExecutionMode( ast::type::OutputLayout layout
		, uint32_t primCount )
	{
		switch ( layout )
		{
		case ast::type::OutputLayout::ePointList:
			registerExecutionMode( spv::ExecutionModeOutputPoints );
			break;
		case ast::type::OutputLayout::eLineStrip:
			registerExecutionMode( spv::ExecutionModeOutputLineStrip );
			break;
		case ast::type::OutputLayout::eTriangleStrip:
			registerExecutionMode( spv::ExecutionModeOutputTriangleStrip );
			break;
		default:
			AST_Failure( "Unsupported OutputLayout" );
			break;
		}

		registerExecutionMode( spv::ExecutionModeOutputVertices, makeOperands( allocator, ValueId{ primCount } ) );
		registerExecutionMode( spv::ExecutionModeInvocations, makeOperands( allocator, ValueId{ 1u } ) );
	}

	void Module::registerExecutionMode( ast::type::PatchDomain domain
		, ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering order
		, uint32_t outputVertices )
	{
		registerExecutionMode( spv::ExecutionModeOutputVertices, makeOperands( allocator, ValueId{ outputVertices } ) );
	}

	void Module::registerExecutionMode( ast::type::PatchDomain domain
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering order )
	{
		switch ( partitioning )
		{
		case ast::type::Partitioning::eEqual:
			registerExecutionMode( spv::ExecutionModeSpacingEqual );
			break;
		case ast::type::Partitioning::eFractionalEven:
			registerExecutionMode( spv::ExecutionModeSpacingFractionalEven );
			break;
		case ast::type::Partitioning::eFractionalOdd:
			registerExecutionMode( spv::ExecutionModeSpacingFractionalOdd );
			break;
		default:
			break;
		}

		switch ( order )
		{
		case ast::type::PrimitiveOrdering::eCW:
			registerExecutionMode( spv::ExecutionModeVertexOrderCw );
			break;
		case ast::type::PrimitiveOrdering::eCCW:
			registerExecutionMode( spv::ExecutionModeVertexOrderCcw );
			break;
		default:
			break;
		}

		switch ( domain )
		{
		case ast::type::PatchDomain::eIsolines:
			registerExecutionMode( spv::ExecutionModeIsolines );
			break;
		case ast::type::PatchDomain::eTriangles:
			registerExecutionMode( spv::ExecutionModeTriangles );
			break;
		case ast::type::PatchDomain::eQuads:
			registerExecutionMode( spv::ExecutionModeQuads );
			break;
		default:
			break;
		}
	}

	void Module::registerExecutionMode( ast::type::InputLayout layout )
	{
		switch ( layout )
		{
		case ast::type::InputLayout::ePointList:
			registerExecutionMode( spv::ExecutionModeInputPoints );
			break;
		case ast::type::InputLayout::eLineList:
		case ast::type::InputLayout::eLineStrip:
			registerExecutionMode( spv::ExecutionModeInputLines );
			break;
		case ast::type::InputLayout::eTriangleList:
		case ast::type::InputLayout::eTriangleStrip:
		case ast::type::InputLayout::eTriangleFan:
			registerExecutionMode( spv::ExecutionModeTriangles );
			break;
		case ast::type::InputLayout::eTriangleListWithAdjacency:
		case ast::type::InputLayout::eTriangleStripWithAdjacency:
			registerExecutionMode( spv::ExecutionModeInputTrianglesAdjacency );
			break;
		case ast::type::InputLayout::eLineListWithAdjacency:
		case ast::type::InputLayout::eLineStripWithAdjacency:
			registerExecutionMode( spv::ExecutionModeInputLinesAdjacency );
			break;
		default:
			AST_Failure( "Unsupported InputLayout" );
			break;
		}
	}

	void Module::registerExecutionModeNV( ast::type::OutputTopology topology
		, uint32_t maxVertices
		, uint32_t maxPrimitives )
	{
		switch ( topology )
		{
		case ast::type::OutputTopology::ePoint:
			registerExecutionMode( spv::ExecutionModeOutputPoints );
			break;
		case ast::type::OutputTopology::eLine:
			registerExecutionMode( spv::ExecutionModeOutputLinesNV );
			break;
		case ast::type::OutputTopology::eTriangle:
			registerExecutionMode( spv::ExecutionModeOutputTrianglesNV );
			break;
		default:
			AST_Failure( "Unsupported OutputTopology" );
			break;
		}

		registerExecutionMode( spv::ExecutionModeOutputVertices, makeOperands( allocator, ValueId{ maxVertices } ) );
		registerExecutionMode( spv::ExecutionModeOutputPrimitivesNV, makeOperands( allocator, ValueId{ maxPrimitives } ) );
	}

	void Module::registerExecutionMode( ast::type::OutputTopology topology
		, uint32_t maxVertices
		, uint32_t maxPrimitives )
	{
		switch ( topology )
		{
		case ast::type::OutputTopology::ePoint:
			registerExecutionMode( spv::ExecutionModeOutputPoints );
			break;
		case ast::type::OutputTopology::eLine:
			registerExecutionMode( spv::ExecutionModeOutputLinesEXT );
			break;
		case ast::type::OutputTopology::eTriangle:
			registerExecutionMode( spv::ExecutionModeOutputTrianglesEXT );
			break;
		default:
			AST_Failure( "Unsupported OutputTopology" );
			break;
		}

		registerExecutionMode( spv::ExecutionModeOutputVertices, makeOperands( allocator, ValueId{ maxVertices } ) );
		registerExecutionMode( spv::ExecutionModeOutputPrimitivesEXT, makeOperands( allocator, ValueId{ maxPrimitives } ) );
	}

	ValueId Module::registerString( std::string const & text )
	{
		ValueId result{ getNextId() };
		debugString.push_back( makeInstruction< StringInstruction >( nameCache
			, result
			, text ) );
		return result;
	}

	spv::Id Module::getIntermediateResult()
	{
		spv::Id result{};

		if ( m_freeIntermediates.empty() )
		{
			result = getNextId();
			m_intermediates.insert( result );
			m_freeIntermediates.insert( result );
		}

		result = *m_freeIntermediates.begin();
		m_freeIntermediates.erase( m_freeIntermediates.begin() );
		return result;
	}

	void Module::lnkIntermediateResult( ValueId intermediate, ValueId var )
	{
		if ( m_intermediates.end() != m_intermediates.find( intermediate.id ) )
		{
			m_busyIntermediates.emplace( intermediate.id, var );
		}
	}

	void Module::putIntermediateResult( ValueId id )
	{
#if SDW_Spirv_IntermediatesPerBlock
		if ( m_intermediates.end() != m_intermediates.find( id ) )
		{
			m_freeIntermediates.insert( id );
			auto it = m_busyIntermediates.begin();

			while ( it != m_busyIntermediates.end() )
			{
				if ( it->first == id
					|| it->second == id )
				{
					it = m_busyIntermediates.erase( it );
				}
				else
				{
					++it;
				}
			}
		}
#endif
	}

	ValueId Module::getNonIntermediate( ValueId id )
	{
		while ( m_intermediates.end() != m_intermediates.find( id.id ) )
		{
			auto it = m_busyIntermediates.find( id.id );
			assert( it != m_busyIntermediates.end() );
			id = it->second;
		}

		return id;
	}

	Function * Module::beginFunction( std::string name
		, TypeId retType
		, ast::var::VariableList const & params )
	{
		ValueId result{ getNextId() };
		m_registeredVariables.emplace( name, VariableInfo{ result, false, false, false } );

		TypeIdList funcTypes{ allocator };
		ValueIdList funcParams{ allocator };
		funcTypes.push_back( retType );
		m_currentFunction = &functions.emplace_back( allocator, result );
		m_currentFunction->registeredVariables = m_registeredVariables; // the function has access to global scope variables.
		m_currentScopeVariables = &m_currentFunction->registeredVariables;

		for ( auto & param : params )
		{
			auto type = param->getType();
			auto kind = type->getKind();
			funcTypes.push_back( registerType( type, nullptr ) );

			if ( isPointerParam( *param ) )
			{
				auto storage = ( isOpaqueType( kind )
					? spv::StorageClassUniformConstant
					: spv::StorageClassFunction );
				funcTypes.back() = registerPointerType( funcTypes.back(), storage );
			}

			ValueId paramId{ getNextId(), funcTypes.back()->type };
			funcParams.push_back( paramId );
			debug.push_back( makeInstruction< NameInstruction >( nameCache
				, paramId
				, param->getName() ) );

			m_currentScopeVariables->emplace( param->getName(), VariableInfo{ funcParams.back(), false, true, param->isOutputParam() } );
			m_registeredVariablesTypes.emplace( funcParams.back(), funcTypes.back() );
		}

		auto it = m_registeredFunctionTypes.find( funcTypes );
		TypeId funcTypeId;

		if ( it == m_registeredFunctionTypes.end() )
		{
			funcTypeId.id.id = getNextId();
			funcTypeId.debug.id = extDebugInfo ? getNextId() : 0u;
			it = m_registeredFunctionTypes.emplace( funcTypes, funcTypeId ).first;

			constantsTypes.push_back( makeInstruction< FunctionTypeInstruction >( nameCache
				, funcTypeId.id
				, convert( funcTypes ) ) );

			if ( extDebugInfo )
			{
				auto flagsId = registerLiteral( uint32_t( spv::NonSemanticShaderDebugInfo100DebugInfoFlags::IsPublic ) );
				makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeFunction
					, funcTypeId.debug
					, debug::makeValueIdList( allocator, flagsId, funcTypes ) );
			}
		}
		else
		{
			funcTypeId = it->second;
		}

		m_currentFunction->debugTypeId = funcTypeId.debug;
		m_currentFunction->declaration.emplace_back( makeInstruction< FunctionInstruction >( nameCache
			, retType.id
			, m_currentFunction->id
			, ValueId{ spv::Id( spv::FunctionControlMaskNone ) }
			, funcTypeId.id ) );
		auto itType = funcTypes.begin() + 1u;
		auto itParam = funcParams.begin();

		for ( auto i = params.begin(); i != params.end(); ++i )
		{
			m_currentFunction->declaration.emplace_back( makeInstruction< FunctionParameterInstruction >( nameCache
				, itType->id
				, *itParam ) );
			++itType;
			++itParam;
		}

		m_registeredVariablesTypes.emplace( m_currentFunction->id, funcTypeId );
		debug.push_back( makeInstruction< NameInstruction >( nameCache
			, result
			, std::move( name ) ) );
		variables = &m_currentFunction->variables;

		return m_currentFunction;
	}

	Block Module::newBlock()
	{
		Block result{ allocator, getNextId() };
		result.instructions.push_back( makeInstruction< LabelInstruction >( nameCache
			, ValueId{ result.label } ) );
		return result;
	}

	void Module::endFunction()
	{
		if ( m_currentFunction
			&& !m_currentFunction->cfg.blocks.empty()
			&& !m_currentFunction->variables.empty() )
		{
			auto & instructions = m_currentFunction->cfg.blocks.begin()->instructions;
			{
				auto params = std::move( m_currentFunction->promotedParams );
				std::reverse( params.begin(), params.end() );

				for ( auto & param : params )
				{
					instructions.emplace( instructions.begin() + 1u
						, std::move( param ) );
				}

				m_currentFunction->promotedParams.clear();
			}
			{
				auto vars = std::move( m_currentFunction->variables );
				std::reverse( vars.begin(), vars.end() );

				for ( auto & variable : vars )
				{
					instructions.emplace( instructions.begin() + 1u
						, std::move( variable ) );
				}

				m_currentFunction->variables.clear();
			}
		}

		variables = &globalDeclarations;
		m_currentScopeVariables = &m_registeredVariables;
		m_currentFunction = nullptr;
	}

	ValueId Module::makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
		, ValueIdList operands )
	{
		ValueId result{ getNextId() };
		makeDebugInstruction( instruction
			, result
			, std::move( operands ) );
		return result;
	}

	ValueId Module::makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
		, Block & block
		, ValueIdList operands )
	{
		ValueId result{ getNextId() };
		makeDebugInstruction( instruction
			, result
			, block
			, std::move( operands ) );
		return result;
	}

	void Module::makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
		, ValueId const & resultId
		, ValueIdList operands )
	{
		debugDeclarations.emplace_back( makeInstruction< ExtInstInstruction >( nameCache
			, m_voidType.id
			, resultId
			, debug::makeValueIdList( allocator, extDebugInfo, ValueId{ spv::Id( instruction ) }, operands ) ) );
	}

	void Module::makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
		, ValueId const & resultId
		, Block & block
		, ValueIdList operands )
	{
		block.instructions.emplace_back( makeInstruction< ExtInstInstruction >( nameCache
			, m_voidType.id
			, resultId
			, debug::makeValueIdList( allocator, extDebugInfo, ValueId{ spv::Id( instruction ) }, operands ) ) );
	}

	ValueId Module::registerDebugVariable( std::string const & name
		, ast::type::TypePtr type
		, uint64_t varFlags
		, ValueId const & variableId
		, glsl::Statement const * debugStatement )
	{
		ValueId result{ 0u, type };

		if ( debugStatement )
		{
			assert( ( ( varFlags & uint64_t( ast::var::Flag::eBuiltin ) ) != 0
					&& debugStatement->type == glsl::StatementType::eBuiltinVariableDecl )
				|| ( ( varFlags & uint64_t( ast::var::Flag::eBuiltin ) ) == 0
					&& ( debugStatement->type == glsl::StatementType::eVariableDecl || debugStatement->type == glsl::StatementType::eVariableBlockDecl ) ) );
			result.id = getNextId();
			auto nameId = registerString( name );
			auto typeId = registerType( type, debugStatement );
			auto lineId = registerLiteral( debugStatement->source.lineStart );
			auto columnId = registerLiteral( debugStatement->source.columnStart );
			auto flagsId = registerLiteral( debug::getFlags( varFlags ) );

			if ( ( varFlags & uint32_t( ast::var::Flag::eLocale ) ) )
			{
				makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::LocalVariable
					, result
					, debug::makeValueIdList( allocator, nameId, typeId, debugSourceId, lineId, columnId, m_currentScopeId, flagsId ) );
			}
			else
			{
				makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::GlobalVariable
					, result
					, debug::makeValueIdList( allocator, nameId, typeId, debugSourceId, lineId, columnId, globalScopeId, nameId, variableId, flagsId ) );
			}
		}

		return result;
	}

	ValueId Module::registerDebugMemberVariable( std::string const & name
		, ast::type::TypePtr type
		, uint64_t varFlags
		, glsl::Statement const * debugStatement )
	{
		ValueId result{ 0u, type };

		if ( debugStatement )
		{
			assert( debugStatement->type == glsl::StatementType::eVariableDecl
				|| debugStatement->type == glsl::StatementType::eStructureMemberDecl );
			auto mbrType = type->getParent()->getMember( type->getIndex() );

			result.id = getNextId();
			auto nameId = registerString( name );
			auto typeId = registerType( type, debugStatement );
			auto lineId = registerLiteral( debugStatement->source.lineStart );
			auto columnId = registerLiteral( debugStatement->source.columnStart );
			auto flagsId = registerLiteral( debug::getFlags( varFlags ) );
			auto offsetId = registerLiteral( mbrType.offset );
			auto sizeId = registerLiteral( mbrType.size );
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeMember
				, result
				, debug::makeValueIdList( allocator, nameId, typeId, debugSourceId, lineId, columnId, offsetId, sizeId, flagsId ) );
		}

		return result;
	}

	spv::Id Module::getNextId()
	{
		auto result = *m_currentId;
		++*m_currentId;
		return result;
	}

	TypeId Module::doRegisterNonArrayType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId parentId
		, glsl::Statement const * debugStatement )
	{
		TypeId result;
		auto unqualifiedType = module::getUnqualifiedType( *m_typesCache, type );
		auto it = m_registeredTypes.find( unqualifiedType );

		if ( it == m_registeredTypes.end() )
		{
			result = doRegisterBaseType( unqualifiedType
				, mbrIndex
				, parentId
				, 0u
				, debugStatement );
		}
		else
		{
			result = it->second;
		}

		return result;
	}

	TypeId Module::doRegisterTypeRec( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId parentId
		, uint32_t arrayStride
		, glsl::Statement const * debugStatement )
	{
		TypeId result{ 0u, type };

		if ( type->getRawKind() == ast::type::Kind::eArray )
		{
			auto arrayedType = static_cast< ast::type::Array const & >( *type ).getType();
			auto elementTypeId = doRegisterTypeRec( arrayedType
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
			auto unqualifiedType = module::getUnqualifiedType( *m_typesCache, type );
			auto it = m_registeredTypes.find( unqualifiedType );

			if ( it == m_registeredTypes.end() )
			{
				result.id.id = getNextId();
				result.debug.id = extDebugInfo ? getNextId() : 0u;
				m_registeredTypes.emplace( unqualifiedType, result );
				auto arraySize = getArraySize( type );

				if ( arraySize != ast::type::UnknownArraySize )
				{
					auto lengthId = registerLiteral( arraySize );
					constantsTypes.push_back( makeInstruction< ArrayTypeInstruction >( nameCache
						, result.id
						, elementTypeId.id
						, lengthId ) );

					if ( extDebugInfo && elementTypeId.debug )
					{
						makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeArray
							, result.debug
							, debug::makeValueIdList( allocator, elementTypeId, lengthId ) );
					}
				}
				else
				{
					constantsTypes.push_back( makeInstruction< RuntimeArrayTypeInstruction >( nameCache
						, result.id
						, elementTypeId.id ) );

					if ( extDebugInfo && elementTypeId.debug )
					{
						auto lengthId = registerLiteral( 1024u );
						makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeArray
							, result.debug
							, debug::makeValueIdList( allocator, elementTypeId, lengthId ) );
					}
				}

				module::writeArrayStride( *this
					, arrayedType
					, result.id
					, arrayStride );
			}
			else
			{
				result = it->second;
			}
		}
		else if ( type->getRawKind() == ast::type::Kind::ePointer )
		{
			auto & pointerType = static_cast< ast::type::Pointer const & >( *type );
			auto rawTypeId = doRegisterTypeRec( pointerType.getPointerType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
			auto storageClass = convert( pointerType.getStorage() );
			result = registerPointerType( rawTypeId
				, storageClass
				, pointerType.isForward() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eRayPayload )
		{
			auto & payloadType = static_cast< ast::type::RayPayload const & >( *type );
			result = doRegisterTypeRec( payloadType.getDataType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eCallableData )
		{
			auto & callableType = static_cast< ast::type::CallableData const & >( *type );
			result = doRegisterTypeRec( callableType.getDataType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eHitAttribute )
		{
			auto & callableType = static_cast< ast::type::HitAttribute const & >( *type );
			result = doRegisterTypeRec( callableType.getDataType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eGeometryOutput )
		{
			auto & outputType = static_cast< ast::type::GeometryOutput const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
			registerExecutionMode( outputType.getLayout(), outputType.getCount() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eGeometryInput )
		{
			auto & inputType = static_cast< ast::type::GeometryInput const & >( *type );
			result = doRegisterTypeRec( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
			registerExecutionMode( inputType.getLayout() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationInputPatch )
		{
			auto & outputType = static_cast< ast::type::TessellationInputPatch const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationOutputPatch )
		{
			auto & outputType = static_cast< ast::type::TessellationOutputPatch const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
		{
			auto & outputType = static_cast< ast::type::TessellationControlOutput const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
			registerExecutionMode( outputType.getDomain()
				, outputType.getPartitioning()
				, outputType.getTopology()
				, outputType.getOrder()
				, outputType.getOutputVertices() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationControlInput )
		{
			auto & inputType = static_cast< ast::type::TessellationControlInput const & >( *type );
			result = doRegisterTypeRec( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationEvaluationInput )
		{
			auto & inputType = static_cast< ast::type::TessellationEvaluationInput const & >( *type );
			result = doRegisterTypeRec( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
		{
			auto & outputType = static_cast< ast::type::MeshVertexOutput const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
		{
			auto & outputType = static_cast< ast::type::MeshPrimitiveOutput const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
		{
			auto & outputType = static_cast< ast::type::TaskPayloadNV const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayload )
		{
			auto & outputType = static_cast< ast::type::TaskPayload const & >( *type );
			result = doRegisterTypeRec( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
		{
			auto & inputType = static_cast< ast::type::TaskPayloadInNV const & >( *type );
			result = doRegisterTypeRec( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
		{
			auto & inputType = static_cast< ast::type::TaskPayloadIn const & >( *type );
			result = doRegisterTypeRec( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else if ( type->getRawKind() == ast::type::Kind::eComputeInput )
		{
			auto & inputType = static_cast< ast::type::ComputeInput const & >( *type );
			result = doRegisterTypeRec( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}
		else
		{
			result = doRegisterNonArrayType( type
				, mbrIndex
				, parentId
				, debugStatement );
		}

		return result;
	}

	TypeId Module::doRegisterBaseType( ast::type::Kind kind
		, uint32_t mbrIndex
		, TypeId parentId
		, uint32_t arrayStride
		, glsl::Statement const * debugStatement )
	{
		assert( kind != ast::type::Kind::eStruct );
		assert( kind != ast::type::Kind::eRayDesc );
		assert( kind != ast::type::Kind::eSampler );
		assert( kind != ast::type::Kind::eImage );
		assert( kind != ast::type::Kind::eSampledImage );
		assert( kind != ast::type::Kind::eCombinedImage );

		auto type = m_typesCache->getBasicType( kind );
		TypeId result{ 0u, type };
		result.id.id = getNextId();
		result.debug.id = extDebugInfo ? getNextId() : 0u;
		m_registeredTypes.emplace( type, result );

		if ( isVectorType( kind )
			|| isMatrixType( kind ) )
		{
			auto componentType = registerType( m_typesCache->getBasicType( getComponentType( kind ) ), debugStatement );
			auto componentCount = getComponentCount( kind );

			if ( isMatrixType( kind ) )
			{
				constantsTypes.push_back( makeInstruction< MatrixTypeInstruction >( nameCache
					, result.id
					, componentType.id
					, ValueId{ componentCount } ) );

				if ( extDebugInfo )
				{
					auto countId = registerLiteral( componentCount );
					auto majornessId = registerLiteral( true );
					makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeMatrix
						, result.debug
						, debug::makeValueIdList( allocator, componentType, countId, majornessId ) );
				}
			}
			else
			{
				constantsTypes.push_back( makeInstruction< VectorTypeInstruction >( nameCache
					, result.id
					, componentType.id
					, ValueId{ componentCount } ) );

				if ( extDebugInfo )
				{
					auto countId = registerLiteral( componentCount );
					makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeVector
						, result.debug
						, debug::makeValueIdList( allocator, componentType, countId ) );
				}
			}
		}
		else
		{
			constantsTypes.push_back( makeBaseTypeInstruction( nameCache
				, kind
				, result.id ) );

			if ( extDebugInfo )
			{
				if ( kind == ast::type::Kind::eVoid )
				{
					m_voidType = result;
				}

				auto nameId = registerString( glsl::getTypeName( kind ) );
				auto sizeId = registerLiteral( debug::getSize( kind ) );
				auto encodingId = registerLiteral( debug::getEncoding( kind ) );
				auto flagId = registerLiteral( 0u );
				makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeBasic
					, result.debug
					, debug::makeValueIdList( allocator, nameId, sizeId, encodingId, flagId ) );
			}
		}

		return result;
	}

	TypeId Module::doRegisterBaseType( ast::type::SamplerPtr type
		, uint32_t mbrIndex
		, TypeId parentId )
	{
		TypeId result{ 0u, type };
		result.id.id = getNextId();
		result.debug.id = extDebugInfo ? getNextId() : 0u;
		constantsTypes.push_back( makeInstruction< SamplerTypeInstruction >( nameCache
			, result.id ) );
		m_registeredTypes.emplace( type, result );

		if ( extDebugInfo )
		{
			auto tagId = registerLiteral( 0u );
			auto nameId = registerString( "@sampler" );
			auto lineId = registerLiteral( 0u );
			auto columnId = registerLiteral( 0u );
			auto flagId = registerLiteral( 0u );
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
				, result.debug
				, debug::makeValueIdList( allocator, nameId, tagId, debugSourceId, lineId, columnId, globalScopeId, nameId, m_debugInfoNone, flagId ) );
		}

		return result;
	}

	TypeId Module::doRegisterBaseType( ast::type::CombinedImagePtr type
		, uint32_t mbrIndex
		, TypeId parentId )
	{
		auto imgTypeId = doRegisterBaseType( type->getImageType()
			, type->isComparison() ? ast::type::Trinary::eTrue : ast::type::Trinary::eFalse );
		TypeId result{ 0u, type };
		result.id.id = getNextId();
		result.debug.id = extDebugInfo ? getNextId() : 0u;
		constantsTypes.push_back( makeInstruction< TextureTypeInstruction >( nameCache
			, result.id
			, imgTypeId.id ) );
		m_registeredTypes.emplace( type, result );

		if ( extDebugInfo )
		{
			auto tagId = registerLiteral( 0u );
			auto nameId = registerString( "@" + glsl::getTypeName( type ) );
			auto lineId = registerLiteral( 0u );
			auto columnId = registerLiteral( 0u );
			auto flagId = registerLiteral( 0u );
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
				, result.debug
				, debug::makeValueIdList( allocator, nameId, tagId, debugSourceId, lineId, columnId, globalScopeId, nameId, m_debugInfoNone, flagId ) );
		}

		return result;
	}

	TypeId Module::doRegisterBaseType( ast::type::ImagePtr type
		, ast::type::Trinary isComparison )
	{
		auto ires = m_registeredImageTypes.emplace( module::myHash( type->getConfig(), isComparison ), TypeId{} );
		auto it = ires.first;

		if ( ires.second )
		{
			// The Sampled Type.
			auto sampledTypeId = registerType( m_typesCache->getBasicType( type->getConfig().sampledType ), nullptr );
			// The Image Type.
			it->second = TypeId{ getNextId(), type };
			it->second.debug.id = extDebugInfo ? getNextId() : 0u;
			constantsTypes.push_back( makeImageTypeInstruction( nameCache
				, type->getConfig()
				, isComparison
				, it->second.id
				, sampledTypeId.id ) );
			m_registeredTypes.emplace( type, it->second );

			if ( extDebugInfo )
			{
				auto tagId = registerLiteral( 0u );
				auto nameId = registerString( "@" + glsl::getTypeName( type ) );
				auto lineId = registerLiteral( 0u );
				auto columnId = registerLiteral( 0u );
				auto flagId = registerLiteral( 0u );
				makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
					, it->second.debug
					, debug::makeValueIdList( allocator, nameId, tagId, debugSourceId, lineId, columnId, globalScopeId, nameId, m_debugInfoNone, flagId ) );
			}
		}

		return it->second;
	}

	TypeId Module::doRegisterBaseType( ast::type::ImagePtr type
		, uint32_t mbrIndex
		, TypeId parent )
	{
		return doRegisterBaseType( type, ast::type::Trinary::eFalse );
	}

	TypeId Module::doRegisterBaseType( ast::type::SampledImagePtr type
		, uint32_t mbrIndex
		, TypeId parent )
	{
		return doRegisterBaseType( type->getImageType(), type->getDepth() );
	}

	TypeId Module::doRegisterBaseType( ast::type::AccelerationStructurePtr type
		, uint32_t mbrIndex
		, TypeId parentId
		, glsl::Statement const * debugStatement )
	{
		TypeId result{ 0u, type };
		result.id.id = getNextId();
		result.debug.id = extDebugInfo ? getNextId() : 0u;
		constantsTypes.push_back( makeAccelerationStructureTypeInstruction( nameCache
			, result.id ) );
		auto ires = m_registeredTypes.emplace( type, result );

		if ( ires.second && extDebugInfo )
		{
			auto tagId = registerLiteral( 0u );
			auto nameId = registerString( "@accelerationStructure" );
			auto lineId = registerLiteral( 0u );
			auto columnId = registerLiteral( 0u );
			auto flagId = registerLiteral( 0u );
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
				, result.debug
				, debug::makeValueIdList( allocator, nameId, tagId, debugSourceId, lineId, columnId, globalScopeId, nameId, m_debugInfoNone, flagId ) );
		}

		return result;
	}

	TypeId Module::doRegisterBaseType( ast::type::StructPtr type
		, uint32_t
		, TypeId
		, glsl::Statement const * debugStatement )
	{
		TypeId result{ 0u, type };
		result.id.id = getNextId();
		result.debug.id = extDebugInfo ? getNextId() : 0u;
		TypeIdList subTypes{ allocator };
		ValueIdList debugSubTypes{ allocator };

		for ( auto & member : *type )
		{
			auto subTypeId = doRegisterTypeRec( member.type
				, member.type->getIndex()
				, result
				, member.arrayStride
				, debugStatement );
			subTypes.push_back( subTypeId );

			if ( extDebugInfo )
			{
				auto nameId = registerString( member.name );
				auto lineId = registerLiteral( debugStatement ? debugStatement->source.lineStart : 0u );
				auto columnId = registerLiteral( debugStatement ? debugStatement->source.columnStart : 0u );
				auto flagId = registerLiteral( 0u );
				auto offsetId = registerLiteral( member.offset );
				auto sizeId = registerLiteral( member.size );
				debugSubTypes.push_back( makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeMember
					, debug::makeValueIdList( allocator, nameId, subTypeId, debugSourceId, lineId, columnId, offsetId, sizeId, flagId ) ) );
			}
		}

		constantsTypes.push_back( makeInstruction< StructTypeInstruction >( nameCache
			, result.id
			, convert( subTypes ) ) );
		debug.push_back( makeInstruction< NameInstruction >( nameCache
			, result.id
			, type->getName() ) );
		bool hasBuiltin = false;
		bool hasDynarray = false;

		for ( auto & member : *type )
		{
			auto index = member.type->getIndex();
			debug.push_back( makeInstruction< MemberNameInstruction >( nameCache
				, result.id
				, ValueId{ index }
				, member.name ) );

			if ( member.builtin == ast::Builtin::eNone )
			{
				decorateMember( result.id
					, index
					, makeIdList( allocator, uint32_t( spv::DecorationOffset ), member.offset ) );
			}
			else
			{
				doAddMbrBuiltin( member.builtin, result.id, index );
				hasBuiltin = true;
			}

			auto kind = getNonArrayKind( member.type );
			auto arraySize = getArraySize( member.type );

			if ( arraySize == ast::type::UnknownArraySize )
			{
				hasDynarray = true;
			}

			if ( isMatrixType( kind ) )
			{
				auto colKind = getComponentType( kind );
				auto colType = m_typesCache->getBasicType( colKind );
				auto rowCount = getComponentCount( colType );

				if ( rowCount == 3
					|| ( rowCount == 2 && type->getMemoryLayout() == ast::type::MemoryLayout::eStd140 ) )
				{
					colType = m_typesCache->getVector( getComponentType( colKind ), 4u );
				}

				auto size = getSize( *colType
					, type->getMemoryLayout() );
				decorateMember( result.id
					, index
					, spv::DecorationColMajor );
				decorateMember( result.id
					, index
					, makeIdList( allocator, uint32_t( spv::DecorationMatrixStride ), size ) );
			}
		}

		if ( hasBuiltin || hasDynarray )
		{
			decorate( result.id, spv::DecorationBlock );
		}

		m_registeredTypes.emplace( type, result );

		if ( extDebugInfo )
		{
			auto tagId = registerLiteral( 1u );
			auto nameId = registerString( glsl::getTypeName( type ) );
			auto lineId = registerLiteral( debugStatement ? debugStatement->source.lineStart : 0u );
			auto columnId = registerLiteral( debugStatement ? debugStatement->source.columnStart : 0u );
			auto flagId = registerLiteral( 0u );
			auto sizeId = registerLiteral( type->empty() ? 0u : getSize( type, type->getMemoryLayout() ) );
			makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite
				, result.debug
				, debug::makeValueIdList( allocator, nameId, tagId, debugSourceId, lineId, columnId, globalScopeId, nameId, sizeId, flagId, debugSubTypes ) );
		}

		return result;
	}

	TypeId Module::doRegisterBaseType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId parentId
		, uint32_t arrayStride
		, glsl::Statement const * debugStatement )
	{
		TypeId result{ 0u, type };

		if ( type->getRawKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		auto kind = type->getRawKind();

		if ( kind == ast::type::Kind::eSampler )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::Sampler >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eCombinedImage )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::CombinedImage >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eImage )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::Image >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eSampledImage )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::SampledImage >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eAccelerationStructure )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::AccelerationStructure >( type )
				, mbrIndex
				, parentId
				, debugStatement );
		}
		else if ( kind == ast::type::Kind::eStruct
			|| kind == ast::type::Kind::eRayDesc )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::Struct >( type )
				, mbrIndex
				, parentId
				, debugStatement );
		}
		else
		{
			result = doRegisterBaseType( kind
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
		}

		return result;
	}

	void Module::doReplaceDecoration( ValueId id
		, spv::Decoration oldDecoration
		, spv::Decoration newDecoration )
	{
		auto varIt = varDecorations.find( id );
		bool processed = false;

		if ( varIt != varDecorations.end() )
		{
			size_t dist;
			auto listIt = std::find_if( varIt->second.begin(), varIt->second.end()
				, [&oldDecoration, &dist]( DecorationMap::value_type const & listIdx )
				{
					auto result = std::find_if( listIdx.first.begin(), listIdx.first.end()
						, [&oldDecoration]( ValueId const & lookup )
						{
							return spv::Id( oldDecoration ) == lookup.id;
						} );

					if ( result != listIdx.first.end() )
					{
						dist = size_t( std::distance( listIdx.first.begin(), result ) );
					}

					return result != listIdx.first.end();
				} );

			if ( listIt != varIt->second.end() )
			{
				auto list = listIt->first;
				auto idx = listIt->second;
				varIt->second.erase( listIt );
				list[dist] = ValueId{ spv::Id( newDecoration ) };
				decorations[idx]->operands[dist + 1u] = spv::Id( newDecoration );
				varIt->second.emplace( list, idx );
				processed = true;
			}
		}

		if ( !processed )
		{
			IdList list{ allocator };
			list.push_back( spv::Id( newDecoration ) );
			decorate( id, list );
		}
	}

	void Module::doReplaceMemberDecoration( ValueId id
		, uint32_t index
		, spv::Decoration oldDecoration
		, spv::Decoration newDecoration )
	{
		auto mbrIt = mbrDecorations.find( makeOperands( allocator, id, ValueId{ index } ) );
		bool processed = false;

		if ( mbrIt != mbrDecorations.end() )
		{
			size_t dist;
			auto listIt = std::find_if( mbrIt->second.begin(), mbrIt->second.end()
				, [&oldDecoration, &dist]( DecorationMap::value_type const & listIdx )
				{
					auto result = std::find_if( listIdx.first.begin(), listIdx.first.end()
						, [&oldDecoration]( ValueId const & lookup )
						{
							return spv::Id( oldDecoration ) == lookup.id;
						} );

					if ( result != listIdx.first.end() )
					{
						dist = size_t( std::distance( listIdx.first.begin(), result ) );
					}

					return result != listIdx.first.end();
				} );

			if ( listIt != mbrIt->second.end() )
			{
				auto list = listIt->first;
				auto idx = listIt->second;
				mbrIt->second.erase( listIt );
				list[dist] = ValueId{ spv::Id( newDecoration ) };
				decorations[idx]->operands[dist + 2u] = spv::Id( newDecoration );
				mbrIt->second.emplace( list, idx );
				processed = true;
			}
		}

		if ( !processed )
		{
			IdList list{ allocator };
			list.push_back( spv::Id( newDecoration ) );
			decorateMember( id, index, list );
		}
	}

	void Module::doInitialiseHeader( Header const & rhs )
	{
		header.push_back( rhs.magic );
		header.push_back( rhs.version );
		header.push_back( rhs.builder );
		header.push_back( rhs.boundIds );
		header.push_back( rhs.schema );
		m_currentId = &header[3];
	}

	void Module::doInitialiseExtensions( bool enableDebug )
	{
		extGlslStd450 = ValueId{ getIntermediateResult() };
		imports.push_back( makeInstruction< ExtInstImportInstruction >( nameCache
			, extGlslStd450
			, "GLSL.std.450" ) );

		if ( enableDebug )
		{
			extDebugInfo = ValueId{ getIntermediateResult() };
			imports.emplace_back( makeInstruction< ExtInstImportInstruction >( nameCache
				, extDebugInfo
				, "NonSemantic.Shader.DebugInfo.100" ) );
		}

		debug.push_back( makeInstruction< SourceInstruction >( nameCache
			, ValueId{ spv::Id( spv::SourceLanguageGLSL ) }
			, ValueId{ 460u } ) );
	}

	void Module::doInitialiseCapacities()
	{
		switch ( m_model )
		{
		case spv::ExecutionModelVertex:
		case spv::ExecutionModelFragment:
		case spv::ExecutionModelGLCompute:
			insertCapability( nameCache, capabilities, spv::CapabilityShader );
			break;
		case spv::ExecutionModelTessellationControl:
		case spv::ExecutionModelTessellationEvaluation:
			insertCapability( nameCache, capabilities, spv::CapabilityShader );
			insertCapability( nameCache, capabilities, spv::CapabilityTessellation );
			break;
		case spv::ExecutionModelGeometry:
			insertCapability( nameCache, capabilities, spv::CapabilityShader );
			insertCapability( nameCache, capabilities, spv::CapabilityGeometry );
			break;
		case spv::ExecutionModelTaskNV:
		case spv::ExecutionModelMeshNV:
			insertCapability( nameCache, capabilities, spv::CapabilityShader );
			insertCapability( nameCache, capabilities, spv::CapabilityMeshShadingNV );
			break;
		case spv::ExecutionModelTaskEXT:
		case spv::ExecutionModelMeshEXT:
			insertCapability( nameCache, capabilities, spv::CapabilityShader );
			insertCapability( nameCache, capabilities, spv::CapabilityMeshShadingEXT );
			break;
		case spv::ExecutionModelAnyHitKHR:
		case spv::ExecutionModelCallableKHR:
		case spv::ExecutionModelClosestHitKHR:
		case spv::ExecutionModelIntersectionKHR:
		case spv::ExecutionModelMissKHR:
		case spv::ExecutionModelRayGenerationKHR:
			insertCapability( nameCache, capabilities, spv::CapabilityShader );
			insertCapability( nameCache, capabilities, spv::CapabilityRayTracingKHR );
			break;
		case spv::ExecutionModelKernel:
			insertCapability( nameCache, capabilities, spv::CapabilityKernel );
			break;
		default:
			AST_Failure( "Unsupported ExecutionModel" );
			break;
		}
	}

	void Module::doInitialiseDebug( bool isDebugEnabled
		, glsl::Statements const & debugStatements )
	{
		if ( isDebugEnabled )
		{
			m_voidType = doRegisterBaseType( ast::type::Kind::eVoid, ast::type::NotMember, TypeId{}, 0u, nullptr );

			m_debugInfoNone = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::InfoNone
				, ValueIdList{ allocator } );

			auto sourceNameId = registerString( "main.glsl" );
			auto sourceTextId = registerString( debugStatements.source );
			debugSourceId = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::Source
				, debug::makeValueIdList( allocator, sourceNameId, sourceTextId ) );

			auto spvVersionId = registerLiteral( 1u );
			auto dwarfVersionId = registerLiteral( 4u );
			auto languageId = registerLiteral( 2u );
			globalScopeId = makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions::CompilationUnit
				, debug::makeValueIdList( allocator, spvVersionId, dwarfVersionId, debugSourceId, languageId ) );

			m_currentScopeId = globalScopeId;
		}
	}

	void Module::doAddDebug( std::string const & name
		, ValueId id )
	{
		auto type = unwrapType( id.type );

		if ( ( type->getKind() != ast::type::Kind::eStruct
				&& type->getKind() != ast::type::Kind::eRayDesc )
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() != name )
		{
			debug.push_back( makeInstruction< NameInstruction >( nameCache
				, id
				, name ) );
		}
		else if ( type->getKind() == ast::type::Kind::eStruct
			|| type->getKind() == ast::type::Kind::eRayDesc
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() == name )
		{
			debug.push_back( makeInstruction< NameInstruction >( nameCache
				, id
				, name + "Inst" ) );
		}
	}

	void Module::doAddBuiltin( ast::Builtin pbuiltin
		, ValueId id )
	{
		Vector< spv::Decoration > additionalDecorations{ allocator };
		auto builtin = getBuiltin( pbuiltin, m_model, additionalDecorations );

		if ( builtin != spv::BuiltInMax )
		{
			decorate( id, makeIdList( allocator, spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) ) );

			for ( auto & decoration : additionalDecorations )
			{
				decorate( id, decoration );
			}
		}
	}

	bool Module::doAddMbrBuiltin( ast::Builtin pbuiltin
		, ValueId outer
		, uint32_t mbrIndex )
	{
		bool result = false;
		Vector< spv::Decoration > additionalDecorations{ allocator };
		auto builtin = getBuiltin( pbuiltin, m_model, additionalDecorations );

		if ( builtin != spv::BuiltInMax )
		{
			decorateMember( outer, mbrIndex, makeIdList( allocator, spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) ) );

			for ( auto & decoration : additionalDecorations )
			{
				decorateMember( outer, mbrIndex, decoration );
			}

			result = true;
		}

		return result;
	}

	void Module::doAddVariable( std::string name
		, ValueId varId
		, Map< std::string, VariableInfo >::iterator & it
		, ValueId initialiser
		, glsl::Statement const * debugStatement )
	{
		assert( varId.isPointer() );
		auto type = varId.type;
		auto rawType = static_cast< ast::type::Pointer const & >( *type ).getPointerType();
		auto rawTypeId = registerType( rawType, debugStatement );
		auto typeStorage = varId.getStorage();

		if ( typeStorage == ast::type::Storage::ePushConstant )
		{
			decorate( rawTypeId.id, spv::DecorationBlock );
		}

		auto varTypeId = registerPointerType( rawTypeId
			, convert( typeStorage ) );

		if ( varId.getStorage() == ast::type::Storage::eFunction
			&& m_currentFunction )
		{
			it = module::addVariable( nameCache
				, varTypeId.id
				, varId
				, std::move( name )
				, initialiser
				, *m_currentScopeVariables
				, m_currentFunction->variables );
		}
		else
		{
			it = module::addVariable( nameCache
				, varTypeId.id
				, varId
				, std::move( name )
				, initialiser
				, m_registeredVariables
				, globalDeclarations );

			if ( m_currentScopeVariables
				&& m_currentScopeVariables != &m_registeredVariables )
			{
				// Register globals to current scope too.
				m_currentScopeVariables->insert( *it );
			}
		}

		m_registeredVariablesTypes.emplace( varId, rawTypeId );
	}

	InstructionList * Module::doSelectInstructionsList( spv::Op opCode )
	{
		InstructionList * list{ nullptr };

		switch ( opCode )
		{
		case spv::OpSource:
		case spv::OpSourceExtension:
		case spv::OpName:
		case spv::OpString:
		case spv::OpMemberName:
			list = &debug;
			break;
		case spv::OpExtInstImport:
		case spv::OpExtension:
			list = &extensions;
			break;
		case spv::OpCapability:
			list = &capabilities;
			break;
		case spv::OpExecutionMode:
			list = &executionModes;
			break;
		case spv::OpDecorate:
		case spv::OpMemberDecorate:
			list = &decorations;
			break;
		case spv::OpVariable:
			list = &globalDeclarations;
			break;
		case spv::OpTypeVoid:
		case spv::OpTypeBool:
		case spv::OpTypeInt:
		case spv::OpTypeFloat:
		case spv::OpTypeVector:
		case spv::OpTypeMatrix:
		case spv::OpTypeImage:
		case spv::OpTypeSampler:
		case spv::OpTypeSampledImage:
		case spv::OpTypeArray:
		case spv::OpTypeRuntimeArray:
		case spv::OpTypeStruct:
		case spv::OpTypeOpaque:
		case spv::OpTypePointer:
		case spv::OpTypeFunction:
		case spv::OpTypeEvent:
		case spv::OpTypeDeviceEvent:
		case spv::OpTypeReserveId:
		case spv::OpTypeQueue:
		case spv::OpTypePipe:
		case spv::OpTypeForwardPointer:
		case spv::OpConstant:
		case spv::OpConstantComposite:
		case spv::OpConstantFalse:
		case spv::OpConstantTrue:
		case spv::OpSpecConstant:
		case spv::OpSpecConstantComposite:
		case spv::OpSpecConstantFalse:
		case spv::OpSpecConstantTrue:
			list = &constantsTypes;
			break;
		default:
			break;
		}

		return list;
	}

	bool Module::doDeserializeInfos( spv::Op opCode
		, InstructionList::iterator & current
		, InstructionList::iterator end )
	{
		bool result = false;

		switch ( opCode )
		{
		case spv::OpMemoryModel:
			memoryModel = std::move( *current );
			result = true;
			++current;
			break;
		case spv::OpEntryPoint:
			entryPoint = std::move( *current );
			result = true;
			++current;
			break;
		default:
			break;
		}

		return result;
	}

	bool Module::doDeserializeFuncs( spv::Op opCode
		, InstructionList::iterator & current
		, InstructionList::iterator end )
	{
		bool result = false;

		switch ( opCode )
		{
		case spv::OpFunction:
			functions.emplace_back( Function::deserialize( allocator, current, end ) );
			result = true;
			break;
		default:
			break;
		}

		return result;
	}

	//*************************************************************************
}
