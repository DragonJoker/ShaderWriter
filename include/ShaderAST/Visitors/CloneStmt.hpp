/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CloneStmt_H___
#define ___SDW_CloneStmt_H___
#pragma once

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast
{
	class StmtCloner
		: public stmt::Visitor
	{
	public:
		SDAST_API static stmt::ContainerPtr submit( stmt::Container * stmt );

	protected:
		SDAST_API StmtCloner( stmt::ContainerPtr & result );

	protected:
		SDAST_API virtual expr::ExprPtr doSubmit( expr::Expr * expr );

		SDAST_API void visitContainerStmt( stmt::Container * cont )override;
		SDAST_API void visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl * stmt )override;
		SDAST_API void visitBreakStmt( stmt::Break * stmt )override;
		SDAST_API void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl * stmt )override;
		SDAST_API void visitContinueStmt( stmt::Continue * stmt )override;
		SDAST_API void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override;
		SDAST_API void visitDemoteStmt( stmt::Demote * stmt )override;
		SDAST_API void visitTerminateInvocationStmt( stmt::TerminateInvocation * stmt )override;
		SDAST_API void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override;
		SDAST_API void visitCommentStmt( stmt::Comment * stmt )override;
		SDAST_API void visitCompoundStmt( stmt::Compound * stmt )override;
		SDAST_API void visitDoWhileStmt( stmt::DoWhile * stmt )override;
		SDAST_API void visitElseIfStmt( stmt::ElseIf * stmt )override;
		SDAST_API void visitElseStmt( stmt::Else * stmt )override;
		SDAST_API void visitForStmt( stmt::For * stmt )override;
		SDAST_API void visitFragmentLayoutStmt( stmt::FragmentLayout * stmt )override;
		SDAST_API void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override;
		SDAST_API void visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl * stmt )override;
		SDAST_API void visitIfStmt( stmt::If * stmt )override;
		SDAST_API void visitImageDeclStmt( stmt::ImageDecl * stmt )override;
		SDAST_API void visitIgnoreIntersectionStmt( stmt::IgnoreIntersection * stmt )override;
		SDAST_API void visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl * stmt )override;
		SDAST_API void visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl * stmt )override;
		SDAST_API void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override;
		SDAST_API void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )override;
		SDAST_API void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override;
		SDAST_API void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override;
		SDAST_API void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override;
		SDAST_API void visitOutputMeshLayoutStmt( stmt::OutputMeshLayout * stmt )override;
		SDAST_API void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )override;
		SDAST_API void visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout * stmt )override;
		SDAST_API void visitPerPrimitiveDeclStmt( stmt::PerPrimitiveDecl * stmt )override;
		SDAST_API void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override;
		SDAST_API void visitReturnStmt( stmt::Return * stmt )override;
		SDAST_API void visitTextureDeclStmt( stmt::TextureDecl * stmt )override;
		SDAST_API void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override;
		SDAST_API void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override;
		SDAST_API void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )override;
		SDAST_API void visitSimpleStmt( stmt::Simple * stmt )override;
		SDAST_API void visitStructureDeclStmt( stmt::StructureDecl * stmt )override;
		SDAST_API void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override;
		SDAST_API void visitSwitchStmt( stmt::Switch * stmt )override;
		SDAST_API void visitTerminateRayStmt( stmt::TerminateRay * stmt )override;
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

	protected:
		stmt::ContainerPtr & m_result;
		stmt::Container * m_current;
		std::vector< stmt::If * > m_ifStmts;
		std::vector< stmt::Switch * > m_switchStmts;
		std::vector< stmt::PreprocIf * > m_preprocIfStmts;
		std::vector< stmt::PreprocIfDef * > m_preprocIfDefStmts;
		std::vector< bool > m_preprocIfDefs;
	};
}

#endif
