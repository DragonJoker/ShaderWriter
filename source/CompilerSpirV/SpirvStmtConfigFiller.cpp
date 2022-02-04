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

#include <ShaderAST/Type/TypeTexture.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

#include <stdexcept>

namespace spirv
{
	void StmtConfigFiller::submit( ast::stmt::Container * cont
		, ModuleConfig & moduleConfig )
	{
		StmtConfigFiller vis{ moduleConfig };
		cont->accept( &vis );
	}

	StmtConfigFiller::StmtConfigFiller( ModuleConfig & result )
		: m_result{ result }
	{
		switch ( m_result.stage )
		{
		case ast::ShaderStage::eVertex:
			m_result.registerCapability( spv::CapabilityShader );
			break;
		case ast::ShaderStage::eTessellationControl:
		case ast::ShaderStage::eTessellationEvaluation:
			m_result.registerCapability( spv::CapabilityShader );
			m_result.registerCapability( spv::CapabilityTessellation );
			break;
		case ast::ShaderStage::eGeometry:
			m_result.registerCapability( spv::CapabilityShader );
			m_result.registerCapability( spv::CapabilityGeometry );
			break;
		case ast::ShaderStage::eFragment:
			m_result.registerCapability( spv::CapabilityShader );
			break;
		case ast::ShaderStage::eCompute:
			m_result.registerCapability( spv::CapabilityShader );
			break;
		case ast::ShaderStage::eTask:
		case ast::ShaderStage::eMesh:
			m_result.registerCapability( spv::CapabilityMeshShadingNV );
			break;
		case ast::ShaderStage::eRayGeneration:
		case ast::ShaderStage::eRayClosestHit:
		case ast::ShaderStage::eRayMiss:
		case ast::ShaderStage::eRayIntersection:
		case ast::ShaderStage::eRayAnyHit:
		case ast::ShaderStage::eCallable:
			m_result.registerCapability( spv::CapabilityShader );
			m_result.registerCapability( spv::CapabilityRayTracingKHR );
			break;
		}
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

	void StmtConfigFiller::visitDemoteStmt( ast::stmt::Demote * stmt )
	{
		m_result.registerCapability( spv::CapabilityDemoteToHelperInvocation );
	}

	void StmtConfigFiller::visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )
	{
		m_result.registerExtension( KHR_terminate_invocation, true );
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

	void StmtConfigFiller::visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )
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

	void StmtConfigFiller::visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * cont )
	{
		if ( isRayTraceStage( m_result.stage ) )
		{
			m_result.registerCapability( spv::CapabilityRayTracingKHR );
		}
		else
		{
			m_result.registerCapability( spv::CapabilityRayQueryKHR );
		}
	}

	void StmtConfigFiller::visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )
	{
		m_result.addressingModel = spv::AddressingModelPhysicalStorageBuffer64;
		m_result.registerCapability( spv::CapabilityPhysicalStorageBufferAddresses );
	}

	void StmtConfigFiller::visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )
	{
		if ( isRayTraceStage( m_result.stage ) )
		{
			m_result.registerCapability( spv::CapabilityRayTracingKHR );
		}
		else
		{
			m_result.registerCapability( spv::CapabilityRayQueryKHR );
		}
	}

	void StmtConfigFiller::visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )
	{
		if ( isRayTraceStage( m_result.stage ) )
		{
			m_result.registerCapability( spv::CapabilityRayTracingKHR );
		}
		else
		{
			m_result.registerCapability( spv::CapabilityRayQueryKHR );
		}
	}

	void StmtConfigFiller::visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )
	{
		if ( isRayTraceStage( m_result.stage ) )
		{
			m_result.registerCapability( spv::CapabilityRayTracingKHR );
		}
		else
		{
			m_result.registerCapability( spv::CapabilityRayQueryKHR );
		}
	}

	void StmtConfigFiller::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		auto imgType = std::static_pointer_cast< ast::type::Image >( ast::type::getNonArrayType( stmt->getVariable()->getType() ) );

		if ( imgType->getConfig().dimension == ast::type::ImageDim::e1D )
		{
			m_result.registerCapability( spv::CapabilitySampled1D );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eRect )
		{
			m_result.registerCapability( spv::CapabilitySampledRect );
		}

		if ( imgType->getConfig().dimension == ast::type::ImageDim::eBuffer )
		{
			m_result.registerCapability( spv::CapabilitySampledBuffer );
		}

		if ( imgType->getConfig().isMS )
		{
			m_result.registerCapability( spv::CapabilityStorageImageMultisample );
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
			m_result.registerCapability( spv::CapabilityStorageImageExtendedFormats );
			break;
		default:
			break;
		}
	}

	void StmtConfigFiller::visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )
	{
		if ( isRayTraceStage( m_result.stage ) )
		{
			m_result.registerCapability( spv::CapabilityRayTracingKHR );
		}
		else
		{
			m_result.registerCapability( spv::CapabilityRayQueryKHR );
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
			m_result.registerCapability( spv::CapabilityTessellation );
		}

		if ( var->isPerSample() )
		{
			m_result.registerCapability( spv::CapabilitySampleRateShading );
		}

		if ( var->isGeometryStream() )
		{
			m_result.registerCapability( spv::CapabilityGeometryStreams );
		}

		doTraverseType( var->getType() );
	}

	void StmtConfigFiller::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		doTraverseType( stmt->getVariable()->getType() );
	}

	void StmtConfigFiller::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
		doTraverseType( stmt->getType() );
	}

	void StmtConfigFiller::visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )
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
		doTraverseType( stmt->getVariable()->getType() );
	}

	void StmtConfigFiller::visitTextureDeclStmt( ast::stmt::TextureDecl * stmt )
	{
		doTraverseType( stmt->getVariable()->getType() );
	}

	void StmtConfigFiller::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
		doTraverseType( stmt->getVariable()->getType() );
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

	void StmtConfigFiller::visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )
	{
		if ( isRayTraceStage( m_result.stage ) )
		{
			m_result.registerCapability( spv::CapabilityRayTracingKHR );
		}
		else
		{
			m_result.registerCapability( spv::CapabilityRayQueryKHR );
		}
	}

	void StmtConfigFiller::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		doTraverseType( stmt->getVariable()->getType() );
		auto var = stmt->getVariable();

		if ( var->isShaderInput() )
		{
			m_result.addInput( var );
		}

		if ( var->isShaderOutput() )
		{
			m_result.addOutput( var );
		}
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
		checkType( type, m_result );
	}
}
