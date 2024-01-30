/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVModule.hpp"

#include "SpirVMakeAccessChain.hpp"
#include "SpirVDebugHelpers.hpp"
#include "SpirVHelpers.hpp"
#include "SpirVSerialize.hpp"
#include "SpirVWrite.hpp"

#include "spirv/NonSemantic.Shader.DebugInfo.100.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#include <algorithm>

namespace spirv
{
	//*************************************************************************

	namespace spvmodule
	{
		static ast::Map< std::string, VariableInfo >::iterator addVariable( NamesCache & nameCache
			, TypeId const & varTypeId
			, DebugId const & varId
			, std::string name
			, ValueId initialiser
			, ast::Map< std::string, VariableInfo, std::less<> > & variables
			, InstructionList & instructions )
		{
			auto result = variables.try_emplace( std::move( name ) ).first;
			result->second.id = varId;
			result->second.isParam = false;
			result->second.isAlias = false;
			instructions.push_back( makeVariableInstruction( nameCache
				, varTypeId.id
				, varId.id
				, initialiser ) );
			return result;
		}

		template< typename LitT >
		static DebugId registerLiteral( LitT value
			, ast::type::TypePtr valueType
			, Module & shaderModule
			, ast::Map< LitT, DebugId > & registeredLitConstants
			, ast::UnorderedMap< DebugId, ast::type::TypePtr, DebugIdHasher > & registeredConstants )
		{
			auto it = registeredLitConstants.find( value );

			if ( it == registeredLitConstants.end() )
			{
				auto type = shaderModule.getTypes().registerType( valueType, nullptr );
				DebugId result{ shaderModule.getNextId(), type->type };
				result.debug = result.id;
				shaderModule.constantsTypes.push_back( makeInstruction< ConstantInstruction >( shaderModule.getNameCache()
					, type.id
					, result.id
					, makeOperands( registeredConstants.get_allocator().getAllocator(), ValueId{ spv::Id( value ) } ) ) );
				it = registeredLitConstants.emplace( value, result ).first;
				registeredConstants.try_emplace( result, valueType );
			}

			return it->second;
		}
	}

	//*************************************************************************

	Module::Module( ast::ShaderAllocatorBlock * alloc
		, SpirVConfig const * spirvConfig
		, glsl::StmtConfig const * stmtConfig
		, ast::type::TypesCache * typesCache )
		: allocator{ alloc }
		, header{ allocator }
		, capabilities{ allocator }
		, extensions{ allocator }
		, imports{ allocator }
		, executionModes{ allocator }
		, decorations{ allocator }
		, constantsTypes{ allocator }
		, globalDeclarations{ allocator }
		, structData{ allocator }
		, functions{ ast::StlAllocatorT< spirv::Function >{ allocator } }
		, variables{ &globalDeclarations }
		, m_registeredVariables{ allocator }
		, m_currentScopeVariables{ &m_registeredVariables }
		, m_registeredVariablesTypes{ allocator }
		, m_registeredMemberVariables{ allocator }
		, m_registeredExecutionModes{ allocator }
		, m_pendingExecutionModes{ allocator }
		, m_entryPointIO{ allocator }
		, varDecorations{ allocator }
		, mbrDecorations{ allocator }
		, m_debugNames{ allocator, spirvConfig }
		, m_nonSemanticDebug{ allocator, *this, stmtConfig }
		, m_types{ allocator, *this, typesCache, constantsTypes }
		, m_literals{ allocator, *this, constantsTypes }
	{
	}

	Module::Module( ast::ShaderAllocatorBlock * alloc
		, ast::type::TypesCache & typesCache
		, SpirVConfig const & spirvConfig
		, glsl::StmtConfig const & stmtConfig
		, spv::AddressingModel addressingModel
		, spv::MemoryModel pmemoryModel
		, spv::ExecutionModel pexecutionModel
		, glsl::Statements const & debugStatements )
		: Module{ alloc, &spirvConfig , &stmtConfig, &typesCache }
	{
		memoryModel = makeInstruction< MemoryModelInstruction >( getNameCache()
			, ValueId{ spv::Id( addressingModel ) }
			, ValueId{ spv::Id( pmemoryModel ) } );
		m_version = spirvConfig.specVersion;
		m_model = pexecutionModel;

		doInitialiseHeader( Header{ spv::MagicNumber
			, m_version
			, ( VendorID << 16 ) | Version
			, 1u	/* Bound IDs. */
			, 0u	/* Schema. */ } );
		doInitialiseExtensions( spirvConfig.debugLevel == DebugLevel::eDebugInfo, debugStatements );
		doInitialiseCapacities();
	}

