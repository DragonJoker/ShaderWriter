/*
See LICENSE file in root folder
*/
#include "SpirvExprConfigFiller.hpp"

#include "SpirvHelpers.hpp"
#include "SpirvImageAccessConfig.hpp"
#include "SpirvIntrinsicConfig.hpp"
#include "SpirvTextureAccessConfig.hpp"

namespace spirv
{
	namespace
	{
		void checkType( ast::type::Kind kind
			, ModuleConfig & config )
		{
			if ( isDoubleType( kind ) )
			{
				config.requiredCapabilities.insert( spv::CapabilityFloat64 );
			}
			else if ( isHalfType( kind ) )
			{
				config.requiredCapabilities.insert( spv::CapabilityFloat16 );
			}
		}

		void checkType( ast::expr::Expr * expr
			, ModuleConfig & config )
		{
			checkType( expr->getType()->getKind()
				, config );
		}

		void checkType( ast::expr::IntrinsicCall * expr
			, ModuleConfig & config )
		{
			checkType( expr->getType()->getKind()
				, config );
			auto kind = expr->getIntrinsic();

			if ( ( kind >= ast::expr::Intrinsic::eDFdxCoarse1
					&& kind <= ast::expr::Intrinsic::eDFdxFine4 )
				|| ( kind >= ast::expr::Intrinsic::eDFdyCoarse1
					&& kind <= ast::expr::Intrinsic::eDFdyFine4 ) )
			{
				config.requiredCapabilities.insert( spv::CapabilityDerivativeControl );
			}
			else if ( kind == ast::expr::Intrinsic::eAtomicAddF
				|| kind == ast::expr::Intrinsic::eAtomicAdd2H
				|| kind == ast::expr::Intrinsic::eAtomicAdd4H )
			{
				if ( isDoubleType( expr->getType()->getKind() ) )
				{
					config.requiredCapabilities.insert( spv::CapabilityAtomicFloat64AddEXT );
				}
				else
				{
					config.requiredCapabilities.insert( spv::CapabilityAtomicFloat32AddEXT );
				}
			}
		}
	}

	void ExprConfigFiller::submit( ast::expr::Expr * expr
		, ModuleConfig & config )
	{
		ExprConfigFiller vis{ config };
		expr->accept( &vis );
	}

	void ExprConfigFiller::submit( ast::expr::ExprPtr const & expr
		, ModuleConfig & config )
	{
		submit( expr.get()
			, config );
	}

	ExprConfigFiller::ExprConfigFiller( ModuleConfig & config )
		: ast::expr::SimpleVisitor{}
		, m_config{ config }
	{
	}

	void ExprConfigFiller::visitUnaryExpr( ast::expr::Unary * expr )
	{
		checkType( expr, m_config );
		expr->getOperand()->accept( this );
	}

	void ExprConfigFiller::visitBinaryExpr( ast::expr::Binary * expr )
	{
		checkType( expr, m_config );
		expr->getLHS()->accept( this );
		expr->getRHS()->accept( this );
	}

	void ExprConfigFiller::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		checkType( expr, m_config );

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
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		checkType( expr, m_config );
		expr->getOuterExpr()->accept( this );

