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
#include "StmtCompound.hpp"
#include "StmtDoWhile.hpp"
#include "StmtElse.hpp"
#include "StmtElseIf.hpp"
#include "StmtFor.hpp"
#include "StmtFunctionDecl.hpp"
#include "StmtIf.hpp"
#include "StmtReturn.hpp"
#include "StmtSimple.hpp"
#include "StmtStructureDecl.hpp"
#include "StmtSwitchCase.hpp"
#include "StmtSwitch.hpp"
#include "StmtVariableDecl.hpp"
#include "StmtWhile.hpp"

namespace ast
{
	class StmtVisitor
	{
	protected:
		StmtVisitor()
		{
		};

	public:
		virtual ~StmtVisitor()
		{
		};

		virtual void visitCompoundStmt( StmtCompound * ) = 0;
		virtual void visitDoWhileStmt( StmtDoWhile * ) = 0;
		virtual void visitElseIfStmt( StmtElseIf * ) = 0;
		virtual void visitElseStmt( StmtElse * ) = 0;
		virtual void visitForStmt( StmtFor * ) = 0;
		virtual void visitFunctionDeclStmt( StmtFunctionDecl * ) = 0;
		virtual void visitIfStmt( StmtIf * ) = 0;
		virtual void visitReturnStmt( StmtReturn * ) = 0;
		virtual void visitSimpleStmt( StmtSimple * ) = 0;
		virtual void visitStructureDeclStmt( StmtStructureDecl * ) = 0;
		virtual void visitSwitchCaseStmt( StmtSwitchCase * ) = 0;
		virtual void visitSwitchStmt( StmtSwitch * ) = 0;
		virtual void visitVariableDeclStmt( StmtVariableDecl * ) = 0;
		virtual void visitWhileStmt( StmtWhile * ) = 0;
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
