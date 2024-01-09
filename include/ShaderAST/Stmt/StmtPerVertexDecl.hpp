/*
See LICENSE file in root folder
*/
#ifndef ___AST_PerVertexDecl_H___
#define ___AST_PerVertexDecl_H___
#pragma once

#include "Stmt.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class PerVertexDecl
		: public Stmt
	{
	public:
		enum Source
		{
			eVertexOutput,
			eTessellationControlInput,
			eTessellationControlOutput,
			eTessellationEvaluationInput,
			eTessellationEvaluationOutput,
			eGeometryInput,
			eGeometryOutput,
			eMeshOutput,
		};

	public:
		SDAST_API PerVertexDecl( StmtCache & stmtCache
			, Source source
			, type::TypePtr type );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline Source getSource()const
		{
			return m_source;
		}

		inline type::TypePtr getType()const
		{
			return m_type;
		}

	private:
		Source m_source;
		type::TypePtr m_type;
	};
}

#endif
