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
#include "StmtComment.hpp"
#include "StmtCompound.hpp"
#include "StmtContainer.hpp"
#include "StmtConstantBufferDecl.hpp"
#include "StmtDiscard.hpp"
#include "StmtDoWhile.hpp"
#include "StmtElse.hpp"
#include "StmtElseIf.hpp"
#include "StmtFor.hpp"
#include "StmtFunctionDecl.hpp"
#include "StmtIf.hpp"
#include "StmtImageDecl.hpp"
#include "StmtInOutVariableDecl.hpp"
#include "StmtInputComputeLayout.hpp"
#include "StmtInputGeometryLayout.hpp"
#include "StmtOutputGeometryLayout.hpp"
#include "StmtPerVertexDecl.hpp"
#include "StmtPushConstantsBufferDecl.hpp"
#include "StmtReturn.hpp"
#include "StmtSamplerDecl.hpp"
#include "StmtShaderBufferDecl.hpp"
#include "StmtSimple.hpp"
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
		Visitor()
		{
		};

	public:
		virtual ~Visitor()
		{
		};

		virtual void visitCommentStmt( Comment * ) = 0;
		virtual void visitCompoundStmt( Compound * ) = 0;
		virtual void visitContainerStmt( Container * ) = 0;
		virtual void visitConstantBufferDeclStmt( ConstantBufferDecl * ) = 0;
		virtual void visitDiscardStmt( Discard * ) = 0;
		virtual void visitDoWhileStmt( DoWhile * ) = 0;
		virtual void visitElseIfStmt( ElseIf * ) = 0;
		virtual void visitElseStmt( Else * ) = 0;
		virtual void visitForStmt( For * ) = 0;
		virtual void visitFunctionDeclStmt( FunctionDecl * ) = 0;
		virtual void visitIfStmt( If * ) = 0;
		virtual void visitImageDeclStmt( ImageDecl * ) = 0;
		virtual void visitInOutVariableDeclStmt( InOutVariableDecl * ) = 0;
		virtual void visitInputComputeLayoutStmt( InputComputeLayout * ) = 0;
		virtual void visitInputGeometryLayoutStmt( InputGeometryLayout * ) = 0;
		virtual void visitOutputGeometryLayoutStmt( OutputGeometryLayout * ) = 0;
		virtual void visitPerVertexDeclStmt( PerVertexDecl * ) = 0;
		virtual void visitPushConstantsBufferDeclStmt( PushConstantsBufferDecl * ) = 0;
		virtual void visitReturnStmt( Return * ) = 0;
		virtual void visitSamplerDeclStmt( SamplerDecl * ) = 0;
		virtual void visitShaderBufferDeclStmt( ShaderBufferDecl * ) = 0;
		virtual void visitSimpleStmt( Simple * ) = 0;
		virtual void visitStructureDeclStmt( StructureDecl * ) = 0;
		virtual void visitSwitchCaseStmt( SwitchCase * ) = 0;
		virtual void visitSwitchStmt( Switch * ) = 0;
		virtual void visitVariableDeclStmt( VariableDecl * ) = 0;
		virtual void visitWhileStmt( While * ) = 0;
		virtual void visitPreprocDefine( PreprocDefine * ) = 0;
		virtual void visitPreprocElif( PreprocElif * ) = 0;
		virtual void visitPreprocElse( PreprocElse * ) = 0;
		virtual void visitPreprocEndif( PreprocEndif * ) = 0;
		virtual void visitPreprocExtension( PreprocExtension * ) = 0;
		virtual void visitPreprocIf( PreprocIf * ) = 0;
		virtual void visitPreprocIfDef( PreprocIfDef * ) = 0;
		virtual void visitPreprocVersion( PreprocVersion * ) = 0;
	};
};

#endif
