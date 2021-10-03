/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvModule.hpp"

#include "SpirvHelpers.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#include <algorithm>

#define SDW_Spirv_IntermediatesPerBlock 0

namespace spirv
{
	//*************************************************************************

	namespace
	{
		ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::TypePtr qualified );

		ast::type::StructPtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::Struct const & qualified )
		{
			auto result = cache.getStruct( qualified.getMemoryLayout(), qualified.getName() );
			assert( result->empty() || ( result->size() == qualified.size() ) );

			if ( result->empty() && !qualified.empty() )
			{
				for ( auto & member : qualified )
				{
					auto type = getUnqualifiedType( cache, member.type );

					if ( type->getKind() == ast::type::Kind::eArray )
					{
						result->declMember( member.name
							, std::static_pointer_cast< ast::type::Array >( type ) );
					}
					else if ( type->getKind() == ast::type::Kind::eStruct )
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

		ast::type::ArrayPtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::Array const & qualified )
		{
			return cache.getArray( getUnqualifiedType( cache, qualified.getType() ), qualified.getArraySize() );
		}

		ast::type::SamplerPtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::Sampler const & qualified )
		{
			return cache.getSampler( qualified.isComparison() );
		}

		ast::type::SampledImagePtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::SampledImage const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return cache.getSampledImage( config );
		}

		ast::type::ImagePtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::Image const & qualified )
		{
			auto config = qualified.getConfig();
			// Ignore access kind, since it's not handled in non Kernel programs.
			// Prevents generating duplicate types in SPIRV programs.
			config.accessKind = ast::type::AccessKind::eReadWrite;
			return cache.getImage( config );
		}

		ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::Type const & qualified )
		{
			ast::type::TypePtr result;

			if ( qualified.getKind() == ast::type::Kind::eArray )
			{
				result = getUnqualifiedType( cache, static_cast< ast::type::Array const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eStruct )
			{
				result = getUnqualifiedType( cache, static_cast< ast::type::Struct const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eImage )
			{
				result = getUnqualifiedType( cache, static_cast< ast::type::Image const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eSampledImage )
			{
				result = getUnqualifiedType( cache, static_cast< ast::type::SampledImage const & >( qualified ) );
			}
			else if ( qualified.getKind() == ast::type::Kind::eSampler )
			{
				result = getUnqualifiedType( cache, static_cast< ast::type::Sampler const & >( qualified ) );
			}
			else if ( qualified.isMember() )
			{
				result = cache.getBasicType( qualified.getKind() );
			}

			return result;
		}

		ast::type::TypePtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::TypePtr qualified )
		{
			ast::type::TypePtr result = getUnqualifiedType( cache, *qualified );
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
				&& kind != ast::type::Kind::eSampledImage
				&& kind != ast::type::Kind::eSampler )
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
			, std::string const & name
			, ValueId initialiser
			, std::map< std::string, VariableInfo > & variables
			, InstructionList & instructions )
		{
			auto result = variables.emplace( name, VariableInfo{} ).first;
			result->second.id = varId;
			result->second.isParam = false;
			result->second.isAlias = false;
			instructions.push_back( makeVariableInstruction( varTypeId
				, varId
				, initialiser ) );
			return result;
		}
	}

	//*************************************************************************

	Module::Module( ast::type::TypesCache & pcache
		, SpirVConfig const & spirvConfig
		, spv::MemoryModel pmemoryModel
		, spv::ExecutionModel pexecutionModel )
		: memoryModel{ makeInstruction< MemoryModelInstruction >( ValueId{ spv::Id( spv::AddressingModelLogical ) }, ValueId{ spv::Id( pmemoryModel ) } ) }
		, variables{ &globalDeclarations }
		, m_cache{ &pcache }
		, m_currentScopeVariables{ &m_registeredVariables }
		, m_model{ pexecutionModel }
	{
		initialiseHeader(
			{
				spv::MagicNumber,
				spirvConfig.specVersion,
				0x00100001,
				1u,	// Bound IDs.
				0u	// Schema.
			} );
		initialiseExtensions();
		initialiseCapacities();
	}

	Module::Module( Header const & pheader
		, InstructionList && instructions )
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
		auto it = spirv.cbegin();
		auto popValue = [&it]( uint32_t & value )
		{
			value = *it;
			++it;
		};
		auto popInstruction = [&it]()
		{
			return spirv::Instruction::deserialize( it );
		};
		Header header{};
		popValue( header.magic );
		popValue( header.version );
		popValue( header.builder );
		popValue( header.boundIds );
		popValue( header.schema );
		assert( header.magic == spv::MagicNumber );
		spirv::InstructionList instructions;

		while ( it != spirv.end() )
		{
			instructions.emplace_back( popInstruction() );
		}

		return Module{ header, std::move( instructions ) };
	}

	ValueId Module::registerType( ast::type::TypePtr type )
	{
		return registerType( type
			, ast::type::NotMember
			, ValueId{}
			, 0u );
	}

	ValueId Module::registerPointerType( ValueId type
		, spv::StorageClass storage )
	{
		uint64_t key = ( uint64_t( type.id ) << 33 )
			| ( ( uint64_t( type.isPointer() ) << 32 ) & 0x01 )
			| uint64_t( storage );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			ValueId id{ getNextId()
				, type.type->getCache().getPointerType( type.type, convert( storage ) ) };
			it = m_registeredPointerTypes.emplace( key, id ).first;
			globalDeclarations.push_back( makeInstruction< PointerTypeInstruction >( id
				, ValueId{ spv::Id( storage ) }
				, type ) );
		}

		return it->second;
	}

	void Module::decorate( ValueId id, spv::Decoration decoration )
	{
		decorate( id, IdList{ spv::Id( decoration ) } );
	}

	void Module::decorate( ValueId id
		, IdList const & decoration )
	{
		ValueIdList operands;
		operands.push_back( id );
		auto decos = convert( decoration );
		operands.insert( operands.end(), decos.begin(), decos.end() );
		decorations.push_back( makeInstruction< DecorateInstruction >( operands ) );
	}

	void Module::decorateMember( ValueId id
		, uint32_t index
		, spv::Decoration decoration )
	{
		decorateMember( id, index, IdList{ spv::Id( decoration ) } );
	}

	void Module::decorateMember( ValueId id
		, uint32_t index
		, IdList const & decoration )
	{
		ValueIdList operands;
		operands.push_back( id );
		operands.push_back( { index } );
		auto decos = convert( decoration );
		operands.insert( operands.end(), decos.begin(), decos.end() );
		decorations.push_back( makeInstruction< MemberDecorateInstruction >( operands ) );
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
				, varId.type->getCache().getPointerType( varId.type, convert( storage ) ) };
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

	void Module::storeVariable( ValueId variable
		, ValueId value
		, Block & currentBlock )
	{
		assert( variable.isPointer() );

		if ( value.isPointer() )
		{
			value = loadVariable( value, currentBlock );
		}

		currentBlock.instructions.push_back( makeInstruction< StoreInstruction >( variable
			, value ) );
	}

	ValueId Module::loadVariable( ValueId variable
		, Block & currentBlock )
	{
		if ( variable.isPointer() )
		{
			auto type = static_cast< ast::type::Pointer const & >( *variable.type ).getPointerType();
			auto typeId = registerType( type );
			ValueId result{ getIntermediateResult(), typeId.type };
			currentBlock.instructions.push_back( makeInstruction< LoadInstruction >( typeId
				, result
				, variable ) );
			lnkIntermediateResult( result, variable );
			return result;
		}

		return variable;
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

	void Module::registerParam( std::string const & name
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
				it = m_currentScopeVariables->emplace( name
					, VariableInfo{ typeId, false, true, isOutput } ).first;
			}
			else
			{
				it = m_registeredVariables.emplace( name
					, VariableInfo{ typeId, false, true, isOutput } ).first;
			}

			m_registeredVariablesTypes.emplace( typeId, rawTypeId );
		}
	}

	void Module::registerAlias( std::string const & name
		, ast::type::TypePtr type
		, ValueId exprResultId )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			auto rawTypeId = registerType( type );

			if ( m_currentFunction )
			{
				it = m_currentScopeVariables->emplace( name
					, VariableInfo{ exprResultId, true, false, false } ).first;
			}
			else
			{
				it = m_registeredVariables.emplace( name
					, VariableInfo{ exprResultId, true, false, false } ).first;
			}

			m_registeredVariablesTypes.emplace( exprResultId, rawTypeId );
		}
	}

	VariableInfo Module::registerVariable( std::string const & name
		, spv::StorageClass storage
		, bool isAlias
		, bool isParam
		, bool isOutParam
		, ast::type::TypePtr type
		, VariableInfo & sourceInfo
		, ValueId initialiser )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			ValueId id{ getNextId()
				, type->getCache().getPointerType( type, convert( storage ) ) };
			addDebug( name, id );
			addBuiltin( name, id );
			addVariable( name, id, it, initialiser );
			sourceInfo = it->second;
		}
		else
		{
			sourceInfo = it->second;

			if ( ( it->second.isParam && !isParam && ( !isPointerParam( type, isOutParam ) ) )
				|| ( it->second.isAlias && !isAlias ) )
			{
				ValueId id{ getNextId()
					, type->getCache().getPointerType( ( it->second.id.isPointer()
							? static_cast< ast::type::Pointer const & >( *it->second.id.type ).getPointerType()
							: it->second.id.type )
						, convert( storage ) ) };
				it->second.isAlias = false;
				it->second.isParam = false;
				it->second.isOutParam = false;
				addDebug( "ptr_" + name, id );
				addVariable( name, id, it, {} );
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
				case ast::expr::LiteralType::eInt:
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt >() ) );
					break;
				case ast::expr::LiteralType::eUInt:
					operands.emplace_back( value.getValue< ast::expr::LiteralType::eUInt >() );
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
				, type->getCache().getPointerType( type, outer.getStorage() ) };
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
			auto type = registerType( m_cache->getBool() );
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
			m_registeredConstants.emplace( result, m_cache->getBool() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( int32_t value )
	{
		auto it = m_registeredIntConstants.find( value );

		if ( it == m_registeredIntConstants.end() )
		{
			auto type = registerType( m_cache->getInt() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ spv::Id( value ) } } ) );
			it = m_registeredIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getInt() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( uint32_t value )
	{
		auto it = m_registeredUIntConstants.find( value );

		if ( it == m_registeredUIntConstants.end() )
		{
			auto type = registerType( m_cache->getUInt() );
			ValueId result{ getNextId(), type.type };
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, ValueIdList{ ValueId{ value } } ) );
			it = m_registeredUIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getUInt() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( float value )
	{
		auto it = m_registeredFloatConstants.find( value );

		if ( it == m_registeredFloatConstants.end() )
		{
			auto type = registerType( m_cache->getFloat() );
			ValueId result{ getNextId(), type.type };
			IdList list;
			list.resize( 1u );
			auto dst = reinterpret_cast< float * >( list.data() );
			*dst = value;
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, convert( list ) ) );
			it = m_registeredFloatConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getFloat() );
		}

		return it->second;
	}

	ValueId Module::registerLiteral( double value )
	{
		auto it = m_registeredDoubleConstants.find( value );

		if ( it == m_registeredDoubleConstants.end() )
		{
			auto type = registerType( m_cache->getDouble() );
			ValueId result{ getNextId(), type.type };
			IdList list;
			list.resize( 2u );
			auto dst = reinterpret_cast< double * >( list.data() );
			*dst = value;
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, convert( list ) ) );
			it = m_registeredDoubleConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getDouble() );
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

	void Module::registerExtension( std::string const & name )
	{
		extensions.push_back( makeInstruction< ExtensionInstruction >( name ) );
	}

	void Module::registerEntryPoint( ValueId functionId
		, std::string const & name
		, ValueIdList const & inputs
		, ValueIdList const & outputs )
	{
		ValueIdList operands;
		operands.insert( operands.end(), inputs.begin(), inputs.end() );
		operands.insert( operands.end(), outputs.begin(), outputs.end() );
		entryPoint = makeInstruction< EntryPointInstruction >( ValueId{ spv::Id( m_model ) }
			, functionId
			, operands
			, name );

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
			//registerExecutionMode( spv::ExecutionModeOriginLowerLeft );
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

	Function * Module::beginFunction( std::string const & name
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
			ValueId funcType{ getNextId(), funcType.type };
			globalDeclarations.push_back( makeInstruction< FunctionTypeInstruction >( funcType
				, funcTypes ) );
			it = m_registeredFunctionTypes.emplace( funcTypes, funcType ).first;
		}

		ValueId funcType{ it->second };
		m_currentFunction->declaration.emplace_back( makeInstruction< FunctionInstruction >( retType
			, result
			, ValueId{ spv::Id( spv::FunctionControlMaskNone ) }
			, funcType ) );
		auto itType = funcTypes.begin() + 1u;
		auto itParam = funcParams.begin();

		for ( auto i = params.begin(); i != params.end(); ++i )
		{
			m_currentFunction->declaration.emplace_back( makeInstruction< FunctionParameterInstruction >( *itType
				, *itParam ) );
			++itType;
			++itParam;
		}

		m_registeredVariablesTypes.emplace( result, funcType );
		debug.push_back( makeInstruction< NameInstruction >( result, name ) );
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
			auto vars = std::move( m_currentFunction->variables );
			std::reverse( vars.begin(), vars.end() );

			for ( auto & variable : vars )
			{
				instructions.emplace( instructions.begin() + 1u
					, std::move( variable ) );
			}

			m_currentFunction->variables.clear();
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
		auto unqualifiedType = getUnqualifiedType( *m_cache, type );
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

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			auto arrayedType = std::static_pointer_cast< ast::type::Array >( type )->getType();
			auto arraySize = getArraySize( type );
			auto elementTypeId = registerType( arrayedType
				, mbrIndex
				, parentId
				, arrayStride );

			auto unqualifiedType = getUnqualifiedType( *m_cache, type );
			auto it = m_registeredTypes.find( unqualifiedType );

			if ( it == m_registeredTypes.end() )
			{
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
		else if ( type->getKind() == ast::type::Kind::ePointer )
		{
			auto & pointerType = static_cast< ast::type::Pointer const & >( *type );
			auto rawTypeId = registerType( pointerType.getPointerType()
				, mbrIndex
				, parentId
				, arrayStride );
			result = registerPointerType( rawTypeId
				, convert( pointerType.getStorage() ) );
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
		assert( kind != ast::type::Kind::eImage );
		assert( kind != ast::type::Kind::eSampledImage );

		auto type = m_cache->getBasicType( kind );
		ValueId result{ 0u, type };

		if ( isVectorType( kind )
			|| isMatrixType( kind ) )
		{
			auto componentType = registerType( m_cache->getBasicType( getComponentType( kind ) ) );
			result.id = getNextId();

			if ( isMatrixType( kind ) )
			{
				globalDeclarations.push_back( makeInstruction< MatrixTypeInstruction >( result
					, componentType
					, ValueId{ getComponentCount( kind ) } ) );

				if ( mbrIndex == ast::type::NotMember )
				{
					decorate( result
						, spv::DecorationColMajor );
				}
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

	ValueId Module::registerBaseType( ast::type::SampledImagePtr type
		, uint32_t mbrIndex
		, ValueId parentId )
	{
		auto imgTypeId = registerType( std::static_pointer_cast< ast::type::SampledImage >( type )->getImageType() );
		ValueId result{ getNextId(), type };
		globalDeclarations.push_back( makeInstruction< SampledImageTypeInstruction >( result
			, imgTypeId ) );
		return result;
	}

	ValueId Module::registerBaseType( ast::type::ImagePtr type
		, uint32_t mbrIndex
		, ValueId parent )
	{
		// The Sampled Type.
		auto sampledTypeId = registerType( m_cache->getBasicType( type->getConfig().sampledType ) );
		// The Image Type.
		ValueId result{ getNextId(), type };
		globalDeclarations.push_back( makeImageTypeInstruction( type->getConfig()
			, result
			, sampledTypeId ) );
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

		for ( auto & member : *type )
		{
			auto index = member.type->getIndex();
			debug.push_back( makeInstruction< MemberNameInstruction >( result, ValueId{ index }, member.name ) );

			if ( !addMbrBuiltin( member.name, result, index ) )
			{
				decorateMember( result
					, index
					, { uint32_t( spv::DecorationOffset ), member.offset } );
			}
			else
			{
				hasBuiltin = true;
			}

			auto kind = getNonArrayKind( member.type );

			if ( isMatrixType( kind ) )
			{
				auto colKind = getComponentType( kind );
				auto colType = m_cache->getBasicType( colKind );
				auto rowCount = getComponentCount( colType );

				if ( rowCount == 3 )
				{
					colType = m_cache->getVector( getComponentType( colKind ), 4u );
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

		if ( hasBuiltin )
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

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		auto kind = type->getKind();

		if ( kind == ast::type::Kind::eSampledImage )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::SampledImage >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eImage )
		{
			result = registerBaseType( std::static_pointer_cast< ast::type::Image >( type )
				, mbrIndex
				, parentId );
		}
		else if ( kind == ast::type::Kind::eStruct )
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
		extensions.push_back( makeInstruction< ExtInstImportInstruction >( id
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
			capabilities.push_back( makeInstruction< CapabilityInstruction >( ValueId{ spv::Id( spv::CapabilityShader ) } ) );
			break;
		case spv::ExecutionModelTessellationControl:
		case spv::ExecutionModelTessellationEvaluation:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( ValueId{ spv::Id( spv::CapabilityShader ) } ) );
			capabilities.push_back( makeInstruction< CapabilityInstruction >( ValueId{ spv::Id( spv::CapabilityTessellation ) } ) );
			break;
		case spv::ExecutionModelGeometry:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( ValueId{ spv::Id( spv::CapabilityShader ) } ) );
			capabilities.push_back( makeInstruction< CapabilityInstruction >( ValueId{ spv::Id( spv::CapabilityGeometry ) } ) );
			break;
		case spv::ExecutionModelKernel:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( ValueId{ spv::Id( spv::CapabilityKernel ) } ) );
			break;
		default:
			AST_Failure( "Unsupported ExecutionModel" );
			break;
		}
	}

	void Module::addDebug( std::string const & name
		, ValueId id )
	{
		auto type = id.type;

		if ( type->getKind() != ast::type::Kind::eStruct
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() != name )
		{
			debug.push_back( makeInstruction< NameInstruction >( id, name ) );
		}
		else if ( type->getKind() == ast::type::Kind::eStruct
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() == name )
		{
			debug.push_back( makeInstruction< NameInstruction >( id, name + "Inst" ) );
		}
	}

	void Module::addBuiltin( std::string const & name
		, ValueId id )
	{
		auto builtin = getBuiltin( name );

		if ( builtin != spv::BuiltInMax )
		{
			decorate( id, { spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) } );
		}
	}

	bool Module::addMbrBuiltin( std::string const & name
		, ValueId outer
		, uint32_t mbrIndex )
	{
		bool result = false;
		auto builtin = getBuiltin( name );

		if ( builtin != spv::BuiltInMax )
		{
			decorateMember( outer, mbrIndex, { spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) } );
			result = true;
		}

		return result;
	}

	void Module::addVariable( std::string const & name
		, ValueId varId
		, std::map< std::string, VariableInfo >::iterator & it
		, ValueId initialiser )
	{
		assert( varId.isPointer() );
		auto type = varId.type;
		auto rawType = static_cast< ast::type::Pointer const & >( *type ).getPointerType();
		auto rawTypeId = registerType( rawType );

		if ( varId.getStorage() == ast::type::Storage::ePushConstant )
		{
			decorate( rawTypeId, spv::DecorationBlock );
		}

		auto varTypeId = registerPointerType( rawTypeId
			, convert( varId.getStorage() ) );

		if ( varId.getStorage() == ast::type::Storage::eFunction
			&& m_currentFunction )
		{
			it = doAddVariable( varTypeId
				, varId
				, name
				, initialiser
				, *m_currentScopeVariables
				, m_currentFunction->variables );
		}
		else
		{
			it = doAddVariable( varTypeId
				, varId
				, name
				, initialiser
				, m_registeredVariables
				, globalDeclarations );
		}

		m_registeredVariablesTypes.emplace( varId, rawTypeId );
	}

	InstructionList * Module::selectInstructionsList( spv::Op opCode )
	{
		InstructionList * list{ nullptr };

		switch ( opCode )
		{
		case spv::OpSource:
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
