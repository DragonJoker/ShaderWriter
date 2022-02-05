/*
See LICENSE file in root folder
*/
#include "GlslStmtConfigFiller.hpp"

#include "GlslExprConfigFiller.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>

namespace glsl
{
	IntrinsicsConfig StmtConfigFiller::submit( ast::ShaderStage stage
		, ast::stmt::Container * container )
	{
		IntrinsicsConfig result{ stage };

		if ( isRayTraceStage( stage ) )
		{
			result.requiredExtensions.insert( EXT_ray_tracing );
		}

		if ( isMeshStage( stage ) )
		{
			result.requiredExtensions.insert( NV_mesh_shader );
		}

		StmtConfigFiller vis{ result };
		container->accept( &vis );
		return result;
	}

	StmtConfigFiller::StmtConfigFiller( IntrinsicsConfig & result )
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

	void StmtConfigFiller::visitContinueStmt( ast::stmt::Continue * stmt )
	{
	}

	void StmtConfigFiller::visitDemoteStmt( ast::stmt::Demote * stmt )
	{
	}

	void StmtConfigFiller::visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )
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

	void StmtConfigFiller::visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )
	{
	}

	void StmtConfigFiller::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * stmt )
	{
	}

	void StmtConfigFiller::visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )
	{
		checkType( stmt->getType(), m_result );
		m_result.requiredExtensions.insert( EXT_buffer_reference2 );
		m_result.requiredExtensions.insert( EXT_scalar_block_layout );
	}

	void StmtConfigFiller::visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )
	{
		checkType( stmt->getVariable()->getType(), m_result );
	}

	void StmtConfigFiller::visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )
	{
		checkType( stmt->getVariable()->getType(), m_result );
	}

	void StmtConfigFiller::visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )
	{
		checkType( stmt->getVariable()->getType(), m_result );
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
		m_result.requiredExtensions.insert( ARB_shader_image_load_store );
		auto image = std::static_pointer_cast< ast::type::Image >( stmt->getVariable()->getType() );
		doParseImageConfig( image->getConfig() );
	}

	void StmtConfigFiller::visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )
	{
	}

	void StmtConfigFiller::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		checkType( stmt->getVariable()->getType(), m_result );

		if ( stmt->getBlendIndex() )
		{
			m_result.requiresBlendIndex = true;
		}
	}

	void StmtConfigFiller::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		checkType( stmt->getVariable()->getType(), m_result );
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

	void StmtConfigFiller::visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )
	{
	}

	void StmtConfigFiller::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
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

	void StmtConfigFiller::visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )
	{
		auto image = std::static_pointer_cast< ast::type::CombinedImage >( ast::type::getNonArrayTypeRec( stmt->getVariable()->getType() ) );
		doParseImageConfig( image->getConfig() );
	}

	void StmtConfigFiller::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		m_result.requiredExtensions.insert( KHR_vulkan_glsl );
		m_result.requiresSeparateSamplers = true;
		auto image = std::static_pointer_cast< ast::type::SampledImage >( ast::type::getNonArrayTypeRec( stmt->getVariable()->getType() ) );
		doParseImageConfig( image->getConfig() );
	}

	void StmtConfigFiller::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
		m_result.requiredExtensions.insert( KHR_vulkan_glsl );
		m_result.requiresSeparateSamplers = true;
	}

	void StmtConfigFiller::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		m_result.requiredExtensions.insert( ARB_shader_storage_buffer_object );

		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eScalar )
		{
			m_result.requiredExtensions.insert( EXT_scalar_block_layout );
		}

		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eScalar )
		{
			m_result.requiredExtensions.insert( EXT_scalar_block_layout );
		}

		m_result.requiredExtensions.insert( ARB_shader_storage_buffer_object );

		for ( auto & type : static_cast< ast::type::Struct const & >( *stmt->getSsboInstance()->getType() ) )
		{
			checkType( type.type, m_result );
		}
	}

	void StmtConfigFiller::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		ExprConfigFiller::submit( stmt->getExpr(), m_result );
	}

	void StmtConfigFiller::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		for ( auto & type : *stmt->getType() )
		{
			checkType( type.type, m_result );
		}
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
	}

	void StmtConfigFiller::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		checkType( stmt->getVariable()->getType(), m_result );
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

	void StmtConfigFiller::doParseImageConfig( ast::type::ImageConfiguration const & config )
	{
		if ( config.dimension == ast::type::ImageDim::eCube
			&& config.isArrayed )
		{
			m_result.requiredExtensions.insert( ARB_texture_cube_map_array );
		}
	}
}
