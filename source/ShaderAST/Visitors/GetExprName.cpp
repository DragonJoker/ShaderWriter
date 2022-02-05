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
			static std::vector< expr::Identifier * > submit( expr::Expr * expr
				, type::Kind kind
				, var::Flag flag )
			{
				std::vector< expr::Identifier * > result;
				IdentifiersExtractor vis{ result, kind, flag };
				expr->accept( &vis );
				return result;
			}

			static std::vector< expr::Identifier * > submit( expr::ExprPtr const & expr
				, type::Kind kind
				, var::Flag flag )
			{
				return submit( expr.get(), kind, flag );
			}

		private:
			IdentifiersExtractor( std::vector< expr::Identifier * > & result
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

			bool isCompatible( var::VariablePtr var )
			{
				return isTypeCompatible( var->getType() )
					&& isFlagCompatible( var );
			}

			bool checkToVisit()const
			{
				return m_kind != type::Kind::eUndefined;
			}

			void visitUnaryExpr( expr::Unary * expr )override
			{
				expr->getOperand()->accept( this );
			}

			void visitBinaryExpr( expr::Binary * expr )override
			{
				expr->getLHS()->accept( this );
				expr->getRHS()->accept( this );
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
			{
				if ( expr->getIdentifier() )
				{
					expr->getIdentifier()->accept( this );
				}

				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getInitialisers() )
					{
						arg->accept( this );
					}
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				expr->getOuterExpr()->accept( this );
			}

			void visitFnCallExpr( expr::FnCall * expr )override
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

			void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override
			{
				if ( checkToVisit() )
				{
					for ( auto & arg : expr->getArgList() )
					{
						arg->accept( this );
					}
				}
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				if ( isCompatible( expr->getVariable() ) )
				{
					m_result.push_back( expr );
				}
			}

			void visitInitExpr( expr::Init * expr )override
			{
				expr->getIdentifier()->accept( this );

				if ( checkToVisit() )
				{
					expr->getInitialiser()->accept( this );
				}
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				expr->getCtrlExpr()->accept( this );

				if ( checkToVisit() )
				{
					expr->getTrueExpr()->accept( this );
					expr->getFalseExpr()->accept( this );
				}
			}

			void visitStreamAppendExpr( expr::StreamAppend * expr )override
			{
				if ( checkToVisit() )
				{
					expr->getOperand()->accept( this );
				}
			}

			void visitSwitchCaseExpr( expr::SwitchCase * expr )override
			{
				expr->getLabel()->accept( this );
			}

			void visitSwitchTestExpr( expr::SwitchTest * expr )override
			{
				expr->getValue()->accept( this );
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				expr->getOuterExpr()->accept( this );
			}

		private:
			std::vector< expr::Identifier * > & m_result;
			type::Kind m_kind;
			var::Flag m_flag;
		};

		//*********************************************************************
	}

	//*************************************************************************

	std::vector< expr::Identifier * > listCommaIdentifiers( expr::Expr * expr )
	{
		std::vector< expr::Identifier * > result;

		if ( expr->getKind() == expr::Kind::eComma )
		{
			auto comma = static_cast< expr::Comma * >( expr );
			result = listCommaIdentifiers( comma->getLHS() );
			auto rhsIdents = listCommaIdentifiers( comma->getRHS() );
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

	std::vector< expr::Identifier * > listIdentifiers( expr::Expr * expr
		, type::Kind kind
		, var::Flag flag )
	{
		return IdentifiersExtractor::submit( expr, kind, flag );
	}

	std::vector< expr::Identifier * > listIdentifiers( expr::ExprPtr const & expr
		, type::Kind kind
		, var::Flag flag )
	{
		return IdentifiersExtractor::submit( expr, kind, flag );
	}

	expr::Identifier * findIdentifier( expr::Expr * expr
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

	expr::Identifier * findIdentifier( expr::ExprPtr const & expr
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

	std::string findName( expr::Expr * expr
		, type::Kind kind
		, var::Flag flag )
	{
		auto ident = findIdentifier( expr, kind, flag );
		std::string result;

		if ( ident )
		{
			result = ident->getVariable()->getName();
		}

		return result;
	}

	std::string findName( expr::ExprPtr const & expr
		, type::Kind kind
		, var::Flag flag )
	{
		auto ident = findIdentifier( expr, kind, flag );
		std::string result;

		if ( ident )
		{
			result = ident->getVariable()->getName();
		}

		return result;
	}

	//*************************************************************************
}
