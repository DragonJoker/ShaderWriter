/*
See LICENSE file in root folder
*/
#include "SpirvStmtConfigFiller.hpp"

#include "SpirvExprConfigFiller.hpp"
#include "SpirvHelpers.hpp"
#include "SpirvImageAccessNames.hpp"
#include "SpirvIntrinsicNames.hpp"
#include "SpirvTextureAccessNames.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

#include <stdexcept>

namespace spirv
{
	namespace
	{
		void checkBuiltin( ast::Builtin builtin
			, ModuleConfig & config )
		{
			switch ( builtin )
			{
			case ast::Builtin::ePosition:
			case ast::Builtin::ePointSize:
				config.requiredCapabilities.insert( spv::CapabilityShader );
				break;
			case ast::Builtin::eClipDistance:
				config.requiredCapabilities.insert( spv::CapabilityClipDistance );
				break;
			case ast::Builtin::eCullDistance:
				config.requiredCapabilities.insert( spv::CapabilityCullDistance );
				break;
			case ast::Builtin::ePrimitiveID:
			case ast::Builtin::ePrimitiveIDIn:
			case ast::Builtin::eInvocationID:
				// Tessellation or Geometry
				break;
			case ast::Builtin::eLayer:
				config.requiredCapabilities.insert( spv::CapabilityGeometry );
				break;
			case ast::Builtin::eViewportIndex:
				config.requiredCapabilities.insert( spv::CapabilityMultiViewport );
				break;
			case ast::Builtin::eTessLevelOuter:
			case ast::Builtin::eTessLevelInner:
			case ast::Builtin::eTessCoord:
			case ast::Builtin::ePatchVertices:
			case ast::Builtin::ePatchVerticesIn:
				config.requiredCapabilities.insert( spv::CapabilityTessellation );
				break;
			case ast::Builtin::eFragCoord:
			case ast::Builtin::ePointCoord:
			case ast::Builtin::eFrontFacing:
				config.requiredCapabilities.insert( spv::CapabilityShader );
				break;
			case ast::Builtin::eSampleID:
			case ast::Builtin::eSamplePosition:
				config.requiredCapabilities.insert( spv::CapabilitySampleRateShading );
				break;
			case ast::Builtin::eSampleMask:
			case ast::Builtin::eSampleMaskIn:
			case ast::Builtin::eFragDepth:
			case ast::Builtin::eHelperInvocation:
				config.requiredCapabilities.insert( spv::CapabilityShader );
				break;
			case ast::Builtin::eNumWorkGroups:
				break;
			case ast::Builtin::eWorkGroupSize:
				break;
			case ast::Builtin::eWorkGroupID:
				break;
			case ast::Builtin::eLocalInvocationID:
				break;
			case ast::Builtin::eGlobalInvocationID:
				break;
			case ast::Builtin::eLocalInvocationIndex:
				break;
			case ast::Builtin::eWorkDim:
			case ast::Builtin::eGlobalSize:
			case ast::Builtin::eEnqueuedWorkgroupSize:
			case ast::Builtin::eGlobalLinearID:
			case ast::Builtin::eSubgroupSize:
			case ast::Builtin::eSubgroupMaxSize:
			case ast::Builtin::eNumSubgroups:
			case ast::Builtin::eNumEnqueuedSubgroups:
			case ast::Builtin::eSubgroupID:
			case ast::Builtin::eSubgroupLocalInvocationID:
				config.requiredCapabilities.insert( spv::CapabilityKernel );
				break;
			case ast::Builtin::eVertexIndex:
			case ast::Builtin::eInstanceIndex:
				config.requiredCapabilities.insert( spv::CapabilityShader );
				break;
			case ast::Builtin::eSubgroupEqMaskKHR:
			case ast::Builtin::eSubgroupGeMaskKHR:
			case ast::Builtin::eSubgroupGtMaskKHR:
			case ast::Builtin::eSubgroupLeMaskKHR:
			case ast::Builtin::eSubgroupLtMaskKHR:
				config.requiredCapabilities.insert( spv::CapabilitySubgroupBallotKHR );
				break;
			case ast::Builtin::eBaseVertex:
			case ast::Builtin::eBaseInstance:
			case ast::Builtin::eDrawIndex:
				config.requiredCapabilities.insert( spv::CapabilityDrawParameters );
				break;
			case ast::Builtin::eDeviceIndex:
				config.requiredCapabilities.insert( spv::CapabilityDeviceGroup );
				break;
			case ast::Builtin::eViewIndex:
				config.requiredCapabilities.insert( spv::CapabilityMultiView );
				break;
			case ast::Builtin::eBaryCoordNoPerspAMD:
				break;
			case ast::Builtin::eBaryCoordNoPerspCentroidAMD:
				break;
			case ast::Builtin::eBaryCoordNoPerspSampleAMD:
				break;
			case ast::Builtin::eBaryCoordSmoothAMD:
				break;
			case ast::Builtin::eBaryCoordSmoothCentroidAMD:
				break;
			case ast::Builtin::eBaryCoordSmoothSampleAMD:
				break;
			case ast::Builtin::eBaryCoordPullModelAMD:
				break;
			case ast::Builtin::eFragStencilRefEXT:
				config.requiredCapabilities.insert( spv::CapabilityStencilExportEXT );
				break;
			case ast::Builtin::eViewportMaskNV:
				config.requiredCapabilities.insert( spv::CapabilityShaderViewportMaskNV );
				break;
			case ast::Builtin::eSecondaryPositionNV:
			case ast::Builtin::eSecondaryViewportMaskNV:
				config.requiredCapabilities.insert( spv::CapabilityShaderStereoViewNV );
				break;
			case ast::Builtin::ePositionPerViewNV:
			case ast::Builtin::eViewportMaskPerViewNV:
				config.requiredCapabilities.insert( spv::CapabilityPerViewAttributesNV );
				break;
			default:
				break;
			}
		}
	}

