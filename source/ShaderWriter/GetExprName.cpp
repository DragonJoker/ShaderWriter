/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GetExprName.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>
#include <ASTGenerator/Var/Variable.hpp>

namespace sdw
{
	using namespace ast;

	namespace
	{
		class ExprNamer
			: public expr::SimpleVisitor
		{
		public:
			static std::string submit( expr::Expr * expr )
			{
				std::string result;
				ExprNamer vis{ result };
				expr->accept( &vis );
				return result;
			}

			static std::string submit( expr::ExprPtr const & expr )
			{
				return submit( expr.get() );
			}

		private:
			ExprNamer( std::string & result )
				: m_result{ result }
			{
			}


		private:
			void visitUnaryExpr( expr::Unary * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getOperand()->accept( this );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getLHS()->accept( this );
				}

				if ( m_result.empty() )
				{
					expr->getRHS()->accept( this );
				}
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getIdentifier()->accept( this );
				}
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getOuterExpr()->accept( this );
				}
			}

			void visitFnCallExpr( expr::FnCall * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getFn()->accept( this );
				}
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				if ( m_result.empty() )
				{
					m_result = expr->getVariable()->getName();
				}
			}

			void visitInitExpr( expr::Init * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getIdentifier()->accept( this );
				}
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getCtrlExpr()->accept( this );
				}
			}

			void visitSwitchCaseExpr( expr::SwitchCase * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getLabel()->accept( this );
				}
			}

			void visitSwitchTestExpr( expr::SwitchTest * expr )override
			{
				if ( m_result.empty() )
				{
					expr->getValue()->accept( this );
				}
			}


		private:
			std::string & m_result;
		};
	}

	std::string findName( ast::expr::Expr * expr )
	{
		return ExprNamer::submit( expr );
	}

	std::string findName( ast::expr::ExprPtr const & expr )
	{
		return ExprNamer::submit( expr );
	}
}
