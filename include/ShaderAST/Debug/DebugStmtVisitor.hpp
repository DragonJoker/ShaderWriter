/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugStmtVisitor_H___
#define ___AST_DebugStmtVisitor_H___
#pragma once

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::debug
{
	class StmtVisitor
		: public stmt::Visitor
	{
	protected:
		SDAST_API StmtVisitor( std::string & result
			, std::string indent );

	public:
		SDAST_API static std::string submit( stmt::Stmt * stmt
			, std::string indent = std::string{} );

	private:
		SDAST_API std::string & displayStmtName( stmt::Stmt * stmt, bool newLine );
		SDAST_API void visitBreakStmt( stmt::Break * stmt )override;
		SDAST_API void visitCommentStmt( stmt::Comment * stmt )override;
		SDAST_API void visitCompoundStmt( stmt::Compound * stmt )override;
		SDAST_API void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override;
		SDAST_API void visitContainerStmt( stmt::Container * stmt )override;
		SDAST_API void visitContinueStmt( stmt::Continue * stmt )override;
		SDAST_API void visitDiscardStmt( stmt::Discard * stmt )override;
		SDAST_API void visitDoWhileStmt( stmt::DoWhile * stmt )override;
		SDAST_API void visitElseIfStmt( stmt::ElseIf * stmt )override;
		SDAST_API void visitElseStmt( stmt::Else * stmt )override;
		SDAST_API void visitForStmt( stmt::For * stmt )override;
		SDAST_API void visitFragmentLayout( stmt::FragmentLayout * stmt )override;
		SDAST_API void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override;
		SDAST_API void visitIfStmt( stmt::If * stmt )override;
		SDAST_API void visitImageDeclStmt( stmt::ImageDecl * stmt )override;
		SDAST_API void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override;
		SDAST_API void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )override;
		SDAST_API void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override;
		SDAST_API void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override;
		SDAST_API void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )override;
		SDAST_API void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override;
		SDAST_API void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override;
		SDAST_API void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override;
		SDAST_API void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override;
		SDAST_API void visitReturnStmt( stmt::Return * stmt )override;
		SDAST_API void visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )override;
		SDAST_API void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override;
		SDAST_API void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override;
		SDAST_API void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )override;
		SDAST_API void visitSimpleStmt( stmt::Simple * stmt )override;
		SDAST_API void visitStructureDeclStmt( stmt::StructureDecl * stmt )override;
		SDAST_API void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override;
		SDAST_API void visitSwitchStmt( stmt::Switch * stmt )override;
		SDAST_API void visitVariableDeclStmt( stmt::VariableDecl * stmt )override;
		SDAST_API void visitWhileStmt( stmt::While * stmt )override;
		SDAST_API void visitPreprocDefine( stmt::PreprocDefine * preproc )override;
		SDAST_API void visitPreprocElif( stmt::PreprocElif * preproc )override;
		SDAST_API void visitPreprocElse( stmt::PreprocElse * preproc )override;
		SDAST_API void visitPreprocEndif( stmt::PreprocEndif * preproc )override;
		SDAST_API void visitPreprocExtension( stmt::PreprocExtension * preproc )override;
		SDAST_API void visitPreprocIf( stmt::PreprocIf * preproc )override;
		SDAST_API void visitPreprocIfDef( stmt::PreprocIfDef * preproc )override;
		SDAST_API void visitPreprocVersion( stmt::PreprocVersion * preproc )override;

	private:
		std::string m_indent;
		bool m_compoundName{ false };
		std::string & m_result;
	};
}

#endif
