/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/StmtSpecialiser.hpp"

#include "ShaderAST/Visitors/ExprSpecialiser.hpp"

#include <algorithm>

namespace ast
{
	stmt::ContainerPtr StmtSpecialiser::submit( type::TypesCache & cache
		, stmt::Container * container
		, SpecialisationInfo const & specialisation )
	{
		auto result = stmt::makeContainer();
		StmtSpecialiser vis{ cache, specialisation, result };
		container->accept( &vis );
		return result;
	}

	StmtSpecialiser::StmtSpecialiser( type::TypesCache & cache
		, SpecialisationInfo const & specialisation
		, stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_cache{ cache }
		, m_specialisation{ specialisation }
	{
	}

	expr::ExprPtr StmtSpecialiser::doSubmit( expr::Expr * expr )
	{
		return ExprSpecialiser::submit( m_cache, expr, m_specialisations );
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
				, expr::makeLiteral( m_cache
					, *reinterpret_cast< bool const * >( it->data.data() ) ) );
			break;
		case type::Kind::eInt:
			assert( it->data.size() == sizeof( int32_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, expr::makeLiteral( m_cache
					, *reinterpret_cast< int32_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eUInt:
			assert( it->data.size() == sizeof( uint32_t ) );
			m_specialisations.emplace( stmt->getVariable()
				, expr::makeLiteral( m_cache
					, *reinterpret_cast< uint32_t const * >( it->data.data() ) ) );
			break;
		case type::Kind::eFloat:
			assert( it->data.size() == sizeof( float ) );
			m_specialisations.emplace( stmt->getVariable()
				, expr::makeLiteral( m_cache
					, *reinterpret_cast< float const * >( it->data.data() ) ) );
			break;
		case type::Kind::eDouble:
			assert( it->data.size() == sizeof( double ) );
			m_specialisations.emplace( stmt->getVariable()
				, expr::makeLiteral( m_cache
					, *reinterpret_cast< double const * >( it->data.data() ) ) );
			break;
		default:
			AST_Failure( "Specialisation can only be scalar type." );
			break;
		}

	}
}
