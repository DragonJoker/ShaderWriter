/*
See LICENSE file in root folder
*/
#include "GlslExprConfigFiller.hpp"

#include "GlslHelpers.hpp"
#include "GlslTextureAccessConfig.hpp"

namespace glsl
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
		return submit( expr.get()
			, config );
	}

	ExprConfigFiller::ExprConfigFiller( IntrinsicsConfig & config )
		: ast::expr::SimpleVisitor{}
		, m_config{ config }
	{
	}

	void ExprConfigFiller::visitUnaryExpr( ast::expr::Unary * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getOperand()->accept( this );
	}

	void ExprConfigFiller::visitBinaryExpr( ast::expr::Binary * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getLHS()->accept( this );
		expr->getRHS()->accept( this );
	}

	void ExprConfigFiller::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		checkType( *expr->getType(), m_config );

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
		checkType( *expr->getType(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getOuterExpr()->accept( this );
	}

	void ExprConfigFiller::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getFn()->accept( this );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		checkType( *expr->getType(), m_config );

		switch ( expr->getIntrinsic() )
		{
		case ast::expr::Intrinsic::eFma1F:
			m_config.requiresFma1F = true;
			break;
		case ast::expr::Intrinsic::eFma2F:
			m_config.requiresFma2F = true;
			break;
		case ast::expr::Intrinsic::eFma3F:
			m_config.requiresFma3F = true;
			break;
		case ast::expr::Intrinsic::eFma4F:
			m_config.requiresFma4F = true;
			break;
		case ast::expr::Intrinsic::eFma1D:
			m_config.requiresFma1D = true;
			break;
		case ast::expr::Intrinsic::eFma2D:
			m_config.requiresFma2D = true;
			break;
		case ast::expr::Intrinsic::eFma3D:
			m_config.requiresFma3D = true;
			break;
		case ast::expr::Intrinsic::eFma4D:
			m_config.requiresFma4D = true;
			break;
		case ast::expr::Intrinsic::eAtomicAdd2H:
		case ast::expr::Intrinsic::eAtomicAdd4H:
		case ast::expr::Intrinsic::eAtomicExchange2H:
		case ast::expr::Intrinsic::eAtomicExchange4H:
			m_config.requiresAtomicFp16Vector = true;
			[[fallthrough]];
		case ast::expr::Intrinsic::eAtomicAddF:
		case ast::expr::Intrinsic::eAtomicExchangeF:
			m_config.requiresAtomicFloat = true;
			break;
		default:
			break;
		}

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		checkType( *expr->getType(), m_config );
		getGlslConfig( expr->getTextureAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		checkType( *expr->getType(), m_config );

		if ( ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicAdd1DF
				&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayF )
			|| ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicExchange1DF
				&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayF ) )
		{
			m_config.requiresAtomicFloat = true;

			for ( auto & arg : expr->getArgList() )
			{
				if ( ast::type::getComponentType( arg->getType() ) == ast::type::Kind::eHalf )
				{
					m_config.requiresAtomicFp16Vector = true;
				}
			}
		}

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		checkType( *expr->getType(), m_config );
	}

	void ExprConfigFiller::visitInitExpr( ast::expr::Init * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getIdentifier()->accept( this );
		expr->getInitialiser()->accept( this );
	}

	void ExprConfigFiller::visitLiteralExpr( ast::expr::Literal * expr )
	{
		checkType( *expr->getType(), m_config );
	}

	void ExprConfigFiller::visitQuestionExpr( ast::expr::Question * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getCtrlExpr()->accept( this );
		expr->getTrueExpr()->accept( this );
		expr->getFalseExpr()->accept( this );
	}

	void ExprConfigFiller::visitSwitchCaseExpr( ast::expr::SwitchCase * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getLabel()->accept( this );
	}

	void ExprConfigFiller::visitSwitchTestExpr( ast::expr::SwitchTest * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getValue()->accept( this );
	}

	void ExprConfigFiller::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		checkType( *expr->getType(), m_config );
		expr->getOuterExpr()->accept( this );
	}
}
