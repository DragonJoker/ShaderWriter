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
		SDAST_API static stmt::ContainerPtr submit( stmt::StmtCache & stmtCache
			, expr::ExprCache & exprCache
			, stmt::Container const & stmt );
		SDAST_API static stmt::StmtPtr submit( stmt::StmtCache & stmtCache
			, expr::ExprCache & exprCache
			, stmt::Stmt const * stmt );

	protected:
		SDAST_API explicit StmtCloner( stmt::StmtCache & stmtCache
			, expr::ExprCache & exprCache
			, stmt::ContainerPtr & result );

	protected:
		SDAST_API virtual expr::ExprPtr doSubmit( expr::Expr const & expr );
		SDAST_API expr::ExprPtr doSubmit( expr::Expr const * expr );

		SDAST_API void visitContainerStmt( stmt::Container const * cont )override;
		SDAST_API void visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl const * stmt )override;
		SDAST_API void visitBreakStmt( stmt::Break const * stmt )override;
		SDAST_API void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl const * stmt )override;
		SDAST_API void visitContinueStmt( stmt::Continue const * stmt )override;
		SDAST_API void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl const * stmt )override;
		SDAST_API void visitDemoteStmt( stmt::Demote const * stmt )override;
		SDAST_API void visitTerminateInvocationStmt( stmt::TerminateInvocation const * stmt )override;
		SDAST_API void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl const * stmt )override;
		SDAST_API void visitCommentStmt( stmt::Comment const * stmt )override;
		SDAST_API void visitCompoundStmt( stmt::Compound const * stmt )override;
		SDAST_API void visitDispatchMeshStmt( stmt::DispatchMesh const * stmt )override;
		SDAST_API void visitDoWhileStmt( stmt::DoWhile const * stmt )override;
		SDAST_API void visitElseIfStmt( stmt::ElseIf const * stmt )override;
		SDAST_API void visitElseStmt( stmt::Else const * stmt )override;
		SDAST_API void visitForStmt( stmt::For const * stmt )override;
		SDAST_API void visitFragmentLayoutStmt( stmt::FragmentLayout const * stmt )override;
		SDAST_API void visitFunctionDeclStmt( stmt::FunctionDecl const * stmt )override;
		SDAST_API void visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl const * stmt )override;
		SDAST_API void visitIfStmt( stmt::If const * stmt )override;
		SDAST_API void visitImageDeclStmt( stmt::ImageDecl const * stmt )override;
		SDAST_API void visitIgnoreIntersectionStmt( stmt::IgnoreIntersection const * stmt )override;
		SDAST_API void visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl const * stmt )override;
		SDAST_API void visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl const * stmt )override;
		SDAST_API void visitInOutVariableDeclStmt( stmt::InOutVariableDecl const * stmt )override;
		SDAST_API void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl const * stmt )override;
		SDAST_API void visitInputComputeLayoutStmt( stmt::InputComputeLayout const * stmt )override;
		SDAST_API void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout const * stmt )override;
		SDAST_API void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout const * stmt )override;
		SDAST_API void visitOutputMeshLayoutStmt( stmt::OutputMeshLayout const * stmt )override;
		SDAST_API void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout const * stmt )override;
		SDAST_API void visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout const * stmt )override;
		SDAST_API void visitPerPrimitiveDeclStmt( stmt::PerPrimitiveDecl const * stmt )override;
		SDAST_API void visitPerVertexDeclStmt( stmt::PerVertexDecl const * stmt )override;
		SDAST_API void visitReturnStmt( stmt::Return const * stmt )override;
		SDAST_API void visitSampledImageDeclStmt( stmt::SampledImageDecl const * stmt )override;
		SDAST_API void visitCombinedImageDeclStmt( stmt::CombinedImageDecl const * stmt )override;
		SDAST_API void visitSamplerDeclStmt( stmt::SamplerDecl const * stmt )override;
		SDAST_API void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl const * stmt )override;
		SDAST_API void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl const * stmt )override;
		SDAST_API void visitSimpleStmt( stmt::Simple const * stmt )override;
		SDAST_API void visitStructureDeclStmt( stmt::StructureDecl const * stmt )override;
		SDAST_API void visitSwitchCaseStmt( stmt::SwitchCase const * stmt )override;
		SDAST_API void visitSwitchStmt( stmt::Switch const * stmt )override;
		SDAST_API void visitTerminateRayStmt( stmt::TerminateRay const * stmt )override;
		SDAST_API void visitVariableDeclStmt( stmt::VariableDecl const * stmt )override;
		SDAST_API void visitWhileStmt( stmt::While const * stmt )override;
		SDAST_API void visitPreprocExtension( stmt::PreprocExtension const * preproc )override;
		SDAST_API void visitPreprocVersion( stmt::PreprocVersion const * preproc )override;

	protected:
		stmt::StmtCache & m_stmtCache;
		expr::ExprCache & m_exprCache;
		stmt::ContainerPtr & m_result;
		stmt::Container * m_current;
		std::vector< stmt::If * > m_ifStmts;
		std::vector< stmt::Switch * > m_switchStmts;
	};
}

#endif
