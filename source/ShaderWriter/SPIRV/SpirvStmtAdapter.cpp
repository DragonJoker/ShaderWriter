/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvStmtAdapter.hpp"

#include "ShaderWriter/CloneExpr.hpp"
#include "ShaderWriter/SPIRV/SpirvExprAdapter.hpp"
#include "ShaderWriter/SPIRV/SpirvExprEvaluator.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw::spirv
{
	stmt::ContainerPtr StmtAdapter::submit( Shader const & shader, ShaderType type )
	{
		auto result = stmt::makeContainer();
		StmtAdapter vis{ shader, type, result.get() };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( Shader const & shader
		, ShaderType type
		, stmt::Container * result )
		: m_shader{ shader }
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
		auto cont = stmt::makeDoWhile( ExprAdapter::submit( stmt->getCtrlExpr(), m_context ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		assert( false && "Unexpected ElseIf statement." );
	}

	void StmtAdapter::visitElseStmt( stmt::Else * stmt )
	{
		assert( false && "Unexpected Else statement." );
	}

	void StmtAdapter::visitForStmt( stmt::For * stmt )
	{
		auto save = m_result;
		auto cont = stmt::makeFor( ExprAdapter::submit( stmt->getInitExpr(), m_context )
			, ExprAdapter::submit( stmt->getCtrlExpr(), m_context )
			, ExprAdapter::submit( stmt->getIncrExpr(), m_context ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		auto save = m_result;
		stmt::FunctionDeclPtr cont;
		var::VariableList params;

		for ( auto & param : stmt->getParameters() )
		{
			params.push_back( param );
		}

		cont = stmt::makeFunctionDecl( stmt->getRet()
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
		auto cont = stmt::makeIf( ExprAdapter::submit( stmt->getCtrlExpr(), m_context ) );
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		auto currentIf = cont.get();
		m_result->addStmt( std::move( cont ) );

		// Replace all else ifs by the following :
		// Origin:
		// if (condA){}
		// else if (condB){}
		// else{}
		//
		// Result:
		// if (condA){}
		// else
		// {
		//   if (condB){}
		//   else{}
		// }
		if ( stmt->getElse()
			|| !stmt->getElseIfList().empty() )
		{
			auto & elseIfs = stmt->getElseIfList();
			auto it = elseIfs.begin();

			while ( it != elseIfs.end() )
			{
				auto elseStmt = currentIf->createElse();
				auto & elseIf = *it;
				cont = stmt::makeIf( ExprAdapter::submit( elseIf->getCtrlExpr(), m_context ) );
				m_result = cont.get();
				visitContainerStmt( elseIf.get() );
				m_result = save;
				currentIf = cont.get();
				elseStmt->addStmt( std::move( cont ) );
				++it;
			}

			if ( stmt->getElse() )
			{
				auto elseStmt = currentIf->createElse();
				m_result = elseStmt;
				visitContainerStmt( stmt->getElse() );
				m_result = save;
			}
		}
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
		m_result->addStmt( stmt::makePerVertexDecl( stmt->getSource(), stmt->getType() ) );
	}

	void StmtAdapter::visitReturnStmt( stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			m_result->addStmt( stmt::makeReturn( ExprAdapter::submit( stmt->getExpr(), m_context ) ) );
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
		m_result->addStmt( stmt::makeSimple( ExprAdapter::submit( stmt->getExpr(), m_context ) ) );
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
			cont = m_switchStmt->createCase( expr::makeSwitchCase( std::make_unique< expr::Literal >( *stmt->getCaseExpr()->getLabel() ) ) );
		}
		else
		{
			cont = m_switchStmt->createDefault();
		}

		auto save = m_result;
		m_result = cont;
		visitContainerStmt( stmt );
		m_result = save;
	}

	void StmtAdapter::visitSwitchStmt( stmt::Switch * stmt )
	{
		auto cont = stmt::makeSwitch( expr::makeSwitchTest( ExprAdapter::submit( stmt->getTestExpr()->getValue(), m_context ) ) );
		m_switchStmt = cont.get();

		auto save = m_result;
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		m_result->addStmt( stmt::makeVariableDecl( stmt->getVariable() ) );
	}

	void StmtAdapter::visitWhileStmt( stmt::While * stmt )
	{
		auto cont = stmt::makeWhile( ExprAdapter::submit( stmt->getCtrlExpr(), m_context ) );

		auto save = m_result;
		m_result = cont.get();
		visitContainerStmt( stmt );
		m_result = save;
		m_result->addStmt( std::move( cont ) );
	}

	void StmtAdapter::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		m_context.defines.emplace( preproc->getName(), preproc->getExpr() );
	}

	void StmtAdapter::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtAdapter::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtAdapter::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
	}

	void StmtAdapter::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		m_result->addStmt( stmt::makePreprocExtension( preproc->getName(), preproc->getStatus() ) );
	}

	void StmtAdapter::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		bool isTrue = eval( preproc->getCtrlExpr(), m_context );

		if ( isTrue )
		{
			visitContainerStmt( preproc );
		}
		else
		{
			uint32_t i = 0u;

			while ( i < preproc->getElifList().size()
				&& !( isTrue = eval( static_cast< stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_context ) ) )
			{
				++i;
			}

			if ( isTrue )
			{
				preproc->getElifList()[i]->accept( this );
			}
			else if ( preproc->getElse() )
			{
				preproc->getElse()->accept( this );
			}
		}
	}

	void StmtAdapter::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		bool isTrue = eval( preproc->getIdentExpr(), m_context );

		if ( isTrue )
		{
			visitContainerStmt( preproc );
		}
		else
		{
			uint32_t i = 0u;

			while ( i < preproc->getElifList().size()
				&& !( isTrue = eval( static_cast< stmt::PreprocElif const & >( *preproc->getElifList()[i] ).getCtrlExpr(), m_context ) ) )
			{
				++i;
			}

			if ( isTrue )
			{
				preproc->getElifList()[i]->accept( this );
			}
			else if ( preproc->getElse() )
			{
				preproc->getElse()->accept( this );
			}
		}
	}

	void StmtAdapter::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		m_result->addStmt( stmt::makePreprocVersion( preproc->getName() ) );
	}
}
