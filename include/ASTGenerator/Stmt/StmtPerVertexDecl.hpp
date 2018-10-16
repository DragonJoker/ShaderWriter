/*
See LICENSE file in root folder
*/
#ifndef ___AST_PerVertexDecl_H___
#define ___AST_PerVertexDecl_H___
#pragma once

#include "Stmt.hpp"

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
		};

	public:
		PerVertexDecl( Source source );

		void accept( VisitorPtr vis )override;

		inline Source getSource()const
		{
			return m_source;
		}

	private:
		Source m_source;
	};
	using PerVertexDeclPtr = std::unique_ptr< PerVertexDecl >;

	inline PerVertexDeclPtr makePerVertexDecl( PerVertexDecl::Source source )
	{
		return std::make_unique< PerVertexDecl >( source );
	}
}

#endif