	Module::Module( ast::ShaderAllocatorBlock * alloc
		, ast::type::TypesCache & typesCache
		, NameCache & names
		, Header const & pheader
		, InstructionList instructions )
		: Module{ alloc, nullptr, nullptr, &typesCache }
	{
		doInitialiseHeader( pheader );
		auto it = instructions.begin();

		while ( it != instructions.end() )
		{
			auto opCode = spv::Op( ( *it )->op.getOpData().opCode );
			auto & instruction = *it;

			switch ( opCode )
			{
			case spv::OpExtInstImport:
				names.add( *instruction->resultId, *instruction->name );

				if ( instruction->name == "GLSL.std.450" )
				{
					this->extGlslStd450.id = *instruction->resultId;
				}
				else if ( instruction->name == "NonSemantic.Shader.DebugInfo.100" )
				{
					m_nonSemanticDebug.setExtID( *instruction->resultId );
				}

				extensions.push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpMemoryModel:
				memoryModel = std::move( instruction );
				++it;
				break;
			case spv::OpEntryPoint:
				entryPoint = std::move( instruction );
				++it;
				break;
			case spv::OpString:
				names.add( *instruction->resultId, *instruction->name );
				m_debugNames.getStringsDeclarations().push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpSource:
			case spv::OpSourceExtension:
				m_debugNames.getNamesDeclarations().push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpName:
				names.add( *instruction->resultId, *instruction->name );
				m_debugNames.getNamesDeclarations().push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpMemberName:
				names.addMember( *instruction->returnTypeId, *instruction->resultId, *instruction->name );
				m_debugNames.getNamesDeclarations().push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpExtension:
				extensions.push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpExtInst:
				m_nonSemanticDebug.getDeclarations().push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpCapability:
				capabilities.push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpExecutionMode:
				executionModes.push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpDecorate:
			case spv::OpMemberDecorate:
				decorations.push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpVariable:
				globalDeclarations.push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpFunction:
				functions.emplace_back( Function::deserialize( allocator, it, instructions.end() ) );
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
				m_types.deserialize( opCode, *instruction, names );
				constantsTypes.push_back( std::move( instruction ) );
				++it;
				break;
			case spv::OpConstant:
			case spv::OpConstantComposite:
			case spv::OpConstantFalse:
			case spv::OpConstantTrue:
			case spv::OpSpecConstant:
			case spv::OpSpecConstantComposite:
			case spv::OpSpecConstantFalse:
			case spv::OpSpecConstantTrue:
				m_literals.deserialize( opCode, *instruction );
				constantsTypes.push_back( std::move( instruction ) );
				++it;
				break;
			default:
				++it;
				break;
			}
		}
	}

	Module Module::deserialize( ast::ShaderAllocatorBlock * allocator
		, ast::type::TypesCache & typesCache
		, NameCache & names
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

		return Module{ allocator, typesCache, names, header, std::move( instructions ) };
	}

	std::string spirv::Module::write( spirv::Module const & shaderModule
		, NameCache & names
		, bool writeHeader )
	{
		return spirv::write( shaderModule, names, writeHeader );
	}

	UInt32List spirv::Module::serialize( spirv::Module const & shaderModule )
	{
		return spirv::serialize( shaderModule );
	}

	TypeId Module::registerType( ast::type::TypePtr type
		, glsl::Statement const * debugStatement )
	{
		return m_types.registerType( std::move( type ), debugStatement );
	}

	TypeId Module::registerImageType( ast::type::ImagePtr image
		, bool isComparison )
	{
		return m_types.registerImageType( std::move( image ), isComparison );
	}

	TypeId Module::registerPointerType( TypeId type
		, spv::StorageClass storage
		, bool isForward )
	{
		return m_types.registerPointerType( std::move( type ), storage, isForward );
	}

	DebugId Module::mergeSamplerImage( DebugId const & image
		, DebugId const & sampler
		, Block & currentBlock )
	{
		return m_types.mergeSamplerImage( image, sampler, currentBlock );
	}

