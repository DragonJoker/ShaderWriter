/*
See LICENSE file in root folder
*/
#include "ShaderAST/Debug/DebugStmtVisitor.hpp"

#include "ShaderAST/Debug/DebugCommon.hpp"
#include "ShaderAST/Debug/DebugExprVisitor.hpp"

namespace ast::debug
{
	namespace
	{
		std::string getName( stmt::Kind kind )
		{
			std::string result;

			switch ( kind )
			{
			case ast::stmt::Kind::eSimple:
				result = "STSIMPLE";
				break;
			case ast::stmt::Kind::eContainer:
				result = "STCONTAINER";
				break;
			case ast::stmt::Kind::eCompound:
				result = "STCOMPOUNT";
				break;
			case ast::stmt::Kind::eComment:
				result = "STCOMMENT";
				break;
			case ast::stmt::Kind::eVariableDecl:
				result = "STVARDECL";
				break;
			case ast::stmt::Kind::ePerVertexDecl:
				result = "STPERVERTEXDECL";
				break;
			case ast::stmt::Kind::eInOutVariableDecl:
				result = "STINOUTVARDECL";
				break;
			case ast::stmt::Kind::eSpecialisationConstantDecl:
				result = "STSPECCONSTDECL";
				break;
			case ast::stmt::Kind::eConstantBufferDecl:
				result = "STCBUFFDECL";
				break;
			case ast::stmt::Kind::ePushConstantsBufferDecl:
				result = "STPCBUFFDECL";
				break;
			case ast::stmt::Kind::eShaderBufferDecl:
				result = "STSHADBUFFDECL";
				break;
			case ast::stmt::Kind::eShaderStructBufferDecl:
				result = "STSHADSTRUCTBUFFDECL";
				break;
			case ast::stmt::Kind::eSamplerDecl:
				result = "STSAMPLERDECL";
				break;
			case ast::stmt::Kind::eImageDecl:
				result = "STIMAGEDECL";
				break;
			case ast::stmt::Kind::eSampledImageDecl:
				result = "STSAMPLEDIMGDECL";
				break;
			case ast::stmt::Kind::eFunctionDecl:
				result = "STFUNCDECL";
				break;
			case ast::stmt::Kind::eStructureDecl:
				result = "STSTRUCTDECL";
				break;
			case ast::stmt::Kind::eIf:
				result = "STIF";
				break;
			case ast::stmt::Kind::eElse:
				result = "STELSE";
				break;
			case ast::stmt::Kind::eElseIf:
				result = "STELSEIF";
				break;
			case ast::stmt::Kind::eWhile:
				result = "STWHILE";
				break;
			case ast::stmt::Kind::eFor:
				result = "STFOR";
				break;
			case ast::stmt::Kind::eDoWhile:
				result = "STDOWHILE";
				break;
			case ast::stmt::Kind::eSwitch:
				result = "STSWITCH";
				break;
			case ast::stmt::Kind::eSwitchCase:
				result = "STSWCASE";
				break;
			case ast::stmt::Kind::eReturn:
				result = "STRETURN";
				break;
			case ast::stmt::Kind::eBreak:
				result = "STBREAK";
				break;
			case ast::stmt::Kind::eContinue:
				result = "STCONTINUE";
				break;
			case ast::stmt::Kind::eDiscard:
				result = "STDISCARD";
				break;
			case ast::stmt::Kind::eInputGeometryLayout:
				result = "STINGEOMLAYOUT";
				break;
			case ast::stmt::Kind::eOutputGeometryLayout:
				result = "STOUTGEOMLAYOUT";
				break;
			case ast::stmt::Kind::eInputComputeLayout:
				result = "STINCOMPLAYOUT";
				break;
			case ast::stmt::Kind::ePreprocDefine:
				result = "STPRDEFINE";
				break;
			case ast::stmt::Kind::ePreprocIf:
				result = "STPRIF";
				break;
			case ast::stmt::Kind::ePreprocElif:
				result = "STPRELIF";
				break;
			case ast::stmt::Kind::ePreprocElse:
				result = "STPRELSE";
				break;
			case ast::stmt::Kind::ePreprocIfDef:
				result = "STPRIFDEF";
				break;
			case ast::stmt::Kind::ePreprocEndif:
				result = "STPRENDIF";
				break;
			case ast::stmt::Kind::ePreprocExtension:
				result = "STPREXTENSION";
				break;
			case ast::stmt::Kind::ePreprocVersion:
				result = "STPRVERSION";
				break;
			case ast::stmt::Kind::eFragmentLayout:
				result = "STFRAGLAYOUT";
				break;
			case ast::stmt::Kind::eOutputTessellationControlLayout:
				result = "STOUTTESSCLAYOUT";
				break;
			case ast::stmt::Kind::eInputTessellationEvaluationLayout:
				result = "STINTESSELAYOUT";
				break;
			case ast::stmt::Kind::eAccelerationStructureDecl:
				result = "STACCSTRUCTDECL";
				break;
			case ast::stmt::Kind::eInOutRayPayloadVariableDecl:
				result = "STINOUTRAYPAYLOADDECL";
				break;
			case ast::stmt::Kind::eHitAttributeVariableDecl:
				result = "STHITATTRDECL";
				break;
			case ast::stmt::Kind::eInOutCallableDataVariableDecl:
				result = "STINOUTCALLDATADECL";
				break;
			case ast::stmt::Kind::eBufferReferenceDecl:
				result = "STBUFREFDECL";
				break;
			case ast::stmt::Kind::eIgnoreIntersection:
				result = "STIGNOREINTER";
				break;
			case ast::stmt::Kind::eTerminateRay:
				result = "STTERMRAY";
				break;
			default:
				AST_Failure( "Unknown statement kind ?" );
				break;
			}

			return result;
		}
	}

