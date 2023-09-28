/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/StmtSpecialiser.hpp"

#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/ExprSpecialiser.hpp"

#include <algorithm>

namespace ast
{
	stmt::ContainerPtr StmtSpecialiser::submit( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container * container
		, SpecialisationInfo const & specialisation )
	{
		auto result = stmtCache.makeContainer();
		StmtSpecialiser vis{ stmtCache, exprCache, typesCache, specialisation, result };
		container->accept( &vis );
		return result;
	}

	StmtSpecialiser::StmtSpecialiser( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, SpecialisationInfo const & specialisation
		, stmt::ContainerPtr & result )
		: StmtCloner{ stmtCache, exprCache, result }
		, m_typesCache{ typesCache }
		, m_specialisation{ specialisation }
	{
	}

	expr::ExprPtr StmtSpecialiser::doSubmit( expr::Expr * expr )
	{
		return ExprSpecialiser::submit( m_exprCache, m_typesCache, expr, m_specialisations );
	}

	void StmtSpecialiser::visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )
	{
		auto it = std::find_if( m_specialisation.data.begin()
			, m_specialisation.data.end()
			, [stmt]( SpecConstantData const & lookup )
			{
				return lookup.info.location == stmt->getLocation();
			} );
		assert( it != m_specialisation.data.end() );
		assert( it->info.type == stmt->getVariable()->getType() );

		switch ( it->info.type->getKind() )
		{
		case type::Kind::eBoolean:
			assert( it->data.size() == sizeof( bool ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< bool const * >( it->data.data() ) ) );
			break;
		case type::Kind::eInt8:
			assert( it->data.size() == sizeof( int8_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< int8_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eInt16:
			assert( it->data.size() == sizeof( int16_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< int16_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eInt32:
			assert( it->data.size() == sizeof( int32_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< int32_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eInt64:
			assert( it->data.size() == sizeof( int64_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< int64_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eUInt8:
			assert( it->data.size() == sizeof( uint8_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< uint8_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eUInt16:
			assert( it->data.size() == sizeof( uint16_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< uint16_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eUInt32:
			assert( it->data.size() == sizeof( uint32_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< uint32_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eUInt64:
			assert( it->data.size() == sizeof( uint64_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< uint64_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eFloat:
			assert( it->data.size() == sizeof( float ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< float const * >( it->data.data() ) ) );
			break;
		case type::Kind::eDouble:
			assert( it->data.size() == sizeof( double ) );
			m_specialisations.emplace( stmt->getVariable()
				, m_exprCache.makeLiteral( m_typesCache
					, *reinterpret_cast< double const * >( it->data.data() ) ) );
			break;
		default:
			AST_Failure( "Specialisation can only be scalar type." );
			break;
		}

	}
}
