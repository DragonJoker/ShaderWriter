/*
See LICENSE file in root folder
*/
#include "GlslExprConfigFiller.hpp"

#include "GlslHelpers.hpp"
#include "GlslCombinedImageAccessConfig.hpp"

namespace glsl
{
	namespace
	{
		void checkBuiltin( ast::Builtin builtin
			, IntrinsicsConfig & config )
		{
			switch ( builtin )
			{
			case ast::Builtin::eGlobalInvocationID:
			case ast::Builtin::eLocalInvocationID:
			case ast::Builtin::eLocalInvocationIndex:
			case ast::Builtin::eNumWorkGroups:
			case ast::Builtin::eWorkGroupID:
				if ( config.stage == ast::ShaderStage::eCompute )
				{
					config.requiredExtensions.insert( ARB_compute_shader );
				}
				break;
			case ast::Builtin::eInvocationID:
				if ( config.stage == ast::ShaderStage::eTessellationControl
					|| config.stage == ast::ShaderStage::eTessellationEvaluation )
				{
					config.requiredExtensions.insert( ARB_tessellation_shader );
				}
				else
				{
					config.requiredExtensions.insert( ARB_gpu_shader5 );
				}
				break;
			case ast::Builtin::ePrimitiveIDIn:
				if ( config.stage == ast::ShaderStage::eTessellationControl
					|| config.stage == ast::ShaderStage::eTessellationEvaluation )
				{
					config.requiredExtensions.insert( ARB_tessellation_shader );
				}
				else
				{
					config.requiredExtensions.insert( NV_gpu_shader5 );
				}
				break;
			case ast::Builtin::eTessLevelInner:
			case ast::Builtin::eTessLevelOuter:
			case ast::Builtin::ePatchVerticesIn:
			case ast::Builtin::eTessCoord:
				config.requiredExtensions.insert( ARB_tessellation_shader );
				break;
			case ast::Builtin::eDrawIndex:
			case ast::Builtin::eBaseInstance:
			case ast::Builtin::eBaseVertex:
				config.requiredExtensions.insert( ARB_shader_draw_parameters );
				break;
			case ast::Builtin::eSampleID:
			case ast::Builtin::eSamplePosition:
				config.requiredExtensions.insert( ARB_sample_shading );
				break;
			case ast::Builtin::eViewportIndex:
				config.requiredExtensions.insert( ARB_viewport_array );
				if ( config.stage != ast::ShaderStage::eGeometry )
				{
					config.requiredExtensions.insert( ARB_fragment_layer_viewport );
				}
				break;
			case ast::Builtin::eSubgroupSize:
			case ast::Builtin::eSubgroupMaxSize:
			case ast::Builtin::eNumSubgroups:
			case ast::Builtin::eSubgroupID:
			case ast::Builtin::eSubgroupLocalInvocationID:
				config.requiredExtensions.insert( KHR_shader_subgroup_basic );
				break;
			case ast::Builtin::eSubgroupEqMask:
			case ast::Builtin::eSubgroupGeMask:
			case ast::Builtin::eSubgroupGtMask:
			case ast::Builtin::eSubgroupLeMask:
			case ast::Builtin::eSubgroupLtMask:
				config.requiredExtensions.insert( KHR_shader_subgroup_ballot );
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
		, IntrinsicsConfig & config )
	{
		ExprConfigFiller vis{ config };
		expr->accept( &vis );
	}

	ExprConfigFiller::ExprConfigFiller( IntrinsicsConfig & config )
		: ast::expr::SimpleVisitor{}
		, m_config{ config }
	{
	}

	void ExprConfigFiller::doSubmit( ast::expr::Expr * expr )
	{
		expr->accept( this );

		if ( expr->isNonUniform() )
		{
			m_config.requiredExtensions.insert( EXT_nonuniform_qualifier );
		}
	}

	void ExprConfigFiller::doSubmit( ast::expr::ExprPtr const & expr )
	{
		doSubmit( expr.get() );
	}

	void ExprConfigFiller::visitUnaryExpr( ast::expr::Unary * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getOperand() );
	}

	void ExprConfigFiller::visitBinaryExpr( ast::expr::Binary * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getLHS() );
		doSubmit( expr->getRHS() );
	}

	void ExprConfigFiller::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		checkType( expr->getType(), m_config );

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
		checkType( expr->getType(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}
	}