		if ( expr->isShaderInput() )
		{
			auto outer = expr->getOuterExpr();
			bool processed = false;

			if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
			{
				outer = static_cast< ast::expr::ArrayAccess const & >( *outer ).getLHS();
			}

			if ( outer->getKind() == ast::expr::Kind::eIdentifier )
			{
				auto outerVar = static_cast< ast::expr::Identifier const & >( *outer ).getVariable();
				processed = m_config.inputs.end () != m_config.inputs.find( outerVar );
			}

			if ( !processed
				&& outer->getType()->getKind() == ast::type::Kind::eGeometryInput )
			{
				auto outerType = expr->getOuterType();
				auto mbr = outerType->getMember( expr->getMemberIndex() );
				m_config.addShaderInput( "geomIn_" + mbr.name
					, mbr.type
					, outerType->getFlag()
					, static_cast< ast::type::GeometryInput const & >( *outer->getType() ) );
			}
		}
	}

	void ExprConfigFiller::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		checkType( expr, m_config );
		expr->getFn()->accept( this );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}
	}

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}

		auto kind = expr->getImageAccess();
		auto & config = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() )->getConfig();

		if ( config.dimension == ast::type::ImageDim::e1D )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityImage1D );
		}
		else if ( config.dimension == ast::type::ImageDim::eRect )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityImageRect );
		}
		else if ( config.dimension == ast::type::ImageDim::eBuffer )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityImageBuffer );
		}

		if ( config.isArrayed )
		{
			if ( config.dimension == ast::type::ImageDim::eCube )
			{
				m_config.requiredCapabilities.insert( spv::CapabilityImageCubeArray );
			}
			else if ( config.isMS )
			{
				m_config.requiredCapabilities.insert( spv::CapabilityImageMSArray );
			}
		}

		if ( ( kind >= ast::expr::ImageAccess::eImageSize1DF
			&& kind <= ast::expr::ImageAccess::eImageSize2DMSArrayU )
			|| ( kind >= ast::expr::ImageAccess::eImageSamples2DMSF
				&& kind <= ast::expr::ImageAccess::eImageSamples2DMSArrayU ) )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityImageQuery );
		}
		else if ( ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicAdd1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayF )
			|| ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicExchange1DF
				&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayF ) )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityAtomicFloat32AddEXT );

			for ( auto & arg : expr->getArgList() )
			{
				if ( ast::type::getComponentType( arg->getType() ) == ast::type::Kind::eHalf )
				{
				}
			}
		}
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}

		auto kind = expr->getIntrinsic();

		if ( ( kind >= ast::expr::Intrinsic::eAtomicAddF
			&& kind <= ast::expr::Intrinsic::eAtomicAdd4H )
			|| ( kind >= ast::expr::Intrinsic::eAtomicExchangeF
				&& kind <= ast::expr::Intrinsic::eAtomicExchange4H ) )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityAtomicFloat32AddEXT );
		}
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			arg->accept( this );
		}

		auto kind = expr->getTextureAccess();

		if ( ( kind >= ast::expr::TextureAccess::eTextureSize1DF
			&& kind <= ast::expr::TextureAccess::eTextureSizeBufferU )
			|| ( kind >= ast::expr::TextureAccess::eTextureQueryLod1DF
				&& kind <= ast::expr::TextureAccess::eTextureQueryLodCubeArrayU )
			|| ( kind >= ast::expr::TextureAccess::eTextureQueryLevels1DF
				&& kind <= ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayU ) )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityImageQuery );
		}
		
		if ( ( kind >= ast::expr::TextureAccess::eTextureGather2DShadowF
			&& kind <= ast::expr::TextureAccess::eTextureGatherOffsets2DRectShadowF ) )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityImageGatherExtended );
		}

		if ( getConstOffsets( kind ) == spv::ImageOperandsConstOffsetsMask )
		{
			m_config.requiredCapabilities.insert( spv::CapabilityImageGatherExtended );
		}

		IntrinsicConfig config;
		getSpirVConfig( kind, config );

		if ( config.offsetIndex )
		{
			assert( expr->getArgList().size() >= config.offsetIndex );
			bool constOffset = expr->getArgList()[config.offsetIndex - 1u]->isConstant();

			if ( getOffset( kind, constOffset ) == spv::ImageOperandsOffsetMask )
			{
				m_config.requiredCapabilities.insert( spv::CapabilityImageGatherExtended );
			}
		}
	}

	void ExprConfigFiller::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		checkType( expr, m_config );

		if ( expr->getVariable()->isShaderInput()
			&& expr->getType()->getKind() != ast::type::Kind::eGeometryInput )
		{
			m_config.inputs.insert( expr->getVariable() );
		}

		if ( expr->getVariable()->isShaderOutput() 
			&& !expr->getVariable()->isMember() )
		{
			m_config.outputs.insert( expr->getVariable() );
		}
	}

	void ExprConfigFiller::visitInitExpr( ast::expr::Init * expr )
	{
		checkType( expr, m_config );
		expr->getIdentifier()->accept( this );
		expr->getInitialiser()->accept( this );
	}

	void ExprConfigFiller::visitLiteralExpr( ast::expr::Literal * expr )
	{
		checkType( expr, m_config );
	}

	void ExprConfigFiller::visitQuestionExpr( ast::expr::Question * expr )
	{
		checkType( expr, m_config );
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
		checkType( expr, m_config );
		expr->getOuterExpr()->accept( this );
	}
}
