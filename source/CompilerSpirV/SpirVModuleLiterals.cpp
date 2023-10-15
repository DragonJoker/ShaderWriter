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
			, Module & module
			, ast::Map< LitT, DebugId > & registeredLitConstants
			, ast::UnorderedMap< DebugId, ast::type::TypePtr, DebugIdHasher > & registeredConstants )
		{
			auto it = registeredLitConstants.find( value );

			if ( it == registeredLitConstants.end() )
			{
				auto type = module.getTypes().registerType( valueType, nullptr );
				DebugId result{ module.getNextId(), type->type };
				result.debug = result.id;
				module.constantsTypes.push_back( makeInstruction< ConstantInstruction >( module.getNameCache()
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
		, Module & module
		, InstructionList & declarations )
		: m_module{ module }
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

	ast::type::Kind ModuleLiterals::getLiteralType( DebugId litId )const
	{
		auto it = m_registeredConstants.find( litId );
		if ( it != m_registeredConstants.end() )
		{
			return it->second->getKind();
		}

		return ast::type::Kind::eUndefined;
	}

	//*************************************************************************
}
