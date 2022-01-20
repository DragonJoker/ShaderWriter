/*
See LICENSE file in root folder
*/
#include "HlslExprConfigFiller.hpp"

#include "HlslHelpers.hpp"
#include "HlslShader.hpp"
#include "HlslVariableReplacer.hpp"
#include "HlslImageAccessConfig.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslTextureAccessConfig.hpp"

namespace hlsl
{
	void ExprConfigFiller::submit( ast::expr::Expr * expr
		, AdaptationData & adaptationData
		, IntrinsicsConfig & config )
	{
		ExprConfigFiller vis{ adaptationData, config };
		expr->accept( &vis );
	}

	void ExprConfigFiller::submit( ast::expr::ExprPtr const & expr
		, AdaptationData & adaptationData
		, IntrinsicsConfig & config )
	{
		submit( expr.get()
			, adaptationData
			, config );
	}

	ExprConfigFiller::ExprConfigFiller( AdaptationData & adaptationData
		, IntrinsicsConfig & config )
		: ast::expr::SimpleVisitor{}
		, m_adaptationData{ adaptationData }
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

		if ( isRayTraceStage( m_adaptationData.shader->getType() ) )
		{
			return;
		}

		if ( expr->isBuiltin() )
		{
			m_adaptationData.addMbrBuiltin( expr->getOuterExpr()
				, expr->getMemberIndex()
				, *expr
				, 0u );
		}
		else if ( expr->isShaderInput() || expr->isShaderOutput() )
		{
			auto type = expr->getOuterType();
			auto mbr = type->getMember( expr->getMemberIndex() );

			if ( expr->isShaderInput() )
			{
				m_adaptationData.addPendingMbrInput( expr->getOuterExpr()
					, expr->getMemberIndex()
					, *expr
					, mbr.location );
			}
			else
			{
				m_adaptationData.addPendingMbrOutput( expr->getOuterExpr()
					, expr->getMemberIndex()
					, *expr
					, mbr.location );
			}
		}
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

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		getHlslConfig( expr->getIntrinsic(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		getHlslConfig( expr->getTextureAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
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

	void ExprConfigFiller::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		expr->getOperand()->accept( this );
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
