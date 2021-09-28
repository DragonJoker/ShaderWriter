/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/GetOutermostExpr.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"
#include "ShaderAST/Var/Variable.hpp"

namespace ast
{
	namespace
	{
		class OutermostExprExtractor
			: public expr::SimpleVisitor
		{
		public:
			static expr::Expr * submit( expr::Expr * expr )
			{
				expr::Expr * result{ nullptr };
				OutermostExprExtractor vis{ result };
				expr->accept( &vis );
				return result;
			}

			static expr::Expr * submit( expr::ExprPtr const & expr )
			{
				return submit( expr.get() );
			}

		private:
			OutermostExprExtractor( expr::Expr *& result )
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
			}

			void visitOtherExpr( expr::Expr * expr )
			{
				if ( !m_result )
				{
					m_result = expr;
				}
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
			{
				if ( !m_result )
				{
					expr->getIdentifier()->accept( this );
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
			{
				visitOtherExpr( expr );
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
				visitOtherExpr( expr );
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override
			{
				visitOtherExpr( expr );
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override
			{
				visitOtherExpr( expr );
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				visitOtherExpr( expr );
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
				visitOtherExpr( expr );
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				visitOtherExpr( expr );
			}

			void visitSwitchCaseExpr( expr::SwitchCase * expr )override
			{
				AST_Failure( "getOutermostExpr: Unexpected SwitchCase" );
			}

			void visitSwitchTestExpr( expr::SwitchTest * expr )override
			{
				AST_Failure( "getOutermostExpr: Unexpected SwitchTest" );
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				if ( !m_result )
				{
					expr->getOuterExpr()->accept( this );
				}
			}

		private:
			expr::Expr *& m_result;
		};
	}

	expr::Expr * getOutermostExpr( ast::expr::Expr * expr )
	{
		return OutermostExprExtractor::submit( expr );
	}

	expr::Expr * getOutermostExpr( ast::expr::ExprPtr const & expr )
	{
		return OutermostExprExtractor::submit( expr );
	}
}
