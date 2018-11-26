/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Visitors/CloneStmt.hpp"

#include "ASTGenerator/Visitors/CloneExpr.hpp"

namespace ast
{
	stmt::ContainerPtr StmtCloner::submit( stmt::Container * stmt )
	{
		stmt::ContainerPtr result = stmt::makeContainer();
		StmtCloner vis{ result };
		stmt->accept( &vis );
		return result;
	}

	StmtCloner::StmtCloner( stmt::ContainerPtr & result )
		: m_result{ result }
		, m_current{ m_result.get() }
	{
	}

	expr::ExprPtr StmtCloner::doSubmit( expr::Expr * expr )
	{
		return ExprCloner::submit( expr );
	}

	void StmtCloner::visitContainerStmt( stmt::Container * cont )
	{
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtCloner::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makeConstantBufferDecl( stmt->getName()
			, stmt->getMemoryLayout()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitDiscardStmt( stmt::Discard * stmt )
	{
		m_current->addStmt( stmt::makeDiscard() );
	}

	void StmtCloner::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makePushConstantsBufferDecl( stmt->getName() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitCommentStmt( stmt::Comment * stmt )
	{
		m_current->addStmt( stmt::makeComment( stmt->getText() ) );
	}

	void StmtCloner::visitCompoundStmt( stmt::Compound * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makeContainer();
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makeDoWhile( doSubmit( stmt->getCtrlExpr() ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		auto save = m_current;
		auto cont = m_ifStmts.back()->createElseIf( doSubmit( stmt->getCtrlExpr() ) );
		m_current = cont;
		visitContainerStmt( stmt );
		m_current = save;
	}

	void StmtCloner::visitElseStmt( stmt::Else * stmt )
	{
		auto save = m_current;
		auto cont = m_ifStmts.back()->createElse();
		m_current = cont;
		visitContainerStmt( stmt );
		m_current = save;
	}

	void StmtCloner::visitForStmt( stmt::For * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makeFor( doSubmit( stmt->getInitExpr() )
			, doSubmit( stmt->getCtrlExpr() )
			, doSubmit( stmt->getIncrExpr() ) );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		var::VariableList params;

		for ( auto & param : stmt->getParameters() )
		{
			params.push_back( param );
		}

		auto save = m_current;
		auto cont = stmt::makeFunctionDecl( stmt->getRet()
			, stmt->getName()
			, params );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitIfStmt( stmt::If * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makeIf( doSubmit( stmt->getCtrlExpr() ) );
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
		m_current->addStmt( stmt::makeImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		m_current->addStmt( stmt::makeInOutVariableDecl( stmt->getVariable()
			, stmt->getLocation() ) );
	}

	void StmtCloner::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		m_current->addStmt( stmt::makeInputComputeLayout( stmt->getWorkGroupsX()
			, stmt->getWorkGroupsY()
			, stmt->getWorkGroupsZ() ) );
	}

	void StmtCloner::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		m_current->addStmt( stmt::makeInputGeometryLayout( stmt->getLayout() ) );
	}

	void StmtCloner::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		m_current->addStmt( stmt::makeOutputGeometryLayout( stmt->getLayout()
			, stmt->getPrimCount() ) );
	}

	void StmtCloner::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		m_current->addStmt( stmt::makePerVertexDecl( stmt->getSource()
			, stmt->getType() ) );
	}

	void StmtCloner::visitReturnStmt( stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			m_current->addStmt( stmt::makeReturn( doSubmit( stmt->getExpr() ) ) );
		}
		else
		{
			m_current->addStmt( stmt::makeReturn() );
		}
	}

	void StmtCloner::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		m_current->addStmt( stmt::makeSampledImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		m_current->addStmt( stmt::makeSamplerDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		auto save = m_current;
		auto cont = stmt::makeShaderBufferDecl( stmt->getSsboName()
			, stmt->getMemoryLayout()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )
	{
		m_current->addStmt( stmt::makeShaderStructBufferDecl( stmt->getSsboName()
			, stmt->getSsboInstance()
			, stmt->getData()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtCloner::visitSimpleStmt( stmt::Simple * stmt )
	{
		m_current->addStmt( stmt::makeSimple( doSubmit( stmt->getExpr() ) ) );
	}

	void StmtCloner::visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )
	{
		m_result->addStmt( stmt::makeSpecialisationConstantDecl( stmt->getVariable()
			, stmt->getLocation()
			, std::make_unique< expr::Literal >( *stmt->getValue() ) ) );
	}

	void StmtCloner::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		m_current->addStmt( stmt::makeStructureDecl( stmt->getType() ) );
	}

	void StmtCloner::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		stmt::SwitchCase * cont;

		if ( stmt->getCaseExpr() )
		{
			cont = m_switchStmts.back()->createCase( expr::makeSwitchCase( std::make_unique< expr::Literal >( *stmt->getCaseExpr()->getLabel() ) ) );
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
		auto save = m_current;
		auto cont = stmt::makeSwitch( expr::makeSwitchTest( doSubmit( stmt->getTestExpr()->getValue() ) ) );
		m_switchStmts.push_back( cont.get() );
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
		m_switchStmts.pop_back();
	}

	void StmtCloner::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		m_current->addStmt( stmt::makeVariableDecl( stmt->getVariable() ) );
	}

	void StmtCloner::visitWhileStmt( stmt::While * stmt )
	{
		auto cont = stmt::makeWhile( doSubmit( stmt->getCtrlExpr() ) );

		auto save = m_current;
		m_current = cont.get();
		visitContainerStmt( stmt );
		m_current = save;
		m_current->addStmt( std::move( cont ) );
	}

	void StmtCloner::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		m_current->addStmt( stmt::makePreprocDefine( preproc->getName(), doSubmit( preproc->getExpr() ) ) );
	}

	void StmtCloner::visitPreprocElif( stmt::PreprocElif * preproc )
	{
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
		m_current->addStmt( stmt::makePreprocEndif() );
	}

	void StmtCloner::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		m_current->addStmt( stmt::makePreprocExtension( preproc->getName()
			, preproc->getStatus() ) );
	}

	void StmtCloner::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		auto cont = stmt::makePreprocIf( doSubmit( preproc->getCtrlExpr() ) );
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
		auto cont = stmt::makePreprocIfDef( expr::makeIdentifier( preproc->getIdentExpr()->getVariable() ) );
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
		m_current->addStmt( stmt::makePreprocVersion( preproc->getName() ) );
	}
}
