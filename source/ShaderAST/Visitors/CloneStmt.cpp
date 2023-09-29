/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/CloneStmt.hpp"

#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"

namespace ast
{
	stmt::ContainerPtr StmtCloner::submit( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, stmt::Container * stmt )
	{
		stmt::ContainerPtr result = stmtCache.makeContainer();
		StmtCloner vis{ stmtCache, exprCache, result };
		stmt->accept( &vis );
		return result;
	}

	StmtCloner::StmtCloner( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, stmt::ContainerPtr & result )
		: m_stmtCache{ stmtCache }
		, m_exprCache{ exprCache }
		, m_result{ result }
		, m_current{ m_result.get() }
	{
	}

	expr::ExprPtr StmtCloner::doSubmit( expr::Expr * expr )
	{
		return ExprCloner::submit( m_exprCache, expr );
	}

	expr::ExprPtr StmtCloner::doSubmit( expr::ExprPtr const & expr )
	{
		return doSubmit( expr.get() );
	}

	void StmtCloner::visitContainerStmt( stmt::Container * cont )
	{
		TraceFunc
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtCloner::visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeAccelerationStructureDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitBreakStmt( stmt::Break * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeBreak( stmt->isSwitchCaseBreak() ) );
	}

	void StmtCloner::visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeBufferReferenceDecl( stmt->getType() ) );
	}

	void StmtCloner::visitContinueStmt( stmt::Continue * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeContinue() );
	}

	void StmtCloner::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeConstantBufferDecl( stmt->getName()
			, stmt->getMemoryLayout()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitDemoteStmt( stmt::Demote * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeDemote() );
	}

	void StmtCloner::visitTerminateInvocationStmt( stmt::TerminateInvocation * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeTerminateInvocation() );
	}

	void StmtCloner::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makePushConstantsBufferDecl( stmt->getName(), stmt->getMemoryLayout() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitCommentStmt( stmt::Comment * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeComment( stmt->getText() ) );
	}

	void StmtCloner::visitCompoundStmt( stmt::Compound * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeCompound();
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitDispatchMeshStmt( stmt::DispatchMesh * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeDispatchMesh( doSubmit( stmt->getNumGroupsX() )
			, doSubmit( stmt->getNumGroupsY() )
			, doSubmit( stmt->getNumGroupsZ() )
			, doSubmit( stmt->getPayload() ) ) );
	}

	void StmtCloner::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeDoWhile( doSubmit( stmt->getCtrlExpr() ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_ifStmts.back()->createElseIf( doSubmit( stmt->getCtrlExpr() ) );
		m_current = cont;
		visitContainerStmt( stmt );
		m_current = save;
	}

	void StmtCloner::visitElseStmt( stmt::Else * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_ifStmts.back()->createElse();
		m_current = cont;
		visitContainerStmt( stmt );
		m_current = save;
	}

	void StmtCloner::visitForStmt( stmt::For * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeFor( doSubmit( stmt->getInitExpr() )
			, doSubmit( stmt->getCtrlExpr() )
			, doSubmit( stmt->getIncrExpr() ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitFragmentLayoutStmt( stmt::FragmentLayout * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeFragmentLayout( stmt->getType()
			, stmt->getFragmentOrigin()
			, stmt->getFragmentCenter() ) );
	}

	void StmtCloner::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeFunctionDecl( stmt->getType()
			, stmt->getName()
			, stmt->getFlags() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeHitAttributeVariableDecl( stmt->getVariable() ) );
	}

	void StmtCloner::visitIfStmt( stmt::If * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeIf( doSubmit( stmt->getCtrlExpr() ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_ifStmts.push_back( cont.get() );
		m_current->addStmt( std::move( cont ) );

		for ( auto & elseIf : stmt->getElseIfList() )
		{
			elseIf->accept( this );
		}

		if ( stmt->getElse() )
		{
			stmt->getElse()->accept( this );
		}

		m_ifStmts.pop_back();
	}

	void StmtCloner::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitIgnoreIntersectionStmt( stmt::IgnoreIntersection * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeIgnoreIntersection() );
	}

	void StmtCloner::visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeInOutCallableDataVariableDecl( stmt->getVariable()
			, stmt->getLocation() ) );
	}

	void StmtCloner::visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeInOutRayPayloadVariableDecl( stmt->getVariable()
			, stmt->getLocation() ) );
	}

	void StmtCloner::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeInOutVariableDecl( stmt->getVariable()
			, stmt->getLocation()
			, stmt->getStreamIndex()
			, stmt->getBlendIndex() ) );
	}

	void StmtCloner::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeInputComputeLayout( stmt->getType()
			, stmt->getWorkGroupsX()
			, stmt->getWorkGroupsY()
			, stmt->getWorkGroupsZ() ) );
	}

	void StmtCloner::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeInputGeometryLayout( stmt->getType()
			, stmt->getLayout() ) );
	}

	void StmtCloner::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeOutputGeometryLayout( stmt->getType()
			, stmt->getLayout()
			, stmt->getPrimCount() ) );
	}

	void StmtCloner::visitOutputMeshLayoutStmt( stmt::OutputMeshLayout * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeOutputMeshLayout( stmt->getType()
			, stmt->getTopology()
			, stmt->getMaxVertices()
			, stmt->getMaxPrimitives() ) );
	}

	void StmtCloner::visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeInputTessellationEvaluationLayout( stmt->getType()
			, stmt->getDomain()
			, stmt->getPartitioning()
			, stmt->getPrimitiveOrdering() ) );
	}

	void StmtCloner::visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeOutputTessellationControlLayout( stmt->getType()
			, stmt->getDomain()
			, stmt->getPartitioning()
			, stmt->getTopology()
			, stmt->getPrimitiveOrdering()
			, stmt->getOutputVertices() ) );
	}

	void StmtCloner::visitPerPrimitiveDeclStmt( stmt::PerPrimitiveDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makePerPrimitiveDecl( stmt->getType() ) );
	}

	void StmtCloner::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makePerVertexDecl( stmt->getSource()
			, stmt->getType() ) );
	}

	void StmtCloner::visitReturnStmt( stmt::Return * stmt )
	{
		TraceFunc
		if ( stmt->getExpr() )
		{
			m_current->addStmt( m_stmtCache.makeReturn( doSubmit( stmt->getExpr() ) ) );
		}
		else
		{
			m_current->addStmt( m_stmtCache.makeReturn() );
		}
	}

	void StmtCloner::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeSampledImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitCombinedImageDeclStmt( stmt::CombinedImageDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeCombinedImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeSamplerDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeShaderBufferDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeShaderStructBufferDecl( stmt->getSsboName()
			, stmt->getSsboInstance()
			, stmt->getData()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitSimpleStmt( stmt::Simple * stmt )
	{
		TraceFunc
		auto expr = doSubmit( stmt->getExpr() );

		if ( expr )
		{
			m_current->addStmt( m_stmtCache.makeSimple( std::move( expr ) ) );
		}
	}

	void StmtCloner::visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )
	{
		TraceFunc
		m_result->addStmt( m_stmtCache.makeSpecialisationConstantDecl( stmt->getVariable()
			, stmt->getLocation()
			, m_exprCache.makeLiteral( *stmt->getValue() ) ) );
	}

	void StmtCloner::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeStructureDecl( stmt->getType() ) );
	}

	void StmtCloner::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		TraceFunc
		stmt::SwitchCase * cont;

		if ( stmt->getCaseExpr() )
		{
			cont = m_switchStmts.back()->createCase( m_exprCache.makeSwitchCase( m_exprCache.makeLiteral( *stmt->getCaseExpr()->getLabel() ) ) );
		}
		else
		{
			cont = m_switchStmts.back()->createDefault();
		}

		auto save = m_current;
		m_current = cont;
		visitContainerStmt( stmt );
		m_current = save;
	}

	void StmtCloner::visitSwitchStmt( stmt::Switch * stmt )
	{
		TraceFunc
		auto save = m_current;
		auto cont = m_stmtCache.makeSwitch( m_exprCache.makeSwitchTest( doSubmit( stmt->getTestExpr()->getValue() ) ) );
		m_switchStmts.push_back( cont.get() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
		m_switchStmts.pop_back();
	}

	void StmtCloner::visitTerminateRayStmt( stmt::TerminateRay * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeTerminateRay() );
	}

	void StmtCloner::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makeVariableDecl( stmt->getVariable() ) );
	}

	void StmtCloner::visitWhileStmt( stmt::While * stmt )
	{
		TraceFunc
		auto cont = m_stmtCache.makeWhile( doSubmit( stmt->getCtrlExpr() ) );

		auto save = m_current;
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makePreprocDefine( preproc->getId()
			, preproc->getName()
			, doSubmit( preproc->getExpr() ) ) );
	}

	void StmtCloner::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		TraceFunc
		stmt::PreprocElif * cont;

		if ( !m_preprocIfDefs.back() )
		{
			cont = m_preprocIfStmts.back()->createElif( doSubmit( preproc->getCtrlExpr() ) );
		}
		else
		{
			cont = m_preprocIfDefStmts.back()->createElif( doSubmit( preproc->getCtrlExpr() ) );
		}

		auto save = m_current;
		m_current = cont;
		visitContainerStmt( preproc );
		m_current = save;
	}

	void StmtCloner::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		TraceFunc
		stmt::PreprocElse * cont;

		if ( !m_preprocIfDefs.back() )
		{
			cont = m_preprocIfStmts.back()->createElse();
		}
		else
		{
			cont = m_preprocIfDefStmts.back()->createElse();
		}

		auto save = m_current;
		m_current = cont;
		visitContainerStmt( preproc );
		m_current = save;
	}

	void StmtCloner::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makePreprocEndif() );
	}

	void StmtCloner::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makePreprocExtension( preproc->getName()
			, preproc->getStatus() ) );
	}

	void StmtCloner::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		TraceFunc
		auto cont = m_stmtCache.makePreprocIf( doSubmit( preproc->getCtrlExpr() ) );
		m_preprocIfStmts.push_back( cont.get() );
		m_preprocIfDefs.push_back( false );

		auto save = m_current;
		m_current = cont.get();
		visitContainerStmt( preproc );
		m_current = save;
		m_current->addStmt( std::move( cont ) );

		for ( auto & elseIf : preproc->getElifList() )
		{
			elseIf->accept( this );
		}

		if ( preproc->getElse() )
		{
			preproc->getElse()->accept( this );
		}

		m_preprocIfStmts.pop_back();
	}

	void StmtCloner::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		TraceFunc
		auto cont = m_stmtCache.makePreprocIfDef( m_exprCache.makeIdentifier( preproc->getIdentExpr()->getTypesCache(), preproc->getIdentExpr()->getVariable() ) );
		m_preprocIfDefStmts.push_back( cont.get() );
		m_preprocIfDefs.push_back( true );

		auto save = m_current;
		m_current = cont.get();
		visitContainerStmt( preproc );
		m_current = save;
		m_current->addStmt( std::move( cont ) );

		for ( auto & elseIf : preproc->getElifList() )
		{
			elseIf->accept( this );
		}

		if ( preproc->getElse() )
		{
			preproc->getElse()->accept( this );
		}

		m_preprocIfDefStmts.pop_back();
	}

	void StmtCloner::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		TraceFunc
		m_current->addStmt( m_stmtCache.makePreprocVersion( preproc->getName() ) );
	}
}
