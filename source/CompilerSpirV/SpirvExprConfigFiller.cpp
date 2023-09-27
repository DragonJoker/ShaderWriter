/*
See LICENSE file in root folder
*/
#include "SpirvExprConfigFiller.hpp"

#include "SpirvHelpers.hpp"
#include "SpirvIntrinsicConfig.hpp"
#include "SpirvStorageImageAccessConfig.hpp"
#include "SpirvCombinedImageAccessConfig.hpp"

namespace spirv
{
	namespace
	{
		void checkType( ast::expr::Expr * expr
			, ModuleConfig & config )
		{
			checkType( expr->getType()
				, config );
		}

		void checkType( ast::expr::IntrinsicCall * expr
			, ModuleConfig & config )
		{
			checkType( expr->getType()
				, config );
			auto kind = expr->getIntrinsic();

			if ( ( kind >= ast::expr::Intrinsic::eDFdxCoarse1
					&& kind <= ast::expr::Intrinsic::eDFdxFine4 )
				|| ( kind >= ast::expr::Intrinsic::eDFdyCoarse1
					&& kind <= ast::expr::Intrinsic::eDFdyFine4 ) )
			{
				config.registerCapability( spv::CapabilityDerivativeControl );
			}
			else if ( kind >= ast::expr::Intrinsic::eInterpolateAtCentroid1
				&& kind <= ast::expr::Intrinsic::eInterpolateAtOffset4 )
			{
				config.registerCapability( spv::CapabilityInterpolationFunction );
			}
			else if ( kind == ast::expr::Intrinsic::eAtomicAddF
				|| kind == ast::expr::Intrinsic::eAtomicAdd2H
				|| kind == ast::expr::Intrinsic::eAtomicAdd4H )
			{
				if ( isDoubleType( expr->getType()->getKind() ) )
				{
					config.registerCapability( spv::CapabilityAtomicFloat64AddEXT );
				}
				else
				{
					config.registerCapability( spv::CapabilityAtomicFloat32AddEXT );
				}
			}
			else if ( kind == ast::expr::Intrinsic::eTraceRay
				|| kind == ast::expr::Intrinsic::eReportIntersection
				|| kind == ast::expr::Intrinsic::eExecuteCallable )
			{
				if ( isRayTraceStage( config.stage ) )
				{
					config.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					config.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}
			else if ( kind == ast::expr::Intrinsic::eSubgroupElect )
			{
				config.registerCapability( spv::CapabilityGroupNonUniform );
			}
			else if ( kind == ast::expr::Intrinsic::eSubgroupAll
				|| kind == ast::expr::Intrinsic::eSubgroupAny
				|| ( kind >= ast::expr::Intrinsic::eSubgroupAllEqual1F
					&& kind <= ast::expr::Intrinsic::eSubgroupAllEqual4D ) )
			{
				config.registerCapability( spv::CapabilityGroupNonUniformVote );
			}
			else if ( ( kind >= ast::expr::Intrinsic::eSubgroupBallot
					&& kind <= ast::expr::Intrinsic::eSubgroupBallotFindMSB )
				|| ( kind >= ast::expr::Intrinsic::eSubgroupBroadcast1F
					&& kind <= ast::expr::Intrinsic::eSubgroupBroadcast4D )
				|| ( kind >= ast::expr::Intrinsic::eSubgroupBroadcastFirst1F
					&& kind <= ast::expr::Intrinsic::eSubgroupBroadcastFirst4D ) )
			{
				config.registerCapability( spv::CapabilityGroupNonUniformBallot );
			}
			else if ( kind >= ast::expr::Intrinsic::eSubgroupShuffle1F
				&& kind <= ast::expr::Intrinsic::eSubgroupShuffleXor4D )
			{
				config.registerCapability( spv::CapabilityGroupNonUniformShuffle );
			}
			else if ( kind >= ast::expr::Intrinsic::eSubgroupShuffleUp1F
				&& kind <= ast::expr::Intrinsic::eSubgroupShuffleDown4D )
			{
				config.registerCapability( spv::CapabilityGroupNonUniformShuffleRelative );
			}
			else if ( kind >= ast::expr::Intrinsic::eSubgroupAdd1F
				&& kind <= ast::expr::Intrinsic::eSubgroupExclusiveXor4B )
			{
				config.registerCapability( spv::CapabilityGroupNonUniformArithmetic );
			}
			else if ( kind >= ast::expr::Intrinsic::eSubgroupClusterAdd1F
				&& kind <= ast::expr::Intrinsic::eSubgroupClusterXor4B )
			{
				config.registerCapability( spv::CapabilityGroupNonUniformArithmetic );
				config.registerCapability( spv::CapabilityGroupNonUniformClustered );
			}
			else if ( kind >= ast::expr::Intrinsic::eSubgroupQuadBroadcast1F
				&& kind <= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D )
			{
				config.registerCapability( spv::CapabilityGroupNonUniformQuad );
			}
			else if ( kind >= ast::expr::Intrinsic::eControlBarrier
				&& kind <= ast::expr::Intrinsic::eMemoryBarrier )
			{
				ast::type::Scope memory;
				bool isControlBarrier = ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );

				if ( isControlBarrier )
				{
					if ( expr->getArgList().size() < 3u )
					{
						throw std::runtime_error{ "Wrong number of parameters for a control barrier" };
					}

					memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
				}
				else
				{
					if ( expr->getArgList().size() < 2u )
					{
						throw std::runtime_error{ "Wrong number of parameters for a memory barrier" };
					}

					memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[0] ) );
				}

