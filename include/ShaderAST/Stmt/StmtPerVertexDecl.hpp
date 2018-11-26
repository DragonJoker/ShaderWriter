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
		};

	public:
		PerVertexDecl( Source source
			, type::StructPtr type );

		void accept( VisitorPtr vis )override;

		inline Source getSource()const
		{
			return m_source;
		}

		inline type::StructPtr getType()const
		{
			return m_type;
		}

	private:
		Source m_source;
		type::StructPtr m_type;
	};
	using PerVertexDeclPtr = std::unique_ptr< PerVertexDecl >;

	inline PerVertexDeclPtr makePerVertexDecl( PerVertexDecl::Source source
		, type::StructPtr type )
	{
		return std::make_unique< PerVertexDecl >( source
			, std::move( type ) );
	}
}

#endif
