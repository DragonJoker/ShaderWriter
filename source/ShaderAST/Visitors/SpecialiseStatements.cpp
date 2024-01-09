/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/SpecialiseStatements.hpp"

#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"
#include "ShaderAST/Visitors/CloneStmt.hpp"

#include <algorithm>
#include <bit>
#include <map>

namespace ast
{
	namespace specialise
	{
		class ExprSpecialiser
			: public ExprCloner
		{
		public:
			static expr::ExprPtr submit( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::Expr const & expr
				, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
			{
				expr::ExprPtr result{};
				ExprSpecialiser vis{ exprCache, typesCache, specialisations, result };
				expr.accept( &vis );
				return result;
			}

		private:
			ExprSpecialiser( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations
				, expr::ExprPtr & result )
				: ExprCloner{ exprCache, result }
				, m_typesCache{ typesCache }
				, m_specialisations{ specialisations }
			{
			}

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				expr::ExprPtr result{};
				ExprSpecialiser vis{ m_exprCache, m_typesCache, m_specialisations, result };
				expr.accept( &vis );

				if ( expr.isNonUniform() )
				{
					result->updateFlag( ast::expr::Flag::eNonUniform );
				}

				return result;
			}

			void visitIdentifierExpr( expr::Identifier const * expr )override
			{
				auto it = m_specialisations.find( expr->getVariable() );

				if ( it != m_specialisations.end() )
				{
					m_result = doSubmit( *it->second );
				}
				else
				{
					m_result = m_exprCache.makeIdentifier( m_typesCache, expr->getVariable() );
				}
			}

		private:
			type::TypesCache & m_typesCache;
			std::map< var::VariablePtr, expr::LiteralPtr > const & m_specialisations;
		};

		class StmtVisitor
			: public StmtCloner
		{
		public:
			static stmt::ContainerPtr submit( stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::Container const & container
				, SpecialisationInfo const & specialisation )
			{
				auto result = stmtCache.makeContainer();
				StmtVisitor vis{ stmtCache, exprCache, typesCache, specialisation, result };
				container.accept( &vis );
				return result;
			}

			StmtVisitor( stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, SpecialisationInfo const & specialisation
				, stmt::ContainerPtr & result )
				: StmtCloner{ stmtCache, exprCache, result }
				, m_typesCache{ typesCache }
				, m_specialisation{ specialisation }
			{
			}

			using StmtCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				return ExprSpecialiser::submit( m_exprCache, m_typesCache, expr, m_specialisations );
			}

			void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl const * stmt )override
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
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< bool const * >( it->data.data() ) ) );
					break;
				case type::Kind::eInt8:
					assert( it->data.size() == sizeof( int8_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< int8_t const * >( it->data.data() ) ) );
					break;
				case type::Kind::eInt16:
					assert( it->data.size() == sizeof( int16_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< int16_t const * >( it->data.data() ) ) );
					break;
				case type::Kind::eInt32:
					assert( it->data.size() == sizeof( int32_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< int32_t const * >( it->data.data() ) ) );
					break;
				case type::Kind::eInt64:
					assert( it->data.size() == sizeof( int64_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< int64_t const * >( it->data.data() ) ) );
					break;
				case type::Kind::eUInt8:
					assert( it->data.size() == sizeof( uint8_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *it->data.data() ) );
					break;
				case type::Kind::eUInt16:
					assert( it->data.size() == sizeof( uint16_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< uint16_t const * >( it->data.data() ) ) );
					break;
				case type::Kind::eUInt32:
					assert( it->data.size() == sizeof( uint32_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< uint32_t const * >( it->data.data() ) ) );
					break;
				case type::Kind::eUInt64:
					assert( it->data.size() == sizeof( uint64_t ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< uint64_t const * >( it->data.data() ) ) );
					break;
				case type::Kind::eFloat:
					assert( it->data.size() == sizeof( float ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< float const * >( it->data.data() ) ) );
					break;
				case type::Kind::eDouble:
					assert( it->data.size() == sizeof( double ) );
					m_specialisations.try_emplace( stmt->getVariable()
						, m_exprCache.makeLiteral( m_typesCache
							, *reinterpret_cast< double const * >( it->data.data() ) ) );
					break;
				default:
					AST_Failure( "Specialisation can only be scalar type." );
					break;
				}
			}

		private:
			type::TypesCache & m_typesCache;
			SpecialisationInfo const & m_specialisation;
			std::map< var::VariablePtr, expr::LiteralPtr > m_specialisations;
		};
	}

	stmt::ContainerPtr specialiseStatements( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container const & container
		, SpecialisationInfo const & specialisation )
	{
		return specialise::StmtVisitor::submit( stmtCache
			, exprCache
			, typesCache
			, container
			, specialisation );
	}
}