	void Module::decorate( DebugId const & id, spv::Decoration decoration )
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

	void Module::decorate( DebugId const & id
		, IdList const & pdecorations )
	{
		auto it = varDecorations.try_emplace( id, allocator ).first;
		auto decos = convert( pdecorations );
		auto [dit, res] = it->second.try_emplace( decos );

		if ( res )
		{
			dit->second = decorations.size();
			decorations.push_back( makeInstruction< DecorateInstruction >( getNameCache()
				, makeOperands( allocator, id.id, decos ) ) );
		}
	}

	void Module::decorateMember( DebugId const & id
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

	void Module::decorateMember( DebugId const & id
		, uint32_t index
		, IdList const & pdecorations )
	{
		auto it = mbrDecorations.try_emplace( makeOperands( allocator, id, ValueId{ index } ), allocator ).first;
		auto decos = convert( pdecorations );
		auto [dit, res] = it->second.try_emplace( decos, 0u );

		if ( res )
		{
			dit->second = decorations.size();
			decorations.push_back( makeInstruction< MemberDecorateInstruction >( getNameCache()
				, makeOperands( allocator, id, index, decos ) ) );
		}
	}

	DebugId Module::getVariablePointer( Block & block
		, DebugId varId
		, std::string name
		, spv::StorageClass storage
		, Block & currentBlock
		, glsl::Statement const * statement
		, glsl::RangeInfo const & columns )
	{
		if ( varId.isPointer() && convert( varId.getStorage() ) != storage )
		{
			varId = loadVariable( varId, currentBlock, statement, columns );
			name = "SDW_Swap_" + name;
		}

		if ( !varId.isPointer() )
		{
			DebugId id{ getNextId()
				, getTypesCache().getPointerType( varId->type, convert( storage ) ) };
			doAddDebug( name, id );
			ast::Map< std::string, VariableInfo >::iterator it;
			doAddVariable( block, name, id, it, DebugId{} );
			storeVariable( it->second.id, varId, currentBlock, statement, columns );
			varId = it->second.id;
		}

		return varId;
	}

	DebugId Module::getVariablePointer( Block & block
		, std::string const & name
		, spv::StorageClass storage
		, Block & currentBlock
		, glsl::Statement const * statement
		, glsl::RangeInfo const & columns )
	{
		DebugId varId;
		ast::Map< std::string, VariableInfo >::iterator it;

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
			varId = getVariablePointer( block
				, varId
				, name
				, storage
				, currentBlock
				, statement
				, columns );
		}

		return varId;
	}

	void Module::storePromoted( DebugId const & variable
		, VariableInfo const & sourceInfo
		, Block & currentBlock
		, glsl::Statement const * debugStatement
		, glsl::RangeInfo const & columns )
	{
		if ( sourceInfo.isParam )
		{
			storeVariable( variable
				, sourceInfo.id
				, m_currentFunction->promotedParams
				, debugStatement
				, columns );
		}
		else
		{
			storeVariable( variable
				, sourceInfo.id
				, currentBlock
				, debugStatement
				, columns );
		}
	}

	void Module::storeVariable( DebugId const & variable
		, DebugId const & value
		, Block & currentBlock
		, glsl::Statement const * debugStatement
		, glsl::RangeInfo const & columns )
	{
		currentBlock.storeVariable( variable, value, *this, m_types, debugStatement, columns, m_nonSemanticDebug );
	}

	DebugId Module::loadVariable( DebugId const & variableId
		, Block & currentBlock
		, glsl::Statement const * debugStatement
		, glsl::RangeInfo const & columns )
	{
		return currentBlock.loadVariable( variableId, *this, m_types, debugStatement, columns, m_nonSemanticDebug );
	}

	void Module::bindVariable( DebugId const & varId
		, uint32_t bindingPoint
		, uint32_t descriptorSet )
	{
		decorate( varId, makeIdList( allocator, spv::Id( spv::DecorationBinding ), bindingPoint ) );
		decorate( varId, makeIdList( allocator, spv::Id( spv::DecorationDescriptorSet ), descriptorSet ) );
	}

