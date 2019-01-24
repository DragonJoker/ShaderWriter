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
		eDiscard,
		eEmitVertex,
		eEmitPrimitive,
		eInputGeometryLayout,
		eOutputGeometryLayout,
		eInputComputeLayout,
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
		Stmt( Kind kind );
		virtual ~Stmt();

		virtual void accept( VisitorPtr ) = 0;

		inline Kind getKind()const
		{
			return m_kind;
		}

	private:
		Kind m_kind;
	};
}

#endif
