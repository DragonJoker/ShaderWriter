/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvModule.hpp"

#include "SpirvHelpers.hpp"
#include "SpirvSerialize.hpp"
#include "SpirvWrite.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#include <algorithm>

#define SDW_Spirv_IntermediatesPerBlock 0

namespace spirv
{
	//*************************************************************************

	namespace
	{
		ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::TypePtr qualified );

		ast::type::StructPtr getUnqualifiedType( ast::type::TypesCache & typesCache
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

		ast::type::ArrayPtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Array const & qualified )
		{
			return typesCache.getArray( getUnqualifiedType( typesCache, qualified.getType() ), qualified.getArraySize() );
		}

		ast::type::SamplerPtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Sampler const & qualified )
		{
			return typesCache.getSampler( qualified.isComparison() );
		}

		ast::type::CombinedImagePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::CombinedImage const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return typesCache.getCombinedImage( config, qualified.isComparison() );
		}

		ast::type::SampledImagePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::SampledImage const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return typesCache.getSampledImage( config, qualified.getDepth() );
		}

		ast::type::ImagePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::Image const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return typesCache.getImage( config );
		}

		ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & typesCache
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

		ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & typesCache
			, ast::type::TypePtr qualified )
		{
			ast::type::TypePtr result = getUnqualifiedType( typesCache, *qualified );
			return result
				? result
				: qualified;
		}

		void writeArrayStride( Module & module
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
					, IdList
					{
						uint32_t( spv::DecorationArrayStride ),
						arrayStride
					} );
			}
		}

		std::map< std::string, VariableInfo >::iterator doAddVariable( ValueId varTypeId
			, ValueId varId
			, std::string name
			, ValueId initialiser
			, std::map< std::string, VariableInfo > & variables
			, InstructionList & instructions )
		{
			auto result = variables.emplace( std::move( name ), VariableInfo{} ).first;
			result->second.id = varId;
			result->second.isParam = false;
			result->second.isAlias = false;
			instructions.push_back( makeVariableInstruction( varTypeId
				, varId
				, initialiser ) );
			return result;
		}

		size_t myHash( ast::type::ImageConfiguration const & config
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
	}

	//*************************************************************************

	static uint32_t constexpr VendorID = 33u;
	static uint32_t constexpr Version = 0x0012u;

	Module::Module( ast::type::TypesCache & typesCache
		, SpirVConfig const & spirvConfig
		, spv::AddressingModel addressingModel
		, spv::MemoryModel pmemoryModel
		, spv::ExecutionModel pexecutionModel )
		: memoryModel{ makeInstruction< MemoryModelInstruction >( ValueId{ spv::Id( addressingModel ) }, ValueId{ spv::Id( pmemoryModel ) } ) }
		, variables{ &globalDeclarations }
		, m_version{ spirvConfig.specVersion }
		, m_typesCache{ &typesCache }
		, m_currentScopeVariables{ &m_registeredVariables }
		, m_model{ pexecutionModel }
	{
		initialiseHeader( { spv::MagicNumber
			, m_version
			, ( VendorID << 16 ) | Version
			, 1u	/* Bound IDs. */
			, 0u	/* Schema. */ } );
		initialiseExtensions();
		initialiseCapacities();
	}

	Module::Module( Header const & pheader
		, InstructionList instructions )
		: variables{ &globalDeclarations }
	{
		initialiseHeader( pheader );
		auto it = instructions.begin();

		while ( it != instructions.end() )
		{
			auto opCode = spv::Op( ( *it )->op.opData.opCode );

			if ( !deserializeInfos( opCode, it, instructions.end() ) )
			{
				if ( !deserializeFuncs( opCode, it, instructions.end() ) )
				{
					if ( auto * list = selectInstructionsList( opCode ) )
					{
						list->emplace_back( std::move( *it ) );
						++it;
					}
				}
			}
		}
	}

	Module Module::deserialize( UInt32List const & spirv )
	{
		BufferCIt buffer{ spirv.cbegin(), 0u };
		Header header{};
		header.magic = buffer.popValue();
		assert( header.magic == spv::MagicNumber );
		header.version = buffer.popValue();
		header.builder = buffer.popValue();
		header.boundIds = buffer.popValue();
		header.schema = buffer.popValue();
		spirv::InstructionList instructions;

		while ( buffer.it != spirv.end() )
		{
			instructions.emplace_back( buffer.popInstruction() );
		}

		return Module{ header, std::move( instructions ) };
	}

	std::string spirv::Module::write( spirv::Module const & module
		, bool writeHeader )
	{
		return spirv::write( module, writeHeader );
	}

	std::vector< uint32_t > spirv::Module::serialize( spirv::Module const & module )
	{
		return spirv::serialize( module );
	}

	ValueId Module::registerType( ast::type::TypePtr type )
	{
		return registerType( type
			, ast::type::NotMember
			, ValueId{}
			, 0u );
	}

	ValueId Module::registerImageType( ast::type::ImagePtr image
		, bool isComparison )
	{
		return registerBaseType( image
			, isComparison ? ast::type::Trinary::eTrue : ast::type::Trinary::eFalse );
	}

	ValueId Module::registerPointerType( ValueId type
		, spv::StorageClass storage
		, bool isForward )
	{
		uint64_t key = ( uint64_t( type.id ) << 33 )
			| ( ( uint64_t( type.isPointer() ) << 32 ) & 0x01 )
			| ( uint64_t( storage ) << 1 )
			| ( isForward & 0x01 );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			ValueId id{ getNextId()
				, type.type->getTypesCache().getPointerType( type.type, convert( storage ) ) };
			it = m_registeredPointerTypes.emplace( key, id ).first;

			if ( isForward )
			{
				globalDeclarations.push_back( makeInstruction< ForwardPointerTypeInstruction >( id
					, ValueId{ spv::Id( storage ) } ) );
				globalDeclarations.push_back( makeInstruction< PointerTypeInstruction >( id
					, ValueId{ spv::Id( storage ) }
					, type ) );
				key = ( uint64_t( type.id ) << 33 )
					| ( ( uint64_t( type.isPointer() ) << 32 ) & 0x01 )
					| ( uint64_t( storage ) << 1 );
				m_registeredPointerTypes.emplace( key, id );
			}
			else
			{
				globalDeclarations.push_back( makeInstruction< PointerTypeInstruction >( id
					, ValueId{ spv::Id( storage ) }
					, type ) );
			}
		}

		return it->second;
	}

	void Module::decorate( ValueId id, spv::Decoration decoration )
	{
		if ( decoration == spv::DecorationBufferBlock )
		{
			// Since we can't have both Block and BufferBlock decorations, replace the former with the latter.
			replaceDecoration( id, spv::DecorationBlock, decoration );
		}
		else
		{
			decorate( id, { spv::Id( decoration ) } );
		}
	}

	void Module::decorate( ValueId id
		, IdList const & pdecorations )
	{
		auto it = varDecorations.emplace( id, DecorationMap{} ).first;
		auto decos = convert( pdecorations );
		auto ires = it->second.emplace( decos, 0u );

		if ( ires.second )
		{
			ValueIdList operands;
			operands.push_back( id );
			operands.insert( operands.end(), decos.begin(), decos.end() );
			ires.first->second = decorations.size();
			decorations.push_back( makeInstruction< DecorateInstruction >( operands ) );
		}
	}

	void Module::decorateMember( ValueId id
		, uint32_t index
		, spv::Decoration decoration )
	{
		if ( decoration == spv::DecorationBufferBlock )
		{
			// Since we can't have both Block and BufferBlock decorations, replace the former with the latter.
			replaceMemberDecoration( id, index, spv::DecorationBlock, decoration );
		}
		else
		{
			decorateMember( id, index, IdList{ spv::Id( decoration ) } );
		}
	}

	void Module::decorateMember( ValueId id
		, uint32_t index
		, IdList const & pdecorations )
	{
		auto it = mbrDecorations.emplace( ValueIdList{ id, ValueId{ index } }, DecorationMap{} ).first;
		auto decos = convert( pdecorations );
		auto ires = it->second.emplace( decos, 0u );

		if ( ires.second )
		{
			ValueIdList operands;
			operands.push_back( id );
			operands.push_back( { index } );
			operands.insert( operands.end(), decos.begin(), decos.end() );
			ires.first->second = decorations.size();
			decorations.push_back( makeInstruction< MemberDecorateInstruction >( operands ) );
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
			addDebug( name, id );
			std::map< std::string, VariableInfo >::iterator it;
			addVariable( name, id, it, {} );
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
		std::map< std::string, VariableInfo >::iterator it;

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

		instructions.push_back( makeInstruction< StoreInstruction >( variable
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
				auto typeId = registerType( type );
				ValueId result{ getIntermediateResult(), typeId.type };

				if ( variable.getStorage() == ast::type::Storage::ePhysicalStorageBuffer )
				{
					// Loading from PhysicalStorageBuffer needs to set the alignment
					auto structType = getStructType( type );
					instructions.push_back( makeInstruction< LoadInstruction >( typeId
						, result
						, ValueIdList{ variable
						, ValueId{ spv::Id( spv::MemoryAccessAlignedMask ) }
						, ValueId{ ast::type::getAlignment( type
							, ( structType
								? structType->getMemoryLayout()
								: ast::type::MemoryLayout::eScalar ) ) } } ) );
				}
				else
				{
					instructions.push_back( makeInstruction< LoadInstruction >( typeId
						, result
						, ValueIdList{ variable
						, ValueId{ spv::Id( spv::MemoryAccessMaskNone ) } } ) );
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
			, std::unordered_map< ValueId, ValueId, ValueIdHasher >{} ).first;
		auto ires = lhsIt->second.emplace( sampler, ValueId{} );
		auto it = ires.first;

		if ( ires.second )
		{
			auto typeId = registerType( image.type->getTypesCache().getCombinedImage( imgType.getConfig()
				, splType.isComparison() ) );
			it->second = { getNextId(), typeId.type };
			currentBlock.instructions.push_back( makeInstruction< SampledImageInstruction >( typeId, it->second, image, sampler ) );
		}

		return it->second;
	}

	void Module::bindVariable( ValueId varId
		, uint32_t bindingPoint
		, uint32_t descriptorSet )
	{
		decorate( varId, { spv::Id( spv::DecorationBinding ), bindingPoint } );
		decorate( varId, { spv::Id( spv::DecorationDescriptorSet ), descriptorSet } );
	}

	void Module::bindBufferVariable( std::string const & name
		, uint32_t bindingPoint
		, uint32_t descriptorSet
		, spv::Decoration structDecoration )
	{
		auto varIt = m_currentScopeVariables->find( name );

		if ( varIt != m_currentScopeVariables->end() )
		{
			auto varId = varIt->second.id;
			decorate( varId, { spv::Id( spv::DecorationBinding ), bindingPoint } );
			decorate( varId, { spv::Id( spv::DecorationDescriptorSet ), descriptorSet } );

			auto typeIt = m_registeredVariablesTypes.find( varId );

			if ( typeIt != m_registeredVariablesTypes.end() )
			{
				auto typeId = typeIt->second;
				decorate( typeId, structDecoration );
			}
		}
	}

	VariableInfo Module::registerParam( std::string name
		, bool isOutput
		, ast::type::TypePtr type )
	{
		auto typeId = registerType( type );
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			auto rawTypeId = registerType( type );

			if ( m_currentFunction )
			{
				it = m_currentScopeVariables->emplace( std::move( name )
					, VariableInfo{ typeId, false, true, isOutput } ).first;
			}
			else
			{
				it = m_registeredVariables.emplace( std::move( name )
					, VariableInfo{ typeId, false, true, isOutput } ).first;
			}

			m_registeredVariablesTypes.emplace( typeId, rawTypeId );
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
			auto rawTypeId = registerType( type );

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
		, ValueId initialiser )
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
						auto typeId = registerType( type );

						if ( storage == spv::StorageClassPhysicalStorageBuffer
							|| storage == spv::StorageClassUniform
							|| storage == spv::StorageClassStorageBuffer )
						{
							decorate( typeId, spv::DecorationBlock );
						}
						else
						{
							decorate( typeId, spv::DecorationBlock );
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

			addDebug( name, id );

			if ( builtin != ast::Builtin::eNone )
			{
				addBuiltin( builtin, id );
			}

			addVariable( std::move( name ), id, it, initialiser );
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
							? static_cast< ast::type::Pointer const & >( *it->second.id.type ).getPointerType()
							: it->second.id.type )
						, convert( storage ) ) };
				it->second.isAlias = false;
				it->second.isParam = false;
				it->second.isOutParam = false;
				addDebug( "ptr_" + name, id );
				addVariable( std::move( name ), id, it, {} );

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
			auto rawTypeId = registerType( type );
			IdList operands;
			debug.push_back( makeInstruction< NameInstruction >( id, name ) );

			if ( value.getLiteralType() == ast::expr::LiteralType::eBool )
			{
				if ( value.getValue< ast::expr::LiteralType::eBool >() )
				{
					globalDeclarations.emplace_back( makeInstruction< SpecConstantTrueInstruction >( rawTypeId, id ) );
				}
				else
				{
					globalDeclarations.emplace_back( makeInstruction< SpecConstantFalseInstruction >( rawTypeId, id ) );
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

				globalDeclarations.emplace_back( makeInstruction< SpecConstantInstruction >( rawTypeId
					, id
					, operands ) );
			}

			decorate( id, { spv::Id( spv::DecorationSpecId ), location } );
			m_registeredVariablesTypes.emplace( id, rawTypeId );
			m_registeredConstants.emplace( id, value.getType() );
		}

		return it->second.id;
	}

	ValueId Module::registerParameter( ast::type::TypePtr type )
	{
		registerType( type );
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
			, [outer]( std::map< std::string, VariableInfo >::value_type const & pair )
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
			, [mbrId]( std::map< std::string, std::pair< ValueId, ValueId > >::value_type const & pair )
			{
				return pair.second.second == mbrId;
			} );
		assert( itInner != m_registeredMemberVariables.end() );
		
		auto result = itInner->second.first;
		auto itOuter = m_registeredMemberVariables.end();

		while ( ( itOuter = std::find_if( m_registeredMemberVariables.begin()
				, m_registeredMemberVariables.end()
				, [result]( std::map< std::string, std::pair< ValueId, ValueId > >::value_type const & pair )
				{
					return pair.second.second == result;
				} ) ) != m_registeredMemberVariables.end() )
		{
			result = itOuter->second.first;
		}

		auto itOutermost = std::find_if( m_currentScopeVariables->begin()
			, m_currentScopeVariables->end()
			, [result]( std::map< std::string, VariableInfo >::value_type const & pair )
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
			auto type = registerType( m_typesCache->getBool() );
			ValueId result{ getNextId(), type.type };

			if ( value )
			{
				globalDeclarations.push_back( makeInstruction< ConstantTrueInstruction >( type
					, result ) );
			}
			else
			{
				globalDeclarations.push_back( makeInstruction< ConstantFalseInstruction >( type
					, result ) );
			}

			it = m_registeredBoolConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getBool() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( int8_t value )
	{
		auto it = m_registeredInt8Constants.find( value );

		if ( it == m_registeredInt8Constants.end() )
		{
			auto type = registerType( m_typesCache->getInt8() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ spv::Id( value ) } } ) );
			it = m_registeredInt8Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getInt8() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( int16_t value )
	{
		auto it = m_registeredInt16Constants.find( value );

		if ( it == m_registeredInt16Constants.end() )
		{
			auto type = registerType( m_typesCache->getInt16() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ spv::Id( value ) } } ) );
			it = m_registeredInt16Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getInt16() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( int32_t value )
	{
		auto it = m_registeredInt32Constants.find( value );

		if ( it == m_registeredInt32Constants.end() )
		{
			auto type = registerType( m_typesCache->getInt32() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ spv::Id( value ) } } ) );
			it = m_registeredInt32Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getInt32() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( int64_t value )
	{
		auto it = m_registeredInt64Constants.find( value );

		if ( it == m_registeredInt64Constants.end() )
		{
			auto type = registerType( m_typesCache->getInt64() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ uint32_t( ( value >> 32 ) & 0x00000000FFFFFFFFll ) }
			, ValueId{ uint32_t( value & 0x00000000FFFFFFFFll ) } } ) );
			it = m_registeredInt64Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getInt64() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( uint8_t value )
	{
		auto it = m_registeredUInt8Constants.find( value );

		if ( it == m_registeredUInt8Constants.end() )
		{
			auto type = registerType( m_typesCache->getUInt8() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ value } } ) );
			it = m_registeredUInt8Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getUInt8() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( uint16_t value )
	{
		auto it = m_registeredUInt16Constants.find( value );

		if ( it == m_registeredUInt16Constants.end() )
		{
			auto type = registerType( m_typesCache->getUInt16() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ value } } ) );
			it = m_registeredUInt16Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getUInt16() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( uint32_t value )
	{
		auto it = m_registeredUInt32Constants.find( value );

		if ( it == m_registeredUInt32Constants.end() )
		{
			auto type = registerType( m_typesCache->getUInt32() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ value } } ) );
			it = m_registeredUInt32Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_typesCache->getUInt32() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( uint64_t value )
	{
		auto it = m_registeredUInt64Constants.find( value );

		if ( it == m_registeredUInt64Constants.end() )
		{
			auto type = registerType( m_typesCache->getUInt64() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ uint32_t( ( value >> 32 ) & 0x00000000FFFFFFFFull ) }
					, ValueId{ uint32_t( value & 0x00000000FFFFFFFFull ) } } ) );
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
			auto type = registerType( m_typesCache->getFloat() );
			ValueId result{ getNextId(), type.type };
			IdList list;
			list.resize( 1u );
			auto dst = reinterpret_cast< float * >( list.data() );
			*dst = value;
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
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
			auto type = registerType( m_typesCache->getDouble() );
			ValueId result{ getNextId(), type.type };
			IdList list;
			list.resize( 2u );
			auto dst = reinterpret_cast< double * >( list.data() );
			*dst = value;
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
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
		auto typeId = registerType( type );
		auto it = std::find_if( m_registeredCompositeConstants.begin()
			, m_registeredCompositeConstants.end()
			, [initialisers]( std::pair< ValueIdList, ValueId > const & lookup )
			{
				return lookup.first == initialisers;
			} );

		if ( it == m_registeredCompositeConstants.end() )
		{
			ValueId result{ getNextId(), typeId.type };
			globalDeclarations.push_back( makeInstruction< ConstantCompositeInstruction >( typeId
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
		extensions.push_back( makeInstruction< ExtensionInstruction >( std::move( name ) ) );
	}

	void Module::registerEntryPoint( ValueId functionId
		, std::string name
		, ValueIdList const & inputs
		, ValueIdList const & outputs )
	{
		ValueIdSet ios;
		ValueIdList operands;

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
		entryPoint = makeInstruction< EntryPointInstruction >( ValueId{ spv::Id( m_model ) }
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
		registerExecutionMode( mode, {} );
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode, ValueIdList const & operands )
	{
		if ( !entryPoint || entryPoint->operands.empty() )
		{
			ValueIdList ops;
			ops.push_back( { 0u } );
			ops.push_back( { spv::Id( mode ) } );
			ops.insert( ops.end(), operands.begin(), operands.end() );
			m_pendingExecutionModes.push_back( makeInstruction< ExecutionModeInstruction >( ops ) );
		}
		else
		{
			ValueIdList ops;
			ops.push_back( { entryPoint->resultId.value() } );
			ops.push_back( { spv::Id( mode ) } );
			ops.insert( ops.end(), operands.begin(), operands.end() );
			executionModes.push_back( makeInstruction< ExecutionModeInstruction >( ops ) );
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

		registerExecutionMode( spv::ExecutionModeOutputVertices, { ValueId{ primCount } } );
		registerExecutionMode( spv::ExecutionModeInvocations, { ValueId{ 1u } } );
	}

	void Module::registerExecutionMode( ast::type::PatchDomain domain
		, ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering order
		, uint32_t outputVertices )
	{
		registerExecutionMode( spv::ExecutionModeOutputVertices, { ValueId{ outputVertices } } );
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

		registerExecutionMode( spv::ExecutionModeOutputVertices, { ValueId{ maxVertices } } );
		registerExecutionMode( spv::ExecutionModeOutputPrimitivesNV, { ValueId{ maxPrimitives } } );
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

		registerExecutionMode( spv::ExecutionModeOutputVertices, { ValueId{ maxVertices } } );
		registerExecutionMode( spv::ExecutionModeOutputPrimitivesEXT, { ValueId{ maxPrimitives } } );
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
		, ValueId retType
		, ast::var::VariableList const & params )
	{
		ValueId result{ getNextId() };
		m_registeredVariables.emplace( name, VariableInfo{ result, false, false, false } );

		ValueIdList funcTypes;
		ValueIdList funcParams;
		funcTypes.push_back( retType );
		Function func;
		functions.emplace_back( std::move( func ) );
		m_currentFunction = &functions.back();
		m_currentFunction->registeredVariables = m_registeredVariables; // the function has access to global scope variables.
		m_currentScopeVariables = &m_currentFunction->registeredVariables;

		for ( auto & param : params )
		{
			auto type = param->getType();
			auto kind = type->getKind();
			funcTypes.push_back( registerType( type ) );

			if ( isPointerParam( *param ) )
			{
				auto storage = ( isOpaqueType( kind )
					? spv::StorageClassUniformConstant
					: spv::StorageClassFunction );
				funcTypes.back() = registerPointerType( funcTypes.back(), storage );
			}

			ValueId paramId{ getNextId(), funcTypes.back().type };
			funcParams.push_back( paramId );
			debug.push_back( makeInstruction< NameInstruction >( paramId, param->getName() ) );

			m_currentScopeVariables->emplace( param->getName(), VariableInfo{ funcParams.back(), false, true, param->isOutputParam() } );
			m_registeredVariablesTypes.emplace( funcParams.back(), funcTypes.back() );
		}

		auto it = m_registeredFunctionTypes.find( funcTypes );

		if ( it == m_registeredFunctionTypes.end() )
		{
			ValueId funcTypeId{ getNextId() };
			globalDeclarations.push_back( makeInstruction< FunctionTypeInstruction >( funcTypeId
				, funcTypes ) );
			it = m_registeredFunctionTypes.emplace( funcTypes, funcTypeId ).first;
		}

		ValueId funcTypeId{ it->second };
		m_currentFunction->declaration.emplace_back( makeInstruction< FunctionInstruction >( retType
			, result
			, ValueId{ spv::Id( spv::FunctionControlMaskNone ) }
			, funcTypeId ) );
		auto itType = funcTypes.begin() + 1u;
		auto itParam = funcParams.begin();

		for ( auto i = params.begin(); i != params.end(); ++i )
		{
			m_currentFunction->declaration.emplace_back( makeInstruction< FunctionParameterInstruction >( *itType
				, *itParam ) );
			++itType;
			++itParam;
		}

		m_registeredVariablesTypes.emplace( result, funcTypeId );
		debug.push_back( makeInstruction< NameInstruction >( result, std::move( name ) ) );
		variables = &m_currentFunction->variables;

		return m_currentFunction;
	}

	Block Module::newBlock()
	{
		Block result{ getNextId() };
		result.instructions.push_back( makeInstruction< LabelInstruction >( ValueId{ result.label } ) );
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

	ValueId Module::doRegisterNonArrayType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, ValueId parentId )
	{
		ValueId result;
		auto unqualifiedType = getUnqualifiedType( *m_typesCache, type );
		auto it = m_registeredTypes.find( unqualifiedType );

		if ( it == m_registeredTypes.end() )
		{
			result = registerBaseType( unqualifiedType
				, mbrIndex
				, parentId
				, 0u );
			m_registeredTypes.emplace( unqualifiedType, result );
		}
		else
		{
			result = it->second;
		}

		return result;
	}

	ValueId Module::registerType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, ValueId parentId
		, uint32_t arrayStride )
	{
		ValueId result{ 0u, type };

		if ( type->getRawKind() == ast::type::Kind::eArray )
		{
			auto arrayedType = static_cast< ast::type::Array const & >( *type ).getType();
			auto elementTypeId = registerType( arrayedType
				, mbrIndex
				, parentId
				, arrayStride );
			auto unqualifiedType = getUnqualifiedType( *m_typesCache, type );
			auto it = m_registeredTypes.find( unqualifiedType );

			if ( it == m_registeredTypes.end() )
			{
				auto arraySize = getArraySize( type );

				if ( arraySize != ast::type::UnknownArraySize )
				{
					auto lengthId = registerLiteral( arraySize );
					result.id = getNextId();
					globalDeclarations.push_back( makeInstruction< ArrayTypeInstruction >( result
						, elementTypeId
						, lengthId ) );
				}
				else
				{
					result.id = getNextId();
					globalDeclarations.push_back( makeInstruction< RuntimeArrayTypeInstruction >( result
						, elementTypeId ) );
				}

				writeArrayStride( *this
					, arrayedType
					, result
					, arrayStride );
				m_registeredTypes.emplace( unqualifiedType, result );
			}
			else
			{
				result = it->second;
			}
		}
		else if ( type->getRawKind() == ast::type::Kind::ePointer )
		{
			auto & pointerType = static_cast< ast::type::Pointer const & >( *type );
			auto rawTypeId = registerType( pointerType.getPointerType()
				, mbrIndex
				, parentId
				, arrayStride );
			result = registerPointerType( rawTypeId
				, convert( pointerType.getStorage() )
				, pointerType.isForward() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eRayPayload )
		{
			auto & payloadType = static_cast< ast::type::RayPayload const & >( *type );
			result = registerType( payloadType.getDataType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eCallableData )
		{
			auto & callableType = static_cast< ast::type::CallableData const & >( *type );
			result = registerType( callableType.getDataType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eHitAttribute )
		{
			auto & callableType = static_cast< ast::type::HitAttribute const & >( *type );
			result = registerType( callableType.getDataType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eGeometryOutput )
		{
			auto & outputType = static_cast< ast::type::GeometryOutput const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
			registerExecutionMode( outputType.getLayout(), outputType.getCount() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eGeometryInput )
		{
			auto & inputType = static_cast< ast::type::GeometryInput const & >( *type );
			result = registerType( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
			registerExecutionMode( inputType.getLayout() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationInputPatch )
		{
			auto & outputType = static_cast< ast::type::TessellationInputPatch const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationOutputPatch )
		{
			auto & outputType = static_cast< ast::type::TessellationOutputPatch const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
		{
			auto & outputType = static_cast< ast::type::TessellationControlOutput const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
			registerExecutionMode( outputType.getDomain()
				, outputType.getPartitioning()
				, outputType.getTopology()
				, outputType.getOrder()
				, outputType.getOutputVertices() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationControlInput )
		{
			auto & inputType = static_cast< ast::type::TessellationControlInput const & >( *type );
			result = registerType( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTessellationEvaluationInput )
		{
			auto & inputType = static_cast< ast::type::TessellationEvaluationInput const & >( *type );
			result = registerType( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
		{
			auto & outputType = static_cast< ast::type::MeshVertexOutput const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
		{
			auto & outputType = static_cast< ast::type::MeshPrimitiveOutput const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
		{
			auto & outputType = static_cast< ast::type::TaskPayloadNV const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayload )
		{
			auto & outputType = static_cast< ast::type::TaskPayload const & >( *type );
			result = registerType( outputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
		{
			auto & inputType = static_cast< ast::type::TaskPayloadInNV const & >( *type );
			result = registerType( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
		{
			auto & inputType = static_cast< ast::type::TaskPayloadIn const & >( *type );
			result = registerType( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else if ( type->getRawKind() == ast::type::Kind::eComputeInput )
		{
			auto & inputType = static_cast< ast::type::ComputeInput const & >( *type );
			result = registerType( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride );
		}
		else
		{
			result = doRegisterNonArrayType( type
				, mbrIndex
				, parentId );
		}

		return result;
	}

	ValueId Module::registerBaseType( ast::type::Kind kind
		, uint32_t mbrIndex
		, ValueId parentId
		, uint32_t arrayStride )
	{
		assert( kind != ast::type::Kind::eStruct );
		assert( kind != ast::type::Kind::eRayDesc );
		assert( kind != ast::type::Kind::eSampler );
		assert( kind != ast::type::Kind::eImage );
		assert( kind != ast::type::Kind::eSampledImage );
		assert( kind != ast::type::Kind::eCombinedImage );

		auto type = m_typesCache->getBasicType( kind );
		ValueId result{ 0u, type };

		if ( isVectorType( kind )
			|| isMatrixType( kind ) )
		{
			auto componentType = registerType( m_typesCache->getBasicType( getComponentType( kind ) ) );
			result.id = getNextId();

			if ( isMatrixType( kind ) )
			{
				globalDeclarations.push_back( makeInstruction< MatrixTypeInstruction >( result
					, componentType
					, ValueId{ getComponentCount( kind ) } ) );
			}
			else
			{
				globalDeclarations.push_back( makeInstruction< VectorTypeInstruction >( result
					, componentType
					, ValueId{ getComponentCount( kind ) } ) );
			}
		}
		else
		{
			result.id = getNextId();
			globalDeclarations.push_back( makeBaseTypeInstruction( kind, result ) );
		}

		return result;
	}

	ValueId Module::registerBaseType( ast::type::SamplerPtr type
		, uint32_t mbrIndex
		, ValueId parentId )
	{
		ValueId result{ getNextId(), type };
		globalDeclarations.push_back( makeInstruction< SamplerTypeInstruction >( result ) );
		return result;
	}

	ValueId Module::registerBaseType( ast::type::CombinedImagePtr type
		, uint32_t mbrIndex
		, ValueId parentId )
	{
		auto imgTypeId = registerBaseType( type->getImageType()
			, type->isComparison() ? ast::type::Trinary::eTrue : ast::type::Trinary::eFalse );
		ValueId result{ getNextId(), type };
		globalDeclarations.push_back( makeInstruction< TextureTypeInstruction >( result
			, imgTypeId ) );
		return result;
	}

	ValueId Module::registerBaseType( ast::type::ImagePtr type
		, ast::type::Trinary isComparison )
	{
		auto ires = m_registeredImageTypes.emplace( myHash( type->getConfig(), isComparison ), ValueId{} );
		auto it = ires.first;

		if ( ires.second )
		{
			// The Sampled Type.
			auto sampledTypeId = registerType( m_typesCache->getBasicType( type->getConfig().sampledType ) );
			// The Image Type.
			it->second = { getNextId(), type };
			globalDeclarations.push_back( makeImageTypeInstruction( type->getConfig()
				, isComparison
				, it->second
				, sampledTypeId ) );
		}

		return it->second;
	}

	ValueId Module::registerBaseType( ast::type::ImagePtr type
		, uint32_t mbrIndex
		, ValueId parent )
	{
		return registerBaseType( type, ast::type::Trinary::eFalse );
	}

	ValueId Module::registerBaseType( ast::type::SampledImagePtr type
		, uint32_t mbrIndex
		, ValueId parent )
	{
		return registerBaseType( type->getImageType(), type->getDepth() );
	}

	ValueId Module::registerBaseType( ast::type::AccelerationStructurePtr type
		, uint32_t mbrIndex
		, ValueId parentId )
	{
		ValueId result{ getNextId(), type };
		globalDeclarations.push_back( makeAccelerationStructureTypeInstruction( result ) );
		return result;
	}

	ValueId Module::registerBaseType( ast::type::StructPtr type
		, uint32_t
		, ValueId )
	{
		ValueId result{ getNextId(), type };
		ValueIdList subTypes;

		for ( auto & member : *type )
		{
			subTypes.push_back( registerType( member.type
				, member.type->getIndex()
				, result
				, member.arrayStride ) );
		}

		globalDeclarations.push_back( makeInstruction< StructTypeInstruction >( result, subTypes ) );
		debug.push_back( makeInstruction< NameInstruction >( result, type->getName() ) );
		bool hasBuiltin = false;
		bool hasDynarray = false;

		for ( auto & member : *type )
		{
			auto index = member.type->getIndex();
			debug.push_back( makeInstruction< MemberNameInstruction >( result, ValueId{ index }, member.name ) );

			if ( member.builtin == ast::Builtin::eNone )
			{
				decorateMember( result
					, index
					, { uint32_t( spv::DecorationOffset ), member.offset } );
			}
			else
			{
				addMbrBuiltin( member.builtin, result, index );
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
				decorateMember( result
					, index
					, spv::DecorationColMajor );
				decorateMember( result
					, index
					, { uint32_t( spv::DecorationMatrixStride ), size } );
			}
		}

		if ( hasBuiltin || hasDynarray )
		{
			decorate( result, spv::DecorationBlock );
		}

		return result;
	}

	ValueId Module::registerBaseType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, ValueId parentId
		, uint32_t arrayStride )
	{
		ValueId result{ 0u, type };

		if ( type->getRawKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		auto kind = type->getRawKind();

		if ( kind == ast::type::Kind::eSampler )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::Sampler >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eCombinedImage )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::CombinedImage >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eImage )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::Image >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eSampledImage )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::SampledImage >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eAccelerationStructure )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::AccelerationStructure >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eStruct
			|| kind == ast::type::Kind::eRayDesc )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::Struct >( type )
				, mbrIndex
				, parentId );
		}
		else
		{
			result = registerBaseType( kind
				, mbrIndex
				, parentId
				, arrayStride );
		}

		return result;
	}

	void Module::replaceDecoration( ValueId id
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
				list[dist] = { spv::Id( newDecoration ) };
				decorations[idx]->operands[dist + 1u] = spv::Id( newDecoration );
				varIt->second.emplace( list, idx );
				processed = true;
			}
		}

		if ( !processed )
		{
			IdList list;
			list.push_back( spv::Id( newDecoration ) );
			decorate( id, list );
		}
	}

	void Module::replaceMemberDecoration( ValueId id
		, uint32_t index
		, spv::Decoration oldDecoration
		, spv::Decoration newDecoration )
	{
		auto mbrIt = mbrDecorations.find( ValueIdList{ id, ValueId{ index } } );
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
				list[dist] = { spv::Id( newDecoration ) };
				decorations[idx]->operands[dist + 2u] = spv::Id( newDecoration );
				mbrIt->second.emplace( list, idx );
				processed = true;
			}
		}

		if ( !processed )
		{
			IdList list;
			list.push_back( spv::Id( newDecoration ) );
			decorateMember( id, index, list );
		}
	}

	spv::Id Module::getNextId()
	{
		auto result = *m_currentId;
		++*m_currentId;
		return result;
	}

	void Module::initialiseHeader( Header const & rhs )
	{
		header.push_back( rhs.magic );
		header.push_back( rhs.version );
		header.push_back( rhs.builder );
		header.push_back( rhs.boundIds );
		header.push_back( rhs.schema );
		m_currentId = &header[3];
	}

	void Module::initialiseExtensions()
	{
		ValueId id{ getIntermediateResult() };
		imports.push_back( makeInstruction< ExtInstImportInstruction >( id
			, "GLSL.std.450" ) );
		debug.push_back( makeInstruction< SourceInstruction >( ValueId{ spv::Id( spv::SourceLanguageGLSL ) }, ValueId{ 460u } ) );
	}

	void Module::initialiseCapacities()
	{
		switch ( m_model )
		{
		case spv::ExecutionModelVertex:
		case spv::ExecutionModelFragment:
		case spv::ExecutionModelGLCompute:
			insertCapability( capabilities, spv::CapabilityShader );
			break;
		case spv::ExecutionModelTessellationControl:
		case spv::ExecutionModelTessellationEvaluation:
			insertCapability( capabilities, spv::CapabilityShader );
			insertCapability( capabilities, spv::CapabilityTessellation );
			break;
		case spv::ExecutionModelGeometry:
			insertCapability( capabilities, spv::CapabilityShader );
			insertCapability( capabilities, spv::CapabilityGeometry );
			break;
		case spv::ExecutionModelTaskNV:
		case spv::ExecutionModelMeshNV:
			insertCapability( capabilities, spv::CapabilityShader );
			insertCapability( capabilities, spv::CapabilityMeshShadingNV );
			break;
		case spv::ExecutionModelTaskEXT:
		case spv::ExecutionModelMeshEXT:
			insertCapability( capabilities, spv::CapabilityShader );
			insertCapability( capabilities, spv::CapabilityMeshShadingEXT );
			break;
		case spv::ExecutionModelAnyHitKHR:
		case spv::ExecutionModelCallableKHR:
		case spv::ExecutionModelClosestHitKHR:
		case spv::ExecutionModelIntersectionKHR:
		case spv::ExecutionModelMissKHR:
		case spv::ExecutionModelRayGenerationKHR:
			insertCapability( capabilities, spv::CapabilityShader );
			insertCapability( capabilities, spv::CapabilityRayTracingKHR );
			break;
		case spv::ExecutionModelKernel:
			insertCapability( capabilities, spv::CapabilityKernel );
			break;
		default:
			AST_Failure( "Unsupported ExecutionModel" );
			break;
		}
	}

	void Module::addDebug( std::string const & name
		, ValueId id )
	{
		auto type = unwrapType( id.type );

		if ( ( type->getKind() != ast::type::Kind::eStruct
				&& type->getKind() != ast::type::Kind::eRayDesc )
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() != name )
		{
			debug.push_back( makeInstruction< NameInstruction >( id, name ) );
		}
		else if ( type->getKind() == ast::type::Kind::eStruct
			|| type->getKind() == ast::type::Kind::eRayDesc
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() == name )
		{
			debug.push_back( makeInstruction< NameInstruction >( id, name + "Inst" ) );
		}
	}

	void Module::addBuiltin( ast::Builtin pbuiltin
		, ValueId id )
	{
		std::vector< spv::Decoration > additionalDecorations;
		auto builtin = getBuiltin( pbuiltin, m_model, additionalDecorations );

		if ( builtin != spv::BuiltInMax )
		{
			decorate( id, { spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) } );

			for ( auto & decoration : additionalDecorations )
			{
				decorate( id, decoration );
			}
		}
	}

	bool Module::addMbrBuiltin( ast::Builtin pbuiltin
		, ValueId outer
		, uint32_t mbrIndex )
	{
		bool result = false;
		std::vector< spv::Decoration > additionalDecorations;
		auto builtin = getBuiltin( pbuiltin, m_model, additionalDecorations );

		if ( builtin != spv::BuiltInMax )
		{
			decorateMember( outer, mbrIndex, { spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) } );

			for ( auto & decoration : additionalDecorations )
			{
				decorateMember( outer, mbrIndex, decoration );
			}

			result = true;
		}

		return result;
	}

	void Module::addVariable( std::string name
		, ValueId varId
		, std::map< std::string, VariableInfo >::iterator & it
		, ValueId initialiser )
	{
		assert( varId.isPointer() );
		auto type = varId.type;
		auto rawType = static_cast< ast::type::Pointer const & >( *type ).getPointerType();
		auto rawTypeId = registerType( rawType );
		auto typeStorage = varId.getStorage();

		if ( typeStorage == ast::type::Storage::ePushConstant )
		{
			decorate( rawTypeId, spv::DecorationBlock );
		}

		auto varTypeId = registerPointerType( rawTypeId
			, convert( typeStorage ) );

		if ( varId.getStorage() == ast::type::Storage::eFunction
			&& m_currentFunction )
		{
			it = doAddVariable( varTypeId
				, varId
				, std::move( name )
				, initialiser
				, *m_currentScopeVariables
				, m_currentFunction->variables );
		}
		else
		{
			it = doAddVariable( varTypeId
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

	InstructionList * Module::selectInstructionsList( spv::Op opCode )
	{
		InstructionList * list{ nullptr };

		switch ( opCode )
		{
		case spv::OpSource:
		case spv::OpSourceExtension:
		case spv::OpName:
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
		case spv::OpVariable:
		case spv::OpConstant:
		case spv::OpConstantComposite:
		case spv::OpConstantFalse:
		case spv::OpConstantTrue:
		case spv::OpSpecConstant:
		case spv::OpSpecConstantComposite:
		case spv::OpSpecConstantFalse:
		case spv::OpSpecConstantTrue:
			list = &globalDeclarations;
			break;
		default:
			break;
		}

		return list;
	}

	bool Module::deserializeInfos( spv::Op opCode
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

	bool Module::deserializeFuncs( spv::Op opCode
		, InstructionList::iterator & current
		, InstructionList::iterator end )
	{
		bool result = false;

		switch ( opCode )
		{
		case spv::OpFunction:
			functions.emplace_back( Function::deserialize( current, end ) );
			result = true;
			break;
		default:
			break;
		}

		return result;
	}

	//*************************************************************************
}
