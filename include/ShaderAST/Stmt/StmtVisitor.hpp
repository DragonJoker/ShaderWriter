/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtVisitor_H___
#define ___AST_StmtVisitor_H___
#pragma once

#include "PreprocExtension.hpp"
#include "PreprocVersion.hpp"
#include "StmtAccelerationStructureDecl.hpp"
#include "StmtBreak.hpp"
#include "StmtBufferReferenceDecl.hpp"
#include "StmtComment.hpp"
#include "StmtCompound.hpp"
#include "StmtContainer.hpp"
#include "StmtContinue.hpp"
#include "StmtConstantBufferDecl.hpp"
#include "StmtDemote.hpp"
#include "StmtDispatchMesh.hpp"
#include "StmtDoWhile.hpp"
#include "StmtElse.hpp"
#include "StmtElseIf.hpp"
#include "StmtFor.hpp"
#include "StmtFragmentLayout.hpp"
#include "StmtFunctionDecl.hpp"
#include "StmtHitAttributeVariableDecl.hpp"
#include "StmtIf.hpp"
#include "StmtImageDecl.hpp"
#include "StmtIgnoreIntersection.hpp"
#include "StmtInOutCallableDataVariableDecl.hpp"
#include "StmtInOutRayPayloadVariableDecl.hpp"
#include "StmtInOutVariableDecl.hpp"
#include "StmtInputComputeLayout.hpp"
#include "StmtInputGeometryLayout.hpp"
#include "StmtInputTessellationEvaluationLayout.hpp"
#include "StmtOutputGeometryLayout.hpp"
#include "StmtOutputMeshLayout.hpp"
#include "StmtOutputTessellationControlLayout.hpp"
#include "StmtPerPrimitiveDecl.hpp"
#include "StmtPerVertexDecl.hpp"
#include "StmtPushConstantsBufferDecl.hpp"
#include "StmtReturn.hpp"
#include "StmtSampledImageDecl.hpp"
#include "StmtCombinedImageDecl.hpp"
#include "StmtSamplerDecl.hpp"
#include "StmtShaderBufferDecl.hpp"
#include "StmtShaderStructBufferDecl.hpp"
#include "StmtSimple.hpp"
#include "StmtSpecialisationConstantDecl.hpp"
#include "StmtStructureDecl.hpp"
#include "StmtSwitchCase.hpp"
#include "StmtSwitch.hpp"
#include "StmtTerminateInvocation.hpp"
#include "StmtTerminateRay.hpp"
#include "StmtVariableDecl.hpp"
#include "StmtWhile.hpp"

namespace ast::stmt
{
	class Visitor
	{
	protected:
		SDAST_API Visitor()noexcept = default;

	public:
		SDAST_API virtual ~Visitor()noexcept = default;

