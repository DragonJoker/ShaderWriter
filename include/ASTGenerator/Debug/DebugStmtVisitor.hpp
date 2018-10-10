/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugStmtVisitor_H___
#define ___AST_DebugStmtVisitor_H___
#pragma once

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	class DebugStmtVisitor
		: public StmtVisitor
	{
	protected:
		DebugStmtVisitor( std::string & result
			, std::string indent );

	public:
		static std::string submit( Stmt * stmt
			, std::string indent = std::string{} );

	private:
		void visitCompoundStmt( StmtCompound * stmt )override;
		void visitDoWhileStmt( StmtDoWhile * stmt )override;
		void visitElseIfStmt( StmtElseIf * stmt )override;
		void visitElseStmt( StmtElse * stmt )override;
		void visitForStmt( StmtFor * stmt )override;
		void visitFunctionDeclStmt( StmtFunctionDecl * stmt )override;
		void visitIfStmt( StmtIf * stmt )override;
		void visitReturnStmt( StmtReturn * stmt )override;
		void visitSimpleStmt( StmtSimple * stmt )override;
		void visitStructureDeclStmt( StmtStructureDecl * stmt )override;
		void visitSwitchCaseStmt( StmtSwitchCase * stmt )override;
		void visitSwitchStmt( StmtSwitch * stmt )override;
		void visitVariableDeclStmt( StmtVariableDecl * stmt )override;
		void visitWhileStmt( StmtWhile * stmt )override;
		void visitPreprocDefine( PreprocDefine * preproc )override;
		void visitPreprocElif( PreprocElif * preproc )override;
		void visitPreprocElse( PreprocElse * preproc )override;
		void visitPreprocEndif( PreprocEndif * preproc )override;
		void visitPreprocExtension( PreprocExtension * preproc )override;
		void visitPreprocIf( PreprocIf * preproc )override;
		void visitPreprocIfDef( PreprocIfDef * preproc )override;
		void visitPreprocVersion( PreprocVersion * preproc )override;

	private:
		std::string m_indent;
		bool m_appendSemiColon{ false };
		std::string & m_result;
	};
};

#endif