	StmtVisitor::StmtVisitor( std::string & result
		, std::string indent )
		: m_indent{ std::move( indent ) }
		, m_result{ result }
	{
	}

	std::string StmtVisitor::submit( stmt::Stmt * stmt
		, std::string indent )
	{
		std::string result;
		StmtVisitor vis{ result, std::move( indent ) };
		stmt->accept( &vis );
		return result;
	}

	std::string & StmtVisitor::displayStmtName( stmt::Stmt * stmt, bool newLine )
	{
		m_result += m_indent + getName( stmt->getKind() ) + ( newLine ? "\n" : " " );
		return m_result;
	}

	void StmtVisitor::visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "B(";
		m_result += std::to_string( stmt->getBindingPoint() ) + ") D(";
		m_result += std::to_string( stmt->getDescriptorSet() ) + ") ";
		m_result += displayVar( stmt->getVariable() ) + "\n";
	}

	void StmtVisitor::visitBreakStmt( stmt::Break * stmt )
	{
		displayStmtName( stmt, true );
	}

	void StmtVisitor::visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += getName( stmt->getType() ) + "\n";
	}

	void StmtVisitor::visitCommentStmt( stmt::Comment * stmt )
	{
		displayStmtName( stmt, false );
		m_result += m_indent + stmt->getText() + "\n";
	}

	void StmtVisitor::visitCompoundStmt( stmt::Compound * stmt )
	{
		if ( m_compoundName )
		{
			displayStmtName( stmt, true );
		}

		auto save = m_indent;
		m_indent += "\t";
		visitContainerStmt( stmt );
		m_indent = save;
		m_compoundName = true;
	}

	void StmtVisitor::visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += stmt->getName() + " B(";
		m_result += std::to_string( stmt->getBindingPoint() ) + ") D(";
		m_result += std::to_string( stmt->getDescriptorSet() ) + ") L(";
		m_result += getName( stmt->getMemoryLayout() ) + ")\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitContainerStmt( stmt::Container * stmt )
	{
		for ( auto & curStmt : *stmt )
		{
			curStmt->accept( this );
		}
	}

	void StmtVisitor::visitContinueStmt( stmt::Continue * stmt )
	{
		displayStmtName( stmt, true );
	}

	void StmtVisitor::visitDiscardStmt( stmt::Discard * stmt )
	{
		displayStmtName( stmt, true );
	}

	void StmtVisitor::visitDoWhileStmt( stmt::DoWhile * stmt )
	{
		displayStmtName( stmt, false );
		m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitElseIfStmt( stmt::ElseIf * stmt )
	{
		displayStmtName( stmt, false );
		m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitElseStmt( stmt::Else * stmt )
	{
		displayStmtName( stmt, true );
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitForStmt( stmt::For * stmt )
	{
		displayStmtName( stmt, false );
		m_result += ExprVisitor::submit( stmt->getInitExpr() ) + ", ";
		m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + ", ";
		m_result += ExprVisitor::submit( stmt->getIncrExpr() ) + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitFragmentLayoutStmt( stmt::FragmentLayout * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "O(" + getName( stmt->getFragmentOrigin() ) + "), ";
		m_result += "C(" + getName( stmt->getFragmentCenter() ) + ")\n";
	}

	void StmtVisitor::visitFunctionDeclStmt( stmt::FunctionDecl * stmt )
	{
		displayStmtName( stmt, false );
		auto type = stmt->getType();
		m_result += getName( *type->getReturnType() );
		m_result += " " + stmt->getName() + "(";
		std::string sep;

		for ( auto & param : *type )
		{
			m_result += sep;
			m_result += displayVar( param );
			sep = ", ";
		}

		m_result += ")\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitIfStmt( stmt::If * stmt )
	{
		displayStmtName( stmt, false );
		m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );

		for ( auto & elseIf : stmt->getElseIfList() )
		{
			elseIf->accept( this );
		}

		if ( stmt->getElse() )
		{
			stmt->getElse()->accept( this );
		}
	}

	void StmtVisitor::visitImageDeclStmt( stmt::ImageDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += " B(";
		m_result += std::to_string( stmt->getBindingPoint() ) + ") D(";
		m_result += std::to_string( stmt->getDescriptorSet() ) + ") ";
		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitIgnoreIntersectionStmt( stmt::IgnoreIntersection * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "\n";
	}

	void StmtVisitor::visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )
	{
		displayStmtName( stmt, false );

		if ( stmt->getVariable()->isShaderConstant() )
		{
			m_result += "CONST";
		}
		else if ( stmt->getVariable()->isPushConstant() )
		{
			m_result += "PUSH";
		}
		else if ( stmt->getVariable()->isShaderInput()
			|| stmt->getVariable()->isShaderOutput() )
		{
			m_result += "LOC";
		}

		m_result += "(" + std::to_string( stmt->getLocation() ) + ") ";

		if ( stmt->getVariable()->isBlendIndex() )
		{
			m_result += "BLEND(" + std::to_string( stmt->getBlendIndex() ) + ") ";
		}

		if ( stmt->getVariable()->isGeometryStream() )
		{
			m_result += "STREAM(" + std::to_string( stmt->getStreamIndex() ) + ") ";
		}

		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "SPECCONST";
		m_result += "(" + std::to_string( stmt->getLocation() ) + ") ";
		m_result += displayVar( stmt->getVariable() );
		m_result += ExprVisitor::submit( stmt->getValue() );
		m_result += "\n";
	}

	void StmtVisitor::visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "X(" + std::to_string( stmt->getWorkGroupsX() ) + ")"
			+ " Y(" + std::to_string( stmt->getWorkGroupsY() ) + ")"
			+ " Z(" + std::to_string( stmt->getWorkGroupsZ() ) + ")\n";
	}

	void StmtVisitor::visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "L(" + getName( stmt->getLayout() ) + ")\n";
	}

	void StmtVisitor::visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "L(" + getName( stmt->getDomain() );
		m_result += "," + getName( stmt->getPartitioning() );
		m_result += "," + getName( stmt->getPrimitiveOrdering() );
		m_result += ")\n";
	}

	void StmtVisitor::visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "L(" + getName( stmt->getLayout() );
		m_result += ") C(" + std::to_string( stmt->getPrimCount() ) + ")\n";
	}

	void StmtVisitor::visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "L(" + getName( stmt->getDomain() );
		m_result += "," + getName( stmt->getPartitioning() );
		m_result += "," + getName( stmt->getTopology() );
		m_result += "," + getName( stmt->getPrimitiveOrdering() );
		m_result += ") C(" + std::to_string( stmt->getOutputVertices() ) + ")\n";
	}

	void StmtVisitor::visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )
	{
		displayStmtName( stmt, false );

		switch ( stmt->getSource() )
		{
		case stmt::PerVertexDecl::Source::eVertexOutput:
			m_result += "VERTOUT";
			break;
		case stmt::PerVertexDecl::Source::eTessellationControlInput:
			m_result += "TESSCIN";
			break;
		case stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
			m_result += "TESSEIN";
			break;
		case stmt::PerVertexDecl::Source::eTessellationControlOutput:
			m_result += "TESSCOUT";
			break;
		case stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
			m_result += "TESSEOUT";
			break;
		case stmt::PerVertexDecl::Source::eGeometryInput:
			m_result += "GEOMIN";
			break;
		case stmt::PerVertexDecl::Source::eGeometryOutput:
			m_result += "GEOMOUT";
			break;
		}
		m_result += "(" + getName( stmt->getType() ) + ")\n";
	}

	void StmtVisitor::visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += stmt->getName() + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += " L(";
		m_result += std::to_string( stmt->getLocation() ) + ") ";
		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += " L(";
		m_result += std::to_string( stmt->getLocation() ) + ") ";
		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitReturnStmt( stmt::Return * stmt )
	{
		displayStmtName( stmt, false );

		if ( stmt->getExpr() )
		{
			m_result += ExprVisitor::submit( stmt->getExpr() ) + " ";
		}

		m_result += "\n";
	}

	void StmtVisitor::visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += " B(";
		m_result += std::to_string( stmt->getBindingPoint() ) + ") D(";
		m_result += std::to_string( stmt->getDescriptorSet() ) + ") ";
		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitSamplerDeclStmt( stmt::SamplerDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += " B(";
		m_result += std::to_string( stmt->getBindingPoint() ) + ") D(";
		m_result += std::to_string( stmt->getDescriptorSet() ) + ") ";
		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += " B(";
		m_result += std::to_string( stmt->getBindingPoint() ) + ") D(";
		m_result += std::to_string( stmt->getDescriptorSet() ) + ") L(";
		m_result += getName( stmt->getMemoryLayout() ) + ") ";
		m_result += stmt->getSsboName() + ", ";
		m_result += displayVar( stmt->getVariable() ) + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += " B(";
		m_result += std::to_string( stmt->getBindingPoint() ) + ") D(";
		m_result += std::to_string( stmt->getDescriptorSet() ) + ") L(";
		m_result += getName( stmt->getMemoryLayout() ) + ") ";
		m_result += stmt->getSsboName() + ", ";
		m_result += displayVar( stmt->getSsboInstance() ) + "\n";
		m_result += "\t" + displayVar( stmt->getData() ) + "\n";
	}

	void StmtVisitor::visitSimpleStmt( stmt::Simple * stmt )
	{
		displayStmtName( stmt, false );
		m_result += ExprVisitor::submit( stmt->getExpr() ) + "\n";
	}

	void StmtVisitor::visitStructureDeclStmt( stmt::StructureDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += getName( stmt->getType() ) + "\n";

		if ( !stmt->getType()->empty() )
		{
			auto save = m_indent;
			m_indent += "\t";

			for ( auto & member : *stmt->getType() )
			{
				m_result += m_indent;
				m_result += getName( *member.type );
				m_result += " " + member.name + "\n";
			}

			m_indent = save;
		}
	}

	void StmtVisitor::visitSwitchCaseStmt( stmt::SwitchCase * stmt )
	{
		displayStmtName( stmt, false );

		if ( stmt->getCaseExpr() )
		{
			m_result += ExprVisitor::submit( stmt->getCaseExpr() ) + "\n";
		}
		else
		{
			m_result += "DEFAULT\n";
		}

		if ( !stmt->empty() )
		{
			m_compoundName = false;
			visitCompoundStmt( stmt );
		}
	}

	void StmtVisitor::visitSwitchStmt( stmt::Switch * stmt )
	{
		displayStmtName( stmt, false );
		m_result += ExprVisitor::submit( stmt->getTestExpr() ) + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitTerminateRayStmt( stmt::TerminateRay * stmt )
	{
		displayStmtName( stmt, false );
		m_result += "\n";
	}

	void StmtVisitor::visitVariableDeclStmt( stmt::VariableDecl * stmt )
	{
		displayStmtName( stmt, false );
		m_result += displayVar( stmt->getVariable() );
		m_result += "\n";
	}

	void StmtVisitor::visitWhileStmt( stmt::While * stmt )
	{
		displayStmtName( stmt, false );
		m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + "\n";
		m_compoundName = false;
		visitCompoundStmt( stmt );
	}

	void StmtVisitor::visitPreprocDefine( stmt::PreprocDefine * preproc )
	{
		displayStmtName( preproc, false );
		m_result += preproc->getName() + " " + ExprVisitor::submit( preproc->getExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElif( stmt::PreprocElif * preproc )
	{
		displayStmtName( preproc, false );
		m_result += ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocElse( stmt::PreprocElse * preproc )
	{
		displayStmtName( preproc, true );
	}

	void StmtVisitor::visitPreprocEndif( stmt::PreprocEndif * preproc )
	{
		displayStmtName( preproc, true );
	}

	void StmtVisitor::visitPreprocExtension( stmt::PreprocExtension * preproc )
	{
		displayStmtName( preproc, false );
		m_result += preproc->getName();

		switch ( preproc->getStatus() )
		{
		case stmt::PreprocExtension::ExtStatus::eDisabled:
			m_result += " DISABLE";
			break;

		case stmt::PreprocExtension::ExtStatus::eEnabled:
			m_result += " ENABLE";
			break;

		case stmt::PreprocExtension::ExtStatus::eRequired:
			m_result += " REQUIRE";
			break;

		}
		m_result += "\n";
	}

	void StmtVisitor::visitPreprocIf( stmt::PreprocIf * preproc )
	{
		displayStmtName( preproc, false );
		m_result += ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocIfDef( stmt::PreprocIfDef * preproc )
	{
		displayStmtName( preproc, false );
		m_result += ExprVisitor::submit( preproc->getIdentExpr() ) + "\n";
	}

	void StmtVisitor::visitPreprocVersion( stmt::PreprocVersion * preproc )
	{
		displayStmtName( preproc, false );
		m_result += preproc->getName() + "\n";
	}
}
