/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVModuleLiterals.hpp"

#include "CompilerSpirV/SpirVModule.hpp"

namespace spirv
{
	//*************************************************************************

	namespace modlit
	{
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
				registeredConstants.emplace( result, valueType );
			}

			return it->second;
		}
	}

	//*************************************************************************

	ModuleLiterals::ModuleLiterals( ast::ShaderAllocatorBlock * allocator
		, Module & shaderModule
		, InstructionList & declarations )
		: m_module{ shaderModule }
		, m_declarations{ declarations }
		, m_allocator{ allocator }
		, m_registeredBoolConstants{ m_allocator }
		, m_registeredInt8Constants{ m_allocator }
		, m_registeredInt16Constants{ m_allocator }
		, m_registeredInt32Constants{ m_allocator }
		, m_registeredInt64Constants{ m_allocator }
		, m_registeredUInt8Constants{ m_allocator }
		, m_registeredUInt16Constants{ m_allocator }
		, m_registeredUInt32Constants{ m_allocator }
		, m_registeredUInt64Constants{ m_allocator }
		, m_registeredFloatConstants{ m_allocator }
		, m_registeredDoubleConstants{ m_allocator }
		, m_registeredCompositeConstants{ m_allocator }
		, m_registeredConstants{ m_allocator }
	{
	}

	DebugId ModuleLiterals::registerLiteral( bool value )
	{
		auto it = m_registeredBoolConstants.find( value );

		if ( it == m_registeredBoolConstants.end() )
		{
			auto type = m_module.registerType( m_module.getTypesCache().getBool(), nullptr );
			DebugId result{ m_module.getNextId(), type->type };
			result.debug = result.id;

			if ( value )
			{
				m_declarations.push_back( makeInstruction< ConstantTrueInstruction >( m_module.getNameCache()
					, type.id
					, result.id ) );
			}
			else
			{
				m_declarations.push_back( makeInstruction< ConstantFalseInstruction >( m_module.getNameCache()
					, type.id
					, result.id ) );
			}

			it = m_registeredBoolConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_module.getTypesCache().getBool() );
		}

		return it->second;
	}

	DebugId ModuleLiterals::registerLiteral( int8_t value )
	{
		return modlit::registerLiteral( value
			, m_module.getTypesCache().getInt8()
			, m_module
			, m_registeredInt8Constants
			, m_registeredConstants );
	}

	DebugId ModuleLiterals::registerLiteral( int16_t value )
	{
		return modlit::registerLiteral( value
			, m_module.getTypesCache().getInt16()
			, m_module
			, m_registeredInt16Constants
			, m_registeredConstants );
	}

	DebugId ModuleLiterals::registerLiteral( int32_t value )
	{
		return modlit::registerLiteral( value
			, m_module.getTypesCache().getInt32()
			, m_module
			, m_registeredInt32Constants
			, m_registeredConstants );
	}

	DebugId ModuleLiterals::registerLiteral( uint8_t value )
	{
		return modlit::registerLiteral( value
			, m_module.getTypesCache().getUInt8()
			, m_module
			, m_registeredUInt8Constants
			, m_registeredConstants );
	}

	DebugId ModuleLiterals::registerLiteral( uint16_t value )
	{
		return modlit::registerLiteral( value
			, m_module.getTypesCache().getUInt16()
			, m_module
			, m_registeredUInt16Constants
			, m_registeredConstants );
	}

	DebugId ModuleLiterals::registerLiteral( uint32_t value )
	{
		return modlit::registerLiteral( value
			, m_module.getTypesCache().getUInt32()
			, m_module
			, m_registeredUInt32Constants
			, m_registeredConstants );
	}

	DebugId ModuleLiterals::registerLiteral( int64_t value )
	{
		auto it = m_registeredInt64Constants.find( value );

		if ( it == m_registeredInt64Constants.end() )
		{
			auto type = m_module.registerType( m_module.getTypesCache().getInt64(), nullptr );
			DebugId result{ m_module.getNextId(), type->type };
			result.debug = result.id;
			m_declarations.push_back( makeInstruction< ConstantInstruction >( m_module.getNameCache()
				, type.id
				, result.id
				, makeOperands( m_allocator
					, ValueId{ uint32_t( ( value >> 32 ) & 0x00000000FFFFFFFFll ) }
					, ValueId{ uint32_t( value & 0x00000000FFFFFFFFll ) } ) ) );
			it = m_registeredInt64Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_module.getTypesCache().getInt64() );
		}

		return it->second;
	}

	DebugId ModuleLiterals::registerLiteral( uint64_t value )
	{
		auto it = m_registeredUInt64Constants.find( value );

		if ( it == m_registeredUInt64Constants.end() )
		{
			auto type = m_module.registerType( m_module.getTypesCache().getUInt64(), nullptr );
			DebugId result{ m_module.getNextId(), type->type };
			result.debug = result.id;
			m_declarations.push_back( makeInstruction< ConstantInstruction >( m_module.getNameCache()
				, type.id
				, result.id
				, makeOperands( m_allocator
					, ValueId{ uint32_t( ( value >> 32 ) & 0x00000000FFFFFFFFull ) }
					, ValueId{ uint32_t( value & 0x00000000FFFFFFFFull ) } ) ) );
			it = m_registeredUInt64Constants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_module.getTypesCache().getUInt64() );
		}

		return it->second;
	}

	DebugId ModuleLiterals::registerLiteral( float value )
	{
		auto it = m_registeredFloatConstants.find( value );

		if ( it == m_registeredFloatConstants.end() )
		{
			auto type = m_module.registerType( m_module.getTypesCache().getFloat(), nullptr );
			DebugId result{ m_module.getNextId(), type->type };
			result.debug = result.id;
			IdList list{ m_allocator };
			list.resize( 1u );
			auto dst = reinterpret_cast< float * >( list.data() );
			*dst = value;
			m_declarations.push_back( makeInstruction< ConstantInstruction >( m_module.getNameCache()
				, type.id
				, result.id
				, convert( list ) ) );
			it = m_registeredFloatConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_module.getTypesCache().getFloat() );
		}

		return it->second;
	}

	DebugId ModuleLiterals::registerLiteral( double value )
	{
		auto it = m_registeredDoubleConstants.find( value );

		if ( it == m_registeredDoubleConstants.end() )
		{
			auto type = m_module.registerType( m_module.getTypesCache().getDouble(), nullptr );
			DebugId result{ m_module.getNextId(), type->type };
			result.debug = result.id;
			IdList list{ m_allocator };
			list.resize( 2u );
			auto dst = reinterpret_cast< double * >( list.data() );
			*dst = value;
			m_declarations.push_back( makeInstruction< ConstantInstruction >( m_module.getNameCache()
				, type.id
				, result.id
				, convert( list ) ) );
			it = m_registeredDoubleConstants.emplace( value, result ).first;
			m_registeredConstants.emplace( result, m_module.getTypesCache().getDouble() );
		}

		return it->second;
	}

	DebugId ModuleLiterals::registerLiteral( DebugIdList const & initialisers
		, ast::type::TypePtr type )
	{
		auto typeId = m_module.registerType( type, nullptr );
		auto it = std::find_if( m_registeredCompositeConstants.begin()
			, m_registeredCompositeConstants.end()
			, [&initialisers]( std::pair< DebugIdList, DebugId > const & lookup )
			{
				return lookup.first == initialisers;
			} );

		if ( it == m_registeredCompositeConstants.end() )
		{
			DebugId result{ m_module.getNextId(), typeId->type };
			result.debug = result.id;
			m_declarations.push_back( makeInstruction< ConstantCompositeInstruction >( m_module.getNameCache()
				, typeId.id
				, result.id
				, convert( initialisers ) ) );
			m_registeredCompositeConstants.emplace_back( initialisers, result );
			it = m_registeredCompositeConstants.begin() + ptrdiff_t( m_registeredCompositeConstants.size() - 1u );
			m_registeredConstants.emplace( result, type );
		}

		return it->second;
	}

	void ModuleLiterals::registerConstant( DebugId const & id
		, ast::type::TypePtr type )
	{
		m_registeredConstants.emplace( id, type );
	}

	void ModuleLiterals::deserialize( spv::Op opCode
		, Instruction const & instruction )
	{
		auto type = m_module.getType( DebugId{ ValueId{ *instruction.returnTypeId } } );

		if ( type == nullptr )
		{
			return;
		}

		DebugId debugId{ *instruction.resultId, type };

		switch ( opCode )
		{
		case spv::OpConstant:
		case spv::OpSpecConstant:
			switch ( type->getKind() )
			{
			case ast::type::Kind::eBoolean:
				m_registeredConstants.emplace( debugId, type );
				m_registeredBoolConstants.emplace( bool( instruction.operands[0] )
					, debugId );
				break;
			case ast::type::Kind::eInt8:
				m_registeredConstants.emplace( debugId, type );
				m_registeredInt8Constants.emplace( int8_t( instruction.operands[0] )
					, debugId );
				break;
			case ast::type::Kind::eInt16:
				m_registeredConstants.emplace( debugId, type );
				m_registeredInt16Constants.emplace( int16_t( instruction.operands[0] )
					, debugId );
				break;
			case ast::type::Kind::eInt32:
				m_registeredConstants.emplace( debugId, type );
				m_registeredInt32Constants.emplace( int32_t( instruction.operands[0] )
					, debugId );
				break;
			case ast::type::Kind::eInt64:
				m_registeredConstants.emplace( debugId, type );
				m_registeredInt64Constants.emplace( ( int64_t( instruction.operands[0] ) << 32 ) + int64_t( instruction.operands[1] )
					, debugId );
				break;
			case ast::type::Kind::eUInt8:
				m_registeredConstants.emplace( debugId, type );
				m_registeredUInt8Constants.emplace( uint8_t( instruction.operands[0] )
					, debugId );
				break;
			case ast::type::Kind::eUInt16:
				m_registeredConstants.emplace( debugId, type );
				m_registeredUInt16Constants.emplace( uint16_t( instruction.operands[0] )
					, debugId );
				break;
			case ast::type::Kind::eUInt32:
				m_registeredConstants.emplace( debugId, type );
				m_registeredUInt32Constants.emplace( uint32_t( instruction.operands[0] )
					, debugId );
				break;
			case ast::type::Kind::eUInt64:
				m_registeredConstants.emplace( debugId, type );
				m_registeredUInt64Constants.emplace( ( uint64_t( instruction.operands[0] ) << 32u ) + uint64_t( instruction.operands[1] )
					, debugId );
				break;
			case ast::type::Kind::eFloat:
#pragma GCC diagnostic push
#if defined( __clang__ )
#	pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
#else
#	pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
				m_registeredConstants.emplace( debugId, type );
				m_registeredFloatConstants.emplace( *reinterpret_cast< float const * >( instruction.operands.data() )
					, debugId );
#pragma GCC diagnostic pop
				break;
			case ast::type::Kind::eDouble:
#pragma GCC diagnostic push
#if defined( __clang__ )
#	pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
#else
#	pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
				assert( instruction.operands.size() >= 2 );
				m_registeredConstants.emplace( debugId, type );
				m_registeredDoubleConstants.emplace( *reinterpret_cast< double const * >( instruction.operands.data() )
					, debugId );
#pragma GCC diagnostic pop
				break;
			default:
				break;
			}
			break;
		case spv::OpConstantComposite:
		case spv::OpSpecConstantComposite:
			{
				DebugIdList initialisers{ m_allocator };

				for ( uint32_t i = 0u; i < uint32_t( instruction.operands.size() ); ++i )
				{
					auto paramTypeId = instruction.operands[i];
					auto cit = std::find_if( m_registeredConstants.begin()
						, m_registeredConstants.end()
						, [paramTypeId]( std::pair< DebugId const, ast::type::TypePtr > const & lookup )
						{
							return lookup.first.id.id == paramTypeId;
						} );
					if ( cit == m_registeredConstants.end() )
					{
						return;
					}

					initialisers.push_back( cit->first );
				}

				m_registeredConstants.emplace( debugId, type );
				m_registeredCompositeConstants.emplace_back( initialisers, debugId );
			}
			break;
		case spv::OpConstantFalse:
		case spv::OpSpecConstantFalse:
			m_registeredConstants.emplace( debugId, type );
			m_registeredBoolConstants.emplace( false
				, DebugId{ instruction.resultId.value(), type } );
			break;
		case spv::OpConstantTrue:
		case spv::OpSpecConstantTrue:
			m_registeredConstants.emplace( debugId, type );
			m_registeredBoolConstants.emplace( true
				, DebugId{ instruction.resultId.value(), type } );
			break;
		default:
			break;
		}
	}

	//*************************************************************************
}
