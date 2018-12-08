/*
See LICENSE file in root folder
*/
#include "HlslExprConfigFiller.hpp"

#include "HlslHelpers.hpp"
#include "HlslVariableReplacer.hpp"
#include "HlslImageAccessConfig.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslTextureAccessConfig.hpp"

#include <ShaderWriter/Intrinsics/Intrinsics.hpp>

namespace hlsl
{
	void ExprConfigFiller::submit( ast::expr::Expr * expr
		, IntrinsicsConfig & config )
	{
		ExprConfigFiller vis{ config };
		expr->accept( &vis );
	}

	void ExprConfigFiller::submit( ast::expr::ExprPtr const & expr
		, IntrinsicsConfig & config )
	{
		submit( expr.get()
			, config );
	}

	ExprConfigFiller::ExprConfigFiller( IntrinsicsConfig & config )
		: ast::expr::SimpleVisitor{}
		, m_config{ config }
	{
	}

	void ExprConfigFiller::visitUnaryExpr( ast::expr::Unary * expr )
	{
		expr->getOperand()->accept( this );
	}

	void ExprConfigFiller::visitBinaryExpr( ast::expr::Binary * expr )
	{
		expr->getLHS()->accept( this );
		expr->getRHS()->accept( this );
	}

	void ExprConfigFiller::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		if ( expr->getIdentifier() )
		{
			expr->getIdentifier()->accept( this );
		}

		for ( auto & init : expr->getInitialisers() )
		{
			init->accept( this );
		}
	}

	void ExprConfigFiller::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		expr->getOuterExpr()->accept( this );
		expr->getMember()->accept( this );
	}

	void ExprConfigFiller::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		expr->getFn()->accept( this );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		getHlslConfig( expr->getImageAccess(), m_config );
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		getHlslConfig( expr->getIntrinsic(), m_config );
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		getHlslConfig( expr->getTextureAccess(), m_config );
	}

	void ExprConfigFiller::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
	}

	void ExprConfigFiller::visitInitExpr( ast::expr::Init * expr )
	{
		expr->getIdentifier()->accept( this );
		expr->getInitialiser()->accept( this );
	}

	void ExprConfigFiller::visitLiteralExpr( ast::expr::Literal * expr )
	{
	}

	void ExprConfigFiller::visitQuestionExpr( ast::expr::Question * expr )
	{
		expr->getCtrlExpr()->accept( this );
		expr->getTrueExpr()->accept( this );
		expr->getFalseExpr()->accept( this );
	}

	void ExprConfigFiller::visitSwitchCaseExpr( ast::expr::SwitchCase * expr )
	{
		expr->getLabel()->accept( this );
	}

	void ExprConfigFiller::visitSwitchTestExpr( ast::expr::SwitchTest * expr )
	{
		expr->getValue()->accept( this );
	}

	void ExprConfigFiller::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		expr->getOuterExpr()->accept( this );
	}
}