	void Module::bindBufferVariable( DebugId const & variableId
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
			decorate( typeId, structDecoration );
		}
	}

	DebugId Module::bindBufferVariable( std::string const & name
		, uint32_t bindingPoint
		, uint32_t descriptorSet
		, spv::Decoration structDecoration )
	{
		DebugId result{};

		if ( auto varIt = m_currentScopeVariables->find( name );
			varIt != m_currentScopeVariables->end() )
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
		auto typeId = m_types.registerType( type, nullptr );
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			auto rawTypeId = m_types.registerType( type, nullptr );

			if ( m_currentFunction )
			{
				it = m_currentScopeVariables->try_emplace( std::move( name )
					, typeId, false, true, isOutput ).first;
			}
			else
			{
				it = m_registeredVariables.try_emplace( std::move( name )
					, typeId, false, true, isOutput ).first;
			}

			m_registeredVariablesTypes.try_emplace( typeId, rawTypeId );
		}

		return it->second;
	}

	VariableInfo Module::registerAlias( std::string name
		, ast::type::TypePtr type
		, DebugId exprResultId )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			auto rawTypeId = m_types.registerType( type, nullptr );

			if ( m_currentFunction )
			{
				it = m_currentScopeVariables->try_emplace( std::move( name )
					, exprResultId, true, false, false ).first;
			}
			else
			{
				it = m_registeredVariables.try_emplace( std::move( name )
					, exprResultId, true, false, false ).first;
			}

			m_registeredVariablesTypes.try_emplace( exprResultId, rawTypeId );
		}

		return it->second;
	}

	VariableInfo Module::registerVariable( Block & block
		, std::string const & name
		, ast::Builtin builtin
		, spv::StorageClass storage
		, bool isAlias
		, bool isParam
		, bool isOutParam
		, ast::type::TypePtr type
		, VariableInfo & sourceInfo
		, DebugId const & initialiser
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
						auto typeId = m_types.registerType( type, debugStatement );
						decorate( typeId, spv::DecorationBlock );
						varType = getTypesCache().getPointerType( type, ast::type::Storage::ePhysicalStorageBuffer );
						varType = getTypesCache().getPointerType( varType, typeStorage );
						typeStorage = ast::type::Storage::ePhysicalStorageBuffer;
					}
				}
			}

			if ( !varType )
			{
				varType = getTypesCache().getPointerType( type, convert( storage ) );
			}

			DebugId id{ getNextId(), varType };
			id.debug = ValueId{ m_nonSemanticDebug.getNextId(), id->type };

			if ( typeStorage == ast::type::Storage::ePhysicalStorageBuffer )
			{
				decorate( id, spv::DecorationAliasedPointer );
			}

			doAddDebug( name, id );

			if ( builtin != ast::Builtin::eNone )
			{
				doAddBuiltin( builtin, id );
			}

			doAddVariable( block, name, id, it, initialiser, debugStatement );
			sourceInfo = it->second;

			if ( m_version >= v1_4
				&& storage != spv::StorageClassFunction )
			{
				m_entryPointIO.insert( id.id );
			}
		}
		else
		{
			sourceInfo = it->second;

			if ( ( it->second.isParam && !isParam && ( !isPointerParam( type, isOutParam ) ) )
				|| ( it->second.isAlias && !isAlias ) )
			{
				DebugId id{ getNextId()
					, getTypesCache().getPointerType( ( it->second.id.isPointer()
							? static_cast< ast::type::Pointer const & >( *it->second->id.type ).getPointerType()
							: it->second->id.type )
						, convert( storage ) ) };
				id.debug = ValueId{ m_nonSemanticDebug.getNextId(), id->type };
				it->second.isAlias = false;
				it->second.isParam = false;
				it->second.isOutParam = false;
				doAddDebug( "ptr_" + name, id );
				doAddVariable( block, name, id, it, DebugId{}, debugStatement );
				m_nonSemanticDebug.declarePointerParam( m_currentFunction->promotedParams.instructions, "ptr_" + name, type, id, initialiser, debugStatement );

				if ( m_version >= v1_4
					&& storage != spv::StorageClassFunction )
				{
					m_entryPointIO.insert( id.id );
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

	DebugId Module::registerSpecConstant( std::string name
		, uint32_t location
		, ast::type::TypePtr type
		, ast::expr::Literal const & value )
	{
		auto it = m_currentScopeVariables->find( name );

		if ( it == m_currentScopeVariables->end() )
		{
			DebugId id{ getNextId() };
			it = m_currentScopeVariables->emplace( name, id ).first;
			auto rawTypeId = m_types.registerType( type, nullptr );
			IdList operands{ allocator };
			m_debugNames.registerName( id, name );

			if ( value.getLiteralType() == ast::expr::LiteralType::eBool )
			{
				if ( value.getValue< ast::expr::LiteralType::eBool >() )
				{
					constantsTypes.emplace_back( makeInstruction< SpecConstantTrueInstruction >( getNameCache()
						, rawTypeId.id
						, id.id ) );
				}
				else
				{
					constantsTypes.emplace_back( makeInstruction< SpecConstantFalseInstruction >( getNameCache()
						, rawTypeId.id
						, id.id ) );
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
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eInt64 >() & 0X00000000FFFFFFFFULL ) );
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
					operands.emplace_back( uint32_t( value.getValue< ast::expr::LiteralType::eUInt64 >() & 0X00000000FFFFFFFFULL ) );
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

				constantsTypes.emplace_back( makeInstruction< SpecConstantInstruction >( getNameCache()
					, rawTypeId.id
					, id.id
					, operands ) );
			}

			decorate( id, makeIdList( allocator, spv::Id( spv::DecorationSpecId ), location ) );
			m_registeredVariablesTypes.try_emplace( id, rawTypeId );
			m_literals.registerConstant( id, value.getType() );
		}

		return it->second.id;
	}

	ValueId Module::registerParameter( ast::type::TypePtr type )
	{
		m_types.registerType( type, nullptr );
		return ValueId{ getNextId() };
	}

	DebugId Module::registerMemberVariableIndex( ast::type::TypePtr type )
	{
		assert( type->isMember() );
		return registerLiteral( type->getIndex() );
	}

	DebugId Module::registerMemberVariable( DebugId outer
		, std::string const & name
		, ast::type::TypePtr type )
	{
		auto it = std::find_if( m_currentScopeVariables->begin()
			, m_currentScopeVariables->end()
			, [&outer]( ast::Map< std::string, VariableInfo >::value_type const & pair )
			{
				return pair.second.id == outer;
			} );
		assert( it != m_currentScopeVariables->end() );
		assert( type->isMember() );
		auto fullName = it->first + "::" + name;
		it = m_currentScopeVariables->find( fullName );

		if ( it == m_currentScopeVariables->end() )
		{
			DebugId id{ getNextId()
				, getTypesCache().getPointerType( type, outer.getStorage() ) };
			m_registeredMemberVariables.try_emplace( fullName, outer, id );
			it = m_currentScopeVariables->try_emplace( fullName, id, false, false, false ).first;
			registerLiteral( type->getIndex() );
		}

		return it->second.id;
	}

	void Module::registerExtension( std::string name )
	{
		extensions.push_back( makeInstruction< ExtensionInstruction >( getNameCache()
			, std::move( name ) ) );
	}

	void Module::registerEntryPoint( DebugId functionId
		, std::string name
		, ValueIdList const & inputs
		, ValueIdList const & outputs )
	{
		ValueIdSet ios{ allocator };
		ValueIdList operands{ allocator };

		for ( auto const & id : inputs )
		{
			ios.insert( id );
		}

		for ( auto const & id : outputs )
		{
			ios.insert( id );
		}

		for ( auto const & id : m_entryPointIO )
		{
			ios.insert( id );
		}

		operands.insert( operands.end(), ios.begin(), ios.end() );
		entryPoint = makeInstruction< EntryPointInstruction >( getNameCache()
			, ValueId{ spv::Id( m_model ) }
			, functionId.id
			, operands
			, std::move( name ) );
		m_nonSemanticDebug.makeEntryPointInstruction( functionId );

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
			executionModes.back()->operands[0] = functionId->id;
		}

		m_pendingExecutionModes.clear();
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode )
	{
		registerExecutionMode( mode, ValueIdList{ allocator } );
	}

	void Module::registerExecutionMode( spv::ExecutionMode mode, ValueIdList const & operands )
	{
		if ( m_registeredExecutionModes.emplace( mode ).second )
		{
			if ( !entryPoint || entryPoint->operands.empty() )
			{
				m_pendingExecutionModes.push_back( makeInstruction< ExecutionModeInstruction >( getNameCache()
					, makeOperands( allocator, 0u, spv::Id( mode ), operands ) ) );
			}
			else
			{
				executionModes.push_back( makeInstruction< ExecutionModeInstruction >( getNameCache()
					, makeOperands( allocator, entryPoint->resultId.value(), spv::Id( mode ), operands ) ) );
			}
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

	void Module::registerExecutionMode( ast::type::PatchDomain
		, ast::type::Partitioning
		, ast::type::OutputTopology
		, ast::type::PrimitiveOrdering
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

	ValueId Module::registerString( std::string text )
	{
		ValueId result{ getNextId() };
		m_debugNames.registerString( result, std::move( text ) );
		return result;
	}

	spv::Id Module::getIntermediateResult()
	{
		return getNextId();
	}

	Function * Module::beginFunction( std::string name
		, TypeId retType
		, ast::var::VariableList const & params
		, glsl::Statement const * declDebugStatement
		, glsl::Statement const * scopeBeginDebugStatement
		, glsl::Statement const * firstLineStatement )
	{
		DebugId result{ getNextId() };
		result.debug = ValueId{ m_nonSemanticDebug.getNextId(), result->type };
		auto & variableInfo = m_registeredVariables.try_emplace( name, result, false, false, false ).first->second;

		TypeIdList funcTypes{ allocator };
		funcTypes.push_back( retType );
		m_currentFunction = &functions.emplace_back( allocator, variableInfo.id );
		m_currentFunction->registeredVariables = m_registeredVariables; // the function has access to global scope variables.
		m_currentScopeVariables = &m_currentFunction->registeredVariables;
		DebugIdList funcParams{ allocator };

		for ( auto & param : params )
		{
			auto type = param->getType();
			auto kind = type->getKind();
			funcTypes.push_back( m_types.registerType( type, nullptr ) );

			if ( isPointerParam( *param ) )
			{
				auto storage = ( isOpaqueType( kind )
					? spv::StorageClassUniformConstant
					: spv::StorageClassFunction );
				funcTypes.back() = m_types.registerPointerType( funcTypes.back(), storage );
			}

			DebugId paramId{ getNextId(), funcTypes.back()->type };
			paramId.debug = ValueId{ m_nonSemanticDebug.getNextId(), paramId->type };
			funcParams.push_back( paramId );
			m_debugNames.registerName( paramId, param->getName() );

			m_currentScopeVariables->try_emplace( param->getName(), funcParams.back(), false, true, param->isOutputParam() );
			m_registeredVariablesTypes.try_emplace( funcParams.back(), funcTypes.back() );
		}

		auto funcTypeId = m_types.registerFunctionType( funcTypes );
		m_currentFunction->debugTypeId = funcTypeId.debug;
		DebugId scopeLineId{};
		m_nonSemanticDebug.declareFunction( *m_currentFunction
			, name
			, params
			, funcParams
			, declDebugStatement
			, scopeBeginDebugStatement
			, firstLineStatement );

		m_currentFunction->declaration.emplace_back( makeInstruction< FunctionInstruction >( getNameCache()
			, retType.id
			, m_currentFunction->id.id
			, ValueId{ spv::Id( spv::FunctionControlMaskNone ) }
			, funcTypeId.id ) );
		auto itType = funcTypes.begin() + 1u;
		auto itParam = funcParams.begin();

		for ( auto itp = params.begin(); itp != params.end(); ++itp )
		{
			m_currentFunction->declaration.emplace_back( makeInstruction< FunctionParameterInstruction >( getNameCache()
				, itType->id
				, itParam->id ) );
			++itType;
			++itParam;
		}

		m_registeredVariablesTypes.try_emplace( m_currentFunction->id, funcTypeId );
		m_debugNames.registerName( m_currentFunction->id, std::move( name ) );
		variables = &m_currentFunction->variables;

		return m_currentFunction;
	}

	Block Module::newBlock()
	{
		Block result{ allocator, getNextId() };
		result.instructions.push_back( makeInstruction< LabelInstruction >( getNameCache()
			, ValueId{ result.label } ) );
		return result;
	}

	void Module::endFunction()
	{
		if ( m_currentFunction
			&& !m_currentFunction->cfg.blocks.empty() )
		{
			if ( !m_currentFunction->variables.empty() )
			{
				auto & instructions = m_currentFunction->cfg.blocks.begin()->instructions;
				{
					auto params = std::move( m_currentFunction->promotedParams.instructions );
					std::reverse( params.begin(), params.end() );

					for ( auto & param : params )
					{
						instructions.emplace( instructions.begin() + 1u
							, std::move( param ) );
					}

					m_currentFunction->promotedParams.instructions.clear();
				}
				{
					auto debugStart = std::move( m_currentFunction->debugStart );
					std::reverse( debugStart.begin(), debugStart.end() );

					for ( auto & dbg : debugStart )
					{
						instructions.emplace( instructions.begin() + 1u
							, std::move( dbg ) );
					}

					m_currentFunction->debugStart.clear();
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
			else
			{
				auto & instructions = m_currentFunction->cfg.blocks.begin()->instructions;
				auto debugStart = std::move( m_currentFunction->debugStart );
				std::reverse( debugStart.begin(), debugStart.end() );

				for ( auto & dbg : debugStart )
				{
					instructions.emplace( instructions.begin() + 1u
						, std::move( dbg ) );
				}

				m_currentFunction->debugStart.clear();
			}
		}

		variables = &globalDeclarations;
		m_currentScopeVariables = &m_registeredVariables;
		m_currentFunction = nullptr;
	}

	spv::Id Module::getNextId()
	{
		auto result = *m_currentId;
		++*m_currentId;
		return result;
	}

	bool Module::isExtGlslStd450( spv::Id id )const
	{
		return id == extGlslStd450.id;
	}

	bool Module::isExtNonSemanticDebugInfo( spv::Id id )const
	{
		return m_nonSemanticDebug.isExtNonSemanticDebugInfo( id );
	}

	InstructionList const & Module::getDebugStringsDeclarations()const noexcept
	{
		return m_debugNames.getStringsDeclarations();
	}

	InstructionList const & Module::getDebugNamesDeclarations()const noexcept
	{
		return m_debugNames.getNamesDeclarations();
	}

	InstructionList const & Module::getNonSemanticDebugDeclarations()const noexcept
	{
		return m_nonSemanticDebug.getDeclarations();
	}

	NamesCache & Module::getNameCache()noexcept
	{
		return m_debugNames.getNameCache();
	}

	ast::type::TypesCache & Module::getTypesCache()const noexcept
	{
		return m_types.getTypesCache();
	}

	void Module::declareDebugAccessChain( InstructionList & instructions
		, ast::expr::Expr const & expr
		, glsl::Statement const * debugStatement
		, DebugId & resultId )
	{
		m_nonSemanticDebug.declareAccessChain( instructions
			, expr
			, debugStatement
			, resultId );
	}

	ast::type::TypePtr Module::getType( DebugId const & typeId )const
	{
		return m_types.getType( typeId );
	}

	void Module::doReplaceDecoration( DebugId const & id
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
				varIt->second.try_emplace( list, idx );
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

	void Module::doReplaceMemberDecoration( DebugId const & id
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
				mbrIt->second.try_emplace( list, idx );
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

	void Module::doInitialiseExtensions( bool enableDebug
		, glsl::Statements const & debugStatements )
	{
		extGlslStd450 = ValueId{ getIntermediateResult() };
		imports.push_back( makeInstruction< ExtInstImportInstruction >( getNameCache()
			, extGlslStd450
			, "GLSL.std.450" ) );

		if ( enableDebug )
		{
			m_nonSemanticDebug.initialise( imports, debugStatements );
		}
		else
		{
			m_debugNames.registerSource( spv::SourceLanguageGLSL, 460 );
		}
	}

	void Module::doInitialiseCapacities()
	{
		switch ( m_model )
		{
		case spv::ExecutionModelVertex:
		case spv::ExecutionModelFragment:
		case spv::ExecutionModelGLCompute:
			insertCapability( getNameCache(), capabilities, spv::CapabilityShader );
			break;
		case spv::ExecutionModelTessellationControl:
		case spv::ExecutionModelTessellationEvaluation:
			insertCapability( getNameCache(), capabilities, spv::CapabilityShader );
			insertCapability( getNameCache(), capabilities, spv::CapabilityTessellation );
			break;
		case spv::ExecutionModelGeometry:
			insertCapability( getNameCache(), capabilities, spv::CapabilityShader );
			insertCapability( getNameCache(), capabilities, spv::CapabilityGeometry );
			break;
		case spv::ExecutionModelTaskNV:
		case spv::ExecutionModelMeshNV:
			insertCapability( getNameCache(), capabilities, spv::CapabilityShader );
			insertCapability( getNameCache(), capabilities, spv::CapabilityMeshShadingNV );
			break;
		case spv::ExecutionModelTaskEXT:
		case spv::ExecutionModelMeshEXT:
			insertCapability( getNameCache(), capabilities, spv::CapabilityShader );
			insertCapability( getNameCache(), capabilities, spv::CapabilityMeshShadingEXT );
			break;
		case spv::ExecutionModelAnyHitKHR:
		case spv::ExecutionModelCallableKHR:
		case spv::ExecutionModelClosestHitKHR:
		case spv::ExecutionModelIntersectionKHR:
		case spv::ExecutionModelMissKHR:
		case spv::ExecutionModelRayGenerationKHR:
			insertCapability( getNameCache(), capabilities, spv::CapabilityShader );
			insertCapability( getNameCache(), capabilities, spv::CapabilityRayTracingKHR );
			break;
		case spv::ExecutionModelKernel:
			insertCapability( getNameCache(), capabilities, spv::CapabilityKernel );
			break;
		default:
			AST_Failure( "Unsupported ExecutionModel" );
			break;
		}
	}

	void Module::doAddDebug( std::string const & name
		, DebugId const & id )
	{
		auto type = unwrapType( id->type );

		if ( ( type->getKind() != ast::type::Kind::eStruct
				&& type->getKind() != ast::type::Kind::eRayDesc )
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() != name )
		{
			m_debugNames.registerName( id, name );
		}
		else if ( type->getKind() == ast::type::Kind::eStruct
			|| type->getKind() == ast::type::Kind::eRayDesc
			|| std::static_pointer_cast< ast::type::Struct >( type )->getName() == name )
		{
			m_debugNames.registerName( id, name + "Inst" );
		}
	}

	void Module::doAddBuiltin( ast::Builtin pbuiltin
		, DebugId const & id )
	{
		ast::Vector< spv::Decoration > additionalDecorations{ allocator };
		auto builtin = getBuiltin( pbuiltin, m_model, additionalDecorations );

		if ( builtin != spv::BuiltInMax )
		{
			decorate( id, makeIdList( allocator, spv::Id( spv::DecorationBuiltIn ), spv::Id( builtin ) ) );

			for ( auto const & decoration : additionalDecorations )
			{
				decorate( id, decoration );
			}
		}
	}

	void Module::doAddVariable( Block & block
		, std::string const & name
		, DebugId const & varId
		, ast::Map< std::string, VariableInfo >::iterator & it
		, DebugId const & initialiser
		, glsl::Statement const * debugStatement )
	{
		assert( varId.isPointer() );
		auto type = varId->type;
		auto rawType = static_cast< ast::type::Pointer const & >( *type ).getPointerType();
		auto rawTypeId = m_types.registerType( rawType, debugStatement );
		auto typeStorage = varId.getStorage();

		if ( typeStorage == ast::type::Storage::ePushConstant )
		{
			decorate( rawTypeId, spv::DecorationBlock );
		}

		auto varTypeId = m_types.registerPointerType( rawTypeId
			, convert( typeStorage ) );

		if ( varId.getStorage() == ast::type::Storage::eFunction
			&& m_currentFunction )
		{
			it = spvmodule::addVariable( getNameCache()
				, varTypeId
				, varId
				, name
				, initialiser.id
				, *m_currentScopeVariables
				, m_currentFunction->variables );
		}
		else
		{
			it = spvmodule::addVariable( getNameCache()
				, varTypeId
				, varId
				, name
				, initialiser.id
				, m_registeredVariables
				, globalDeclarations );

			if ( m_currentScopeVariables
				&& m_currentScopeVariables != &m_registeredVariables )
			{
				// Register globals to current scope too.
				m_currentScopeVariables->insert( *it );
			}
		}

		m_registeredVariablesTypes.try_emplace( varId, rawTypeId );
		m_nonSemanticDebug.declareVariable( block.instructions, name, type, varId, initialiser, debugStatement );
	}

	//*************************************************************************
}
