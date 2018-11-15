/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslStmtAdapter.hpp"

#include "ShaderWriter/GLSL/GlslExprAdapter.hpp"
#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/GLSL/GlslTextureAccessFunctions.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw::glsl
{
	stmt::ContainerPtr StmtAdapter::submit( Shader const & shader
		, ShaderType type
		, IntrinsicsConfig const & config )
	{
		auto result = stmt::makeContainer();
		StmtAdapter vis{ shader, type, config, result.get() };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( Shader const & shader
		, ShaderType type
		, IntrinsicsConfig const & config
		, stmt::Container * result )
		: m_config{ config }
		, m_result{ result }
		, m_type{ type }
	{
	}

	void StmtAdapter::visitContainerStmt( stmt::Container * cont )
	{
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtAdapter::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeConstantBufferDecl( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitDiscardStmt( stmt::Discard * stmt )
	{
		m_result->addStmt( stmt::makeDiscard() );
	}

	void StmtAdapter::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makePushConstantsBufferDecl( stmt->getName() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitCommentStmt( stmt::Comment * stmt )
	{
		m_result->addStmt( stmt::makeComment( stmt->getText() ) );
	}

	void StmtAdapter::visitCompoundStmt( stmt::Compound * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeContainer();
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeDoWhile( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		auto save = m_result;
		auto cont = m_ifStmts.back()->createElseIf( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config ) );
		m_result = cont;
		visitContainerStmt( stmt );
		m_result = save;
	}

	void StmtAdapter::visitElseStmt( stmt::Else * stmt )
	{
		auto save = m_result;
		auto cont = m_ifStmts.back()->createElse();
		m_result = cont;
		visitContainerStmt( stmt );
		m_result = save;
	}

	void StmtAdapter::visitForStmt( stmt::For * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeFor( ExprAdapter::submit( stmt->getInitExpr()
				, m_config )
			, ExprAdapter::submit( stmt->getCtrlExpr()
				, m_config )
			, ExprAdapter::submit( stmt->getIncrExpr()
				, m_config ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		var::VariableList params;

		for ( auto & param : stmt->getParameters() )
		{
			params.push_back( param );
		}

		auto save = m_result;
		auto cont = stmt::makeFunctionDecl( stmt->getRet()
			, stmt->getName()
			, params );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitIfStmt( stmt::If * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeIf( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_ifStmts.push_back( cont.get() );
		m_result->addStmt( std::move( cont ) );

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

	void StmtAdapter::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		m_result->addStmt( stmt::makeImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtAdapter::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		m_result->addStmt( stmt::makeInOutVariableDecl( stmt->getVariable()
			, stmt->getLocation() ) );
	}

	void StmtAdapter::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		m_result->addStmt( stmt::makeInputComputeLayout( stmt->getWorkGroupsX()
			, stmt->getWorkGroupsY()
			, stmt->getWorkGroupsZ() ) );
	}

	void StmtAdapter::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		m_result->addStmt( stmt::makeInputGeometryLayout( stmt->getLayout() ) );
	}

	void StmtAdapter::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		m_result->addStmt( stmt::makeOutputGeometryLayout( stmt->getLayout()
			, stmt->getPrimCount() ) );
	}

	void StmtAdapter::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		m_result->addStmt( stmt::makePerVertexDecl( stmt->getSource()
			, stmt->getType() ) );
	}

	void StmtAdapter::visitReturnStmt( stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			m_result->addStmt( stmt::makeReturn( ExprAdapter::submit( stmt->getExpr()
				, m_config ) ) );
		}
		else
		{
			m_result->addStmt( stmt::makeReturn() );
		}
	}

	void StmtAdapter::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		m_result->addStmt( stmt::makeSampledImageDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtAdapter::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		m_result->addStmt( stmt::makeSamplerDecl( stmt->getVariable()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtAdapter::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeShaderBufferDecl( stmt->getName()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitSimpleStmt( stmt::Simple * stmt )
	{
		m_result->addStmt( stmt::makeSimple( ExprAdapter::submit( stmt->getExpr()
			, m_config ) ) );
	}

	void StmtAdapter::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		m_result->addStmt( stmt::makeStructureDecl( stmt->getType() ) );
	}

	void StmtAdapter::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
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

		auto save = m_result;
		m_result = cont;
		visitContainerStmt( stmt );
		m_result = save;
	}

	void StmtAdapter::visitSwitchStmt( stmt::Switch * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeSwitch( expr::makeSwitchTest( ExprAdapter::submit( stmt->getTestExpr()->getValue()
			, m_config ) ) );
		m_switchStmts.push_back( cont.get() );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
		m_switchStmts.pop_back();
	}

	void StmtAdapter::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		m_result->addStmt( stmt::makeVariableDecl( stmt->getVariable() ) );
	}

	void StmtAdapter::visitWhileStmt( stmt::While * stmt )
	{
		auto cont = stmt::makeWhile( ExprAdapter::submit( stmt->getCtrlExpr()
			, m_config ) );

		auto save = m_result;
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		m_result->addStmt( stmt::makePreprocDefine( preproc->getName(), ExprAdapter::submit( preproc->getExpr()
			, m_config ) ) );
	}

	void StmtAdapter::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		stmt::PreprocElif * cont;

		if ( !m_preprocIfDefs.back() )
		{
			cont = m_preprocIfStmts.back()->createElif( ExprAdapter::submit( preproc->getCtrlExpr()
				, m_config ) );
		}
		else
		{
			cont = m_preprocIfDefStmts.back()->createElif( ExprAdapter::submit( preproc->getCtrlExpr()
				, m_config ) );
		}

		auto save = m_result;
		m_result = cont;
		visitContainerStmt( preproc );
		m_result = save;
	}

	void StmtAdapter::visitPreprocElse( stmt::PreprocElse * preproc )
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

		auto save = m_result;
		m_result = cont;
		visitContainerStmt( preproc );
		m_result = save;
	}

	void StmtAdapter::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
		m_result->addStmt( stmt::makePreprocEndif() );
	}

	void StmtAdapter::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		m_result->addStmt( stmt::makePreprocExtension( preproc->getName()
			, preproc->getStatus() ) );
	}

	void StmtAdapter::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		auto cont = stmt::makePreprocIf( ExprAdapter::submit( preproc->getCtrlExpr()
			, m_config ) );
		m_preprocIfStmts.push_back( cont.get() );
		m_preprocIfDefs.push_back( false );

		auto save = m_result;
		m_result = cont.get();
		visitContainerStmt( preproc );
		m_result = save;
		m_result->addStmt( std::move( cont ) );

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

	void StmtAdapter::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		auto cont = stmt::makePreprocIfDef( makeIdent( preproc->getIdentExpr()->getVariable() ) );
		m_preprocIfDefStmts.push_back( cont.get() );
		m_preprocIfDefs.push_back( true );

		auto save = m_result;
		m_result = cont.get();
		visitContainerStmt( preproc );
		m_result = save;
		m_result->addStmt( std::move( cont ) );

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

	void StmtAdapter::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		m_result->addStmt( stmt::makePreprocVersion( preproc->getName() ) );
		auto cont = stmt::makeContainer();
		compileGlslTextureAccessFunctions( cont.get(), m_config );
		m_result->addStmt( std::move( cont ) );
	}
}
