/*
See LICENSE file in root folder
*/
#include "HlslStmtConfigFiller.hpp"

#include "HlslExprConfigFiller.hpp"
#include "HlslHelpers.hpp"
#include "HlslImageAccessFunctions.hpp"
#include "HlslIntrinsicFunctions.hpp"
#include "HlslTextureAccessFunctions.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

namespace hlsl
{
	namespace
	{
		bool isOutput( ast::stmt::PerVertexDecl::Source source )
		{
			return source == ast::stmt::PerVertexDecl::Source::eGeometryOutput
				|| source == ast::stmt::PerVertexDecl::Source::eTessellationControlOutput
				|| source == ast::stmt::PerVertexDecl::Source::eTessellationEvaluationOutput
				|| source == ast::stmt::PerVertexDecl::Source::eVertexOutput;
		}
	}

	IntrinsicsConfig StmtConfigFiller::submit( HlslShader & shader
		, AdaptationData & adaptationData
		, ast::stmt::Container * container )
	{
		IntrinsicsConfig result;
		StmtConfigFiller vis{ shader, adaptationData, result };
		container->accept( &vis );
		return result;
	}

	StmtConfigFiller::StmtConfigFiller( HlslShader & shader
		, AdaptationData & adaptationData
		, IntrinsicsConfig & result )
		: m_shader{ shader }
		, m_adaptationData{ adaptationData }
		, m_result{ result }
	{
	}

	void StmtConfigFiller::doSubmit( ast::expr::Expr * expr )
	{
		ExprConfigFiller::submit( expr, m_adaptationData, m_result );
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
		doSubmit( stmt->getCtrlExpr() );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseIfStmt( ast::stmt::ElseIf * stmt )
	{
		doSubmit( stmt->getCtrlExpr() );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitElseStmt( ast::stmt::Else * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitForStmt( ast::stmt::For * stmt )
	{
		doSubmit( stmt->getInitExpr() );
		doSubmit( stmt->getCtrlExpr() );
		doSubmit( stmt->getIncrExpr() );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )
	{
	}

	void StmtConfigFiller::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getFlags() && !isRayTraceStage( m_shader.getType() ) )
		{
			if ( !stmt->isEntryPoint() )
			{
				m_adaptationData.addEntryPoint( *stmt );
			}
			
			m_adaptationData.updateCurrentEntryPoint( stmt );
			m_adaptationData.initialiseEntryPoint( *stmt );
		}

		visitContainerStmt( stmt );

		m_adaptationData.updateCurrentEntryPoint( nullptr );
	}

	void StmtConfigFiller::visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * cont )
	{
	}

	void StmtConfigFiller::visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )
	{
		throw std::runtime_error{ "ast::stmt::BufferReferenceDecl are not supported in HLSL" };
	}

	void StmtConfigFiller::visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )
	{
	}

	void StmtConfigFiller::visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )
	{
	}

	void StmtConfigFiller::visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )
	{
	}

	void StmtConfigFiller::visitIfStmt( ast::stmt::If * stmt )
	{
		doSubmit( stmt->getCtrlExpr() );
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
	}

	void StmtConfigFiller::visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )
	{
	}

	void StmtConfigFiller::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		auto var = stmt->getVariable();

		if ( var->isShaderInput() )
		{
			m_adaptationData.addInputVar( var
				, stmt->getLocation() );
		}

		if ( var->isShaderOutput() )
		{
			m_adaptationData.addOutputVar( var
				, stmt->getLocation() );
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
		auto index = 0u;
		auto type = getNonArrayType( stmt->getType() );
		assert( type->getKind() == ast::type::Kind::eStruct );

		for ( auto & member : static_cast< ast::type::Struct const & >( *type ) )
		{
			auto name = ast::getName( member.builtin );
			auto var = ( m_shader.hasVar( name )
				? m_shader.getVar( name, member.type )
				: m_shader.registerBuiltin( member.builtin, member.type, 0u ) );

			if ( isOutput( stmt->getSource() ) )
			{
				m_adaptationData.addPendingOutput( var, index++ );
			}
			else
			{
				m_adaptationData.addPendingInput( var, index++ );
			}
		}
	}

	void StmtConfigFiller::visitReturnStmt( ast::stmt::Return * stmt )
	{
		if ( stmt->getExpr() )
		{
			doSubmit( stmt->getExpr() );
		}
	}

	void StmtConfigFiller::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
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
	}

	void StmtConfigFiller::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		doSubmit( stmt->getExpr() );
	}

	void StmtConfigFiller::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
	}

	void StmtConfigFiller::visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		doSubmit( stmt->getTestExpr()->getValue() );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )
	{
	}

	void StmtConfigFiller::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
	}

	void StmtConfigFiller::visitWhileStmt( ast::stmt::While * stmt )
	{
		doSubmit( stmt->getCtrlExpr() );
		visitContainerStmt( stmt );
	}

	void StmtConfigFiller::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
		doSubmit( preproc->getExpr() );
	}

	void StmtConfigFiller::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
		doSubmit( preproc->getCtrlExpr() );
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
		doSubmit( preproc->getCtrlExpr() );
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
		visitContainerStmt( preproc );
	}

	void StmtConfigFiller::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
	}
}