		SDAST_API virtual void visitAccelerationStructureDeclStmt( AccelerationStructureDecl const * ) = 0;
		SDAST_API virtual void visitBreakStmt( Break const * ) = 0;
		SDAST_API virtual void visitBufferReferenceDeclStmt( BufferReferenceDecl const * ) = 0;
		SDAST_API virtual void visitCommentStmt( Comment const * ) = 0;
		SDAST_API virtual void visitCompoundStmt( Compound const * ) = 0;
		SDAST_API virtual void visitContainerStmt( Container const * ) = 0;
		SDAST_API virtual void visitContinueStmt( Continue const * ) = 0;
		SDAST_API virtual void visitConstantBufferDeclStmt( ConstantBufferDecl const * ) = 0;
		SDAST_API virtual void visitDemoteStmt( Demote const * ) = 0;
		SDAST_API virtual void visitDispatchMeshStmt( DispatchMesh const * ) = 0;
		SDAST_API virtual void visitTerminateInvocationStmt( TerminateInvocation const * ) = 0;
		SDAST_API virtual void visitDoWhileStmt( DoWhile const * ) = 0;
		SDAST_API virtual void visitElseIfStmt( ElseIf const * ) = 0;
		SDAST_API virtual void visitElseStmt( Else const * ) = 0;
		SDAST_API virtual void visitForStmt( For const * ) = 0;
		SDAST_API virtual void visitFragmentLayoutStmt( FragmentLayout const * ) = 0;
		SDAST_API virtual void visitFunctionDeclStmt( FunctionDecl const * ) = 0;
		SDAST_API virtual void visitHitAttributeVariableDeclStmt( HitAttributeVariableDecl const * ) = 0;
		SDAST_API virtual void visitIfStmt( If const * ) = 0;
		SDAST_API virtual void visitImageDeclStmt( ImageDecl const * ) = 0;
		SDAST_API virtual void visitIgnoreIntersectionStmt( IgnoreIntersection const * stmt ) = 0;
		SDAST_API virtual void visitInOutCallableDataVariableDeclStmt( InOutCallableDataVariableDecl const * ) = 0;
		SDAST_API virtual void visitInOutRayPayloadVariableDeclStmt( InOutRayPayloadVariableDecl const * ) = 0;
		SDAST_API virtual void visitInOutVariableDeclStmt( InOutVariableDecl const * ) = 0;
		SDAST_API virtual void visitInputComputeLayoutStmt( InputComputeLayout const * ) = 0;
		SDAST_API virtual void visitInputGeometryLayoutStmt( InputGeometryLayout const * ) = 0;
		SDAST_API virtual void visitInputTessellationEvaluationLayoutStmt( InputTessellationEvaluationLayout const * ) = 0;
		SDAST_API virtual void visitOutputGeometryLayoutStmt( OutputGeometryLayout const * ) = 0;
		SDAST_API virtual void visitOutputMeshLayoutStmt( OutputMeshLayout const * ) = 0;
		SDAST_API virtual void visitOutputTessellationControlLayoutStmt( OutputTessellationControlLayout const * ) = 0;
		SDAST_API virtual void visitPerPrimitiveDeclStmt( PerPrimitiveDecl const * ) = 0;
		SDAST_API virtual void visitPerVertexDeclStmt( PerVertexDecl const * ) = 0;
		SDAST_API virtual void visitPushConstantsBufferDeclStmt( PushConstantsBufferDecl const * ) = 0;
		SDAST_API virtual void visitReturnStmt( Return const * ) = 0;
		SDAST_API virtual void visitCombinedImageDeclStmt( CombinedImageDecl const * ) = 0;
		SDAST_API virtual void visitSampledImageDeclStmt( SampledImageDecl const * ) = 0;
		SDAST_API virtual void visitSamplerDeclStmt( SamplerDecl const * ) = 0;
		SDAST_API virtual void visitShaderBufferDeclStmt( ShaderBufferDecl const * ) = 0;
		SDAST_API virtual void visitShaderStructBufferDeclStmt( ShaderStructBufferDecl const * ) = 0;
		SDAST_API virtual void visitSimpleStmt( Simple const * ) = 0;
		SDAST_API virtual void visitSpecialisationConstantDeclStmt( SpecialisationConstantDecl const * ) = 0;
		SDAST_API virtual void visitStructureDeclStmt( StructureDecl const * ) = 0;
		SDAST_API virtual void visitSwitchCaseStmt( SwitchCase const * ) = 0;
		SDAST_API virtual void visitSwitchStmt( Switch const * ) = 0;
		SDAST_API virtual void visitTerminateRayStmt( TerminateRay const * ) = 0;
		SDAST_API virtual void visitVariableDeclStmt( VariableDecl const * ) = 0;
		SDAST_API virtual void visitWhileStmt( While const * ) = 0;
		SDAST_API virtual void visitPreprocExtension( PreprocExtension const * ) = 0;
		SDAST_API virtual void visitPreprocVersion( PreprocVersion const * ) = 0;
	};