	void ExprConfigFiller::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		checkType( expr->getType(), m_config );
		checkBuiltin( *expr->getOuterType(), expr->getMemberIndex(), m_config );
		doSubmit( expr->getOuterExpr() );
	}

	void ExprConfigFiller::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getFn() );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		checkType( expr->getType(), m_config );

		if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupElect )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_basic );
		}
		else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupAll
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupAllEqual4D )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_vote );
		}
		else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupBroadcast1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupBallotFindMSB )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_ballot );
		}
		else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupShuffle1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupShuffleXor4D )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_shuffle );
		}
		else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupShuffleUp1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupShuffleDown4D )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_shuffle_relative );
		}
		else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupAdd1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupExclusiveXor4B )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_arithmetic );
		}
		else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupClusterAdd1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupClusterXor4B )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_arithmetic );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_clustered );
		}
		else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadBroadcast1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D )
		{
			m_config.requiredExtensions.insert( KHR_vulkan_glsl );
			m_config.requiredExtensions.insert( KHR_shader_subgroup );
			m_config.requiredExtensions.insert( KHR_shader_subgroup_quad );
		}
		else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier
			|| expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
		{
			ast::type::Scope memory;
			ast::type::MemorySemantics semantics;
			bool isControlBarrier = ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );

			if ( isControlBarrier )
			{
				if ( expr->getArgList().size() < 3u )
				{
					throw std::runtime_error{ "Wrong number of parameters for a control barrier" };
				}

				memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
				semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[2] ) );
			}
			else
			{
				if ( expr->getArgList().size() < 2u )
				{
					throw std::runtime_error{ "Wrong number of parameters for a memory barrier" };
				}

				memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[0] ) );
				semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
			}

			if ( memory == ast::type::Scope::eWorkgroup )
			{
				if ( checkAllMemoryBarrier( semantics ) )
				{
					m_config.requiredExtensions.insert( ARB_compute_shader );
				}
				else
				{
					m_config.requiredExtensions.insert( ARB_compute_shader );
				}
			}
			else if ( memory == ast::type::Scope::eSubgroup )
			{
				m_config.requiredExtensions.insert( KHR_vulkan_glsl );
				m_config.requiredExtensions.insert( KHR_shader_subgroup_basic );
			}
			else
			{
				if ( checkAllMemoryBarrier( semantics ) )
				{
					m_config.requiredExtensions.insert( ARB_compute_shader );
				}
				else if ( checkBufferMemoryBarrier( semantics ) )
				{
					m_config.requiredExtensions.insert( ARB_compute_shader );
				}
				else if ( checkSharedMemoryBarrier( semantics ) )
				{
					m_config.requiredExtensions.insert( ARB_compute_shader );
				}
				else if ( checkImageMemoryBarrier( semantics ) )
				{
					m_config.requiredExtensions.insert( ARB_compute_shader );
				}
				else
				{
					m_config.requiredExtensions.insert( ARB_compute_shader );
				}
			}
		}

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
		case ast::expr::Intrinsic::eDFdxCoarse1:
		case ast::expr::Intrinsic::eDFdxCoarse2:
		case ast::expr::Intrinsic::eDFdxCoarse3:
		case ast::expr::Intrinsic::eDFdxCoarse4:
		case ast::expr::Intrinsic::eDFdxFine1:
		case ast::expr::Intrinsic::eDFdxFine2:
		case ast::expr::Intrinsic::eDFdxFine3:
		case ast::expr::Intrinsic::eDFdxFine4:
		case ast::expr::Intrinsic::eDFdyCoarse1:
		case ast::expr::Intrinsic::eDFdyCoarse2:
		case ast::expr::Intrinsic::eDFdyCoarse3:
		case ast::expr::Intrinsic::eDFdyCoarse4:
		case ast::expr::Intrinsic::eDFdyFine1:
		case ast::expr::Intrinsic::eDFdyFine2:
		case ast::expr::Intrinsic::eDFdyFine3:
		case ast::expr::Intrinsic::eDFdyFine4:
			m_config.requiredExtensions.insert( ARB_derivative_control );
			break;
		case ast::expr::Intrinsic::eUaddCarry1:
		case ast::expr::Intrinsic::eUaddCarry2:
		case ast::expr::Intrinsic::eUaddCarry3:
		case ast::expr::Intrinsic::eUaddCarry4:
		case ast::expr::Intrinsic::eUsubBorrow1:
		case ast::expr::Intrinsic::eUsubBorrow2:
		case ast::expr::Intrinsic::eUsubBorrow3:
		case ast::expr::Intrinsic::eUsubBorrow4:
		case ast::expr::Intrinsic::eUmulExtended1:
		case ast::expr::Intrinsic::eUmulExtended2:
		case ast::expr::Intrinsic::eUmulExtended3:
		case ast::expr::Intrinsic::eUmulExtended4:
		case ast::expr::Intrinsic::eImulExtended1:
		case ast::expr::Intrinsic::eImulExtended2:
		case ast::expr::Intrinsic::eImulExtended3:
		case ast::expr::Intrinsic::eImulExtended4:
		case ast::expr::Intrinsic::eBitfieldExtract1I:
		case ast::expr::Intrinsic::eBitfieldExtract2I:
		case ast::expr::Intrinsic::eBitfieldExtract3I:
		case ast::expr::Intrinsic::eBitfieldExtract4I:
		case ast::expr::Intrinsic::eBitfieldExtract1U:
		case ast::expr::Intrinsic::eBitfieldExtract2U:
		case ast::expr::Intrinsic::eBitfieldExtract3U:
		case ast::expr::Intrinsic::eBitfieldExtract4U:
		case ast::expr::Intrinsic::eBitfieldInsert1I:
		case ast::expr::Intrinsic::eBitfieldInsert2I:
		case ast::expr::Intrinsic::eBitfieldInsert3I:
		case ast::expr::Intrinsic::eBitfieldInsert4I:
		case ast::expr::Intrinsic::eBitfieldInsert1U:
		case ast::expr::Intrinsic::eBitfieldInsert2U:
		case ast::expr::Intrinsic::eBitfieldInsert3U:
		case ast::expr::Intrinsic::eBitfieldInsert4U:
		case ast::expr::Intrinsic::eBitfieldReverse1I:
		case ast::expr::Intrinsic::eBitfieldReverse2I:
		case ast::expr::Intrinsic::eBitfieldReverse3I:
		case ast::expr::Intrinsic::eBitfieldReverse4I:
		case ast::expr::Intrinsic::eBitfieldReverse1U:
		case ast::expr::Intrinsic::eBitfieldReverse2U:
		case ast::expr::Intrinsic::eBitfieldReverse3U:
		case ast::expr::Intrinsic::eBitfieldReverse4U:
		case ast::expr::Intrinsic::eBitCount1I:
		case ast::expr::Intrinsic::eBitCount2I:
		case ast::expr::Intrinsic::eBitCount3I:
		case ast::expr::Intrinsic::eBitCount4I:
		case ast::expr::Intrinsic::eBitCount1U:
		case ast::expr::Intrinsic::eBitCount2U:
		case ast::expr::Intrinsic::eBitCount3U:
		case ast::expr::Intrinsic::eBitCount4U:
		case ast::expr::Intrinsic::eFindLSB1I:
		case ast::expr::Intrinsic::eFindLSB2I:
		case ast::expr::Intrinsic::eFindLSB3I:
		case ast::expr::Intrinsic::eFindLSB4I:
		case ast::expr::Intrinsic::eFindLSB1U:
		case ast::expr::Intrinsic::eFindLSB2U:
		case ast::expr::Intrinsic::eFindLSB3U:
		case ast::expr::Intrinsic::eFindLSB4U:
		case ast::expr::Intrinsic::eFindMSB1I:
		case ast::expr::Intrinsic::eFindMSB2I:
		case ast::expr::Intrinsic::eFindMSB3I:
		case ast::expr::Intrinsic::eFindMSB4I:
		case ast::expr::Intrinsic::eFindMSB1U:
		case ast::expr::Intrinsic::eFindMSB2U:
		case ast::expr::Intrinsic::eFindMSB3U:
		case ast::expr::Intrinsic::eFindMSB4U:
		case ast::expr::Intrinsic::eFrexp1F:
		case ast::expr::Intrinsic::eFrexp2F:
		case ast::expr::Intrinsic::eFrexp3F:
		case ast::expr::Intrinsic::eFrexp4F:
		case ast::expr::Intrinsic::eFrexp1D:
		case ast::expr::Intrinsic::eFrexp2D:
		case ast::expr::Intrinsic::eFrexp3D:
		case ast::expr::Intrinsic::eFrexp4D:
		case ast::expr::Intrinsic::eLdexp1F:
		case ast::expr::Intrinsic::eLdexp2F:
		case ast::expr::Intrinsic::eLdexp3F:
		case ast::expr::Intrinsic::eLdexp4F:
		case ast::expr::Intrinsic::eLdexp1D:
		case ast::expr::Intrinsic::eLdexp2D:
		case ast::expr::Intrinsic::eLdexp3D:
		case ast::expr::Intrinsic::eLdexp4D:
		case ast::expr::Intrinsic::ePackUnorm2x16:
		case ast::expr::Intrinsic::ePackSnorm4x8:
		case ast::expr::Intrinsic::ePackUnorm4x8:
		case ast::expr::Intrinsic::eUnpackUnorm2x16:
		case ast::expr::Intrinsic::eUnpackSnorm4x8:
		case ast::expr::Intrinsic::eUnpackUnorm4x8:
		case ast::expr::Intrinsic::eInterpolateAtCentroid1:
		case ast::expr::Intrinsic::eInterpolateAtCentroid2:
		case ast::expr::Intrinsic::eInterpolateAtCentroid3:
		case ast::expr::Intrinsic::eInterpolateAtCentroid4:
		case ast::expr::Intrinsic::eInterpolateAtSample1:
		case ast::expr::Intrinsic::eInterpolateAtSample2:
		case ast::expr::Intrinsic::eInterpolateAtSample3:
		case ast::expr::Intrinsic::eInterpolateAtSample4:
		case ast::expr::Intrinsic::eInterpolateAtOffset1:
		case ast::expr::Intrinsic::eInterpolateAtOffset2:
		case ast::expr::Intrinsic::eInterpolateAtOffset3:
		case ast::expr::Intrinsic::eInterpolateAtOffset4:
			m_config.requiredExtensions.insert( ARB_gpu_shader5 );
			break;
		case ast::expr::Intrinsic::ePackHalf2x16:
		case ast::expr::Intrinsic::ePackSnorm2x16:
		case ast::expr::Intrinsic::eUnpackHalf2x16:
		case ast::expr::Intrinsic::eUnpackSnorm2x16:
			m_config.requiredExtensions.insert( ARB_shading_language_packing );
			break;
		case ast::expr::Intrinsic::eAtomicAdd2H:
		case ast::expr::Intrinsic::eAtomicAdd4H:
		case ast::expr::Intrinsic::eAtomicExchange2H:
		case ast::expr::Intrinsic::eAtomicExchange4H:
			m_config.requiredExtensions.insert( NV_shader_atomic_fp16_vector );
			[[fallthrough]];
		case ast::expr::Intrinsic::eAtomicAddF:
		case ast::expr::Intrinsic::eAtomicExchangeF:
			m_config.requiredExtensions.insert( NV_shader_atomic_float );
			break;
		case ast::expr::Intrinsic::eTraceRay:
			m_config.requiresRayDescDecl = true;
			break;
		case ast::expr::Intrinsic::eHelperInvocation:
			break;
		default:
			break;
		}

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}
	}

	void ExprConfigFiller::visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )
	{
		checkType( expr->getType(), m_config );
		getGlslConfig( expr->getCombinedImageAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}
	}

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )
	{
		checkType( expr->getType(), m_config );

		if ( ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAdd1DF
				&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF )
			|| ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicExchange1DF
				&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF ) )
		{
			m_config.requiredExtensions.insert( NV_shader_atomic_float );

			for ( auto & arg : expr->getArgList() )
			{
				if ( ast::type::getComponentType( arg->getType() ) == ast::type::Kind::eHalf )
				{
					m_config.requiredExtensions.insert( NV_shader_atomic_fp16_vector );
				}
			}
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageSize1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageSize2DMSArrayU )
		{
			m_config.requiredExtensions.insert( ARB_shader_image_size );
		}

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg );
		}
	}

	void ExprConfigFiller::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		checkType( expr->getType(), m_config );
		checkBuiltin( *expr->getVariable(), m_config );
	}

	void ExprConfigFiller::visitInitExpr( ast::expr::Init * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getIdentifier() );
		doSubmit( expr->getInitialiser() );
	}

	void ExprConfigFiller::visitLiteralExpr( ast::expr::Literal * expr )
	{
		checkType( expr->getType(), m_config );
	}

	void ExprConfigFiller::visitQuestionExpr( ast::expr::Question * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getCtrlExpr() );
		doSubmit( expr->getTrueExpr() );
		doSubmit( expr->getFalseExpr() );
	}

	void ExprConfigFiller::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getOperand() );
	}

	void ExprConfigFiller::visitSwitchCaseExpr( ast::expr::SwitchCase * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getLabel() );
	}

	void ExprConfigFiller::visitSwitchTestExpr( ast::expr::SwitchTest * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getValue() );
	}

	void ExprConfigFiller::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		checkType( expr->getType(), m_config );
		doSubmit( expr->getOuterExpr() );
	}
}
