/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVModuleTypes.hpp"

#include "CompilerSpirV/SpirVHelpers.hpp"
#include "CompilerSpirV/SpirVModule.hpp"

#include <ShaderAST/Type/TypeCache.hpp>

namespace spirv
{
	//*************************************************************************

	namespace modtyp
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

		static void writeArrayStride( Module & shaderModule
			, ast::type::TypePtr elementType
			, TypeId const & typeId
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

				shaderModule.decorate( typeId
					, makeIdList( shaderModule.allocator
						, uint32_t( spv::DecorationArrayStride )
						, arrayStride ) );
			}
		}

		static size_t myHash( ast::type::TypePtr type
			, ast::type::Trinary isComparison = ast::type::Trinary::eDontCare )noexcept
		{
			size_t result = std::hash< ast::type::TypePtr >{}( type );
			result = ast::type::hashCombine( result, isComparison );
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
	}

	//*************************************************************************

	ModuleTypes::ModuleTypes( ast::ShaderAllocatorBlock * allocator
		, Module & shaderModule
		, ast::type::TypesCache * typesCache
		, InstructionList & constantsTypes )
		: m_allocator{ allocator }
		, m_module{ shaderModule }
		, m_debugNames{ m_module.getDebugNames() }
		, m_nonSemanticDebug{ m_module.getNonSemanticDebug() }
		, m_declarations{ constantsTypes }
		, m_typesCache{ typesCache }
		, m_registeredTypes{ m_allocator }
		, m_registeredSamplerImages{ m_allocator }
		, m_registeredImageTypes{ m_allocator }
		, m_registeredPointerTypes{ m_allocator }
		, m_registeredForwardPointerTypes{ m_allocator }
		, m_registeredFunctionTypes{ m_allocator }
	{
	}

	TypeId ModuleTypes::registerType( ast::type::TypePtr type
		, glsl::Statement const * debugStatement )
	{
		return doRegisterTypeRec( type
			, ast::type::NotMember
			, TypeId{}
			, 0u
			, debugStatement );
	}

	TypeId ModuleTypes::registerType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId const & parentId
		, glsl::Statement const * debugStatement )
	{
		return doRegisterTypeRec( type
			, mbrIndex
			, parentId
			, 0u
			, debugStatement );
	}

	TypeId ModuleTypes::registerImageType( ast::type::ImagePtr image
		, bool isComparison )
	{
		return doRegisterBaseType( image
			, isComparison ? ast::type::Trinary::eTrue : ast::type::Trinary::eFalse );
	}

	TypeId ModuleTypes::registerFunctionType( TypeIdList const & funcTypes )
	{
		auto it = m_registeredFunctionTypes.find( funcTypes );
		TypeId resultId;

		if ( it == m_registeredFunctionTypes.end() )
		{
			resultId.id.id = m_module.getNextId();

			m_declarations.push_back( makeInstruction< FunctionTypeInstruction >( m_module.getNameCache()
				, resultId.id
				, convert( funcTypes ) ) );
			m_nonSemanticDebug.registerFunctionType( funcTypes, resultId );

			it = m_registeredFunctionTypes.try_emplace( funcTypes, resultId ).first;
		}
		else
		{
			resultId = it->second;
		}

		return resultId;
	}

	TypeId ModuleTypes::registerPointerType( TypeId type
		, spv::StorageClass storage
		, bool isForward )
	{
		uint64_t key = ( uint64_t( type.id.id ) << 33 )
			| ( ( uint64_t( type.isPointer() ) << 32 ) & 0x01 )
			| ( uint64_t( storage ) << 1 )
			| ( isForward ? 0x01 : 0x00 );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			TypeId id{ m_module.getNextId()
				, getTypesCache().getPointerType( type->type, convert( storage ) ) };
			id.debug = type.debug;
			it = m_registeredPointerTypes.try_emplace( key, id ).first;

			if ( isForward )
			{
				m_declarations.push_back( makeInstruction< ForwardPointerTypeInstruction >( m_module.getNameCache()
					, id.id
					, ValueId{ spv::Id( storage ) } ) );
				m_declarations.push_back( makeInstruction< PointerTypeInstruction >( m_module.getNameCache()
					, id.id
					, ValueId{ spv::Id( storage ) }
					, type.id ) );
				key = ( uint64_t( type.id.id ) << 33 )
					| ( ( uint64_t( type.isPointer() ) << 32 ) & 0x01 )
					| ( uint64_t( storage ) << 1 );
				m_registeredPointerTypes.try_emplace( key, id );
			}
			else
			{
				m_declarations.push_back( makeInstruction< PointerTypeInstruction >( m_module.getNameCache()
					, id.id
					, ValueId{ spv::Id( storage ) }
					, type.id ) );
			}
		}

		return it->second;
	}

	DebugId ModuleTypes::mergeSamplerImage( DebugId const & image
		, DebugId const & sampler
		, Block & currentBlock )
	{
		auto & imgType = static_cast< ast::type::Image const & >( *getNonArrayType( image->type ) );
		auto & splType = static_cast< ast::type::Sampler const & >( *getNonArrayType( sampler->type ) );
		auto lhsIt = m_registeredSamplerImages.try_emplace( image, m_allocator ).first;
		auto [it, res] = lhsIt->second.try_emplace(sampler);

		if ( res )
		{
			auto typeId = registerType( getTypesCache().getCombinedImage( imgType.getConfig()
				, splType.isComparison() )
				, nullptr );
			it->second = DebugId{ m_module.getNextId(), typeId->type };
			currentBlock.instructions.push_back( makeInstruction< SampledImageInstruction >( m_module.getNameCache()
				, typeId.id
				, it->second.id
				, image.id
				, sampler.id ) );
		}

		return it->second;
	}

	ast::type::TypePtr ModuleTypes::getType( DebugId const & typeId )const
	{
		if ( auto rit = std::find_if( m_registeredTypes.begin()
			, m_registeredTypes.end()
			, [&typeId]( std::pair< size_t const, TypeId > const & lookup )
			{
				return lookup.second.id.id == typeId.id.id;
			} );
			rit != m_registeredTypes.end() )
		{
			return rit->second->type;
		}

		return nullptr;
	}

	void ModuleTypes::deserialize( spv::Op opCode
		, Instruction const & instruction
		, NameCache const & names )
	{
		switch ( opCode )
		{
		case spv::OpTypeVoid:
			doRegisterBaseType( *instruction.resultId, ast::type::Kind::eVoid );
			break;
		case spv::OpTypeBool:
			doRegisterBaseType( *instruction.resultId, ast::type::Kind::eBoolean );
			break;
		case spv::OpTypeInt:
			{
				auto size = instruction.operands[0];
				auto sign = instruction.operands[1];
				ast::type::Kind kind;

				if ( size <= 8u )
				{
					if ( sign != 0u )
					{
						kind = ast::type::Kind::eInt8;
					}
					else
					{
						kind = ast::type::Kind::eUInt8;
					}
				}
				else if ( size <= 16u )
				{
					if ( sign != 0u )
					{
						kind = ast::type::Kind::eInt16;
					}
					else
					{
						kind = ast::type::Kind::eUInt16;
					}
				}
				else if ( size <= 32u )
				{
					if ( sign != 0u )
					{
						kind = ast::type::Kind::eInt32;
					}
					else
					{
						kind = ast::type::Kind::eUInt32;
					}
				}
				else
				{
					if ( sign != 0u )
					{
						kind = ast::type::Kind::eInt64;
					}
					else
					{
						kind = ast::type::Kind::eUInt64;
					}
				}

				doRegisterBaseType( *instruction.resultId, kind );
			}
			break;
		case spv::OpTypeFloat:
			{
				auto size = instruction.operands[0];
				ast::type::Kind kind;

				if ( size <= 16u )
				{
					kind = ast::type::Kind::eHalf;
				}
				else if ( size <= 32u )
				{
					kind = ast::type::Kind::eFloat;
				}
				else
				{
					kind = ast::type::Kind::eDouble;
				}

				doRegisterBaseType( *instruction.resultId, kind );
			}
			break;
		case spv::OpTypeVector:
			{
				auto componentId = instruction.operands[0];
				auto cit = std::find_if( m_registeredTypes.begin()
					, m_registeredTypes.end()
					, [componentId]( std::pair< size_t const, TypeId > const & lookup )
					{
						return lookup.second.id.id == componentId;
					} );
				if ( cit == m_registeredTypes.end() )
				{
					return;
				}

				auto kind = cit->second->type->getKind();

				if ( auto count = instruction.operands[1];
					count == 2u )
				{
					kind = m_typesCache->getVec2Kind( kind );
				}
				else if ( count == 3u )
				{
					kind = m_typesCache->getVec3Kind( kind );
				}
				else
				{
					kind = m_typesCache->getVec4Kind( kind );
				}

				if ( kind == ast::type::Kind::eUndefined )
				{
					return;
				}

				doRegisterBaseType( *instruction.resultId, kind );
			}
			break;
		case spv::OpTypeMatrix:
			{
				auto componentId = instruction.operands[0];
				auto cit = std::find_if( m_registeredTypes.begin()
					, m_registeredTypes.end()
					, [componentId]( std::pair< size_t const, TypeId > const & lookup )
					{
						return lookup.second.id.id == componentId;
					} );
				if ( cit == m_registeredTypes.end() )
				{
					return;
				}

				auto kind = cit->second->type->getKind();

				if ( auto count = instruction.operands[1];
					count == 2u )
				{
					kind = m_typesCache->getMat2Kind( kind );
				}
				else if ( count == 3u )
				{
					kind = m_typesCache->getMat3Kind( kind );
				}
				else
				{
					kind = m_typesCache->getMat4Kind( kind );
				}

				if ( kind == ast::type::Kind::eUndefined )
				{
					return;
				}

				doRegisterBaseType( *instruction.resultId, kind );
			}
			break;
		case spv::OpTypeImage:
			{
				ast::type::ImageConfiguration config;
				config.dimension = ast::type::ImageDim( instruction.operands[1] );
				auto isComparison = ( instruction.operands[2] == 1u
					? ast::type::Trinary::eTrue
					: ( instruction.operands[2] == 0u
						? ast::type::Trinary::eFalse
						: ast::type::Trinary::eDontCare ) );
				config.isArrayed = instruction.operands[3] == 1u;
				config.isMS = instruction.operands[4] == 1u;
				config.isSampled = ( instruction.operands[5] == 1u
					? ast::type::Trinary::eTrue
					: ( instruction.operands[5] == 0u
						? ast::type::Trinary::eFalse
						: ast::type::Trinary::eDontCare ) );
				config.format = getImageFormat( spv::ImageFormat( instruction.operands[6] ) );
				auto type = m_typesCache->getImage( config );
				doRegisterBaseType( *instruction.resultId, type, isComparison );
			}
			break;
		case spv::OpTypeSampler:
			{
				auto type = m_typesCache->getSampler();
				doRegisterBaseType( *instruction.resultId, type );
			}
			break;
		case spv::OpTypeSampledImage:
			{
				auto imageId = instruction.operands[0u];
				auto iit = std::find_if( m_registeredTypes.begin()
					, m_registeredTypes.end()
					, [imageId]( std::pair< size_t const, TypeId > const & lookup )
					{
						return lookup.second.id.id == imageId;
					} );
				if ( iit == m_registeredTypes.end() )
				{
					return;
				}

				auto image = std::static_pointer_cast< ast::type::Image >( iit->second->type );
				auto type = m_typesCache->getCombinedImage( image->getConfig() );
				doRegisterBaseType( *instruction.resultId, type );
			}
			break;
		case spv::OpTypeArray:
			{
				auto elementId = instruction.operands[0];
				auto cit = std::find_if( m_registeredTypes.begin()
					, m_registeredTypes.end()
					, [elementId]( std::pair< size_t const, TypeId > const & lookup )
					{
						return lookup.second.id.id == elementId;
					} );
				if ( cit == m_registeredTypes.end() )
				{
					return;
				}

				auto count = instruction.operands[1];
				auto type = m_typesCache->getArray( cit->second->type, count );
				doRegisterBaseType( *instruction.resultId, type );
			}
			break;
		case spv::OpTypeRuntimeArray:
			{
				auto elementId = instruction.operands[0];
				auto cit = std::find_if( m_registeredTypes.begin()
					, m_registeredTypes.end()
					, [elementId]( std::pair< size_t const, TypeId > const & lookup )
					{
						return lookup.second.id.id == elementId;
					} );
				if ( cit == m_registeredTypes.end() )
				{
					return;
				}

				auto type = m_typesCache->getArray( cit->second->type );
				doRegisterBaseType( *instruction.resultId, type );
			}
			break;
		case spv::OpTypePointer:
			{
				auto storage = spv::StorageClass( instruction.operands[0] );
				auto elementId = instruction.operands[1];
				auto cit = std::find_if( m_registeredTypes.begin()
					, m_registeredTypes.end()
					, [elementId]( std::pair< size_t const, TypeId > const & lookup )
					{
						return lookup.second.id.id == elementId;
					} );
				if ( cit == m_registeredTypes.end() )
				{
					return;
				}

				auto key = ( uint64_t( cit->second.id.id ) << 33 )
					| ( ( uint64_t( cit->second.isPointer() ) << 32 ) & 0x01 )
					| ( uint64_t( storage ) << 1 );
				auto type = m_typesCache->getPointerType( cit->second->type, convert( storage ) );
				m_registeredPointerTypes.try_emplace( key, *instruction.resultId, type );
			}
			break;
		case spv::OpTypeStruct:
			{
				auto structId = instruction.resultId.value();
				auto type = m_typesCache->getStruct( ast::type::MemoryLayout::eC
					, names.get( structId ) );
				std::vector< ast::type::Struct::Member > members;

				for ( uint32_t i = 0u; i < uint32_t( instruction.operands.size() ); ++i )
				{
					auto subTypeId = instruction.operands[i];
					auto cit = std::find_if( m_registeredTypes.begin()
						, m_registeredTypes.end()
						, [subTypeId]( std::pair< size_t const, TypeId > const & lookup )
						{
							return lookup.second.id.id == subTypeId;
						} );
					if ( cit == m_registeredTypes.end() )
					{
						return;
					}

					if ( cit->second->type->getKind() == ast::type::Kind::eArray )
					{
						type->declMember( names.getMember( structId, i )
							, std::static_pointer_cast< ast::type::Array >( cit->second->type ) );
					}
					else
					{
						type->declMember( names.getMember( structId, i ), cit->second->type );
					}
				}

				doRegisterBaseType( structId, type );
			}
			break;
		case spv::OpTypeFunction:
			{
				auto funcId = instruction.resultId.value();
				ast::var::VariableList params;
				auto retTypeId = instruction.operands[0];
				auto cit = std::find_if( m_registeredTypes.begin()
					, m_registeredTypes.end()
					, [retTypeId]( std::pair< size_t const, TypeId > const & lookup )
					{
						return lookup.second.id.id == retTypeId;
					} );
				if ( cit == m_registeredTypes.end() )
				{
					return;
				}

				TypeIdList types{ m_allocator };
				auto returnType = cit->second->type;
				types.emplace_back( cit->second );

				for ( uint32_t i = 1u; i < uint32_t( instruction.operands.size() ); ++i )
				{
					auto paramTypeId = instruction.operands[i];
					cit = std::find_if( m_registeredTypes.begin()
						, m_registeredTypes.end()
						, [paramTypeId]( std::pair< size_t const, TypeId > const & lookup )
						{
							return lookup.second.id.id == paramTypeId;
						} );
					ast::type::TypePtr paramType;

					if ( cit == m_registeredTypes.end() )
					{
						auto pit = std::find_if( m_registeredPointerTypes.begin()
							, m_registeredPointerTypes.end()
							, [paramTypeId]( std::pair< uint64_t, TypeId > const & lookup )
							{
								return lookup.second.id.id == paramTypeId;
							} );

						if ( pit == m_registeredPointerTypes.end() )
						{
							return;
						}

						paramType = pit->second.id.type;
					}
					else
					{
						paramType = cit->second->type;
					}

					types.emplace_back( paramTypeId, paramType );
					params.push_back( ast::var::makeVariable( { i, "param" + std::to_string( i ) }, paramType ) );
				}

				auto type = m_typesCache->getFunction( returnType, std::move( params ) );
				auto resultId = doRegisterBaseType( funcId, type );
				m_registeredFunctionTypes.try_emplace( std::move( types ), resultId );
			}
			break;
		default:
			break;
		}
	}

	TypeId ModuleTypes::doRegisterNonArrayType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId const & parentId
		, glsl::Statement const * debugStatement )
	{
		TypeId result;
		auto unqualifiedType = modtyp::getUnqualifiedType( *m_typesCache, type );

		if ( auto it = m_registeredTypes.find( modtyp::myHash( unqualifiedType ) );
			it == m_registeredTypes.end() )
		{
			result = doRegisterBaseType( unqualifiedType
				, mbrIndex
				, parentId
				, debugStatement );
		}
		else
		{
			result = it->second;
		}

		return result;
	}

	TypeId ModuleTypes::doRegisterTypeRec( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId const & parentId
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
			auto unqualifiedType = modtyp::getUnqualifiedType( *m_typesCache, type );
			auto hash = modtyp::myHash( unqualifiedType );
			auto it = m_registeredTypes.find( hash );

			if ( it == m_registeredTypes.end() )
			{
				result.id.id = m_module.getNextId();
				auto & resultId = m_registeredTypes.try_emplace( hash, result ).first->second;
				
				if ( auto arraySize = getArraySize( type );
					arraySize != ast::type::UnknownArraySize )
				{
					auto lengthId = m_module.registerLiteral( arraySize );
					m_declarations.push_back( makeInstruction< ArrayTypeInstruction >( m_module.getNameCache()
						, resultId.id
						, elementTypeId.id
						, lengthId.id ) );
					m_nonSemanticDebug.registerArrayType( elementTypeId, arraySize, resultId );
				}
				else
				{
					m_declarations.push_back( makeInstruction< RuntimeArrayTypeInstruction >( m_module.getNameCache()
						, resultId.id
						, elementTypeId.id ) );
					m_nonSemanticDebug.registerRuntimeArrayType( elementTypeId, resultId );
				}

				modtyp::writeArrayStride( m_module
					, arrayedType
					, resultId
					, arrayStride );
				result = resultId;
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
			m_module.registerExecutionMode( outputType.getLayout(), outputType.getCount() );
		}
		else if ( type->getRawKind() == ast::type::Kind::eGeometryInput )
		{
			auto & inputType = static_cast< ast::type::GeometryInput const & >( *type );
			result = doRegisterTypeRec( inputType.getType()
				, mbrIndex
				, parentId
				, arrayStride
				, debugStatement );
			m_module.registerExecutionMode( inputType.getLayout() );
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
			m_module.registerExecutionMode( outputType.getDomain()
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

	TypeId & ModuleTypes::doRegisterBaseType( spv::Id id
		, ast::type::TypePtr type )
	{
		TypeId result{ 0u, type };
		result.id.id = id;
		return m_registeredTypes.try_emplace( modtyp::myHash( type ), result ).first->second;
	}

	TypeId & ModuleTypes::doRegisterBaseType( spv::Id id
		, ast::type::Kind kind )
	{
		return doRegisterBaseType( id, m_typesCache->getBasicType( kind ) );
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::Kind kind
		, glsl::Statement const * debugStatement )
	{
		assert( kind != ast::type::Kind::eStruct );
		assert( kind != ast::type::Kind::eRayDesc );
		assert( kind != ast::type::Kind::eSampler );
		assert( kind != ast::type::Kind::eImage );
		assert( kind != ast::type::Kind::eSampledImage );
		assert( kind != ast::type::Kind::eCombinedImage );

		auto & resultId = doRegisterBaseType( m_module.getNextId(), kind );

		if ( isVectorType( kind )
			|| isMatrixType( kind ) )
		{
			auto componentType = registerType( m_typesCache->getBasicType( getComponentType( kind ) ), debugStatement );
			auto componentCount = getComponentCount( kind );

			if ( isMatrixType( kind ) )
			{
				m_declarations.push_back( makeInstruction< MatrixTypeInstruction >( m_module.getNameCache()
					, resultId.id
					, componentType.id
					, ValueId{ componentCount } ) );
				m_nonSemanticDebug.registerMatrixType( componentType, componentCount, resultId );
			}
			else
			{
				m_declarations.push_back( makeInstruction< VectorTypeInstruction >( m_module.getNameCache()
					, resultId.id
					, componentType.id
					, ValueId{ componentCount } ) );
				m_nonSemanticDebug.registerVectorType( componentType, componentCount, resultId );
			}
		}
		else
		{
			m_declarations.push_back( makeBaseTypeInstruction( m_module.getNameCache()
				, kind
				, resultId.id ) );
			m_nonSemanticDebug.registerBaseType( kind, resultId );
		}

		return resultId;
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::SamplerPtr type )
	{
		auto & resultId = doRegisterBaseType( m_module.getNextId(), type );
		m_declarations.push_back( makeInstruction< SamplerTypeInstruction >( m_module.getNameCache()
			, resultId.id ) );
		m_nonSemanticDebug.registerSamplerType( std::move( type ), resultId );
		return resultId;
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::CombinedImagePtr type )
	{
		auto & resultId = doRegisterBaseType( m_module.getNextId(), type );
		auto imgTypeId = doRegisterBaseType( type->getImageType()
			, type->isComparison() ? ast::type::Trinary::eTrue : ast::type::Trinary::eFalse );
		m_declarations.push_back( makeInstruction< TextureTypeInstruction >( m_module.getNameCache()
			, resultId.id
			, imgTypeId.id ) );
		m_nonSemanticDebug.registerCombinedImageType( std::move( type ), resultId );
		return resultId;
	}

	void ModuleTypes::doRegisterBaseType( spv::Id id
		, ast::type::ImagePtr type
		, ast::type::Trinary isComparison )
	{
		auto [it, res] = m_registeredImageTypes.try_emplace( modtyp::myHash( type->getConfig(), isComparison ) );

		if ( res )
		{
			it->second = TypeId{ id, type };
			auto const & resultId = m_registeredTypes.try_emplace( modtyp::myHash( type, isComparison ), it->second ).first->second;
			it->second = resultId;
		}
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::ImagePtr type
		, ast::type::Trinary isComparison )
	{
		auto [it, res] = m_registeredImageTypes.try_emplace( modtyp::myHash( type->getConfig(), isComparison ) );

		if ( res )
		{
			// The Sampled Type.
			auto sampledTypeId = registerType( m_typesCache->getBasicType( type->getConfig().sampledType ), nullptr );
			// The Image Type.
			it->second = TypeId{ m_module.getNextId(), type };
			m_declarations.push_back( makeImageTypeInstruction( m_module.getNameCache()
				, type->getConfig()
				, isComparison
				, it->second.id
				, sampledTypeId.id ) );
			auto & resultId = m_registeredTypes.try_emplace( modtyp::myHash( type, isComparison ), it->second ).first->second;
			m_nonSemanticDebug.registerImageType( std::move( type ), resultId );
			it->second = resultId;
		}

		return it->second;
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::ImagePtr type )
	{
		return doRegisterBaseType( type, ast::type::Trinary::eFalse );
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::SampledImagePtr type )
	{
		return doRegisterBaseType( type->getImageType(), type->getDepth() );
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::AccelerationStructurePtr type )
	{
		TypeId result{ 0u, type };
		result.id.id = m_module.getNextId();
		m_declarations.push_back( makeAccelerationStructureTypeInstruction( m_module.getNameCache()
			, result.id ) );
		auto & resultId = m_registeredTypes.try_emplace( modtyp::myHash( type ), result ).first->second;
		m_nonSemanticDebug.registerAccelerationStructureType( resultId );
		return resultId;
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::StructPtr type
		, uint32_t
		, TypeId const &
		, glsl::Statement const * debugStatement )
	{
		TypeId result{ 0u, type };
		result.id.id = m_module.getNextId();
		TypeIdList subTypes{ m_allocator };
		ValueIdList debugSubTypes{ m_allocator };

		for ( auto & member : *type )
		{
			auto subTypeId = doRegisterTypeRec( member.type
				, member.type->getIndex()
				, result
				, member.arrayStride
				, debugStatement );
			subTypes.push_back( subTypeId );
			m_nonSemanticDebug.registerMemberType( member
				, subTypeId
				, debugStatement
				, debugSubTypes );
		}

		m_declarations.push_back( makeInstruction< StructTypeInstruction >( m_module.getNameCache()
			, result.id
			, convert( subTypes ) ) );
		m_debugNames.registerName( result, type->getName() );
		bool hasBuiltin = false;
		bool hasDynarray = false;

		for ( auto & member : *type )
		{
			auto index = member.type->getIndex();
			m_debugNames.registerMemberName( result, index, member.name );

			if ( member.builtin == ast::Builtin::eNone )
			{
				m_module.decorateMember( result
					, index
					, makeIdList( m_allocator, uint32_t( spv::DecorationOffset ), member.offset ) );
			}
			else
			{
				doAddMbrBuiltin( member.builtin, result, index );
				hasBuiltin = true;
			}

			auto kind = getNonArrayKind( member.type );

			if ( auto arraySize = getArraySize( member.type );
				arraySize == ast::type::UnknownArraySize )
			{
				hasDynarray = true;
			}

			if ( isMatrixType( kind ) )
			{
				auto colKind = getComponentType( kind );
				auto colType = m_typesCache->getBasicType( colKind );

				if ( auto rowCount = getComponentCount( colType );
					rowCount == 3
						|| ( rowCount == 2 && type->getMemoryLayout() == ast::type::MemoryLayout::eStd140 ) )
				{
					colType = m_typesCache->getVector( getComponentType( colKind ), 4u );
				}

				auto size = getSize( *colType
					, type->getMemoryLayout() );
				m_module.decorateMember( result
					, index
					, spv::DecorationColMajor );
				m_module.decorateMember( result
					, index
					, makeIdList( m_allocator, uint32_t( spv::DecorationMatrixStride ), size ) );
			}
		}

		if ( hasBuiltin || hasDynarray )
		{
			m_module.decorate( result, spv::DecorationBlock );
		}

		auto & resultId = m_registeredTypes.try_emplace( modtyp::myHash( type ), result ).first->second;
		m_nonSemanticDebug.registerStructType( std::move( type )
			, debugSubTypes
			, debugStatement
			, resultId );
		return resultId;
	}

	TypeId ModuleTypes::doRegisterBaseType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, TypeId const & parentId
		, glsl::Statement const * debugStatement )
	{
		TypeId result{ 0u, type };

		if ( type->getRawKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		if ( auto kind = type->getRawKind();
			kind == ast::type::Kind::eSampler )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::Sampler >( type ) );
		}
		else if ( kind == ast::type::Kind::eCombinedImage )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::CombinedImage >( type ) );
		}
		else if ( kind == ast::type::Kind::eImage )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::Image >( type ) );
		}
		else if ( kind == ast::type::Kind::eSampledImage )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::SampledImage >( type ) );
		}
		else if ( kind == ast::type::Kind::eAccelerationStructure )
		{
			result = doRegisterBaseType( std::static_pointer_cast< ast::type::AccelerationStructure >( type ) );
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
				, debugStatement );
		}

		return result;
	}

	bool ModuleTypes::doAddMbrBuiltin( ast::Builtin pbuiltin
		, DebugId const & outer
		, uint32_t mbrIndex )
	{
		bool result = false;
		ast::Vector< spv::Decoration > additionalDecorations{ m_allocator };

		if ( auto builtin = getBuiltin( pbuiltin, m_module.getExecutionModel(), additionalDecorations );
			builtin != spv::BuiltInMax )
		{
			m_module.decorateMember( outer, mbrIndex, makeIdList( m_allocator, spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) ) );

			for ( auto const & decoration : additionalDecorations )
			{
				m_module.decorateMember( outer, mbrIndex, decoration );
			}

			result = true;
		}

		return result;
	}

	//*************************************************************************
}