	class SimpleVisitor
		: public Visitor
	{
	protected:
		SDAST_API SimpleVisitor()noexcept = default;

	public:
		SDAST_API ~SimpleVisitor()noexcept override = default;

		SDAST_API void visitAccelerationStructureDeclStmt( AccelerationStructureDecl const * stmt )override
		{
		}

		SDAST_API void visitBreakStmt( Break const * stmt )override
		{
		}

		SDAST_API void visitBufferReferenceDeclStmt( BufferReferenceDecl const * stmt )override
		{
		}

		SDAST_API void visitCommentStmt( Comment const * stmt )override
		{
		}

		SDAST_API void visitCompoundStmt( Compound const * stmt )override
		{
			visitContainerStmt( stmt );
		}

		SDAST_API void visitContainerStmt( Container const * stmt )override
		{
			for ( auto & subStmt : *stmt )
			{
				subStmt->accept( this );
			}
		}

		SDAST_API void visitContinueStmt( Continue const * stmt )override
		{
		}

		SDAST_API void visitConstantBufferDeclStmt( ConstantBufferDecl const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitDemoteStmt( Demote const * stmt )override
		{
		}

		SDAST_API void visitDispatchMeshStmt( DispatchMesh const * stmt )override
		{
		}

		SDAST_API void visitTerminateInvocationStmt( TerminateInvocation const * stmt )override
		{
		}

		SDAST_API void visitDoWhileStmt( DoWhile const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitElseIfStmt( ElseIf const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitElseStmt( Else const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitForStmt( For const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitFragmentLayoutStmt( FragmentLayout const * stmt )override
		{
		}

		SDAST_API void visitFunctionDeclStmt( FunctionDecl const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitHitAttributeVariableDeclStmt( HitAttributeVariableDecl const * stmt )override
		{
		}

		SDAST_API void visitIfStmt( If const * stmt )override
		{
			visitCompoundStmt( stmt );

			for ( auto & elseIf : stmt->getElseIfList() )
			{
				elseIf->accept( this );
			}

			if ( stmt->getElse() )
			{
				stmt->getElse()->accept( this );
			}
		}

		SDAST_API void visitImageDeclStmt( ImageDecl const * stmt )override
		{
		}

		SDAST_API void visitIgnoreIntersectionStmt( IgnoreIntersection const * stmt )override
		{
		}

		SDAST_API void visitInOutCallableDataVariableDeclStmt( InOutCallableDataVariableDecl const * stmt )override
		{
		}

		SDAST_API void visitInOutRayPayloadVariableDeclStmt( InOutRayPayloadVariableDecl const * stmt )override
		{
		}

		SDAST_API void visitInOutVariableDeclStmt( InOutVariableDecl const * stmt )override
		{
		}

		SDAST_API void visitInputComputeLayoutStmt( InputComputeLayout const * stmt )override
		{
		}

		SDAST_API void visitInputGeometryLayoutStmt( InputGeometryLayout const * stmt )override
		{
		}

		SDAST_API void visitInputTessellationEvaluationLayoutStmt( InputTessellationEvaluationLayout const * stmt )override
		{
		}

		SDAST_API void visitOutputGeometryLayoutStmt( OutputGeometryLayout const * stmt )override
		{
		}

		SDAST_API void visitOutputMeshLayoutStmt( OutputMeshLayout const * stmt )override
		{
		}

		SDAST_API void visitOutputTessellationControlLayoutStmt( OutputTessellationControlLayout const * stmt )override
		{
		}

		SDAST_API void visitPerPrimitiveDeclStmt( PerPrimitiveDecl const * stmt )override
		{
		}

		SDAST_API void visitPerVertexDeclStmt( PerVertexDecl const * stmt )override
		{
		}

		SDAST_API void visitPushConstantsBufferDeclStmt( PushConstantsBufferDecl const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitReturnStmt( Return const * stmt )override
		{
		}

		SDAST_API void visitCombinedImageDeclStmt( CombinedImageDecl const * stmt )override
		{
		}

		SDAST_API void visitSampledImageDeclStmt( SampledImageDecl const * stmt )override
		{
		}

		SDAST_API void visitSamplerDeclStmt( SamplerDecl const * stmt )override
		{
		}

		SDAST_API void visitShaderBufferDeclStmt( ShaderBufferDecl const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitShaderStructBufferDeclStmt( ShaderStructBufferDecl const * stmt )override
		{
		}

		SDAST_API void visitSimpleStmt( Simple const * stmt )override
		{
		}

		SDAST_API void visitSpecialisationConstantDeclStmt( SpecialisationConstantDecl const * stmt )override
		{
		}

		SDAST_API void visitStructureDeclStmt( StructureDecl const * stmt )override
		{
		}

		SDAST_API void visitSwitchCaseStmt( SwitchCase const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitSwitchStmt( Switch const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitTerminateRayStmt( TerminateRay const * stmt )override
		{
		}

		SDAST_API void visitVariableDeclStmt( VariableDecl const * stmt )override
		{
		}

		SDAST_API void visitWhileStmt( While const * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitPreprocExtension( PreprocExtension const * stmt )override
		{
		}

		SDAST_API void visitPreprocVersion( PreprocVersion const * stmt )override
		{
		}
	};
}

#endif
