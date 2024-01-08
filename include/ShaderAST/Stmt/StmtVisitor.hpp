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

		SDAST_API virtual void visitAccelerationStructureDeclStmt( AccelerationStructureDecl * ) = 0;
		SDAST_API virtual void visitBreakStmt( Break * ) = 0;
		SDAST_API virtual void visitBufferReferenceDeclStmt( BufferReferenceDecl * ) = 0;
		SDAST_API virtual void visitCommentStmt( Comment * ) = 0;
		SDAST_API virtual void visitCompoundStmt( Compound * ) = 0;
		SDAST_API virtual void visitContainerStmt( Container * ) = 0;
		SDAST_API virtual void visitContinueStmt( Continue * ) = 0;
		SDAST_API virtual void visitConstantBufferDeclStmt( ConstantBufferDecl * ) = 0;
		SDAST_API virtual void visitDemoteStmt( Demote * ) = 0;
		SDAST_API virtual void visitDispatchMeshStmt( DispatchMesh * ) = 0;
		SDAST_API virtual void visitTerminateInvocationStmt( TerminateInvocation * ) = 0;
		SDAST_API virtual void visitDoWhileStmt( DoWhile * ) = 0;
		SDAST_API virtual void visitElseIfStmt( ElseIf * ) = 0;
		SDAST_API virtual void visitElseStmt( Else * ) = 0;
		SDAST_API virtual void visitForStmt( For * ) = 0;
		SDAST_API virtual void visitFragmentLayoutStmt( FragmentLayout * ) = 0;
		SDAST_API virtual void visitFunctionDeclStmt( FunctionDecl * ) = 0;
		SDAST_API virtual void visitHitAttributeVariableDeclStmt( HitAttributeVariableDecl * ) = 0;
		SDAST_API virtual void visitIfStmt( If * ) = 0;
		SDAST_API virtual void visitImageDeclStmt( ImageDecl * ) = 0;
		SDAST_API virtual void visitIgnoreIntersectionStmt( IgnoreIntersection * stmt ) = 0;
		SDAST_API virtual void visitInOutCallableDataVariableDeclStmt( InOutCallableDataVariableDecl * ) = 0;
		SDAST_API virtual void visitInOutRayPayloadVariableDeclStmt( InOutRayPayloadVariableDecl * ) = 0;
		SDAST_API virtual void visitInOutVariableDeclStmt( InOutVariableDecl * ) = 0;
		SDAST_API virtual void visitInputComputeLayoutStmt( InputComputeLayout * ) = 0;
		SDAST_API virtual void visitInputGeometryLayoutStmt( InputGeometryLayout * ) = 0;
		SDAST_API virtual void visitInputTessellationEvaluationLayoutStmt( InputTessellationEvaluationLayout * ) = 0;
		SDAST_API virtual void visitOutputGeometryLayoutStmt( OutputGeometryLayout * ) = 0;
		SDAST_API virtual void visitOutputMeshLayoutStmt( OutputMeshLayout * ) = 0;
		SDAST_API virtual void visitOutputTessellationControlLayoutStmt( OutputTessellationControlLayout * ) = 0;
		SDAST_API virtual void visitPerPrimitiveDeclStmt( PerPrimitiveDecl * ) = 0;
		SDAST_API virtual void visitPerVertexDeclStmt( PerVertexDecl * ) = 0;
		SDAST_API virtual void visitPushConstantsBufferDeclStmt( PushConstantsBufferDecl * ) = 0;
		SDAST_API virtual void visitReturnStmt( Return * ) = 0;
		SDAST_API virtual void visitCombinedImageDeclStmt( CombinedImageDecl * ) = 0;
		SDAST_API virtual void visitSampledImageDeclStmt( SampledImageDecl * ) = 0;
		SDAST_API virtual void visitSamplerDeclStmt( SamplerDecl * ) = 0;
		SDAST_API virtual void visitShaderBufferDeclStmt( ShaderBufferDecl * ) = 0;
		SDAST_API virtual void visitShaderStructBufferDeclStmt( ShaderStructBufferDecl * ) = 0;
		SDAST_API virtual void visitSimpleStmt( Simple * ) = 0;
		SDAST_API virtual void visitSpecialisationConstantDeclStmt( SpecialisationConstantDecl * ) = 0;
		SDAST_API virtual void visitStructureDeclStmt( StructureDecl * ) = 0;
		SDAST_API virtual void visitSwitchCaseStmt( SwitchCase * ) = 0;
		SDAST_API virtual void visitSwitchStmt( Switch * ) = 0;
		SDAST_API virtual void visitTerminateRayStmt( TerminateRay * ) = 0;
		SDAST_API virtual void visitVariableDeclStmt( VariableDecl * ) = 0;
		SDAST_API virtual void visitWhileStmt( While * ) = 0;
		SDAST_API virtual void visitPreprocExtension( PreprocExtension * ) = 0;
		SDAST_API virtual void visitPreprocVersion( PreprocVersion * ) = 0;
	};

	class SimpleVisitor
		: public Visitor
	{
	public:
		SDAST_API ~SimpleVisitor()noexcept override = default;

		SDAST_API void visitAccelerationStructureDeclStmt( AccelerationStructureDecl * stmt )override
		{
		}

		SDAST_API void visitBreakStmt( Break * stmt )override
		{
		}

		SDAST_API void visitBufferReferenceDeclStmt( BufferReferenceDecl * stmt )override
		{
		}

		SDAST_API void visitCommentStmt( Comment * stmt )override
		{
		}

		SDAST_API void visitCompoundStmt( Compound * stmt )override
		{
			visitContainerStmt( stmt );
		}

		SDAST_API void visitContainerStmt( Container * stmt )override
		{
			for ( auto & subStmt : *stmt )
			{
				subStmt->accept( this );
			}
		}

		SDAST_API void visitContinueStmt( Continue * stmt )override
		{
		}

		SDAST_API void visitConstantBufferDeclStmt( ConstantBufferDecl * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitDemoteStmt( Demote * stmt )override
		{
		}

		SDAST_API void visitDispatchMeshStmt( DispatchMesh * stmt )override
		{
		}

		SDAST_API void visitTerminateInvocationStmt( TerminateInvocation * stmt )override
		{
		}

		SDAST_API void visitDoWhileStmt( DoWhile * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitElseIfStmt( ElseIf * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitElseStmt( Else * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitForStmt( For * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitFragmentLayoutStmt( FragmentLayout * stmt )override
		{
		}

		SDAST_API void visitFunctionDeclStmt( FunctionDecl * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitHitAttributeVariableDeclStmt( HitAttributeVariableDecl * stmt )override
		{
		}

		SDAST_API void visitIfStmt( If * stmt )override
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

		SDAST_API void visitImageDeclStmt( ImageDecl * stmt )override
		{
		}

		SDAST_API void visitIgnoreIntersectionStmt( IgnoreIntersection * stmt )override
		{
		}

		SDAST_API void visitInOutCallableDataVariableDeclStmt( InOutCallableDataVariableDecl * stmt )override
		{
		}

		SDAST_API void visitInOutRayPayloadVariableDeclStmt( InOutRayPayloadVariableDecl * stmt )override
		{
		}

		SDAST_API void visitInOutVariableDeclStmt( InOutVariableDecl * stmt )override
		{
		}

		SDAST_API void visitInputComputeLayoutStmt( InputComputeLayout * stmt )override
		{
		}

		SDAST_API void visitInputGeometryLayoutStmt( InputGeometryLayout * stmt )override
		{
		}

		SDAST_API void visitInputTessellationEvaluationLayoutStmt( InputTessellationEvaluationLayout * stmt )override
		{
		}

		SDAST_API void visitOutputGeometryLayoutStmt( OutputGeometryLayout * stmt )override
		{
		}

		SDAST_API void visitOutputMeshLayoutStmt( OutputMeshLayout * stmt )override
		{
		}

		SDAST_API void visitOutputTessellationControlLayoutStmt( OutputTessellationControlLayout * stmt )override
		{
		}

		SDAST_API void visitPerPrimitiveDeclStmt( PerPrimitiveDecl * stmt )override
		{
		}

		SDAST_API void visitPerVertexDeclStmt( PerVertexDecl * stmt )override
		{
		}

		SDAST_API void visitPushConstantsBufferDeclStmt( PushConstantsBufferDecl * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitReturnStmt( Return * stmt )override
		{
		}

		SDAST_API void visitCombinedImageDeclStmt( CombinedImageDecl * stmt )override
		{
		}

		SDAST_API void visitSampledImageDeclStmt( SampledImageDecl * stmt )override
		{
		}

		SDAST_API void visitSamplerDeclStmt( SamplerDecl * stmt )override
		{
		}

		SDAST_API void visitShaderBufferDeclStmt( ShaderBufferDecl * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitShaderStructBufferDeclStmt( ShaderStructBufferDecl * stmt )override
		{
		}

		SDAST_API void visitSimpleStmt( Simple * stmt )override
		{
		}

		SDAST_API void visitSpecialisationConstantDeclStmt( SpecialisationConstantDecl * stmt )override
		{
		}

		SDAST_API void visitStructureDeclStmt( StructureDecl * stmt )override
		{
		}

		SDAST_API void visitSwitchCaseStmt( SwitchCase * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitSwitchStmt( Switch * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitTerminateRayStmt( TerminateRay * stmt )override
		{
		}

		SDAST_API void visitVariableDeclStmt( VariableDecl * stmt )override
		{
		}

		SDAST_API void visitWhileStmt( While * stmt )override
		{
			visitCompoundStmt( stmt );
		}

		SDAST_API void visitPreprocExtension( PreprocExtension * stmt )override
		{
		}

		SDAST_API void visitPreprocVersion( PreprocVersion * stmt )override
		{
		}
	};
}

#endif
