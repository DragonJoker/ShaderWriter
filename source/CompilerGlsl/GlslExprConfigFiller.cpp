/*
See LICENSE file in root folder
*/
#include "GlslExprConfigFiller.hpp"

#include "GlslHelpers.hpp"
#include "GlslTextureAccessConfig.hpp"
#include "GlslSampledImageAccessConfig.hpp"

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

	void ExprConfigFiller::doSubmit( ast::expr::Expr * expr )
	{
		expr->accept( this );

		if ( expr->isNonUniform() )
		{
			m_config.requiredExtensions.insert( EXT_nonuniform_qualifier );
		}
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
			doSubmit( init.get() );
		}
	}

	void ExprConfigFiller::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		checkType( expr->getType(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg.get() );
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
			doSubmit( arg.get() );
		}
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		checkType( expr->getType(), m_config );

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
			doSubmit( arg.get() );
		}
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		checkType( expr->getType(), m_config );
		getGlslConfig( expr->getTextureAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg.get() );
		}
	}

	void ExprConfigFiller::visitSampledImageAccessCallExpr( ast::expr::SampledImageAccessCall * expr )
	{
		m_config.requiredExtensions.insert( KHR_vulkan_glsl );
		m_config.requiresSeparateSamplers = true;
		checkType( expr->getType(), m_config );
		getGlslConfig( expr->getSampledImageAccess(), m_config );

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg.get() );
		}
	}

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		checkType( expr->getType(), m_config );

		if ( ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicAdd1DF
				&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayF )
			|| ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicExchange1DF
				&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayF ) )
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
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageSize1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageSize2DMSArrayU )
		{
			m_config.requiredExtensions.insert( ARB_shader_image_size );
		}

		for ( auto & arg : expr->getArgList() )
		{
			doSubmit( arg.get() );
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
