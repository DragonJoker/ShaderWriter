/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtVisitor_H___
#define ___AST_StmtVisitor_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtDoWhile.hpp"
#include "StmtElse.hpp"
#include "StmtFor.hpp"
#include "StmtFunctionDecl.hpp"
#include "StmtIf.hpp"
#include "StmtSimple.hpp"
#include "StmtStructureDecl.hpp"
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
		virtual void visitElseStmt( StmtElse * ) = 0;
		virtual void visitForStmt( StmtFor * ) = 0;
		virtual void visitFunctionDeclStmt( StmtFunctionDecl * ) = 0;
		virtual void visitIfStmt( StmtIf * ) = 0;
		virtual void visitSimpleStmt( StmtSimple * ) = 0;
		virtual void visitStructureDeclStmt( StmtStructureDecl * ) = 0;
		virtual void visitVariableDeclStmt( StmtVariableDecl * ) = 0;
		virtual void visitWhileStmt( StmtWhile * ) = 0;
	};
};

#endif