				if ( memory == ast::type::Scope::eSubgroup )
				{
					config.registerCapability( spv::CapabilitySubgroupBallotKHR );
				}
			}
		}
	}

	void ExprConfigFiller::submit( ast::expr::Expr * expr
		, ModuleConfig & config )
	{
		ExprConfigFiller vis{ config };
		expr->accept( &vis );

		if ( expr->isNonUniform() )
		{
			config.registerCapability( spv::CapabilityShaderNonUniform );
		}
	}

	ExprConfigFiller::ExprConfigFiller( ModuleConfig & config )
		: ast::expr::SimpleVisitor{}
		, m_config{ config }
	{
	}

	void ExprConfigFiller::doSubmit( ast::expr::Expr * expr )
	{
		submit( expr, m_config );
	}

	void ExprConfigFiller::doSubmit( ast::expr::ExprPtr const & expr )
	{
		doSubmit( expr.get() );
	}

	void ExprConfigFiller::visitUnaryExpr( ast::expr::Unary * expr )
	{
		checkType( expr, m_config );
		doSubmit( expr->getOperand() );
	}

	void ExprConfigFiller::visitBinaryExpr( ast::expr::Binary * expr )
	{
		checkType( expr, m_config );
		doSubmit( expr->getLHS() );
		doSubmit( expr->getRHS() );
	}

	void ExprConfigFiller::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		checkType( expr, m_config );

		if ( expr->getIdentifier() )
		{
			doSubmit( expr->getIdentifier() );
		}

		for ( auto & init : expr->getInitialisers() )
		{
			doSubmit( init );
		}
	}

	void ExprConfigFiller::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}
	}

	void ExprConfigFiller::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		checkType( expr, m_config );
		doSubmit( expr->getOuterExpr() );

		if ( expr->isBuiltin() )
		{
			m_config.addMbrBuiltin( expr->getOuterExpr()
				, expr->getMemberIndex()
				, *expr
				, 0u
				, ast::type::NotArray );
		}
	}

	void ExprConfigFiller::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		checkType( expr, m_config );
		doSubmit( expr->getFn() );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}
	}

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )
	{
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}

		auto kind = expr->getImageAccess();
		auto & config = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() )->getConfig();

		if ( config.dimension == ast::type::ImageDim::e1D )
		{
			m_config.registerCapability( spv::CapabilityImage1D );
		}
		else if ( config.dimension == ast::type::ImageDim::eRect )
		{
			m_config.registerCapability( spv::CapabilityImageRect );
		}
		else if ( config.dimension == ast::type::ImageDim::eBuffer )
		{
			m_config.registerCapability( spv::CapabilityImageBuffer );
		}

		if ( config.isArrayed )
		{
			if ( config.dimension == ast::type::ImageDim::eCube )
			{
				m_config.registerCapability( spv::CapabilityImageCubeArray );
			}
			else if ( config.isMS )
			{
				m_config.registerCapability( spv::CapabilityImageMSArray );
			}
		}

		if ( ( kind >= ast::expr::StorageImageAccess::eImageSize1DF
			&& kind <= ast::expr::StorageImageAccess::eImageSize2DMSArrayU )
			|| ( kind >= ast::expr::StorageImageAccess::eImageSamples2DMSF
				&& kind <= ast::expr::StorageImageAccess::eImageSamples2DMSArrayU ) )
		{
			m_config.registerCapability( spv::CapabilityImageQuery );
		}
		else if ( ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAdd1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF )
			|| ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicExchange1DF
				&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF ) )
		{
			m_config.registerCapability( spv::CapabilityAtomicFloat32AddEXT );
		}
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}

		auto kind = expr->getIntrinsic();

		if ( ( kind >= ast::expr::Intrinsic::eAtomicAddF
			&& kind <= ast::expr::Intrinsic::eAtomicAdd4H )
			|| ( kind >= ast::expr::Intrinsic::eAtomicExchangeF
				&& kind <= ast::expr::Intrinsic::eAtomicExchange4H ) )
		{
			m_config.registerCapability( spv::CapabilityAtomicFloat32AddEXT );
		}
		else if ( kind == ast::expr::Intrinsic::eHelperInvocation )
		{
			m_config.registerCapability( spv::CapabilityDemoteToHelperInvocation );
			// The extension is not optional, when using helperInvocation intrinsic.
			m_config.registerExtension( EXT_demote_to_helper_invocation );
		}
	}

	void ExprConfigFiller::visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )
	{
		checkType( expr, m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );

			if ( arg->isNonUniform() )
			{
				m_config.registerCapability( spv::CapabilitySampledImageArrayNonUniformIndexing );
			}
		}

		auto kind = expr->getCombinedImageAccess();

		if ( ( kind >= ast::expr::CombinedImageAccess::eTextureSize1DF
			&& kind <= ast::expr::CombinedImageAccess::eTextureSizeBufferU )
			|| ( kind >= ast::expr::CombinedImageAccess::eTextureQueryLod1DF
				&& kind <= ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU )
			|| ( kind >= ast::expr::CombinedImageAccess::eTextureQueryLevels1DF
				&& kind <= ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU ) )
		{
			m_config.registerCapability( spv::CapabilityImageQuery );
		}
		
		if ( ( kind >= ast::expr::CombinedImageAccess::eTextureGather2DShadowF
			&& kind <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectShadowF ) )
		{
			m_config.registerCapability( spv::CapabilityImageGatherExtended );
		}

		if ( getConstOffsets( kind ) == spv::ImageOperandsConstOffsetsMask )
		{
			m_config.registerCapability( spv::CapabilityImageGatherExtended );
		}

		IntrinsicConfig config;
		getSpirVConfig( kind, config );

		if ( config.offsetIndex )
		{
			assert( expr->getArgList().size() >= config.offsetIndex );
			bool constOffset = expr->getArgList()[config.offsetIndex - 1u]->isConstant();

			if ( getOffset( kind, constOffset ) == spv::ImageOperandsOffsetMask )
			{
				m_config.registerCapability( spv::CapabilityImageGatherExtended );
			}
		}
	}

	void ExprConfigFiller::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		checkType( expr, m_config );
	}

	void ExprConfigFiller::visitInitExpr( ast::expr::Init * expr )
	{
		checkType( expr, m_config );
		doSubmit( expr->getIdentifier() );
		doSubmit( expr->getInitialiser() );
	}

	void ExprConfigFiller::visitLiteralExpr( ast::expr::Literal * expr )
	{
		checkType( expr, m_config );
	}

	void ExprConfigFiller::visitQuestionExpr( ast::expr::Question * expr )
	{
		checkType( expr, m_config );
		doSubmit( expr->getCtrlExpr() );
		doSubmit( expr->getTrueExpr() );
		doSubmit( expr->getFalseExpr() );
	}

	void ExprConfigFiller::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		doSubmit( expr->getOperand() );
	}

	void ExprConfigFiller::visitSwitchCaseExpr( ast::expr::SwitchCase * expr )
	{
		doSubmit( expr->getLabel() );
	}

	void ExprConfigFiller::visitSwitchTestExpr( ast::expr::SwitchTest * expr )
	{
		doSubmit( expr->getValue() );
	}

	void ExprConfigFiller::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		checkType( expr, m_config );
		doSubmit( expr->getOuterExpr() );
	}
}
