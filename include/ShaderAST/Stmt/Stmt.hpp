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
		eDispatchMesh,
		ePreprocExtension,
		ePreprocVersion,
	};

	class Stmt
	{
	public:
		SDAST_API explicit Stmt( StmtCache & stmtCache
			, size_t size
			, Kind kind );
		SDAST_API virtual ~Stmt()noexcept = default;

		SDAST_API virtual void accept( VisitorPtr )const = 0;

		Kind getKind()const
		{
			return m_kind;
		}

		StmtCache & getStmtCache()const noexcept
		{
			return m_stmtCache;
		}

	private:
		friend class StmtCache;

		size_t getSize()const noexcept
		{
			return m_size;
		}

	private:
		StmtCache & m_stmtCache;
		size_t m_size;
		Kind m_kind;
	};
}

#endif
