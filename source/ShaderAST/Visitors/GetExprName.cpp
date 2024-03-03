/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/GetExprName.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"
#include "ShaderAST/Var/Variable.hpp"

namespace ast
{
	//************************************************************************

	namespace
	{
		class IdentifiersExtractor
			: public expr::SimpleVisitor
		{
		public:
			static std::vector< expr::Identifier const * > submit( expr::Expr const & expr
				, type::Kind kind
				, var::Flag flag )
			{
				std::vector< expr::Identifier const * > result;
				IdentifiersExtractor vis{ result, kind, flag };
				expr.accept( &vis );
				return result;
			}

		private:
			IdentifiersExtractor( std::vector< expr::Identifier const * > & result
				, type::Kind kind
				, var::Flag flag )
				: m_result{ result }
				, m_kind{ kind }
				, m_flag{ flag }
			{
			}

		private:
			bool isTypeCompatible( type::TypePtr type )const
			{
				return m_kind == type::Kind::eUndefined
					|| m_kind == type::getNonArrayKind( type );
			}

			bool isFlagCompatible( var::VariablePtr var )const
			{
				return m_flag == var::Flag::eNone
					|| var->hasFlag( m_flag );
			}

			bool isCompatible( var::VariablePtr var )const
			{
				return isTypeCompatible( var->getType() )
					&& isFlagCompatible( var );
			}

			bool checkToVisit()const
			{
				return m_kind != type::Kind::eUndefined;
			}

			void visitUnaryExpr( expr::Unary const * expr )override
			{
				if ( auto operand = expr->getOperand() )
				{
					operand->accept( this );
				}
			}

			void visitBinaryExpr( expr::Binary const * expr )override
			{
				if ( auto lhs = expr->getLHS() )
				{
					lhs->accept( this );
				}

				if ( auto rhs = expr->getRHS() )
				{
					rhs->accept( this );
				}
			}

			void visitAggrInitExpr( expr::AggrInit const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					expr->getIdentifier().accept( this );
				}

				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getInitialisers() )
					{
						arg->accept( this );
					}
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitMbrSelectExpr( expr::MbrSelect const * expr )override
			{
				expr->getOuterExpr()->accept( this );
			}

			void visitFnCallExpr( expr::FnCall const * expr )override
			{
				expr->getFn()->accept( this );

				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitIdentifierExpr( expr::Identifier const * expr )override
			{
				if ( isCompatible( expr->getVariable() ) )
				{
					m_result.push_back( expr );
				}
			}

			void visitInitExpr( expr::Init const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					expr->getIdentifier().accept( this );
				}

				if ( checkToVisit() )
				{
					expr->getInitialiser()->accept( this );
				}
			}

			void visitLiteralExpr( expr::Literal const * expr )override
			{
			}

			void visitQuestionExpr( expr::Question const * expr )override
			{
				expr->getCtrlExpr()->accept( this );

				if ( checkToVisit() )
				{
					expr->getTrueExpr()->accept( this );
					expr->getFalseExpr()->accept( this );
				}
			}

			void visitStreamAppendExpr( expr::StreamAppend const * expr )override
			{
				if ( checkToVisit() )
				{
					expr->getOperand()->accept( this );
				}
			}

			void visitSwitchCaseExpr( expr::SwitchCase const * expr )override
			{
				expr->getLabel()->accept( this );
			}

			void visitSwitchTestExpr( expr::SwitchTest const * expr )override
			{
				expr->getValue()->accept( this );
			}

			void visitSwizzleExpr( expr::Swizzle const * expr )override
			{
				expr->getOuterExpr()->accept( this );
			}

		private:
			std::vector< expr::Identifier const * > & m_result;
			type::Kind m_kind;
			var::Flag m_flag;
		};
	}

	//*************************************************************************

	std::vector< expr::Identifier const * > listCommaIdentifiers( expr::Expr const & expr )
	{
		std::vector< expr::Identifier const * > result;

		if ( expr.getKind() == expr::Kind::eComma )
		{
			auto & comma = static_cast< expr::Comma const & >( expr );

			if ( comma.getLHS() )
			{
				result = listCommaIdentifiers( *comma.getLHS() );
			}

			if ( comma.getRHS() )
			{
				auto rhsIdents = listCommaIdentifiers( *comma.getRHS() );
				result.insert( result.end(), rhsIdents.begin(), rhsIdents.end() );
			}
		}
		else
		{
			if ( auto ident = findIdentifier( expr ) )
			{
				result.emplace_back( ident );
			}
		}

		return result;
	}

	std::vector< expr::Identifier const * > listIdentifiers( expr::Expr const & expr
		, type::Kind kind
		, var::Flag flag )
	{
		return IdentifiersExtractor::submit( expr, kind, flag );
	}

	expr::Identifier const * findIdentifier( expr::Expr const & expr
		, type::Kind kind
		, var::Flag flag )
	{
		auto result = listIdentifiers( expr, kind, flag );

		if ( result.empty() )
		{
			return nullptr;
		}

		return result.front();
	}

	std::string findName( expr::Expr const & expr
		, type::Kind kind
		, var::Flag flag )
	{
		std::string result;

		if ( auto ident = findIdentifier( expr, kind, flag ) )
		{
			result = ident->getVariable()->getName();
		}

		return result;
	}

	//*************************************************************************
}