	void StmtConfigFiller::submit( ast::stmt::Container * cont
		, ModuleConfig & moduleConfig )
	{
		StmtConfigFiller vis{ moduleConfig };
		cont->accept( &vis );
	}

	StmtConfigFiller::StmtConfigFiller( ModuleConfig & result )
		: m_result{ result }
	{
	}

	void StmtConfigFiller::visitBreakStmt( ast::stmt::Break * cont )
	{
	}

	void StmtConfigFiller::visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitContainerStmt( ast::stmt::Container * cont )
	{
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtConfigFiller::visitContinueStmt( ast::stmt::Continue * cont )
	{
	}

	void StmtConfigFiller::visitDiscardStmt( ast::stmt::Discard * stmt )
	{
	}

	void StmtConfigFiller::visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitCommentStmt( ast::stmt::Comment * stmt )
	{
	}

	void StmtConfigFiller::visitCompoundStmt( ast::stmt::Compound * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitDoWhileStmt( ast::stmt::DoWhile * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseStmt( ast::stmt::Else * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitForStmt( ast::stmt::For * stmt )
	{
		ExprConfigFiller::submit( stmt->getInitExpr(), m_result );
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		ExprConfigFiller::submit( stmt->getIncrExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitFragmentLayout( ast::stmt::FragmentLayout * stmt )
	{
	}

	void StmtConfigFiller::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getFlags() )
		{
			m_result.initialise( *stmt );
		}

		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitIfStmt( ast::stmt::If * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );

		for ( auto & elseIf : stmt->getElseIfList() )
		{
			elseIf->accept( this );
		}

		if ( stmt->getElse() )
		{
			stmt->getElse()->accept( this );
		}
	}

	void StmtConfigFiller::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		auto imgType = std::static_pointer_cast< ast::type::Image >( ast::type::getNonArrayType( stmt->getVariable()->getType() ) );

		if ( imgType->getConfig().dimension == ast::type::ImageDim::e1D )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampled1D );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eRect )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledRect );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eBuffer )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledBuffer );
		}

		if ( imgType->getConfig().isMS )
		{
			m_result.requiredCapabilities.insert( spv::CapabilityStorageImageMultisample );
		}

		switch ( imgType->getConfig().format )
		{
		case ast::type::ImageFormat::eRg32f:
		case ast::type::ImageFormat::eRg16f:
		case ast::type::ImageFormat::eR32f:
		case ast::type::ImageFormat::eR16f:
		case ast::type::ImageFormat::eRg32i:
		case ast::type::ImageFormat::eRg16i:
		case ast::type::ImageFormat::eRg8i:
		case ast::type::ImageFormat::eR32i:
		case ast::type::ImageFormat::eR16i:
		case ast::type::ImageFormat::eR8i:
		case ast::type::ImageFormat::eRg32u:
		case ast::type::ImageFormat::eRg16u:
		case ast::type::ImageFormat::eRg8u:
		case ast::type::ImageFormat::eR32u:
		case ast::type::ImageFormat::eR16u:
		case ast::type::ImageFormat::eR8u:
			m_result.requiredCapabilities.insert( spv::CapabilityStorageImageExtendedFormats );
			break;
		default:
			break;
		}
	}

	void StmtConfigFiller::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		auto var = stmt->getVariable();

		if ( !var->isShaderConstant() )
		{
			if ( var->isShaderInput() )
			{
				m_result.addPendingInput( var
					, stmt->getLocation() );
			}

			if ( var->isShaderOutput() )
			{
				m_result.addPendingOutput( var
					, stmt->getLocation() );
			}
		}

		if ( var->isPatch() )
		{
			m_result.requiredCapabilities.insert( spv::CapabilityTessellation );
		}

		if ( var->isPerSample() )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampleRateShading );
		}

		if ( var->isGeometryStream() )
		{
			m_result.requiredCapabilities.insert( spv::CapabilityGeometryStreams );
		}
	}

	void StmtConfigFiller::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
	}

	void StmtConfigFiller::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
	}

	void StmtConfigFiller::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
	}

	void StmtConfigFiller::visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )
	{
	}

	void StmtConfigFiller::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
	}

	void StmtConfigFiller::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
	}

	void StmtConfigFiller::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
	}

	void StmtConfigFiller::visitReturnStmt( ast::stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			ExprConfigFiller::submit( stmt->getExpr(), m_result );
		}
	}

	void StmtConfigFiller::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		auto imgType = std::static_pointer_cast< ast::type::SampledImage >( ast::type::getNonArrayType( stmt->getVariable()->getType() ) );

		if ( imgType->getConfig().dimension == ast::type::ImageDim::e1D )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampled1D );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eRect )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledRect );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eBuffer )
		{
			m_result.requiredCapabilities.insert( spv::CapabilitySampledBuffer );
		}

		switch ( imgType->getConfig().format )
		{
		case ast::type::ImageFormat::eRg32f:
		case ast::type::ImageFormat::eRg16f:
		case ast::type::ImageFormat::eR32f:
		case ast::type::ImageFormat::eR16f:
		case ast::type::ImageFormat::eRg32i:
		case ast::type::ImageFormat::eRg16i:
		case ast::type::ImageFormat::eRg8i:
		case ast::type::ImageFormat::eR32i:
		case ast::type::ImageFormat::eR16i:
		case ast::type::ImageFormat::eR8i:
		case ast::type::ImageFormat::eRg32u:
		case ast::type::ImageFormat::eRg16u:
		case ast::type::ImageFormat::eRg8u:
		case ast::type::ImageFormat::eR32u:
		case ast::type::ImageFormat::eR16u:
		case ast::type::ImageFormat::eR8u:
			m_result.requiredCapabilities.insert( spv::CapabilityStorageImageExtendedFormats );
			break;
		default:
			break;
		}
	}

	void StmtConfigFiller::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
	}

	void StmtConfigFiller::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		doTraverseType( stmt->getSsboInstance()->getType() );
	}

	void StmtConfigFiller::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		ExprConfigFiller::submit( stmt->getExpr(), m_result );
		doTraverseType( stmt->getExpr()->getType() );
	}

	void StmtConfigFiller::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		ExprConfigFiller::submit( stmt->getTestExpr()->getValue(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		doTraverseType( stmt->getVariable()->getType() );
	}

	void StmtConfigFiller::visitWhileStmt( ast::stmt::While * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		ExprConfigFiller::submit( preproc->getExpr(), m_result );
	}

	void StmtConfigFiller::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		ExprConfigFiller::submit( preproc->getCtrlExpr(), m_result );
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocElse( ast::stmt::PreprocElse * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
	}

	void StmtConfigFiller::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
	}

	void StmtConfigFiller::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
		ExprConfigFiller::submit( preproc->getCtrlExpr(), m_result );
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
	}

	void StmtConfigFiller::doTraverseType( ast::type::TypePtr type )
	{
		type = ast::type::getNonArrayType( type );
		auto kind = type->getKind();

		if ( kind == ast::type::Kind::eStruct )
		{
			doTraverseType( std::static_pointer_cast< ast::type::Struct >( type ) );
		}
		else
		{
			kind = getScalarType( kind );

			if ( kind == ast::type::Kind::eDouble )
			{
				m_result.requiredCapabilities.insert( spv::CapabilityFloat64 );
			}
		}
	}

	void StmtConfigFiller::doTraverseType( ast::type::StructPtr type )
	{
		for ( auto & member : *type )
		{
			doTraverseType( member.type );
		}
	}
}
