/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugStmtVisitor_H___
#define ___AST_DebugStmtVisitor_H___
#pragma once

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::debug
{
	class StmtVisitor
		: public stmt::Visitor
	{
	protected:
		StmtVisitor( std::string & result
			, std::string indent );

	public:
		static std::string submit( stmt::Stmt * stmt
			, std::string indent = std::string{} );

	private:
		void visitCompoundStmt( stmt::Compound * stmt )override;
		void visitContainerStmt( stmt::Container * stmt )override;
		void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override;
		void visitDoWhileStmt( stmt::DoWhile * stmt )override;
		void visitElseIfStmt( stmt::ElseIf * stmt )override;
		void visitElseStmt( stmt::Else * stmt )override;
		void visitForStmt( stmt::For * stmt )override;
		void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override;
		void visitIfStmt( stmt::If * stmt )override;
		void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override;
		void visitReturnStmt( stmt::Return * stmt )override;
		void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override;
		void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override;
		void visitSimpleStmt( stmt::Simple * stmt )override;
		void visitStructureDeclStmt( stmt::StructureDecl * stmt )override;
		void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override;
		void visitSwitchStmt( stmt::Switch * stmt )override;
		void visitVariableDeclStmt( stmt::VariableDecl * stmt )override;
		void visitWhileStmt( stmt::While * stmt )override;
		void visitPreprocDefine( stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( stmt::PreprocElif * preproc )override;
		void visitPreprocElse( stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( stmt::PreprocEndif * preproc )override;
		void visitPreprocExtension( stmt::PreprocExtension * preproc )override;
		void visitPreprocIf( stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( stmt::PreprocIfDef * preproc )override;
		void visitPreprocVersion( stmt::PreprocVersion * preproc )override;

	private:
		std::string m_indent;
		bool m_appendSemiColon{ false };
		std::string & m_result;
	};
};

#endif
