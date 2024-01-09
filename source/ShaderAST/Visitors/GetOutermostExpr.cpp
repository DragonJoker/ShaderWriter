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
			static expr::Expr const * submit( expr::Expr const & expr )
			{
				expr::Expr const * result{};
				OutermostExprExtractor vis{ result };
				expr.accept( &vis );
				return result;
			}

		private:
			explicit OutermostExprExtractor( expr::Expr const *& result )
				: m_result{ result }
			{
			}

		private:
			void visitOtherExpr( expr::Expr const & expr )
			{
				if ( !m_result )
				{
					m_result = &expr;
				}
			}

			void visitUnaryExpr( expr::Unary const * expr )override
			{
				if ( !m_result )
				{
					expr->getOperand()->accept( this );
				}
			}

			void visitBinaryExpr( expr::Binary const * expr )override
			{
				if ( !m_result )
				{
					expr->getLHS()->accept( this );
				}
			}

			void visitAggrInitExpr( expr::AggrInit const * expr )override
			{
				if ( !m_result
					&& expr->hasIdentifier() )
				{
					expr->getIdentifier().accept( this );
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override
			{
				visitOtherExpr( *expr );
			}

			void visitMbrSelectExpr( expr::MbrSelect const * expr )override
			{
				if ( !m_result )
				{
					expr->getOuterExpr()->accept( this );
				}
			}

			void visitFnCallExpr( expr::FnCall const * expr )override
			{
				if ( !m_result )
				{
					expr->getFn()->accept( this );
				}
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override
			{
				visitOtherExpr( *expr );
			}

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
			{
				visitOtherExpr( *expr );
			}

			void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
			{
				visitOtherExpr( *expr );
			}

			void visitIdentifierExpr( expr::Identifier const * expr )override
			{
				visitOtherExpr( *expr );
			}

			void visitInitExpr( expr::Init const * expr )override
			{
				if ( !m_result
					&& expr->hasIdentifier() )
				{
					expr->getIdentifier().accept( this );
				}
			}

			void visitLiteralExpr( expr::Literal const * expr )override
			{
				visitOtherExpr( *expr );
			}

			void visitQuestionExpr( expr::Question const * expr )override
			{
				visitOtherExpr( *expr );
			}

			void visitStreamAppendExpr( expr::StreamAppend const * expr )override
			{
				if ( !m_result )
				{
					expr->getOperand()->accept( this );
				}
			}

			void visitSwitchCaseExpr( expr::SwitchCase const * expr )override
			{
				AST_Failure( "getOutermostExpr: Unexpected SwitchCase" );
			}

			void visitSwitchTestExpr( expr::SwitchTest const * expr )override
			{
				AST_Failure( "getOutermostExpr: Unexpected SwitchTest" );
			}

			void visitSwizzleExpr( expr::Swizzle const * expr )override
			{
				if ( !m_result )
				{
					expr->getOuterExpr()->accept( this );
				}
			}

		private:
			expr::Expr const *& m_result;
		};
	}

	expr::Expr const * getOutermostExpr( ast::expr::Expr const & expr )
	{
		return OutermostExprExtractor::submit( expr );
	}
}
