/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtVisitor_H___
#define ___AST_StmtVisitor_H___
#pragma once

#include "PreprocDefine.hpp"
#include "PreprocElif.hpp"
#include "PreprocElse.hpp"
#include "PreprocEndif.hpp"
#include "PreprocExtension.hpp"
#include "PreprocIf.hpp"
#include "PreprocIfDef.hpp"
#include "PreprocVersion.hpp"
#include "StmtBreak.hpp"
#include "StmtComment.hpp"
#include "StmtCompound.hpp"
#include "StmtContainer.hpp"
#include "StmtContinue.hpp"
#include "StmtConstantBufferDecl.hpp"
#include "StmtDiscard.hpp"
#include "StmtDoWhile.hpp"
#include "StmtElse.hpp"
#include "StmtElseIf.hpp"
#include "StmtFor.hpp"
#include "StmtFragmentLayout.hpp"
#include "StmtFunctionDecl.hpp"
#include "StmtIf.hpp"
#include "StmtImageDecl.hpp"
#include "StmtInOutVariableDecl.hpp"
#include "StmtInputComputeLayout.hpp"
#include "StmtInputGeometryLayout.hpp"
#include "StmtOutputGeometryLayout.hpp"
#include "StmtOutputTessellationControlLayout.hpp"
#include "StmtPerVertexDecl.hpp"
#include "StmtPushConstantsBufferDecl.hpp"
#include "StmtReturn.hpp"
#include "StmtSampledImageDecl.hpp"
#include "StmtSamplerDecl.hpp"
#include "StmtShaderBufferDecl.hpp"
#include "StmtShaderStructBufferDecl.hpp"
#include "StmtSimple.hpp"
#include "StmtSpecialisationConstantDecl.hpp"
#include "StmtStructureDecl.hpp"
#include "StmtSwitchCase.hpp"
#include "StmtSwitch.hpp"
#include "StmtVariableDecl.hpp"
#include "StmtWhile.hpp"

namespace ast::stmt
{
	class Visitor
	{
	protected:
		SDAST_API Visitor()
		{
		}

	public:
		SDAST_API virtual ~Visitor()noexcept = default;

		SDAST_API virtual void visitBreakStmt( Break * ) = 0;
		SDAST_API virtual void visitCommentStmt( Comment * ) = 0;
		SDAST_API virtual void visitCompoundStmt( Compound * ) = 0;
		SDAST_API virtual void visitContainerStmt( Container * ) = 0;
		SDAST_API virtual void visitContinueStmt( Continue * ) = 0;
		SDAST_API virtual void visitConstantBufferDeclStmt( ConstantBufferDecl * ) = 0;
		SDAST_API virtual void visitDiscardStmt( Discard * ) = 0;
		SDAST_API virtual void visitDoWhileStmt( DoWhile * ) = 0;
		SDAST_API virtual void visitElseIfStmt( ElseIf * ) = 0;
		SDAST_API virtual void visitElseStmt( Else * ) = 0;
		SDAST_API virtual void visitForStmt( For * ) = 0;
		SDAST_API virtual void visitFragmentLayout( FragmentLayout * ) = 0;
		SDAST_API virtual void visitFunctionDeclStmt( FunctionDecl * ) = 0;
		SDAST_API virtual void visitIfStmt( If * ) = 0;
		SDAST_API virtual void visitImageDeclStmt( ImageDecl * ) = 0;
		SDAST_API virtual void visitInOutVariableDeclStmt( InOutVariableDecl * ) = 0;
		SDAST_API virtual void visitInputComputeLayoutStmt( InputComputeLayout * ) = 0;
		SDAST_API virtual void visitInputGeometryLayoutStmt( InputGeometryLayout * ) = 0;
		SDAST_API virtual void visitOutputGeometryLayoutStmt( OutputGeometryLayout * ) = 0;
		SDAST_API virtual void visitOutputTessellationControlLayoutStmt( OutputTessellationControlLayout * ) = 0;
		SDAST_API virtual void visitPerVertexDeclStmt( PerVertexDecl * ) = 0;
		SDAST_API virtual void visitPushConstantsBufferDeclStmt( PushConstantsBufferDecl * ) = 0;
		SDAST_API virtual void visitReturnStmt( Return * ) = 0;
		SDAST_API virtual void visitSampledImageDeclStmt( SampledImageDecl * ) = 0;
		SDAST_API virtual void visitSamplerDeclStmt( SamplerDecl * ) = 0;
		SDAST_API virtual void visitShaderBufferDeclStmt( ShaderBufferDecl * ) = 0;
		SDAST_API virtual void visitShaderStructBufferDeclStmt( ShaderStructBufferDecl * ) = 0;
		SDAST_API virtual void visitSimpleStmt( Simple * ) = 0;
		SDAST_API virtual void visitSpecialisationConstantDeclStmt( SpecialisationConstantDecl * ) = 0;
		SDAST_API virtual void visitStructureDeclStmt( StructureDecl * ) = 0;
		SDAST_API virtual void visitSwitchCaseStmt( SwitchCase * ) = 0;
		SDAST_API virtual void visitSwitchStmt( Switch * ) = 0;
		SDAST_API virtual void visitVariableDeclStmt( VariableDecl * ) = 0;
		SDAST_API virtual void visitWhileStmt( While * ) = 0;
		SDAST_API virtual void visitPreprocDefine( PreprocDefine * ) = 0;
		SDAST_API virtual void visitPreprocElif( PreprocElif * ) = 0;
		SDAST_API virtual void visitPreprocElse( PreprocElse * ) = 0;
		SDAST_API virtual void visitPreprocEndif( PreprocEndif * ) = 0;
		SDAST_API virtual void visitPreprocExtension( PreprocExtension * ) = 0;
		SDAST_API virtual void visitPreprocIf( PreprocIf * ) = 0;
		SDAST_API virtual void visitPreprocIfDef( PreprocIfDef * ) = 0;
		SDAST_API virtual void visitPreprocVersion( PreprocVersion * ) = 0;
	};
}

#endif
