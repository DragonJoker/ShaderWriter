/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/GetExprName.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"
#include "ShaderAST/Var/Variable.hpp"

namespace ast
{
	namespace
	{
		class IdentifierExtractor
			: public expr::SimpleVisitor
		{
		public:
			static expr::Identifier * submit( expr::Expr * expr )
			{
				expr::Identifier * result{ nullptr };
				IdentifierExtractor vis{ result };
				expr->accept( &vis );
				return result;
			}

			static expr::Identifier * submit( expr::ExprPtr const & expr )
			{
				return submit( expr.get() );
			}

		private:
			IdentifierExtractor( expr::Identifier *& result )
				: m_result{ result }
			{
			}


		private:
			void visitUnaryExpr( expr::Unary * expr )override
			{
				if ( !m_result )
				{
					expr->getOperand()->accept( this );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )override
			{
				if ( !m_result )
				{
					expr->getLHS()->accept( this );
				}

				if ( !m_result )
				{
					expr->getRHS()->accept( this );
				}
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
			{
				if ( !m_result
					&& expr->getIdentifier() )
				{
					expr->getIdentifier()->accept( this );
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
			{
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				if ( !m_result )
				{
					expr->getOuterExpr()->accept( this );
				}
			}

			void visitFnCallExpr( expr::FnCall * expr )override
			{
				if ( !m_result )
				{
					expr->getFn()->accept( this );
				}
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
			{
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override
			{
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override
			{
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				if ( !m_result )
				{
					m_result = expr;
				}
			}

			void visitInitExpr( expr::Init * expr )override
			{
				if ( !m_result )
				{
					expr->getIdentifier()->accept( this );
				}
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				if ( !m_result )
				{
					expr->getCtrlExpr()->accept( this );
				}
			}

			void visitSwitchCaseExpr( expr::SwitchCase * expr )override
			{
				if ( !m_result )
				{
					expr->getLabel()->accept( this );
				}
			}

			void visitSwitchTestExpr( expr::SwitchTest * expr )override
			{
				if ( !m_result )
				{
					expr->getValue()->accept( this );
				}
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				if ( !m_result )
				{
					expr->getOuterExpr()->accept( this );
				}
			}

		private:
			expr::Identifier *& m_result;
		};
	}

	std::vector< expr::Identifier * > listIdentifiers( expr::Expr * expr )
	{
		std::vector< expr::Identifier * > result;

		if ( expr->getKind() == expr::Kind::eComma )
		{
			auto comma = static_cast< expr::Comma * >( expr );
			result = listIdentifiers( comma->getLHS() );
			auto rhsIdents = listIdentifiers( comma->getRHS() );
			result.insert( result.end(), rhsIdents.begin(), rhsIdents.end() );
		}
		else
		{
			auto ident = findIdentifier( expr );

			if ( ident )
			{
				result.emplace_back( ident );
			}
		}

		return result;
	}

	expr::Identifier * findIdentifier( ast::expr::Expr * expr )
	{
		return IdentifierExtractor::submit( expr );
	}

	expr::Identifier * findIdentifier( ast::expr::ExprPtr const & expr )
	{
		return IdentifierExtractor::submit( expr );
	}

	std::string findName( ast::expr::Expr * expr )
	{
		auto ident = findIdentifier( expr );
		std::string result;

		if ( ident )
		{
			result = ident->getVariable()->getName();
		}

		return result;
	}

	std::string findName( ast::expr::ExprPtr const & expr )
	{
		auto ident = findIdentifier( expr );
		std::string result;

		if ( ident )
		{
			result = ident->getVariable()->getName();
		}

		return result;
	}
}
