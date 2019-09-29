/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirvModule.hpp"

#include "SpirvHelpers.hpp"
#include "SpirvStmtRegister.hpp"

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
		ast::type::Kind getComponentType( ast::type::ImageFormat format )
		{
			ast::type::Kind result;

			switch ( format )
			{
			case ast::type::ImageFormat::eRgba32f:
			case ast::type::ImageFormat::eRgba16f:
			case ast::type::ImageFormat::eRg32f:
			case ast::type::ImageFormat::eRg16f:
			case ast::type::ImageFormat::eR32f:
			case ast::type::ImageFormat::eR16f:
				return ast::type::Kind::eFloat;

			case ast::type::ImageFormat::eRgba32i:
			case ast::type::ImageFormat::eRgba16i:
			case ast::type::ImageFormat::eRgba8i:
			case ast::type::ImageFormat::eRg32i:
			case ast::type::ImageFormat::eRg16i:
			case ast::type::ImageFormat::eRg8i:
			case ast::type::ImageFormat::eR32i:
			case ast::type::ImageFormat::eR16i:
			case ast::type::ImageFormat::eR8i:
				return ast::type::Kind::eInt;

			case ast::type::ImageFormat::eRgba32u:
			case ast::type::ImageFormat::eRgba16u:
			case ast::type::ImageFormat::eRgba8u:
			case ast::type::ImageFormat::eRg32u:
			case ast::type::ImageFormat::eRg16u:
			case ast::type::ImageFormat::eRg8u:
			case ast::type::ImageFormat::eR32u:
			case ast::type::ImageFormat::eR16u:
			case ast::type::ImageFormat::eR8u:
				return ast::type::Kind::eUInt;

			default:
				assert( false && "Unsupported ast::type::ImageFormat." );
				return ast::type::Kind::eFloat;
			}

			return result;
		}

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
			return cache.getSampledImage( qualified.getConfig() );
		}

		ast::type::ImagePtr getUnqualifiedType( ast::type::TypesCache & cache
			, ast::type::Image const & qualified )
		{
			return cache.getImage( qualified.getConfig() );
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

		ast::type::MemoryLayout getMemoryLayout( ast::type::Type const & type )
		{
			ast::type::MemoryLayout result{ ast::type::MemoryLayout::eStd430 };
			auto kind = type.getKind();

			if ( kind == ast::type::Kind::eArray )
			{
				if ( type.isMember() )
				{
					result = getMemoryLayout( *type.getParent() );
				}
				else
				{
					result = getMemoryLayout( *static_cast< ast::type::Array const & >( type ).getType() );
				}
			}
			else if ( kind == ast::type::Kind::eStruct )
			{
				auto & structType = static_cast< ast::type::Struct const & >( type );
				result = structType.getMemoryLayout();
			}
			else if ( type.isMember() )
			{
				result = getMemoryLayout( *type.getParent() );
			}

			return result;
		}

		void writeArrayStride( Module & module
			, ast::type::TypePtr type
			, uint32_t typeId
			, uint32_t arrayStride )
		{
			auto kind = getNonArrayKind( type );

			if ( kind != ast::type::Kind::eImage
				&& kind != ast::type::Kind::eSampledImage
				&& kind != ast::type::Kind::eSampler )
			{
				module.decorate( typeId
					, IdList
					{
						uint32_t( spv::DecorationArrayStride ),
						arrayStride
					} );
			}
		}
	}

	//*************************************************************************

	Module::Module( ast::type::TypesCache & cache
		, spv::MemoryModel memoryModel
		, spv::ExecutionModel executionModel )
		: variables{ &globalDeclarations }
		, memoryModel{ makeInstruction< MemoryModelInstruction >( spv::Id( spv::AddressingModelLogical ), spv::Id( memoryModel ) ) }
		, m_cache{ &cache }
		, m_model{ executionModel }
		, m_currentScopeVariables{ &m_registeredVariables }
	{
		initialiseHeader(
			{
				spv::MagicNumber,
				0x00010000,
				0x00100001,
				1u,	// Bound IDs.
				0u	// Schema.
			} );
		initialiseExtensions();
		initialiseCapacities();
	}

	Module::Module( Header const & header
		, InstructionList && instructions )
		: variables{ &globalDeclarations }
	{
		initialiseHeader( header );
		auto it = instructions.begin();

		while ( it != instructions.end() )
		{
			auto opCode = spv::Op( ( *it )->op.opCode );
			deserializeInfos( opCode, it, instructions.end() );
			deserializeFuncs( opCode, it, instructions.end() );

			if ( auto * list = selectInstructionsList( opCode ) )
			{
				list->emplace_back( std::move( *it ) );
				++it;
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
		assert( header.magic = spv::MagicNumber );
		spirv::InstructionList instructions;

		while ( it != spirv.end() )
		{
			instructions.emplace_back( popInstruction() );
		}

		return Module{ header, std::move( instructions ) };
	}

	spv::Id Module::registerType( ast::type::TypePtr type )
	{
		return registerType( type
			, ast::type::NotMember
			, 0u
			, 0u );
	}

	spv::Id Module::registerPointerType( spv::Id type, spv::StorageClass storage )
	{
		uint64_t key = ( uint64_t( type ) << 32 ) | uint64_t( storage );
		auto it = m_registeredPointerTypes.find( key );

		if ( it == m_registeredPointerTypes.end() )
		{
			spv::Id id{ getNextId() };
			it = m_registeredPointerTypes.emplace( key, id ).first;
			globalDeclarations.push_back( makeInstruction< PointerTypeInstruction >( id
				, spv::Id( storage )
				, type ) );
		}

		return it->second;
	}

	void Module::decorate( spv::Id id, spv::Decoration decoration )
	{
		decorate( id, IdList{ spv::Id( decoration ) } );
	}

	void Module::decorate( spv::Id id
		, IdList const & decoration )
	{
		IdList operands;
		operands.push_back( id );
		operands.insert( operands.end(), decoration.begin(), decoration.end() );
		decorations.push_back( makeInstruction< DecorateInstruction >( operands ) );
	}

	void Module::decorateMember( spv::Id id
		, uint32_t index
		, spv::Decoration decoration )
	{
		decorateMember( id, index, IdList{ spv::Id( decoration ) } );
	}

	void Module::decorateMember( spv::Id id
		, uint32_t index
		, IdList const & decoration )
	{
		IdList operands;
		operands.push_back( id );
		operands.push_back( index );
		operands.insert( operands.end(), decoration.begin(), decoration.end() );
		decorations.push_back( makeInstruction< MemberDecorateInstruction >( operands ) );
	}

	spv::Id Module::loadVariable( spv::Id variable
		, ast::type::TypePtr type
		, Block & currentBlock )
	{
		auto result = getIntermediateResult();
		currentBlock.instructions.push_back( makeInstruction< LoadInstruction >( registerType( type )
			, result
			, variable ) );
		lnkIntermediateResult( result, variable );
		return result;
	}

	void Module::bindVariable( spv::Id varId
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
			auto varId = varIt->second;
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

	VariableInfo & Module::registerVariable( std::string const & name
		, spv::StorageClass storage
		, ast::type::TypePtr type
		, VariableInfo & info )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			spv::Id id{ getNextId() };
			addDebug( name, type, id );
			addBuiltin( name, id );
			addVariable( name, storage, type, id, it );
		}

		info.id = it->second;
		return info;
	}

	spv::Id Module::registerSpecConstant( std::string name
		, uint32_t location
		, ast::type::TypePtr type
		, ast::expr::Literal const & value )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			spv::Id id{ getNextId() };
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
				}

				globalDeclarations.emplace_back( makeInstruction< SpecConstantInstruction >( rawTypeId
					, id
					, operands ) );
			}

			decorate( id, { spv::Id( spv::DecorationSpecId ), spv::Id( location ) } );
			m_registeredVariablesTypes.emplace( id, rawTypeId );
			m_registeredConstants.emplace( id, value.getType() );
		}

		return it->second;
	}

	spv::Id Module::registerParameter( ast::type::TypePtr type )
	{
		auto typeId = registerType( type );
		auto paramId = getNextId();
		return paramId;
	}

	spv::Id Module::registerMemberVariableIndex( ast::type::TypePtr type )
	{
		assert( type->isMember() );
		return registerLiteral( type->getIndex() );
	}

	spv::Id Module::registerMemberVariable( spv::Id outer
		, std::string name
		, ast::type::TypePtr type )
	{
		auto it = std::find_if( m_currentScopeVariables->begin()
			, m_currentScopeVariables->end()
			, [outer]( std::map< std::string, spv::Id >::value_type const & pair )
			{
				return pair.second == outer;
			} );
		assert( it != m_currentScopeVariables->end() );
		assert( type->isMember() );
		auto fullName = it->first + "::" + name;
		auto outerId = it->second;
		it = m_currentScopeVariables->find( fullName );

		if ( it == m_currentScopeVariables->end() )
		{
			spv::Id id{ getNextId() };
			m_registeredMemberVariables.insert( { fullName, { outer, id } } );
			it = m_currentScopeVariables->emplace( fullName, id ).first;
			registerLiteral( type->getIndex() );
		}

		return it->second;
	}

	ast::type::Kind Module::getLiteralType( spv::Id litId )const
	{
		auto it = m_registeredConstants.find( litId );
		assert( it != m_registeredConstants.end() );
		return it->second->getKind();
	}

	spv::Id Module::getOuterVariable( spv::Id mbrId )const
	{
		auto itInner = std::find_if( m_registeredMemberVariables.begin()
			, m_registeredMemberVariables.end()
			, [mbrId]( std::map< std::string, std::pair< spv::Id, spv::Id > >::value_type const & pair )
			{
				return pair.second.second == mbrId;
			} );
		assert( itInner != m_registeredMemberVariables.end() );
		
		auto result = itInner->second.first;
		auto itOuter = m_registeredMemberVariables.end();

		while ( ( itOuter = std::find_if( m_registeredMemberVariables.begin()
				, m_registeredMemberVariables.end()
				, [result]( std::map< std::string, std::pair< spv::Id, spv::Id > >::value_type const & pair )
				{
					return pair.second.second == result;
				} ) ) != m_registeredMemberVariables.end() )
		{
			result = itOuter->second.first;
		}

		auto itOutermost = std::find_if( m_currentScopeVariables->begin()
			, m_currentScopeVariables->end()
			, [result]( std::map< std::string, spv::Id >::value_type const & pair )
			{
					return pair.second == result;
			} );
		assert( itOutermost != m_currentScopeVariables->end() );
		result = itOutermost->second;
		return result;
	}

	spv::Id Module::registerLiteral( bool value )
	{
		auto it = m_registeredBoolConstants.find( value );

		if ( it == m_registeredBoolConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getBool() );

			if ( value )
			{
				globalDeclarations.push_back( makeInstruction< ConstantTrueInstruction >( type, result ) );
			}
			else
			{
				globalDeclarations.push_back( makeInstruction< ConstantFalseInstruction >( type, result ) );
			}

			it = m_registeredBoolConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getBool() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( int32_t value )
	{
		auto it = m_registeredIntConstants.find( value );

		if ( it == m_registeredIntConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getInt() );
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, IdList{ uint32_t( value ) } ) );
			it = m_registeredIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getInt() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( uint32_t value )
	{
		auto it = m_registeredUIntConstants.find( value );

		if ( it == m_registeredUIntConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getUInt() );
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, IdList{ value } ) );
			it = m_registeredUIntConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getUInt() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( float value )
	{
		auto it = m_registeredFloatConstants.find( value );

		if ( it == m_registeredFloatConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getFloat() );
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, IdList{ *reinterpret_cast< uint32_t * >( &value ) } ) );
			it = m_registeredFloatConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getFloat() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( double value )
	{
		auto it = m_registeredDoubleConstants.find( value );

		if ( it == m_registeredDoubleConstants.end() )
		{
			spv::Id result{ getNextId() };
			auto type = registerType( m_cache->getDouble() );
			IdList list;
			list.resize( 2u );
			auto dst = reinterpret_cast< double * >( list.data() );
			*dst = value;
			globalDeclarations.push_back( makeInstruction< ConstantInstruction >( type
				, result
				, list ) );
			it = m_registeredDoubleConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_cache->getDouble() );
		}

		return it->second;
	}

	spv::Id Module::registerLiteral( IdList const & initialisers
		, ast::type::TypePtr type )
	{
		auto typeId = registerType( type );
		auto it = std::find_if( m_registeredCompositeConstants.begin()
			, m_registeredCompositeConstants.end()
			, [initialisers]( std::pair< IdList, spv::Id > const & lookup )
			{
				return lookup.first == initialisers;
			} );

		if ( it == m_registeredCompositeConstants.end() )
		{
			spv::Id result{ getNextId() };
			globalDeclarations.push_back( makeInstruction< ConstantCompositeInstruction >( typeId
				, result
				, initialisers ) );
			m_registeredCompositeConstants.emplace_back( initialisers, result );
			it = m_registeredCompositeConstants.begin() + m_registeredCompositeConstants.size() - 1u;
			m_registeredConstants.emplace( result, type );
		}

		return it->second;
	}

	void Module::registerExtension( std::string const & name )
	{
		extensions.push_back( makeInstruction< ExtensionInstruction >( name ) );
	}

	void Module::registerEntryPoint( spv::Id functionId
		, std::string const & name
		, IdList const & inputs
		, IdList const & outputs )
	{
		IdList operands;
		operands.insert( operands.end(), inputs.begin(), inputs.end() );
		operands.insert( operands.end(), outputs.begin(), outputs.end() );
		entryPoint = makeInstruction< EntryPointInstruction >( spv::Id( m_model )
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
			executionModes.back()->operands[0] = functionId;
		}

		m_pendingExecutionModes.clear();
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode )
	{
		registerExecutionMode( mode, {} );
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode, IdList const & operands )
	{
		if ( !entryPoint || entryPoint->operands.empty() )
		{
			IdList ops;
			ops.push_back( spv::Id( 0u ) );
			ops.push_back( spv::Id( mode ) );
			ops.insert( ops.end(), operands.begin(), operands.end() );
			m_pendingExecutionModes.push_back( makeInstruction< ExecutionModeInstruction >( ops ) );
		}
		else
		{
			IdList ops;
			ops.push_back( entryPoint->resultId.value() );
			ops.push_back( spv::Id( mode ) );
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

	void Module::lnkIntermediateResult( spv::Id intermediate, spv::Id var )
	{
		if ( m_intermediates.end() != m_intermediates.find( intermediate ) )
		{
			m_busyIntermediates.emplace( intermediate, var );
		}
	}

	void Module::putIntermediateResult( spv::Id id )
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

	spv::Id Module::getNonIntermediate( spv::Id id )
	{
		while ( m_intermediates.end() != m_intermediates.find( id ) )
		{
			id = m_busyIntermediates.find( id )->second;
		}

		return id;
	}

	Function * Module::beginFunction( std::string const & name
		, spv::Id retType
		, ast::var::VariableList const & params )
	{
		spv::Id result{ getNextId() };
		m_registeredVariables.emplace( name, result );

		IdList funcTypes;
		IdList funcParams;
		funcTypes.push_back( retType );
		Function func;
		functions.emplace_back( std::move( func ) );
		m_currentFunction = &functions.back();
		m_currentFunction->registeredVariables = m_registeredVariables; // the function has access to global scope variables.
		m_currentScopeVariables = &m_currentFunction->registeredVariables;

		for ( auto & param : params )
		{
			funcTypes.push_back( registerType( param->getType() ) );
			spv::Id paramId{ getNextId() };
			funcParams.push_back( paramId );
			debug.push_back( makeInstruction< NameInstruction >( paramId, param->getName() ) );
			auto kind = param->getType()->getKind();

			if ( isSampledImageType( kind )
				|| isImageType( kind )
				|| isSamplerType( kind ) )
			{
				funcTypes.back() = registerPointerType( funcTypes.back(), spv::StorageClassUniformConstant );
			}
			else
			{
				funcTypes.back() = registerPointerType( funcTypes.back(), spv::StorageClassFunction );
			}

			m_currentScopeVariables->emplace( param->getName(), funcParams.back() );
			m_registeredVariablesTypes.emplace( funcParams.back(), funcTypes.back() );
		}

		auto it = m_registeredFunctionTypes.find( funcTypes );

		if ( it == m_registeredFunctionTypes.end() )
		{
			spv::Id funcType{ getNextId() };
			globalDeclarations.push_back( makeInstruction< FunctionTypeInstruction >( funcType
				, funcTypes ) );
			it = m_registeredFunctionTypes.emplace( funcTypes, funcType ).first;
		}

		spv::Id funcType{ it->second };
		m_currentFunction->declaration.emplace_back( makeInstruction< FunctionInstruction >( retType
			, result
			, spv::Id( spv::FunctionControlMaskNone )
			, funcType ) );
		auto itType = funcTypes.begin() + 1u;
		auto itParam = funcParams.begin();

		for ( auto & param : params )
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
		Block result
		{
			getNextId()
		};
		result.instructions.push_back( makeInstruction< LabelInstruction >( result.label ) );
		return result;
	}

	void Module::endFunction()
	{
		if ( m_currentFunction
			&& !m_currentFunction->cfg.blocks.empty()
			&& !m_currentFunction->variables.empty() )
		{
			auto & instructions = m_currentFunction->cfg.blocks.begin()->instructions;
			auto variables = std::move( m_currentFunction->variables );
			std::reverse( variables.begin(), variables.end() );

			for ( auto & variable : variables )
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

	spv::Id Module::doRegisterNonArrayType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		spv::Id result;

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

	spv::Id Module::registerType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId
		, uint32_t arrayStride )
	{
		spv::Id result;

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
					result = getNextId();
					globalDeclarations.push_back( makeInstruction< ArrayTypeInstruction >( result
						, elementTypeId
						, lengthId ) );
				}
				else
				{
					result = getNextId();
					globalDeclarations.push_back( makeInstruction< RuntimeArrayTypeInstruction >( result
						, elementTypeId ) );
				}

				writeArrayStride( *this
					, unqualifiedType
					, result
					, arrayStride );
				m_registeredTypes.emplace( unqualifiedType, result );
			}
			else
			{
				result = it->second;
			}
		}
		else
		{
			result = doRegisterNonArrayType( type
				, mbrIndex
				, parentId );
		}

		return result;
	}

	spv::Id Module::registerBaseType( ast::type::Kind kind
		, uint32_t mbrIndex
		, spv::Id parentId
		, uint32_t arrayStride )
	{
		assert( kind != ast::type::Kind::eStruct );
		assert( kind != ast::type::Kind::eImage );
		assert( kind != ast::type::Kind::eSampledImage );

		spv::Id result{};
		auto type = m_cache->getBasicType( kind );

		if ( isVectorType( kind )
			|| isMatrixType( kind ) )
		{
			auto componentType = registerType( m_cache->getBasicType( getComponentType( kind ) ) );
			result = getNextId();

			if ( isMatrixType( kind ) )
			{
				globalDeclarations.push_back( makeInstruction< MatrixTypeInstruction >( result
					, componentType
					, getComponentCount( kind ) ) );

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
					, getComponentCount( kind ) ) );
			}
		}
		else
		{
			result = getNextId();
			globalDeclarations.push_back( makeBaseTypeInstruction( kind, result ) );
		}

		return result;
	}

	spv::Id Module::registerBaseType( ast::type::SampledImagePtr type
		, uint32_t mbrIndex
		, spv::Id parentId )
	{
		auto imgTypeId = registerType( std::static_pointer_cast< ast::type::SampledImage >( type )->getImageType() );
		auto result = getNextId();
		globalDeclarations.push_back( makeInstruction< SampledImageTypeInstruction >( result
			, imgTypeId ) );
		return result;
	}

	spv::Id Module::registerBaseType( ast::type::ImagePtr type
		, uint32_t mbrIndex
		, spv::Id parent )
	{
		// The Sampled Type.
		auto sampledTypeId = registerType( m_cache->getBasicType( type->getConfig().sampledType ) );
		// The Image Type.
		auto result = getNextId();
		globalDeclarations.push_back( makeImageTypeInstruction( type->getConfig(), result, sampledTypeId ) );
		return result;
	}

	spv::Id Module::registerBaseType( ast::type::StructPtr type
		, uint32_t
		, spv::Id )
	{
		spv::Id result{ getNextId() };
		IdList subTypes;

		for ( auto & member : *type )
		{
			subTypes.push_back( registerType( member.type
				, member.type->getIndex()
				, result
				, member.arrayStride ) );
		}

		globalDeclarations.push_back( makeInstruction< StructTypeInstruction >( result, subTypes ) );
		debug.push_back( makeInstruction< NameInstruction >( result, type->getName() ) );

		for ( auto & member : *type )
		{
			auto index = member.type->getIndex();
			debug.push_back( makeInstruction< MemberNameInstruction >( result, index, member.name ) );
			decorateMember( result
				, index
				, makeOperands( uint32_t( spv::DecorationOffset ), member.offset ) );
			auto kind = getNonArrayKind( member.type );

			if ( isMatrixType( kind ) )
			{
				auto colType = getComponentType( kind );
				auto size = getSize( *m_cache->getBasicType( colType )
					, ast::type::MemoryLayout::eStd430 );
				decorateMember( result
					, index
					, spv::DecorationColMajor );
				decorateMember( result
					, index
					, makeOperands( uint32_t( spv::DecorationMatrixStride ), size ) );
			}
		}

		return result;
	}

	spv::Id Module::registerBaseType( ast::type::TypePtr type
		, uint32_t mbrIndex
		, spv::Id parentId
		, uint32_t arrayStride )
	{
		spv::Id result{};

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
		auto id = getIntermediateResult();
		extensions.push_back( makeInstruction< ExtInstImportInstruction >( id
			, "GLSL.std.450" ) );
		debug.push_back( makeInstruction< SourceInstruction >( spv::Id( spv::SourceLanguageGLSL ), 460u ) );
	}

	void Module::initialiseCapacities()
	{
		switch ( m_model )
		{
		case spv::ExecutionModelVertex:
		case spv::ExecutionModelFragment:
		case spv::ExecutionModelGLCompute:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			break;
		case spv::ExecutionModelTessellationControl:
		case spv::ExecutionModelTessellationEvaluation:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityTessellation ) ) );
			break;
		case spv::ExecutionModelGeometry:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityShader ) ) );
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityGeometry ) ) );
			break;
		case spv::ExecutionModelKernel:
			capabilities.push_back( makeInstruction< CapabilityInstruction >( spv::Id( spv::CapabilityKernel ) ) );
			break;
		default:
			assert( false && "Unsupported ExecutionModel" );
			break;
		}
	}

	void Module::addDebug( std::string const & name
		, ast::type::TypePtr type
		, spv::Id id )
	{
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
		, spv::Id id )
	{
		auto builtin = getBuiltin( name );

		if ( builtin != spv::BuiltIn( -1 ) )
		{
			decorate( id, { spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) } );
		}
	}

	void Module::addVariable( std::string const & name
		, spv::StorageClass storage
		, ast::type::TypePtr type
		, spv::Id id
		, std::map< std::string, spv::Id >::iterator & it )
	{
		auto rawTypeId = registerType( type );

		if ( storage == spv::StorageClassPushConstant )
		{
			decorate( rawTypeId, spv::DecorationBlock );
		}

		auto varTypeId = registerPointerType( rawTypeId, storage );

		if ( storage == spv::StorageClassFunction
			&& m_currentFunction )
		{
			it = m_currentScopeVariables->emplace( name, id ).first;
			m_currentFunction->variables.push_back( makeInstruction< VariableInstruction >( varTypeId
				, id
				, spv::Id( storage ) ) );
		}
		else
		{
			it = m_registeredVariables.emplace( name, id ).first;
			globalDeclarations.push_back( makeInstruction< VariableInstruction >( varTypeId
				, id
				, spv::Id( storage ) ) );
		}

		m_registeredVariablesTypes.emplace( id, rawTypeId );
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
		}

		return list;
	}

	void Module::deserializeInfos( spv::Op opCode
		, InstructionList::iterator & current
		, InstructionList::iterator end )
	{
		switch ( opCode )
		{
		case spv::OpMemoryModel:
			memoryModel = std::move( *current );
			++current;
			break;
		case spv::OpEntryPoint:
			entryPoint = std::move( *current );
			++current;
			break;
		}
	}

	void Module::deserializeFuncs( spv::Op opCode
		, InstructionList::iterator & current
		, InstructionList::iterator end )
	{
		switch ( opCode )
		{
		case spv::OpFunction:
			functions.emplace_back( Function::deserialize( current, end ) );
			break;
		}
	}

	//*************************************************************************
}
