/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GLSLStmtVisitor_H___
#define ___SDW_GLSLStmtVisitor_H___
#pragma once

#include "CompilerGlsl/compileGlsl.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

namespace glsl
{
	class StmtVisitor
		: public ast::stmt::Visitor
	{
	public:
		static std::string submit( GlslConfig const & writerConfig
			, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
			, ast::stmt::Stmt * stmt
			, std::string indent = std::string{} );

	private:
		StmtVisitor( GlslConfig const & writerConfig
			, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
			, std::string & result
			, std::string indent );
		std::string doSubmit( ast::expr::Expr * expr );
		void doAppendLineEnd();
		void visitContainerStmt( ast::stmt::Container * stmt )override;
		void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * cont )override;
		void visitBreakStmt( ast::stmt::Break * stmt )override;
		void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )override;
		void visitContinueStmt( ast::stmt::Continue * stmt )override;
		void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override;
		void visitDemoteStmt( ast::stmt::Demote * stmt )override;
		void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )override;
		void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override;
		void visitCommentStmt( ast::stmt::Comment * stmt )override;
		void visitCompoundStmt( ast::stmt::Compound * stmt )override;
		void visitDoWhileStmt( ast::stmt::DoWhile * stmt )override;
		void visitElseIfStmt( ast::stmt::ElseIf * stmt )override;
		void visitElseStmt( ast::stmt::Else * stmt )override;
		void visitForStmt( ast::stmt::For * stmt )override;
		void visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )override;
		void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override;
		void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )override;
		void visitIfStmt( ast::stmt::If * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )override;
		void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )override;
		void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )override;
		void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override;
		void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override;
		void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override;
		void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override;
		void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * )override;
		void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override;
		void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )override;
		void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override;
		void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )override;
		void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override;
		void visitReturnStmt( ast::stmt::Return * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override;
		void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitSimpleStmt( ast::stmt::Simple * stmt )override;
		void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override;
		void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override;
		void visitSwitchStmt( ast::stmt::Switch * stmt )override;
		void visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )override;
		void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override;
		void visitWhileStmt( ast::stmt::While * stmt )override;
		void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( ast::stmt::PreprocElif * preproc )override;
		void visitPreprocElse( ast::stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override;
		void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override;
		void visitPreprocIf( ast::stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override;
		void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override;

		void doWriteBinding( uint32_t binding
			, uint32_t set
			, std::string sep );

	private:
		GlslConfig const & m_writerConfig;
		std::map< ast::var::VariablePtr, ast::expr::Expr * > & m_aliases;
		std::string m_indent;
		bool m_appendSemiColon{ false };
		bool m_appendLineEnd{ false };
		std::string & m_result;
	};
}

#endif
