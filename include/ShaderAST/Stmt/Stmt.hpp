/*
See LICENSE file in root folder
*/
#ifndef ___AST_Stmt_H___
#define ___AST_Stmt_H___
#pragma once

#include "ShaderAST/ShaderASTPrerequisites.hpp"

namespace ast::stmt
{
	enum class Kind
		: uint8_t
	{
		eSimple,
		eContainer,
		eCompound,
		eComment,
		eVariableDecl,
		ePerPrimitiveDecl,
		ePerVertexDecl,
		eInOutVariableDecl,
		eSpecialisationConstantDecl,
		eConstantBufferDecl,
		ePushConstantsBufferDecl,
		eShaderBufferDecl,
		eShaderStructBufferDecl,
		eSamplerDecl,
		eImageDecl,
		eSampledImageDecl,
		eCombinedImageDecl,
		eFunctionDecl,
		eStructureDecl,
		eIf,
		eElse,
		eElseIf,
		eWhile,
		eFor,
		eDoWhile,
		eSwitch,
		eSwitchCase,
		eReturn,
		eBreak,
		eContinue,
		eDemote,
		eTerminateInvocation,
		eInputGeometryLayout,
		eOutputGeometryLayout,
		eInputComputeLayout,
		eOutputMeshLayout,
		eFragmentLayout,
		eOutputTessellationControlLayout,
		eInputTessellationEvaluationLayout,
		eAccelerationStructureDecl,
		eInOutRayPayloadVariableDecl,
		eHitAttributeVariableDecl,
		eInOutCallableDataVariableDecl,
		eBufferReferenceDecl,
		eTerminateRay,
		eIgnoreIntersection,
		ePreprocDefine,
		ePreprocIf,
		ePreprocElif,
		ePreprocElse,
		ePreprocIfDef,
		ePreprocEndif,
		ePreprocExtension,
		ePreprocVersion,
	};

	class Stmt
	{
	public:
		SDAST_API explicit Stmt( Kind kind );
		SDAST_API virtual ~Stmt();

		SDAST_API virtual void accept( VisitorPtr ) = 0;

		inline Kind getKind()const
		{
			return m_kind;
		}

	private:
		Kind m_kind;
	};
}

#endif
