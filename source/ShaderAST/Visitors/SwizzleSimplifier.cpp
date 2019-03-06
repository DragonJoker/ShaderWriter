/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/SwizzleSimplifier.hpp"

#include "ShaderAST/Visitors/CloneExpr.hpp"

namespace ast
{
	namespace
	{
		std::vector< expr::SwizzleKind > getSwizzleValues( expr::SwizzleKind swizzle )
		{
			assert( !swizzle.isOneComponent()
				&& "Invalid swizzle for components listing" );
			std::vector< expr::SwizzleKind > result;
			result.push_back( swizzle.getFirstValue() );
			auto count = swizzle.getComponentsCount();

			if ( count >= 2u )
			{
				result.push_back( swizzle.getSecondValue() );
			}

			if ( count >= 3u )
			{
				result.push_back( swizzle.getThirdValue() );
			}

			if ( count >= 4u )
			{
				result.push_back( swizzle.getFourthValue() );
			}

			return result;
		}

		uint32_t getSwizzleIndex( expr::SwizzleKind swizzle )
		{
			assert( swizzle.isOneComponent()
				&& "Invalid swizzle for components indexing" );

			return swizzle == expr::SwizzleKind::e0
				? 0u
				: ( swizzle == expr::SwizzleKind::e1
					? 1u
					: ( swizzle == expr::SwizzleKind::e2
						? 2u
						: 3u ) );
		}

		std::vector< uint32_t > getSwizzleIndices( expr::SwizzleKind swizzle )
		{
			std::vector< uint32_t > result;
			result.push_back( getSwizzleIndex( swizzle.getFirstValue() ) );
			auto count = swizzle.getComponentsCount();

			if ( count >= 2u )
			{
				result.push_back( getSwizzleIndex( swizzle.getSecondValue() ) );
			}

			if ( count >= 3u )
			{
				result.push_back( getSwizzleIndex( swizzle.getThirdValue() ) );
			}

			if ( count >= 4u )
			{
				result.push_back( getSwizzleIndex( swizzle.getFourthValue() ) );
			}

			return result;
		}

		expr::SwizzleKind getFinalSwizzle( std::vector< expr::SwizzleKind > const & values
			, std::vector< uint32_t > const & indices )
		{
			expr::SwizzleKind result;
			uint32_t shift = 0u;

			for ( auto & index : indices )
			{
				result |= values[index] >> shift;
				shift += 4u;
			}

			return result;
		}

		class ExprSwizzleSimplifier
			: public ExprCloner
		{
		public:
			static expr::ExprPtr submit( type::TypesCache & cache
				, expr::Expr * expr )
			{
				expr::ExprPtr result;
				ExprSwizzleSimplifier vis{ cache, result };
				expr->accept( &vis );
				return result;
			}

			static expr::ExprPtr submit( type::TypesCache & cache
				, expr::ExprPtr expr )
			{
				return submit( cache, expr.get() );
			}

		private:
			ExprSwizzleSimplifier( type::TypesCache & cache
				, expr::ExprPtr & result )
				: ExprCloner{ result }
				, m_cache{ cache }
			{
			}

		private:
			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				expr::ExprPtr result;
				ExprSwizzleSimplifier vis{ m_cache, result };
				expr->accept( &vis );
				return result;
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				if ( expr->getLHS()->getKind() == expr::Kind::eSwizzle
					&& expr->getRHS()->getKind() == expr::Kind::eLiteral )
				{
					uint32_t index = 0u;
					auto & lit = static_cast< expr::Literal const & >( *expr->getRHS() );
					assert( lit.getLiteralType() == expr::LiteralType::eInt
						|| lit.getLiteralType() == expr::LiteralType::eUInt );

					if ( lit.getLiteralType() == expr::LiteralType::eInt )
					{
						index = uint32_t( lit.getValue< expr::LiteralType::eInt >() );
					}
					else
					{
						index = lit.getValue< expr::LiteralType::eUInt >();
					}

					auto & outer = static_cast< expr::Swizzle & >( *expr->getLHS() );
					m_result = submit( m_cache
						, expr::makeSwizzle( submit( m_cache, outer.getOuterExpr() )
							, outer.getSwizzle()[index] ) );
				}
				else
				{
					ExprCloner::visitArrayAccessExpr( expr );
				}
			}
			
			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				if ( expr->getOuterExpr()->getKind() == expr::Kind::eSwizzle )
				{
					auto & outer = static_cast< expr::Swizzle & >( *expr->getOuterExpr() );
					auto values = getSwizzleValues( outer.getSwizzle() );
					auto indices = getSwizzleIndices( expr->getSwizzle() );

					m_result = submit( m_cache
						, expr::makeSwizzle( submit( m_cache, outer.getOuterExpr() )
							, getFinalSwizzle( values, indices ) ) );
				}
				else
				{
					ExprCloner::visitSwizzleExpr( expr );
				}
			}

		private:
			type::TypesCache & m_cache;
		};
	}

	stmt::ContainerPtr SwizzleSimplifier::submit( type::TypesCache & cache
		, stmt::Container * stmt )
	{
		auto result = ast::stmt::makeContainer();
		SwizzleSimplifier vis{ cache, result };
		stmt->accept( &vis );
		return result;
	}

	SwizzleSimplifier::SwizzleSimplifier( type::TypesCache & cache
		, stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_cache{ cache }
	{
	}

	expr::ExprPtr SwizzleSimplifier::doSubmit( expr::Expr * expr )
	{
		return ExprSwizzleSimplifier::submit( m_cache, expr );
	}
}
