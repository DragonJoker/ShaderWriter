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
		, stmt::Container const & stmt )
	{
		stmt::ContainerPtr result = stmtCache.makeContainer();
		StmtCloner vis{ stmtCache, exprCache, result };
		stmt.accept( &vis );
		return result;
	}

	stmt::StmtPtr StmtCloner::submit( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, stmt::Stmt const * stmt )
	{
		stmt::ContainerPtr result = stmtCache.makeContainer();
		StmtCloner vis{ stmtCache, exprCache, result };
		stmt->accept( &vis );
		return result->empty()
			? nullptr
			: std::move( result->m_statements.front() );
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

	expr::ExprPtr StmtCloner::doSubmit( expr::Expr const & expr )
	{
		return ExprCloner::submit( m_exprCache, expr );
	}

	expr::ExprPtr StmtCloner::doSubmit( expr::Expr const * expr )
	{
		if ( expr )
		{
			return doSubmit( *expr );
		}

		return nullptr;
	}

	void StmtCloner::visitContainerStmt( stmt::Container const * cont )
	{
		TraceFunc;
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtCloner::visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeAccelerationStructureDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitBreakStmt( stmt::Break const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeBreak( stmt->isSwitchCaseBreak() ) );
	}

	void StmtCloner::visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeBufferReferenceDecl( stmt->getType() ) );
	}

	void StmtCloner::visitContinueStmt( stmt::Continue const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeContinue() );
	}

	void StmtCloner::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl const * stmt )
	{
		TraceFunc;
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

	void StmtCloner::visitDemoteStmt( stmt::Demote const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeDemote() );
	}

	void StmtCloner::visitTerminateInvocationStmt( stmt::TerminateInvocation const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeTerminateInvocation() );
	}

	void StmtCloner::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_stmtCache.makePushConstantsBufferDecl( stmt->getName(), stmt->getMemoryLayout() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitCommentStmt( stmt::Comment const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeComment( stmt->getText() ) );
	}

	void StmtCloner::visitCompoundStmt( stmt::Compound const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_stmtCache.makeCompound();
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitDispatchMeshStmt( stmt::DispatchMesh const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeDispatchMesh( doSubmit( stmt->getNumGroupsX() )
			, doSubmit( stmt->getNumGroupsY() )
			, doSubmit( stmt->getNumGroupsZ() )
			, doSubmit( stmt->getPayload() ) ) );
	}

	void StmtCloner::visitDoWhileStmt( stmt::DoWhile const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_stmtCache.makeDoWhile( doSubmit( stmt->getCtrlExpr() ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitElseIfStmt( stmt::ElseIf const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_ifStmts.back()->createElseIf( doSubmit( stmt->getCtrlExpr() ) );
		m_current = cont;
		visitContainerStmt( stmt );
		m_current = save;
	}

	void StmtCloner::visitElseStmt( stmt::Else const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_ifStmts.back()->createElse();
		m_current = cont;
		visitContainerStmt( stmt );
		m_current = save;
	}

	void StmtCloner::visitForStmt( stmt::For const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_stmtCache.makeFor( doSubmit( stmt->getInitExpr() )
			, doSubmit( stmt->getCtrlExpr() )
			, doSubmit( stmt->getIncrExpr() ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitFragmentLayoutStmt( stmt::FragmentLayout const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeFragmentLayout( stmt->getType()
			, stmt->getFragmentOrigin()
			, stmt->getFragmentCenter() ) );
	}

	void StmtCloner::visitFunctionDeclStmt( stmt::FunctionDecl const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_stmtCache.makeFunctionDecl( stmt->getFuncVar()
			, stmt->getFlags() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeHitAttributeVariableDecl( stmt->getVariable() ) );
	}

	void StmtCloner::visitIfStmt( stmt::If const * stmt )
	{
		TraceFunc;
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

	void StmtCloner::visitImageDeclStmt( stmt::ImageDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitIgnoreIntersectionStmt( stmt::IgnoreIntersection const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeIgnoreIntersection() );
	}

	void StmtCloner::visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeInOutCallableDataVariableDecl( stmt->getVariable()
			, stmt->getLocation() ) );
	}

	void StmtCloner::visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeInOutRayPayloadVariableDecl( stmt->getVariable()
			, stmt->getLocation() ) );
	}

	void StmtCloner::visitInOutVariableDeclStmt( stmt::InOutVariableDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeInOutVariableDecl( stmt->getVariable()
			, stmt->getLocation()
			, stmt->getStreamIndex()
			, stmt->getBlendIndex() ) );
	}

	void StmtCloner::visitInputComputeLayoutStmt( stmt::InputComputeLayout const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeInputComputeLayout( stmt->getType()
			, stmt->getWorkGroupsX()
			, stmt->getWorkGroupsY()
			, stmt->getWorkGroupsZ() ) );
	}

	void StmtCloner::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeInputGeometryLayout( stmt->getType()
			, stmt->getLayout() ) );
	}

	void StmtCloner::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeOutputGeometryLayout( stmt->getType()
			, stmt->getLayout()
			, stmt->getPrimCount() ) );
	}

	void StmtCloner::visitOutputMeshLayoutStmt( stmt::OutputMeshLayout const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeOutputMeshLayout( stmt->getType()
			, stmt->getTopology()
			, stmt->getMaxVertices()
			, stmt->getMaxPrimitives() ) );
	}

	void StmtCloner::visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeInputTessellationEvaluationLayout( stmt->getType()
			, stmt->getDomain()
			, stmt->getPartitioning()
			, stmt->getPrimitiveOrdering() ) );
	}

	void StmtCloner::visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeOutputTessellationControlLayout( stmt->getType()
			, stmt->getDomain()
			, stmt->getPartitioning()
			, stmt->getTopology()
			, stmt->getPrimitiveOrdering()
			, stmt->getOutputVertices() ) );
	}

	void StmtCloner::visitPerPrimitiveDeclStmt( stmt::PerPrimitiveDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makePerPrimitiveDecl( stmt->getType() ) );
	}

	void StmtCloner::visitPerVertexDeclStmt( stmt::PerVertexDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makePerVertexDecl( stmt->getSource()
			, stmt->getType() ) );
	}

	void StmtCloner::visitReturnStmt( stmt::Return const * stmt )
	{
		TraceFunc;
		if ( auto expr = stmt->getExpr() )
		{
			m_current->addStmt( m_stmtCache.makeReturn( doSubmit( *expr ) ) );
		}
		else
		{
			m_current->addStmt( m_stmtCache.makeReturn() );
		}
	}

	void StmtCloner::visitSampledImageDeclStmt( stmt::SampledImageDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeSampledImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitCombinedImageDeclStmt( stmt::CombinedImageDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeCombinedImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitSamplerDeclStmt( stmt::SamplerDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeSamplerDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_stmtCache.makeShaderBufferDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeShaderStructBufferDecl( stmt->getSsboName()
			, stmt->getSsboInstance()
			, stmt->getData()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitSimpleStmt( stmt::Simple const * stmt )
	{
		TraceFunc;
		auto expr = doSubmit( stmt->getExpr() );

		if ( expr )
		{
			m_current->addStmt( m_stmtCache.makeSimple( std::move( expr ) ) );
		}
	}

	void StmtCloner::visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl const * stmt )
	{
		TraceFunc;
		m_result->addStmt( m_stmtCache.makeSpecialisationConstantDecl( stmt->getVariable()
			, stmt->getLocation()
			, m_exprCache.makeLiteral( *stmt->getValue() ) ) );
	}

	void StmtCloner::visitStructureDeclStmt( stmt::StructureDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeStructureDecl( stmt->getType() ) );
	}

	void StmtCloner::visitSwitchCaseStmt( stmt::SwitchCase const * stmt )
	{
		TraceFunc;
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

	void StmtCloner::visitSwitchStmt( stmt::Switch const * stmt )
	{
		TraceFunc;
		auto save = m_current;
		auto cont = m_stmtCache.makeSwitch( m_exprCache.makeSwitchTest( doSubmit( stmt->getTestExpr()->getValue() ) ) );
		m_switchStmts.push_back( cont.get() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
		m_switchStmts.pop_back();
	}

	void StmtCloner::visitTerminateRayStmt( stmt::TerminateRay const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeTerminateRay() );
	}

	void StmtCloner::visitVariableDeclStmt( stmt::VariableDecl const * stmt )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makeVariableDecl( stmt->getVariable() ) );
	}

	void StmtCloner::visitWhileStmt( stmt::While const * stmt )
	{
		TraceFunc;
		auto cont = m_stmtCache.makeWhile( doSubmit( stmt->getCtrlExpr() ) );

		auto save = m_current;
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitPreprocExtension( stmt::PreprocExtension const * preproc )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makePreprocExtension( preproc->getName()
			, preproc->getStatus() ) );
	}

	void StmtCloner::visitPreprocVersion( stmt::PreprocVersion const * preproc )
	{
		TraceFunc;
		m_current->addStmt( m_stmtCache.makePreprocVersion( preproc->getName() ) );
	}
}
