/*
See LICENSE file in root folder
*/
#include "GlslStmtConfigFiller.hpp"

#include "GlslExprConfigFiller.hpp"

#include <ShaderWriter/Shader.hpp>

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

using namespace ast;
using namespace sdw;

namespace glsl
{
	IntrinsicsConfig StmtConfigFiller::submit( Shader const & shader )
	{
		IntrinsicsConfig result;
		StmtConfigFiller vis{ shader, result };
		shader.getStatements()->accept( &vis );
		return result;
	}

	StmtConfigFiller::StmtConfigFiller( Shader const & shader
		, IntrinsicsConfig & result )
		: m_result{ result }
	{
	}

	void StmtConfigFiller::visitContainerStmt( stmt::Container * cont )
	{
		for ( auto & stmt : *cont )
		{
			stmt->accept( this );
		}
	}

	void StmtConfigFiller::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitDiscardStmt( stmt::Discard * stmt )
	{
	}

	void StmtConfigFiller::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitCommentStmt( stmt::Comment * stmt )
	{
	}

	void StmtConfigFiller::visitCompoundStmt( stmt::Compound * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseStmt( stmt::Else * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitForStmt( stmt::For * stmt )
	{
		ExprConfigFiller::submit( stmt->getInitExpr(), m_result );
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		ExprConfigFiller::submit( stmt->getIncrExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitIfStmt( stmt::If * stmt )
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

	void StmtConfigFiller::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		auto image = std::static_pointer_cast< type::Image >( stmt->getVariable()->getType() );
		doParseImageConfig( image->getConfig() );
	}

	void StmtConfigFiller::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
	}

	void StmtConfigFiller::visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )
	{
	}

	void StmtConfigFiller::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
	}

	void StmtConfigFiller::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
	}

	void StmtConfigFiller::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
	}

	void StmtConfigFiller::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
	}

	void StmtConfigFiller::visitReturnStmt( stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			ExprConfigFiller::submit( stmt->getExpr(), m_result );
		}
	}

	void StmtConfigFiller::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		auto image = std::static_pointer_cast< type::SampledImage >( stmt->getVariable()->getType() );
		doParseImageConfig( image->getConfig() );
	}

	void StmtConfigFiller::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
	}

	void StmtConfigFiller::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )
	{
	}

	void StmtConfigFiller::visitSimpleStmt( stmt::Simple * stmt )
	{
		ExprConfigFiller::submit( stmt->getExpr(), m_result );
	}

	void StmtConfigFiller::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
	}

	void StmtConfigFiller::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitSwitchStmt( stmt::Switch * stmt )
	{
		ExprConfigFiller::submit( stmt->getTestExpr()->getValue(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
	}

	void StmtConfigFiller::visitWhileStmt( stmt::While * stmt )
	{
		ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		ExprConfigFiller::submit( preproc->getExpr(), m_result );
	}

	void StmtConfigFiller::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		ExprConfigFiller::submit( preproc->getCtrlExpr(), m_result );
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
	}

	void StmtConfigFiller::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
	}

	void StmtConfigFiller::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		ExprConfigFiller::submit( preproc->getCtrlExpr(), m_result );
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
	}

	void StmtConfigFiller::doParseImageConfig( type::ImageConfiguration const & config )
	{
		if ( config.dimension == type::ImageDim::eCube
			&& config.isArrayed )
		{
			m_result.requiresCubeMapArray = true;
		}
	}
}
