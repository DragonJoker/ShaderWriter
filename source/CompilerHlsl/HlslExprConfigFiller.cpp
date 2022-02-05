/*
See LICENSE file in root folder
*/
#include "HlslExprConfigFiller.hpp"

#include "HlslHelpers.hpp"
#include "HlslShader.hpp"
#include "HlslVariableReplacer.hpp"
#include "HlslImageAccessConfig.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslSampledImageAccessConfig.hpp"
#include "HlslTextureAccessConfig.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

namespace hlsl
{
	namespace
	{
		void checkBuiltin( ast::Builtin builtin
			, IntrinsicsConfig & config )
		{
			switch ( builtin )
			{
			case ast::Builtin::eSampleID:
				config.requiresSampledIndex = true;
				break;
			default:
				break;
			}
		}

		void checkBuiltin( ast::var::Variable const & var
			, IntrinsicsConfig & config )
		{
			if ( var.isBuiltin() )
			{
				checkBuiltin( var.getBuiltin(), config );
			}
		}

		void checkBuiltin( ast::type::Struct const & type
			, uint32_t index
			, IntrinsicsConfig & config )
		{
			auto mbr = *std::next( type.begin(), ptrdiff_t( index ) );

			if ( mbr.builtin != ast::Builtin::eNone )
			{
				checkBuiltin( mbr.builtin, config );
			}
		}
	}

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
		checkType( expr->getType(), m_config );
		expr->getOperand()->accept( this );
	}

	void ExprConfigFiller::visitBinaryExpr( ast::expr::Binary * expr )
	{
		checkType( expr->getType(), m_config );
		expr->getLHS()->accept( this );
		expr->getRHS()->accept( this );
	}

	void ExprConfigFiller::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		checkType( expr->getType(), m_config );

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
		checkType( expr->getType(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		checkType( expr->getType(), m_config );
		checkBuiltin( *expr->getOuterType(), expr->getMemberIndex(), m_config );
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
		else if ( !expr->isPerTask()
			&& ( expr->isShaderInput() || expr->isShaderOutput() ) )
		{
			auto ident = ast::findIdentifier( expr );

			if ( ident
				&& ident->getVariable()->isPerTask() )
			{
				return;
			}

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
		checkType( expr->getType(), m_config );
		expr->getFn()->accept( this );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		checkType( expr->getType(), m_config );
		getHlslConfig( expr->getImageAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		checkType( expr->getType(), m_config );
		getHlslConfig( expr->getIntrinsic(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitSampledImageAccessCallExpr( ast::expr::SampledImageAccessCall * expr )
	{
		checkType( expr->getType(), m_config );
		getHlslConfig( expr->getSampledImageAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )
	{
		checkType( expr->getType(), m_config );
		getHlslConfig( expr->getCombinedImageAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		checkBuiltin( *expr->getVariable(), m_config );
		checkType( expr->getType(), m_config );
	}

	void ExprConfigFiller::visitInitExpr( ast::expr::Init * expr )
	{
		checkType( expr->getType(), m_config );
		expr->getIdentifier()->accept( this );
		expr->getInitialiser()->accept( this );
	}

	void ExprConfigFiller::visitLiteralExpr( ast::expr::Literal * expr )
	{
		checkType( expr->getType(), m_config );
	}

	void ExprConfigFiller::visitQuestionExpr( ast::expr::Question * expr )
	{
		checkType( expr->getType(), m_config );
		expr->getCtrlExpr()->accept( this );
		expr->getTrueExpr()->accept( this );
		expr->getFalseExpr()->accept( this );
	}

	void ExprConfigFiller::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		checkType( expr->getType(), m_config );
		expr->getOperand()->accept( this );
	}

	void ExprConfigFiller::visitSwitchCaseExpr( ast::expr::SwitchCase * expr )
	{
		checkType( expr->getType(), m_config );
		expr->getLabel()->accept( this );
	}

	void ExprConfigFiller::visitSwitchTestExpr( ast::expr::SwitchTest * expr )
	{
		checkType( expr->getType(), m_config );
		expr->getValue()->accept( this );
	}

	void ExprConfigFiller::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		checkType( expr->getType(), m_config );
		expr->getOuterExpr()->accept( this );
	}
}
